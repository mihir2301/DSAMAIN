//Snakes and transition from Capitalism and Socialism

#include<bits/stdc++.h>
using namespace std;

int visited[1000][1000];
int level[1000][1000];

vector<vector<int>>movements={{1,1},{-1,1},{-1,-1},{1,-1},{1,0},{-1,0},{0,1},{0,-1}};

bool isvalid(int x,int y,int n,int m){
    return x>=0 && y>=0 && x<n && y<m;
}
int bfs(vector<vector<int>>&grid,int n,int m){
    int a=INT_MIN;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,grid[i][j]);
        }
    }
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==ans){
                q.push({i,j});
                visited[i][j]=1;
                level[i][j]=0;
            }
        }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto child:movements){
                int nx=x+child[0];
                int ny=y+child[1];
                if(isvalid(nx,ny,n,m)&&visited[nx][ny]!=1){
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                    level[nx][ny]=level[x][y]+1;
                    a=max(a,level[nx][ny]);
                }
            }
        }
        return a;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int p;
            cin>>p;
            grid[i][j]=p;
        }
    }
    cout<<bfs(grid,n,m);
}