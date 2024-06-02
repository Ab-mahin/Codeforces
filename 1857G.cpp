// USER: "Ab.Mahin"
// Problem: G. Counting Graphs
// Contest: Codeforces - Codeforces Round 891 (Div. 3)
// URL: https://codeforces.com/contest/1857/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define m 998244353
//0x3f

#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller


/* To finding all possible submask for a mask(set bits);
 
for(ll mask = 0; mask < (1 << n); mask++){
    for(ll submask = mask ; submask > 0; submask = (submask - 1) & mask){
    	cout << mask << ' ' << submask << '\n';	
    }
}
*/

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 2e5 + 5;
vector<ll> sz, pr;
auto find(ll i){
	if(pr[i] == i) return i;
	return pr[i] = find(pr[i]);
}

void uni(ll a, ll b){
	a = find(a);
	b = find(b);
	if(a != b){
		if(sz[a] < sz[b]){
			pr[b] = a;
			sz[a] += sz[b];
		}
		else{
			pr[a] = b;
			sz[b] += sz[a];
		}
	}
}

ll bigmod(ll a, ll b){
	if(!b) return 1;
	if(b & 1){
		return bigmod(a, b - 1) * a % m;
	}
	ll x= bigmod(a, b / 2);
	return (x * x) % m;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        ll n, s;
        cin >> n >> s;
        
        vector<tuple<ll, ll, ll>> vec;
        
        sz = vector<ll>(n + 1, 0);
        pr = vector<ll>(n + 1);
        
        for(ll i = 0; i < n - 1; i++){
        	ll u, v, w;
        	cin >> u >> v >> w;
        	vec.push_back({w, u, v});
        }
        sort(vec.begin(), vec.end());        
        for(ll i = 1; i <= n; i++) pr[i] = i, sz[i] = 1;        
       	ll ans = 1;
       	for(auto [z, x, y] : vec){
       		ll p = sz[find(x)];
       		ll q = sz[find(y)];
       		uni(x, y);
       		ans = (ans * bigmod(s - z + 1, p * q - 1)) % m;
       	}
        cout << ans << '\n';
    }
    return 0;
}