#include<bits/stdc++.h>
using namespace std;

// Presence of back edge in a graph implies cycle in graph
// There are two case for backedge detection in graph
// back-edge detection in Undirected graph -- not valid for directed graph
// (peform dfs on graph if(vis[nbr] and nbr != parent)==> back-edge is present) --> simple condition for backedge detection in undirected graph
// back-edge detection in Directed graph -- valid for both directed and undirected graph


// Here we discuss back-edge in directed graph as it is more important

// Special property of DFS and Ancestor
//--> ancestor of a node has to be in call stack when I reach the current node;
// using this property only we will find back-edge in directed graph.

// Whatever node is in the top of call stack all other node in the call stack are it ancestors.

// state of node
// 0 -> not visited
// 1 -> visited but in call stack
// 2 -> visited but not in call stack


const int N = 1e5 + 1;

vector<int> gr[N];
int vis[N];
bool cycle = false;

void dfs(int cur, int par) {
	// visited and in call stack
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (vis[x] == 0) {
			dfs(x, cur);
		}
		else if (x != par && vis[x] == 1) {
			// backedge
			cycle = true;
		}
	}
	// visited and not in call stack
	vis[cur] = 2;
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs(i, 0);
		}
	}

	if (cycle) {
		cout << "Yes cycle found";
	}
	else {
		cout << "Not found";
	}


	return 0;
}