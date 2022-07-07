/*

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const ll int  MOD = 1000000007;

vector<vector<ll>> g;
vector<vector<ll>> dp;
// dp[i][0] = no of ways in which index i is colored in white
// dp[i][1] = no of ways in which index i is colored in black

void dfs(ll cur, ll par) {
    // no need for visited tracking because it tree
	for (auto i : g[cur]) {
        // if i is parent continue to next iteration otherwise it will enter into infinite loop
		if (i == par) continue; 
        
        // filling the dp values for child nodes first
		dfs(i, cur);

        // now using the dp value of child i to fill dp[cur]
        // for white color at cur, child i may have black or white
		dp[cur][0] = dp[cur][0] * ((dp[i][0] + dp[i][1]) % MOD) % MOD;
        // for black color at cur, child i should have white only
		dp[cur][1] = dp[cur][1] * dp[i][0] % MOD;
	}

}

void solve(int ttt) {
	ll n;
	cin >> n;
	g.resize(n, vector<ll>());
	dp.resize(n, vector<ll>(2, 1));

	for (ll i = 0; i < n - 1; ++i)
	{
		ll x, y;
		cin >> x >> y;
		g[x - 1].pb(y - 1);
		g[y - 1].pb(x - 1);
	}
    // we are always considering 0 as head
	dfs(0, -1);
    // the total ways at head(index 0) is the answer
	cout << (dp[0][1] + dp[0][0]) % MOD << endl;

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