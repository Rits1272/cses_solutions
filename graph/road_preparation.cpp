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
int n, m, cost = 0;
vector<pair<int, pair<int, int>>> edge;
int tree_id[N], rnk[N];

int findset(int a){
	if(tree_id[a] != a){
		return tree_id[a] = findset(tree_id[a]);
	}
	return a;
}

void unionset(int a, int b){
	int x = findset(a), y = findset(b);
	if(rnk[x] > rnk[y]){
		tree_id[y] = x;
	}
	else{
		tree_id[x] = y;
		if(rnk[x] == rnk[y]){
			rnk[y]++;
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		tree_id[i] = i;
	}
	for(int i = 0; i < m; i++){
		int a, b, w; cin >> a >> b >> w;
		--a, --b;
		edge.pb({w, {a, b}});
	}
	sort(edge.begin(), edge.end()); // sort by weight
	int cnt = 0;
	for(int i = 0; i < m; i++){
		int x = edge[i].second.first, y = edge[i].second.second;
		if(findset(x) != findset(y)){
			cost += edge[i].first;
			unionset(x, y);
			++cnt;
		}
	}
	if(cnt == n-1){
		cout << cost;
	}
	else{
		cout << "IMPOSSIBLE\n";
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

