#include <iostream>
using namespace std;

class Empty{
		};
		class Full{
		};
template <typename T>
class Stack{
	private:
		T *p;
		int num;
		int size;
	public:
		Stack(int _size=10){
			size=_size;
			num=0;
			p=new T[_size];
		}
		~Stack(){
			delete[] p;
		}
		bool isFull(){
			return num==size; 
		}
		bool isEmpty(){
			return num==0;
		}
		T pop(){
			if(num>0){
				return p[num-1];
			}else{
				throw Empty();
			}
		}
		void push(T val){
			if(num!=size){
				p[num]=val;
				num++;
			}else{
				throw Full();
			}
		}
		void delTop(){
			if(num>0){
				num--;
			}else{
				throw Empty();
			}
		}
	
}; 

int main(){
	Stack<int> s(2);
	cout<<s.isEmpty()<<endl;
	s.push(1);
	s.push(2);
	try{
		s.push(3);
	}catch(Full e){
		cout<<"is full"<<endl;
	}
	cout<<s.pop()<<endl;
	s.delTop();
	cout<<s.pop()<<endl;
	s.delTop();
	try{
		cout<<s.pop()<<endl;
		s.delTop();
	}catch(Empty e){
		cout<<"is empty"<<endl;
	}
}
