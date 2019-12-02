#include<bits/stdc++.h>
using namespace std;

void merge(int *a , int n , int *l , int n1 , int *r , int n2){

    int i=0 , j=0 , k=0;
    while(i<n1 && j<n2){
        if(l[i] < r[j]){
            a[k++] = l[i++];
        }
        else{
            a[k++] = r[j++];
        }
    }
    while(i< n1){
        a[k++] = l[i++];
    }
    while(j<n2){
        a[k++] = r[j++];
    }
}

void merge_sort(int *a , int n ){

    if(n< 2)
        return;

    int mid = n/2;
    int l[mid] , r[n- mid];

    for(int i=0 ; i<mid ; i++){
        l[i] = a[i];
    }
    for(int i=mid ; i<n ; i++){
        r[i - mid] = a[i];
    }
    merge_sort(l , mid);
    merge_sort(r , n - mid);
    merge(a , n , l , mid , r , n- mid);
}

int main(){
    int a[] = {1 ,9 ,7, 8 , 5, 4,7 ,3, 5, 3, 1, 0};
    int n = sizeof(a)/sizeof(a[0]);
    merge_sort(a , n);

    for(int x: a) cout<<x<<" ";
}
