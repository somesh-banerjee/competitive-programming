/*
	https://codeforces.com/problemset/problem/1328/E
	Obs: If parent is in the path then possible otherwise not
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<vector<int>> g;
vector<int> in, out, parent, level;
int Time;

void dfs(int cur = 1, int _parent = 0, int depth =  0) {
	level[cur] = depth;
	parent[cur] = _parent;

	in[cur] = Time++;

	for ( auto nb : g[cur]) {
		if (nb != _parent) {
			dfs(nb, cur, depth + 1);
		}
	}

	out[cur] = Time++;
}

void solve(int ttt) {
	int n, m;
	cin >> n >> m ;
	g.resize(n + 1, vector<int>());
	in.resize(n + 1);
	out.resize(n + 1);
	parent.resize(n + 1);
	level.resize(n + 1);
	Time = 0;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs();
	// cout << m;
	while (m--) {
		int k, maxLvl = -1, farthest;
		cin >> k;
		vector<int> v(k);
		for (int i = 0; i < k; ++i)
		{
			cin >> v[i];
			// Finding the farthest point of root i.e. max level
			if (level[v[i]] > maxLvl) {
				maxLvl = level[v[i]];
				farthest = v[i];
			}
			// Storing only the parent
			v[i] = parent[v[i]];
		}

		string ans = "YES";

		// for parents of all points checking if it is ancestor of farthest point
		for (int i = 0; i < k; ++i)
		{
			if (v[i] == 0) continue;
			if (in[v[i]] > in[farthest] || out[v[i]] < out[farthest] ) {
				ans = "NO";
				break;
			}
		}
		cout << ans << endl;
	}


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