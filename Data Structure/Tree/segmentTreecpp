#include <bits/stdc++.h>
using namespace std;
void build(const int*a , int start , int end , int* st , int node)
{
    if(start==end){
        st[node] = a[start];
        return;
    }
    else{
        int mid = (start + end)/2;
        build(a , start , mid , st , 2*node + 1);
        build(a , mid+1 , end , st , 2*node + 2);
        st[node] = st[2*node + 1]+st[2*node + 2];
    }

}
void update(int*a , int start , int end , int* st , int node , int ind , int val)
{
        if(start==end){
            st[node] = val;
            a[ind] = val;
            return;
        }
        else{
            int mid = (start + end)/2;
            if(start <= ind && ind <= mid){
                update(a , start , mid , st , 2*node +1 , ind , val);
            }
            else{
                update(a , mid +1 , end , st , 2*node + 2, ind , val);
            }
            st[node] = st[2*node + 1] + st[2*node + 2];
        }
}
int query(int* a, int start , int end , int l , int r , int* st , int node)
{
    if(r < start || l > end)
        return 0;
    if(l<=start && end<=r)
        return st[node];

    int mid =( start + end) / 2;
    int p1 = query(a , start , mid , l , r , st , 2*node + 1);
    int p2 = query(a , mid + 1 ,end , l , r , st , 2*node + 2);
    return (p1 + p2);
}

int main()
{
    int a[]={1, 3, 5, 7, 9, 11};
    int n = sizeof(a)/ sizeof(a[0]);

    int height  = (int)ceil(log2(n));
    int mx_sz = 2*pow(2 , height) + 1;
    int *st = new int[mx_sz];
    build(a , 0 , n-1 , st , 0);
    cout<<"Sum of values in given range = "<<query(a , 0 , n-1 , 1 , 3 ,  st, 0)<<endl;

    update(a, 0 , n-1 , st, 0 , 1, 10);

    cout<<"Updated sum of values in given range = "
        <<query(a , 0 , n-1 , 1 , 3 ,  st, 0)<<endl;
    return 0;

}
