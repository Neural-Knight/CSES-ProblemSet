#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,q;
    cin>>n>>q;
    vector<vector<int> > v(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char ch;
            cin>>ch;
            if(ch=='.'){
                v[i][j]=0;
            }else{
                v[i][j]=1;
            }
        }
    }
    vector<vector<int> > pref(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pref[i][j]=pref[i-1][j]+pref[i][j-1]+v[i][j]-pref[i-1][j-1];
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int ans=pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1];
        cout<<ans<<"\n";
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