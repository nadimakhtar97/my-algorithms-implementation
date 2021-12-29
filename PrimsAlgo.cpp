#include<bits/stdc++.h>
using namespace std;

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

    int prims_mst(){

        // Min Heap Init
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> Q;

        // visited array denotes whether the node has been included in mst or not
        bool* visited = new bool[v]{0};

        // cost of minimum spanning tree
        int ans = 0;

        Q.push({0,0});  // {weight,node}

        while(!Q.empty()){

            pair<int,int> best = Q.top();
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