#include<bits/stdc++.h>
using namespace std;
using ll=long long int; 
const int N=1e6+2;
ll a[N],dp[N],s[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		cin >> s[i];
		dp[i]=max(dp[i]+a[i],dp[i-1]+s[i]);
	}
	ll mx=0;
	for(int i=2;i<=n;i++){
		mx=max(dp[i-1]+a[i]+s[i],mx);
	}
	cout << mx;
}
