#include<bits/stdc++.h>
using namespace std;
 
const int mxN = 1e5 + 5;
vector<int> adj[mxN];
int p[mxN], n, m;
bool visited[mxN];
vector<int> ans;
bool flag = false;
 
void dfs(int u, int pv = -1){
    p[u] = pv;
    visited[u] = true;
    for(int v: adj[u]){
	if(v == pv)
	    continue;
	if(visited[v]){
	    // backtrack here
	    int u2 = u;
	    while(u^v){
		ans.push_back(u);
		u = p[u];
	    }
	    ans.push_back(v);
	    ans.push_back(u2);
	    cout << ans.size() << "\n";
	    for(auto x: ans)
		cout << x << " ";
	    exit(0);
	}
	else
	    dfs(v, u);
    }
}
 
int main(){
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++){
	cin >> a >> b;
	adj[a].push_back(b);
	adj[b].push_back(a);
    }
    memset(visited, false, sizeof visited);
    for(int i=1; i<=n; i++){
	if(!visited[i])
	    dfs(i);
    }
    cout << "IMPOSSIBLE";
    return 0;
}
