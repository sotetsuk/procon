#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <numeric>
#include <iomanip>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

///////////////////////////////////////////////////////////////
// namespace
///////////////////////////////////////////////////////////////
using namespace std;
// namespace mp = boost::multiprecision;

///////////////////////////////////////////////////////////////
// types
///////////////////////////////////////////////////////////////
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// using mpi = mp::cpp_int;
// using mpf = mp::number<mp::cpp_dec_float<1024>>;

///////////////////////////////////////////////////////////////
// mod https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
///////////////////////////////////////////////////////////////
// ll MOD = 1000000007;
//
//  ll mod(ll val) {
//      ll res = val % MOD;
//      if (res < 0) res += MOD;
//      return res;
//  }
//
// ll modinv(ll a) {
//     ll b = MOD, u = 1, v = 0;
//     while (b) {
//         ll t = a / b;
//         a -= t * b; swap(a, b);
//         u -= t * v; swap(u, v);
//     }
//     u %= MOD;
//     if (u < 0) u += MOD;
//     return u;
// }
//
// const int MAX = -1;
// ll fac[MAX], finv[MAX], inv[MAX];
// void com_init() {  // initialize nCk table with O(N)
//     fac[0] = fac[1] = 1;
//     finv[0] = finv[1] = 1;
//     inv[1] = 1;
//     for (int i = 2; i < MAX; i++){
//         fac[i] = fac[i - 1] * i % MOD;
//         inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
//         finv[i] = finv[i - 1] * inv[i] % MOD;
//     }
// }
// ll com(int n, int k){  // nCk
//     if (n < k) return 0;
//     if (n < 0 || k < 0) return 0;
//     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
// }

struct UnionFind{
    vector<int> par;
    vector<int> rank;  // height of tree
    UnionFind(int m) : par(m), rank(m) {
        for(int i = 0; i < m; i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    int root(int x) {
        return x == par[x] ? x : par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        if(same(x, y)) return;
        if(rank[x] < rank[y]) {
            par[root(x)] = root(y);  // make y above
        } else {
            par[root(y)] = root(x);
            if(rank[x] == rank[y]) ++rank[x];
        }
    }
};

bool is_bridge(int i, int n, const vector<pii> &edges) {
    UnionFind uf(n);
    for (int j = 0; j < edges.size(); ++j) {
        if (i == j) continue;
        auto e = edges[j];
        uf.unite(e.first, e.second);
    }
    auto root = uf.root(0);
    for (int j = 0; j < n; ++j) if (root != uf.root(j)) return true;
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<pii> edges;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        edges.emplace_back(a, b);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) if (is_bridge(i, n, edges)) ++ans;
    cout << ans << endl;
    // cout << setprecision(10);
    return 0;
}
