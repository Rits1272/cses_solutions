#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(x) cout << "[" << #x << ": " << x << "]";
#define println(x) cout << "[" << #x << ": " << x << "]\n";
#define show(v) for(int i = 0; i < (int)v.size(); i++) cout << v[i] << " ";
#define deb(v) for(int i = 0; i < (int)v.size(); i++) {print(i) println(v[i])}
#define pb push_back
#define INF 1e17

const int NINF = -INF;
const int MOD = 1e9 + 7;

const int N = 5e3 + 5;
int n, m;
vector<array<int, 2>> adj[N];

vector<int> d;

void solve(){
	// Relaxations
	for(int k = 1; k < n; k++){
		for(int u = 0; u < n; u++){
			for(array<int, 2> x: adj[u]){
				if(d[u] == INF) continue;
				d[x[0]] = min(d[x[0]], d[u]+x[1]);
				d[x[0]] = max(d[x[0]], NINF);
			}
		}
	}

	// Detecting Negative Cycle
	for(int k = 1; k < n; k++){
		for(int u = 0; u < n; u++){
			for(array<int, 2> x: adj[u]){
				if(d[u] == INF) continue;
				if(d[x[0]] > d[u] + x[1]){
					d[x[0]] = NINF;
				}
			}
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m;
	d.resize(n, INF);
	d[0] = 0;
	for(int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w;
		--a, --b;
		adj[a].pb({b, -w});
	}
	solve();
	cout << (d[n-1] == NINF ? -1 : -d[n-1]);
	// cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " s" << '\n';
	return 0; 
}