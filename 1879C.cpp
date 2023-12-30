// USER: "Ab.Mahin"
// Problem: C. Make it Alternating
// Contest: Codeforces - Educational Codeforces Round 155 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1879/problem/C
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
#define m 998244353


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
ll fac[N];
void fun(){
	fac[0] = 1;
	for(ll i = 1; i < N; i++){
		fac[i] = (fac[i - 1] * i) % m;
	}
}

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
	fun();
    while(t--){
        string s;
        cin >> s;
        
        ll n = s.size();
        ll c = 0, ans = 0, res = 1;
        for(ll i = 1; i < n; i++){
        	if(s[i] == s[i - 1]){
        		c++;
        	}
        	else {
        		ans += c;
        		res = (res * (c + 1))  % m;
        		c = 0;
        	}
        }
        ans += c;
        res = (res * (c + 1))  % m;
        res = (res * fac[ans])  % m;
        
        cout << ans << ' ' << res << '\n';        
    }
    
    
    return 0;
}