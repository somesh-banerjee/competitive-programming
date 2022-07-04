/*

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

#define MOD 1000000007;

void solve(int ttt) {
	ll n;
	cin >> n;

	vector<vector<ll>> a(n + 1, vector<ll>(n, 0));
	for (ll i = 1; i <= n; i++) {
		//Note row is 1 to n but column is 0 to n-1; reason easy for bitmasking
		for (ll j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	/*
	We will use bitmask to keep track of which women are chosen
	dp[i][mask] is #ways when ith man and women represented by mask are chosen.
	if 0 1 3 index women are chosen then mask is 1011
	dp[1][1] means 1st man is chosen and women at 0 index is chosen to pair up and the no of ways it can pair up is stored in dp[1][1]
	dp[1][2] means 1st man & 1 index woman
	dp[1][3] means 1st man & 0,1 index women
	dp[3][9] means 3rd man & 0,3 index women and so on

	*/

	ll maxMask = pow(2, n) - 1; // max mask when all women are chosen

	vector<vector<ll>> dp(n + 1, vector<ll>(maxMask + 1, 0));
	// base case no man and women chosen; #ways = 1;
	dp[0][0] = 1;

	/*
	dp is created by first selecting the man then the #ways can be paired with
	*/

	for (ll i = 1; i <= n; i++) { // the man currently chosen
		for (ll mask = 0; mask <= maxMask; mask++) {
			dp[i][mask] = 0;
			if (i == __builtin_popcount(mask)) { // checking if same no of women and men are chosen
				// if ith man is chosen then mask should also have i 1s
				for (ll j = 0; j < n; j++) {
					/*
					j represent woman
					1<<j & mask =1 means jth woman is in the mask
					*/
					if (a[i][j] && (mask & (1 << j))) {
						//If jth woman is compatible with ith man and is presnt in mask
						// then #ways is increased by the #ways to pair (i-1)th man with mask excluding jth woman
						dp[i][mask] += dp[i - 1][mask - (1 << j)];
					}
					dp[i][mask] %= MOD;
				}
			}
		}
	}

	cout << dp[n][maxMask] << endl;
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