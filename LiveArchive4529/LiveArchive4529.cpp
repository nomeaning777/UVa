#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int MAP[16][16];
int N,T,ans;
int used[3][128];
int dp[1<<16][16];

int maximum(int y,int used){
	int i;
	if(y==N)return 0;
	int ret=dp[used][y];
	if(ret==-1){
		for(i=0;i<N;i++){
			int tmp;
			if(used>>i&1)continue;
			tmp=MAP[y][i]+maximum(y+1,used|(1<<i));
			if(ret<tmp){
				ret=tmp;
			}
		}
	}
	dp[used][y]=ret;
	return ret;
}
void solve(int y,int score,int usedX){
	int i;
	if(y==N){
		if(ans<score){
			ans=score;
		}
		return;
	}
	if(score+maximum(y,usedX)<=ans)return;
	for(i=0;i<N;i++){
		if(used[0][i])continue;
		if(used[1][i+y+64])continue;
		if(used[2][i-y+64])continue;
		used[0][i]=used[1][i+y+64]=used[2][i-y+64]=1;
		solve(y+1,score+MAP[y][i],usedX|(1<<i));
		used[0][i]=used[1][i+y+64]=used[2][i-y+64]=0;
	}
}
int main(void) {
	int i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				scanf("%d",&MAP[i][j]);
			}
		}
		ans=0;
		memset(dp,-1,sizeof(dp));
		solve(0,0,0);
		printf("%d\n",ans);
	}
	return EXIT_SUCCESS;
}
