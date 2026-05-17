#include<bits/stdc++.h>
using namespace std;
bool canplaceq(int r,int c,vector<vector<int>>&boards,int n){
    for(int i = 0; i < r; i++){
        if(boards[i][c] == 1)
            return false;
    }

        for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--){
        if(boards[i][j] == 1)
            return false;
    }

    // check right diagonal
    for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++){
        if(boards[i][j] == 1)
            return false;
    }
         return true;
    }
   

bool NQueens(int r,vector<vector<int>>&boards,int n){
    if(r==n){
        return true;
    }
    for(int i=0;i<n;i++){
       
        if(canplaceq(r,i,boards,n)){
            boards[r][i]=1;
            if(NQueens(r+1,boards,n))
            return true;
            boards[r][i]=0;
        }
       
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter value of n";
    cin>>n;
    bool ans;
    vector<vector<int>>boards(n,vector<int>(n));
    ans=NQueens(0,boards,n);

}