#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=2e5+5,M=1e5+5;
pii g[N];
vector<int> p;
int pa[M];

int find(int x){
  if(pa[x]==x) return x;
  return pa[x]=find(pa[x]);
}

void U(int a,int b){
  a=find(a);
  b=find(b);
  if(a!=b){
    pa[a]=b;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++) pa[i]=i;
  for(int i=1;i<=m;i++){
    int a,b;
    cin >> a >> b;
    g[i]={a,b};
  }
  for(int i=1;i<=m;i++){
    int a;
    cin >> a;
    p.push_back(a);
  }
  int cnt=n;
  stack<int> ans;
  for(int i=p.size()-1;i>=0;i--){
    int a=g[p[i]].first;
    int b=g[p[i]].second;
    ans.push(cnt);
    if(find(a)!=find(b)){
      cnt--;
      U(a,b);
    }
    
  }
  while(!ans.empty()){
    cout << ans.top() << "\n";
    ans.pop();
  }
}
