// Problem: C. Game with Reversing
// Contest: Codeforces - Codeforces Round 879 (Div. 2)
// URL: https://codeforces.com/contest/1834/problem/C
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
		string s, b;
		
		cin >> s >> b;
		
		ll x = 0, y = 0;
		
		for(ll i = 0, j = n - 1; i < n && j >= 0; i++, j--){
			if(s[i] != b[i]) x++;
			if(s[i] != b[j]) y++;
		}
		cout << min(max(0ll, x * 2 - (x & 1)), max(2ll, y * 2 - !(y & 1))) << '\n';
		
		
	}
	
	return 0;
}