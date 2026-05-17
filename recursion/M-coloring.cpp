#include<bits/stdc++.h>
using namespace std;
bool checkcancolor(int ind,vector<int>adj[],vector<int> &color){
    for(auto i:adj[ind]){
        if(color[i]==color[ind])
        return false;
    }
    return true;
}
bool Mcolor(int ind,vector<int>adj[],vector<int> &color,int m,int n){
    if(ind==n){
        return true;
    }
    for(int i=0;i<m;i++){
        color[ind]=i;
            if(checkcancolor(ind,adj,color))
            {
           if( Mcolor(ind+1,adj,color,m,n))
                return true;
        }
        color[ind]=-1;
    }
    return false;
}
int main(){
    int m;
    cout<<"Enter value of m";
    cin>>m;
    int n;
    cout<<"Enter no. of nodes";
    cin>>n;
    int v;
    cout<<"Enter no. of edges";
    cin>>v;
    vector<int>adj[n];
    for(int i=0;i<v;i++){
        int t,c;
        cin>>t>>c;
        adj[t].push_back(c);
        adj[c].push_back(t);
    }
    vector<int>color(n,-1);
    bool k=Mcolor(0,adj,color,m,n);
    if(k==true){
        cout<<"Yes";
    }
    else cout<<"NO";
}