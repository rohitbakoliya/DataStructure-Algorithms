#include <stdio.h>
void InsertionSort(int *a , int n ){

    for(int i=1 ; i<n   ; i++){

        int j= i-1;
        int value = a[i];

        while(j>=0 && value < a[j]){
            a[j + 1] = a[j];
            j--;
        }

        a[j+1] = value;
    }
    for(int i=0 ; i< 10 ; i++){
        printf("%d ", a[i]);
    }
}
int main() {

    int a[]={9 , 8 , 7 , 6 ,1 , 4 , 2, 5 ,3,0};
    InsertionSort(a , sizeof(a)/ sizeof(a[0]));
}
