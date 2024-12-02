//https://codeforces.com/blog/entry/75627

#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N],dp[N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      dp[i][j]=-1e9;
    }
  }
  for(int i=1;i+2<=n;i++){
    dp[i][i+2]=a[i]+a[i+2];
    dp[i][i+1]=0;
  }
  dp[n-1][n]=0;
  for(int i=3;i<=n;i++){
    for(int j=1;i+j<=n;j++){
      for(int k=j+1;k<i+j;k++){
        dp[j][i+j]=max(dp[j][i+j],dp[j][k]+dp[k][i+j]+a[j]+a[i+j]);
      }
    }
  }
//  for(int i=1;i<=n;i++){
//  	for(int j=1;j<=n;j++){
//  		cout << dp[i][j] << ' ';
//	  }
//	  cout << "\n";
//  }
  cout << dp[1][n];
}

