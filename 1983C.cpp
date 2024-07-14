// USER: "Ab.Mahin"
// Problem: C. Have Your Cake and Eat It Too
// Contest: Codeforces - Codeforces Round #956 (Div. 2) and ByteRace 2024
// URL: https://codeforces.com/contest/1983/problem/C
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
vector<ll> a, b, c;
ll n, val;

pair<ll, ll> fun(vector<ll> a, vector<ll> b, vector<ll> c){
	ll sum = 0, l = 0, r = 0;
	for(ll i = 0; i < n; i++){
		sum += a[i];
		if(sum >= val){
			l = i;
			break;
		}
	}
	sum = 0;
	for(ll i = n - 1; i > l; i--){
		sum += b[i];
		if(sum >= val){
			r = i;
			break;
		}
	}
	sum = 0;
	for(ll i = l + 1; i < r; i++){
		sum += c[i];
	}
	if(sum >= val) return {l, r};
	else return {-1, -1};
}


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
        cin >> n;
        a = vector<ll>(n);
        b = vector<ll>(n);
        c = vector<ll>(n);
        val  = 0;
        for(ll i = 0; i < n; i++) cin >> a[i], val += a[i];
        for(ll i = 0; i < n; i++) cin >> b[i];
        for(ll i = 0; i < n; i++) cin >> c[i];
        
        val = (val + 2) / 3;
        
        pair<ll, ll> p = {-1, -1};
        if(fun(a, b, c) != p){
        	// bug(1);
        	auto [x, y] = fun(a, b, c);
        	cout << 1 << ' ' << x + 1 << ' ' << y + 1 << ' ' << n << ' ' << x + 2 << ' ' << y << '\n';
        }
        else if(fun(a, c, b) != p){
        	// bug(2);
        	auto [x, y] = fun(a, c, b);
        	cout << 1 << ' ' << x + 1 << ' ' << x + 2 << ' ' << y << ' ' << y + 1 << ' ' << n << '\n';
        }
        else if(fun(b, a, c) != p){
        	// bug(3);
        	auto [x, y] = fun(b, a, c);
        	cout << y + 1 << ' ' << n << ' ' << 1 << ' ' << x + 1 << ' ' << x + 2 << ' ' << y << '\n';
        }
        else if(fun(b, c, a) != p){
        	// bug(4);
        	auto [x, y] = fun(b, c, a);
        	cout << x + 2 << ' ' << y << ' ' << 1 << ' ' << x + 1 << ' ' << y + 1 << ' ' << n << '\n';
        }
        else if(fun(c, a, b) != p){
        	// bug(5);
        	auto [x, y] = fun(c, a, b);
        	cout << y + 1 << ' ' << n << ' ' << x + 2 << ' ' << y << ' ' << 1 << ' ' << x + 1 << '\n';
        }
        else if(fun(c, b, a) != p){
        	// bug(6);
        	auto [x, y] = fun(c, b, a);
        	cout << x + 2 << ' ' << y << ' ' << y + 1 << ' ' << n << ' ' << 1 << ' ' << x + 1 << '\n';
        }
        else cout << -1 << '\n';
    }
    
    return 0;
}