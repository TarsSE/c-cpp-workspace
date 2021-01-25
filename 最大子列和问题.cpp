#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,preMax=0,max=0,curSum=0,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(preMax>0){
			preMax+=temp;
		}else{
			preMax=temp;
		}
		if(preMax>max){
			max=preMax;
		}
	}
	printf("%d",max);
}
