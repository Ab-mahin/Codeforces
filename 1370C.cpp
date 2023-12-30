// USER: "Ab.Mahin"
// Problem: C. Number Game
// Contest: Codeforces - Codeforces Round 651 (Div. 2)
// URL: https://codeforces.com/contest/1370/problem/C
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
        ll n;
        cin >> n;
        ll cnt = 0, crt = 0, x = n;
        while(n % 2 == 0) n /= 2, cnt++;
        
        for(ll i = 1; i * i <= x; i++){
        	if(x % i == 0){
        		if(i != 1)crt += (i & 1);
        		ll y = (x / i);
        		if(y != i){
        			if(y != 1) crt += (y & 1);
        		}
        	}
        }
        
        //cout << cnt << ' ' << crt << ' ' << x << '\n';
        cout << ((x == 1 || (cnt == 1 && crt == 1) || x != 2 && !(x & (x - 1))) ? "FastestFinger" : "Ashishgup") << '\n';        
    }
    
    
    return 0;
}