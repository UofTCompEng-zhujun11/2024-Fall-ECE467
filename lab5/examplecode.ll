; ModuleID = 'examplecode.c'
source_filename = "examplecode.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @complexFunction(i32 noundef %input) #0 {
entry:
  %input.addr = alloca i32, align 4
  %result = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  store i32 %input, ptr %input.addr, align 4
  store i32 0, ptr %result, align 4
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %if.end117, %entry
  %0 = load i32, ptr %i, align 4
  %cmp = icmp slt i32 %0, 10
  br i1 %cmp, label %while.body, label %while.end119

while.body:                                       ; preds = %while.cond
  store i32 0, ptr %j, align 4
  br label %while.cond1

while.cond1:                                      ; preds = %if.end90, %while.body
  %1 = load i32, ptr %j, align 4
  %cmp2 = icmp slt i32 %1, 5
  br i1 %cmp2, label %while.body3, label %while.end92

while.body3:                                      ; preds = %while.cond1
  %2 = load i32, ptr %i, align 4
  %rem = srem i32 %2, 2
  %cmp4 = icmp eq i32 %rem, 0
  br i1 %cmp4, label %if.then, label %if.else48

if.then:                                          ; preds = %while.body3
  %3 = load i32, ptr %j, align 4
  %rem5 = srem i32 %3, 2
  %cmp6 = icmp eq i32 %rem5, 0
  br i1 %cmp6, label %if.then7, label %if.else22

if.then7:                                         ; preds = %if.then
  %4 = load i32, ptr %input.addr, align 4
  %cmp8 = icmp sgt i32 %4, 50
  br i1 %cmp8, label %if.then9, label %if.else18

if.then9:                                         ; preds = %if.then7
  %5 = load i32, ptr %result, align 4
  %6 = load i32, ptr %i, align 4
  %7 = load i32, ptr %j, align 4
  %mul = mul nsw i32 %6, %7
  %add = add nsw i32 %5, %mul
  store i32 %add, ptr %result, align 4
  store i32 0, ptr %k, align 4
  br label %while.cond10

while.cond10:                                     ; preds = %if.end, %if.then9
  %8 = load i32, ptr %k, align 4
  %cmp11 = icmp slt i32 %8, 3
  br i1 %cmp11, label %while.body12, label %while.end

while.body12:                                     ; preds = %while.cond10
  %9 = load i32, ptr %k, align 4
  %rem13 = srem i32 %9, 2
  %cmp14 = icmp eq i32 %rem13, 0
  br i1 %cmp14, label %if.then15, label %if.else

if.then15:                                        ; preds = %while.body12
  %10 = load i32, ptr %result, align 4
  %11 = load i32, ptr %k, align 4
  %add16 = add nsw i32 %10, %11
  store i32 %add16, ptr %result, align 4
  br label %if.end

if.else:                                          ; preds = %while.body12
  %12 = load i32, ptr %result, align 4
  %13 = load i32, ptr %k, align 4
  %sub = sub nsw i32 %12, %13
  store i32 %sub, ptr %result, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then15
  %14 = load i32, ptr %k, align 4
  %add17 = add nsw i32 %14, 1
  store i32 %add17, ptr %k, align 4
  br label %while.cond10, !llvm.loop !6

while.end:                                        ; preds = %while.cond10
  br label %if.end21

if.else18:                                        ; preds = %if.then7
  %15 = load i32, ptr %result, align 4
  %16 = load i32, ptr %i, align 4
  %sub19 = sub nsw i32 %15, %16
  %17 = load i32, ptr %j, align 4
  %add20 = add nsw i32 %sub19, %17
  store i32 %add20, ptr %result, align 4
  br label %if.end21

if.end21:                                         ; preds = %if.else18, %while.end
  br label %if.end47

if.else22:                                        ; preds = %if.then
  %18 = load i32, ptr %input.addr, align 4
  %cmp23 = icmp slt i32 %18, 30
  br i1 %cmp23, label %if.then24, label %if.else38

if.then24:                                        ; preds = %if.else22
  store i32 0, ptr %k, align 4
  br label %while.cond25

