#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,c,d,cnt=0;
	cin >> n >> c >> d;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		cnt=(cnt+x)%2;
	}
	if(cnt==0){
		cout << "No";
		return 0;
	}
	else{
		bool chk=true;
		n--,c--,d--;
		for(int i=0;i*c<=n;i++){
			if((n-c*i)%d==0){
				chk=false;
				break;
			}
		}
		if(chk!=false)cout << "No";
		else cout << "Yes";
	}
}
