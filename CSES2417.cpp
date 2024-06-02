// USER: "Ab.Mahin"
// Problem: Counting Coprime Pairs
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2417
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
ll spf[N];
void siv(){
	for(ll i = 1; i < N; i++) spf[i] = i;
	for(ll i = 2; i < N; i++){
		for(ll j = i; j < N; j += i){
			spf[j] = min(spf[j], i);
		}
	}
}
ll mp[N];

ll fun(ll n){
	return (n * (n + 1)) / 2;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll n;
    cin >> n;
    
    ll a[n];
    
    siv();
    
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
    	
    	vector<ll> v;
    	ll x = a[i], y = 1;
	   	while(x != 1){
			if(y != spf[x]) v.push_back(spf[x]);
			y = spf[x];
			x /= spf[x];
    	}
    	
    	for(ll j = 1; j < (1 << v.size()); j++){
    		ll val = 1;
    		for(ll k = 0; k < v.size(); k++){
    			if(j & (1 << k)){
    				val *= v[k];
    			}
    		}
    		mp[val]++;
    	}
    	
    }
    
    ll ans = 0;
    
    for(ll i = 0; i < n; i++){
    	
    	vector<ll> v;
    	ll x = a[i], res = n - i, y = 1;
    	
	   	while(x != 1){
			if(y != spf[x]) v.push_back(spf[x]);
			y = spf[x];
			x /= spf[x];
    	}
    	
    	for(ll j = 1; j < (1 << v.size()); j++){
    		ll c = 0, val = 1;
    		for(ll k = 0; k < v.size(); k++){
    			if(j & (1 << k)){
    				c++;
    				val *= v[k];
    			}
    		}
    		if(c & 1){
    			res -= mp[val];
    		}
    		else res += mp[val];
    	}
    	
    	for(ll j = 1; j < (1 << v.size()); j++){
    		ll val = 1;
    		for(ll k = 0; k < v.size(); k++){
    			if(j & (1 << k)){
    				val *= v[k];
    			}
    		}
    		mp[val]--;
    	}
    	if(a[i] == 1) res--;
    	ans += res;
    }
    	cout << ans << '\n';
    
    
    return 0;
}