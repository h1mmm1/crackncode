#include<stdio.h>

int main(){
	int t=5;
	while(t--){
		int a[65];
		int b[65];
		for(int i=0;i<65;i++) a[i]=0,b[i]=0;
		long long int n,x=0;
		scanf("%lld",&n);
		while(n>0){
			a[x]=n%2;
			x++;
			n/=2;
		}
		int ans=0,cnt=0,j=1;
		for(int i=0;i<x;i++){
			b[i]=a[x-i-1];
		}
		for(int i=0;i<=x;i++){
			//printf("%d\n",b[i]);
			if(b[i]==0){
				ans+=cnt;
				cnt=0;
				j=1;
			} 
			else{
				cnt+=j;
				j*=2;
			}
		}
		printf("%d\n",ans);

	}
}
