/*
Prim's Algorithm
*/

#include <bits/stdc++.h>
using namespace std;


class Graph {
	int V;
	vector<vector<pair<int, int>>> l;

public:
	Graph(int v) {
		V = v;
		l.resize(V);
	}

	void addEdge(int u, int v, int cost) {
		l[u].push_back(make_pair(v, cost));
		l[v].push_back(make_pair(u, cost));
	}

	int prim_mst() {
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

		vector<bool> visited(V , false);
		long long ans = 0;

		Q.push({0, 0}); // weight, node

		while (!Q.empty()) {
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;
			if (visited[to])
				continue;

			ans += weight;
			visited[to] = true;

			for (auto x : l[to]) {
				if (!visited[x.first]) {
					Q.push({x.second, x.first});
				}
			}
		}

		return ans;
	}
};

void solve(int ttt) {
	int v, q;
	cin >> v >> q;
	Graph g(v);
	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		g.addEdge(x - 1, y - 1, z);
	}
	cout << g.prim_mst() << endl;
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