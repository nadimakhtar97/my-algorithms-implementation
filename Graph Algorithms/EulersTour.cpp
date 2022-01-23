#include<bits/stdc++.h>
using namespace std;


const int N = 1e9+1;
int gr[N];
int tin[N];   // time in
vector<int> tout[N];    // time out
int tim = 0; // curr time



// Euler Tour 1st type
void dfs1(int cur,int par){

    cout<<cur<<endl;
    tin[cur] = tim++;

    for(auto nbr : gr[cur]){

        if( nbr != par)
            dfs1(nbr,cur);

    }

    cout<<cur<<endl;
    tout[cur] = tim++;

}

// Euler Tour 2nd type
void dfs2(int cur,int par){

    cout<<cur<<endl;

    for(auto nbr : gr[cur]){

        if(nbr != par)
            dfs2(nbr,cur);

        cout<<cur<<endl;
    }
}


// Euler Tour 3rd type or Best Euler Tour
void dfs3(int cur,int par){

    tin[cur] = ++tim;

    for(auto nbr : gr[par]){

        if(nbr != par)
            dfs3(nbr,cur);
    }

    tout[cur] = tim;
}


int main(){

    
    int n; // number of edges
    cin>>n;

    for(int i=0;i<n;i++){

        int a,b;
        cin>>a>>b;

        gr[a].push_back(b);
        gr[b].push_back(a);
    }


    dfs1(1,0);

    dfs2(1,0);
}