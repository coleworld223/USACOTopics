#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0);

    // setIO ("hps");

    ll n; cin >> n;

    vector <ll> a (n + 1);

    for (ll i = 1; i <= n; i += 1) {
        cin >> a[i];
        a[i] += a[i - 1];
        a[i] = ((a[i] % n) + n) % n;
    }

    auto do_ = [&] () -> ll {
        ll res = 0; map <ll, ll> cnt; cnt[0] += 1;
        for (ll i = 1; i <= n; i += 1) {
            if (cnt.count (a[i])) {
                res += cnt[a[i]];
            }
            cnt[a[i]] += 1;
        }
        return res;
    };

    cout << do_ () << "\n";

}
