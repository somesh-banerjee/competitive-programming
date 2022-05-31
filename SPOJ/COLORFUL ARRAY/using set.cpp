// Time: 2.87
// Memory: 14M

#include <bits/stdc++.h>
using namespace std;

void solve(int ttt) {
	int n, q; // edges
	cin >> n >> q;
	std::vector<int> l(q), r(q), c(q), ans(n, 0);
	for (int i = 0; i < q; ++i)
	{
		cin >> l[i] >> r[i] >> c[i];
	}
	unordered_set<int> st;
	for (int i = 1; i <= n; i++) {
		st.insert(i);
	}
	for (int i = q - 1; i >= 0; --i)
	{
		//cout << "here" << endl;
		for (auto it = st.begin(); it != st.end(); ) {
			int j = *it;
			it++;
			if (j >= l[i] && j <= r[i]) {
				ans[j - 1] = c[i];
				st.erase(st.find(j));
			}
		}
	}
	for (auto i : ans) {
		cout << i << endl;
	}
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