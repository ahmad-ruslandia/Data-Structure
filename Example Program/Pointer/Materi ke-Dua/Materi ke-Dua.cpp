#include <iostream>
using namespace std;

void tukar(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	
}

int main(){
	int a, b;
	
	a = 1;
	b = 2;
	
	tukar(a,b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	
}
