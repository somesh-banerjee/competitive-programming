/*

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const ll mod = 1e9 + 7;

void solve(int ttt) {
	ll n;
	cin >> n;

	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	// dp[l][r] means answer for range[l,r] index
	vector<vector<ll>> sz(n, vector<ll>(n, 0));
	// sz[l][r] means size of range[l,r] index
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][i] = 0; // answer for single slime is 0
		sz[i][i] = a[i]; // size of single slime is a[i]
	}

	for (ll i = 2; i <= n; i++) { // i is width
		for (ll l = 0, r = i - 1; r < n; l++, r++) {
			sz[l][r] = a[l] + sz[l + 1][r];
			dp[l][r] = 1e18; // initializing with max value
			for (ll x = l; x < r; x++) {
                // finding optimal x(l<=x<=r) for which dp[l][r] is min.
				dp[l][r] = min(dp[l][r], dp[l][x] + dp[x + 1][r] + sz[l][r]);
			}
		}
	}

	cout << dp[0][n - 1] << endl;
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