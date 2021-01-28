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


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> pre(n);
	pre[0] = a[0];
	for(int i = 1; i < n; i++){
		pre[i] = pre[i-1]^a[i];
	}
	//show(pre)
	while(q--){
		int u, v; cin >> u >> v;
		--u, --v;
		cout << (pre[v]^(u?pre[u-1]:0)) << "\n"; 
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

