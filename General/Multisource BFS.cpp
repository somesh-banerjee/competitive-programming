/*
	Multisource BFS
	https://www.codechef.com/submit-v2/SNSOCIAL
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};

void solve(int ttt) {
	int mx = 0, n, m;
	cin >> n >> m ;

	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			mx = max(mx, a[i][j]);
		}
	}

	vector<vector<int>> dist(n, vector<int>(m, -1));
	int ans = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == mx) {
				dist[i][j] = 0;
				q.push({i, j});
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int X = cur.first, Y = cur.second;

		for (int i = 0; i < 8; i++) {
			int x, y;
			x = X + dx[i];
			y = Y + dy[i];
			if (x < 0 || y < 0 || x >= n || y >= m || dist[x][y] != -1) continue;
			dist[x][y] = dist[X][Y] + 1;
			q.push({x, y});
			ans = max(ans, dist[x][y]);
		}
	}

	cout << ans  << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::clock_t start;
	start = std::clock();

	int ttt = 1;
	cin >> ttt;
	while (ttt--) {
		solve(ttt);
	}

	cout << "\nTime: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	return 0;
}