#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0);

    setIO ("hps");

    ll n; cin >> n;

    vector <array <ll, 3>> dp (n + 1);

    auto relax = [&] (ll i) {
        for (ll j = 0; j < 3; j += 1) {
            dp[i][j] += dp[i - 1][j];
        }
    };

    for (ll i = 1; i <= n; i += 1) {
        char x; cin >> x;
        if (x == 'H') dp[i][0] += 1;
        if (x == 'P') dp[i][1] += 1;
        if (x == 'S') dp[i][2] += 1;
        relax (i);  
    }

    auto m_sum = [&] (ll l, ll r) -> ll {
        if (r < l) return 0ll;
        array <ll, 3> ans = {dp[r][0] - dp[l - 1][0],
                             dp[r][1] - dp[l - 1][1],
                             dp[r][2] - dp[l - 1][2]};
        auto [x, y, z] = ans;

        return max ({x, y, z});
    };

    ll ans = 0;

    for (ll i = 1; i <= n; i += 1) {
        ans = max (ans, m_sum (1, i) + m_sum (i + 1, n));
    }

    cout << ans << "\n";

}
