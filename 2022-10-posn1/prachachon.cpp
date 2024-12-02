#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int cnt=0,x=13;
		char s[15];
		scanf("%s",&s);
		for(int i=0;i<12;i++){
			cnt+=(s[i]-'0')*x;
			x--;
			cnt%=11;
		}
//		cout << cnt << ' ';
		int y=(11-(cnt))%10;
//		cout << cnt;
		if(s[12]-'0'==y) printf("Y\n");
		else printf("N\n");
	}
}
