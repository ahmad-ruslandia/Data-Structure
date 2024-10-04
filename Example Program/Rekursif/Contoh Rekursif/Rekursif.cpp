#include <iostream>
using namespace std;

int bilangan_berpangkat(int a, int b){
	int hasil = a;
	
//Looping
	for(int i = 1; i < b; i++){
		hasil = hasil * a;
	}
     
	return hasil;
}

int main(){
	int a;
	int b;

cout << "Angka : ";
cin >> a;
cout << "Pangkat : ";
cin >> b;

cout << "Hasil : "  << bilangan_berpangkat(a,b) << endl;
	
	cin.get();

	return 0;
}
