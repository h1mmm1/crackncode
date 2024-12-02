#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5;
ll v[N],w[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  ll n,m,p;
  cin >> n >> m >> p;
  for(int i=1;i<=n;i++){
    cin >> v[i] >> w[i];
    v[i]+=v[i-1];
    w[i]+=w[i-1];
  }
  if(m==n && p==2){
    auto u=lower_bound(w+1,w+1+m,w[m]/2)-w;
    ll x=w[u],y=w[m]-w[u],xx,yy;
    ll ans=v[m]-(max(x,y)*max(x,y));
    if(u>1) {
      xx=w[u-1],yy=w[m]-w[u-1];
      ans=max(ans,v[m]-(max(xx,yy)*max(xx,yy)));
    }
    cout << ans;
  }
  else if(p==2){
    ll ans=-2e18;
    for(int i=1;i<=n-m+1;i++){
      auto u=lower_bound(w+i,w+i+m,w[i-1]+(w[m+i-1]-w[i-1])/2)-w;
      ll x=w[u]-w[i-1],y=w[m+i-1]-w[u],xx,yy;
      ans=max(ans,v[m+i-1]-v[i-1]-max(x,y)*max(x,y));
      if(u>i){
        xx=w[u-1]-w[i-1],yy=(w[m+i-1]-w[u-1]);
        ans=max(ans,v[m+i-1]-v[i-1]-max(xx,yy)*max(xx,yy));
      }
    }
    cout << ans;
  }
  else if(m==n){
    ll l=0,r=w[n];
    while(l<r){
      int mid=(l+r)/2;
      int cnt=0;
      auto e=w+1;
      while(e!=w+1+n){
        auto u=upper_bound(e,w+1+n,*(e-1)+mid);
        if(e==u){
          cnt=p+1;
        }
        cnt++;
        e=u;
        if(cnt>p) break;
      }
      if(cnt>p) l=mid+1;
      else r=mid;      
    }
    cout << v[n]-l*l;
  }
  else{
    ll ans=-2e18;
      for(int i=1;i<=n-m+1;i++){
        ll l=0,r=w[m+i-1];
        while(l<r){
          int mid=(l+r)/2;
          int cnt=0;
          auto e=w+i;
          while(e!=w+i+m){
            auto u=upper_bound(e,w+i+m,*(e-1)+mid);
            if(e==u){
              cnt=p+1;
              break;
            }
            cnt++;
            e=u;
            if(cnt>p) break;
          }
          if(cnt>p) l=mid+1;
          else r=mid;
        }
        ans=max(ans,v[m+i-1]-v[i-1]-l*l);
      }
    cout << ans;
  }
}
