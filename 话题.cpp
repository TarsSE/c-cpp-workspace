#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <ctype.h>
#define SIZE 100
using namespace std;

struct box{
	string base;
	int num;
	bool operator<(box& right){
		return base<right.base;
	}
	box(string _base,int _num){
		base=_base;
		num=_num;
	}
	box(int _num=0){
		num=_num;
	}
};

void toBase(string &origin);//将话题转换为大写字母开头的输出标准格式
int hushValue(string topic);//生成字符串哈希值
vector<string> getTopic(string &origin);//从一行中得到标准格式话题 
bool isInStringVector(string &str,vector<string> vec);
int findBox(string &target,vector<box> &boxList);


int main(){
	int lineNum,tempHush,maxNum=0,p;
	box maxRefered;
	maxRefered.num=0;
	string origin;
	cin>>lineNum;
	vector<vector<box> > hushTable(SIZE);
	vector<string> tempTopics;
	getchar();
	for(int i=0;i<lineNum;i++){
		getline(cin,origin);
		tempTopics=getTopic(origin);
		for(int j=0;j<tempTopics.size();j++){
//			cout<<tempTopics[j]<<' '<<hushValue(tempTopics[j])<<'\n';
			tempHush=hushValue(tempTopics[j]);
			p=findBox(tempTopics[j],hushTable[tempHush]);
			if(p==hushTable[tempHush].size()){
				hushTable[tempHush].push_back(box(tempTopics[j],1));
				maxNum++;
//				cout<<"insert"<<'\n';
				if((hushTable[tempHush])[p].num>maxRefered.num){
//					cout<<"change"<<'\n';
					maxRefered.base=(hushTable[tempHush])[p].base;
					maxRefered.num=(hushTable[tempHush])[p].num;
					
				}else if((hushTable[tempHush])[p].num==maxRefered.num){
					if((hushTable[tempHush])[p].base<maxRefered.base){
						maxRefered.base=(hushTable[tempHush])[p].base;
						maxRefered.num=(hushTable[tempHush])[p].num;
					}
				}
			}else{
				(hushTable[tempHush])[p].num++;
				if((hushTable[tempHush])[p].base==maxRefered.base){
					maxRefered.num++;
				}else if((hushTable[tempHush])[p].num>maxRefered.num){
					maxRefered.base=(hushTable[tempHush])[p].base;
					maxRefered.num=(hushTable[tempHush])[p].num;
				}else if((hushTable[tempHush])[p].num==maxRefered.num){
					if((hushTable[tempHush])[p].base<maxRefered.base){
						maxRefered.base=(hushTable[tempHush])[p].base;
						maxRefered.num=(hushTable[tempHush])[p].num;
					}
				}
			}
		}
	}
	cout<<maxRefered.base<<'\n'
		<<maxRefered.num<<'\n';
	if(maxNum>1)
	cout<<"And "<<maxNum-1<<" more ...";
}

void toBase(string &origin){
	string temp;
	for(int i=0;i<origin.size();i++){
		if(!isalnum(origin[i])){
			origin[i]=' ';
		}
	}
	char pre=' ',cur=0;
	int cnt=0;
	for(int i=0;i<origin.size();i++){
		pre=cur;
		cur=origin[i];
		if(cnt==0&&isalpha(cur)){
			cnt++;
			temp.push_back(toupper(cur));
		}else if(isalnum(cur)||(pre!=' '&&cur==' ')){
			temp.push_back(tolower(cur));
		}
	}
	if(temp[temp.size()-1]==' '){
		origin.clear();
		for(int i=0;i<temp.size()-1;i++){
			origin.push_back(temp[i]);
		}
	}else{
		origin=temp;
	}
} 
vector<string> getTopic(string &origin){
	bool start=false;
	vector<string> ret;
	string temp;
	for(int i=0;i<origin.size();i++){
		if(origin[i]=='#'&&start==false){
			start=true;
			continue;
		}
		if(start==true&&origin[i]=='#'){
			if(!isInStringVector(temp,ret)){
				toBase(temp);
				ret.push_back(temp);
			}
			temp.clear();
			start=false;
			continue;
		}
		if(start==true){
			temp.push_back(origin[i]);
		}
		
	}
	return ret;
}
int hushValue(string origin){
	int ret=0;
	toBase(origin);
	for(int i=0;i<origin.size();i++){
		ret=(ret+origin[i])%SIZE;
	}
	return ret;
}
bool isInStringVector(string &str,vector<string> vec){
	for(int i=0;i<vec.size();i++){
		if(str==vec[i]){
			return true;
		}
	}
	return false;
}
int findBox(string &target,vector<box> &boxList){
	int ret;
	for(ret=0;ret<boxList.size();ret++){
		if(boxList[ret].base==target){
			return ret;
		}
	}
	return ret;
}
