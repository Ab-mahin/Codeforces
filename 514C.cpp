// USER: "Ab.Mahin"
// Problem: C. Watto and Mechanism
// Contest: Codeforces - Codeforces Round 291 (Div. 2)
// URL: https://codeforces.com/contest/514/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 3e6 + 5;
map<pair<ll, ll> ,ll> mp, pm;
const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 27;
pair<ll, ll> Hash(string s, ll ck){
	ll h1 = 0, h2 = 0;
	for(ll i = 0; i < s.size(); i++){
		h1 = ((h1 * p1) % MOD1 + s[i]) % MOD1;
		h2 = ((h2 * p2) % MOD2 + s[i]) % MOD2;
	}
	if(!ck) mp[{h1, h2}]++;
	return {h1, h2};
}
ll pow1[N], pow2[N];
void fun(){
	pow1[0] = 1;
	pow2[0] = 1;
	for(ll i = 1; i < N; i++){
		pow1[i] = (pow1[i - 1] * p1) % MOD1;
		pow2[i] = (pow2[i - 1] * p2) % MOD2;
	}
	
}

ll ck(ll ck, ll x, ll l, char a, char b){
	ll y = (x - ((ck ? pow1[l] : pow2[l]) * a % (ck ? MOD1 : MOD2)) + (ck ? MOD1 : MOD2)) % (ck ? MOD1 : MOD2);
	y = (y + (ck ? pow1[l] : pow2[l]) * b) % ((ck ? MOD1 : MOD2));
	return y;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    //cin >> t;
	fun();
    while(t--){
        ll n, q;
        cin >> n >> q;
        string s;
        for(ll i = 0; i < n; i++){
        	cin >> s;
        	pair<ll,ll> h = Hash(s, 0);   
        	//cout << h.first << ' ' << h.second << '\n';     	
        }
        //cout << '\n';
        
        while(q--){
        	cin >> s;
        	string b = s;
        	ll ok = 0;
        	pair<ll,ll> h = Hash(b, 1);
        	for(ll j = 0; j < s.size(); j++){
        		for(char k = 'a'; k <= 'c'; k++){
        			if(s[j] == k) continue;
        			ll l = s.size() - j - 1;
        			pair<ll,ll> cur = h;
        			cur.first = ck(1, cur.first, l, s[j], k);
        			cur.second = ck(0, cur.second, l, s[j], k);
        			//cout << cur.first << ' ' << h.first << '\n';
        			if(mp[cur]) ok = 1;
        			//cout << b << ' ' << h.first << ' ' << h.second << '\n';
        		}
        	}
        	//cout << s << ' ' << h.first << ' ' << h.second << '\n';
        	cout << (ok ? "YES" : "NO") << '\n';
        }
        
    }
    
    
    return 0;
}