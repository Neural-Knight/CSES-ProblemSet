#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    long minmoves=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            int diff=(arr[i]-arr[i+1]);
            minmoves+=diff;
            arr[i+1]+=diff;
        }
    }
    cout<<minmoves<<"\n";
    return 0;
}