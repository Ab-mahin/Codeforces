// USER: "Ab.Mahin"
// Problem: D. Three Activities
// Contest: Codeforces - Codeforces Round 916 (Div. 3)
// URL: https://codeforces.com/contest/1914/problem/D
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
ll n;

ll fun(vector<pair<ll, ll>> a, vector<pair<ll, ll>> b, vector<pair<ll, ll>> c) {
  ll i = a[0].second, j = b[0].second, k = c[0].second;
  ll aa = a[0].first, bb = b[0].first, cc = c[0].first;

  ll x = b[0].second;
  ll y = c[0].second;

  if (x == i) {
    for (ll l = 0; l < n; l++) {
      ll p = b[l].second;
      if (p != i) {
        j = p;
        bb = b[l].first;
        break;
      }
    }
  }

  if (y == i || y == j) {
    for (ll l = 0; l < n; l++) {
      ll p = c[l].second;
      if (p != i && p != j) {
        cc = c[l].first;
        break;
      }
    }
  }

  ll ans = 0;
  ans = (aa + bb + cc);
  return ans;
}

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
    cin >> n;

    vector<pair<ll, ll>> a, b, c;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      a.push_back({x, i});
    }
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      b.push_back({x, i});
    }
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      c.push_back({x, i});
    }

    sort(a.begin(), a.end(), greater<pair<ll, ll>>());
    sort(b.begin(), b.end(), greater<pair<ll, ll>>());
    sort(c.begin(), c.end(), greater<pair<ll, ll>>());

    ll res = 0;

    res = max({res, fun(a, b, c), fun(a, c, b), fun(b, a, c), fun(b, c, a), fun(c, a, b), fun(c, b, a)});

    cout << res << '\n';
  }

  return 0;
}