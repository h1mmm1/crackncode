#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=705,G=-0x3f;
int com[M][N],sz[M][N*2],dp1[M][N*2],dp2[M][N*2],p[M];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=1;i<=m;i++){
    int x;
    cin >> x;
    vector<int> g[N];
    for(int j=1;j<=x;j++){
      int u,v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    queue<int> q;
    int o=n;
    if(i==1) o=1;
    int cnt=n,sum=0;
    for(int j=1;j<=o;j++){
      if(com[i][j]!=0) continue;
      q.push(j);
      sum=0;
      cnt++;
      com[i][j]=cnt;
      while(!q.empty()){
        int x=q.front();
        q.pop();
        sum++;
        for(auto e:g[x]){
          if(com[i][e]==0){
            q.push(e);
            com[i][e]=cnt;

          }
        }
      }
      sz[i][cnt]=sum;
    }
    p[i]=cnt;
  }
  memset(dp1, -0x3f, sizeof(dp1));
  memset(dp2, -0x3f, sizeof(dp2));
  for(int l=1;l<=n;l++){
    if(com[1][1]==com[1][l]) {
      dp1[0][l]=sz[1][com[1][1]];
//      dp2[0][l]=sz[1][com[1][1]];
      dp1[0][com[1][l]]=sz[1][com[1][1]];
//      dp2[0][com[1][l]]=sz[1][com[1][1]];
    }
  }
  int mx=sz[1][com[1][1]];
  for(int i=1;i<m;i++){
    int e=min(k-1,i);
    for(int j=e;j>=0;j--){
      for(int l=1;l<=n;l++){
        // if(dp1[j][l]>0){
          dp2[j+1][com[i+1][l]]=max(dp2[j+1][com[i+1][l]],dp1[j][l]+sz[i+1][com[i+1][l]]);
//          dp2[j][l]=max(dp2[j][l],dp1[j][l]);
        // }
        // if(dp1[j][com[i][l]]>0){
          dp2[j+1][com[i+1][l]]=max(dp2[j+1][com[i+1][l]],dp1[j][com[i][l]]+sz[i+1][com[i+1][l]]);
          dp2[j][l]=max(dp2[j][l],dp1[j][com[i][l]]);
        // }
      }
    }
    int ee=max(p[i+1],p[i]);
    if(i+1>=k) for(int l=1;l<=ee;l++) mx=max(mx,dp2[k][l]);

    for(int j=e+1;j>=0;j--){
      for(int l=1;l<=ee;l++){
        dp1[j][l]=dp2[j][l];
      }
      for(int l=n+1;l<=ee;l++){
        dp2[j][l]=G;
      }
    }
  }
  cout << mx;
}
