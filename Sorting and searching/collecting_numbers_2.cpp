#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(n+2,0);
    b[n+1]=n+1;
    b[0]=-1;
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[a[i]]=i;
    }

    int ans=1;
    for(int i=2; i<=n; i++){
        if(b[i]<b[i-1]) ans++;
    }

    for(int i=0; i<m; i++){
        int x,y,p,q,temp;
        cin>>x>>y;
        p=min(x-1,y-1);
        q=max(x-1,y-1);

        
        
        if(a[p]+1==a[q] || a[q]+1==a[p]){
            if(a[p]<a[q]) ans++;
            else ans--;
        }
        
            if(b[a[p]]<b[a[p]-1] && b[a[q]]>b[a[p]-1]) ans--;
            if(b[a[p]]>b[a[p]-1] && b[a[q]]<b[a[p]-1]) ans++;
            if(b[a[p]]<b[a[p]+1] && b[a[q]]>b[a[p]+1]) ans++;
            if(b[a[p]]>b[a[p]+1] && b[a[q]]<b[a[p]+1]) ans--;

            if(b[a[q]]<b[a[q]-1] && b[a[p]]>b[a[q]-1]) ans--;
            if(b[a[q]]>b[a[q]-1] && b[a[p]]<b[a[q]-1]) ans++;
            if(b[a[q]]<b[a[q]+1] && b[a[p]]>b[a[q]+1]) ans++;
            if(b[a[q]]>b[a[q]+1] && b[a[p]]<b[a[q]+1]) ans--;
    

        temp=a[p];
        a[p]=a[q];
        a[q]=temp;
        b[a[p]]=p;
        b[a[q]]=q;
        
        cout<<ans<<endl;
    }
    return 0;
}