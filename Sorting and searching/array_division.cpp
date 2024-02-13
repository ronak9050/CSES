#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    ll high=0,low=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        low=max(low,a[i]);
        high+=a[i];
    }
    
    while(low<high){
        ll mid=(low+high)/2;
        int ct=0;
        ll sum=0;
        for(int i=0; i<n; i++){
            if(sum+a[i]>mid){
                sum=0;
                ct++;
            }
            sum+=a[i];
        }
        ct++;
        if(ct>k) low=mid+1;
        else high=mid;
        // cout<<mid<<" "<<ct<<endl;
    }
    cout<<low<<endl;
    return 0;
}