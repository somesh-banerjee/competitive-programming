/*
	we will represent groups with bitmasks
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const ll int MOD = 1e9 + 7;

vector<ll> pre;
// pre[i] stores the score for mask i
vector<ll> dp;
// dp[i] stores the max score that can be achieved when we group all rabbits from mask i
// The final answer is dp[(1<<n) - 1] where all rabbits are grouped

void rec(ll i, vector<ll> &not_taken, ll cur_score, ll mask, ll group) {
	if (i == not_taken.size()) {
		dp[mask] = max(dp[mask], cur_score + pre[group]);
		return;
	}
	// performing rec while not chosing the ith rabbit
	rec(i + 1, not_taken, cur_score, mask, group);
	// performing rec while  chosing the ith rabbit
	ll newMask = mask ^ (1 << not_taken[i]);
	ll newGroup = group ^ (1 << not_taken[i]);
	rec(i + 1, not_taken, cur_score, mask ^ (1 << not_taken[i]), newGroup);
}
// time complexity of the rec fn is O(2^n)

void solve(int ttt) {
	ll n;
	cin >> n;
	vector<vector<ll>> a(n, vector<ll>(n));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	pre.resize(1 << n);

	// looping over all possible mask so, 2^n times
	for (ll mask = 0; mask < (1 << n); mask++) {
		for (ll i = 0; i < n ; i++) {
			// checking if ith rabbit is in the mask
			if (mask & (1 << i)) {
				for (ll j = i + 1; j < n; j++) {
					if (mask & (1 << j)) {
						// checking if jth rabbit is in the mask
						// if both are in the mask the score is updated
						pre[mask] += a[i][j];
					}
				}
			}
		}
	}
	// The time complexity of above nested loop is O(2^n * n^2)

	dp.resize(1 << n, INT_MIN);
	dp[0] = 0; // when none is selected than best score is 0

	for (ll mask = 0; mask < (1 << n); mask++) {
		vector<ll> not_taken;
		// not_taken will consist of rabbits which are not present in the current mask
		for (ll i = 0; i < n ; i++) {
			// checking if ith rabbit is not in the mask
			if (!(mask & (1 << i))) {
				// if not present than adding to not_taken
				not_taken.pb(i);
			}
		}
		// performing recursion where the rabbits not taken are grouped the best score of (mask + group) is found
		// initially the group i.e. last parameter is 0 
		rec(0, not_taken, dp[mask], mask, 0); 
	}
	// The time complexity of above nested loop is O(2^n * n  + 4^n )
    // 4^n for n=16 is 4294967296 ~= 4.3*1e9

	cout << dp[(1 << n) - 1] << endl;

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