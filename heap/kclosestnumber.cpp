#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,x;
    cin>>n>>k>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<pair<int,int>>p;
    for(int i=0;i<n;i++){
        p.push({abs(a[i]-x),a[i]});
        if(p.size()>k){
            p.pop();
        }
    }
    while(p.size()!=0){
        cout<<p.top().second;
        p.pop();
    }
}