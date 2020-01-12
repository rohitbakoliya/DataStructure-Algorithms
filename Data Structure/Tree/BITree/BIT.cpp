#include <bits/stdc++.h>
using namespace std;
int BITree[100]={0};
void updateSum(int ind , int val , int n)
{
    ind++;
    while(ind <=n)
    {
        BITree[ind]+=val;
        ind+=ind&(-ind);
    }
}
int getSum(int ind)
{
    int sum=0;
    ind++;
    while(ind>0)
    {
        sum+=BITree[ind];
        ind-=ind&(-ind);
    }
    return sum;
}
void build(int *a , int n)
{
    for(int i=0 ; i<=n ; i++) BITree[i]=0;
    for(int i=0 ; i<n ; i++)
    {
        updateSum(i , a[i] , n);
    }
}

int main()
{
    int a[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a)/ sizeof(a[0]);
    build(a , n );
    cout<<getSum(5)<<endl;
    a[3]+=6;
    updateSum(3 , 6 , n );
    cout<<getSum(5)<<endl;

}
