/*
	Min Query Sparse Table
*/

#include <bits/stdc++.h>
using namespace std;

struct sparse_table
{
	vector<vector<int>> mat;
	int n, m;
	vector<int> p2;

	void init(int _n) {
		n = _n;
		m = ceil(log2(n)) + 1;
		mat.resize(n, vector<int>(m));
		p2.resize(n + 1);
		p2[0] = p2[1] = 0;
		for (int i = 2; i <= n; i++) {
			p2[i] = p2[i / 2] + 1;
		}
	}

	void build(vector<int> &arr) {
		for (int i = 0; i < n; i++) mat[i][0] = arr[i];
		for (int j = 1; j < m; j++) {
			for (int i = 0; i + (1 << j) <= n; i++) {
				mat[i][j] = min(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	int query(int l, int r) {
		int pw = p2[r - l];
		return min(mat[l][pw], mat[r - (1 << pw) + 1][pw]);
	}
};

void solve(int ttt) {
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sparse_table st;
	st.init(n);
	st.build(arr);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << st.query(l, r) << endl;
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