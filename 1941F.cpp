// USER: "Ab.Mahin"
// Problem: F. Rudolf and Imbalance
// Contest: Codeforces - Codeforces Round 933 (Div. 3)
// URL: https://codeforces.com/contest/1941/problem/F
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
	
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        ll a[n], b[m], c[k];
        
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll j = 0; j < m; j++) cin >> b[j];
        for(ll i = 0; i < k; i++) cin >> c[i];
        
        sort(b, b + m);
        sort(c, c + k);
        
        
        /*for(auto i : b){
        	cout << i << ' ';
        }
        cout << '\n';
        for(auto i : c){
        	cout << i << ' ';
        }
        cout << '\n';*/
        
        vector<ll> v;
        for(ll i = 1; i < n; i++){
        	ll x = a[i] - a[i - 1];
        	v.push_back(x);
        }
        sort(v.begin(), v.end());
        
        ll x = count(v.begin(), v.end(), v.back());
        if(x > 1){
        	cout << v.back() << '\n';
        }
        else{
        	ll lo = 0, hi = v.back(), ans = v.back();
        	
        	for(ll i = v.size() - 1; i >= 0; i--){
        		if(v[i] != v.back()){
        			lo = v[i];
        			break;
        		}	
        	}
        	ll l = 0;
        	for(ll i = 1; i < n; i++){
    			ll x = a[i] - a[i - 1];
    			if(x != v.back()) continue;
    			else l = i - 1;
    		}
        	
        	//bug(a[l]);
        	
        	auto fun = [&](ll d, ll mid){
        		ll ck = 0;
        		if(d - a[l] <= mid && a[l + 1] - d <= mid){
        			ck = 1;
        		}
        		return ck;
        	};
        	
        	while(lo <= hi){
        		ll mid = (lo + hi) / 2;
        		ll ok = 0;
        		for(ll i = 0; i < m; i++){
        			if(b[i] >= a[l + 1] || ok) break;
        			ll x = a[l] + mid - b[i];
        			ll y = lower_bound(c, c + k, x) - c;
        			if(y == k) y--;
        			ll d = b[i] + c[y];
        			ok |= fun(d, mid);
        			if(y) {
        				y--;
	        			d = b[i] + c[y];
	        			ok |= fun(d, mid);
        			}
        			if(ok){
        				break;
        			}
        		}
        		if(ok) hi = mid - 1, ans = mid;
        		else lo = mid + 1;
        	}
        	cout << ans << '\n';
        }
        
    }
    
    
    return 0;
}