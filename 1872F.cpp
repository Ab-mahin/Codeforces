// USER: "Ab.Mahin"
// Problem: F. Selling a Menagerie
// Contest: Codeforces - Codeforces Round 895 (Div. 3)
// URL: https://codeforces.com/contest/1872/problem/F
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
const ll N = 1e5 + 5;
ll par[N], c[N], vis[N], ind[N],mn = MAX;
vector<ll> res;

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
        
        for(ll i = 0; i <= n; i++){
        	vis[i] = par[i] = ind[i] = 0;
        }
        
        for(ll i = 1; i <= n; i++){
        	cin >> par[i];
        	ind[par[i]]++;
        	
        }
        for(ll i = 1; i <= n; i++) cin >> c[i];
        
        queue<ll> q;
        vector<ll> ans;
        
        auto dfs = [&](ll i, ll &id, auto &&dfs)->void{
        	vis[i] = 1;
        	ll x = par[i];
        	
        	ll d = c[i];
        	res.push_back(i);
        	if(mn >= d){
        		id = i;
        		mn = d;
        	}
        	if(!vis[x]){
        		dfs(x, id, dfs);
        	}
        };
        
        for(ll i = 1; i <= n ;i++){
        	if(!ind[i]){
        		q.push(i);
        	}
        }
        
        while(!q.empty()){
        	ll x = q.front();
        	q.pop();
        	ans.push_back(x);
        	vis[x] = 1;
        	ind[par[x]]--;
        	if(ind[par[x]] == 0){
        		q.push(par[x]);
        	}
        }
        
        
        for(ll i = 1; i <= n; i++){
        	if(!vis[i]){
        		mn = MAX;
        		ll id = -1;
        		res.clear();
        		dfs(i, id, dfs);
        		
        		ll p = 0;
        		
        		for(ll j = 0; j < res.size(); j++){
        			if(res[j] == id){
        				p = j;
        				break;
        			}
        		}
        		
        		for(ll j = p + 1; j < res.size(); j++){
        			ans.push_back(res[j]);
        		}
        		for(ll j = 0; j <= p; j++){
        			ans.push_back(res[j]);
        		}
        		
        	}
        }
        
        
        for(auto i : ans){
        	cout << i << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}