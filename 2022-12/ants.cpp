#include<bits/stdc++.h>
using namespace std;
using ll=long long int;

int main(){
   ios::sync_with_stdio(0); cin.tie(0);
   int n;
   ll cnt=0,ans=0;
  cin >> n;
  for(int i=1;i<=n;i++){
    int m;
    cin >> m;
    if(m==1) cnt++;
    else ans+=cnt;
  }
  cout << ans;
}
