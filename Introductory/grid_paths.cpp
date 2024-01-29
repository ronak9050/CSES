// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> vis(9,vector<int>(9,0));

// bool inbounds(int x, int y){
//     return 1 <= x && x <= 7 && 1 <= y && y <= 7;
// }


// int func(int p,int i,int j,string &s){
//     if((i==7 && j==1) || p==s.size()) {
//         // cout<<"done\n";
//         return ((i==7 && j==1) && p==s.size());
//     }
//     int x=i,y=j;
//     if((!inbounds(x+1, y) || vis[x+1][y]) && (!inbounds(x-1, y) || vis[x-1][y]))
//         if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1])
//             return 0;
//     if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1]))
//         if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y])
//             return 0;


//     int ct=0;
//     vis[i][j]=1;

//     if(s[p]=='?'){
//         ct+=func(p+1,i+1,j,s);
//         ct+=func(p+1,i-1,j,s);
//         ct+=func(p+1,i,j+1,s);
//         ct+=func(p+1,i,j-1,s);
//     }
//     else if(s[p]=='D') ct+=func(p+1,i+1,j,s);
//     else if(s[p]=='U') ct+=func(p+1,i-1,j,s);
//     else if(s[p]=='R') ct+=func(p+1,i,j+1,s);
//     else ct+=func(p+1,i,j-1,s);

//     vis[i][j]=0;
//     return ct;
// }




// #define ll long long int
// int main(){
//     string s;
//     cin>>s;
//     cout<<func(1,1,0,s);
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
const int N = 7;

int ans;
char c[N*N+1];
bool vis[N+1][N+1];

bool inbounds(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

void dfs(int x, int y, int i){
    if(i == N*N-1 || (x == N && y == 1)){
        ans += (i == N*N-1 && (x == N && y == 1));
        return;
    }

    if((!inbounds(x+1, y) || vis[x+1][y]) && (!inbounds(x-1, y) || vis[x-1][y]))
        if(inbounds(x, y-1) && !vis[x][y-1] && inbounds(x, y+1) && !vis[x][y+1])
            return;
    if((!inbounds(x, y+1) || vis[x][y+1]) && (!inbounds(x, y-1) || vis[x][y-1]))
        if(inbounds(x+1, y) && !vis[x+1][y] && inbounds(x-1, y) && !vis[x-1][y])
            return;

    vis[x][y] = true;
    if(c[i] == 'D' || c[i] == '?')
        if(inbounds(x+1, y) && !vis[x+1][y])
            dfs(x+1, y, i+1);
    if(c[i] == 'U' || c[i] == '?')
        if(inbounds(x-1, y) && !vis[x-1][y])
            dfs(x-1, y, i+1);
    if(c[i] == 'R' || c[i] == '?')
        if(inbounds(x, y+1) && !vis[x][y+1])
            dfs(x, y+1, i+1);
    if(c[i] == 'L' || c[i] == '?')
        if(inbounds(x, y-1) && !vis[x][y-1])
            dfs(x, y-1, i+1);
    vis[x][y] = false;
}

int main(){
    scanf(" %s", c);
    dfs(1, 1, 0);
    printf("%d\n", ans);
}