#include<bits/stdc++.h>
using namespace std;
using ppi=pair<int,int>;
const int N=1e5+5;
vector<ppi> g[N];
int a[N],dis[N];
bool vis[N];
vector<int> p,v;
unordered_map<int,int> mp[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    if(a[i]==1){
      p.push_back(i);
    }
  }
  for(int i=1;i<=n-1;i++){
    int aa,b,c;
    cin >> aa >> b >> c;
    aa++,b++;
    g[aa].push_back({b,c});
    g[b].push_back({aa,c});
  }
  for(auto r:p){
    queue<ppi> q;
    dis[r]=0;		
    q.push({dis[r],r});
  //	cout << r << "---\n";
    while(!q.empty()){
      int l=q.front().first;
      int x=q.front().second;
      q.pop();
      dis[x]=max(dis[x],l);
//			cout << l << ' ' << x << "\n";
      for(auto e:g[x]){
        int xx=e.first;
        int ll=e.second;
        if(a[xx]==1) continue;
        if(vis[xx]==false){
          if(mp[x][xx]<l+ll){
            mp[x][xx]=l+ll;
            vis[xx]=true;
            v.push_back(xx);
            q.push({l+ll,xx});            
          }

        }

      }
    }
    for(auto e:v) vis[e]=false;
    v.clear();
//		memset(vis,false,sizeof vis);
  }		

  for(int i=1;i<=m;i++){
    int x;
    cin >> x;
    x++;
    cout << dis[x] << "\n";
  }
}
