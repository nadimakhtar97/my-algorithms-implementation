#include <bits/stdc++.h>
using namespace std;


class Graph{

public:

    int v;
    vector<int> bfs;
    vector<vector<int>> gr;

    Graph(int v)
    {
        this->v = v;
        gr.resize(v, vector<int>());
    }

    // undirected unweighted graph
    void addEdge(int u, int v)
    {
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    void BFS(int src){

        vector<int> visited(v,0);
        queue<int> q;
        q.push(src);
        visited[src] = 1;

        while(!q.empty()){

            int node = q.front();
            q.pop();
            // cout<<node<<" ";
            bfs.push_back(node);

            for(auto& nbr : gr[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }

        }

    }


};


int main()
{

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);

    g.BFS(0);

    for(auto a : g.bfs){
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}