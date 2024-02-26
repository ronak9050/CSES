#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

/*** Needs C++11 or C++14 ***/

/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in long long

struct Treap{ /// hash = 96814
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    unordered_map <long long, int> mp; /// Change to int if only int in treap
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;

    Treap(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void clear(){
        len = 0;
        T.clear(), mp.clear();
    }

    inline void insert(long long x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }

    inline void erase(long long x){
        x += MAXVAL;
        int c = mp[x];
        if (c){
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k){
        if (k < 1 || k > len) return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    }

    /// Count of value < x in treap
    inline int count(long long x){
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }

    /// Number of elements in treap
    inline int size(){
        return len;
    }
};

bool cmp(vector<int>&a,vector<int>&b){
    return (a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    for(int i=0; i<n; i++){
        int p,q;
        cin>>p>>q;
        a[i] = {p,q,i};
    }

    sort(a.begin(),a.end(),cmp);
    Treap c = Treap();
    Treap d = Treap();
    vector<int> ans1(n,0),ans2(n,0);
    for(int i=0; i<n; i++){
        int add = c.size()-c.count(a[i][1]);
        ans1[a[i][2]]=add;
        c.insert(a[i][1]);
    }

    for(int i=n-1; i>=0; i--){
        int add=d.count(a[i][1]+1);
        ans2[a[i][2]]=add;
        d.insert(a[i][1]);
    }

    for(auto e:ans2){
        if(e) cout<<1<<" ";
        else cout<<0<<" ";
    }
    cout<<endl;
    for(auto e:ans1){
        if(e) cout<<1<<" ";
        else cout<<0<<" ";
    }

    return 0;
}