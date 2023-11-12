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

    ll n, k; cin >> n >> k;

    vector <ll> a (n + 1);

    for (ll i = 1; i <= n; i += 1) {
        cin >> a[i];
    }

    map <ll, ll> mp; ll ans = 0;

    for (ll i = 1, j = 1; i <= n; i += 1) {
        while (j <= n && (mp.count (a[j]) || mp.size() < k)) {
            mp[a[j]] += 1; j += 1;
        }
        ans += (j - i);
        mp[a[i]] -= 1;
        if (mp[a[i]] == 0) mp.erase(a[i]);
    }

    cout << ans << "\n";
}
