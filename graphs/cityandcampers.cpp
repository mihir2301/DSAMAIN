#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int Size[N];
multiset<int>m;

void make(int n){
    parent[n]=n;
    Size[n]=1;
    m.insert(Size[n]);
}

int find(int n){
    if(n==parent[n]) return n;
    return parent[n]=find(parent[n]);
}

void merge(int a,int b){
    m.erase(m.find(Size[a]));
    m.erase(m.find(Size[b]));
    m.insert(Size[a]+Size[b]);

}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(Size[a]>Size[b]){
            swap(a,b);
        }
        parent[a]=parent[b];
        merge(a,b);
        Size[b]+=Size[a];
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        make(i);
    }
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    if(m.size()==1){
        cout<<"0";
        return 0;
    }
    int l=*(m.begin());
    int s=*(--m.end());
    cout<<l-s;
}