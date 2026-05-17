#include<bits/stdc++.h>
using namespace std;
bool checkpal(int ind,int n,string &s){
    while(ind<n){
        if(s[ind]!=s[n])
        return false;
        else{
            ind++;
            n--;
        }
    }
    return true;
}
int  palindrome(int ind,int n,string &s){
    if(ind>=n||checkpal(ind,n,s)){
        return 0;
    }
    int res=INT_MAX,cuts;
    for(int k=ind;k<n;k++){
        if(checkpal(ind,k,s)){
        cuts=1+palindrome(k+1,n,s);
        res=min(res,cuts);}
    }
    return res;
}
int main(){
    string s;
    cout<<"Enter string";
    cin>>s;
    int k=palindrome(0,s.length()-1,s);
    cout<<"minimum cut="<<k;
}