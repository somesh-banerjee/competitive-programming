/*
	Dijkstra's Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
	unordered_map<T, vector<pair<T, int>>> l;

public:

	void addEdge(T u, T v, int cost, bool bidir = true) {
		l[u].push_back(make_pair(v, cost));
		if (bidir)
			l[v].push_back(make_pair(u, cost));
	}

	void printAdj() {

		for (auto i : l) {
			cout << i.first << "->";

			for (auto j : i.second) {
				cout << "(" << j.first << "," << j.second << "),";
			}
			cout << endl;
		}
	}

	void dijkstra(T src) {
		unordered_map<T, int> dist;

		for (auto i : l) {
			dist[i.first] = INT_MAX;
		}

		set<pair<int, T>> s; // sorting based on weight

		dist[src] = 0;
		s.insert(make_pair(0, src));

		while (!s.empty()) {

			auto p = *(s.begin());
			T node = p.second;
			int curDist = p.first;
			s.erase(s.begin());

			for (auto i : l[node]) {
				if (curDist + i.second < dist[i.first]) {
					auto f = s.find(make_pair(dist[i.first], i.first));
					if (f != s.end()) {
						s.erase(f);
					}
					s.insert(make_pair(curDist + i.second, i.first));
					dist[i.first] = curDist + i.second;
				}
			}
		}
		cout << src << " to" << endl;
		for (auto i : dist) {
			cout << i.first << " " << i.second << endl;
		}

	}
};

void solve(int ttt) {
	int q;
	cin >> q;
	Graph<string> g;
	for (int i = 0; i < q; i++) {
		string x, y;
		int z;
		cin >> x >> y >> z;
		g.addEdge(x , y , z);
	}
	g.printAdj();
	cout << endl;
	g.dijkstra("Amritsar");
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