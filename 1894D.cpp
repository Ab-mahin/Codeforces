// USER: "Ab.Mahin"
// Problem: D. Neutral Tonality
// Contest: Codeforces - Codeforces Round 908 (Div. 2)
// URL: https://codeforces.com/contest/1894/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353


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
    
    cin >> t;
	
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll a[n + 1], b[m + 1];
        
        for(ll i = 1; i <= n; i++) cin >> a[i];
        for(ll i = 1; i <= m; i++) cin >> b[i];
        
        vector<ll> v;
        sort(b + 1, b + m + 1, greater<ll>());
        
        ll j = m, i = n;
        while(j && i){
        	//cout << i << ' ' << j  << ' ' << a[i] << ' ' << b[j] << '\n';
        	if(a[i] >= b[j]){
        		v.push_back(b[j]);
        		j--;
        		if(j == 0){
        			while(i){
        				v.push_back(a[i]);
        				i--;
        			}
        			break;
        		}
        	}
        	else{
        		v.push_back(a[i]);
        		i--;
        		if(i == 0){
        			while(j){
        				v.push_back(b[j]);
        				j--;
        			}
        			break;
        		}
        	}
        }
        reverse(v.begin(), v.end());
        for(auto i : v){
        	cout << i << ' ';
        }
        cout << '\n';
        
    }
    
    
    return 0;
}