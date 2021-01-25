#include <iostream>
#include <map>
using namespace std;

//struct Person{
//	long long phone;
//	int times;
//	bool operator<(const Person& right)const{
//		if(times<right.times){
//			return true;
//		}else{
//			return false;
//		}
//	}
//};

int main(){
	int n;
	cin>>n;
	long long tempTel,resultTel;
	int resultTimes=0,num=0;
	map<long long,int> people;
	map<long long,int>::iterator it;
	for(int i=0;i<2*n;i++){
		cin>>tempTel;
		it=people.find(tempTel);
		if(it!=people.end()){
			people[tempTel]++;
			if(people[tempTel]>resultTimes){
				resultTel=tempTel;
				resultTimes=people[tempTel];
				num=1;
			}else if(people[tempTel]==resultTimes&&tempTel<resultTel){
				resultTel=tempTel;
				resultTimes=people[tempTel];
				num++;
			}
		}else{
			people.insert(make_pair(tempTel,1));
			if(1>resultTimes){
				resultTel=tempTel;
				resultTimes=1;
				num=1;
			}else if(1==resultTimes&&tempTel<resultTel){
				resultTel=tempTel;
				resultTimes=1;
				num++;
			}
		}
	}
	if(num==1)
	cout<<resultTel<<' '<<resultTimes; 
	else
	cout<<resultTel<<' '<<resultTimes<<' '<<num;
}
