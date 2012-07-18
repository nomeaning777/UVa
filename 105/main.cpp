#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> in[10005],out[10005];
bool input(){
  int a,h,b;
  while(cin>>a>>h>>b){
    in[a].push_back(h);
    out[b].push_back(h);
  }
  return true;
}
int main(){
  input();
  multiset<int> ss;
  ss.insert(0);
  int back=0;
  bool start=false;
  for(int i=1;i<10005;i++){
    for(int j=0;j<in[i].size();j++){
      ss.insert(in[i][j]);
    }
    for(int j=0;j<out[i].size();j++){
      ss.erase(ss.find(out[i][j]));
    }
    if(*ss.rbegin()!=back){
      if(start){
        cout<<" ";
      }else{
        start=true;
      }
      cout<<i<<" "<<*ss.rbegin();
      back=*ss.rbegin();
    }
  }
  cout<<endl;
}
