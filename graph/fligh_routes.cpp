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

const int N = 1e5 + 5;
int n, m;
vector<int> adj[N], radj[N];
vector<bool> vis1(N, false), vis2(N, false);

void dfs1(int u){
	vis1[u] = true;
	for(int v: adj[u]){
		if(!vis1[v]){
			dfs1(v);
		}
	}
}


void dfs2(int u){
	vis2[u] = true;
	for(int v: radj[u]){
		if(!vis2[v]){
			dfs2(v);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		radj[v].pb(u);
	}
	dfs1(1);
	dfs2(1);
	bool yes = true;
	for(int i = 1; i <= n; i++){
		if(!vis1[i] || !vis2[i]){
			yes = false;
			break;
		}
	}
	if(yes){
		cout << "YES\n";
		return 0;
	}
	else{
		cout << "NO\n";
		for(int i = 1; i <= n; i++){
			if(!vis1[i]){
				cout << "1 " << i << "\n";
				return 0;
			}
		}
		for(int i = 1; i <= n; i++){
			if(!vis2[i]){
				cout << i << " 1\n";
				return 0;
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

