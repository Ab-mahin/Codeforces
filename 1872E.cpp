// USER: "Ab.Mahin"
// Problem: E. Data Structures Fan
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define ll int

const int N = 2e5 + 1;
int a[N], B[N], g;
string s;
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  long long t[4 * N], lazy[4 * N], vxora[4 * N], vxorb[4 * N];
  
  inline void push(int n, int b, int e) {
    if (lazy[n] % 2 == 0) return;
    t[n] = (e - b + 1) - t[n];
    swap(vxora[n], vxorb[n]);
    
    if (b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) {
    return (a ^ b);
  }
  inline void pull(int n) {
    t[n] = t[lc] + t[rc];
    vxora[n] = vxora[lc] ^ vxora[rc];
    vxorb[n] = vxorb[lc] ^ vxorb[rc];
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    vxora[n] = 0;
    vxorb[n] = 0;
    if (b == e) {
      t[n] = B[b];
      if(s[b] == '1') vxora[n] = a[b];
      else vxorb[n] = a[b];
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
      lazy[n] += v; //set lazy
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
    	if(g){
    		return vxora[n];
    	}
    	else return vxorb[n];
    }
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
};
int32_t main() {
    
    ios_base::sync_with_stdio(0);
  	cin.tie(0);
    
    ll t = 1;
    cin >> t;
    
    while(t--){
    	ll n;
    	cin >> n;
    	
    	for(ll i = 0; i < n; i++){
    		cin >> a[i];
    	}
    	    	
    	ST st;
    	
    	cin >> s;
    	st.build(1, 0, n - 1);
    	
    	for(ll i = 0; i < n; i++){
    		B[i] = s[i] - '0';
    	}
    	
    	ll q;
    	cin >> q;
    	
    	while(q--){
    		
    		ll op;
    		cin >> op;
    		if(op & 1){
    			ll l, r;
    			cin >> l >> r;
    			l--,r--;
    			st.upd(1, 0, n - 1, l, r, 1);
    		}
    		else{
    			cin >> g;
    			cout << st.query(1, 0, n - 1, 0, n - 1) << ' ';    			
    		}
    	}
    	cout << '\n';
    	
    }
    
}