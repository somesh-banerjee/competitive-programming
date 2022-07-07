/*

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const ll int MOD = 1e9 + 7;

void solve(int ttt) {
	ll n, k;
	cin >> n >> k;

	vector<vector<ll>> a(n, vector<ll>(n));

	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	vector<ll> dp(n, 1);
	// dp[i] - #ways to vertex i

	for (ll step = 0; step < k; step++) {
		vector<ll> new_dp(n);
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (a[i][j]) {
					new_dp[j] += dp[i];
					new_dp[j] %= MOD;
				}
			}
		}
		dp = new_dp;
	}

    
	ll ans = 0;
	for (auto i : dp) {
		ans += i;
		ans %= MOD;
	}
	cout << ans << endl;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::clock_t start;
	start = std::clock();

	int ttt = 1;
	// cin >> ttt;
	while (ttt--) {
		solve(ttt);
	}

	// cout << "\nTime: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	return 0;
}