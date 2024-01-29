#include<bits/stdc++.h>
using namespace std;

#define ll long long int

map<int,int> row,clm,lt,rt;
int func(int i,vector<string>&s){
    if(i==8) return 1;
    int ct=0;
    for(int j=0; j<8; j++){
        if(s[i][j]=='*') continue;
        if(row[i]==0 && clm[j]==0 && lt[i+j]==0 && rt[16+i-j]==0){
            row[i]=1;
            clm[j]=1;
            lt[i+j]=1;
            rt[16+i-j]=1;
            ct+=func(i+1,s);
            row[i]=0;
            clm[j]=0;
            lt[i+j]=0;
            rt[16+i-j]=0;
        }
    }
    return ct;
}


int main(){
    vector<string> s;
    for(int i=0; i<8; i++){
        string p;
        cin>>p;
        s.push_back(p);
    }
    cout<<func(0,s);
    return 0;
}