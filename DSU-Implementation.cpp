#include<bits/stdc++.h>
using namespace std;

class DSU{

    int* parent;
    int* rank;

    public:

    DSU(int size){

        parent = new int[size];
        rank = new int[size];

        for(int i=0;i<size;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // find function
    int find(int i){

        // base case
        if(parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    //union function
    void union_set(int x,int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2){
            if(rank[s1] > rank[s2]){
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            else{
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }            
        }
    }

};