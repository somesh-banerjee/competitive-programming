/*
    pre-req: segmentation tree; to find max within range [0,r] in O(logn) time
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define MOD 1000000007

void solve(int ttt) {
	ll n;
	cin >> n;

	ll base = 1;
    // base is smallest power of 2 greater than n
	while (base <= n) base *= 2;

	vector<ll> tree(2 * base); // segment tree to store max dp[i] in range 0 to height i

	vector<ll> h(n, 0);
	vector<ll> a(n, 0);

	for (ll i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	for (ll i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	vector<ll> dp(n + 1, 0); // height i <= n
	// dp[i] - the max total beauty so far if the last flower taken has height i
	ll ans = INT_MIN;
	for (ll i = 0; i < n; ++i)
	{

        // linearly finding best; 
		// for (ll j = 0; j < h[i]; j++) {
		// 	dp[h[i]] = max(dp[h[i]], dp[j] + a[i]);
		// }

        //The above method will result in O(n^2) soln
        // So to optimize we will find the best for dp[h[i]] using segment tree
        // then the time complx. will be O(nlogn)

		ll x = h[i] + base;
		// max dp[j] for j in [0,h[i]-1]
		ll best = 0;
		while (x > 1) {
			if (x % 2 == 1) {
				best = max(best, tree[x - 1]);
			}
			x /= 2;
		}

		dp[h[i]] = best + a[i];

		for (ll j = base + h[i]; j >= 1 ; j /= 2) {
			tree[j] = max(tree[j], dp[h[i]]);
		}

	}
	for (ll i = 0; i <= n; ++i)
	{
		ans = max(ans, dp[i]);
	}

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