/*
	Euler tour
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> gr[N];
int tin[N], tout[N], timer = 0;

void euler_tour_1(int cur, int par) {
	cout << cur << " ";
	for (auto x : gr[cur]) {
		if (x != par) {
			euler_tour_1(x, cur);
			cout << cur << " ";
		}
	}
	return;
}

void euler_tour_2(int cur, int par) {
	cout << cur << " ";
	for (auto x : gr[cur]) {
		if (x != par) {
			euler_tour_2(x, cur);
		}
	}
	cout << cur << " ";
	return;
}

void euler_tour_3(int cur, int par) {
	cout << cur << " ";
	tin[cur] = ++timer;
	for (auto x : gr[cur]) {
		if (x != par) {
			euler_tour_3(x, cur);
		}
	}
	tout[cur] = timer;
	return;
}

void solve(int ttt) {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	// euler_tour_1(1, 0);
	// euler_tour_2(1, 0);
	euler_tour_3(1, 0);
	cout << endl;
	for (int i = 1; i < n + 1; ++i)
	{
		cout << i << " " << tin[i] << " " << tout[i] << endl;
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