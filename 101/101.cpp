#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,x)for(int i=0;i<(int)x;i++)
int n;
vector<int> st[26];
bool check(int a,int b){
	REP(i,26){
		if(find(st[i].begin(),st[i].end(),a)!=st[i].end() &&
				find(st[i].begin(),st[i].end(),b)!=st[i].end())
			return false;
	}
	return true;
}

pair<int,int> search(int x){
	REP(i,26){
		if(find(st[i].begin(),st[i].end(),x)!=st[i].end()){
			return make_pair(i,find(st[i].begin(),st[i].end(),x)-st[i].begin());
		}
	}
	return make_pair(-1,-1);
}
int main(void) {
	cin>>n;
	REP(i,n){
		st[i].push_back(i);
	}

	string cmd1,cmd2;
	int a,b;
	while(cin>>cmd1,cmd1!="quit"){
		cin>>a>>cmd2>>b;
		if(!check(a,b))continue; // a,bが同じスタックに
		vector<int> mv;
		if(cmd1=="move"){
			// 上を全部壊す
			pair<int,int> p=search(a);
			for(int i=p.second+1;i<(int)st[p.first].size();i++){
				int tar=st[p.first][i];
				st[tar].push_back(tar);
			}
			st[p.first].erase(st[p.first].begin()+p.second,st[p.first].end());
			mv.push_back(a);
		}else{
			// 上を全部残す
			pair<int,int> p=search(a);
			mv.push_back(a);
			for(int i=p.second+1;i<(int)st[p.first].size();i++){
				int tar=st[p.first][i];
				mv.push_back(tar);
			}
			st[p.first].erase(st[p.first].begin()+p.second,st[p.first].end());
		}
		if(cmd2=="onto"){
			// 上を全部壊す
			pair<int,int> p=search(b);
			for(int i=p.second+1;i<(int)st[p.first].size();i++){
				int tar=st[p.first][i];
				st[tar].push_back(tar);
			}
			st[p.first].erase(st[p.first].begin()+p.second+1,st[p.first].end());
			REP(i,mv.size()){
				st[p.first].push_back(mv[i]);
			}
		}else{
			pair<int,int> p=search(b);
			REP(i,mv.size()){
				st[p.first].push_back(mv[i]);
			}
		}
	}
	REP(i,n){
		cout<<""<<i<<":";
		REP(j,st[i].size()){
			cout<<" "<<st[i][j];
		}
		cout<<endl;
	}
	return 0;
}
