#include <iostream>
#include <queue>
using namespace std;

struct Student{
	int masterLevel,number;
	Student(int _level,int _number):masterLevel(_level),number(_number){}
	bool operator>(const Student& right)const{//实现>的功能 
		if(masterLevel>right.masterLevel){
			return true;
		}else if(masterLevel==right.masterLevel){
			if(number>right.number){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}
	Student& operator=(const Student &right){
		masterLevel=right.masterLevel;
		number=right.number;
		return *this;
	}
};

int main(){
	int studentNum,tempLevel,helpNum,advanceNum;
	Student tempStudent(0,0);
	cin>>studentNum;
	priority_queue<Student,vector<Student>,greater<Student> > student;
	for(int i=1;i<=studentNum;i++){
		cin>>tempLevel;
		tempStudent.masterLevel=tempLevel;
		tempStudent.number=i;
		student.push(tempStudent);
	}
	cin>>helpNum;
	for(int i=0;i<helpNum;i++){
		cin>>advanceNum;
		tempStudent=student.top();
		student.pop();
		tempStudent.masterLevel+=advanceNum;
		student.push(tempStudent);
//		for(int i=0;i<studentNum;i++){
//			tempStudent=student.top();
//			student.pop();
//			cout<<tempStudent.masterLevel<<' '<<tempStudent.number<<'\n';
//		}
	}
	cout<<student.top().number<<' '<<student.top().masterLevel;
}
