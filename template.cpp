/*
ID: "@rohitbakoliya"
PROG: 
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define sz(a) (a.size())
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define all(c) c.begin(), c.end()
#define pb push_back
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define F first
#define S second
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define endl "\n"
#define bsearch(arr,ind) (int)(lower_bound(all(arr),ind)-arr.begin())
#define fill(a,b) memset(a,b,sizeof(a))
#define bitcnt(n) __builtin_popcountll(n)
#define f(i , a , b) for(i=a ; i<b ; i++)
#define fe(i , a , b) for( i=a ; i<=b ; i++)
#define fr( i , a , b) for( i=a ; i>b ; i--)
#define fre( i , a , b) for( i=a ; i>=b ; i--)
#define debug(x) cout<<#x<<" : "<<x<<endl;
#define debug2(x,y) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<" , "<<#z<<" : "<<z<<endl;

#define PI acos(-1)
const int M = 1000000007;
const int N=3e5+5;
double phi = 1.61803398875;
int powmod(int a,int b){int res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}
int powmod(int a,int b,int M){int res=1;a%=M;for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res;}

int NcR(int n,int r){int p=1,k=1;if(n-r<r)r=n-r;if(r!=0){while(r){p*=n;k*=r;int m=__gcd(p,k);p/=m;k/=m;n--;r--;}}else p=1;return p;}
signed main()
{


}
