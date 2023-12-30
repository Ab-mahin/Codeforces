// USER: "Ab.Mahin"
// Problem: C. Game with Multiset
// Contest: Codeforces - Educational Codeforces Round 160 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1913/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
#define MAX LLONG_MAX

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
        
        ll a[35]{0};
        
        for(ll i = 0; i < n; i++){
        	ll x, y;
        	cin >> x >> y;
        	//bug(x, y);
        	if(x == 1){
        		a[y]++;
        	}
        	else{
        		ll ok = 1,x = 0;        		
        		for(ll j = 0; j < 30; j++){
        			if(y & (1 << j)){
        				x = (x / 2) + a[j];
        				//cout << x << '\n';
        				if(x <= 0){
        					ok = 0;
        				}
        				x--;
        			}
        			else{
        				x /= 2;
        				x += a[j];
        			}
        		}
        		cout << (ok ? "YES" : "NO") << '\n';
        	}
        }
                
    }
    
    
    return 0;
}