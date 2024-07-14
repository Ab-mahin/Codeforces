// USER: "Ab.Mahin"
// Problem: D. Test of Love
// Contest: Codeforces - Codeforces Round 957 (Div. 3)
// URL: https://codeforces.com/contest/1992/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
// 0x3f

#define MAX LLONG_MAX

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order() and order_of_key()
// k-th largest element and strictly smaller

// Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;

    cin >> t;

    while (t--) {
        ll n, m , k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        
        s = "L" + s + "L";
        ll p = 0, ok = 1;
        n += 2;
        for(ll i = 0; i < n - 1;){
        	ll ck = 0;
        	if(s[i] == 'L'){
        		for(ll j = i + 1; j < n && j <= i + m; j++){
    				if(s[j] == 'L'){
    					i = j;
    					ck = 1;
    					break;
    				}
    			}
    			if(!ck){
    				i += m;
    				if(s[i] == 'C'){
    					ok = 0;
    					break;
    				}
    			}
        	}else{
        		i++;
        		if(s[i] == 'C'){
        			ok = 0;
        			break;
        		}
        		k--;
        	}
        }
        cout << (ok  && k >= 0 ? "YES" : "NO") << '\n';
    }
    
    return 0;
}