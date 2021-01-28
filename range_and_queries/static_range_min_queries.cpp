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

int n, q;
vector<int> tree(4*N);

struct SegTree{
	//vector<int> tree;
	SegTree(){
		tree.resize(4*n+1);
	}
	void build(int v, int tl, int tr, vector<int> &a){
		if(tl == tr){
			tree[v] = a[tl];
			return;
		}
		int tm = (tl + tr)/2;
		build(2*v, tl, tm, a);
		build(2*v+1, tm+1, tr, a);
		tree[v] = min(tree[2*v], tree[2*v+1]);
	}
	
	int query(int v, int tl, int tr, int ql, int qr){
		if(ql > tr || qr < tl){
			return INF;
		}
		if(tl >= ql && tr <= qr){
			return tree[v];
		}
		int tm = (tl + tr)/2;
		return min(query(2*v, tl, tm, ql, qr), query(2*v+1, tm+1, tr, ql, qr));
	}
};

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	int n, q; cin >> n >> q;
	vector<int> a(n);
	SegTree segtree;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	segtree.build(1, 0, n-1, a);
	while(q--){
		int a, b; cin >> a >> b;
		--a, --b;
		cout << segtree.query(1, 0, n-1, a, b) << "\n";
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

