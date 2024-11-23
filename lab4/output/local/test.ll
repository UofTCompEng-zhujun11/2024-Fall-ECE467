; ModuleID = 'output/local/test.bc'
source_filename = "output/local/test.bc"
target triple = "x86_64-unknown-linux-gnu"

@a = common global i32 0
@c = common global i32 0
@d = common global i32 0
@q = common global i1 false
@b = common global i32 0
@aa = common global [5 x i32] zeroinitializer
@bb = common global [7 x i1] zeroinitializer

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)

declare void @newLine()

declare i32 @readInt()

declare i1 @readBool()

define i32 @this(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %q = alloca i32, align 4
  %nmsl = alloca i32, align 4
  %wow = alloca i1, align 1
  %aaa = alloca [5 x i32], align 4
  %bbb = alloca [7 x i1], align 1
  store i32 1, ptr %a1, align 4
  %0 = load i32, ptr %nmsl, align 4
  store i32 %0, ptr %nmsl, align 4
  %1 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  store i32 5, ptr %1, align 4
  %2 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 2
  %3 = load i32, ptr %2, align 4
  store i32 %3, ptr %b2, align 4
  store i32 7, ptr %a1, align 4
  %4 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 2
  %5 = load i32, ptr %4, align 4
  %6 = sub i32 1, %5
  %7 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  %8 = load i32, ptr %7, align 4
  %9 = sub i32 %6, %8
  store i32 %9, ptr %a1, align 4
  %10 = load i32, ptr %q, align 4
  %11 = sub i32 3, %10
  store i32 %11, ptr %b2, align 4
  %12 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %13 = load i32, ptr %12, align 4
  %14 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 4
  %15 = load i32, ptr %14, align 4
  %16 = sdiv i32 %13, %15
  %17 = load i32, ptr %b2, align 4
  %18 = mul i32 %16, %17
  %19 = add i32 %18, 5
  store i32 %19, ptr %b2, align 4
  %20 = load i32, ptr %a1, align 4
  %21 = icmp eq i32 1, %20
  %22 = and i1 %21, true
  store i1 %22, ptr %wow, align 1
  %23 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  %24 = load i32, ptr %23, align 4
  %25 = load i32, ptr %b2, align 4
  %26 = icmp sle i32 %24, %25
  %27 = getelementptr [7 x i1], ptr %bbb, i32 0, i32 1
  %28 = load i1, ptr %27, align 1
  %29 = or i1 %26, %28
  store i1 %29, ptr %wow, align 1
  %30 = load i32, ptr %q, align 4
  %31 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %32 = load i32, ptr %31, align 4
  %33 = icmp sge i32 %30, %32
  %34 = load i32, ptr %b2, align 4
  %35 = icmp ne i32 1, %34
  %36 = and i1 %33, %35
  store i1 %36, ptr %wow, align 1
  %37 = load i32, ptr %q, align 4
  %38 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %39 = load i32, ptr %38, align 4
  %40 = icmp sgt i32 %37, %39
  %41 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  %42 = load i32, ptr %41, align 4
  %43 = load i32, ptr %a1, align 4
  %44 = icmp ne i32 %42, %43
  %45 = and i1 %40, %44
  store i1 %45, ptr %wow, align 1
  %46 = load i32, ptr %q, align 4
  %47 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %48 = load i32, ptr %47, align 4
  %49 = icmp slt i32 %46, %48
  %50 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  %51 = load i32, ptr %50, align 4
  %52 = load i32, ptr %a1, align 4
  %53 = icmp ne i32 %51, %52
  %54 = or i1 %49, %53
  store i1 %54, ptr %wow, align 1
  %55 = load i32, ptr %q, align 4
  %56 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %57 = load i32, ptr %56, align 4
  %58 = icmp ne i32 %55, %57
  %59 = getelementptr [7 x i1], ptr %bbb, i32 0, i32 1
  %60 = load i1, ptr %59, align 1
  %61 = or i1 %58, %60
  store i1 %61, ptr %wow, align 1
  %62 = load i32, ptr %q, align 4
  %63 = icmp ne i32 %62, 7
  store i1 %63, ptr %wow, align 1
  store i1 false, ptr %wow, align 1
  store i1 true, ptr %wow, align 1
  store i32 -23, ptr %a1, align 4
  %64 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  store i32 -1, ptr %64, align 4
  %65 = load i32, ptr %a1, align 4
  %66 = sub i32 0, %65
  store i32 %66, ptr %b2, align 4
  %67 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 4
  %68 = load i32, ptr %67, align 4
  %69 = sub i32 0, %68
  store i32 %69, ptr %b2, align 4
  %70 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 4
  %71 = load i32, ptr %70, align 4
  ret i32 %71
}

