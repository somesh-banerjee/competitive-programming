/*
Kruskal's Algorithm for MST
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int i) {
	if (parent[i] == i) {
		return i;
	}
	return parent[i] = find(parent[i]);
}

void union_set(int a, int b) {
	int s1 = find(a);
	int s2 = find(b);

	if (s1 != s2) {
		parent[s1] = max(s1, s2);
		parent[s2] = max(s1, s2);
	}
}

void solve(int ttt) {
	int n, q; // edges
	cin >> n >> q;
	parent.resize(n + 1, -1);
	for (int i = 0; i <= n; i++) parent[i] = i;
	vector<vector<int>> edges(q, vector<int>(3));

	for (int i = 0; i < q; ++i)
	{
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0]; // Input as node1 node2 cost
	}

	sort(edges.begin(), edges.end());
	int cost = 0;
	vector<vector<int>> ans;

	for ( auto i : edges) {
		int s1 = find(i[1]);
		int s2 = find(i[2]);
		if (s1 != s2) {
			cost += i[0];
			ans.push_back({i[1], i[2]});
			union_set(s1, s2);
		}
	}
	cout << "Edges in MST:\n";
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i][0] << "--" << ans[i][1] << endl;
	}
	cout << "Total cost of MST is: " << cost << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ttt = 1;
	cin >> ttt;
	while (ttt--) {
		solve(ttt);
	}
}