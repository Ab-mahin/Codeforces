// Problem: B. Imbalanced Arrays
// Contest: Codeforces - Codeforces Round 887 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1852/B
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
	
	read:
	while(t--){
		ll n;
		cin >> n;
		
		ll a[n], ans[n];
		vector<pair<ll, ll>> v;
		
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			v.push_back({a[i], i});
		}
		
		sort(v.begin(), v.end());
		
		deque<ll> dq;
		for(ll i = 0; i < n; i++){
			dq.push_back(v[i].first);
		}
		
		ll val = n,i = 0, j = n - 1;
		while(i <= j){
			ll x = dq.front();
			ll y = dq.back();
			if(y == n - i || x == n - j - 1){
				if(y == n - i){
					ans[v[j--].second] = val--;
					dq.pop_back();
				}
				else{
					ans[v[i++].second] = -(val--);
					dq.pop_front();
				}
			}
			else{
				cout << "NO" << '\n';
				goto read;
			}
			
		}
		
		
		cout << "YES" << '\n';
		
		for(ll i = 0; i < n; ++i){
			cout << ans[i] << " \n"[i == n - 1]; 
		}
		
	}
	
	return 0;
}