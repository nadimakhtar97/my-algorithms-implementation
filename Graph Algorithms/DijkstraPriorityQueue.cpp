#include <bits/stdc++.h>
using namespace std;

// dijkstra's algo is like bfs in a weighted undirected graph
// in bfs we use queue and in dijkstra's we use *priority_queue*
// we also find shortest path using bfs if the given graph
// is undirected unweighted graph.

// there are two implementation for dijkstra one using set other
// using priority queue. priority_queue is more intiuitive as
// it matches with bfs

class Graph
{

    int v;
    vector<vector<pair<int, int>>> gr;

public:
    Graph(int v)
    {
        this->v = v;
        gr.resize(v, vector<pair<int, int>>());
    }

    void addEdge(int u, int v, int w)
    {

        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    int dijkstra(int src, int dst)
    {

        vector<int> dist(v, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        dist[src] = 0;
        q.push({0, src}); // {distance,node}

        while (!q.empty())
        {

            int distTillNow = q.top().first;
            int node = q.top().second;
            q.pop();

            //Iterate over nbrs of node
            for (auto nbrPair : gr[node])
            {

                int nbr = nbrPair.first;
                int currentEdge = nbrPair.second;

                if (distTillNow + currentEdge < dist[nbr])
                {
                    // insert the updated value with new distance
                    dist[nbr] = distTillNow + currentEdge;
                    q.push({dist[nbr], nbr});
                }
            }
        }

        return dist[dst];
    }
};

int main()
{

    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(1,2,1);
    g.addEdge(2,3,2);
    g.addEdge(3,4,3);

    cout << g.dijkstra(0, 4) << endl;

    return 0;
}