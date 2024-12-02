#include<bits/stdc++.h>
using namespace std;
char a[505][505];
int l[505][505];
int d[505][505];

int main(){
   ios::sync_with_stdio(0); cin.tie(0);
   int n,m;
   cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> a[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i][j]!='O') l[i][j]+=l[i][j-1]+1,d[i][j]+=d[i-1][j]+1;
    }
  }
  int mx=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(l[i][j]==0 || d[i][j]==0) continue;
      int x=min(l[i][j],d[i][j]);
      for(int k=x;k>0;k--){
        if(l[i-k+1][j]>=k && d[i-k+1][j-k+1]>=k && l[i-2*k+2][j]>=k){
          mx=max(mx,k);
          break;
        }
      }
    }
  }
  cout << mx;
}
/*
10 10
O......O..
O.....O...
O..O..O.OO
..OOOOOOOO
..........
......O...
..........
..........
..........
O.....OO..
*/
