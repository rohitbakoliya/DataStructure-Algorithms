#include<bits/stdc++.h>
using namespace std;
int binary_search(int *a , int first , int last , int find){

    if(first <= last){
                int mid = first + (last - first)/2;
        if(a[mid]==find){
            return mid;
        }
        else if(a[mid] > find){
            return binary_search(a  , first , mid-1 , find);
        }
        else{
            return binary_search(a , mid+1 , last , find);
        }
    }
    return -1;
}

int main(){
    int a[] = {1 , 2, 3 , 4 , 5, 6 , 7 ,8 ,9 , 10 };
    int n = 10;
    int find = 11;
    if(binary_search(a,0 ,9 ,find )!=-1){
        cout<<"yes it is in array at! "<<binary_search(a,0 ,9 ,find )<<endl;
    }
    else{
        cout<<"not present\n";
    }
}
