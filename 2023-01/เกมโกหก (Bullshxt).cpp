#include<bits/stdc++.h>
using namespace std;
int a[100005];
int dp[100005][105];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<=n;i++){
    
    for(int j=1;j<=m;j++){
      int x=j-1,y=j+1;
      if(j==1) x=m; 
      else if(j==m) y=1;
      if(a[i]!=j){
        dp[i][j]=min(dp[i-1][x],dp[i-1][y])+1;
      }
      else{
        dp[i][j]=min(dp[i-1][x],dp[i-1][y]);
      }
    }
  }
  int mn=INT_MAX;
  for(int i=1;i<=m;i++){
  	mn=min(mn,dp[n][i]);
  }
  cout << mn;
}

//5 10
//   8  9 4 3 2
//
//1  1  2 3 4 5
//2  1  2 3 4 2
//3  1  2 3 2 5
//4  1  2 2 4 3
//5  1  2 3 3 5
//6  1  2 3 4 3
//7  1  1 3 2 5
//8  0  2 1 4 3
//9  1  0 3 2 5
//10 1  2 3 4 3
  

