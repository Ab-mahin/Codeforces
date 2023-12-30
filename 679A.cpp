// USER: "Ab.Mahin"
// Problem: A. Bear and Prime 100
// Contest: Codeforces - Codeforces Round 356 (Div. 1)
// URL: https://codeforces.com/contest/679/problem/A
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
       	
       	ll ok = 1;
       	ll c = 0;
       	vector<ll> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
       	for(auto i : v){
       		c++;
       		cout << i << endl;
       		string s;
       		cin >> s;
       		
       		if(s == "yes"){
       			if(i * i <= 100){
       				cout << i * i << endl;
	       			cin >> s;
	       			if(s == "yes"){
	   					ok = 0;
	   					break;
	   				}
       			}
       			for(ll j = c; j < v.size(); j++){
       				cout << v[j] << endl;
       				cin >> s;
       				if(s == "yes"){
       					ok = 0;
       					break;
       				}
       			}
       			break;
       		}       		
       	}
       	
       	cout << (ok ? "prime" : "composite") << endl;
                
    }
    
    
    return 0;
}