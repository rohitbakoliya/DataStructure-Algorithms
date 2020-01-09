#include<bits/stdc++.h>
using namespace std;
int st[1000001];
void fill(){
    for(int i=0 ; i<=1000000 ; i++)
    st[i] = INT_MAX;
    
}
void build(int* a , int start , int end , int node)
{
    if(start==end){
        st[node]=a[start];
        
        return;
    }
    else{
        int mid = (start + end)/ 2;
        build(a , start , mid , 2*node + 1);
        build(a , mid+1 , end , 2*node + 2);
        st[node]=min(st[2*node+1] , st[2*node+2]);
    }
}
void update(int *a , int start , int end , int node , int ind , int val)
{
    if(start==end){
        a[ind] = val;
        st[node] = val;
        return;
    }
    else
    {
        int mid = (start + end)/2;
        if(start<=ind && ind<=mid){
            update(a , start , mid , 2*node + 1 , ind , val);
        }
        else{
            update(a , mid + 1 , end , 2*node + 2 , ind , val);
        }
        st[node] = std::min(st[2*node + 1],st[2*node + 2]);
    }
}
int query(int *a , int start , int end , int l , int r , int node)
{
    if(r<start || end<l)return INT_MAX;
    if(l<=start && r>=end) return st[node];

    int mid = (start + end)/2;
    int p1 = query(a , start , mid , l , r , 2*node + 1);
    int p2 = query(a , mid+1 , end , l , r , 2*node + 2);
    int mn = min(p1 ,p2);
    return mn;
}
int main()
{
    int n , q, i;
    cin>>n>>q;
    fill();
    int *a = new int[n];
    for(i=0 ;i<n ; i++){
      cin>>a[i];
    } 
    build(a , 0 , n-1 , 0);
    // for(i=0 ; i<15 ; i++)
    // {
    //     cout<<st[i]<<" ";
    // }
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='q')
        {
            int l , r;
            cin>>l>>r;
            l--, r--;
            cout<<query(a , 0 , n-1 , l , r , 0 )<<"\n";
        }
        else{
            int ind , val;
            cin>>ind>>val;
            ind--;
            update(a , 0 , n-1 , 0 , ind , val);
        }
    }
}
