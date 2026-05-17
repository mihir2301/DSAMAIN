#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ans;
    priority_queue<int,vector<int>,greater<int>>p;
    for(int i=0;i<n;i++){
        p.push(a[i]);
        if(p.size()==k){
            ans.push_back(p.top());
            p.pop();
        }
    }
    while(p.size()!=0){
        ans.push_back(p.top());
        p.pop();
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}