/*
 * author : rits1272
 */

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(x) cerr << "[" << #x << ": " << x << "]";
#define println(x) cerr << "[" << #x << ": " << x << "]\n";
#define show(v) for(int i = 0; i < (int)v.size(); i++) cout << v[i] << (i == (int)v.size()-1 ? "\n" : " ");
#define deb(v) for(int i = 0; i < (int)v.size(); i++) {print(i) println(v[i])}
#define pb push_back
#define INF 1e18 + 5
const int MOD = 1e9 + 7;

const int N = 500;
int n, m;
int adj[N][N];
int oadj[N][N];

bool bfs(int s, int t, vector<int> &parent){
	vector<bool> vis(n, false);
	queue<int> q;
	q.push(s);
	vis[s] = true;
	parent[s] = -1;
	
	while(q.size()){
		int u = q.front(); q.pop();
		for(int v = 0; v < n; v++){
			if(!vis[v] && adj[u][v] > 0){
				q.push(v);
				parent[v] = u;
				vis[v] = true;
			}
		}
	}
	// if we find a augmented path
	return (vis[t] == true);
}

void dfs(int u, vector<bool> &vis){
	vis[u] = true;
	for(int v = 0; v < n; v++){
		if(!vis[v] && adj[u][v]){
			dfs(v, vis);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m;
	int u, v;
	memset(adj, 0, sizeof(adj));
	memset(oadj, 0, sizeof(oadj));
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		--a, --b;
		adj[a][b]++;
		adj[b][a]++;
		oadj[b][a]++;
		oadj[a][b]++;
	}
	int flow = 0;
	vector<int> parent(n);
	int s = 0, t = n-1;
	while(bfs(s, t, parent)){
		int path_flow = INF;
		for(v=t; v!=s; v=parent[v]){
			u = parent[v];
			path_flow = min(path_flow, adj[u][v]);
		}
		for(v=t; v!=s; v=parent[v]){
			u = parent[v];
			adj[u][v] -= path_flow;
			adj[v][u] += path_flow;
		}
		flow += path_flow;
	}
	cout << flow << "\n";
	
	vector<bool> vis(n, false);
	dfs(s, vis);
	// MAX FLOW = MIN CUT CAPACITIES
	for(int u = 0; u < n; u++){
		for(int v = 0; v < n; v++){
			if(vis[u] && !vis[v] && oadj[u][v]){
				cout << u+1 << " " << v+1 << "\n";
			}
		}
	}
	return 0; 
}

/*
 * Only write code when you are sure of the approach.
 * Do optimized thinking (Think which technique/observation can be used).
 * Do post analysis after the contest.
 * Upsolve the problems.
 * Learn a technique and solve some problems if its new to you.
 * DON'T GET STUCK ON ONE APPROACH
 */ 
