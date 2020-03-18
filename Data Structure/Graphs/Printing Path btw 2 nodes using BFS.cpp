//Referece : https://www.geeksforgeeks.org/shortest-path-unweighted-graph/
//Question Link : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/description/

#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
vector<int> v[1001];
bool visited[1001];
int x ,y;
int from[1001];
void bfs()
{
    queue< int > q;
    q.push(x);
    visited[x] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i=0 ; i<v[p].size() ; i++)
        {
            if(!visited[v[p][i]])
            {
                from[v[p][i]] = p;
                visited[v[p][i]] = true;
                q.push(v[p][i]);
                if(v[p][i]==y)
                {
                    return;
                }
                
            }
        }
        
    }
}

int main()
{
    FAST;
    int n, m , i ,j , t , c;
    cin >> n >> m >> t >> c;
    for(i=0 ; i<m ; i++)
    {
        int a , b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cin >> x >> y;
    if(m==0)
    {
        //since it is connected
        cout<<1<<endl;
        cout<<1<<endl;
        return 0;
    }
    for(i=1 ; i<=n ; i++)
    {
        sort(v[i].begin() , v[i].end());
    }
    bfs();
    vector< int > ans;
    ans.push_back(y);
    int s = from[y];
    while(s!=x)
    {
        ans.push_back(s);
        s = from[s];
    }
    ans.push_back(x);
    cout<<ans.size()<<endl;
    reverse(ans.begin() , ans.end());
    for(auto a : ans) cout<<a<<" ";
}


