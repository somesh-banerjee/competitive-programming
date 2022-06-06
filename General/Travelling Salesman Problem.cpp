/*
	Travelling Salesman Problem
*/

#include <bits/stdc++.h>
using namespace std;

int VISTED_ALL, n;
vector<vector<int>> dist;
vector<vector<int>> dp;

int tsp(int mask, int pos) {
	if (mask == VISTED_ALL) {
		return dist[pos][0];
	}
	if (dp[mask][pos] != -1) return dp[pos][mask];
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) == 0) {
			int newAns = dist[pos][i] + tsp(mask | (1 << i), i);
			ans = min(ans, newAns);
		}
	}
	return dp[mask][pos] = ans;
}

void solve(int ttt) {
	cin >> n;
	VISTED_ALL = (1 << n) - 1;
	dp.resize(pow(2, n), vector<int>(n, -1));
	dist.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	}
	cout << tsp(1, 0) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ttt = 1;
	//cin >> ttt;
	while (ttt--) {
		solve(ttt);
	}
}