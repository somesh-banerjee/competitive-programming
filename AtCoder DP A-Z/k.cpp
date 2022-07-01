/*
 
*/
 
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
 
const ll mod = 1e9 + 7;
 
void solve(int ttt) {
	ll n, k;
	cin >> n >> k;
 
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
 
	vector<ll> dp(k + 1, 0); // dp[k] tells winner with k stones at start.
    //dp[k]=1 means winner is first else second
	for (int i = 1; i <= k; i++) {
		for (int x : a) {
            //when dp[i-x]==0 i.e. winner is second so dp[i] winner is first
			if (x <= i && dp[i - x] == 0) {
				dp[i] = 1;
				break;
			}
		}
	}
 
	if (dp[k]) {
		cout << "First\n";
	} else {
		cout << "Second\n";
	}
 
}
 
int main() {
 
	std::clock_t start;
	start = std::clock();
 
	int ttt = 1;
	// cin >> ttt;
	while (ttt--) {
		solve(ttt);
	}
 
	// cout << "\nTime: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
	return 0;
}