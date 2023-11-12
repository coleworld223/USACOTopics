#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0);

    setIO ("bcount");

    ll n, q; cin >> n >> q;

    vector <ll> a (n + 1);

    vector <array <ll, 4>> dp (n + 1);

    for (ll i = 1; i <= n; i += 1) {
        cin >> a[i];
        dp[i][a[i]] += 1;
        for (ll j = 1; j <= 3; j += 1) {
            dp[i][j] += dp[i - 1][j];
        }
    }

    auto do_query = [&] () -> array <ll, 3> {
        ll l, r; cin >> l >> r;
        array <ll, 3> ans;

        for (ll i = 0; i < 3; i += 1) {
            ll ele = i + 1;
            ans[i] = dp[r][ele] - dp[l - 1][ele];
        }

        return ans;
    };

    vector <array <ll, 3>> ans (q);

    for (ll i = 0; i < q; i += 1) {
        ans[i] = do_query ();
    }

    for (auto [x, y, z] : ans) {
        cout << x << " " << y << " " << z << "\n";
    }

}
