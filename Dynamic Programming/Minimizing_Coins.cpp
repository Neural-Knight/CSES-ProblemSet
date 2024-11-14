#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,x;
    cin>>n>>x;
    int coins[n];
    for(int i=0;i<n;i++) cin>>coins[i];
    vector<int> dp(x+1,1e9);
    //dp[i]= min coins to generate a sum of i
    dp[0]=0; //Base case

    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    cout<<(dp[x]<1e9?dp[x]:-1)<<"\n";
    return 0;
}