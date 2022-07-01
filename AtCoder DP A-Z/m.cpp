/*

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const ll mod = 1e9 + 7;

void solve(int ttt) {
	ll n, k;
	cin >> n >> k;

	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
	// dp[i][j] represents no of ways in distributing j candies in i children
    // dp[i][j] = sum[k=0 to j](#ways ith child has k candies ans i-1 children has j-k candies)

	vector<ll> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
		dp[i][0] = dp[i + 1][0] = 1; // sharing 0 candies in any no of child is only 1 way
	}

	for (ll i = 1; i <= n; i++) {
        // sum[k] stores the prefix sum; #ways to distribute 0 to k candies among i-1
		vector<ll> sum(k + 1);

		sum[0] = dp[i - 1][0];
		for (ll j = 1; j <= k; j++) {
			sum[j] = (sum[j - 1] + dp[i - 1][j]) % mod;
		}
		
        // But there is a constraint of how many candies a child may have
        for (ll j = 0; j <= k; j++) {
            //if within the constraint then take the # from sum[j]
			if (j <= a[i]) {
				dp[i][j] = sum[j];
			} else {
                // crossed the limit
				ll np = j - a[i] - 1; // finding the non existing state 
                /*
                Non existing state means suppose j=m but limit is n 
                for j=m, i-1 will have k-m candies
                But ith child can't have m candies so i-1 children will always have candies > k-m
                so we subtract sum[k-m] from sum[j] which gives how many way k-m to j candies is distributed among i-1
                */
				dp[i][j] = (sum[j] - sum[np] + mod) % mod; // add by mod doesn't change answer bcoz of %
			}
		}
		sum.clear();
	}

	cout << dp[n][k] << endl;

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