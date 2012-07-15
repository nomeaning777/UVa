#include <iostream>
using namespace std;
const int MAX_N=1000011;
typedef long long lli;
#define REP(i,x)for(int i=0;i<(int)x;i++)
lli dp[MAX_N][4];
int main() {
	dp[0][0]=1;
	REP(i,MAX_N){
		REP(j,3){
			if(i+3-j<MAX_N){
				dp[i+3-j][j]+=dp[i][j];
				dp[i+3-j][j+1]+=dp[i][j];
			}

		}
	}
	int n;
	int tc=1;
	while(cin>>n,n){
		cout<<"Case "<<tc++<<": "<<dp[n][3]<<endl;
	}
	return 0;
}
