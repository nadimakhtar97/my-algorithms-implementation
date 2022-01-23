#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];
int Par[N];

// This is DFS on tree in which
// i don't require visited array
// because a node points to two types of node
// 1. children 2. parent
void dfs(int cur,int par){
    Par[cur] = par;

    for(auto children : gr[cur]){
        if( children != par)
            dfs(children,cur);
    }

}


int main(){

    int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}


    // consider 10 as root and do dfs;
    dfs(10, 0);

	// then print all ancestors of 6
	int x = 6;

	while (x) {
		cout << x << '\n';
		x = Par[x];
	}

    return 0;
}