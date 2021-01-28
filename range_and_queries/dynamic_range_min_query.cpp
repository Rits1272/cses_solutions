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

int n, q;

struct SegTree{
	vector<int> tree;
	
	SegTree(int n){
		tree.resize(4*n+1);
	}
	
	void build(int v, int tl, int tr, vector<int>&a){
		if(tl == tr){
			tree[v] = a[tl];
		}
		else{
			int tm = (tl + tr)/2;
			build(v*2, tl, tm, a);
			build(v*2+1, tm+1, tr, a);
			tree[v] = min(tree[v*2], tree[v*2+1]);
		}
	}
	
	int query(int v, int tl, int tr, int ql, int qr){
		if(ql > qr){
			return INF;
		}
		if(tl == ql && tr == qr){
			return tree[v];
		}
		int tm = (tl + tr)/2;
		return min(query(v*2, tl, tm, ql, min(tm, qr)), query(v*2+1, tm+1, tr, max(tm+1, ql), qr));
	}
	
	void update(int v, int tl, int tr, int pos, int val){
		if(tl == tr){
			tree[v] = val;
		}
		else{
			int tm = (tl + tr)/2;
			if(pos <= tm){
				update(v*2, tl, tm, pos, val);
			}
			else{
				update(v*2+1, tm+1, tr, pos, val);
			}
			tree[v] = min(tree[v*2], tree[v*2+1]);
		}
	}
};

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	SegTree segTree(n);
	segTree.build(1, 0, n-1, a);
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int k, u; cin >> k >> u;
			--k;
			segTree.update(1, 0, n-1, k, u);
		}
		else{
			int a, b; cin >> a >> b;
			--a, --b;
			cout << segTree.query(1, 0, n-1, a, b) << "\n";
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

