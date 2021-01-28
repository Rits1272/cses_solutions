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

int tree_id[N], sz[N];

int findset(int a){
	if(tree_id[a] != a){
		return tree_id[a] = findset(tree_id[a]);
	}
	return a;
}

void unionset(int a, int b){
	int x = findset(a), y = findset(b);
	if(x != y){
		if(sz[x] < sz[y]){
			swap(x, y);
		}
		tree_id[y] = x;
		sz[x] += sz[y];
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		tree_id[i] = i;
		sz[i] = 1;
	}
	int components = n;
	int mx = 1;
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		--a, --b;
		if(findset(a) != findset(b)){
			--components;
			unionset(a, b);
		}
		mx = max(mx, sz[findset(a)]);
		mx = max(mx, sz[findset(b)]);
		cout << components << " " << mx << "\n";
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

