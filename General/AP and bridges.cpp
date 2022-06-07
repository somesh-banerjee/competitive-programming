/*
	AP and bridges
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
vector<int> dsvT, low;
int tme;
vector<int> art_p;
vector<pair<int, int>> bridge;

void dfs(int cur, int par) {
	dsvT[cur] = low[cur] = tme++;
	int noChild = 0;

	for (auto child : gr[cur]) {
		// not visited
		if (dsvT[child] == 0) {
			dfs(child, cur);
			noChild++;

			low[cur] = min(low[cur], low[child]);

			if (par != 0 && low[child] >= dsvT[cur]) {
				art_p.push_back(cur);
			}

			if (low[child] > dsvT[cur]) {
				bridge.push_back(make_pair(cur, child));
			}
		} else if (child != par) {
			// backedge
			low[cur] = min(low[cur], dsvT[child]);
		}
	}

	if (par == 0 && noChild > 1) {
		art_p.push_back(cur);
	}
}

void solve(int ttt) {
	int n, m;
	cin >> n >> m;
	gr.resize(n + 1, vector<int>());
	dsvT.resize(n + 1);
	low.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	tme = 1;
	dfs(1, 0);
	for (auto x : art_p) {
		cout << x << " ";
	}
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