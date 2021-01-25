#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <queue>
#include <vector>

using namespace std;

class PCB{
	int runtime;
	int exptime;
	int grade;
	string status;
	public:
	string name;
	void run(){
		cout<<("\n???? "+name+" ????????\n");
		status="R";
		printInfo();
		runtime++;
		grade--;
		status="W";
		if(runtime==exptime){
			status="F";
		}
	}
	void printInfo(){
		printf("\n????????%-10s????%-4s??????????%-5d????CPU???:%-5d??????????:%-5d???????%-5d\n",
		name.c_str(),status.c_str(),exptime,runtime,exptime-runtime,grade);
	}
	bool operator<(const PCB& r)const{
		return grade<r.grade;
	}
	bool isFinished(){
		return status=="F";
	}
	void fill(){
		cout<<"\n??????????????:";
		cin>>this->name;
		this->runtime=0;
		cout<<"\n????????????§Ö????(>0):";
		cin>>this->exptime;
		cout<<"\n??????????????:";
		cin>>this->grade;
		status="W";
	}
};

void printQueueStatus(priority_queue<PCB,vector<PCB>,less<PCB> > &q){
	vector<PCB> t;
	while(!(q.empty())){
		PCB tempPCB=q.top();
		tempPCB.printInfo();
		q.pop();
		t.push_back(tempPCB);
	}
	for(int i=0;i<t.size();i++){
		q.push(t.at(i));
	}
}

int main(){
	priority_queue<PCB,vector<PCB>,less<PCB> > q;
	vector<PCB> theFinished,transportor;
	char next;
	cout<<"????????????????????";
	int pNum;
	cin>>pNum;
	for(int i=0;i<pNum;i++){
		PCB temp;
		cout<<"\n?????No.";
		cout<<i;
		cout<<'\n'; 
		temp.fill();
		q.push(temp);
	}
	int timeCnt=0;
	while(!(q.empty())){
		cout<<"\n??n????\n";
		
		do{
			next=getch();
		}while(next!='n'&&next!='N');
		
		cout<<"\n??§Õ???:";
		cout<<(++timeCnt);
		cout<<"\n";
		
		PCB temp=q.top();
		q.pop();
		temp.run();
		
		cout<<"\n----------------------------?????????????----------------------------\n"; 
		
		printQueueStatus(q);
		
		if(!(temp.isFinished())){
			q.push(temp);
		}else{
			cout<<"\n????????????????"+(temp.name)+"????????\n";
		}
	}
	cout<<"\n????????????,??q???\n";
	char end;
	do{
		end=getch();
	}while(end!='q'&&end!='Q');
}


