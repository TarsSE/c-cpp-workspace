#include <iostream>
using namespace std;

int maxFac(int a,int b);
class Rational{
	private:
		int up,down;
	public:
		Rational(int _up=1,int _down=1){
			up=_up/maxFac(_up,_down);
			down=_down/maxFac(_up,_down);
		}
		void show(){
			cout<<(double)up/down;
		}
		Rational operator+(const Rational& r){
			int _up,_down;
			_up=up*r.down+down*r.up;
			_down=down*r.down;
			return Rational(_up,_down);
		}
		Rational operator-(const Rational& r){
			int _up,_down;
			_up=up*r.down-r.up*down;
			_down=down*r.down;
			return Rational(_up,_down);
		}
		Rational operator*(const Rational& r){
			return Rational(up*r.up,down*r.down);
		}
		Rational operator/(const Rational& r){
			return Rational(up*r.down,down*r.up);
		}
		Rational& operator+=(const Rational& r){
			*this=*this+r;
			return *this;
		}
		Rational& operator-=(const Rational& r){
			*this=*this-r;
			return *this;
		}
		Rational& operator*=(const Rational& r){
			*this=*this*r;
			return *this;
		}
		Rational& operator/=(const Rational& r){
			*this=*this/r;
			return *this;
		}
		bool operator>(const Rational& r){
			return up*(r.down)>r.up*down;
		}
		bool operator==(const Rational& r){
			return up==r.up&&down==r.down;
		}
		bool operator!=(const Rational& r){
			return !(*this==r);
		}
		bool operator<(const Rational& r){
			return !(*this>r)&&!(*this==r);
		}
		bool operator>=(const Rational& r){
			return *this>r||*this==r;
		}
		bool operator<=(const Rational& r){
			return *this<r||*this==r;
		}
		friend ostream& operator<<(ostream& o,const Rational& r){
			o<<r.up<<'/'<<r.down;
		}
};

int main(){
	Rational r1(3,4),r2(5,6);
	cout<<r1+r2<<endl
		<<r1-r2<<endl
		<<r1*r2<<endl
		<<r1/r2<<endl;
}

int maxFac(int a,int b){
	if(a<b){
		int temp=a;
		a=b;
		b=temp;
	}
	int c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

