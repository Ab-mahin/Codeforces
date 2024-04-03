// USER: "Ab.Mahin"
// Problem: D. Berserk Monsters
// Contest: Codeforces - Educational Codeforces Round 161 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1922/problem/D
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
//#define m 1000000007 // 998244353
//0x3f

#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cerr.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 3e5 + 5;


vector<ll> r, l;

ll find(ll i){
	if(r[i] == i) return r[i];
	return r[i] = find(r[i]);
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
        ll n;
        cin >> n;
        
        r.resize(n + 5);
        l.resize(n + 5);
        
        iota(l.begin(), l.end(), 1);
        iota(r.begin(), r.end(), -1);
        
        vector<ll> a(n + 5, 0), b(n + 5, 0);
        
        vector<ll> v;
        r[0] = 0;
        l[n + 1] = n;
        
        for(ll i = 1; i <= n; i++) cin >> a[i];
        for(ll i = 1; i <= n; i++) cin >> b[i];
        
                
        ll ans[n + 5]{0}, c = 0, ck[n + 5]{0};
        
        for(ll i = 1; i <= n; i++){
    		ll d = a[l[i]] + a[r[i]];
    		if(d > b[i]){
    			v.push_back(i);
    		}
        }
        
        ck[0] = ck[n + 1] = 1;
        while(v.size() >= 1){
        	vector<ll> m;
        	set<ll> s;
        	c++;
        	for(ll i = 0; i < v.size(); i++){
        		ll x = v[i];
        		r[l[x]] = r[x];
        		l[r[x]] = l[x];
        		s.insert(l[x]);
        		s.insert(r[x]);
        		ck[x] = 1;
        		ans[c]++;
        	}
        	v.clear();
        	for(auto i : s){
        		if(!ck[i] && (a[l[i]] + a[r[i]] > b[i])) v.push_back(i);
        	}
        }
        for(ll i = 1; i <= n; i++){
        	cout << ans[i] << ' ';
        }
        cout << '\n';
                
    }
    
    
    return 0;
}