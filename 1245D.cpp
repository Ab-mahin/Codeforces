// USER: "Ab.Mahin"
// Problem: D. Shichikuji and Power Grid
// Contest: Codeforces - Codeforces Round 597 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1245/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define ll long long int
#define MAX INT_MAX
using namespace std;

const int N = 1e6 + 5;
vector<ll> c, k, pr, sz;

map<pair<ll ,ll> ,ll> mp;

ll find(ll i){
    if(pr[i] == i) return i;
    return pr[i] = find(pr[i]);
}

void uni(ll a, ll b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(sz[a] > sz[b]) swap(a, b);
        pr[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    ll n;
    cin >> n;
    ll a[n + 1], b[n + 1];
    a[0] = b[0] = 0;
    for(ll i = 1; i <= n ;i++){
        cin >> a[i] >> b[i];
        mp[{a[i], b[i]}] = MAX;
    }

    c.resize(n + 5);
    k.resize(n + 5);
    pr.resize(n + 5);
    sz.resize(n + 5);

    for(ll i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(ll i = 1; i <= n; i++) {
        cin >> k[i];
    }
	
	vector<tuple<ll, ll, ll>> q;
	
    iota(pr.begin(), pr.end(), 0);
    fill(sz.begin(), sz.end(), 1);
    
    for(ll i = 1; i <= n; i++){
    	q.push_back({c[i], 0, i});
    	for(ll j = i + 1; j <= n; j++){
    		ll cd = (abs(a[i] - a[j]) + abs(b[i] - b[j])) * (k[i] + k[j]);
    		q.push_back({cd, i, j});    		
    	}
    }
    ll ans = 0;
    vector<ll> res;
    vector<pair<ll, ll>> con;
    
    sort(q.begin(), q.end());
    for(auto [z, x, y] : q){
    	
    	if(find(x) != find(y)){
    		uni(x, y);
    		ans += z;
    		if(!x || !y) res.push_back(max(x, y));
    		else con.push_back({x, y});
    	}
    }
    
    cout << ans << '\n';
    cout << res.size() << '\n';
    for(auto i : res){
    	cout << i << ' ';
    }
    cout << '\n';
    cout << con.size() << '\n';
    for(auto [x, y] : con){
    	cout << x << ' ' << y << '\n';
    }
    cout << '\n';
    

    return 0;
}
