#!/bin/bash

# Check if an input file is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <input.ll>"
    exit 1
fi

# Input file from command-line argument
INPUT_FILE=$1

# Ensure the output directory exists
mkdir -p output

# Redirect both stdout and stderr to respective files
/cad2/ece467f/llvm-project/build/bin/opt -load-pass-plugin=libA5Dom.so -passes="A5Dom" -disable-output "$INPUT_FILE" > output/local.txt 2>&1
/cad2/ece467f/llvm-project/build/bin/opt -load-pass-plugin=/cad2/ece467f/public/libA5DomRef.so -passes="A5Dom" -disable-output "$INPUT_FILE" > output/ref.txt 2>&1

echo "All tasks completed successfully!"
