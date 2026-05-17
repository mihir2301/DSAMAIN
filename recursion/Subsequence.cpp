#include<bits/stdc++.h>
using namespace std;
void sub(int ind,int n,int a[],vector<int>ds){
    if(ind==n){
        for(auto i:ds){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }

        ds.push_back(a[ind]);
        sub(ind+1,n,a,ds);
        ds.pop_back();
        sub(ind+1,n,a,ds);
    
}
int main(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    cout<<"Enter array elements";
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ds;
    sub(0,n,a,ds);
}