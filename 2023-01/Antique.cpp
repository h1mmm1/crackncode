#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using ppi=pair<int,ll>;
using pii=pair<ppi,int>;
vector<ppi> p;
queue<pii> q[2];
unordered_map<int,int> mp[10];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,k,a,b;
  cin >> n >> k >> a >> b;
  for(int i=1;i<=n;i++){
    int x,y;
    cin >> x >> y;
    if(b%y==0){
      p.push_back({x,y});
    }
  }
  q[0].push({{1,1},0});
  int j=1,mx=0;
  for(auto e:p){
    int id=(j+1)%2; // j is new
    int x=p[j-1].first;
	ll y=p[j-1].second;
//    q[j&1].push({{1,1},0});
//    cout<<j<<" "<<x<<" "<<y<<"\n\n";
    while(!q[id].empty()){
      int xx=q[id].front().first.first;
      ll yy=q[id].front().first.second;
      int cnt=q[id].front().second;
      q[j&1].push({{xx,yy},cnt});
      q[id].pop();      
//      cout << j << ": " <<xx << ' ' << yy << ' ' << cnt << "\n";
      if(yy*y<b && b%(yy*y)==0){
        if(mp[xx*x%k].find(yy*y)==mp[xx*x%k].end()){
            q[id].push({{xx*x%k,yy*y},cnt+1});
//            q[j&1].push({{xx*x%k,yy*y},cnt+1});
            mp[xx*x%k][yy*y]=cnt+1;
            continue;
        }
//        if(mp[xx*x%k][yy*y]<cnt+1) q[j&1].push({{xx*x%k,yy*y},cnt+1});
        if(mp[xx*x%k][yy*y]<cnt+1){
        	q[id].push({{xx*x%k,yy*y},cnt+1});
        	mp[xx*x%k][yy*y]=cnt+1;
		}
      }
      else if(yy*y==b && xx*x%k==a) mx=max(mx,cnt+1); 

    }
    j++;
//    cout<<"\n\n";
  }
  cout << mx;
}
/*
5 5 3 32
3 32
2 4
2 2
4 8
1 2


{1,1,0} 
i=1
3,32    
{}       ans=1

{(1,1,0),(3,32,1)}            ans=1
i=2
2,4
{(1,1,0),(2,4,1),(4,16,2)}    ans=1

i=3
{(1,1,0),(2,4,1),(4,16,2)} 
*/

