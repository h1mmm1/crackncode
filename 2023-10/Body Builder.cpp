#include<bits/stdc++.h>
using namespace std;
int s[25];
int w[25];
int a[25];
int ans[25];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    cin >> s[i] >> w[i];
  }
  for(int i=1;i<=pow(2,n)-1;i++){
    int x=i,t=0,e=0;
    bool chk=true;
    vector<int> p;
    while(x>0){
      a[t]=x%2;
      if(x%2==1) p.push_back(t);
      x/=2;
      t++;
    }
    e=p.size();
    for(int j=0;j<e;j++){
      for(int k=j+1;k<e;k++){
        if(s[p[j]]<=s[p[k]] && w[p[j]]>=w[p[k]] ){
          chk=false;
          j=e;
          break;
        }
        else if(s[p[j]]>=s[p[k]] && w[p[j]]<=w[p[k]] ){
          chk=false;
          j=e;
          break;
        }
      }
    }
    if(chk==true ) ans[e]++;
    memset(a,0,sizeof a);
  }
  while(m--){
    int q;
    cin >> q;
    cout << ans[q] << "\n";
  }
}
