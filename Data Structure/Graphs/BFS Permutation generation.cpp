//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/t1-1-6064aa64/

#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define F first
#define S second
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define one(x) cout<<#x<<" : "<<x<<endl;
#define two(x,y) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<endl;
#define three(x,y,z) cout<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<" , "<<#z<<" : "<<z<<endl;
#define PI acos(-1)
const int M = 1000000007;
const int N=3e5+5;


signed main()
{
    int n , i ,j;
    cin >> n;
    vector< int > v(n);
    string final  , cur;
    for(i=0 ; i<n ;i++) {
        cin >> v[i];
        cur.pb(char(v[i] + '0'));
        final.pb(char(i+1 + '0'));
    }
    queue< string > q;
    map< string , int > dis;
    q.push(cur);
    dis[cur] = 0;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur == final ){
            cout << dis[final] << endl;
        }
        for(i=2 ; i<=n ; i++)
        {
            string nxt = cur;
            reverse(nxt.begin() , nxt.begin() + i);
            if(dis.count(nxt)== 0){
                dis[nxt]= dis[cur] + 1;
                q.push(nxt);
            }
        }
    }
}


