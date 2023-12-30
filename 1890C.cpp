// USER: "Ab.Mahin"
// Problem: C. Qingshan Loves Strings 2
// Contest: Codeforces - Codeforces Round 906 (Div. 2)
// URL: https://codeforces.com/contest/1890/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const ll N = 1e7 + 5;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        
        string s;
        cin >> s;
                
        vector<ll> ans;
        
        
        string b;
        for(ll i = 0; i < 600; i++) b += '#', s += '#';
        s = b + s;
        ll l = 600, r = l + n - 1;  
        ll c = 0, p = 0, q = n, ok = 1;
        while(l <= r){
        	if(c > 300){
        		ok = 0;
        		break;
        	}
        	if(s[l] == s[r]){
        		if(s[l] == '1'){
        			s[l - 1] = '1';
        			s[l - 2] = '0';
        			c++;
        			ans.push_back(p);
        			p++;
        			q++;
        			l--;
        			r--;
        		}
        		else{
        			s[r + 1] = '0';
        			s[r + 2] = '1';
        			c++;
        			ans.push_back(q);
        			q++;
        			p++;
        			l++;
        			r++;
        		}
        	}
        	else l++, r--, p++, q--;
        }
        
        if(!ok){
        	cout << -1 << '\n';
        }
        else{
        	cout << ans.size() << '\n';
        	for(auto i : ans){
        		cout << i << ' ';
        	}
        	cout << '\n';
        }
        
    }
    
    
    return 0;
}