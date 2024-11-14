#include<bits/stdc++.h>
using namespace std;
// #define int long long
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; //find_by_order,order_of_key

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    else return a.first<b.first;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    map<pair<int,int>,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        mp[make_pair(a[i].first,a[i].second)]=i;
    }
    sort(a.begin(),a.end(),cmp);
    pbds start,end;
    vector<int> contains(n);
    for(int i=n-1;i>=0;i--){
        int e=a[i].second,s=a[i].first;
        int less=0;
        if(end.size()!=0)less=end.order_of_key(e+1);
        contains[mp[make_pair(s,e)]]=less;
        end.insert(e);
    }
    for(int i=0;i<n;i++) cout<<contains[i]<<" ";
    cout<<"\n";
    vector<int> containedby(n);
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        int e=a[i].second,s=a[i].first;
        cnt[e]++;
        int less=0;
        if(start.size()!=0)less=start.order_of_key(e);
        containedby[mp[make_pair(s,e)]]=(i-less);
        start.insert(e);
    }
    for(int i=0;i<n;i++) cout<<containedby[i]<<" ";
    cout<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}