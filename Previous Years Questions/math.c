 #include <stdio.h>

 
 //	Pow function X^a
int powX(int x, int a){
	int result=1;
    for(int i=1;i<=a;i++) result *= x;
    return result;
}


// is the number is first
int isFirst(int x){ //x>2
    if(x==0||x==1)return 0;
    if(x==2) return 1;
    for(int i=2; i<x; i++)
        if(x%i==0) return 0;
    return 1;
}


//	Firt numbers till n
int firstNumberCount(int n){
    if(n==0||n==1)return 0;
    int count=0;
    for(int i=2; i<=n; i++)
        if(isFirst(i)) count ++;
    return count;
}



