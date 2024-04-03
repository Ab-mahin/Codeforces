// USER: "Ab.Mahin"
// Problem: C. Multiplicity
// Contest: Codeforces - Codeforces Round 523 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1061/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define m 1000000007 // 998244353
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
const ll N = 1e6 + 5;
ll a[N], n;
/*ll solve(ll i, ll j){
	if(i > n) return 0;
	ll res = 0;
	res += solve(i + 1, j);
	if(a[i] % j == 0) res += solve(i + 1, j + 1) + 1;
	return res;
}*/
vector<ll> v[N];
void siv(){
	for(ll i = 1; i < N; i++){
		for(ll j = i; j < N; j += i){
			v[j].push_back(i);
		}
	}
	for(ll i = 2; i < N; i++){
		reverse(v[i].begin(), v[i].end());
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
	siv();
    while(t--){
        cin >> n;
        ll dp[N]{0};
        dp[0] = 1;
        for(ll i = 1; i <= n; i++) {
        	cin >> a[i];
        	
        	for(auto j : v[a[i]]){
        		dp[j] = (dp[j] + dp[j - 1]) % m;
        	}
        }
        
        ll ans = 0;
        for(ll i = 1; i <= n; i++){
        	ans = (dp[i] + ans) % m;
        }
        cout << ans << '\n';
                
    }
    
    
    return 0;
}