#include <bits/stdc++.h>
using namespace std;
int st[20]={0};
int lazy[20]={0};

/*1) If current segment tree node has any pending
update, then first add that pending update to
        current node.
2) If current node's range lies completely in
update query range.
....a) Update current node
....b) Postpone updates to children by setting
lazy value for children nodes.
3) If current node's range overlaps with update
range, follow the same approach as above simple
        update.
...a) Recur for left and right children.
...b) Update current node using results of left
and right calls*/
void build(int *a , int start , int end , int node)
{
    if(start == end)
    {
        st[node] = a[start];
        return;
    } else{
        int mid = (start + end)/2;
        build(a , start , mid , 2*node + 1);
        build(a , mid +1 , end , 2*node + 2);
        st[node] = st[2*node + 1 ] + st[2*node + 2];
    }
}
void update(int *a , int start , int end , int l , int r ,int node , int val )
{
    if(lazy[node]!=0)
    {
        st[node]+=/*(end - start + 1 ) **/ lazy[node];
        if(start!=end)//that is for non leaf nodes
        {
            lazy[2*node +1 ]+=lazy[node];
            lazy[2*node +2 ]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start > end  || start > r || end < l)
        return;
    if(l<=start && r>=end)
    {
        st[node]+=val;
        if(start!=end)//then propagate the value to the children's;
        {
            // Not leaf node
            lazy[2*node + 1]+=val;
            lazy[2*node + 2]+=val;
        }
        return;
    }
    int mid = (start + end)/2;
    update(a , start , mid , l , r,2*node + 1 , val);
    update(a , mid+1 , end , l , r,2*node + 2 , val);
    st[node] = st[2*node + 1] + st[2*node + 2];
}
int query(int *a , int start , int end , int l , int r , int node)
{
    if(lazy[node]!=0)
    {
        st[node] +=/*(end - start + 1 ) * */lazy[node];
        if(start!=end)
        {
            lazy[2*node + 1]+=lazy[node];
            lazy[2*node + 2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start > end || r< start || l>end)
        return 0;
    if(start>=l && end<=r)
    {
        return st[node];
    }
    int mid = (start + end)/2;
    int p1 = query(a , start , mid , l , r , 2*node + 1);
    int p2 = query(a , mid + 1 , end , l , r , 2*node + 2);
    return (p1 + p2);
}
int main()
{
    int a[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(a)/sizeof(a[0]);

    // Build segment tree from given array
    build(a , 0 , n-1 , 0);
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
           query(a , 0 , n-1 , 1, 3 , 0));

    // Add 10 to all nodes at indexes from 1 to 5.
    update(a , 0 , n-1, 1, 5, 0 , 10);
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
           query(a , 0 , n-1 , 1, 3 , 0));

    return 0;
}
