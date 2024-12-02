#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> g[N],p[N],v[N];
int cnt[N],sum[N];
  
int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    if(g[i].size()<sqrt(n)){
      p[i]=g[i];
      for(auto e:g[i]){
        if(g[e].size()>=sqrt(n)) v[i].push_back(e);
      }
    }
    else{
      for(auto e:g[i]){
        if(g[e].size()>=sqrt(n)) v[i].push_back(e);
      }
    }
  }
  
  int q;
  cin >> q;
  while(q--){
    char c;
    cin >> c;
    if(c=='U'){
      int x,y;
      cin >> x >> y;
      if(g[x].size()<sqrt(n)){
        cnt[x]+=y;
        for(auto e:g[x]){
          cnt[e]+=y;
        }
      }
      else{
        sum[x]+=y;
      }
    }
    else{
      int x,ans=0;
      cin >> x;
      ans=sum[x];
      for(auto e:v[x]){
        ans+=sum[e];
      }
      cout << cnt[x]+ans << "\n";
    }
  }
}

