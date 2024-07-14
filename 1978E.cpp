// USER: "Ab.Mahin"
// Problem: E. Computing Machine
// Contest: Codeforces - Codeforces Round 953 (Div. 2)
// URL: https://codeforces.com/contest/1978/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
//0x3f

#define MAX LLONG_MAX

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller

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
const ll N = 2e5 + 5;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 0;
    
    cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        
        string s, b;
        cin >> s >> b;
       
        ll prf[n + 1]{0}, suf[n + 1]{0}, res[n + 1]{0};
        for(ll i = 0; i < n; i++){
        	if(s[i] == '1') prf[i + 1] = suf[i + 1] = i + 1;
        	else{
        		if(i == 0 || i == n - 1){
        			prf[i + 1] = -i - N;
        			suf[i + 1] = i + N;
        		}else{
        			if(b[i - 1] == '1' && b[i + 1] == '1'){
        				prf[i + 1] = i;
        				suf[i + 1] = i + 2;
        			}else if(b[i - 1] == '1' && b[i + 1] == '0' && s[i + 2] == '0'){
        				prf[i + 1] = i;
        				suf[i + 1] = i + 3;
        			}else if(b[i - 1] == '0' && b[i + 1] == '1' && s[i - 2] == '0'){
        				prf[i + 1] = i - 1;
        				suf[i + 1] = i + 2;
        			}else if(b[i - 1] == '0' && b[i + 1] == '0' && s[i - 2] == '0' && s[i + 2] == '0'){
        				prf[i + 1] = i - 1;
        				suf[i + 1] = i + 3;
        			}else{
        				prf[i + 1] = -i - N;
        				suf[i + 1] = i + N;
        			}
        		}
        	}
        }
        ll q;
        cin >> q;
        
        for(ll i = 1; i <= n; i++){
        	res[i] += res[i - 1];
        	if(prf[i] >= 1 && suf[i] <= n){
        		res[i]++;
        		s[i - 1] = '1';
        	}
        }
        while(q--){
        	ll l, r;
        	cin >> l >> r;
        	
        	ll ans = res[r] - res[l - 1];
        	
        	set<ll> st;
        	
        	for(ll i = l; i < l + 2; i++){
        		st.insert(i);
        	}
        	for(ll i = r; i >= r - 2; i--){
        		st.insert(i);
        	}
        	for(auto u : st){
        		if(u >= l && u <= r){
        			if((prf[u] < l || suf[u] > r) && s[u - 1] == '1') ans--;
        		}
        	}
        	cout << ans << '\n';
        	tt++;
        }
        
                
    }
    return 0;
}