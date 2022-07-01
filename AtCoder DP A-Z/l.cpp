/*
    Explanation : https://www.youtube.com/watch?v=PEONHX2qssY&ab_channel=UtkarshGupta
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const ll mod = 1e9 + 7;

void solve(int ttt) {
	ll n, s = 0;
	cin >> n;

	vector<ll> a(n);
	ll	dp[n][n][2];  
    // dp[l][r][t] = maximum score of x when array index from l to r is considered and t player's turn
	// t=0 -> first player t=1 -> 2nd player 
    for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
        // Base case 1: when 1st player turn and only 1 index; max score of x = value at that index;
		dp[i][i][0] = a[i];
        // Base case 2: when 2nd player turn and only 1 index; max score of x = 0;
		dp[i][i][1] = 0;
	}

	for (ll i = 1; i < n; i++) {
		for (ll l = 0; l + i < n; l++) {
			ll r = l + i;
			dp[l][r][0] = max(a[l] + dp[l + 1][r][1], a[r] + dp[l][r - 1][1]);
			dp[l][r][1] = min(dp[l + 1][r][0], dp[l][r - 1][0]);
		}
	}
	ll x = dp[0][n - 1][0];
	cout << (ll)(2 * x - s) << endl;

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