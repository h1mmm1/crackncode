#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ppi=pair<pii,int>;
const int N=5e4+5;
vector<ppi> g[N];
int v[N];
unordered_map<int,int> dis[N];
unordered_map<int,bool> vis[N];
priority_queue<ppi,vector<ppi>,greater<ppi>> q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    int k,p;
    cin >> k >> p;
    for(int j=1;j<=k;j++){
      cin >> v[j];
    }
    for(int e=2;e<=k;e++){
        g[v[e]].push_back({{v[e-1],p},i});
        g[v[e-1]].push_back({{v[e],p},i});
    }
  }
  dis[0][0]=0;
  q.push({{dis[0][0],0},0});
  while(!q.empty()){
    int l=q.top().first.first;
    int x=q.top().first.second;
    int idx=q.top().second;
    q.pop();
//    cout << x << ' ';
    if(x==n-1){
      cout << l;
      return 0;
    }
    if(vis[x].find(idx)!=vis[x].end()) continue;
    vis[x][idx]=true;
    for(auto e:g[x]){
      int xx=e.first.first;
      int ll=e.first.second;
      int k=e.second;
      if(idx==k) ll=0;
      if(dis[xx].find(k)==dis[xx].end()) dis[xx][k]=1e9;
      if(vis[xx].find(k)!=vis[xx].end()) continue;
      if(dis[xx][k]>dis[x][idx]+ll){
        dis[xx][k]=dis[x][idx]+ll;
        q.push({{dis[xx][k],xx},k});
      }
    }
  }
  cout << "-1";
}

