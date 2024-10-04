#include <iostream>
using namespace std;

int main(){
	int a, b, *c;
	
	a = 1;
	b = 2;
	
	c = &a;
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << *c << endl;
	
}
