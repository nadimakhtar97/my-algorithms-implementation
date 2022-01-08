#include<bits/stdc++.h>
using namespace std;

// kruskal's algo is very simple the major part in 
// kruskal's algo is the implementation of DSU

class DSU{
    

    public:
    
    int disjointSetCount;
    vector<int> parent;
    vector<int> rank;
    
    
    DSU(int disjointSetCount){
        this->disjointSetCount = disjointSetCount;
        parent.resize(disjointSetCount,-1);
        rank.resize(disjointSetCount,1);
    }
    
    int find(int x){
        
        if(parent[x] == -1)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    bool union_set(int x,int y){
        
        int s1 = find(x);
        int s2 = find(y);
        
        if( s1 != s2){
                
            if(rank[s1]>rank[s2]){
                parent[s2] = s1;
                rank[s1] += rank[s2];
                disjointSetCount--;
                return true;
                
            }
            else{
                parent[s1] = s2;
                rank[s2] = rank[s1];
                disjointSetCount--;
                return true;
            }
            
        }
        
        return false;
    }
};


class Graph{

    int v;
    vector<vector<int>> edgeList;
    DSU* s;

    public:

    Graph(int v){
        this->v = v;
        s = new DSU(v);
    }

    void addEdge(int x,int y, int w)
    {
        edgeList.push_back({w,x,y});
    }

    int kruskal_mst(){

        // sort all edges according to their weight;
        sort(edgeList.begin(),edgeList.end());
        int ans = 0;

        for(auto edge : edgeList){

            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if(s->find(x) != s->find(y)){
                s->union_set(x,y);
                ans += w;
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

    cout<<g.kruskal_mst()<<endl;


}