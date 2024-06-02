// USER: "Ab.Mahin"
// Problem: C. Everything Nim
// Contest: Codeforces - Codeforces Round 941 (Div. 2)
// URL: https://codeforces.com/contest/1966/problem/C
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
        ll n;
        cin >> n;
        ll a[n];
        map<ll,ll> mp;
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	mp[a[i]] = 1;
        	
        }
        
        ll ok = 0, l = mp.size(), ck = 0;
       	for(ll i = 1; i <= n; i++){
       		if(mp[i]){
       			ok = i;
       		}
       		else break;
       	}
       	//bug(l);
       	if(ok & 1){
       		if(l - ok == 0) ck = 1;
       	}
       	else{
       		if(!ok) ck = 1;
       		else if(l - ok >= 1) ck = 1;
       	}
       	
        cout << (ck ? "Alice" : "Bob") << '\n';
    }
    
    
    return 0;
}