while.cond25:                                     ; preds = %if.end35, %if.then24
  %19 = load i32, ptr %k, align 4
  %cmp26 = icmp slt i32 %19, 4
  br i1 %cmp26, label %while.body27, label %while.end37

while.body27:                                     ; preds = %while.cond25
  %20 = load i32, ptr %input.addr, align 4
  %21 = load i32, ptr %k, align 4
  %rem28 = srem i32 %20, %21
  %cmp29 = icmp eq i32 %rem28, 0
  br i1 %cmp29, label %if.then30, label %if.else33

if.then30:                                        ; preds = %while.body27
  %22 = load i32, ptr %result, align 4
  %23 = load i32, ptr %k, align 4
  %mul31 = mul nsw i32 %23, 2
  %add32 = add nsw i32 %22, %mul31
  store i32 %add32, ptr %result, align 4
  br label %if.end35

if.else33:                                        ; preds = %while.body27
  %24 = load i32, ptr %result, align 4
  %25 = load i32, ptr %k, align 4
  %sub34 = sub nsw i32 %24, %25
  store i32 %sub34, ptr %result, align 4
  br label %if.end35

if.end35:                                         ; preds = %if.else33, %if.then30
  %26 = load i32, ptr %k, align 4
  %add36 = add nsw i32 %26, 1
  store i32 %add36, ptr %k, align 4
  br label %while.cond25, !llvm.loop !8

while.end37:                                      ; preds = %while.cond25
  br label %if.end46

if.else38:                                        ; preds = %if.else22
  %27 = load i32, ptr %i, align 4
  %cmp39 = icmp slt i32 %27, 5
  br i1 %cmp39, label %if.then40, label %if.else42

if.then40:                                        ; preds = %if.else38
  %28 = load i32, ptr %result, align 4
  %29 = load i32, ptr %input.addr, align 4
  %div = sdiv i32 %29, 2
  %sub41 = sub nsw i32 %28, %div
  store i32 %sub41, ptr %result, align 4
  br label %if.end45

if.else42:                                        ; preds = %if.else38
  %30 = load i32, ptr %result, align 4
  %31 = load i32, ptr %input.addr, align 4
  %div43 = sdiv i32 %31, 3
  %add44 = add nsw i32 %30, %div43
  store i32 %add44, ptr %result, align 4
  br label %if.end45

if.end45:                                         ; preds = %if.else42, %if.then40
  br label %if.end46

if.end46:                                         ; preds = %if.end45, %while.end37
  br label %if.end47

if.end47:                                         ; preds = %if.end46, %if.end21
  br label %if.end71

if.else48:                                        ; preds = %while.body3
  %32 = load i32, ptr %j, align 4
  %cmp49 = icmp eq i32 %32, 3
  br i1 %cmp49, label %if.then50, label %if.else57

if.then50:                                        ; preds = %if.else48
  %33 = load i32, ptr %input.addr, align 4
  %cmp51 = icmp eq i32 %33, 42
  br i1 %cmp51, label %if.then52, label %if.else54

if.then52:                                        ; preds = %if.then50
  %34 = load i32, ptr %result, align 4
  %mul53 = mul nsw i32 %34, 3
  store i32 %mul53, ptr %result, align 4
  br label %if.end56

if.else54:                                        ; preds = %if.then50
  %35 = load i32, ptr %result, align 4
  %sub55 = sub nsw i32 %35, 1
  store i32 %sub55, ptr %result, align 4
  br label %if.end56

if.end56:                                         ; preds = %if.else54, %if.then52
  br label %if.end70

if.else57:                                        ; preds = %if.else48
  %36 = load i32, ptr %input.addr, align 4
  %cmp58 = icmp slt i32 %36, 20
  br i1 %cmp58, label %if.then59, label %if.else67

if.then59:                                        ; preds = %if.else57
  store i32 0, ptr %k, align 4
  br label %while.cond60

while.cond60:                                     ; preds = %while.body62, %if.then59
  %37 = load i32, ptr %k, align 4
  %cmp61 = icmp slt i32 %37, 2
  br i1 %cmp61, label %while.body62, label %while.end66

