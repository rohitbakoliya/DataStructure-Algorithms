#include<bits/stdc++.h>
using namespace std;
const int N = 1003;
int n, m;
int a[N][N], dp[N][N], visited[N][N];
//Returns the max sum you can achieve 
//when you start at (i,j) and end at (n-1, m-1)
//and move only in down and right directions
int solve(int i, int j)
{
    if(i==n-1 && j==m-1)return a[i][j];
    if(visited[i][j]) return dp[i][j];
    visited[i][j] = 1;
    int &ans = dp[i][j];
    if(i<n-1 && j<n-1)
    {
        ans = a[i][j] + max(solve(i+1, j) , solve(i, j+1));
    }
    else if(i==n-1)
    {
        ans = a[i][j] + solve(i, j+1);
    }
    else if(j==n-1){
        ans = a[i][j] + solve(i+1 , j);
    }
    return ans;
}
int main()
{
    int i, j;
    cin>>n>>m;
    for(i=0 ;i<n ;i++)
    {
        for(j=0; j<m ; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<solve(0, 0)<<endl;

}
//sample input
// 4 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
//output : 73
