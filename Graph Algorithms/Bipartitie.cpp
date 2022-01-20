#include<bits/stdc++.h>
using namespace std;

class Graph {
public:

    int v;
    vector<vector<int>> gr;

    Graph(int v)
    {
        this->v = v;
        gr.resize(v,vector<int>());
    }

    void addEdge(int u, int v)
    {

        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    
    
    bool dfs(int src,int parent,int color,vector<int>& visited){
        
        visited[src] = color;
        for(auto nbr : gr[src]){
            
            if(visited[nbr] == 0){
                
                bool subProblem = dfs(nbr,src,3-color,visited);
                if(subProblem == false){
                    return false;
                }
            }
            else if( nbr != parent and visited[nbr] == visited[src]){
                return false;
            }
        }
        
        return true;
        
    }
    
    bool isBipartite() {
        

        bool isBip = true;
        vector<int> visited(v,0);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
                isBip = dfs(i,-1,1,visited);
                if(isBip == false)
                    return false;
            }
        }
        
        return isBip;
        
    }
};


int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,2);

    cout << g.isBipartite()<< endl;

    return 0;
}