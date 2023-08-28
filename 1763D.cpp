// USER: "Ab.Mahin"
// Problem: D. Valid Bitonic Permutations
// Contest: Codeforces - Codeforces Round 840 (Div. 2) and Enigma 2022 - Cybros LNMIIT
// URL: https://codeforces.com/contest/1763/problem/D
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
#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll N = 101;
ll giv[N], dp[N][N] , p, q, x, y, n;

ll solve(ll i, ll pre){
	
	if(pre >= y){
		if(i <= p) return 0;
		if(pre == y){
			if(pre == n){
				if(i == n || i == 1) return 0;
				return 1;
			}
			if(q == y) return giv[n - y - 1] - 1;
			return giv[n - y - 1];
		}
		if(q - i == (n - y)){
			if(pre == n){
				if(i == n || i == 1) return 0;
				return 1;
			}
			return giv[n - pre - 1];
		}
		return 0;
	}
	
	if(dp[i][pre] != -1) return dp[i][pre];
	
	ll res = 0;
	for(ll j = pre + 1; j <= n; j++){
		if(i == p - 1){
			if(pre > x) res = 0;
			else res = (res + solve(i + 1, x)) % m;
			break;
		}
		if(i == q - 1){
			res = (res + solve(i + 1, y)) % m;
			break;
		}
		else if(j != x && j != y){
			res = (res + solve(i + 1, j)) % m;
		}
	}
	return dp[i][pre] = res;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t;
    cin >> t;
    
    giv[0] = 1;
    for(ll i = 1; i < N; i++){
    	giv[i] = (giv[i - 1] * 2) % m;
    }

    while(t--){
        
        cin >> n >> p >> q >> x >> y;
        memset(dp, -1, sizeof(dp));
        
        if(x > y){
        	swap(x, y);
        	swap(p, q);
        	p = n - p + 1;
        	q = n - q + 1;
        }
        
        cout << solve(0, 0) << '\n';
    }
    
    
    return 0;
}