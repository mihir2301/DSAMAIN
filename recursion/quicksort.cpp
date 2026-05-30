#include<bits/stdc++.h>
using namespace std;

int part(int a[],int low,int high){
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j){
        while(a[i]<=pivot && i<=j){
            i++;
        }
        while(a[j]>pivot&&j>=i){
            j--;
        }
        if(i<j)
        swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}

void quicksort(int a[],int low,int high){

    if(low>=high)return;
    int pivot=part(a,low,high);
    quicksort(a,low,pivot-1);
    quicksort(a,pivot+1,high);

}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}