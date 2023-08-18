// Problem: C. Tear It Apart
// Contest: Codeforces - Educational Codeforces Round 147 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1821/problem/C
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
		string s;
		cin >> s;
		
		ll n = s.size();
				vector<ll> v[27];
		for(ll i = 0; i < n; i++){
			if(!v[s[i] - 'a'].size()){
				v[s[i] - 'a'].push_back(0);
				v[s[i] - 'a'].push_back(i + 1);
			}
			else{
				v[s[i] - 'a'].push_back(i + 1);
			}
		}
		
		
		
		ll ans = N;
		for(ll i = 0; i <= 26; i++){
			if(v[i].size()){
				v[i].push_back(n + 1);
				ll res = 0;
				for(ll j = 1; j < v[i].size(); j++){
					res = max(res, v[i][j] - v[i][j - 1] - 1);
				}
				ll x = 0;
				while(res){
					res /= 2;
					x++;
				}
				ans = min(ans, x);
			}
		}
		cout << ans << '\n';
		
	}
	
	return 0;
}