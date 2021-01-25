#include <iostream>
#include <string.h>
using namespace std;

class String{
	private:
		char *head;
		int lenth;
		int strLen;
	public:
		String(int _lenth=100);
		String(const String& s);
		~String();
		int getStrLen(){
			return strLen;
		}
		friend ostream& operator<<(ostream& o,const String s){
			o<<s.head;
			return o;
		} 
		friend istream& operator>>(istream& i,String &s);
		String operator+(const String &s);
		String& operator+=(const String &s);
		String& operator=(const String &s);
		bool operator>(const String &s);
		bool operator<(const String &s);
		bool operator==(const String &s);
		bool operator>=(const String &s);
		bool operator<=(const String &s);
		bool operator!=(const String &s);
		char& operator[](int num);
};

String::String(int _lenth){
	head=new char[_lenth];
	lenth=_lenth;
	strLen=0;
}
String::String(const String& s){
	head=new char[s.lenth];
	char *p=s.head;
	lenth=s.lenth;
	strLen=s.strLen;
	for(int i=0;i<lenth;i++){
		head[i]=p[i];
	}
}
String::~String(){
	delete[] head;
}
istream& operator>>(istream& in,String &s){
	const int l=s.lenth;
	char temp[l],*p=s.head;
	in>>temp;
	int i;
	for(i=0;i<strlen(temp);i++){
		p[i]=temp[i];
	}
	p[i]='\0';
	return in;
}
String String::operator+(const String &s){
	String temp(lenth+s.lenth);
	char *pt=temp.head,*p=head;
	int i;
	for(i=0;i<strLen;i++){
		pt[i]=p[i];
	}
	p=s.head;
	for(;i<strLen+s.strLen;i++){
		pt[i]=p[i-strLen-1];
	}
	pt[i]='\0';
	return temp;
}
String& String::operator+=(const String& s){
	*this=*this+s;
	return *this;
}
String& String::operator=(const String& s){
	head=new char[s.lenth];
	char *p=s.head;
	lenth=s.lenth;
	strLen=s.strLen;
	for(int i=0;i<lenth;i++){
		head[i]=p[i];
	}
	return *this;
}
bool String::operator==(const String& s){
	return strcmp(head,s.head)==0;
}
bool String::operator>(const String& s){
	return strcmp(head,s.head)==1;
} 
bool String::operator<(const String& s){
	return strcmp(head,s.head)==-1;
} 
bool String::operator>=(const String& s){
	return *this==s||*this>s;
} 
bool String::operator<=(const String& s){
	return *this==s||*this<s;
} 
bool String::operator!=(const String& s){
	return !(*this==s);
} 
char& String::operator[](int num){
	if(num<0||num>strLen+1){
		return head[0];
	}else{
		return head[num];
	}
}
int main(){
	String s;
	cin>>s;
	cout<<s;
}
 
