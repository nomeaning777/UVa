#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long lli;
set<lli> ss;
void solve(){
	priority_queue<lli,vector<lli>,greater<lli> > que;
	que.push(1);
	int rank=0;
	while(!que.empty()){
		rank++;
		lli now=que.top();que.pop();
		if(ss.count(now*2)==0){
			que.push(now*2);
			ss.insert(now*2);
		}
		if(ss.count(now*3)==0){
			que.push(now*3);
			ss.insert(now*3);
		}
		if(ss.count(now*5)==0){
			que.push(now*5);
			ss.insert(now*5);
		}
		if(rank==1500){
			cout<<"The 1500'th ugly number is "<<now<<"."<<endl;
			break;
		}
	}
}
int main() {
	solve();
	return 0;
}
