#include<bits/stdc++.h>
using namespace std;
using ppi=pair<int,int>;
using pii=pair<ppi,int>;
const int N=1e5+5;
vector<pii> g[N];
int dis[N];
priority_queue<ppi,vector<ppi>,greater<ppi>> q;
bool vis[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		g[a].push_back({{b,c},d});
		g[b].push_back({{a,c},d});
	}
	for(int i=1;i<=n;i++) dis[i]=1e9;
	dis[1]=0;
	q.push({dis[1],1});
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		if(x==n){
			cout << dis[n];
			return 0;
		}
		for(auto e:g[x]){
			int xx=e.first.first;
			int w=e.first.second;
			int f=e.second;
			int cnt=0;
			// ((dis[x]+w)/f*f)
			if((dis[x]/f)%2==0) cnt+=(w+dis[x]%f)/f*f;
			else if((dis[x]/f)%2==1) cnt+=w/f*f+f-dis[x]%f;
			if(vis[xx]==false && dis[xx]>dis[x]+w+cnt){
				dis[xx]=dis[x]+w+cnt;
				q.push({dis[xx],xx});
			}
		}
	}
}