define i1 @that(i1 zeroext %a, i1 zeroext %b) {
entry:
  %a1 = alloca i1, align 1
  store i1 %a, ptr %a1, align 1
  %b2 = alloca i1, align 1
  store i1 %b, ptr %b2, align 1
  %q = alloca i1, align 1
  %wow = alloca i1, align 1
  %aaa = alloca [5 x i1], align 1
  %bbb = alloca [7 x i1], align 1
  store i1 true, ptr %a1, align 1
  %0 = getelementptr [5 x i1], ptr %aaa, i32 0, i32 3
  store i1 false, ptr %0, align 1
  %1 = getelementptr [5 x i1], ptr %aaa, i32 0, i32 2
  %2 = load i1, ptr %1, align 1
  store i1 %2, ptr %b2, align 1
  %3 = load i1, ptr %a1, align 1
  %4 = load i1, ptr %b2, align 1
  %5 = and i1 %3, %4
  store i1 %5, ptr %q, align 1
  %6 = getelementptr [7 x i1], ptr %bbb, i32 0, i32 3
  %7 = load i1, ptr %6, align 1
  %8 = or i1 true, %7
  store i1 %8, ptr %b2, align 1
  ret i1 false
}

define void @main2() {
entry:
  %retv = alloca i32, align 4
  %cc = alloca i32, align 4
  %dd = alloca i32, align 4
  %ddd = alloca [6 x i32], align 4
  %maka = alloca i1, align 1
  store i32 4, ptr %dd, align 4
  %0 = load i32, ptr %cc, align 4
  %1 = getelementptr [6 x i32], ptr %ddd, i32 0, i32 4
  %2 = load i32, ptr %1, align 4
  %3 = call i32 @this(i32 %0, i32 %2)
  %4 = getelementptr [6 x i32], ptr %ddd, i32 0, i32 2
  store i32 %3, ptr %4, align 4
  %5 = load i1, ptr %maka, align 1
  %6 = call i1 @that(i1 true, i1 %5)
  store i1 %6, ptr %maka, align 1
  store i32 4, ptr @a, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %7 = getelementptr [6 x i32], ptr %ddd, i32 0, i32 2
  %8 = load i32, ptr %7, align 4
  %9 = icmp sge i32 %8, 0
  br i1 %9, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %q = alloca i32, align 4
  %nmsl = alloca i32, align 4
  %wow = alloca i1, align 1
  %aaa = alloca [5 x i32], align 4
  %bbb = alloca [7 x i1], align 1
  store i32 1, ptr @a, align 4
  %10 = load i32, ptr %nmsl, align 4
  store i32 %10, ptr %nmsl, align 4
  %11 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  store i32 5, ptr %11, align 4
  %12 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 2
  %13 = load i32, ptr %12, align 4
  store i32 %13, ptr @b, align 4
  store i32 7, ptr @a, align 4
  %14 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 2
  %15 = load i32, ptr %14, align 4
  %16 = sub i32 1, %15
  %17 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  %18 = load i32, ptr %17, align 4
  %19 = sub i32 %16, %18
  store i32 %19, ptr @a, align 4
  %20 = load i32, ptr %q, align 4
  %21 = sub i32 3, %20
  store i32 %21, ptr @b, align 4
  %22 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %23 = load i32, ptr %22, align 4
  %24 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 4
  %25 = load i32, ptr %24, align 4
  %26 = sdiv i32 %23, %25
  %27 = load i32, ptr @b, align 4
  %28 = mul i32 %26, %27
  %29 = add i32 %28, 5
  store i32 %29, ptr @b, align 4
  %30 = load i32, ptr @a, align 4
  %31 = icmp eq i32 1, %30
  %32 = and i1 %31, true
  store i1 %32, ptr %wow, align 1
  %33 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  %34 = load i32, ptr %33, align 4
  %35 = load i32, ptr @b, align 4
  %36 = icmp sle i32 %34, %35
  %37 = getelementptr [7 x i1], ptr %bbb, i32 0, i32 1
  %38 = load i1, ptr %37, align 1
  %39 = or i1 %36, %38
  store i1 %39, ptr %wow, align 1
  %40 = load i32, ptr %q, align 4
  %41 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %42 = load i32, ptr %41, align 4
  %43 = icmp sge i32 %40, %42
  %44 = load i32, ptr @b, align 4
  %45 = icmp ne i32 1, %44
  %46 = and i1 %43, %45
  store i1 %46, ptr %wow, align 1
  %47 = load i32, ptr %q, align 4
  %48 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %49 = load i32, ptr %48, align 4
  %50 = icmp sgt i32 %47, %49
  %51 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  %52 = load i32, ptr %51, align 4
  %53 = load i32, ptr @a, align 4
  %54 = icmp ne i32 %52, %53
  %55 = and i1 %50, %54
  store i1 %55, ptr %wow, align 1
  %56 = load i32, ptr %q, align 4
  %57 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %58 = load i32, ptr %57, align 4
  %59 = icmp slt i32 %56, %58
  %60 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 3
  %61 = load i32, ptr %60, align 4
  %62 = load i32, ptr @a, align 4
  %63 = icmp ne i32 %61, %62
  %64 = or i1 %59, %63
  store i1 %64, ptr %wow, align 1
  %65 = load i32, ptr %q, align 4
  %66 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  %67 = load i32, ptr %66, align 4
  %68 = icmp ne i32 %65, %67
  %69 = getelementptr [7 x i1], ptr %bbb, i32 0, i32 1
  %70 = load i1, ptr %69, align 1
  %71 = or i1 %68, %70
  store i1 %71, ptr %wow, align 1
  %72 = load i32, ptr %q, align 4
  %73 = icmp ne i32 %72, 7
  store i1 %73, ptr %wow, align 1
  store i1 false, ptr %wow, align 1
  store i1 true, ptr %wow, align 1
  store i32 -23, ptr @a, align 4
  %74 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 1
  store i32 -1, ptr %74, align 4
  %75 = load i32, ptr @a, align 4
  %76 = sub i32 0, %75
  store i32 %76, ptr @b, align 4
  %77 = getelementptr [5 x i32], ptr %aaa, i32 0, i32 4
  %78 = load i32, ptr %77, align 4
  %79 = sub i32 0, %78
  store i32 %79, ptr @b, align 4
  %80 = load i32, ptr @a, align 4
  %81 = sub i32 %80, 1
  store i32 %81, ptr @a, align 4
  br label %while.cond

while.exit:                                       ; preds = %while.cond
  %82 = getelementptr [6 x i32], ptr %ddd, i32 0, i32 2
  %83 = load i32, ptr %82, align 4
  %84 = icmp sge i32 %83, 0
  br i1 %84, label %then, label %else

then:                                             ; preds = %while.exit
  %q1 = alloca i32, align 4
  %nmsl2 = alloca i32, align 4
  %wow3 = alloca i1, align 1
  %aaa4 = alloca [5 x i32], align 4
  %bbb5 = alloca [7 x i1], align 1
  store i32 1, ptr @a, align 4
  %85 = load i32, ptr %nmsl2, align 4
  store i32 %85, ptr %nmsl2, align 4
  %86 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 3
  store i32 5, ptr %86, align 4
  %87 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 2
  %88 = load i32, ptr %87, align 4
  store i32 %88, ptr @b, align 4
  store i32 7, ptr @a, align 4
  %89 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 2
  %90 = load i32, ptr %89, align 4
  %91 = sub i32 1, %90
  %92 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 3
  %93 = load i32, ptr %92, align 4
  %94 = sub i32 %91, %93
  store i32 %94, ptr @a, align 4
  %95 = load i32, ptr %q1, align 4
  %96 = sub i32 3, %95
  store i32 %96, ptr @b, align 4
  %97 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 1
  %98 = load i32, ptr %97, align 4
  %99 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 4
  %100 = load i32, ptr %99, align 4
  %101 = sdiv i32 %98, %100
  %102 = load i32, ptr @b, align 4
  %103 = mul i32 %101, %102
  %104 = add i32 %103, 5
  store i32 %104, ptr @b, align 4
  %105 = load i32, ptr @a, align 4
  %106 = icmp eq i32 1, %105
  %107 = and i1 %106, true
  store i1 %107, ptr %wow3, align 1
  %108 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 3
  %109 = load i32, ptr %108, align 4
  %110 = load i32, ptr @b, align 4
  %111 = icmp sle i32 %109, %110
  %112 = getelementptr [7 x i1], ptr %bbb5, i32 0, i32 1
  %113 = load i1, ptr %112, align 1
  %114 = or i1 %111, %113
  store i1 %114, ptr %wow3, align 1
  %115 = load i32, ptr %q1, align 4
  %116 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 1
  %117 = load i32, ptr %116, align 4
  %118 = icmp sge i32 %115, %117
  %119 = load i32, ptr @b, align 4
  %120 = icmp ne i32 1, %119
  %121 = and i1 %118, %120
  store i1 %121, ptr %wow3, align 1
  %122 = load i32, ptr %q1, align 4
  %123 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 1
  %124 = load i32, ptr %123, align 4
  %125 = icmp sgt i32 %122, %124
  %126 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 3
  %127 = load i32, ptr %126, align 4
  %128 = load i32, ptr @a, align 4
  %129 = icmp ne i32 %127, %128
  %130 = and i1 %125, %129
  store i1 %130, ptr %wow3, align 1
  %131 = load i32, ptr %q1, align 4
  %132 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 1
  %133 = load i32, ptr %132, align 4
  %134 = icmp slt i32 %131, %133
  %135 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 3
  %136 = load i32, ptr %135, align 4
  %137 = load i32, ptr @a, align 4
  %138 = icmp ne i32 %136, %137
  %139 = or i1 %134, %138
  store i1 %139, ptr %wow3, align 1
  %140 = load i32, ptr %q1, align 4
  %141 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 1
  %142 = load i32, ptr %141, align 4
  %143 = icmp ne i32 %140, %142
  %144 = getelementptr [7 x i1], ptr %bbb5, i32 0, i32 1
  %145 = load i1, ptr %144, align 1
  %146 = or i1 %143, %145
  store i1 %146, ptr %wow3, align 1
  %147 = load i32, ptr %q1, align 4
  %148 = icmp ne i32 %147, 7
  store i1 %148, ptr %wow3, align 1
  store i1 false, ptr %wow3, align 1
  store i1 true, ptr %wow3, align 1
  store i32 -23, ptr @a, align 4
  %149 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 1
  store i32 -1, ptr %149, align 4
  %150 = load i32, ptr @a, align 4
  %151 = sub i32 0, %150
  store i32 %151, ptr @b, align 4
  %152 = getelementptr [5 x i32], ptr %aaa4, i32 0, i32 4
  %153 = load i32, ptr %152, align 4
  %154 = sub i32 0, %153
  store i32 %154, ptr @b, align 4
  %155 = load i32, ptr @a, align 4
  %156 = sub i32 %155, 1
  store i32 %156, ptr @a, align 4
  br label %merge

merge:                                            ; preds = %else, %then
  ret void

else:                                             ; preds = %while.exit
  %q6 = alloca i32, align 4
  %nmsl7 = alloca i32, align 4
  %wow8 = alloca i1, align 1
  %aaa9 = alloca [5 x i32], align 4
  %bbb10 = alloca [7 x i1], align 1
  store i32 1, ptr @a, align 4
  %157 = load i32, ptr %nmsl7, align 4
  store i32 %157, ptr %nmsl7, align 4
  %158 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 3
  store i32 5, ptr %158, align 4
  %159 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 2
  %160 = load i32, ptr %159, align 4
  store i32 %160, ptr @b, align 4
  store i32 7, ptr @a, align 4
  %161 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 2
  %162 = load i32, ptr %161, align 4
  %163 = sub i32 1, %162
  %164 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 3
  %165 = load i32, ptr %164, align 4
  %166 = sub i32 %163, %165
  store i32 %166, ptr @a, align 4
  %167 = load i32, ptr %q6, align 4
  %168 = sub i32 3, %167
  store i32 %168, ptr @b, align 4
  %169 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 1
  %170 = load i32, ptr %169, align 4
  %171 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 4
  %172 = load i32, ptr %171, align 4
  %173 = sdiv i32 %170, %172
  %174 = load i32, ptr @b, align 4
  %175 = mul i32 %173, %174
  %176 = add i32 %175, 5
  store i32 %176, ptr @b, align 4
  %177 = load i32, ptr @a, align 4
  %178 = icmp eq i32 1, %177
  %179 = and i1 %178, true
  store i1 %179, ptr %wow8, align 1
  %180 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 3
  %181 = load i32, ptr %180, align 4
  %182 = load i32, ptr @b, align 4
  %183 = icmp sle i32 %181, %182
  %184 = getelementptr [7 x i1], ptr %bbb10, i32 0, i32 1
  %185 = load i1, ptr %184, align 1
  %186 = or i1 %183, %185
  store i1 %186, ptr %wow8, align 1
  %187 = load i32, ptr %q6, align 4
  %188 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 1
  %189 = load i32, ptr %188, align 4
  %190 = icmp sge i32 %187, %189
  %191 = load i32, ptr @b, align 4
  %192 = icmp ne i32 1, %191
  %193 = and i1 %190, %192
  store i1 %193, ptr %wow8, align 1
  %194 = load i32, ptr %q6, align 4
  %195 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 1
  %196 = load i32, ptr %195, align 4
  %197 = icmp sgt i32 %194, %196
  %198 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 3
  %199 = load i32, ptr %198, align 4
  %200 = load i32, ptr @a, align 4
  %201 = icmp ne i32 %199, %200
  %202 = and i1 %197, %201
  store i1 %202, ptr %wow8, align 1
  %203 = load i32, ptr %q6, align 4
  %204 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 1
  %205 = load i32, ptr %204, align 4
  %206 = icmp slt i32 %203, %205
  %207 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 3
  %208 = load i32, ptr %207, align 4
  %209 = load i32, ptr @a, align 4
  %210 = icmp ne i32 %208, %209
  %211 = or i1 %206, %210
  store i1 %211, ptr %wow8, align 1
  %212 = load i32, ptr %q6, align 4
  %213 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 1
  %214 = load i32, ptr %213, align 4
  %215 = icmp ne i32 %212, %214
  %216 = getelementptr [7 x i1], ptr %bbb10, i32 0, i32 1
  %217 = load i1, ptr %216, align 1
  %218 = or i1 %215, %217
  store i1 %218, ptr %wow8, align 1
  %219 = load i32, ptr %q6, align 4
  %220 = icmp ne i32 %219, 7
  store i1 %220, ptr %wow8, align 1
  store i1 false, ptr %wow8, align 1
  store i1 true, ptr %wow8, align 1
  store i32 -23, ptr @a, align 4
  %221 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 1
  store i32 -1, ptr %221, align 4
  %222 = load i32, ptr @a, align 4
  %223 = sub i32 0, %222
  store i32 %223, ptr @b, align 4
  %224 = getelementptr [5 x i32], ptr %aaa9, i32 0, i32 4
  %225 = load i32, ptr %224, align 4
  %226 = sub i32 0, %225
  store i32 %226, ptr @b, align 4
  %227 = load i32, ptr @a, align 4
  %228 = sub i32 %227, 1
  store i32 %228, ptr @a, align 4
  br label %merge
}

