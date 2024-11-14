//Method 1
#include<bits/stdc++.h>
using namespace std;
#define int long long
int diameter = 0;

void dfs(int curnode, int parentnode, vector<vector<int>> &adj, vector<int> &distance) {
    int max1 = 0, max2 = 0;
    for (int child : adj[curnode]) {
        if (child != parentnode) {
            dfs(child, curnode, adj, distance);
            // Calculate distances properly
            if (distance[child] + 1 > max1) {
                max2 = max1;
                max1 = distance[child] + 1;
            } else if (distance[child] + 1 > max2) {
                max2 = distance[child] + 1;
            }
        }
    }
    distance[curnode] = max1;  // Update the longest distance from this node
    diameter = max(diameter, max1 + max2);  // Update diameter
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    // Read n-1 edges for a tree with n nodes
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> distance(n + 1, 0);
    diameter = 0;  // Reset diameter before each test case
    dfs(1, -1, adj, distance);  // Start DFS from node 1 (or any node)
    cout << diameter << "\n";  // Output the diameter
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}

//Method 2
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// void dfs(int curnode, int parentnode, vector<vector<int>> &adj, vector<int> &distance){
//     for(int child:adj[curnode]){
//         if(child!=parentnode){
//             distance[child]=1+distance[curnode];
//             dfs(child,curnode,adj,distance);
//         }
//     }
// }
// void solve(){
//     int n;
//     cin>>n;
//     vector<vector<int>> adj(n+1);
//     for(int i=0;i<n-1;i++){
//         int a,b;
//         cin>>a>>b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     vector<int> distance(n+1,0);
//     dfs(1,-1,adj,distance);
//     int maxdisnode=1,maxdis=-1;
//     for(int i=1;i<=n;i++){
//         if(distance[i]>maxdis){
//             maxdis=distance[i];
//             maxdisnode=i;
//         }
//         distance[i]=0;
//     }
    
//     dfs(maxdisnode,-1,adj,distance);
//     int diameter=0;
//     for(int i=1;i<=n;i++){
//         if(distance[i]>diameter){
//             diameter=distance[i];
//         }
//     }
//     cout<<diameter<<"\n";
// }
// signed main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int t=1;
// // 	cin>>t;
// 	while(t--) {
// 		solve();
// 	}
// }
