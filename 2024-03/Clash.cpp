#include<bits/stdc++.h>
using namespace std;
const int N=5005,M=10;
int a[M],b;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,mn=INT_MAX,mx=0;
  cin >> n;
  for(int i=0;i<8;i++){
    cin >> a[i];
  }
  
  int ans=0,cnt=0;
  for(int i=1;i<=n;i++){
    cin >> b;
    int mx=0,id;
    for(int j=0;j<4;j++){
      if(mx<abs(b-a[j])){
        mx=abs(b-a[j]);
        id=j;
      }
    }
    ans+=mx;
    int x=a[id];
    for(int k=id;k<7;k++){
      a[k]=a[k+1];
    }
    a[7]=x;
  }
  cout << ans;
}
