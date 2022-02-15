#include <bits/stdc++.h>
using namespace std;


class Graph{

public:

    int v;
    vector<int> bfs;
    vector<int> parent;
    vector<int> dist;
    vector<vector<int>> gr;


    Graph(int v)
    {
        this->v = v;
        parent.resize(v,-1);
        dist.resize(v,INT_MAX);
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
        dist[src] = 0;
        parent[src] = src;


        while(!q.empty()){

            int node = q.front();
            q.pop();
            // cout<<node<<" ";
            bfs.push_back(node);

            for(auto& nbr : gr[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr] = node;
                    dist[nbr] = dist[node] + 1;
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