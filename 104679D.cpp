// USER: "Ab.Mahin"
// Problem: D. Yet Another Mysterious Array
// Contest: Codeforces - Replay of Battle of Brains 2022, University of Dhaka
// URL: https://codeforces.com/gym/104679/problem/D
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
const ll N = 2e5 + 5;

vector<ll> v;
bitset<N> pr;

void siv(){
	v.push_back(2);
	for(ll i = 3; i < N; i += 2){
		if(!pr[i]){
			v.push_back(i);
			for(ll j = i * i; j < N; j += i){
				pr[j] = i;
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
    
    cin >> t;
	siv();
    while(t--){
        ll n;
        cin >> n;
        ll a[n], ans = 0;
        map<ll, ll> mp;
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	
        	for(ll j = 0; j < v.size() && v[j] <= a[i]; j++){
        		if(a[i] % v[j] == 0){
        			ll cnt = 0;
        			while(a[i] % v[j] == 0){
        				a[i] /= v[j];
        				cnt++;
        			}
        			mp[v[j]] = max(mp[v[j]], cnt);
        		}
        	}
        	if(a[i] != 1) mp[a[i]] = max(mp[a[i]], 1ll);
        }
        
        for(auto i : mp){
        	ans += i.second;
        }
        
        cout << (ans & 1 ? "Alice" : "Bob") << '\n';
        
    }
    
    
    return 0;
}