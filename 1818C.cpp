// Problem: C. Almost Increasing Subsequence
// Contest: Codeforces - Codeforces Round 869 (Div. 2)
// URL: https://codeforces.com/contest/1818/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long int

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
	//cin >> t;
	
	while(t--){
		ll n, q;
		cin >> n >> q;
		
		ll a[n + 1], cnt[n + 1]{0};
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		for(ll i = 1; i <= n; i++){
			if(i - 3 >= 0){
				if(a[i] <= a[i - 1] && a[i - 1] <= a[i - 2]){
					cnt[i] = cnt[i - 1];
				}
				else cnt[i] = cnt[i - 1] + 1;
			}
			else cnt[i] = cnt[i - 1] + 1;
		}
		
		while(q--){
			ll l, r;
			cin >> l >> r;
			ll ans =  cnt[r] - cnt[l - 1];
			
									
			for(ll i = l; i <= min(l + 1, r); i++){
				if((i - 2) >= 0 && ((a[i] <= a[i - 1]) && (a[i - 1] <= a[i - 2]))) ans++;
			}
			
			
			cout << ans << '\n';
		}
		
	}
	
	return 0;
}