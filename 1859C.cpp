// Problem: C. Another Permutation Problem
// Contest: Codeforces - Codeforces Round 892 (Div. 2)
// URL: https://codeforces.com/contest/1859/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long int
//#define  m 1000000007

using namespace std;

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
		
		ll ans = 0;
		
		for(ll i = 1; i <= n; i++){
			vector<ll> v;
			for(ll j = 1; j < i; j++){
				v.push_back(j);
			}
			for(ll j = n; j >= i; j--){
				v.push_back(j);
			}
			ll mx = 0, res = 0;
			for(ll j = 0; j < n; j++){
				res += ((j + 1) * v[j]);
				mx = max(mx, (j + 1) * v[j]);		
			}
			
			ans = max(res - mx, ans);
		}
		cout << ans << '\n';
		
	}
	
	return 0;
}