#include<bits/stdc++.h>
using namespace std;

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
