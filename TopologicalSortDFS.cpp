#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    vector<int> topo_order;
    vector<int> visited;
    vector<vector<int>> gr;

public:
    Graph(int v)
    {
        this->v = v;
        gr.resize(v, vector<int>());
        visited.resize(v,0);
    }

    void addEdge(int u, int v)
    {
        gr[u].push_back(v);
    }



// This is the main code for topological sort
    void dfs(int src){

        visited[src] = 1;
        for(auto nbr : gr[src]){
            if(!visited[nbr])
                dfs(nbr);
        }

        topo_order.push_back(src);
        return;
    }

    void topological_sort(){
      
        for(int i=0;i<v;i++){
          if(!visited[i])
            dfs(i);
        }
        reverse(topo_order.begin(),topo_order.end());
        return;
    }

    void getOrder(){

      for(auto a : topo_order){
        cout<<a<<" ";
      }
      cout<<endl;
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

    g.topological_sort();
    g.getOrder();

    return 0;
}