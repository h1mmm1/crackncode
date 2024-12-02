#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e5+5,MOD=1e9+7;
vector<int> g[N];
long long int dp[N],f[N],sum[N],ff[N];

inline ll ncr(ll n,ll r){
	return ((ff[n]*f[n-r])%MOD*f[r])%MOD;
}

inline ll rec(int x){
	ll cnt=1,n=sum[x];
	for(auto e:g[x]){
		cnt=((cnt*ncr(n,sum[e]+1))%MOD*rec(e))%MOD;
		n-=sum[e]+1;
	}
	return dp[x]=cnt;
}

inline int dfs(int x){
	int cnt=g[x].size();
	for(auto e:g[x]){
		cnt+=dfs(e);
		cnt%=MOD;
	}
	return sum[x]=cnt;
}

inline ll mod(ll n,ll m){
	ll ans=1;
	while(m>0){
		if(m%2==1){
			ans*=n;
			ans%=MOD;
		}
		n*=n;
		n%=MOD;
		m/=2;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	ff[0]=1;
	f[0]=1;
	for(int i=1;i<=n;i++){
		ff[i]=ff[i-1]*i;
		ff[i]%=MOD;
		f[i]=mod(ff[i],MOD-2);
	}
	for(int i=1;i<=n-1;i++){
		int a,b;
		cin >> a >> b;
		g[b].push_back(a);
	}
	dfs(1);
	cout << rec(1);	
//	for(int i=1;i<=n;i++){
//		cout << '\n' << dp[i];
//	}
}
