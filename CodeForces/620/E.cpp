/*
	Not solved 
    TLE at test 43
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
vector<int> color;
vector<int> order;


void euler_tour_2(int cur, int par) {
	// cout << cur << " ";
	order.push_back(cur);
	for (auto x : gr[cur]) {
		if (x != par) {
			euler_tour_2(x, cur);
		}
	}
	// cout << cur << " ";
	order.push_back(cur);
	return;
}

void solve(int ttt) {
	int n, m;
	cin >> n >> m;
	gr.resize(n , vector<int>());
	color.resize(n );
	for (int i = 0; i < n; i++) {
		cin >> color[i];
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		gr[x - 1].push_back(y - 1);
		gr[y - 1].push_back(x - 1);
	}
	euler_tour_2(0, -1);

	for (int i = 0; i < m; ++i)
	{
		int tk, x, y;
		cin >> tk >> x ;
		if (tk == 1) {
			cin >> y;
			bool subtree = false;
			for (int i : order)
			{
				if (i == x - 1) subtree = !subtree;
				if (subtree) {
					color[i] = y;
				}
			}
		} else {
			bool subtree = false;
			unordered_set<int> cl;
			for (int i : order)
			{
				if (i == x - 1) subtree = !subtree;
				if (subtree) {
					cl.insert(color[i]);
				}
			}
			cout << cl.size();
			cout << endl;
		}

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