while.body62:                                     ; preds = %while.cond60
  %38 = load i32, ptr %result, align 4
  %39 = load i32, ptr %k, align 4
  %40 = load i32, ptr %j, align 4
  %mul63 = mul nsw i32 %39, %40
  %add64 = add nsw i32 %38, %mul63
  store i32 %add64, ptr %result, align 4
  %41 = load i32, ptr %k, align 4
  %add65 = add nsw i32 %41, 1
  store i32 %add65, ptr %k, align 4
  br label %while.cond60, !llvm.loop !9

while.end66:                                      ; preds = %while.cond60
  br label %if.end69

if.else67:                                        ; preds = %if.else57
  %42 = load i32, ptr %result, align 4
  %div68 = sdiv i32 %42, 2
  store i32 %div68, ptr %result, align 4
  br label %if.end69

if.end69:                                         ; preds = %if.else67, %while.end66
  br label %if.end70

if.end70:                                         ; preds = %if.end69, %if.end56
  br label %if.end71

if.end71:                                         ; preds = %if.end70, %if.end47
  %43 = load i32, ptr %result, align 4
  %cmp72 = icmp sgt i32 %43, 100
  br i1 %cmp72, label %if.then73, label %if.else80

if.then73:                                        ; preds = %if.end71
  %44 = load i32, ptr %i, align 4
  %cmp74 = icmp sgt i32 %44, 5
  br i1 %cmp74, label %if.then75, label %if.else77

if.then75:                                        ; preds = %if.then73
  %45 = load i32, ptr %result, align 4
  %sub76 = sub nsw i32 %45, 50
  store i32 %sub76, ptr %result, align 4
  br label %if.end79

if.else77:                                        ; preds = %if.then73
  %46 = load i32, ptr %result, align 4
  %add78 = add nsw i32 %46, 10
  store i32 %add78, ptr %result, align 4
  br label %if.end79

if.end79:                                         ; preds = %if.else77, %if.then75
  br label %if.end90

if.else80:                                        ; preds = %if.end71
  %47 = load i32, ptr %result, align 4
  %cmp81 = icmp slt i32 %47, 0
  br i1 %cmp81, label %if.then82, label %if.end89

if.then82:                                        ; preds = %if.else80
  %48 = load i32, ptr %j, align 4
  %cmp83 = icmp sgt i32 %48, 2
  br i1 %cmp83, label %if.then84, label %if.else86

if.then84:                                        ; preds = %if.then82
  %49 = load i32, ptr %result, align 4
  %add85 = add nsw i32 %49, 25
  store i32 %add85, ptr %result, align 4
  br label %if.end88

if.else86:                                        ; preds = %if.then82
  %50 = load i32, ptr %result, align 4
  %sub87 = sub nsw i32 %50, 5
  store i32 %sub87, ptr %result, align 4
  br label %if.end88

if.end88:                                         ; preds = %if.else86, %if.then84
  br label %if.end89

if.end89:                                         ; preds = %if.end88, %if.else80
  br label %if.end90

if.end90:                                         ; preds = %if.end89, %if.end79
  %51 = load i32, ptr %j, align 4
  %add91 = add nsw i32 %51, 1
  store i32 %add91, ptr %j, align 4
  br label %while.cond1, !llvm.loop !10

while.end92:                                      ; preds = %while.cond1
  %52 = load i32, ptr %i, align 4
  %rem93 = srem i32 %52, 3
  %cmp94 = icmp eq i32 %rem93, 0
  br i1 %cmp94, label %if.then95, label %if.end102

if.then95:                                        ; preds = %while.end92
  %53 = load i32, ptr %input.addr, align 4
  %cmp96 = icmp slt i32 %53, 25
  br i1 %cmp96, label %if.then97, label %if.else99

if.then97:                                        ; preds = %if.then95
  %54 = load i32, ptr %result, align 4
  %mul98 = mul nsw i32 %54, 2
  store i32 %mul98, ptr %result, align 4
  br label %if.end101

if.else99:                                        ; preds = %if.then95
  %55 = load i32, ptr %result, align 4
  %sub100 = sub nsw i32 %55, 5
  store i32 %sub100, ptr %result, align 4
  br label %if.end101

