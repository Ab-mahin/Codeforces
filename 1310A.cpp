// USER: "Ab.Mahin"
// Problem: F - From Jannat
// Contest: Virtual Judge - FSI Contest 03
// URL: https://vjudge.net/contest/631942#problem/F
// Memory Limit: 512 MB
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



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    // cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        
        multiset<ll> s;
        pair<ll, ll> a[n + 1];
        ll ans = 0, sum = 0;
        for(ll i = 0; i < n; i++){
        	cin >> a[i].first;
        }
        for(ll i = 0; i < n; i++){
        	cin >> a[i].second;
        }
        
        sort(a, a + n);
        a[n] = {MAX, 0};
        
        for(ll i = 0; i < n; i++){
        	auto [x, y] = a[i];
        	auto [p, q] = a[i + 1];
        	sum += y;
        	ll val = x;
        	ll nxtVal = p;
        	s.insert(y);
        	while(val < nxtVal && s.size()){
        		auto it = --s.end();
        		sum -= *it;
        		s.erase(it);
        		ans += sum;
        		val++;
        	}
        }
        
        vector<ll> v;
        ll c = 0, res = 0,mxVal = 0;
        for(ll i = 0; i < n; i++){
        	mxVal = max(mxVal + 1, a[i].first);
        	s.insert(mxVal);
        }
        sort(a, a + n, [](auto c, auto d){
        	auto [x, y] = c;
        	auto [p, q] = d;
        	return y > q;
        });
        for(ll i = 0; i < n; i++){
        	auto [x, y] = a[i];
        	auto it = *s.lower_bound(x);
        	res += (it - x) * y;
        	s.erase(it);
        }
        cout << (ans + res) / 2 << '\n';
        
                
    }
    return 0;
}