// Time: 2.74
// Memory: 8.3M

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
	vector<int> l(q + 5), r(q + 5), c(q + 5), ans(n + 5, 0);
 
	parent.resize(n + 1);
	for (int i = 1; i <= n + 1; ++i)
	{
		parent[i] = i;
	}
 
	for (int i = 0; i < q; ++i)
	{
		cin >> l[i] >> r[i] >> c[i];
	}
 
	for (int i = q - 1; i >= 0; --i)
	{
		int index = find(l[i]);
 
		while (index <= r[i]) {
			ans[index] = c[i];
			union_set(index, index + 1);
			index = find(index);
		}
	}
 
 
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
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