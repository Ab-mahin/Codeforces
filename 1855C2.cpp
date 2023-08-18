// Problem: C2. Dual (Hard Version)
// Contest: Codeforces - Codeforces Round 889 (Div. 2)
// URL: https://codeforces.com/contest/1855/problem/C2
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
ll a[N], n, ng, z;
void try1(ll j, ll p){
	cout << (p + ng + n - 1) << '\n';
	
	for(ll i = 0; i < p; i++){
		a[j] *= 2;
		cout << (j + 1) << ' ' << (j + 1) << '\n';
	}
	
	for(ll i = 0; i < n; i++){
		if(a[i] < 0){
			a[i] = a[j];
			cout << (i + 1) << ' ' << (j + 1) << '\n';
		}
	}
	
	for(ll i = 1; i < n; i++){
		a[i] += a[i - 1];
		cout << i + 1 << ' ' << i << '\n';
	}
}

void try2(ll j, ll p){
	cout << (p + (n - ng) - z + n - 1) << '\n';
	
	for(ll i = 0; i < p; i++){
		a[j] *= 2;
		cout << (j + 1) << ' ' << (j + 1) << '\n';
	}
	
	for(ll i = 0; i < n; i++){
		if(a[i] > 0){
			a[i] = a[j];
			cout << (i + 1) << ' ' << (j + 1) << '\n';
		}
	}
	
	for(ll i = n - 2; i >= 0; i--){
		a[i] += a[i + 1];
		cout << (i + 1) << ' ' << (i + 2) << '\n';
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
	
	while(t--){
		cin >> n;
		
		ll mx = -1, mn = 0, idx = -1, idy = -1;
		
		ng = z = 0;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] && mx < a[i]){
				mx = a[i];
				idx = i;
			}
			if(a[i] < 0){
				if(a[i] < mn){
					mn = a[i];
					idy = i;
				}
			}
			ng += (a[i] < 0);
			z += (a[i] == 0);
		}
		
		if(is_sorted(a, a + n)){
			cout << 0 << '\n';
			continue;
		}
		
		ll x = 0, y = 0;
		ll p = mx, q = mn;
		if(idx != -1){
			while(p < abs(q)){
				p *= 2;
				x++;
			}
		}
		p = mx, q = mn;
		if(idy != -1){
			while(abs(q) < p){
				q *= 2;
				y++;
			}
		}
		
		if(idy == -1){
			try1(idx, x);
		}
		else if(idx == -1){
			try2(idy, y);
		}
		else{
			if((y + (n - ng) - z + n - 1) <= (x + ng + n - 1)){
				try2(idy, y);
			}
			else try1(idx, x);
		}
		
	}
	
	return 0;
}