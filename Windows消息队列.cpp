#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Message{
	string m;
	int order;
	bool operator>(const Message &right)const{
		return order>right.order;
	}
};

int main(){
	int n,order;
	cin>>n;
	priority_queue<Message,vector<Message>,greater<Message> > q;
	string operation,msg;
	Message temp;
	for(int i=0;i<n;i++){
		cin>>operation;
		switch(operation[0]){
			case 'P':
				cin>>msg>>order;
				temp.m=msg;
				temp.order=order;
				q.push(temp);
				break;
			case 'G':
				if(q.empty()){
					cout<<"EMPTY QUEUE!\n";
				}else{
					temp=q.top();
					q.pop();
					cout<<temp.m<<'\n';
				}
				break;
			default:
				break;
				
		}
	}
}
