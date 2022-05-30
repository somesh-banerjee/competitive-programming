#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<pair<int, int>> l;

public:
	Graph(int V) {
		this->V = V;
	}

	int addEdge(int x, int y) {
		l.push_back(make_pair(x, y));
	}

	//FIND func
	int find(int i, vector<int> &parent) {
		if (parent[i] == -1) {
			return i;
		}
		return parent[i] = find(parent[i], parent);
	}

	//UNION func
	void union_set(int a, int b, vector<int> &parent, vector<int> &rank) {
		int s1 = find(a, parent);
		int s2 = find(b, parent);

		if (s1 != s2) {
			if (rank[s1] > rank[s2]) {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			} else {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
		}
	}

	bool contains_cycle() {
		//DSU logic to check cycle
		vector<int> parent(V, -1);
		vector<int> rank(V, 1);
		for (auto i : l) {
			int s1 = find(i.first, parent);
			int s2 = find(i.second, parent);

			if (s1 != s2) {
				union_set(s1, s2, parent, rank);
			} else {
				return true;
			}
		}

		return false;
	}
};

void solve() {
	int N; // no of vertices
	cin >> N;

	Graph g(N);

	int m; // edges
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		g.addEdge(x, y);
	}

	cout << g.contains_cycle() << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
}