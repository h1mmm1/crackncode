#include<stdio.h>
#include<string.h>


int main(){
	int n;
	scanf("%d",&n);

	for(int i=1;i<=2*n-1;i++){
		for(int j=1;j<=2*n-1;j++){
			if(j==1  || j==2*n-1 || i==j) printf("#");
			else printf(" ");
		}
		printf("\n");
	}

	
}
