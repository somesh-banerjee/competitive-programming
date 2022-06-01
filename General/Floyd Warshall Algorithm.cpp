/*
	Floyd Warshall Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	vector<vector<long>> l;

public:
	Graph(int n) {
		v = n;
		l.resize(n, vector<long>(n, 100000));
		for (int i = 0; i < n; ++i)
		{
			l[i][i] = 0;
		}
	}

	void addEdge(int u, int v, long cost) {
		l[u][v] = cost;
	}

	void printAdjMat() {

		for (auto i : l) {

			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
	}

	void algorithm() {

		for (int k = 0; k < v; k++) {
			for (int i = 0; i < v; i++ ) {
				for (int j = 0; j < v; j++) {
					l[i][j] = min(l[i][j], l[i][k] + l[k][j]);
				}
			}
		}
	}
};

void solve(int ttt) {
	int n, q;
	cin >> n >> q;
	Graph g(n);
	for (int i = 0; i < q; i++) {
		int x, y;
		int z;
		cin >> x >> y >> z;
		g.addEdge(x - 1, y - 1 , z);
	}
	g.printAdjMat();
	g.algorithm();
	cout << endl;
	g.printAdjMat();
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