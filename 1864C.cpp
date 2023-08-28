// USER: "Ab.Mahin"
// Problem: C. Divisor Chain
// Contest: Codeforces - Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1864/problem/C
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
#define m 1000000007


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

ll find(ll x){
	ll y = 1, z = 1;
	
	while(y < x){
		if(x % y == 0){
			z = y;
		}
		y *= 2;
	}
	return z;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        
        vector<ll> ans;
        ans.push_back(n);
        
        ll x = n;
        while(x != 1){
        	ll z = find(x);
        	ans.push_back(x - z);
        	x -= z;
        } 
        
        cout << ans.size() << '\n';
        
        for(auto i : ans){
        	cout << i << ' ';
        }
        cout << '\n';
        
    }
    
    
    return 0;
}