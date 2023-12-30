// USER: "Ab.Mahin"
// Problem: E. Replace With the Previous, Minimize
// Contest: Codeforces - Codeforces Round 787 (Div. 3)
// URL: https://codeforces.com/contest/1675/problem/E
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
#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
ll pr[30];

ll find(ll i){
	if(pr[i] == i) return pr[i] = i;
	return pr[i] = find(pr[i]);
}

void Union(ll a, ll b){
	a = find(a);
	b = find(b);
	
	if(a != b){
		pr[b]  = a;
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
	
    while(t--){
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        for(ll i = 1; i < 30; i++){
        	pr[i] = i;
        }
        pr[0] = 1;
                
        for(ll i = 0; i < n; i++){
        	ll x = find(s[i] - 'a' + 1);
        	for(ll j = x; j > 0; j--){
        		if(!k || find(j) == 1) break;
        		Union(j - 1, j);
        		k--;
        	} 	
        }
        
        for(ll i = 0; i < n; i++){
        	ll x = find(pr[s[i] - 'a' + 1]) - 1;
        	cout << char('a' + x);
        }
        cout << '\n';
        
    }
    
    
    return 0;
}