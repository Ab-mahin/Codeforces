// USER: "Ab.Mahin"
// Problem: C. Largest Subsequence
// Contest: Codeforces - Codeforces Round 915 (Div. 2)
// URL: https://codeforces.com/contest/1905/problem/C
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
//#define m 1000000007 // 998244353
#define MAX LLONG_MAX

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
const ll N = 2e5 + 5;

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
        string s, b, d = "";
        cin >> s;
        b = s;
        
        sort(b.begin(), b.end());
        stack<char> q;
        stack<ll> st;
                
		q.push(s[0]);
		st.push(0);
        for(ll i = 1; i < n; i++){
        	
        	
        	char x = q.top();
        	ll ck = 0;
        	//cout << x << '\n';
        	while(q.size() && x < s[i]){
        		q.pop();
        		st.pop();
        		ck = 1;
        		if(q.size() == 0) break;
        		x = q.top();
        	}
        	q.push(s[i]), st.push(i);;
        }
        
        vector<ll> v;
        
        while(!q.empty()){
        	char x = q.top();
        	ll y = st.top();
        	d += x;
        	q.pop();
        	st.pop();
        	v.push_back(y);
        }
        
        sort(d.begin(), d.end());
        sort(v.begin(), v.end());
        
        ll ans = d.size(), ok = 0, cnt[30]{0};
        for(ll i = 0; i < d.size(); i++){
        	s[v[i]] = d[i];
        	cnt[d[i] - 'a']++;
        }
        //cout << d.back() << '\n';     
		ans -= cnt[d.back() - 'a'];
                        
        if(s != b) ans = -1;
        //cout << p << '\n';
        
        cout << ans << '\n';
        //cout << d << '\n';
    }
    
    
    return 0;
}