#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://github.com/atcoder-live/library/blob/master/mint.cpp
const std::int64_t mod = 1000000007;
struct mint {
    std::int64_t x; // typedef long long ll;
    mint(std::int64_t x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(std::int64_t t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
std::istream& operator>>(std::istream& is, const mint& a) { return is >> a.x;}
std::ostream& operator<<(std::ostream& os, const mint& a) { return os << a.x;}


vector<ll> memo;

mint dfs(ll s) {
    if (s == 0) return 1;
    if (s <= 2) return 0;
    if (memo[s] >= 0) return memo[s];
    mint ret = 0;
    for (ll x = 3; x <= s; ++x) {
        ret += dfs(s - x);
    }
    return memo[s] = ret.x;
}

int main() {
    ll S; cin >> S;
    memo = vector<ll>(2005, -1);
    cout << dfs(S) << endl;
    return 0;
}
