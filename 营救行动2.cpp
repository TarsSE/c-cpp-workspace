#include <iostream>
#include <vector>
using namespace std;

int getGuardNum(vector<int> &jail,int l,int r);
void addGuard(vector<int> &jail,int l,int r,int num);

int main(){
	int n,m,guardNum=0,l,r;
	char operate;
	cin>>n>>m;
	vector<int> jail(n+1);
	for(int i=1;i<=n;i++){
		cin>>guardNum;
		jail[i]=guardNum;
	}
	for(int i=0;i<m;i++){
		cin>>operate;
		switch(operate){
			case 'Q':
				cin>>l>>r;
				cout<<getGuardNum(jail,l,r)<<endl;
				break;
			case 'C':
				cin>>l>>r>>guardNum;
				addGuard(jail,l,r,guardNum);
				break;
			default:
				break;
		}
	}
} 

int getGuardNum(vector<int> &jail,int l,int r){
	int ret=0;
	for(int i=l;i<=r;i++){
		ret+=jail[i];
	}
	return ret;
}
void addGuard(vector<int> &jail,int l,int r,int num){
	for(int i=l;i<=r;i++){
		jail[i]+=num;
	}
}
