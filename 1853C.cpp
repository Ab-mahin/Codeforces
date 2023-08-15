// Problem: C. Ntarsis' Set
// Contest: Codeforces - Codeforces Round 887 (Div. 2)
// URL: https://codeforces.com/contest/1853/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
		ll n, k;
		cin >> n >> k;
		
		vector<ll> a(n + 1, 0), c(n + 1, 0);
		
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			c[i] = c[i - 1] + (a[i] - a[i - 1] - 1);
		}
		
		
		ll lo = 1, hi = 1e18, mid = 0, ans = 0;
		
		while(lo <= hi){
			mid = (lo + hi) >> 1;
			ll ex = mid, val = 0;
			ll u = upper_bound(a.begin(), a.end(), ex) - a.begin();
			u--;			
			for(ll i = 1; i <= k; i++){
				val = a[u] - c[u];
				ex -= val;
				u = upper_bound(a.begin(), a.end(), ex) - a.begin();
				u--;
				if(ex < 0) break;
			}
			if(ex > 0){
				if(ex == 1){
					ans = mid;
				}
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		cout << ans << '\n';
		
	}
	
	return 0;
}