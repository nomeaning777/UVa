#include <cstdio>
#include <iostream>
using namespace std;
char inputs[10000000];
const int EMPTY=123456;
const int OK=222223;
class Main{
  public:
    char *it;
    int expr(int now,int target,int depth=0){
      if(*(it+1)==')'){
        it++;it++;
        return EMPTY; // EmptyTree
      }else{
        it++;
        int val=sum();
        int ans=false;
        int l1=expr(now+val,target,depth+1);
        int l2=expr(now+val,target,depth+1);
        if(now + val == target && l1+l2 == EMPTY * 2){
          ans = OK;
        }
        if(l1 == OK || l2 == OK)ans = OK;
        it++;
        return ans;
      }
    }
    void program(){
      while(*it=='-'||isdigit(*it)){
        int s = sum();
        if(expr(0,s)==OK){
          puts("yes");
        }else{
          puts("no");
        }
      }
    }
    int sum(){
      int sign=1;
      while(*it=='-'){
        it++;
        sign*=-1;
      }
      int ret=0;
      while(isdigit(*it)){
        ret=ret*10+*it-'0';
        it++;
      }
      return ret*sign;
    }
    Main(){
      it=inputs;
      program();
    }
};
int main() {
  char *in=inputs;
  while(true){
    int tmp=getchar();
    if(tmp==EOF)break;
    if(isdigit(tmp)||tmp=='('||tmp==')'||tmp=='-')
      *(in++)=tmp;
  }
  Main();
  return 0;
}
