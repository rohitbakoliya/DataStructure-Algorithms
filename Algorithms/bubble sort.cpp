#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int *a , int n ){

    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j< n-i-1 ; j++){

            if(a[j]> a[j+1]){
                swap(a[j] , a[j+1]);
            }
        }
    }
    for(int i=0 ;i<n ; i++){
        cout<<a[i]<<" ";
    }
}

int main(){

    int a[] = {1 , 9 , 4 , 2, 3 , 6,5, 0 , 1 , 8};
    BubbleSort(a , sizeof(a)/sizeof(a[0]));
}
