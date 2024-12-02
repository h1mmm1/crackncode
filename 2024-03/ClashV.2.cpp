#include<bits/stdc++.h>
using namespace std;
int dp[5005][8][8][8][8];
int a[8];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=0;i<8;i++) cin >> a[i];
  for(int i=1;i<5005;i++){
    for(int j=0;j<8;j++){
      for(int k=0;k<8;k++){
        for(int o=0;o<8;o++){
          for(int p=0;p<8;p++){
            dp[i][j][k][o][p]=-1;
          }
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    for(int p=0;p<8;p++){
      for(int j=0;j<8;j++){
        if(p==j) continue;
        for(int k=0;k<8;k++){
          if(p==k || j==k) continue;
          for(int o=0;o<8;o++){
            if(p==o || j==o || k==o) continue;
            if(dp[i][p][j][k][o]==-1) continue;       
            for(int e=0;e<8;e++){
              if(e==p || e==j || e==k || e==o) continue;
              dp[i+1][j][k][o][e]=max(dp[i+1][j][k][o][e],dp[i][p][j][k][o]+abs(a[e]-x));
            }
            
          }
        }
      }
    }
  }
  int mx=0;
  for(int p=0;p<8;p++){
    for(int j=0;j<8;j++){
      if(p==j) continue;
      for(int k=0;k<8;k++){
        if(p==k || j==k) continue;
        for(int o=0;o<8;o++){
          if(p==o || j==o || k==o) continue;
          mx=max(dp[n][p][j][k][o],mx);
        }
      }
    }
  }
  cout << mx;
}

