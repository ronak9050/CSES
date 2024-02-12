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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    
    Treap tp = Treap();
    for(int i=0; i<k; i++){
        tp.insert(a[i]);
    }
    int ind;
    if(k&1) ind=k/2+1;
    else ind=k/2;
    int med = tp.kth(ind);
    ll ans=0;
    for(int i=0; i<k; i++){
        ans=ans+0ll+abs(a[i]-med);
    }
    int j=0;
    vector<ll> res;
    for(int i=k; i<n; i++){
        res.push_back(ans);
        ans=ans-abs(a[j]-med);
        int pvk = tp.kth(k/2+1);
        if(k%2==0) ans=ans-abs(pvk-med);

        tp.insert(a[i]);
        tp.erase(a[j]);

        med = tp.kth(ind);
        if(k%2==0) ans=ans+abs(pvk-med);
        ans=ans+abs(a[i]-med);
        // ans+=k*1ll*abs(med-prev);
        j++;
    }
    res.push_back(ans);

    for(auto e: res) cout<<e<<" ";
    cout<<endl;

    return 0;
}