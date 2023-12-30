// USER: "Ab.Mahin"
// Problem: E. Boxers
// Contest: Codeforces - Codeforces Round 579 (Div. 3)
// URL: https://codeforces.com/contest/1203/problem/E
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
#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

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

  // cin >> t;

  while (t--) {
    ll n;
    cin >> n;

    map<ll, ll> mp, ck;
    vector<ll> v;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      if (!mp[x]) {
        v.push_back(x);
      }
      mp[x]++;
    }
    sort(v.begin(), v.end());

    vector<ll> ans, vv;
    ll ex = 0;
    for (auto i : v) {
      if (!vv.size()) {
        vv.push_back(i);
        ex += (mp[i] - 1);
        ck[i]++;
      } else {      	
        if (i - vv.back() == 1) {
          vv.push_back(i);
          ck[i]++;
          ex += (mp[i] - 1);
        } else {      	
          if (ex == 1) {
            if (vv[0] == 1) {
              ck[vv.back() + 1] = 1;
            } else if (!ck[vv[0] - 1]) {
              ck[vv[0] - 1] = 1;
            } else {
              ck[vv.back() + 1] = 1;
            }
          } else if (ex >= 2) {
            if (vv[0] == 1) {
              ck[vv.back() + 1] = 1;
            } else {
              ck[vv[0] - 1] = 1;
              ck[vv.back() + 1] = 1;
            }
          }
          ex = 0;
          vv.clear();
          vv.push_back(i);
          ex += (mp[i] - 1);
          ck[i]++;
        }
      }
    }
    if (ex == 1) {
      if (vv[0] == 1) {
        ck[vv.back() + 1] = 1;
      } else if (!ck[vv[0] - 1]) {
        ck[vv[0] - 1] = 1;
      } else {
        ck[vv.back() + 1] = 1;
      }
    } else if (ex >= 2) {
      if (vv[0] == 1) {
        ck[vv.back() + 1] = 1;
      } else {
        ck[vv[0] - 1] = 1;
        ck[vv.back() + 1] = 1;
      }
    }
    
    cout << ck.size() << '\n';
  }

  return 0;
}