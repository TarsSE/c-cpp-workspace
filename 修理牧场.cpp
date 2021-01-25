#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int n,tempLen,a,b,result=0;
	scanf("%d",&n);
	priority_queue<int,vector<int>,greater<int> > stick;
	for(int i=0;i<n;i++){
		scanf("%d",&tempLen);
		stick.push(tempLen);
	}
	while(stick.size()>1){
		a=stick.top();
		stick.pop();
		b=stick.top();
		stick.pop();
		a=a+b;
		stick.push(a);
		result+=a;
	}
	printf("%d",result);
}
