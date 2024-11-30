//
//  A5Dom.cpp
//  ECE467 Lab 5
//
//  Created by Tarek Abdelrahman on 2023-11-18.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

#include <algorithm>
#include <cassert>
#include <codecvt>
#include <iostream>
#include <iterator>
#include <llvm-14/llvm/IR/BasicBlock.h>
#include <llvm-14/llvm/IR/CFG.h>
#include <llvm-14/llvm/IR/Function.h>
#include <set>
#include <string>
#include <map>
#include <vector>

using namespace llvm;
using namespace std;

namespace {

class BBDom{
  public:
    std::string BBName;
    std::set<std::string> Dom;
    std::string Dom_imm;
    std::set<std::string> PDom; 
    std::string PDom_imm;

    BBDom(){}
    BBDom(std::string BBs){
      BBName = BBs;
      Dom_imm = "X";
      PDom_imm = "X";
    }
    void printDom(){
      std::cout << BBName << ": " << std::endl << "    ";
      for (auto DomIt = Dom.begin(); DomIt != Dom.end(); DomIt++)
        std::cout << *DomIt << " ";
      std::cout << std::endl << "    " << Dom_imm << std::endl << "    ";
      for (auto PDomIt = PDom.begin(); PDomIt != PDom.end(); PDomIt++)
        std::cout << *PDomIt << " ";
      std::cout << std::endl << "    " << PDom_imm << std::endl;
      return;
    }
};

// This method implements what the pass does
void processFunction(Function &F) {
  // ECE467 STUDENT: add your code here
  BasicBlock &entry = F.getEntryBlock();
  Function::BasicBlockListType::iterator BBit1, BBit2;
  for (BBit1 = F.begin(); BBit1 != F.end(); BBit1++) {
    if (llvm::Instruction *terminator = BBit1->getTerminator()) {
      if (llvm::isa<llvm::ReturnInst>(terminator)) {
        break;
      }
    }
  }
  BasicBlock &exit = *BBit1;
  std::map<std::string, BBDom> BBInfoList;
  bool changed = true;
  bool immediate;

  //Init
  for (BBit1 = F.begin(); BBit1 != F.end(); BBit1++) {
    std::string BBName = BBit1->getName().str();
    BBInfoList.emplace(BBName, BBDom(BBName));

    for (BBit2 = F.begin(); BBit2 != F.end(); BBit2++){
      BBInfoList[BBName].Dom.insert(BBit2->getName().str());
      BBInfoList[BBName].PDom.insert(BBit2->getName().str());
    }
  }
  BBInfoList[entry.getName().str()].Dom.clear();
  BBInfoList[exit.getName().str()].PDom.clear();

  //Dom
  while (changed){
    changed = false;
    for (BBit1 = F.begin(); BBit1 != F.end(); BBit1++) {
      std::set<std::string> oldDom;
      std::string BBName = BBit1->getName().str();
      llvm::pred_range predList = llvm::predecessors(&(*BBit1));

      oldDom = BBInfoList[BBName].Dom;
      for (auto predIt = predList.begin(); predIt != predList.end(); predIt++) {
        std::set<std::string> intersect;
        std::set<std::string> predDom;

        predDom = BBInfoList[(*predIt)->getName().str()].Dom;
        if (predIt == predList.begin())
          BBInfoList[BBName].Dom = predDom;
        std::set_intersection(BBInfoList[BBName].Dom.begin(), BBInfoList[BBName].Dom.end(), 
                              predDom.begin(), predDom.end(), std::inserter(intersect, intersect.begin()));
        BBInfoList[BBName].Dom = intersect;
      }
      BBInfoList[BBName].Dom.insert(BBName);
      if (oldDom != BBInfoList[BBName].Dom) changed = true;
    }
  }

  changed = true;
  //PDom
  while (changed){
    changed = false;
    for (BBit1 = F.begin(); BBit1 != F.end(); BBit1++) {
      std::set<std::string> oldPDom;
      std::string BBName = BBit1->getName().str();
      llvm::succ_range succList = llvm::successors(&(*BBit1));

      oldPDom = BBInfoList[BBName].PDom;
      for (auto succIt = succList.begin(); succIt != succList.end(); succIt++) {
        std::set<std::string> intersect;
        std::set<std::string> succPDom;

        succPDom = BBInfoList[(*succIt)->getName().str()].PDom;
        if (succIt == succList.begin())
          BBInfoList[BBName].PDom = succPDom;
        std::set_intersection(BBInfoList[BBName].PDom.begin(), BBInfoList[BBName].PDom.end(), 
                              succPDom.begin(), succPDom.end(), std::inserter(intersect, intersect.begin()));
        BBInfoList[BBName].PDom = intersect;
      }
      BBInfoList[BBName].PDom.insert(BBName);
      BBInfoList[BBName].PDom.insert(exit.getName().str());
      if (oldPDom != BBInfoList[BBName].PDom) changed = true;
    }
  }

  //Find immediate dom and Pdom
  for (auto BBInfoIt = BBInfoList.begin(); BBInfoIt != BBInfoList.end(); BBInfoIt++){
    for (auto DomItTarget = BBInfoIt->second.Dom.begin(); DomItTarget != BBInfoIt->second.Dom.end(); DomItTarget++){
      if (BBInfoIt->second.BBName == *DomItTarget) continue;
      immediate = true;
      for (auto DomIt = BBInfoIt->second.Dom.begin(); DomIt != BBInfoIt->second.Dom.end(); DomIt++){
        if (BBInfoIt->second.BBName == *DomIt || *DomItTarget == *DomIt) continue;
        if (BBInfoList[*DomIt].Dom.find(*DomItTarget) != BBInfoList[*DomIt].Dom.end()){
          immediate = false;
        }
      }
      if (immediate){
        BBInfoIt->second.Dom_imm = *DomItTarget;
      }
    }
    for (auto PDomItTarget = BBInfoIt->second.PDom.begin(); PDomItTarget != BBInfoIt->second.PDom.end(); PDomItTarget++){
      if (BBInfoIt->second.BBName == *PDomItTarget) continue;
      immediate = true;
      for (auto PDomIt = BBInfoIt->second.PDom.begin(); PDomIt != BBInfoIt->second.PDom.end(); PDomIt++){
        if (BBInfoIt->second.BBName == *PDomIt || *PDomItTarget == *PDomIt) continue;
        if (BBInfoList[*PDomIt].PDom.find(*PDomItTarget) != BBInfoList[*PDomIt].PDom.end()){
          immediate = false;
        }
      }
      if (immediate){
        BBInfoIt->second.PDom_imm = *PDomItTarget;
      }
    }
  }

  //print
  for (auto BBinfoIt = BBInfoList.begin(); BBinfoIt != BBInfoList.end(); BBinfoIt++){
    BBinfoIt->second.printDom();
  }
  
  return;
}

struct A5Dom : PassInfoMixin<A5Dom> {
  // This is the main entry point for processing the IR of a function
  // It simply calls the function that has your code
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &) {
    processFunction(F);
    return PreservedAnalyses::all();
  }

  // This makes sure that the pass is executed, even when functions are
  // decorated with the optnone attribute; this is the case when using
  // clang without -O flags
  static bool isRequired() { return true; }
};
} // namespace

// Register the pass with the pass manager as a function pass
llvm::PassPluginLibraryInfo getA5DomPluginInfo() {
  return {LLVM_PLUGIN_API_VERSION, "A5Dom", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, FunctionPassManager &FPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "A5Dom") {
                    FPM.addPass(A5Dom());
                    return true;
                  }
                  return false;
                });
          }};
}

// This ensures that opt recognizes A5Dom when specified on the
// command line by -passes="A5Dom"
extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getA5DomPluginInfo();
}
