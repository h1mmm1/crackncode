#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll a[100005];
ll b[100005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	ll mx;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		mx=max(mx,abs(a[i]-b[i]));
	}	
	cout << mx;
}
