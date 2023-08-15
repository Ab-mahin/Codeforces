// Problem: C. To Become Max
// Contest: Codeforces - Codeforces Round 890 (Div. 2) supported by Constructor Institute
// URL: https://codeforces.com/contest/1856/problem/C
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
		
		vector<ll> a(n), b(n);
		
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		
		ll mx = 0;
		for(ll i = n - 1; i >= 0; i--){
			b[i] = max(a[i], mx + 1);
			mx = max(b[i], mx);
		}
				
		ll lo = b[n - 1], hi = b[0], ans = 0, mid = 0;
		
		while(lo <= hi){
			mid = (lo + hi) >> 1;
			ll ck = 0;
			for(ll i = 0; i < n; i++){
				ll nd = k, p = mid;
				for(ll j = i; j < n; j++){
					if(p <= b[j]){
						if(p <= a[j]){
							ck = 1;
							break;
						}
						nd -= (p - a[j]);
						if(nd < 0) break;
						p--;
					}
					else{
						break;
					}
				}
				if(ck) break;
			}
			
			if(ck){
				ans = mid;
				lo = mid + 1;
			}
			else{
				hi = mid - 1;
			}
		}
		cout << ans << '\n';		
	}
	
	return 0;
}