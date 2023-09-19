// USER: "Ab.Mahin"
// Problem: D. Yet Another Problem
// Contest: Codeforces - Codeforces Round 832 (Div. 2)
// URL: https://codeforces.com/contest/1747/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
	
	
	ll n, q;
	cin >> n >> q;
	
	ll a[n + 1], pxor[n + 1]{0}, ln[n + 1]{0}, idx[n + 1]{0};
	map<ll, ll> od, ev;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		pxor[i] = pxor[i - 1] ^ a[i];
		ln[i] = (a[i] == 0) ? ln[i - 1] : i;
		if(i & 1) idx[i] = ev[pxor[i]], od[pxor[i]] = i;
		else idx[i] = od[pxor[i]], ev[pxor[i]] = i;
	} 
    
    
    while(q--){
    	ll l, r;
    	cin >> l >> r;
    	
    	if(pxor[r] != pxor[l - 1]){
    		cout << -1 << '\n';
    	}
    	else if(ln[r] < l){
    		cout << 0 << '\n';
    	}
    	else if(r % 2 == l % 2){
    		cout << 1 << '\n';
    	}
    	else if(!a[l] || !a[r]){
    		cout << 1 << '\n';
    	}
    	else if(idx[r] >= l){
    		cout << 2 << '\n';
    	}
    	else cout << -1 << '\n';
    }
    
    
    return 0;
}