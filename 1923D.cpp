// USER: "Ab.Mahin"
// Problem: D. Slimes
// Contest: Codeforces - Educational Codeforces Round 162 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1923/problem/D
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

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        ll prf[n + 1], ck[n + 1], a[n + 1], res[n + 1];
        for(ll i = 1; i <= n; i++) cin >> a[i];
        prf[0] = ck[0] = a[0] = 0;
        
        for(ll i = 1; i <= n; i++){
        	ck[i] = prf[i] = 0;
        	ck[i] += ck[i - 1] + (a[i] == a[i - 1]);
        	prf[i] += prf[i - 1] + a[i];
        }
        
        /*for(ll i = 1; i <= n; i++)cout << ck[i] << ' ' ;
        cout << '\n';*/
        
        auto f = [&](ll i, ll lo, ll hi){
        	ll ans = INT_MAX;
        	while(lo <= hi){
        		ll mid = (lo + hi) / 2;
        		ll x = 0, y = 0, d = 0, m = 0;
        		if(lo < i){
        			d = 1;
        			m = i - mid;
        			x = ck[i - 1] - ck[mid];
        			y = prf[i - 1] - prf[mid - 1];
        		}
        		else {
        			m = mid - i;
        			x = ck[mid] - ck[i + 1];
        			y = prf[mid] - prf[i];
        		}
        		//bug(i, x, y, mid, lo, hi, m);
        		
        		if((x + 1 < m || m == 1 || (i - x >= 1 && a[i - x] > a[i]) || (i + x <= n && a[i + x] > a[i])) && y > a[i]){
        			
        			if(d) lo = mid + 1, ans = i - mid;
        			else hi = mid - 1, ans = mid - i;
        		}
        		else{
        			if(d) hi = mid - 1;
        			else lo = mid + 1;
        		}
        	}
        	return ans;
        };
        
        for(ll i = 1; i <= n; i++){
        	
        	ll x = f(i,1 , i - 1);
        	ll y = f(i, i + 1, n);
        	//cout << x << ' ' << y << '\n';
        	ll mn = min(x, y);
        	res[i] = mn == INT_MAX ? -1 : mn;
        }
        //cout << '\n';
        
        for(ll i  = 1; i <= n; i++){
        	cout << res[i] << " \n"[i == n];
        }
        
        
                
    }
    
    
    return 0;
}
