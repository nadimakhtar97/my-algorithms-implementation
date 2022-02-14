#include<bits/stdc++.h>
using namespace std;

// Prims MST for weighted undirected graph (greedy algorithm).
// Terms
// MST set = []
// Active Edge = an edge from a vertex in set MST to an edge in set visited
// MST Edge = an edge that has been included in MST so far.

// Algorithm
// 1. start from any source node
// 2. out of all active edges, pick the one with smallest weight
// -select Y in MST
// add edges starting from Y in the active edge list

class Graph{

    int v; // no. of vertex
    vector<vector<pair<int,int>>> l;   //adjacency list implementation

    public:

    Graph(int v){

        this->v = v;
        l.resize(v,vector<pair<int,int>>());
    }


    void addEdge(int x,int y,int weight){

        l[x].push_back({y,weight});
        l[y].push_back({x,weight});
    }

    // Difference between Prims and Dijkstra is “Don’t add current vertex distance to calculate neighbour distance”.
    //Example : u, v
    // Dijkstra - dis[v] = dis[u] + graph[u][v];
    // Prims - dis[v] = graph[u][v];
    int prims_mst(){

        // Min Heap Init
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> Q;

        // visited array denotes whether the node has been included in mst or not
        bool* visited = new bool[v]{0};

        // cost of minimum spanning tree
        int ans = 0;

        Q.push({0,0});  // {weight,node}

        while(!Q.empty()){

            pair<int,int>& best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;


            // if the node is visited then discard and continue
            if(visited[to])
                continue;

            visited[to] = 1;
            ans += weight;        

            // add all the active edges to heap
            for(auto edge : l[to]){

                    if(!visited[edge.first]){
                        Q.push({edge.second,edge.first});
                    }
            }


        }

        return ans;


    }




};




int main(){

    int n,m;
    cin>>n>>m;

    Graph g(n);

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;

        g.addEdge(x-1,y-1,w);
    }

    cout<<g.prims_mst()<<endl;


}