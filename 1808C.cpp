// Problem: C. Unlucky Numbers
// Contest: Codeforces - Codeforces Round 861 (Div. 2)
// URL: https://codeforces.com/contest/1808/problem/C
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
string s, b, ans, res;
ll dp[20][2][2][2][21][11], n, mmx;

ll solve(ll i, ll ck, ll fck, ll lck, ll mx, ll mn){
	if(i == n){
		if(abs(mx - mn) < mmx){
			ans = res;
			mmx = abs(mx - mn);
		}
		return abs(mx - mn);
	}
	
	if(dp[i][ck][fck][lck][mx][mn] != -1) return dp[i][ck][fck][lck][mx][mn];
	
	ll lo = s[i] - '0', hi = b[i] - '0', tot = 10;
	
	if(fck) lo = 0;
	if(lck) hi = 9;
	
	for(ll j = lo; j <= hi; j++){
		res += char(j + '0');
		ll val = solve(i + 1, ck | (j > 0), fck | (j > lo), lck | (j < hi), max(mx, j), min(mn, (ck | (j > 0) ? j : mn)));
		res.pop_back();
		tot = min(val, tot);
	}
	
	return dp[i][ck][fck][lck][mx][mn] = tot;
}

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
		cin >> s >> b;
		ans = res = "";
		mmx = 10;
		n = b.size();
		
		string d = "";
		
		for(ll i = 0; i < (n - s.size()); i++){
			d += '0';
		}
		s = d + s;
		memset(dp, -1, sizeof(dp));
		solve(0, (s[0] != '0'), 0, 0, 0, 10);
		ll ok = 0;
		for(ll i = 0; i < n; i++){
			if(ans[i] - '0'){
				ok = 1;
			}
			if(ok) cout << ans[i];
		}
		cout << '\n';
	}
	
	return 0;
}