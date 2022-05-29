#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], int i, bool *visited, vector<int> &stack) {
	visited[i] = true;

	for (auto nbr : graph[i]) {
		if (!visited[nbr]) {
			dfs(graph, nbr, visited, stack);
		}
	}

	stack.push_back(i);
}

void dfs(vector<int> graph[], int i, bool *visited) {
	visited[i] = true;
	cout << i << " ";
	for (auto nbr : graph[i]) {
		if (!visited[nbr]) {
			dfs(graph, nbr, visited);
		}
	}
}

void Kosaraju(vector<int> graph[], vector<int> rev_graph[], int N) {
	bool visited[N];
	memset(visited, 0, N);

    // Step 1 creating the ordering list as stack on the basis of finish time, i.e. the last to finish is at end of list like a stack
	vector<int> stack;
	for (int i = 0; i < N; ++i)
	{
		if (!visited[i]) {
			dfs(graph, i, visited, stack);
		}
	}
    // Step 2 creating reverse graph done at input
    
    // Step 3 running DFS on reverse graph and find components
	memset(visited, 0, N);
	char id = 'A';
	for (int i = stack.size(); i >= 0; --i)
	{
		int node = stack[i];
		if (!visited[node])
		{
			cout << "Component " << id++ << ": ";
			dfs(rev_graph, node, visited);
			cout << endl;
		}

	}
}

void solve() {
	int N; // no of vertices
	cin >> N;

	std::vector<int> graph[N]; // adj graph
	std::vector<int> rev_graph[N]; // for creating reverse graph

	int m; // no of edges
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		rev_graph[y].push_back(x);
	}
    // Running the algo
	Kosaraju(graph, rev_graph, N);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
}