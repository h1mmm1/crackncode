#include<bits/stdc++.h>
using namespace std;
const int N=1001,M=701,G=1e9;
int com[M][N],sz[M][N*2],dp1[M][N*2],dp2[M][N*2],p[M];
queue<int> q;

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
  for(int i=0;i<=k;i++){
  	for(int j=1;j<=n*2;j++){
  		dp2[i][j]=dp1[i][j]=-G;
	  }
  }  
  dp1[0][com[1][1]]=sz[1][com[1][1]];
  dp1[0][1]=sz[1][com[1][1]];
  for(int l=2;l<=n;l++){
    if(com[1][1]==com[1][l]) dp1[0][l]=sz[1][com[1][1]];
  }
  int mx=sz[1][com[1][1]];
  for(int i=1;i<m;i++){
  	int e=min(k-1,i-1);
    for(int j=e;j>=0;j--){
      for(int l=1;l<=n;l++){
//        if(dp1[j][l]>0){
          dp2[j+1][com[i+1][l]]=max(dp2[j+1][com[i+1][l]],dp1[j][l]+sz[i+1][com[i+1][l]]);
          dp2[j][l]=max(dp2[j][l],dp1[j][l]);
//        }
//        if(dp1[j][com[i][l]]>0){
          dp2[j+1][com[i+1][l]]=max(dp2[j+1][com[i+1][l]],dp1[j][com[i][l]]+sz[i+1][com[i+1][l]]);
          dp2[j][l]=max(dp2[j][l],dp1[j][com[i][l]]);
//        }
      }
    }
    int ee=max(p[i+1],p[i]);
    for(int j=e+1;j>=0;j--){
      for(int l=1;l<=ee;l++){
        dp1[j][l]=dp2[j][l];
        mx=max(mx,dp1[j][l]);
        dp2[j][l]=-G;
      }
    }
  }
  cout << mx;
}
