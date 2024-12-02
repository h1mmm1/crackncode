#define __USE_MINGW_ANSI_STDIO 0
#include<stdio.h>
int a[10100055],dp[10100055];
int chk(int x,int y){
	if((x==6 && y==9) || (x==9 && y==6) || (x==0 && y==0) || (x==1 && y==1) || (x==8 && y==8)) return 1;
	return 0;
}

int main(){
	
	for(int i=0;i<=10100000;i++) a[i]=0,dp[i]=0;
	for(int i=1;i<=10100000;i++){
		int x=i,k=0,t=0;
		while(x>0){
			a[k]=x%10;
			x/=10;
			k++;
		}
		for(int j=0;j<=k/2;j++){
			if(chk(a[j],a[k-j-1])==0){
				t=1;
				break;
			}
		}
		if(t==0) dp[i]++;
		dp[i+1]+=dp[i];
	}
//	for(int i=0;i<50;i++){
//		printf("%d %d\n",i,dp[i]);
//	}
	int n;
	scanf("%d",&n);
	while(n--){
		int e,r;
		scanf("%d%d",&e,&r);
		printf("%d\n",dp[r]-dp[e-1]);
	} 
}
