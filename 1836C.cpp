// Problem: C. k-th equality
// Contest: Codeforces - Codeforces Round 880 (Div. 2)
// URL: https://codeforces.com/contest/1836/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	
	read:
	while(t--){
		ll a, b, c, k;
		cin >> a >> b >> c >> k;
		
		ll x = round(pow(10, a - 1));
		ll xx = round(pow(10, a)) - 1;
				
		for(ll i = x; i <= xx; i++){
			ll mx = min(round(pow(10, c)) - i - 1, round(pow(10, b)) - 1);
			ll mn = max(round(pow(10, c - 1)) - i, round(pow(10, b - 1)));
			if(mn > mx) continue;
			ll dif = mx - mn + 1;
			
			if(dif >= k){
				cout << i << " + " << mn + k - 1 << " = " << (mn + k - 1 + i) << '\n';
				goto read; 
			}
			k -= dif;
		}
		cout << -1 << '\n';		
	}
	
	return 0;
}