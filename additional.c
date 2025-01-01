
//va_arg
#include <stdarg.h> //va_arg

double AddDouble(int x, ...){ // x= number of args
    va_list arglist; //...[1.5, 2.5, 3.5, 4.5]
    int i;
    double result = 0.0;

    printf("The number of arguments is: %d\n", x);
    va_start (arglist, x); //[1.5, 2.5, 3.5, 4.5], 4
            //void va_start(va_list ap, lastfix);
    for (i=0; i<x; i++) //i=0, 1, 2 ,3
        result += va_arg(arglist, double); //[1.5, 2.5, 3.5, 4.5], double
                //type va_arg(va_list ap, data_type)
    va_end (arglist);
    return result;
}
    

double d1 = 1.5;
double d2 = 2.5;
double d3 = 3.5;
double d4 = 4.5;

AddDouble(4, d1, d2, d3, d4);

AddDouble(1, d1);



// multy dimension Array
int array_int[2][3];
array_int[0][0] = 1;
array_int[0][1] = 2;
array_int[0][2] = 3;
array_int[1][0] = 4;
array_int[1][1] = 5;
array_int[1][2] = 6;
int array_int2[2][3] = {1, 2, 3, 4, 5, 6};
int array_int3[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
for (int i=0; i<2; i++){
    printf("\n");
    for (int j=0; j<3; j++)
    printf("%6d", array_int[i][j]);
}   //6characters distance if



//Structs
struct Person{
    int age;
    char *name;
    int height_in_cm;
};


struct Person hero = { 20, "Robin Hood", 191 };
struct Person john;

john.age = 31;
john.name = "John Little";
john.height_in_cm = 237;

printf("%s is %d years old and stands %dcm tall in his socks\n",
        john.name, john.age, john.height_in_cm);

printf( "He is often seen with %s.\n", hero.name );





//Threads
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* routine(){ //function
    printf("Test from thread\n");
    sleep(3);
    printf("Ending thread\n");
}


//pthread_t t1, t2;
pthread_t t1;
pthread_t t2;
int thread1body = pthread_create(&t1, NULL, &routine, NULL);
int thread2body = pthread_create(&t2, NULL, &routine, NULL);
    // always check errors!
    if(thread1body != 0) return 1;
    if(thread2body != 0) return 1;
int thread1join = pthread_join(t1, NULL);
int thread2join = pthread_join(t2, NULL);
    if(thread1join != 0) return 1;
    if(thread2join != 0) return 1;