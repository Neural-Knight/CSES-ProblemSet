#include<bits/stdc++.h>
using namespace std;
//#define int long long

bool dfs(int currnode, int parentnode, vector<int> &vis,  vector<vector<int>> &adj, vector<int> &path,vector<int> &parent){
    vis[currnode]=1;
    parent[currnode]=parentnode;
    for(int child:adj[currnode]){
        if(child==parentnode) continue;
        if(vis[child]){
            path.push_back(child);
            int u=currnode;
            while(u!=child){
                path.push_back(u);
                u=parent[u];
            }
            path.push_back(u);
            return true;
        }else{
            bool flag=dfs(child,currnode,vis,adj,path,parent);
            if(flag) return true;
        }
    }
    return false;
}

void solve(){
    int n,m,z;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0),parent(n+1,-1);
    vector<int>path;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i,-1,vis,adj,path,parent)){
                cout<<path.size()<<"\n";
                for(int x:path){
                    cout<<x<<" ";
                }
                cout<<"\n";
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
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