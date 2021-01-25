#include <iostream>
using namespace std;

class Vehicle{
	protected:
		string type,name,color;
		double fuelVol,fuelRate;
	public:
		virtual void showMsg(){
			cout<<"type:"<<type<<" "
			<<"name:"<<name<<" "
			<<"color:"<<color<<" "
			<<"fuel volumn"<<fuelVol<<" "
			<<"fuel rate"<<fuelRate<<endl;
		}
		virtual double getVol()=0;
};

class Car:public Vehicle{
	private:
		int peopleNum;
	public:
	Car(string s,double d,int n){
		type=s;
		name=s;
		color=s;
		fuelVol=d;
		fuelRate=d;
		peopleNum=n;
	}
	virtual void showMsg(){
			cout<<"name:"<<name<<" "
			<<"color:"<<color<<" "
			<<"fuel volumn"<<fuelVol<<" "
			<<"fuel rate"<<fuelRate<<" "
			<<"people number"<<peopleNum<<endl;
		} 
	virtual double getVol(){
		return fuelVol;
	}
};

class Truck:public Vehicle{
	private:
		double carryNum;
	public:
		Truck(string s,double d){
		type=s;
		name=s;
		color=s;
		fuelVol=d;
		fuelRate=d;
		carryNum=d;
	}
		virtual void showMsg(){
			cout<<"name:"<<name<<" "
			<<"color:"<<color<<" "
			<<"fuel volumn"<<fuelVol<<" "
			<<"fuel rate"<<fuelRate<<" "
			<<"carry Number"<<carryNum<<endl;
		} 
		virtual double getVol(){
		return fuelVol;
	}
};

int main(){
	Vehicle *pb;
	Car car("da",2.3,4);
	Truck truck("ds",3);
	pb=&car;
	pb->showMsg();
	cout<<(pb->getVol());
	pb=&truck;
	pb->showMsg();
	cout<<(pb->getVol());
}
