// USER: "Ab.Mahin"
// Problem: E. Strings and Queries
// Contest: Codeforces - PSTU-BU Inter University Online Programming Contest,
// July 2024 URL: https://codeforces.com/gym/534044/problem/E Memory Limit: 256
// MB Time Limit: 5000 ms
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

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order() and order_of_key()
// k-th largest element and strictly smaller

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
const ll N = 3e4 + 5;
ll id[N], n;
ll st[N][20], ans[N][20];
void build() {
    for (ll i = 0; i < n; i++) st[i][0] = id[i], ans[i][0] = i;
    for (ll j = 1; j < 20; j++) {
        for (ll i = 0; i + (1 << j) <= n; i++) {
            ll x = st[i][j - 1];
            ll y = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = max(x, y);
            if (x == y)
                ans[i][j] = min(ans[i][j - 1], ans[i + (1 << (j - 1))][j - 1]);
            else if (x > y)
                ans[i][j] = ans[i][j - 1];
            else
                ans[i][j] = ans[i + (1 << (j - 1))][j - 1];
        }
    }
}

ll query(ll l, ll r) {
    ll d = log2(r - l + 1);
    ll x = st[l][d];
    ll y = st[r - (1 << d) + 1][d];
    ll p = ans[l][d];
    ll q = ans[r - (1 << d) + 1][d];
    if (x == y)
        return min(p, q) + 1;
    else if (x > y)
        return p + 1;
    else
        return q + 1;
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
        ll q;
        cin >> n >> q;
        map<string, int> mp;
        for (ll i = 0; i < n; i++) {
            string s;
            cin >> s;
            mp[s] = i;
            ll m = s.size(), cnt = 0;
            for (ll j = 0; j < m; j++) {
                string b;
                for (ll k = j; k < m; k++) {
                    b += s[k];
                    string c = b;
                    reverse(c.begin(), c.end());
                    if (c == b) cnt++;
                }
            }
            id[i] = cnt;
        }
        build();
        while (q--) {
            string a, b;
            cin >> a >> b;
            ll l = mp[a], r = mp[b];
            if(l > r) swap(l, r);
            cout << query(l, r) << '\n';
        }
    }
    return 0;
}