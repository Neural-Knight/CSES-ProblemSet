#include<bits/stdc++.h>
using namespace std;
#define int long long

class DSU{
    vector<int> parent;
    vector<int> subtreesize;
    public:
    DSU(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
            subtreesize.push_back(1);
        }
    }

    int find(int u){
        while(u!=parent[u]){
            parent[u]=parent[parent[u]];
            u=parent[u];
        }
        return u;
    }
    void combine(int u, int v){
        int rootu=find(u),rootv=find(v);
        if(rootu==rootv)return;
        if(subtreesize[rootu]>subtreesize[rootv]){
            parent[rootv]=rootu;
            subtreesize[rootu]+=subtreesize[rootv];
        }
        else{
            parent[rootu]=rootv;
            subtreesize[rootv]+=subtreesize[rootu];
        }
    }
    int getsize(int u){
        return subtreesize[find(u)]*1LL;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    DSU dsu(n+1);
    int components=n,maxcount=1;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        int ru=dsu.find(u),rv=dsu.find(v);
        if(ru!=rv){
            dsu.combine(u,v);
            int tempcomp=(n-dsu.getsize(u))+1;
            if(tempcomp>=components) components--;
            else components=tempcomp;
            maxcount=max(maxcount,dsu.getsize(u));
        }
        cout<<components<<" "<<maxcount<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}