// Problem: C. Li Hua and Chess
// Contest: Codeforces - Codeforces Round 864 (Div. 2)
// URL: https://codeforces.com/contest/1797/problem/C
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
const ll N = INT_MAX;
ll n, m;
ll query(ll x, ll y){
	if(x > n || y > m) return N;
	ll d;
	cout << "? " << x << " " << y << endl;
	cin >> d;
	return d;	
}

int32_t main(){
	
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);*/
	
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	
	ll t = 1, tt = 1;
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		ll p = query(1, 1);
		
		ll l = query(1, p + 1);
		ll r = query(p + 1, 1);
		
		if(l <= r) cout << "! " << (l + 1) << " " << (p + 1) << endl;
		else cout << "! " << (p + 1) << " " << (r + 1) << endl;	
	}
	
	return 0;
}