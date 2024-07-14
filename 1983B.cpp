// USER: "Ab.Mahin"
// Problem: B. Corner Twist
// Contest: Codeforces - Codeforces Round #956 (Div. 2) and ByteRace 2024
// URL: https://codeforces.com/contest/1983/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
        ll n, m;
        cin >> n >> m;
        
        string s[n], b[n];
        ll a[n][m], c[n][m], ok = 1;
        
        for(ll i = 0; i < n; i++){
        	cin >> s[i];
        	for(ll j = 0; j < m; j++){
        		a[i][j] = s[i][j] - '0';
        	}
        }
        for(ll i = 0; i < n; i++){
        	cin >> b[i];
        	for(ll j = 0; j < m; j++){
        		c[i][j] = b[i][j] - '0';
        	}
        }
        
        for(ll i = 0; i < n; i++){
        	ll sumA = 0, sumB = 0;
        	for(ll j = 0; j < m; j++){
        		sumA += a[i][j];
        		sumB += c[i][j];
        	}
        	if(sumA % 3 != sumB % 3) ok = 0;
        }
        
        for(ll i = 0; i < m; i++){
        	ll sumA = 0, sumB = 0;
        	for(ll j = 0; j < n; j++){
        		sumA += a[j][i];
        		sumB += c[j][i];
        	}
        	if(sumA % 3 != sumB % 3) ok = 0;
        }
        
        
        cout << (ok ? "YES" : "NO") << '\n';
    }
    
    return 0;
}