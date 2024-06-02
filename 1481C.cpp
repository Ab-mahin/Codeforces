// USER: "Ab.Mahin"
// Problem: C. Fence Painting
// Contest: Codeforces - Codeforces Round 699 (Div. 2)
// URL: https://codeforces.com/contest/1481/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
// 0x3f

#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

// find_by_order() and order_of_key()
// k-th largest element and strictly smaller

/* To finding all possible submask for a mask(set bits);

for(ll mask = 0; mask < (1 << n); mask++){
    for(ll submask = mask ; submask > 0; submask = (submask - 1) & mask){
        cout << mask << ' ' << submask << '\n';
    }
}
*/

// Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 2e5 + 5;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /*#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif*/

  ll t, tt;
  t = tt = 1;

  cin >> t;

  while (t--) {
    ll n, m;
    cin >> n >> m;

    ll a[n], b[n], c[m], ck[n + 1]{0};
    
	vector<ll> v[n + 1];

    for (ll i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
      cin >> b[i];
      ck[b[i]] = i + 1;
      if (a[i] != b[i]) {
        v[b[i]].push_back(i);
      }
    }

    for (ll i = 0; i < m; i++) {
      cin >> c[i];
    }

    ll d = 1;
    vector<ll> ans;

    for (ll i = 0; i < m; i++) {
      if (v[c[i]].size()) {
        ll x = v[c[i]].back();
        v[c[i]].pop_back();
        a[x] = c[i];
        for (ll j = 0; j < d; j++) {
          ans.push_back(x + 1);
        }
        d = 1;
      } else if (ck[c[i]]) {
        for (ll j = 0; j < d; j++) {
          ans.push_back(ck[c[i]]);
        }
        d = 1;
      } else
        d++;
    }
    ll ok = 1;
    
    for(ll i = 0; i < n; i++){
    	ok &= (a[i] == b[i]);
    }

    if (d == 1 && ok) {
      cout << "YES" << '\n';
      for (auto i : ans) {
        cout << i << ' ';
      }
      cout << '\n';
    } else
      cout << "NO" << '\n';

  }

  return 0;
}