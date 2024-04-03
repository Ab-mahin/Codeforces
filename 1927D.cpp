// USER: "Ab.Mahin"
// Problem: D. Find the Different Ones!
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/D
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
        ll n;
        cin >> n;
        ll a[n + 1];
        vector<ll> prf(n + 5, 0), suf(n + 5, 0);
        vector<ll> x, y;
        ll d = -1;
        for(ll i = 1; i <= n; i++){
        	cin >> a[i];
        	if(i != 1){
        		if(a[i] == a[i - 1]) prf[i] = d;
        		else prf[i] = i - 1, d = i - 1, x.push_back(i);
        	} else prf[i] = d;
        }
        d = -1;
        for(ll i = n; i >= 1; i--){
        	if(i != n){
        		if(a[i] == a[i + 1]) suf[i] = d;
        		else suf[i] = i + 1, d = i + 1, y.push_back(i);
        	} else suf[i] = d;
        }
        
        sort(y.begin(), y.end());
        
       /* for(auto i : x){
        	cout << i << ' ';
        }
        cout << '\n';
        for(auto i : y){
        	cout << i << ' ';
        }
        cout << '\n';*/
        
        ll q;
        cin >> q;
        //cout << q << '\n';
        while(q--){
        	
        	ll l, r;
        	cin >> l >> r;
        	ll ok = 1;
        	ll i = lower_bound(x.begin(), x.end(), l) - x.begin();
        	ll d = 0;
        	for(ll j = i; j < x.size() && x[j] <= r ; j++){
        		if(d > 100) break;
        		d++;
        		//cout << x[i] << ' ' << prf[x[i]] << '\n';
	        	if(ok && (x[i] >= l  && suf[x[i]] <= r && suf[x[i]] >= l)){
	        		cout << x[i] << ' ' << suf[x[i]] << '\n';
	        		ok = 0;
	        		continue;
	        	}
	        	if(ok && (x[i] >= l  && prf[x[i]] <= r && prf[x[i]] >= l)){
	        		cout << x[i] << ' ' << prf[x[i]] << '\n';
	        		ok = 0;
	        		continue;
	        	}
        	}
			
        	if(ok){
        		cout << -1 << ' ' << -1 << '\n';
        	}
        }
        cout << '\n';
                        
    }
    
    
    return 0;
}