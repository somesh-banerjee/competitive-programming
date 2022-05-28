#include <bits/stdc++.h>
using namespace std;

void solve(int testcase) {
	cout << "Case #" << testcase << ": ";
	int n, l;
	cin >> n >> l;

	pair<int, int> d[n];
	pair<int, int> p[n];

	//Observation
	// Assume ants dont bounce on collide then find the time require to fall.
	// Now if we see carefully when ants collide they just transfer their expected motion from above step to the other ant
	// First we find distance left to fall in p array.
	for (int i = 0; i < n; i++) {
		int x, dr;
		cin >> x >> dr;
		d[i] = {x, i};
		if (dr == 0) {
			p[i] = {x, 0};
		} else {
			p[i] = {l - x, 1};
		}
	}

	// sorting by distance left to fall.
	sort(p, p + n);
	sort(d, d + n);

	// In a given point only leftmost or rightmost ant will fall.
	// So keeping track of the leftmost and rightmost ants presentand not yet fallen.
	int lt = 0, rt = n - 1;

	vector<pair<int, int>> ans(n);
	for (int i = 0; i < n; ++i)
	{
		int ant = p[i].second ? d[rt--].second : d[lt++].second;
		ans[i] = {p[i].first, ant};
	}
	sort(ans.begin(), ans.end());

	for (auto i : ans) {
		cout << i.second + 1 << " ";
	}
	cout << endl;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int tt;
	cin >> tt;
	for (int i = 1; i <= tt; i++) {
		solve(i);
	}
}