define i32 @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %z = alloca i32, align 4
  store i32 1, ptr %x, align 4
  store i32 3, ptr %y, align 4
  store i32 11, ptr %z, align 4
  br label %while.cond

while.cond:                                       ; preds = %merge, %entry
  %0 = load i32, ptr %x, align 4
  %1 = icmp slt i32 %0, 5
  %2 = load i32, ptr %z, align 4
  %3 = icmp ne i32 %2, 1
  %4 = and i1 %1, %3
  br i1 %4, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %5 = load i32, ptr %y, align 4
  %6 = icmp slt i32 %5, 5
  br i1 %6, label %then, label %else

while.exit:                                       ; preds = %while.cond
  ret i32 0

then:                                             ; preds = %while.body
  %7 = load i32, ptr %y, align 4
  call void @writeInt(i32 %7)
  call void @newLine()
  %8 = load i32, ptr %y, align 4
  %9 = add i32 %8, 1
  store i32 %9, ptr %y, align 4
  br label %merge

merge:                                            ; preds = %else, %then
  %10 = load i32, ptr %x, align 4
  call void @writeInt(i32 %10)
  call void @newLine()
  %11 = load i32, ptr %x, align 4
  %12 = add i32 %11, 1
  store i32 %12, ptr %x, align 4
  br label %while.cond

else:                                             ; preds = %while.body
  call void @writeInt(i32 -5)
  call void @newLine()
  br label %merge
}
