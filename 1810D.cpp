// Problem: D. Climbing the Tree
// Contest: Codeforces - CodeTON Round 4 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1810/problem/D
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
		ll n;
		cin >> n;
		
		ll l = 0, r = 1e18;
		for(ll i = 0; i < n; i++){
			ll op;
			cin >> op;
			
			if(op & 1){
				ll a, b, d;
				cin >> a >> b >> d;
				ll x = a * (d - 1) - b * (d - 2) + 1; 
				ll y = (a * d) - (b * (d - 1));
				if(d == 1) x = 1, y = a;
				if(x <= r && l <= y){
					l = max(l, x), r = min(r, y), cout << 1 <<  ' ';
				}
				else cout << 0 << ' ';	
				cout << x << ' ' << y << '\n';		
			}
			else{
				ll a, b;
				cin >> a >> b;
				
				ll x = max(1ll, (l - b + a - b - 1) / (a - b));
				ll y = max(1ll, (r - b + a - b - 1) / (a - b));
				cout << l << ' ' << r << '\n';
				if(x == y){
					cout << x << ' ';
				}
				else cout << -1 << ' ';
			}
		}
		cout << '\n';
	}
	
	return 0;
}