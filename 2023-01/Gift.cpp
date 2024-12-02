#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e4+5;
ll a[N],b[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++) cin >> a[i],a[i]+=a[i-1];
		for(int i=1;i<=n;i++) cin >> b[i];
		ll l=1,ans=0,mn=1e18,id=n+1;
		for(int r=1;r<=n;r++){
			if(a[r]-a[l-1]>m){
				l=r;
				ans+=mn;
				mn=1e18;
				id=l;
			}
			else{
				mn=min(b[r],mn);
			}
//			cout << l << ' ' << r << ' ' << ans << "\n";
		}
		if(mn==1e18){
			mn=1e18;
			for(int i=id;i<=n;i++){
				mn=min(mn,b[i]);
			}
			ans+=mn;
		}
		cout << ans << "\n";
	}
}
