#include <stdio.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a,int  *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}