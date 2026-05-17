#include<bits/stdc++.h>
using namespace std;
int cost(int n,int height[]){
    if(n==0)return 0;
    int mincost=INT_MAX;
    mincost=min(mincost,cost(n-1,height)+abs(height[n]-height[n-1]));
    if(n>1)
    mincost=min(mincost,cost(n-2,height)+abs(height[n-2]-height[n]));
    return mincost;
}
int main(){
    int height[4]={20,30,40,20};
    int ans=cost(3,height);
    cout<<ans;
}