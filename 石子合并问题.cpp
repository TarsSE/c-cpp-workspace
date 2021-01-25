#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,rockNum,pay=0,afterOp;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > rock;
	for(int i=0;i<n;i++){
		cin>>rockNum;
		rock.push(rockNum);
	}
	while(rock.size()!=1){
		afterOp=0;
		afterOp+=rock.top();
		rock.pop();
		afterOp+=rock.top();
		rock.pop();
		pay+=afterOp;
		rock.push(afterOp);
	}
	cout<<pay;
}
