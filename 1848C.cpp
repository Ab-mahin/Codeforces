// Problem: C. Vika and Price Tags
// Contest: Codeforces - Codeforces Round 885 (Div. 2)
// URL: https://codeforces.com/contest/1848/problem/C
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
	
	while(t--){
		ll n;
		cin >> n;
		
		vector<ll> a(n), b(n), v;
		
		
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		
		for(ll i = 0; i < n; i++){
			cin >> b[i];
		}
		
		for(ll i = 0; i < n; i++){
			ll op = 0;
			read:
			if(!a[i] && !b[i]) continue;
			if(a[i] >= b[i] * 2){
				if(!b[i]){
					op++;
					v.push_back(op);
					continue;
				}
				ll x = (b[i] * 2);
				op += (a[i] / x) * 3;
				a[i] = (a[i] % x);
				goto read;			
			}
			else if(a[i]){
				ll x = abs(a[i] - b[i]);
				a[i] = b[i];
				b[i] = x;
				op++;
				goto read;
			}
			v.push_back(op);
		}
		
		sort(v.begin(), v.end());
		ll ok = 1;
		for(ll i = 1; i < v.size(); i++){
			if((v[i] - v[0]) % 3) ok = 0;
		}
		cout << (ok ? "YES" : "NO") << '\n';
		
	}
	
	return 0;
}