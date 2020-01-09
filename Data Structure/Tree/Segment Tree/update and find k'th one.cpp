#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);

int a[1000000]={0};
int st[4000001]={0};
void build(int* a , int start , int end , int node)
{
    if(start==end){
        st[node] = a[start];
        return;
    }
    int mid =( start + end )/2;
    build(a , start , mid , 2*node + 1);
    build(a , mid + 1 , end , 2*node + 2);
    st[node] = st[2*node + 1] + st[2*node + 2];
}
void update(int*a , int start , int end ,int ind, int node)
{
    if(start==end)
    {
        st[node]=0;
        a[ind] = 0;
        return;
    }
    int mid = (start + end)/2;
    if(start<=ind && ind<=mid){
        update(a , start , mid , ind , 2*node + 1);
    }
    else
    {
        update(a , mid+1 , end , ind , 2*node + 2);
    }
    st[node] = st[2*node + 1] + st[2*node + 2];
}
int query(int *a , int start , int end ,  int k, int node)
{
    if(start==end)
    {
        return end;
    }
    int mid = (start + end)/2;
    if(st[2*node+1] < k)
    {
        k -=st[2*node + 1];
        return query(a , mid+1 , end , k , 2*node + 2);
    }
    else{
        
        return query(a , start , mid , k , 2*node + 1);
    }
    
}
signed main()
{
    int n , i,q , j , t , k;
    cin>>n;
    for(i=0 ; i<n ; i++)
    {
        a[i]=1;
    }
    build(a, 0 ,n-1 , 0);
    cin>>q;
    while(q--)
    {
        cin>>t>>k;
        if(t==0){
            k--;
            update(a , 0 , n-1 , k , 0);
        }
        else{
            if(k > st[0])
            cout<<-1<<endl;
            else
            cout<<query(a , 0 , n-1 , k , 0) + 1<<endl;
        }
    }
    
    
}


