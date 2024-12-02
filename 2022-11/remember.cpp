#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int> g[N];
int cnt[N];
  
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    int a,b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int q;
  cin >> q;
  while(q--){
    char c;
    cin >> c;
    if(c=='U'){
      int x,y;
      cin >> x >> y;
      cnt[x]+=y;
      for(auto e:g[x]){
        cnt[e]+=y;
      }
    }
    else{
      int x;
      cin >> x;
      cout << cnt[x] << "\n";
    }
  }
}

