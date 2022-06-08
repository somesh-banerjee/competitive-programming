/*
	Lowest Common Ancestor
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int M = 22;
int timer = 0;
vector<vector<int>> gr;
vector<vector<int>> spar;
vector<int> par;
vector<int> depth;
vector<int> tin, tout;

void dfs(int cur, int _par) {
	par[cur] = _par;
	tin[cur] = ++timer;
	for (auto x : gr[cur]) {
		if (x != _par) {
			depth[x] = depth[cur] + 1;
			dfs(x, cur);
		}
	}
	tout[cur] = timer;
}

// O(n)
int lca_brute(int x , int y) {
	if (x == y) return x;
	if (depth[x] < depth[y]) swap(x, y);

	while (depth[x] > depth[y]) {
		x = par[x];
	}

	while (x != y) {
		x = par[x];
		y = par[y];
	}
	return x;
}

// O(n*M)
void calculate_sparse_table(int cur, int par) {
	spar[cur][0] = par;
	for (int j = 1; j < M; j++) {
		spar[cur][j] = spar[spar[cur][j - 1]][j - 1];
	}

	for (auto x : gr[cur]) {
		if (x != par) {
			calculate_sparse_table(x, cur);
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

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca_using_time(int u, int v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;

	for (int i = M - 1; i >= 0; i--) {
		if (!is_ancestor(spar[u][i], v)) {
			u = spar[u][i];
		}
	}
	return spar[u][0];
}

void solve(int ttt) {
	int n, q;
	cin >> n >> q ;
	gr.resize(n + 1, vector<int>());
	spar.resize(n + 1, vector<int>(M, 0));
	par.resize(n + 1);
	depth.resize(n + 1);
	tin.resize(n + 1);
	tout.resize(n + 1);
	timer = 0;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	tin[0] = 0;
	tout[0] = n + 1;
	dfs(1, 0);
	calculate_sparse_table(1, 0);

	while (q--) {
		int x, y;
		cin >> x >> y;
		// cout << lca_brute(x, y) << endl;
		cout << lca_using_depth(x, y) << endl;
		// cout << lca_using_time(x, y) << endl;
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