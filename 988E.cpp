// USER: "Ab.Mahin"
// Problem: E. Divisibility by 25
// Contest: Codeforces - Codeforces Round 486 (Div. 3)
// URL: https://codeforces.com/contest/988/problem/E
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
string b;
ll n;
ll fun(char ch, ll p){
	ll c = 0;
	for(ll i = n; i >= 0; i--){
		if(b[i] == ch){
			ll j = i;
			while(j != p){
				c++;
				swap(b[j], b[j + 1]);
				j++;
			}
			if(ch == '0') b[p] = '1';
			break;
		}
	}
	return c;
}

ll valid(){
	for(ll i = 0; i < n; i++){
		if(b[i] != '0'){
			return i;
		}
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
    
    //cin >> t;
	
    while(t--){
        string s;
        cin >> s;
        
        ll c[10]{0};
        n = s.size();
        for(ll i = 0; i < n; i++){
        	c[s[i] - '0']++;
        }
        ll ans = n * n;
        if(c[2] && c[5] || c[0] >= 2 || c[7] && c[5] || c[5] && c[0]){
			b = s;
			ll res = 0;
        	if(c[2] && c[5]){
        		res += fun('5', n - 1);
        		res += fun('2', n - 2);
        		res += valid();
        		ans = min(ans, res);
        	}  
        	b = s;
        	res = 0;
        	if(c[7] && c[5]){
        		res += fun('5', n - 1);
        		res += fun('7', n - 2);
        		res += valid();
        		ans = min(ans, res);
        	}
        	b = s;
        	res = 0;
        	if(c[5] && c[0]){
        		res += fun('0', n - 1);
        		res += fun('5', n - 2);
        		res += valid();
        		ans = min(ans, res);
        	} 
        	b = s;
        	res = 0;
        	if(c[0] >= 2){
        		res += fun('0', n - 1);
        		res += fun('0', n - 2);
        		res += valid();
        		ans = min(ans, res);
        	}
        	cout << ans << '\n';
        }
        else cout << -1 << '\n';
                
    }
    
    
    return 0;
}