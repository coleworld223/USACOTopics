#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0);

    setIO ("div7");

    ll n; cin >> n; ll m = 7;

    vector <ll> a (n + 1), pf (n + 1);

    for (ll i = 1; i <= n; i += 1) {
        cin >> a[i];
        pf[i] = ((a[i] + pf[i - 1]) % m);
    }

    auto do_ = [&] () {
        map <ll, ll> ind;
        ind[0] = 0;

        ll ans = 0;

        for (ll i = 1; i <= n; i += 1) {
            if (ind.count (pf[i])) {
                ans = max (ans, i - ind[pf[i]]);
            }
            else {
                ind[pf[i]] = i;
            }
        }

        return ans;
    };

    cout << do_ () << "\n";

}
