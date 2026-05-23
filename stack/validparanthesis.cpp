#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int costA,costB;
    cin>>s;
    cin>>costA>>costB;
    stack<char>st;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                ans+=costB;
            }
            else st.pop();
        }
    }
    while(!st.empty()){
        ans+=costA;
        st.pop();
    }
    cout<<ans;
}