 #include <stdio.h>


// String to pointer
void pointerStringToArray(char *str, char emptyarr[]){
    auto int i;
    for (i=0;str[i];i++){   /*str[i] != NULL*/
        emptyarr[i]=str[i];
    }
}


// String character counter
int stringLength(char str[]){
    auto int count=0;
    auto int i;
    for(i=0; str[i]; i++) count++;
    return count;
}


// Swop chars
void swapChar(char *x, char *y){
    auto char tmp=*x;
    *x=*y;
    *y=*x;
}


// Swop the string
void stringSwop(char str[]){
    auto int i;
    auto int length=stringLength(str);
    for (i=0; i<=((length-1)/2); i++){
        swapChar(&str[i], &str[length-i-1]);
        /*char tmp=str[i];*/
        /*str[i]=str[length-i-1];*/
        /*str[length-i-1]=tmp;*/
    }
}


//	Compare 2 strings
int charCompare(char *str1, char *str2){
    auto int i;
    for(i=0; str1[i]&&str2[i]; i++){
            if(str1[i]!=str2[i]) return 0;
    } 
    if(str1[i]||str2[i]) return 0;
    return 1;
}