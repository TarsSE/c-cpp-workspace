#include <iostream>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

struct Complex{
	int a,b;
	int modsqrt;
	Complex(int _a=0,int _b=0):a(_a),b(_b){
		modsqrt=_a*_a+_b*_b;
	}
	bool operator<(const Complex &right)const{
//		return modsqrt<right.modsqrt;
		if(modsqrt<right.modsqrt){
			return true;
		}else if(modsqrt==right.modsqrt){
			if(a<right.a){
				return true;
			}else if(a==right.a){
				if(b<right.b){
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}
};

int itemNum=0,totala=0,totalb=0;
vector<set<Complex> > modHushTable(131);
void pop(int mod);
void value();

void insert(int a,int b);
bool judgeSquareSum(int c);
void deleteItem(int a,int b);


int main(){
	string operation;
	int tempa,tempb,tempMod,num;
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>operation;
		switch (operation[0]){
			case 'i':
				cin>>tempa>>tempb;
				insert(tempa,tempb);
				break;
			case 'd':
				cin>>tempa>>tempb;
				deleteItem(tempa,tempb);
				break; 
			case 'p':
				cin>>tempMod;
				pop(tempMod);
				break;
			case 'v':
				value();
				break;
			default:
				break;	
		}
	}
} 

void insert(int a,int b){
	Complex complex(a,b);
	pair<set<Complex>::iterator,bool> insertResult;
	insertResult=modHushTable[complex.modsqrt%131].insert(complex);
	if(insertResult.second){
		totala+=a;
		totalb+=b;
		itemNum++;
		cout<<"size = "<<itemNum<<'\n';
	}
}
void deleteItem(int a,int b){
	Complex complex(a,b);
	set<Complex>::iterator it;
	int hushValue=complex.modsqrt%131;
	it=modHushTable[hushValue].find(complex);
	if(it!=modHushTable[hushValue].end()){
		modHushTable[hushValue].erase(it);
		totala-=a;
		totalb-=b;
		itemNum--;
		cout<<"size = "<<itemNum<<'\n';
	}
}

void pop(int mod){
	if(mod<0||mod>1415){
		return ;
	}
	int modSqrt=mod*mod;
	if(judgeSquareSum(modSqrt)){
		int hushValue=modSqrt%131;
		set<Complex>::iterator it;
		for(it=modHushTable[hushValue].begin();it!=modHushTable[hushValue].end();it++){
			if((*it).modsqrt==modSqrt){
				while((*it).modsqrt==modSqrt){
					itemNum--;
					totala-=(*it).a;
					totalb-=(*it).b;
					modHushTable[hushValue].erase(it++);
				}
				break;
			}
		}
	}
	cout<<"size = "<<itemNum<<'\n';
}

void value(){
	cout<<"value = "<<totala*totala+totalb*totalb<<'\n';
}

bool judgeSquareSum(int c) {
        long long int left = 0;
        long long int right = sqrt(c) + 1;
        while(left <= right){
            long long int sum = left * left + right *right;
            if (sum < c) {
                left ++;
            } else if (sum > c){
                right --;
            }  else {
                return true;
            }
        }
        return false;
    }

