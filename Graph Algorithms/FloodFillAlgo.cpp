#include<bits/stdc++.h>
using namespace std;


    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        return dfs(image,sr,sc,newColor,visited,m,n);
        
    }
    
    
    // this is flood fill algo using dfs, although it can be done using bfs
    vector<vector<int>> dfs(vector<vector<int>>& image, int sr, int sc, int newColor , vector<vector<int>>& visited,int m,int n)
        
    {
        visited[sr][sc] = 1;        
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        

         for(int k=0;k<4;k++)
        {
            int xx = sr + dx[k];
            int yy = sc + dy[k];
             
            if(xx<m && xx>=0 && yy<n && yy>=0 && image[xx][yy] == oldColor && visited[xx][yy] == 0)
            {
                dfs(image,xx,yy,newColor,visited,m,n);
            }
            
        }
        
        return image;
        
    }
    