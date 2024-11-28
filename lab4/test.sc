#include "scio.h"

int fib(int x){
    int res1;
    int res2;
    if(x <= 1)
        //return x;
        res1 = 5;
    else{
        res1 = fib(x-1);
        res2 = fib(x-2);
        //return res1 + res2;
    }
    return 1;
}

int main() {
    int r;
    r = fib(7);
    writeInt(r);
    newLine();
    return 0;
}