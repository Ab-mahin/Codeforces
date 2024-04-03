// USER: "Ab.Mahin"
// Problem: C. Obtain The String
// Contest: Codeforces - Educational Codeforces Round 81 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1295/C
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
    
    cin >> t;
	
    while(t--){
    	        
        vector<ll> v[27];
        string a, b;
        cin >> a >> b;
        
        ll ans = 1;
        
        for(ll i = 0; i < a.size(); i++){
        	v[a[i] - 'a'].push_back(i + 1);
        }
        ll p = 0;
        for(ll i = 0; i < b.size(); i++){
        	if(v[b[i] - 'a'].size() == 0){
        		ans = -1;
        		break;
        	}
        	
        	if(v[b[i] - 'a'].back() <= p) p = 0, ans++;
        	
        	ll x = upper_bound(v[b[i] - 'a'].begin(), v[b[i] - 'a'].end(), p) - v[b[i] - 'a'].begin();
        	
        	if(x == v[b[i] - 'a'].size()) ans++;
        	else p = v[b[i] - 'a'][x];
        	ll q = v[b[i] - 'a'][x];
        }
        cout << ans << '\n';
    }
    
    
    return 0;
}