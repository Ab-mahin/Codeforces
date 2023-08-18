// Problem: C. Game on Permutation
// Contest: Codeforces - Educational Codeforces Round 153 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1860/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long int
//#define  m 1000000007

using namespace std;

//Findout buggs:

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>

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
  cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 2e5 + 5;


int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	
	ll t = 1, tt = 1;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		ll a[n];
		ll mn = n + 1, ans = 0, v = n + 1;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			if(!i){
				mn = a[i];
				continue;
			}
			
			if(mn < a[i]){
				if(v > a[i]) ans++;
				v = min(a[i], v);
			}	
			mn = min(mn, a[i]);		
		}
		cout << ans << '\n';
		
	}
	
	return 0;
}