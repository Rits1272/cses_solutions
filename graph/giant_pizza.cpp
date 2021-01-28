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

const int N = 2e5 + 5;
int n, m;
vector<int> adj[N], radj[N];
vector<bool> vis(N, false);

vector<int> order, comp(N, -1);

void dfs1(int u){
	vis[u] = true;
	for(int v: adj[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}
	order.pb(u);
}

void dfs2(int u, int cl){
	vis[u] = true;
	comp[u] = cl;
	for(int v: radj[u]){
		if(!vis[v]){
			dfs2(v, cl);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		char x, y;
		int a, b;
		cin >> x >> a >> y >> b;
		if(x == '-'){
			a = 2*m-a+1;
		}
		if(y == '-'){
			b = 2*m-b+1;
		}
		adj[2*m-a+1].pb(b), adj[2*m-b+1].pb(a);
		radj[a].pb(2*m-b+1), radj[b].pb(2*m-a+1);
	}
	
	for(int i = 1; i <= 2*m; i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	
	vis.assign(N, false);
	int k = 0;
	for(auto x = order.rbegin(); x != order.rend(); x++){
		int v = *x;
		if(!vis[v]){
			dfs2(v, k++); 
		}
	}
	
	for(int i = 1; i <= m; i++){
		if(comp[i] == comp[2*m-i+1]){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		assignment[i] = comp[i] > comp[2*m-i+1];
	}
	
	for(int i = 1; i <= m; i++){
		cout << (assignment[i] ? '+' : '-') << " ";
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

