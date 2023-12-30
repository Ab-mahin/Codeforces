// USER: "Ab.Mahin"
// Problem: D. K-good
// Contest: Codeforces - CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/D
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
//#define m 1000000007


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
const ll N = 2e6 + 5;
bitset<N> pr;
vector<ll> v;
void solve(){
	v.push_back(2);
	for(ll i = 3; i < N; i += 2){
		if(!pr[i]){
			v.push_back(i);
			for(ll j = i * i; j < N; j += (2 * i)){
				pr[j] = 1;
			}
		}
	}
}

ll fun(ll n){
	return (n * (n - 1)) / 2;
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
    read:
    while(t--){
        ll n;
        cin >> n;
       	ll x = n, cnt = 0;
       	if(!(x & (x - 1))){
       		cout << -1 << '\n';
       		goto read;
       	}  
       	x *= 2;
       	while(x % 2 == 0) x /= 2, cnt++;
       	
       	for(ll i = 1; i <= cnt; i++){
       		ll k = (1ll << i);
	       	ll kk = (1ll << (cnt - i)) * x;
       		ll p = (kk - k - 1);
       		if(p >= 0 && p % 2 == 0){
       			cout << k << '\n';
       			goto read;
       		}
       	}
       	
       	for(ll i = 0; i <= cnt; i++){
       		ll k = (1ll << i) * x;
       		ll kk = (1ll << (cnt - i));
       		ll p = (kk - k - 1);
       		if(p >= 0 && p % 2 == 0){
       			cout << k << '\n';
       			goto read;
       		}
       	}
       	
       	cout << -1 << '\n';  
    }
    
    
    return 0;
}