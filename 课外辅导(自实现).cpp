#include <iostream>
#include <vector>
using namespace std;

struct Student{
	int masterLevel,number;
	Student(int _level=0,int _number=0):masterLevel(_level),number(_number){}
	bool operator<(const Student &right)const{
		if(masterLevel<right.masterLevel){
			return true;
		}else if(masterLevel==right.masterLevel){
			if(number<right.number){
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

struct StudentHeap{
	vector<Student> heap;
	int maxSize,last;
	StudentHeap(int _maxSize){
		heap.resize(_maxSize+1);
		last=0;
		maxSize=_maxSize;
	}
	void insert(const Student &aStudent){
		if(last==maxSize){
			return ;
		}
		int i=++last;
		while(i!=1&&aStudent<heap[i/2]){
			heap[i]=heap[i/2];
			i/=2;
		}
		heap[i]=aStudent;
	}
	Student deleteMin(){
		if(last==0){
			exit(1);
		}
		Student x=heap[1],y=heap[last--];
		int i=1,ci=2;
		while(ci<=last){
			if(heap[ci+1]<heap[ci]){
				ci++;
			}
			if(!(heap[ci]<y)){
				break;
			}
			heap[i]=heap[ci];
			i=ci;
			ci*=2;
		}
		heap[i]=y;
		return x;
	}
};

int main(){
	int studentNum,tempLevel,advanceLevel,helpNum;
	Student tempStudent;
	cin>>studentNum;
	StudentHeap sHeap(studentNum);
	for(int i=1;i<=studentNum;i++){
		cin>>tempStudent.masterLevel;
		tempStudent.number=i;
		sHeap.insert(tempStudent);
	}
	cin>>helpNum;
	for(int i=0;i<helpNum;i++){
		cin>>advanceLevel;
		tempStudent=sHeap.deleteMin();
		tempStudent.masterLevel+=advanceLevel;
		sHeap.insert(tempStudent);
	}
	cout<<(sHeap.heap)[1].number<<' '<<(sHeap.heap)[1].masterLevel;
}
