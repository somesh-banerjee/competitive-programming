/*

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const ll int MOD = 1e9 + 7;

ll n;

struct Matrix {
	vector<vector<ll>> m;
	Matrix() {
		m.resize(n, vector<ll>(n));
	}

	Matrix operator* (const Matrix &b) const {
		Matrix c = Matrix();
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				for (ll k = 0; k < n; k++) {
					c.m[i][k] += (m[i][j] * b.m[j][k]);
					c.m[i][k] %= MOD;
				}
			}
		}
		return c;
	}
};

void solve(int ttt) {
	ll k;
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

	// for (ll step = 0; step < k; step++) {
	// 	vector<ll> new_dp(n);
	// 	for (ll i = 0; i < n; i++) {
	// 		for (ll j = 0; j < n; j++) {
	// 			if (a[i][j]) {
	// 				new_dp[j] += dp[i];
	// 				new_dp[j] %= MOD;
	// 			}
	// 		}
	// 	}
	// 	dp = new_dp;
	// }

    // The above soln runs in O(k*n*n) time but k<=1e18 so we have to optimize the soln
    // This can be optimized by Matrix exponentiation 
    // The mat[i][j] means #ways to go from i to j
	// If we look carefully a[i][j] is #ways to go from i to j in 1 step

	Matrix am = Matrix();
    // am will contain the final answer
    // initially it is identity matrix
	for (ll i = 0; i < n; i++) am.m[i][i] = 1;

	Matrix m = Matrix();
	m.m = a;

	while (k) {
		if (k % 2) {
			// check this explanation https://discuss.codechef.com/t/r-walk-atcoder-educational-dp/58938/2
			// to understand how matrix multiplication is reducing the time complexity
			am = am * m;
		}
		// if m represent i to j in k steps
		// then m*m represent i to j in 2*k steps
		m = m * m;
		k /= 2;
	}


	ll ans = 0;
	// summing the values of all cells to get total #ways
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			ans += am.m[i][j];
			ans %= MOD;
		}
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