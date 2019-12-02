#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int* a , int n ){

    for(int i=0 ; i<n - 1 ; i++){

        int MinPos = i;
        for(int j=i+1 ; j<n ; j++){

            if(a[j] < a[MinPos]){
                MinPos = j;
            }
        }
        swap(a[i] , a[MinPos] );
    }

    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
}

int main()
{
    int arr[] = {1 , 5 , 9 ,2, 5 ,0 , 6, 4, 8 , 7 };
    SelectionSort(arr , sizeof(arr)/sizeof(arr[0]));
}
