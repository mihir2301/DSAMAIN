#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int low,int mid,int high){
    vector<int>temp;
    int i=low;
    int j=mid+1;
    while(i<=mid&&j<=high){
        if(a[i]<a[j]){
            temp.push_back(a[i]);
            i++;
        }
       else{ temp.push_back(a[j]);
        j++;
       }
    }
    while(i<=mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(a[j]);
        j++;
    }
    for(int i=low;i<=high;i++){
        a[i]=temp[i-low];
    }
}
void mergesort(int a[],int low,int high){
    if(low>=high)return;
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}