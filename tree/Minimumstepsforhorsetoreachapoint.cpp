#include<bits/stdc++.h>
using namespace std;
int getx(string s1){
    return s1[0]-'a';
}
int gety(string s1){
    return s1[1]-'1';
}
bool isvalid(int x,int y){
    return x>=0 && y>=0 && x<8 && y<8;
}
vector<vector<int>>movements={
    {2,1},{-2,1},{2,-1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}
};
void bfs(int x,int y,int x2,int y2,vector<vector<int>>&visited,vector<vector<int>>&depth){
    visited[x][y]=1;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int>p=q.front();
        int x1=p.first;
        int y1=p.second;
        q.pop();
        if((x1==x2)&&(y1==y2))break;
        for(auto i:movements){
            int nx=x1+i[0];
            int ny=y1+i[1];
            if(isvalid(nx,ny)&&visited[nx][ny]!=1){
                q.push({nx,ny});
                visited[nx][ny]=1;
                depth[nx][ny]=depth[x1][y1]+1;
            }
        }
        
    }

}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int x=getx(s1);
    int y=gety(s1);
    int x2=getx(s2);
    int y2=gety(s2);
    vector<vector<int>>visited(8,vector<int>(8,0));
    vector<vector<int>>depth(8,vector<int>(8,0));
    bfs(x,y,x2,y2,visited,depth);
    cout<<depth[x2][y2];
    
}