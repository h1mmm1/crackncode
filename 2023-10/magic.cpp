#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int a[1000005];
int mp[1000005];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while(q--){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
      cin >> a[i];
    }
    int cnt=0,j=1;
    ll ans=0;
    for(int i=1;i<=n;i++){
      while(cnt<k && j<=n){
        if(mp[a[j]]==0){
          mp[a[j]]++;
          cnt++;
          j++;
        }
        else{
        	mp[a[j]]++;        	
        	j++;
		}
      }
      if(cnt>=k) ans+=n-(j-1)+1;
      //cout << ans << ' '  << j-1 << "\n";
      mp[a[i]]--;
      if(mp[a[i]]==0) cnt--;
    }

    cout << ans << "\n";
  }
}
/*
k=3

1 1 2 4 5 5 3 2 2 2 2

i=1    4    8
i=2    4  8
i=3    5
i=4    7
i=5    8  
  */

