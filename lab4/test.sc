#include "scio.h"
//int a;
//int c;
//int d;
//bool q;
//int b;
//int aa[5];
//bool bb[7];
//
int this(int a, int b);
int this(int a, int b);
//int this(int a, int b){
//    int q;
//    int nmsl;
//    bool wow;
//    int aaa[5];
//    bool bbb[7];
//
//    a = 1;
//    nmsl = nmsl;
//    aaa[3] = 5;
//    b = aaa[2];
//    a = 1 + 1 + 2+ 3;
//    a = 1 - aaa[2] - aaa[3];
//    b = 1 * 3 - q;
//    b = aaa[1] / aaa[4] * b + 5;
//    wow = 1 == a && true;
//    wow = aaa[3] <= b || bbb[1];
//    wow = q >= aaa[1] && 1 != b;
//    wow = q > aaa[1] && aaa[3] != a;
//    wow = q < aaa[1] || aaa[3] != a;
//    wow = q != aaa[1] || bbb[1];
//    wow = q != 7;
//    wow = !true;
//    wow = !false;
//    a = -23;
//    aaa[1] = -1;
//    b = -a;
//    b = -aaa[4];
//
//    return aaa[4];
//}
////bool that(bool a, bool b){
////    bool q;
////    bool wow;
////    bool aaa[5];
////    bool bbb[7];
////
////    a = true;
////    aaa[3] = false;
////    b = aaa[2];
////
////    q = a && b;
////    b = true || bbb[3];
////
////    //return aaa[4];
////    return false;
////}
////woooooooooooo
//
//void main(){
//    int retv;
//    int cc;
//    int dd;
//    int ddd[6];
//    dd = 4;
//
//    ddd[2] = this(cc, ddd[4]);
//    //ddd[2] = this(c, d);
//    a = 4;
//    while (ddd[2] >= 0){
//        int q;
//        int nmsl;
//        bool wow;
//        int aaa[5];
//        bool bbb[7];
//
//        a = 1;
//        nmsl = nmsl;
//        aaa[3] = 5;
//        b = aaa[2];
//        a = 1 + 1 + 2+ 3;
//        a = 1 - aaa[2] - aaa[3];
//        b = 1 * 3 - q;
//        b = aaa[1] / aaa[4] * b + 5;
//        wow = 1 == a && true;
//        wow = aaa[3] <= b || bbb[1];
//        wow = q >= aaa[1] && 1 != b;
//        wow = q > aaa[1] && aaa[3] != a;
//        wow = q < aaa[1] || aaa[3] != a;
//        wow = q != aaa[1] || bbb[1];
//        wow = q != 7;
//        wow = !true;
//        wow = !false;
//        a = -23;
//        aaa[1] = -1;
//        b = -a;
//        b = -aaa[4];
//        a = a-1;
//    }
//    if (ddd[2] >= 0){
//        int q;
//        int nmsl;
//        bool wow;
//        int aaa[5];
//        bool bbb[7];
//
//        a = 1;
//        nmsl = nmsl;
//        aaa[3] = 5;
//        b = aaa[2];
//        a = 1 + 1 + 2+ 3;
//        a = 1 - aaa[2] - aaa[3];
//        b = 1 * 3 - q;
//        b = aaa[1] / aaa[4] * b + 5;
//        wow = 1 == a && true;
//        wow = aaa[3] <= b || bbb[1];
//        wow = q >= aaa[1] && 1 != b;
//        wow = q > aaa[1] && aaa[3] != a;
//        wow = q < aaa[1] || aaa[3] != a;
//        wow = q != aaa[1] || bbb[1];
//        wow = q != 7;
//        wow = !true;
//        wow = !false;
//        a = -23;
//        aaa[1] = -1;
//        b = -a;
//        b = -aaa[4];
//        a = a-1;
//    } else {
//        int q;
//        int nmsl;
//        bool wow;
//        int aaa[5];
//        bool bbb[7];
//
//        a = 1;
//        nmsl = nmsl;
//        aaa[3] = 5;
//        b = aaa[2];
//        a = 1 + 1 + 2+ 3;
//        a = 1 - aaa[2] - aaa[3];
//        b = 1 * 3 - q;
//        b = aaa[1] / aaa[4] * b + 5;
//        wow = 1 == a && true;
//        wow = aaa[3] <= b || bbb[1];
//        wow = q >= aaa[1] && 1 != b;
//        wow = q > aaa[1] && aaa[3] != a;
//        wow = q < aaa[1] || aaa[3] != a;
//        wow = q != aaa[1] || bbb[1];
//        wow = q != 7;
//        wow = !true;
//        wow = !false;
//        a = -23;
//        aaa[1] = -1;
//        b = -a;
//        b = -aaa[4];
//        a = a-1;
//    }
//
//    return;
//}


int main() {
  int x;
  int y;
  int z;
  x = 1;
  y = 3;
  z = 11;
  
  while (x < 5 && z != 1) {
    if (y < 5) {
       writeInt(y);
       newLine();
       y = y + 1;
    }
    else {
       writeInt(-5);
       newLine();
    }
    writeInt(x);
    newLine();
    x = x + 1;
  }

  return 0;
}