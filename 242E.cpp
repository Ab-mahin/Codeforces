// USER: "Ab.Mahin"
// Problem: E. XOR on Segment
// Contest: Codeforces - Codeforces Round 149 (Div. 2)
// URL: https://codeforces.com/contest/242/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], n;
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  long long t[4 * N][25], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    //t[n] = t[n] + lazy[n] * (e - b + 1);
    int d = (e - b + 1);
    for(int k = 0; k < 25; k++){
    	if(lazy[n] & (1 << k)){
    		t[n][k] = (d - t[n][k]);
    	}
    }
    
    if (b != e) {
      lazy[lc] = lazy[lc] ^ lazy[n];
      lazy[rc] = lazy[rc] ^ lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) {
    return a + b;
  }
  inline void pull(int n) {
  	for(int k = 0; k < 25; k++){
  		t[n][k] = t[lc][k] + t[rc][k];
  	}
    //t[n] = t[lc] + t[rc];
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      for(int k = 0; k < 25; k++){
      	if(a[b] & (1 << k)){
      		t[n][k] = 1;
      	}
      }
      
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j){
    	long long res = 0;
    	for(int k = 0; k < 25; k++){
    		res = (res + (1 << k) * t[n][k]);
    	}
    	return res;
    }
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
};
int32_t main() {
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    
    ST tr;
    tr.build(1, 1, n);
    
    int q;
    cin >> q;
    
    while(q--){
    	int op, l, r;
    	cin >> op >> l >> r;
    	
    	if(op & 1){
    		long long ans = tr.query(1, 1, n, l, r);
    		cout << ans << '\n';
    	}
    	else{
    		int v;
    		cin >> v;
    		tr.upd(1, 1, n, l, r, v);
    	}
    }
    
    
    
}