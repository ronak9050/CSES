// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// bool cmp(pair<int,int>&a,pair<int,int>&b){
//     return (a.second<b.second || (a.second==b.second && a.first<b.first));
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n,k;
//     cin>>n>>k;
//     // vector<pair<int,int>> a(n);
//     multiset<pair<int,int>> st,st2;
//     for(int i=0; i<n; i++) {
//         int p,q;
//         cin>>p>>q;
//         st.insert({p,q});
//         st2.insert({q,p});
//     }

//     // for(auto e:a) cout<<e.first<<" "<<e.second<<endl;
//     int ans=0;
//     for(int i=0; i<k; i++){
//         if(st2.empty()) break;
//         auto it=st2.begin();
//         int p=it->second;
//         int q=it->first;
//         ans++;
//         st.erase(st.lower_bound({p,q}));
//         st2.erase(st2.lower_bound({q,p}));
//         auto itr = st.lower_bound({q,0});
//         while(!st.empty() && itr!=st.end()){
//             ans++;
//             p=itr->first;
//             q=itr->second;
//             itr=st.lower_bound({q,0});
//             st.erase(st.lower_bound({p,q}));
//             st2.erase(st2.lower_bound({q,p}));
//         }
//     }
//     cout<<ans<<endl;

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5, SIZE = 5e6;
const int INF = 0x3f3f3f3f;

int N, K, ans, A[maxN], B[maxN], lo[SIZE], hi[SIZE], d[SIZE], mx[SIZE];
struct Movie { int t, id, type; } movies[2*maxN];
map<int,int> mp;

void push(int i){
    if(d[i]){
        d[2*i] += d[i];
        d[2*i+1] += d[i];
        d[i] = 0;
    }
}

void pull(int i){
    mx[i] = max(mx[2*i]+d[2*i], mx[2*i+1]+d[2*i+1]);
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r)  return;
    int m = l+(r-l)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void increment(int i, int l, int r){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        d[i]++; return;
    }
    push(i);
    increment(2*i, l, r);
    increment(2*i+1, l, r);
    pull(i);
}

int maximum(int i, int l, int r){
    if(l > hi[i] || r < lo[i])      return -INF;
    if(l <= lo[i] && hi[i] <= r)    return mx[i]+d[i];

    push(i);
    int lmax = maximum(2*i, l, r);
    int rmax = maximum(2*i+1, l, r);
    pull(i);

    return max(lmax, rmax);
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &A[i], &B[i]);
        movies[2*i] = {A[i], i, 0};
        movies[2*i+1] = {B[i], i, 1};
    }
    sort(movies, movies+2*N, [](Movie a, Movie b){
        return a.t == b.t ? A[a.id] > A[b.id] : a.t < b.t;
    });

    for(int i = 0; i < 2*N; i++)
        mp[movies[i].t] = i+1;

    init(1, 1, 2*N);
    for(int i = 0; i < 2*N; i++){
        if(movies[i].type == 1){
            int id = movies[i].id;
            int a = mp[A[id]];
            int b = mp[B[id]];

            if(maximum(1, a+1, b) < K){
                increment(1, a, b);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}