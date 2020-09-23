//
//  main.c
//  Cse2320 - Lab 4
//
//  Created by Duy Nguyen on 10/24/18.
//  Copyright © 2018 Duy Nguyen. All rights reserved.
//  Description: Compute the kth smallest number in a sequence of n integers in the range 0 .... 999,999,999

#include <stdio.h>
//Isolate a specific digit  position from an int
//int pos - position index of an integer, the position index start at 1 in ascending order from right to left
//int num - an integer which needs to specify a digit  position
int isolateDigit (int pos, int num){
    int i;
    double exp = 10;
    for (i=0;i<pos-2;i++){
        exp *= 10;
    }
    return (int)(num/exp)%10;
}

//Counting Sort
//int inp[] - array of integers which needs to be sort
//int *n - pointer of size of inp[]
//int digitPos - digit position of an integer. This parameter tell count sort to sort base on a specific digit position of integers
//int *k - pointer of the smallest value index of a sequence
void countSort(int inp[],int *n, int digitPos, int *k){
    int i, count[10],slot[10];
    for (i=0;i<10;i++){
        count[i]=0;
    }
    //Phase 2 of counting Sort
    for (i=0;i<*n;i++){
        count[isolateDigit(digitPos,inp[i])]++;
    }
    
    //Phase 3 of counting Sort
    slot[0] = 0;
    for (i=1;i<10;i++){
        slot[i] = slot[i-1]+count[i-1];
    }
    
    //update new K ,new N to reduce sequence size for finding the kth smallest number
    int newN = 1 ,newK=0,newStartIndex = 0,newEndIndex = 0;
    for (i=1;i<10;i++){
        if (slot[i]>*k ){
            newStartIndex = slot[i-1];
            newEndIndex = slot[i];
            newN =  newEndIndex - newStartIndex;
            newK = *k - newStartIndex;
            break;
        }
    }

    //Phase 4 of counting Sort
    int out[*n];
    for (i=0; i<*n; i++) {
        out[slot[isolateDigit(digitPos,inp[i])]++] = inp[i];
    }
    
    //update newInp to cut the sequence size based on new K ,new N for finding the kth smallest number
    int newInp[newN];
    if (newN !=1 ){
        for (i= newStartIndex; i<newEndIndex+1; i++){
            newInp[i-newStartIndex]= out[i];
        }
    }
    else{
        newInp[0] = out[*k-1];
    }
    
    //change n ,k, inp[] as newN , newK, newInp[]. These below codes can be optimized but I keep it for the purpose of clearness.
    *n = newN;
    *k = newK;
     if (newN !=1 ){
        for (i=0;i<newN;i++){
            inp[i]= newInp[i];
        }
     }
     else{
         inp[0] = newInp[0];
     }
}

//Radix Sort
//inp[] - array of integers
//int *n - pointer of size of inp[]
//int *k - pointer of the smallest value index of a sequence
//int *stopDigitPos - pointer of stop digit position of an integer. This parameter help me to know which digit position has n =1.
void radixSort (int inp[], int *n,int *k, int *stopDigitPos) {
    int i;
    //Sort from the hundred millions digits to ones digits and stop it when the sequence size is reduced to 1.
    for (i=9;i>=1;i--){
        printf("position %d n %d\n", i,*n);
        countSort(inp, n, i,k);
        if (*n == 1) {
            *stopDigitPos = i;
            break;
        }
    }
}

int main(int argc, const char * argv[]) {
    int i,n,k,stopDigitPos;
    //insert the data
    scanf("%d %d",&n,&k);
    int startK = k;
    int inp[n];
    for (i=0; i<n; i++) {
        scanf("%d",&inp[i]);
    }
    
    radixSort(inp, &n, &k, &stopDigitPos);
    
    //Result Output
    printf("position %d n %d\n", stopDigitPos-1,n);
    printf("MSD 10 radix: The value with rank %d is %d\n",startK,inp[0]);
}
