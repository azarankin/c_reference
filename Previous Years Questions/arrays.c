 #include <stdio.h>

 //	Array swop, begin to end [1, 2, 3] to [3, 2, 1]
void arrSwop(int arr[], int arrLength){
    auto int i;
    auto int tmp;

    for (i=0; i<=((arrLength-1)/2); i++){
        tmp=arr[i];
        arr[i]=arr[arrLength-i-1];
        arr[arrLength-i-1]=tmp;
    }
}

//	The biggest value in the array
// Condition, at least 2 elements inside the array!
int biggest(int arr[], int arrLength){
    auto int b=arr[0];   //biggest
    auto int i;
    for (i=1;i<arrLength;i++)
        if (b<arr[i]) b=arr[i];
    return b;
}


//	The biggest 3rd element
#include <limits.h> // For INT_MIN
int biggest3(int arr[], int arrLength){
    auto int b1 = INT_MIN, b2 = INT_MIN, b3 = INT_MIN;
    auto int i;

    for (i=0; i< arrLength; i++){
        //if(arr[i]<b3) continue;
        if(arr[i]<=b2 && arr[i]>b3) b3=arr[i];
        else if(arr[i]<=b1 && arr[i]>b2) {b3=b2; b2=arr[i];}
        else if(arr[i]>=b1) {b3=b2; b2=b1; b1=arr[i];}
        }
    return b3;
}



void maina(){
    int arr[] = {10, 4, 3, 50, 23, 90};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    int result = biggest3(arr, arrLength);
}




// Turn array values 1 place left
void turnLeft(int arr[], int arrLength){
    auto int first=arr[0];  //first
    auto int i;

    for ( i = 0; i < arrLength - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[arrLength-1] = first;

}


// Turn array values 3 places left
void turnLeft3(int arr[], int arrLength){
        for(int i=1;i<=3; i++)
            turnLeft(arr, arrLength);
}


void turnLeft3_2(int arr[], int arrLength) {
    // Store the first 3 elements
    auto int first1 = arr[0];
    auto int first2 = arr[1];
    auto int first3 = arr[2];

    auto int i;

    // Shift everything left by 3
    for ( i = 0; i < arrLength - 3; i++) {
        arr[i] = arr[i + 3];
    }

    // Put the saved elements at the end
    arr[arrLength - 3] = first1;
    arr[arrLength - 2] = first2;
    arr[arrLength - 1] = first3;
}



//	Remove place from the array
void deleteArr(int arr[], int arrLength, int deletePlace){
    auto int i;
    for (i=deletePlace; i<(arrLength-1); i++)
        arr[i]=arr[i+1];
    arr[arrLength-1]=-1;
}



//	Merge 2 arrays
void mergeArray(int merge[], int arr1[], int length1, int arr2[], int length2){
    for(int i=0; i<length1; i++)
        merge[i]=arr1[i];
    for(int i=0; i<length2; i++)
        merge[length1+i]=arr2[i]; // continue merge array after [length1-1]
}



//	Merge 2 arrays with sorting
    // The 2 arrays is sorted
void mergeArraySort(int merge[], int arr1[], int length1, int arr2[], int length2){
    auto int i, j, m; //array1, array2, merged array counters
    i=j=m=0;
    while (i < length1 && j < length2) {
        if (arr1[i] <= arr2[j]) {
            merge[m++] = arr1[i++];
        } else {
            merge[m++] = arr2[j++];
        }
    }

    //one of the arrays is empty

    // Copy remaining elements from arr1 (if any)
    while (i < length1) {
        merge[m++] = arr1[i++];
    }

    // Copy remaining elements from arr2 (if any)
    while (j < length2) {
        merge[m++] = arr2[j++];
    }
}


void swop(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void swop(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}



//	Sort arrays
void bubleSortArray(int arr[], int arrLength){
    auto int i;
    for(i=0; i<arrLength; ++i )
        for(int j=i+1; j<arrLength; ++j )
            if(arr[i]>arr[j]){//swop values inside array for buble sort
                swop(&arr[i], &arr[j]);
                //int tmp=arr[i];
                //arr[i]=arr[j];
                //arr[j]=tmp;
            }
}



void swop_ptr(int** a, int** b)
{
    int* tmp = *a;
    *a = *b;
    *b = tmp;
}




// Print array
void printArr(int arr[], int arrLength){
        auto int i;
        for(i=0; i<arrLength; i++){
            printf("%i ", arr[i]);
        }
}