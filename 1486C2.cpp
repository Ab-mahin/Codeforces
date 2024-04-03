// USER: "Ab.Mahin"
// Problem: C2. Guessing the Greatest (hard version)
// Contest: Codeforces - Codeforces Round 703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/C2
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

ll query(ll l, ll r){
	if(l == r) return -1;
	ll i;
	cout << "? " << l << ' ' << r << endl;
	cin >> i;
	return i;
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
    
    //cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        
        ll x = 0, y = 0,ans = 0;
        ll q = query(1, n);
        
        if(q != 1 ){
        	x = query(1, q);
        }
        if(q != n){
        	y = query(q, n);
        }
        if(x == q){
        	ll lo = 1, hi = q, mid = 0;
        	while(lo <= hi){
        		mid = (lo + hi) / 2;
        		if(query(mid ,q) == q){
        			ans = mid;
        			lo = mid  + 1;
        		}
        		else hi = mid - 1;
        	}
        }
        else{
        	ll lo = q, hi = n, mid = 0;
        	while(lo <= hi){
        		mid = (lo + hi) / 2;
        		if(query(q, mid) == q){
        			ans = mid;
        			hi = mid - 1;
        		}
        		else lo = mid + 1;
        	}
        }
        
        cout << "! " << ans << endl;     
    }
    
    
    return 0;
}