 #include <stdio.h>

 
 //	Pow function X^a
int powX(int x, int a){
	auto int result = x;
    for(int i=0;i<a-1;i++) result *= x;
    return result;
}


// is the number is first
int isFirst(int x){ //x>2
    auto int i;
    if(x==0||x==1)
        return 0;
    if(x==2)
        return 1;
    for(i=2; i<x; i++)
        if(x%i==0)
            return 0;
    return 1;
}


int isFirstFaster(int x){ //x>2
    auto int i;
    if(x==0||x==1)
        return 0;
    if(x==2)
        return 1;
    for(i=2; i * i <= x; i++) // i <= sqrt(x)
        if(x%i==0)
            return 0;
    return 1;
}


//	Firt numbers till n
int firstNumberCount(int n){
    auto int count = 0;
    auto int i;
    if(n==0||n==1)
        return 0;
    for(i=2; i<=n; i++)
        if(isFirst(i)) count ++;
    return count;
}



