#include<bits/stdc++.h>
using namespace std;

void heapify(int *a , int n , int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n and a[l]> a[largest])
        largest = l;
    if( r<n and a[r] > a[largest])
        largest = r;

    if(largest!=i){
        swap(a[largest] , a[i]);
        heapify(a, n , largest);
    }
}


void heapsort(int*a , int n){
    //to heapify internal nodes
    for(int i=n/2 - 1 ; i>=0 ; i--){
        heapify(a , n , i);
    }

    //deletion of root node
    for(int i=n-1 ; i>=0 ; i--){
        swap(a[0] ,a[i]);
        //now size of heap is equal to i only and 
        //we have to again heapify wrt root i.e. pos 0
        heapify(a , i , 0);
    }

}

int main(){
    int a[] = {4, 10, 3, 5, 1 , 7 , 6};
    int n = 7;
    int root = 0;
    heapsort(a , n);
    for(int i : a) cout<<i<<" ";
}
