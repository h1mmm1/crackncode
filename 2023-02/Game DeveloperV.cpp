#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using ppi=pair<ll,ll>;
using pii=pair<ll,ppi>;
const int N=2e5+5;
ll a[N];
priority_queue<pii,vector<pii>,greater<pii>> q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    a[i]+=a[i-1];
  }
  ll mx=0;
  q.push({0,{0,0}});
  for(int r=1;r<=n;r++){
//  	cout << q.top().first << "\n";
    while(q.top().second.first!=r){
      ll sum=q.top().first;
      int up=q.top().second.first;
      int id=q.top().second.second;
      q.pop();
      q.push({(a[r]-a[r-1])*(id)-a[id],{r,id}});
    }
    mx=max(mx,(a[r]-a[r-1])*(r-1)-a[r-1]-q.top().first);
    q.push({(a[r]-a[r-1])*(r-1)-a[r-1],{r,r-1}});
  }
  cout << mx;
}

/*

a1 a2 a3 a4 a5 a6 a7   a7*(7-1)-(s6-s0)
   a2 a3 a4 a5 a6 a7   a7*(7-2)-(s6-s1)
      a3 a4 a5 a6 a7   a7*(7-3)-(s6-s2)
         a4 a5 a6 a7   a7*(7-4)-(s6-s3)

                       a[r]*(r-l)-(s[r-1]-s[l-1])

                  max  a[r]*(r-1)-s[r-1]  -[ a[r]*(l-1)-s[l-1] ]  
                       a[r]*(r-1)-s[r-1] - min[ a[r]*(l-1)-s[l-1] ]  
                                       min[ a[r]*(l-1)-s[l-1],r ]  

  a[5]*5-s[5-1]

  a[13]*5-s[5-1],13.5


  a[20]*5-s[5-1],20.5

  */
