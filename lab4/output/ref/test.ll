; ModuleID = 'output/ref/test.bc'
source_filename = "output/ref/test.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @fib(i32 %x) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  %res1 = alloca i32, align 4
  %res2 = alloca i32, align 4
  %0 = load i32, ptr %x1, align 4
  %1 = icmp sle i32 %0, 1
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  store i32 5, ptr %res1, align 4
  br label %merge

merge:                                            ; preds = %else, %then
  ret i32 1

else:                                             ; preds = %entry
  %2 = load i32, ptr %x1, align 4
  %3 = sub i32 %2, 1
  %4 = call i32 @fib(i32 %3)
  store i32 %4, ptr %res1, align 4
  %5 = load i32, ptr %x1, align 4
  %6 = sub i32 %5, 2
  %7 = call i32 @fib(i32 %6)
  store i32 %7, ptr %res2, align 4
  br label %merge
}

define i32 @main() {
entry:
  %r = alloca i32, align 4
  %0 = call i32 @fib(i32 7)
  store i32 %0, ptr %r, align 4
  %1 = load i32, ptr %r, align 4
  call void @writeInt(i32 %1)
  call void @newLine()
  ret i32 0
}

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)
