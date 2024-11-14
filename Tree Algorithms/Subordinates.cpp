#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int curnode, int parentnode, vector<vector<int>> &adj, vector<int> &subtreesize){
    subtreesize[curnode]=1;
    for(int child:adj[curnode]){
        if(child!=parentnode){
            dfs(child,curnode,adj,subtreesize);
            subtreesize[curnode]+=subtreesize[child];
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    int i=2;
    for(int j=0;j<n-1;j++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
        i++;
    }
    vector<int> subtreesize(n+1,0);
    dfs(1,-1,adj,subtreesize);
    for(int i=1;i<=n;i++){
        cout<<subtreesize[i]-1<<" ";
    }
    cout<<"\n";
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t=1;
// 	cin>>t;
	while(t--) {
		solve();
	}
}
