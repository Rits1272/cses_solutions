#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(x) cout << "[" << #x << ": " << x << "]";
#define println(x) cout << "[" << #x << ": " << x << "]\n";
#define show(v) for(int i = 0; i < (int)v.size(); i++) cout << v[i] << " ";
#define deb(v) for(int i = 0; i < (int)v.size(); i++) {print(i) println(v[i])}
#define pb push_back
#define INF 1e18 + 5
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, q, t[N], depth[N], ind[N], comp[N], nex[N];
int tmp[N], par[N][18];
vector<int> child[N], adj[N];
bool incyc[N];

void gencomp(int x, int i){
	if(comp[x]) return;
	comp[x] = u;
	for(int y: adj[x]){
		gencomp(y, i);
	}
}

void dfs(int x){
	int X = x;
	while(tmp[x] == 0){
		tmp[x] = X;
		x = t[x];
	}
	while(tmp[x] == X){
		
		}
}

void process(){
	for(int i = 1; i <= n; i++){
		dfs(i);
	}
	for(int i = 1; i <= n; i++){
		par[i][0] = t[i];
	}
	for(int i = 1; i <= 18; i++){
		par[j][i] = par[par[j][i-1]][i-1];
	}
	for(int i = 1; i <= n; i++){
		if(incyc[i]){
			DFS(i);
		}
	}
}


int32_t main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
        child[t[i]].pb(i);
		adj[i].pb(t[i]);
		adj[t[i]].pb(i);
    }
    
    for(int i = 1; i <= n; i++){
		if(comp[i] == 0){
			gencomp(i, i);
		}
	}
	
	process();
}
