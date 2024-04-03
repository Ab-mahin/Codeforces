// USER: "Ab.Mahin"
// Problem: C. Number of Ways
// Contest: Codeforces - Codeforces Round 266 (Div. 2)
// URL: https://codeforces.com/contest/466/problem/C
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

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cerr.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
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
        ll a[n], sum = 0, x = 0, y = 0, ans = 0;
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	sum += a[i];
        }
        if(sum % 3){
        	cout << 0 << '\n';
        	continue;
        }
        
        x = sum / 3;
        y = x * 2;
        map<ll, ll> mp;
        sum = 0;
        
        for(ll i = 0; i < n; i++){
        	sum += a[i];
        	if(sum == y){
        		ans += mp[x];
        	}
        	mp[sum]++;
        }
        
        if(!sum){
        	ans -= mp[0] - 1;
        }
        cout << ans << '\n';
                
    }
    
    
    return 0;
}