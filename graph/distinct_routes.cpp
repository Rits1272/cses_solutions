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
int adj[N][N], oadj[N][N];

vector<int> ans;
vector<bool> vis;
vector<int> p;

bool bfs(int s, int t, vector<int> &parent){
	vector<bool> vis(n, false);
	vis[s] = true;
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	while(q.size()){
		int u = q.front(); q.pop();
		for(int v = 0; v < n; v++){
			if(!vis[v] && adj[u][v] > 0){
				parent[v] = u;
				q.push(v);
				vis[v] = true;
			}
		}
	}
	return vis[t];
}

bool dfs(int u = 0){
	//println(u)
	if(u == n-1){
		while(u^0){
			ans.pb(u);
			u = p[u];
		}
		ans.pb(0);
		cout << ans.size() << "\n";
		reverse(ans.begin(), ans.end());
		for(int x: ans){
			cout << x+1 << " ";
		}
		ans.clear();
		cout << "\n";
		return true;
	}
	for(int v = 0; v < n; v++){
		if(!adj[u][v] && oadj[u][v]){
			p[v] = u;
			oadj[u][v] = 0;
			if(dfs(v)) return true;
		}
	}
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m;
	memset(adj, 0, sizeof(adj));
	memset(oadj, 0, sizeof(adj));
	for(int i= 0; i < m; i++){
		int a, b; cin >> a >> b;
		--a, --b;
		adj[a][b]++;
		oadj[a][b]++;
	}
	int flow = 0;
	int s = 0, t = n-1, u, v;
	vector<int> parent(n);
	p.assign(n, -1);
	while(bfs(s, t, parent)){
		int path_flow = INF;
		for(v=t;v!=s;v=parent[v]){
			u = parent[v];
			path_flow = min(path_flow, adj[u][v]);
		}
		for(v=t;v!=s;v=parent[v]){
			u = parent[v];
			adj[u][v] -= path_flow;
			adj[v][u] += path_flow;
		}
		flow += path_flow;
	}
	cout << flow << "\n";
	while(dfs(0));
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

