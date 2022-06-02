/*
	Splitwise App Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int ttt) {
	int n, q; //n : no of friends, q: no of txs
	cin >> n >> q;

	unordered_map<string, int> net;

	for (int i = 0; i < q; i++) {
		string x, y;
		int z;
		cin >> x >> y >> z;
		net[x] -= z;
		net[y] += z;
	}

	int cnt = 0;
	vector<string> tx;
	multiset < pair<int, string>> m;
	for (auto i : net) {
		if (i.second != 0) m.insert({i.second, i.first});
	}

	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());

		int cr = high->first;
		int de = low->first;
		string dep = low->second;
		string crp = high->second;
		m.erase(low);
		m.erase(high);

		int tx_amt = min(-de, cr);

		cr -= tx_amt;
		de += tx_amt;
		tx.push_back(dep + " will pay " + to_string(tx_amt) + " to " + crp);
		cnt++;

		if (cr) m.insert({cr, crp});
		if (de) m.insert({de, dep});
	}

	cout << "Minimum transactions required: " << cnt << endl;
	for (auto i : tx) {
		cout << i << endl;
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