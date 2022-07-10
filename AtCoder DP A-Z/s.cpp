/*
 
*/
 
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const ll int MOD = 1e9 + 7;
 
// dp[i][j] means #ways to choose digits
// such that sum is 'i' and j means
// the number we chosed from k is allowed
 
void solve(int ttt) {
	string k;
	ll d;
	cin >> k >> d;
	ll n = k.size();
	vector<vector<ll>> dp(d, vector<ll>(2));
	dp[0][0] = 1;
	for (ll pos = 0; pos < n; pos++) {
		vector<vector<ll>> tdp(d, vector<ll>(2));
		for (ll sum = 0; sum < d; sum++) {
			for (bool valid : {0, 1}) {
				for (int digit = 0; digit < 10; ++digit) {
					if (digit > k[pos] - '0' && !valid) {
						break;
					}
					tdp[(sum + digit) % d][valid || (k[pos] - '0') > digit] += dp[sum][valid];
					tdp[(sum + digit) % d][valid || (k[pos] - '0') > digit] %= MOD;
				}
			}
		}
		dp = tdp;
	}
 
 
	ll ans = (dp[0][0] + dp[0][1]) % MOD;
	if (ans) ans--;
	else ans=MOD-1;
	cout << ans << endl;
 
}
 
int main() {
 
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