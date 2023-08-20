// Problem: D. Balanced String
// Contest: Codeforces - Educational Codeforces Round 153 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1860/problem/D
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
const ll N = 101;
ll dp[N][N][1255];
ll n, x, zr, on;
string s;

ll solve(ll i, ll zrr, ll val){
	
	if(val > x) return INT_MAX;
	
	if(i == n){
		return (val == x ? 0 : INT_MAX);
	}
	if(dp[i][zrr][val] != -1) return dp[i][zrr][val];
	
	ll res = INT_MAX, onn = i - zrr;
	
	if(zrr < zr){
		res = min(res, solve(i + 1, zrr + 1, val + onn) + (s[i] == '1'));
	}
	if(onn < on){
		res = min(res, solve(i + 1, zrr, val) + (s[i] == '0'));
	}
	
	return dp[i][zrr][val] = res;	
}

int32_t main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	
	cin >> s;
	
	zr = 0;
	n = s.size();
	for(ll i = 0; i < n; i++){
		zr += (s[i] == '0');
	}
	on = n - zr;
	
	memset(dp, -1, sizeof(dp));
	x = (zr * on) / 2;
	cout << solve(0, 0, 0) / 2;
	
	
	return 0;
}