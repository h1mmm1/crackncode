#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
bool a[N];
int cnt[N];
vector<int> p;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i=2;i*i<N;i++){
    if(a[i]==false){
      for(int j=i*i;j<N;j+=i){
        a[j]=true;
      }
    }
  }  
  p.push_back(2);
  for(int i=3;i<N;i+=2){
    if(a[i]==false) p.push_back(i);
  }
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    for(auto e:p){
      int mx=0;
      if(e*e>x) break;
      while(x%e==0){
        mx++;
        x/=e;
      }
      cnt[e]=max(cnt[e],mx);
    }   
    if(x>1) cnt[x]=max(cnt[x],1);
  }
  int ans=0;
  for(auto e:p){
    ans+=cnt[e];
//    if(cnt[e]>0) cout << e << ' ' << cnt[e] << "\n";
  }
  cout << ans;
}
