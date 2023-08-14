// Problem: C. Strongly Composite
// Contest: Codeforces - Codeforces Round 868 (Div. 2)
// URL: https://codeforces.com/contest/1823/problem/C
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
const ll N = 4165;
vector<ll> v;
bitset<N> pr;

void siv(){
	v.push_back(2);
	for(ll i = 3; i < N; i += 2){
		if(!pr[i]){
			v.push_back(i);
			for(ll j = i * i; j < N; j += i){
				pr[j] = 1;
			}
		}
	}
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
	
	siv();
	while(t--){
		ll n;
		cin >> n;
		
		ll a[n], ans = 0;
		
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		
		ll ex = 0;
		for(ll i = 0; i < v.size(); i++){
			ll cnt = 0;
			for(ll j = 0; j < n; j++){
				while(a[j] % v[i] == 0){
					cnt++;
					a[j] /= v[i];
				}
			}
			
			ans += (cnt / 2);
			ex += (cnt % 2);
		}
		
		map<ll, ll> mp;
		for(ll i = 0; i < n; i++){
			mp[a[i]]++;
		}
		
		for(ll i = 0; i < n; i++){
			if(a[i] == 1) continue;
			ans += (mp[a[i]] / 2);
			ex += (mp[a[i]] % 2);
			mp[a[i]] = 0;
		}
		
		ans += (ex / 3);
		
		cout << ans << '\n';
	}
	
	return 0;
}