/*
    Maximum flow in a network
	Edmond Karp Algorithm
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<vector<int>> cap;

bool bfs(vector<vector<int>> &cap, int src, int sink, vector<int> &par) {
	int n = cap.size();
	vector<bool> vis(n, false);
	queue<int> q;
	vis[src] = true;
	q.push(src);
	bool foundPath = false;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; v++ ) {
			if (!vis[v] && cap[u][v] > 0) {
				par[v] = u;
				vis[v] = true;
				q.push(v);
				if (v == sink) {
					return true;
				}
			}
		}
	}

	return false;
}

void printPaths(vector<vector<int>> paths) {
	for (auto i : paths) {
		for (auto j : i) {
			cout << j << " -> ";
		}
		cout << endl;
	}
}

int maxFlow(int src, int sink) {
	int n = cap.size();
	vector<vector<int>> residualCap = cap;
	vector<int> par(1000);
	vector<vector<int>> paths;
	int maxFlow = 0;

	while (bfs(residualCap, src, sink, par)) {
		int f = INT_MAX;
		vector<int> curPath;
		int v = sink;
		while (v != src) {
			curPath.pb(v);
			int  u = par[v];
			if (f > residualCap[u][v]) {
				f = residualCap[u][v];
			}
			v = u;
		}
		curPath.pb(src);
		reverse(curPath.begin(), curPath.end());
		paths.pb(curPath);
		maxFlow += f;

		v = sink;
		while (v != src) {
			int u = par[v];
			residualCap[u][v] -= f;
			residualCap[v][u] += f;
			v = u;
		}
	}
	cout << "Paths:\n";
	printPaths(paths);
	return maxFlow;
}

void solve(int ttt) {
	int n, e;
	cin >> n >> e ;
	cap.resize(n, vector<int>(n, 0));
	for (int i = 0; i < e; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		cap[x][y] = w;
	}
	cout << "Maxflow = " << maxFlow(0, 1) << endl;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::clock_t start;
	start = std::clock();

	int ttt = 1;
	//cin >> ttt;
	while (ttt--) {
		solve(ttt);
	}

	cout << "\nTime: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	return 0;
}