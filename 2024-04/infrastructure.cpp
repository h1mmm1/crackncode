#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5;
int a[N],chk[N],cnt[N],qs[N],dp[N];
queue<int> q;
vector<int> g[N],p[N];
bool vis[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,s,k;
	cin >> n >> m >> s >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++){
		int v,u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	int mx=0;
	vis[s]=true;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto e:g[x]){
			if(vis[e]) continue;
			vis[e]=true;		
			chk[e]=chk[x]+1;
			mx=max(mx,chk[e]);
			p[chk[e]].push_back(e);
			q.push(e);
		}
	}
	for(int i=1;i<=n;i++) cnt[i]=1e9;
	ll sum=0;
	priority_queue<ll> mn;	
	for(int i=mx;i>0;i--){
		for(auto e:p[i]) mn.push(a[e]);
		if(!mn.empty()){
			cnt[i]=mn.top();
			sum+=mn.top();
			mn.pop();
		}
	}		
	dp[1]=cnt[1];
	for(int i=2;i<=n;i++){
		cnt[i]=min(cnt[i],cnt[i-1]);
		dp[i]=cnt[i];
//		qs[i]=qs[i-1]+cnt[i];
	}
	sort(dp+1,dp+1+n);
	
	for(int i=1;i<=n;i++){
		qs[i]=qs[i-1]+dp[i];
	}
	while(k--){	
		ll ans=0;
		int t,y,u;
		cin >> t;	
		if(t==1){
			ans=sum;
			cin >> y >> u;
			int x=chk[y]+1;
			if(x>mx) ans+=u;
			else{
				if(cnt[x]<u){
					ans-=cnt[x];
					ans+=u;
				}
			}
			cout << ans << "\n";	
		}
		else{
			cin >> u;
			auto v=lower_bound(dp+1,dp+1+n,u)-dp-1;
			cout << sum*(n)-qs[v]+u*(v) << "\n";
            cout << sum*(n)<<" "<< v <<" " << qs[v]<< " " << u*(v);			
//			 << ' ' << v << "---\n";
//			for(int i=1;i<=n;i++){
//				ll tmp=sum;
//				int x=chk[i]+1;
//				if(x>mx) tmp+=u;
//				else{
//					if(cnt[x]<u){
//						tmp-=cnt[x];
//						tmp+=u;
//						cout << cnt[x] << "\n";
//					}					
//				}
//				cout << tmp << "\n";
//				ans+=tmp;
//			}
		}
	}
	cout << "\n";
	for(int i=1;i<=n;i++) cout << dp[i] << ' ';
	cout << "\n";
	for(int i=1;i<=n;i++) cout << qs[i] << ' ';
	cout << "\n";
	for(int i=1;i<=n;i++) cout << cnt[i] << ' ';
	
}
/*
8 7 1 1
300 100 50 90 150 200 600 300
1 2
2 3
3 4
4 5
5 6
6 7
7 8
2 10000

6 8 3 7
1 100 0 1 100 2000
1 2
2 3
3 4
4 5
5 6
1 5
2 4
1 6
1 6 50
1 5 50
1 4 50
1 3 50
1 2 50
1 1 50
2 50


*/
