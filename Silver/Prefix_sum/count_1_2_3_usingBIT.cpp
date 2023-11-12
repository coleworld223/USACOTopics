#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class BIT {
public:

   BIT (ll n) {
      arr.resize(n + 1);
      tree.resize(n + 1);
      sz = n;
   }

   void upd (ll pos, ll val) {
      arr[pos] = val;
      for (ll i = pos; i <= sz; i += (i & -i)) {
         tree[i] += val;
      }
   }

   ll sum (ll pos) {
      ll ret = 0;
      for (ll i = pos; i > 0; i -= (i & -i)) {
         ret += (tree[i]);
      }
      return ret;
   }

   ll range (ll l, ll r) {
      return sum (r) - sum (l - 1);
   }

   ll sz;
   vector <ll> arr;
   vector <ll> tree; 
};

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0);

    setIO ("bcount");

    ll n, q; cin >> n >> q;

    vector <ll> a (n + 1);

    BIT t1 (n + 1), t2 (n + 1), t3 (n + 1);

    for (ll i = 1; i <= n; i += 1) {
        cin >> a[i];
        if (a[i] == 1) t1.upd (i, 1);
        if (a[i] == 2) t2.upd (i, 1);
        if (a[i] == 3) t3.upd (i, 1);
    }

    auto do_ = [&] () {
        ll l, r; cin >> l >> r;
        array <ll, 3> ans = {t1.range (l, r), t2.range (l, r), t3.range (l, r)};
        auto [x, y, z] = ans;
        cout << x << " " << y << " " << z << "\n";
    };

    for (ll i = 0; i < q; i += 1) {
        do_();
    }

}
