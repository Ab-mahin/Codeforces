// USER: "Ab.Mahin"
// Problem: C. Manhattan Permutations
// Contest: Codeforces - Codeforces Round 953 (Div. 2)
// URL: https://codeforces.com/contest/1978/problem/C
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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

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
    map<ll, ll> mp, pm;
    vector<ll> v;
    v.push_back(0);
    for(ll i = 2; i <= N; i++){
    	mp[i] = mp[i - 2] + (i - 1) * 2; 
    	v.push_back(mp[i]);
    	pm[mp[i]] = i;
    }
    
    while(t--){
    	tt++;
        ll n, k;
        cin >> n >> k;
        if(k & 1 || k > mp[n]){
        	cout << "No" << '\n';
        }else{
        	ll ans[n + 1];
        	cout << "Yes" << '\n';
        	ll it = lower_bound(v.begin(), v.end(), k) - v.begin();
        	ll x = v[it];
        	ll d = (mp[pm[x]] - k) / 2;
        	for(ll i = 1; i <= n; i++){
        		ans[i] = i;
        	}
        	ll y = pm[x];
        	ll c = y / 2;
        	ll m = y - 1;      	
        	for(ll i = 1, j = y; i < j; i++, j--){
        		ll ok = 0;
        		c--;
        		if(c < d){
        			ok = 1;
        		}
        		ll p = i + m - ok;
        		if(p == 0) break;
        		swap(ans[i], ans[p]);
        		m -= 2;
        	}
        	for(ll i = 1; i <= n; i++){
        		cout << ans[i] << ' ';
        	}
        	cout << '\n';
        }
                
    }
    return 0;
}