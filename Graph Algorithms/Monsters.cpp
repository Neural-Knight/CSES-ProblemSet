#include<bits/stdc++.h>
using namespace std;
// #define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];

    auto is_valid=[&](int i, int j){
        if(i<0 || i>=n) return false;
        if(j<0 || j>=m) return false;
        if(grid[i][j]=='#') return false;
        return true;
    };
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    char symbol[]={'D','U','R','L'};
    vector<vector<int>> time(n,vector<int>(m,1e6));
    queue<array<int,3>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M') q.push({i,j,0});
        }
    }
    while(!q.empty()){
        auto [i,j,t]=q.front();
        q.pop();
        if(time[i][j]<=t) continue;
        time[i][j]=t;
        for(int dir=0;dir<4;dir++){
            int ni=i+dx[dir],nj=j+dy[dir];
            if(is_valid(ni,nj)&&(t+1)<time[ni][nj]){
                q.push({ni,nj,t+1});
            }
        }
    }
    vector<vector<int>> direction(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                direction[i][j]=0;
                q.push({i,j,0});
                break;
            }
        }
    }
    while(!q.empty()){
        auto [i,j,tm]=q.front();
        q.pop();
        for(int dir=0;dir<4;dir++){
            int ni=i+dx[dir],nj=j+dy[dir];
            if(is_valid(ni,nj)&&(tm+1)<time[ni][nj]&&direction[ni][nj]==-1){
                direction[ni][nj]=dir;
                q.push({ni,nj,tm+1});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!='#' &&(i==0 || i==n-1 || j==0 || j==m-1)){
                if(direction[i][j]==-1)continue;
                string path;
                while(grid[i][j]!='A'){
                    int d=direction[i][j];
                    path.push_back(symbol[d]);
                    i=i-dx[d],j=j-dy[d];
                }
                reverse(path.begin(),path.end());
                cout<<"YES\n"<<path.size()<<"\n"<<path<<"\n";
                return;
            }
        }
    }
    cout<<"NO\n";
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