if.end101:                                        ; preds = %if.else99, %if.then97
  br label %if.end102

if.end102:                                        ; preds = %if.end101, %while.end92
  %56 = load i32, ptr %i, align 4
  %rem103 = srem i32 %56, 4
  %cmp104 = icmp eq i32 %rem103, 0
  br i1 %cmp104, label %if.then105, label %if.end117

if.then105:                                       ; preds = %if.end102
  %57 = load i32, ptr %result, align 4
  %cmp106 = icmp sgt i32 %57, 200
  br i1 %cmp106, label %if.then107, label %if.else109

if.then107:                                       ; preds = %if.then105
  %58 = load i32, ptr %result, align 4
  %div108 = sdiv i32 %58, 3
  store i32 %div108, ptr %result, align 4
  br label %if.end116

if.else109:                                       ; preds = %if.then105
  %59 = load i32, ptr %result, align 4
  %cmp110 = icmp slt i32 %59, 50
  br i1 %cmp110, label %if.then111, label %if.else113

if.then111:                                       ; preds = %if.else109
  %60 = load i32, ptr %result, align 4
  %add112 = add nsw i32 %60, 15
  store i32 %add112, ptr %result, align 4
  br label %if.end115

if.else113:                                       ; preds = %if.else109
  %61 = load i32, ptr %result, align 4
  %sub114 = sub nsw i32 %61, 10
  store i32 %sub114, ptr %result, align 4
  br label %if.end115

if.end115:                                        ; preds = %if.else113, %if.then111
  br label %if.end116

if.end116:                                        ; preds = %if.end115, %if.then107
  br label %if.end117

if.end117:                                        ; preds = %if.end116, %if.end102
  %62 = load i32, ptr %i, align 4
  %add118 = add nsw i32 %62, 1
  store i32 %add118, ptr %i, align 4
  br label %while.cond, !llvm.loop !11

while.end119:                                     ; preds = %while.cond
  %63 = load i32, ptr %result, align 4
  %cmp120 = icmp sgt i32 %63, 100
  br i1 %cmp120, label %if.then121, label %if.else128

if.then121:                                       ; preds = %while.end119
  %64 = load i32, ptr %input.addr, align 4
  %cmp122 = icmp sgt i32 %64, 40
  br i1 %cmp122, label %if.then123, label %if.else125

if.then123:                                       ; preds = %if.then121
  %65 = load i32, ptr %result, align 4
  %sub124 = sub nsw i32 %65, 100
  store i32 %sub124, ptr %result, align 4
  br label %if.end127

if.else125:                                       ; preds = %if.then121
  %66 = load i32, ptr %result, align 4
  %add126 = add nsw i32 %66, 50
  store i32 %add126, ptr %result, align 4
  br label %if.end127

if.end127:                                        ; preds = %if.else125, %if.then123
  br label %if.end137

if.else128:                                       ; preds = %while.end119
  %67 = load i32, ptr %result, align 4
  %cmp129 = icmp slt i32 %67, 0
  br i1 %cmp129, label %if.then130, label %if.end136

if.then130:                                       ; preds = %if.else128
  %68 = load i32, ptr %input.addr, align 4
  %cmp131 = icmp slt i32 %68, 10
  br i1 %cmp131, label %if.then132, label %if.else133

if.then132:                                       ; preds = %if.then130
  store i32 0, ptr %result, align 4
  br label %if.end135

if.else133:                                       ; preds = %if.then130
  %69 = load i32, ptr %result, align 4
  %70 = load i32, ptr %input.addr, align 4
  %add134 = add nsw i32 %69, %70
  store i32 %add134, ptr %result, align 4
  br label %if.end135

if.end135:                                        ; preds = %if.else133, %if.then132
  br label %if.end136

if.end136:                                        ; preds = %if.end135, %if.else128
  br label %if.end137

if.end137:                                        ; preds = %if.end136, %if.end127
  %71 = load i32, ptr %result, align 4
  ret i32 %71
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 18.0.0 (https://github.com/llvm/llvm-project.git bf87638a9d2771a75f59aa40296368cdec3e7353)"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
!11 = distinct !{!11, !7}
