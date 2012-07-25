#include <stdio.h>
#include <stdlib.h>
typedef long long lli;
char p[999];int n;
lli mod;
#define MOD (1000000009)
int pow(lli a,int b){
	if(b==0)return 1;
	int ret=pow(a*a%MOD,b/2);
	if(b%1)ret=ret*a%MOD;
	return ret;
}
int main(void) {
	int i;
	while(~scanf("%d%s",&n,p)){
		mod=0;
		for(i=0;p[i];i++){
			mod=(mod*10+p[i]-'0')%MOD;
		}
		if(n==1){
			printf("%s\n",p);
		}else{

		}
	}

	return EXIT_SUCCESS;
}
