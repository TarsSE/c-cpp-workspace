#include <iostream>
#include <string>
#include <vector>
using namespace std;

int hushValue(const string &str,const int BASE);
int power(int base,const int &up);
bool isInTable(int value,vector<unsigned short> &table);
unsigned short bitMask(int value);
void insert(int value,vector<unsigned short> &table);

int main(){
	int n,m,k,result=0,subNum,value;
	cin>>n>>m>>k;
	char in1,in2;
	string all,temp;
	cin>>all;
//	cout<<'\n'<<all;
	int hushTableSize=(power(m,k)+15)>>4;
//	cout<<hushTableSize<<' ';
	vector<unsigned short> hushTable(hushTableSize,0);
	subNum=n-k+1;
	for(int i=0;i<subNum;i++){
		temp=all.substr(i,k);
		value=hushValue(temp,m);
		if(!isInTable(value,hushTable)){
			result++;
			insert(value,hushTable);
		}
	}
	cout<<result;
}

int hushValue(const string &str,const int BASE){
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
bool isInTable(int value,vector<unsigned short> &table){
	unsigned short line=table[value>>4];
	return (line&bitMask(value))!=0;
}
unsigned short bitMask(int value){
	return 1<<(value&15);
}
void insert(int value,vector<unsigned short> &table){
	table[value>>4]|=bitMask(value);
}
