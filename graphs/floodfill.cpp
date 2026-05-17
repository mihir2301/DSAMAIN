#include<bits/stdc++.h>
using namespace std;
bool issafe(int i,int j){
    return i>=0&&i<3&&j>=0&&j<4;
}
void bfs(int i,int j,vector<vector<bool>>&visited,int nw,int img[3][4]){
    visited[i][j]=true;
    img[i][j]=nw;
    queue<pair<int,int>>q;
    q.push({i,j});
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        int m=q.front().first;
        int r=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int mn=m+dir[k][0];
            int nr=r+dir[k][1];
            if(issafe(mn,nr)&&visited[mn][nr]==false&&img[mn][nr]==1){
                q.push({mn,nr});
                img[mn][nr]=nw;
                visited[mn][nr]=true;
            }
        }
    }
}
int main(){
    int img[3][4]= {{1, 1, 1, 0},  
               {0, 1, 1, 1}, 
               {1, 0, 1, 1}};
    int sr,sc,nw;
    cout<<"Enter value of sr,sc";
    cin>>sr>>sc;
    cout<<"Enter new color";
    cin>>nw;
    vector<vector<bool>>visited(3,vector<bool>(4,false));
    bfs(sr,sc,visited,nw,img);
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<img[i][j]<<" ";
        }
        cout<<endl;
    }
    }