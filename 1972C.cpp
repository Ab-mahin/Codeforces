// USER: "Ab.Mahin"
// Problem: C. Permutation Counting
// Contest: Codeforces - Codeforces Round 942 (Div. 2)
// URL: https://codeforces.com/contest/1972/problem/C
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
	
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[n];
        
        ll lo = 0, hi = k, ans = 0, mx = 0;
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	mx = max(mx, a[i]);
        }
        hi += mx;
        while(lo <= hi){
        	ll mid = (lo + hi) / 2;
        	ll ex = 0;
        	for(ll i = 0; i < n; i++){
        		ex += max(mid - a[i], 0ll);
        	}
        	//bug(ex, mid);
        	if(ex <= k){
        		lo = mid + 1;
        		ans = mid;
        	}
        	else hi = mid - 1;
        }
        ll ex = 0;  
             
        for(ll i = 0; i < n; i++){
        	if(a[i] <= ans) {
        		k -= (ans - a[i]);
        	};
        	if(a[i] > ans) ex++;
        }
        ans += (ans - 1) * (n - 1) + (ex + k);
        cout << ans << '\n';
    }
    
    
    return 0;
}