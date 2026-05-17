#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int Size[N];

void make(int n){
    parent[n]=n;
    Size[n]=1;
}

int find(int n){
    if(n==parent[n]) 
    return n;
    return parent[n]=find(parent[n]);
}

void Union(int a ,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
    if(Size[a]>Size[b]){
        swap(a,b);
    }
    
    parent[a]=parent[b];
    Size[b]+=Size[a];
}
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<n;i++){
      make(i);
    }
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        Union(u,v);
    }
    int cc=0;
    for(int i=0;i<n;i++){
        if(parent[i]==i){
            cc++;
        }
    }
    cout<<cc;
}