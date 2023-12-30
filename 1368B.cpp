// USER: "Ab.Mahin"
// Problem: B. Codeforces Subsequences
// Contest: Codeforces - Codeforces Global Round 8
// URL: https://codeforces.com/contest/1368/problem/B
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

    ll t, tt;
    t = tt = 1;
    
    //cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        
        ll v = 1, d = 1;
        string s = "codeforces";
        
        for(ll i = 1; i <= 50; i++){
        	ll x = 1;
        	for(ll j = 0; j < 10; j++) x *= i;
        	if(x >= n){
        		v = i;
        		d = x;
        		break;
        	}
        }
        
        ll cnt[10]{0};        
        for(ll i = 0; i < 10; i++){
        	cnt[i] = v;
        	if(cnt[i] != 1 && (d / cnt[i]) * (cnt[i] - 1) >= n){        			
        		d /= cnt[i];
        		cnt[i]--;
        		d *= cnt[i];
        	}
        }
        ll j = 0, m = 0;
        for(auto i : cnt){
        	ll x = i;
        	m += x;
        	while(x){
        		cout << s[j];
        		x--;
        	}
        	j++;
        }
    }
    
    
    return 0;
}