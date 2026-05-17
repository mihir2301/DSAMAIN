#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter size of array and k";
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<int>p;
    for(int i=0;i<n;i++){
        p.push(a[i]);
        if(p.size()>k){
            p.pop();
        }
    }
    cout<<p.top();
}