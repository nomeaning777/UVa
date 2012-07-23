#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
#define REP(i,x)for(int i=0;i<(int)x;i++)
typedef long long lli;
lli INF=1LL<<60;
lli in[9];
int no[256];
int main(){
	no['B']=0;
	no['G']=1;
	no['C']=2;
	while(cin>>in[0]){
		REP(i,8)cin>>in[i+1];
		string ansS;
		lli ansI=1000000000;
		string tmp="BCG";
		do{
			lli tans=accumulate(in,in+9,0);
			REP(i,tmp.size()){
				tans-=in[i*3+no[tmp[i]]];
			}
			if(ansI>tans){
				ansI=tans;
				ansS=tmp;
			}
		}while(next_permutation(tmp.begin(),tmp.end()));
		cout<<ansS<<" "<<ansI<<endl;
	}
}
