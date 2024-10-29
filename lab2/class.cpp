#include <iostream>

using namespace std;

class myClass{
    public:
        void myMethod();
};

void myClass::myMethod(){
    cout << "Hello World";
}
int main(){
    myClass objad;
    objad.myMethod();

}