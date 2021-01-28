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
int n, m, k;
int adj[N][N];

bool possible(int u, vector<bool> &seen, vector<int> &matchR){
	for(int v = 0; v < n; v++){
		if(adj[u][v] && !seen[v]){
			seen[v] = true;
			
			if(matchR[v] < 0 || possible(matchR[v], seen, matchR)){
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		int a, b; cin >> a >> b;
		--a, --b;
		// Pay important attention here
		adj[b][a] = 1;
	}
	
	vector<int> matchR(n, -1);
	int res = 0;
	
	for(int u = 0; u < m; u++){
		vector<bool> seen(n, false);
		if(possible(u, seen, matchR)){
			res++;
		}
	}
	cout << res << "\n";
	for(int i = 0; i < n; i++){
		if(matchR[i] != -1){
			cout << i+1 << " " <<  matchR[i]+1 << "\n";
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

