 #include <stdio.h>

//	pointers value comperison
int pointerEqual(int *a, int *b){
    return *a==*b;
}


// Swop between to int pointers
void swopPointer(int *x, int *y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
}



void swopPointer_without_tmp(int *x, int *y){
    *x = *x + *y;  // Step 1
    *y = *x - *y;  // Step 2
    *x = *x - *y;  // Step 3
}



void swopPointer_without_tmp_2(int *x, int *y){
    //With xor
    *x = *x ^ *y;  // Step 1
    *y = *x ^ *y;  // Step 2
    *x = *x ^ *y;  // Step 3
}