#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
#define REP(i,x)for(int i=0;i<(int)x;i++)
int k, n;
typedef vector<int> Array;

bool comp(Array &a,Array &b){
	REP(i,a.size()){
		if(a[i]<=b[i])return false;
	}
	return true;
}
int main(void) {
	while(cin>>k>>n){
		Array in[k];

		vector<int> ord(k);
		REP(i,k){
			ord[i]=i;
			in[i]=Array(n);
			REP(j,n){
				cin>>in[i][j];
			}
			sort(in[i].begin(),in[i].end());
		}
		REP(i,k){
			REP(j,k-1){
				if(in[j]>in[j+1]){
					swap(in[j],in[j+1]);
					swap(ord[j],ord[j+1]);
				}
			}
		}
		vector<Array> dp=vector<Array>(k+1);
		REP(i,k){
			dp[i].push_back(ord[i]+1);
		}
		REP(i,k){
			for(int j=i+1;j<k;j++){
				if(comp(in[j],in[i])){
					Array next=dp[i];
					next.push_back(ord[j]+1);
					if(dp[j].size()<next.size()){
						dp[j]=next;
					}else if(dp[j].size()==next.size()){
						dp[j]=min(dp[j],next);
					}
				}
			}
		}
		Array res;
		REP(i,k){
			if(dp[i].size()>res.size()){
				res=dp[i];
			}else if(dp[i].size()==res.size()){
				res=min(res,dp[i]);
			}
		}
		cout<<res.size()<<endl<<res[0];
		REP(i,res.size()-1){
			cout<<" "<<res[i+1];
		}
		cout<<endl;
	}
	return 0;
}
