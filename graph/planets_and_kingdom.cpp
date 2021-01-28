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

const int N = 1e5;
int n, m;
vector<int> adj[N], radj[N];
vector<bool> vis(N);
vector<int> ans(N);

vector<int> order;

void dfs1(int u){
	vis[u] = true;
	for(int v: adj[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}
	order.pb(u);
}

void dfs2(int u,int k){
	vis[u] = true;
	ans[u] = k;
	//print(u) println(k)
	for(int v: radj[u]){
		if(!vis[v]){
			dfs2(v, k);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m;
	ans.resize(n);
	vis.resize(n);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		radj[v].pb(u);
	}
	vis.assign(n, false);
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	vis.assign(n, false);
	int k = 1;
	for(int i = 0; i < n; i++){
		int v = order[n-i-1];
		if(!vis[v]){
			dfs2(v, k);
			++k;
		}
	}
	set<int> s;
	for(int i = 0; i < n; i++){
		if(ans[i] == 0){
			ans[i] = k++;
		}
		s.insert(ans[i]);
	}
	cout << s.size() << "\n";
	show(ans);
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

