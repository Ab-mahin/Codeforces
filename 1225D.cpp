// USER: "Ab.Mahin"
// Problem: D. Power Products
// Contest: Codeforces - Technocup 2020 - Elimination Round 2
// URL: https://codeforces.com/contest/1225/problem/D
// Memory Limit: 512 MB
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
vector<ll> v;
bitset<N> pr;
void siv(){
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
        ll n, k;
        cin >> n >> k;
        ll a[n], ans = 0;
        map<ll, ll> mp;
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	ll x = a[i], d = 1, p = 1;
        	for(ll j = 0; j < v.size() && v[j] <= x; j++){
        		if(x % v[j] == 0){
        			ll cnt = 0;
        			while(x % v[j] == 0){
        				x /= v[j];
        				cnt = (cnt + 1) % k;
        			}
        			ll crt = k - cnt;
        			while(cnt--){
        				d *= v[j];
        			}
        			while(crt != k && crt--){
        				p *= v[j];
        			}
        		}
        	}
        	if(x != 1){
        		d *= x;
        		for(ll j = 0; j < k - 1; j++){
        			p *= x;
        		}
        	}
        	//cout << d << ' ' << p << ' ' << mp[p] << '\n';
        	ans += mp[p];
        	mp[d]++;
        }
        cout << ans << '\n';
    }
    
    
    return 0;
}