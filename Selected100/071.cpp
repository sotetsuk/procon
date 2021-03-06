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
ll MOD = 1000000007;

ll mod(long long val) {
    long long res = val % MOD;
    if (res < 0) res += MOD;
    return res;
}

ll modinv(ll a) {
    ll b = MOD, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

ll modpow(ll a, ll n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

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

int N, Q;
vector<ll> a;
vector<pii> query;
vector<ll> d;

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        ll t; cin >> t;
        a.push_back(t);
    }
    int tmp = 0;
    for (int i = 0; i < Q; ++i) {
        int t; cin >> t; --t;
        query.emplace_back(min(tmp, t), max(tmp, t));
        tmp = t;
    }
    query.emplace_back(0, tmp);
    d.push_back(0);
    for (int i = 0; i < N - 1; ++i) d.push_back(modpow(a[i], a[i+1]));
    // 0, 1, 2
    // 0, 2, 3
    // 0, 2, 5
    for (int i = 0; i < N - 1; ++i) d[i + 1] += d[i];
    // d[i] ... distance([0, i])
    ll ans = 0;
    for (const auto &kv : query) {
        int l = kv.first;
        int r = kv.second;
        ans += mod(d[r] - d[l]);
        ans = mod(ans);
    }
    cout << ans << endl;
    return 0;
}
