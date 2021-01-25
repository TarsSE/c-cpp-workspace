#include <iostream>
  using namespace std;  
  class Base { protected:   int bi; public:   Base() {    bi=10;  }   ~Base() {     cout<<bi<<' ';   } }; class Base1:virtual public Base { public:   Base1() {    bi+=6;  }   ~Base1() {     cout<<bi<<' ';   } }; class Base2:virtual public Base { public:   Base2() {    bi+=8;  }   ~Base2() {     cout<<bi<<' ';   } }; class Derived:public Base2, public Base1 { public:   Derived() {  }   ~Derived() {     cout<<bi<<' '<<Base::bi<<' '<<Base1::bi<<' '<<Base2::bi<<' ';   } }; 
 
int main() {   Derived dObj;   return 0; }
