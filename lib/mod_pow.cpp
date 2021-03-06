/*
計算量は O(log(n)) で次式の計算結果を返す

x**n (mod mod)

つまり，xを乗して，modで割った余りを返す．

ex) mod_pow(2, 3, 3) = 2

素数pに対して x**p = x (mod p) が成り立つ
*/
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mod;
            x = x * x % mod;
            n >>= 1;
    }
    return res;
}


/*
計算量は O(log(n)) で次式の計算結果を返す

x**n (mod mod)

つまり，xを乗して，modで割った余りを返す．

ex) mod_pow(2, 3, 3) = 2

素数pに対して x**p = x (mod p) が成り立つ
*/
ll mod_pow(ll x, ll n, ll mod) {
    if(n == 0) return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    ll (n & 1) res = res * x % mod;
    return res;
}
