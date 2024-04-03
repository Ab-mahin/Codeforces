// USER: "Ab.Mahin"
// Problem: C. Find a Mine
// Contest: Codeforces - Codeforces Round 931 (Div. 2)
// URL: https://codeforces.com/contest/1934/problem/C
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


ll query(ll x, ll y){
	cout << "? " << x << " " << y << endl;
	ll p;
	cin >> p;
	return p;
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
        ll n, m;
        cin >> n >> m;
        
        ll d = query(1, 1);;
        
        ll xx = 0, yy = 0, x = 0, y = 0;
        ll p;
        if(d >= m){
        	p = query(d - m + 2, m);
        	xx = d - m + 2 + (p / 2);
        	yy = m - (p / 2);        	        	
        }
        else {
        	p = query(1, d + 1);
        	xx = 1 + (p / 2);
        	yy = d + 1 - (p / 2); 
        }
        
        if(d >= n){
        	p = query(n, d - n + 2);
        	x = n - (p / 2);
        	y = d - n + 2 + (p / 2);
        }
        else {
        	p = query(d + 1, 1);
        	x = d + 1 - (p / 2);
        	y = 1 + (p / 2);
        }
        if(!query(xx, yy)){
        	cout << "! " << xx << ' ' << yy << endl;
        }
        else cout << "! " << x << ' ' << y << endl;
    }
    
    
    return 0;
}