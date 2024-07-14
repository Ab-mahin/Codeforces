// USER: "Ab.Mahin"
// Problem: D. GCD-sequence
// Contest: Codeforces - Codeforces Round 950 (Div. 3)
// URL: https://codeforces.com/contest/1980/problem/D
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
    
    cin >> t;
	read:
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        vector<ll> v;
        ll prf[n - 1]{0}, suf[n - 1]{0};
        prf[0] = 1;
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        }
        for(ll i = 0; i < n - 1; i++){
        	v.push_back(__gcd(a[i], a[i + 1]));
        }
        
        for(ll i = 1; i < n - 1; i++){
        	if(v[i - 1] <= v[i]){
        		prf[i] = prf[i - 1];
        	}
        }
        
        suf[n - 2] = 1;
        for(ll i = n - 3; i >= 0; i--){
        	if(v[i] <= v[i + 1]) suf[i] = suf[i + 1];
        }
              
        ll ok = 0;
        for(ll i = 0; i < n; i++){
        	
        	ll l = INT_MIN, r = INT_MAX, ck = 1;
        	
        	if (i - 2 >= 0 && prf[i - 2] == 0) ck = 0;
			if (i + 1 < n - 1 && suf[i + 1] == 0) ck = 0;
			
        	if(i - 2 >= 0) l = v[i - 2];
        	if(i + 1 < n - 1) r = v[i + 1];
        	
        	if(i > 0 && i < n - 1){
        		ll g = __gcd(a[i - 1], a[i + 1]);
        		if(l > g || g > r){
        			ck = 0;
        		}
        	}
        	if(ck){
        		cout << "YES" << '\n';
        		goto read;
        	}
        }
        
        cout << "NO" << '\n';
    }
    return 0;
}