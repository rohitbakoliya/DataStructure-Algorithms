//https://www.geeksforgeeks.org/coin-change-dp-7/

#include<bits/stdc++.h>
using namespace std;
const int N = 1003;
int n;
int a[N], vis[N][N], dp[N][N];
int solve(int pos, int s)
{
    if(pos==n) return s==0;
    int times=0;
    int &ans=dp[pos][s];
    if(vis[pos][s]) return dp[pos][s];
    vis[pos][s] = 1;
    while(times*a[pos] <= s) ans+=solve(pos+1, s - times*a[pos]), times++;
    return ans;
}
int main()
{
    int t, i, s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0 ;i<n ;i++) cin>>a[i];
        cin>>s;
        cout<<solve(0, s)<<endl;
        for(i=0 ; i<n ;i++)
        {
            for(int j=0 ;j<=s; j++)
            {
                dp[i][j]=0;
                vis[i][j]=0;
            }
        }
        
    }
}
