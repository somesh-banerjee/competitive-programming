/*
	Lowest Common Ancestor
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int M = 22;
vector<vector<pair<int, int>>> gr;
vector<vector<int>> spar;
vector<int> par;
vector<int> depth;
vector<int> dist;

void dfs(int cur, int _par, int d) {
	par[cur] = _par;
	dist[cur] = d;
	for (auto x : gr[cur]) {
		if (x.first != _par) {
			depth[x.first] = depth[cur] + 1;
			dfs(x.first, cur, d + x.second);
		}
	}
}

// O(n*M)
void calculate_sparse_table(int cur, int par) {
	spar[cur][0] = par;
	for (int j = 1; j < M; j++) {
		spar[cur][j] = spar[spar[cur][j - 1]][j - 1];
	}

	for (auto x : gr[cur]) {
		if (x.first != par) {
			calculate_sparse_table(x.first, cur);
		}
	}
}

// O(logn)
int lca_using_depth(int u, int v) {
	if (u == v) return u;
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];

	for (int i = M - 1; i >= 0; i--) {
		if ((diff >> i) & 1 ) {
			u = spar[u][i];
		}
	}

	if (u == v) return u;

	for (int i = M - 1; i >= 0; i--) {
		if (spar[u][i] != spar[v][i]) {
			u = spar[u][i];
			v = spar[v][i];
		}
	}

	return spar[u][0];
}

void solve(int ttt) {
	int n, q;
	cin >> n >> q ;
	gr.resize(n + 1, vector<pair<int, int>>());
	spar.resize(n + 1, vector<int>(M, 0));
	par.resize(n + 1);
	depth.resize(n + 1);
	dist.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].pb({y, w});
		gr[y].pb({x, w});
	}
	dist[0] = 0;
	dfs(1, 0, 0);
	calculate_sparse_table(1, 0);

	while (q--) {
		int x, y;
		cin >> x >> y;
		int lca = lca_using_depth(x, y);
		cout << dist[x] + dist[y] - 2 * dist[lca] << endl;
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	std::clock_t    start;
	start = std::clock();

	int ttt = 1;
	//cin >> ttt;
	while (ttt--) {
		solve(ttt);
	}

	cout << "\nTime: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	return 0;
}