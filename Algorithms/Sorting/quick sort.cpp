#include<bits/stdc++.h>
using namespace std;

int partition(int *a , int start , int end){
    int pivot = a[end];
    int pIndex = start;
    for(int i=start ; i<end; i++){
        if(a[i] <= pivot){
            swap(a[i] , a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex] , a[end]);
    return pIndex;

}

void quick_sort(int *a , int start , int end ){
    if(start < end){

        int pIndex = partition(a , start , end); 
        quick_sort(a ,start , pIndex - 1);
        quick_sort(a , pIndex + 1 , end);

    }
}

int main(){
    int a[] = {1 ,9 ,7, 8 , 5, 4,7 ,3, 5, 3, 1, 0};
    int n = sizeof(a)/sizeof(a[0]);
    quick_sort(a , 0 , n - 1);

    for(int x: a) cout<<x<<" ";
}
