; ModuleID = 'output/local/test.bc'
source_filename = "output/local/test.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @this(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  ret i32 1
}
