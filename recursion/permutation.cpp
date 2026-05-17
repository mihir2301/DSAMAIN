#include<bits/stdc++.h>
using namespace std;
void Permut(int ind,int n,int a[],vector<int>&ds,vector<bool>&flag){
    if(ds.size()==n){
        for(auto i:ds){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(flag[i]==true){
            flag[i]=false;
            ds.push_back(a[i]);
            Permut(i,n,a,ds,flag);
            ds.pop_back();
            flag[i]=true;
        }
    }
}
int main(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    cout<<"Enter array elements";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ds;
    vector<bool>flag(n,true);
    Permut(0,n,a,ds,flag);
}