#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hushValue(const string& str,const int BASE);
int power(int base,const int &up);

int main(){
	int n,m,k,result=0,subNum,value;
	cin>>n>>m>>k;
	string all,temp;
	cin>>all;
	int hushTableSize=power(m,k);
	vector<bool> hushTable(hushTableSize,false);
	subNum=n-k+1;
	for(int i=0;i<subNum;i++){
		temp=all.substr(i,k);
		value=hushValue(temp,m);
//		cout<<value<<'\n';
		if(!hushTable[value]){
			result++;
			hushTable[value]=true;
		}
	}
	cout<<result;
}

int hushValue(const string& str,const int BASE){
	int ret=0,size=str.size();
	for(int i=0;i<size;i++){
		ret=ret*BASE+str[i]-'a';
	}
	return ret;
}
int power(int base,const int &up){
	int ret=1;
	for(int i=0;i<up;i++){
		ret*=base;
	}
//	cout<<base;
	return ret;
}
