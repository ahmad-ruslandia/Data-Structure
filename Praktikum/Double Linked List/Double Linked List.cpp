#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};
	
	Node *head=NULL, *tail=NULL, *x=NULL, *acuan=NULL;

int isEmpty() {
    if (tail == NULL)return 1;
    else return 0;
}


//Buat Node Awal
void buatNodeAwal(int i){
    if (isEmpty() == 0)
    {
        cout << "\nNode awal telah terisi" << endl;
    }
    else {
    	Node* awal;
		awal = new Node;
		awal->data = i;
		awal->prev = NULL;
		head = awal;
		tail = awal;
		tail->next = NULL;
		cout << "\nNode awal berhasil di buat" << endl;
	}
}


//Tambah Node
void tambahDepan(int i)
{
	if (isEmpty() == 0)
    {
		Node* depan;
		depan = new Node;
		depan->data = i;
		depan->next = head;
		head->prev = depan;
		depan->prev = NULL;
		head = depan;
		cout << "\nAngka telah di input pada node depan";
	}
    else {
		cout << "\nSilahkan buat node awal terlebih dahulu" << endl;
	}
}	

void tambahBelakang(int i){
	if (isEmpty() == 0)
    {
		Node* belakang;
		belakang = new Node;
		belakang->data = i;
		belakang->prev = tail;
		tail->next = belakang;
		tail = belakang;
		tail->next = NULL;
		cout << "\nAngka telah di input pada node belakang";
	}
    else {
		cout << "\nSilahkan buat node awal terlebih dahulu" << endl;
	}
}

int j;
void tambahTengah(int i, int j){
	if (isEmpty() == 0)
    {
		Node* tengah;
		acuan = head;
		int nomor = 1;
    	while (nomor < j - 1) {
        	acuan = acuan->next;
        	nomor++;
    	}
			tengah = new Node;
			tengah->data = i;
			tengah->next = acuan->next;
			acuan->next = tengah;
			tengah->prev = acuan;
			acuan = tengah->next;
			acuan->prev = tengah;
			cout << "\nAngka telah di input pada node tengah";
	}
    else {
		cout << "\nSilahkan buat node awal terlebih dahulu" << endl;
	}
}


//Hapus Node
void hapusDepan(){
	if (isEmpty() == 0)
    {
    	if (head != tail)
        {
	x = head;
	head = x->next;
	head->prev = NULL;
	delete(x);
	x = NULL;
			cout << "\nNode depan telah di hapus" << endl;
		}
		else {
            cout << "\nNode telah di hapus" << endl;
            head = tail = NULL;
   		}
	}
	else {
        cout << "\nMasih kosong ";
    }
}

void hapusBelakang(){
	if (isEmpty() == 0)
    {
    	if (head != tail)
        {
	x = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete(x);
	x = NULL;
			cout << "\nNode belakang telah di hapus" << endl;
		}
		else {
            cout << "\nNode telah di hapus" << endl;
            head = tail = NULL;
   		}
	}
	else {
        cout << "\nMasih kosong ";
    }
}

void hapusTengah(int j){
	Node* hapus; 
	Node* tengah;
	if (isEmpty() == 0)
    {
    	if (head != tail)
        {
		acuan = head;
 		int nomor = 1;
        	while (nomor < j - 1) {
            	acuan = acuan->next;
            	nomor++;
        	}
		hapus = acuan->next;
		tengah = hapus->next;
		acuan->next = tengah;
		tengah->prev = acuan;
		delete hapus;
			cout << "\nNode tengah telah di hapus" << endl;
		}
		else {
            cout << "\nNode telah di hapus" << endl;
            head = tail = NULL;
   		}
	}
	else {
        cout << "\nMasih kosong ";
    }

}


//Tampil
void tampilDepan(){
	if (isEmpty() == 0)
    {
		x = head;
		while(x != NULL){
			cout << " " << x->data << " ";
			x = x->next;
		} 
	}
	else {
		cout << "\nMasih kosong \n";	
	}
}

void tampilBelakang(){
	if (isEmpty() == 0)
    {
		x = tail;
		while(x != NULL){
		cout << " " << x->data << " ";
		x = x->prev;
		}
	}
	else {
		cout << "\nMasih kosong \n";	
	}
}


//Main
int main (){

	int pil, pil1, i;
	
	do {
	system("cls"); 
	cout << " " << endl;
	cout << "Menu :" << endl;
	cout << " " << endl;
	cout << "1. Buat Node Awal" << endl;
	cout << "2. Tambah Node" << endl;
	cout << "3. Hapus Node" << endl;
	cout << "4. Tampilkan Node" << endl;
	cout << "5. Keluar" << endl;
	cout << " " << endl;
	cout << "Masukkan Pilihan : ";
	cin >> pil;
	switch (pil)
	{
	case 1 : system("cls"); {
		cout << " " << endl;
		cout << "Masukkan angka untuk mengisi node baru : ";
		cin >> i;
		buatNodeAwal(i);
		break;
	}
	case 2 : system("cls"); {
		cout << " " << endl;
		cout << "Menu :" << endl; 
		cout << " " << endl;
		cout << "1. Tambah Node Depan		" << endl;
		cout << "2. Tambah Node Belakang	" << endl;
		cout << "3. Tambah Node Tengah		" << endl;
		cout << " " << endl;
		cout << "Masukkan Pilihan : ";
		cin >> pil1;
		if (pil1 == 1){
			cout << "\nMasukkan angka untuk mengisi node depan : ";
			cin >> i;
			tambahDepan(i);
		}
		else if (pil1 == 2){
			cout << "\nMasukkan angka untuk mengisi node belakang : ";
			cin >> i;
			tambahBelakang(i);
		}
		else if (pil1 == 3){
			cout << "\nMasukkan angka untuk mengisi node tengah : ";
			cin >> i;
			tambahTengah(i, j);
		}
		else {
			cout << "\nPilihan Tidak Tersedia" << endl;
		}
		break;
	}
	case 3 : system("cls"); {
		cout << " " << endl;
		cout << "Menu :" << endl; 
		cout << " " << endl;
		cout << "1. Hapus Node Depan		" << endl;
		cout << "2. Hapus Node Belakang		" << endl;
		cout << "3. Hapus Node Tengah		" << endl;
		cout << " " << endl;
		cout << "Masukkan Pilihan : ";
		cin >> pil1;
		if (pil1 == 1){
			hapusDepan();
		}
		else if (pil1 == 2){
			hapusBelakang();
		}
		else if (pil1 == 3){
			hapusTengah(j);
		}
		else {
			cout << "\nPilihan Tidak Tersedia" << endl;
		}
		break;
	}
	case 4 : system("cls"); {
		cout << " " << endl;
		cout << "Menu :" << endl; 
		cout << " " << endl;
		cout << "1. Tampilkan Node dari Depan		" << endl;
		cout << "2. Tampilkan Node dari Belakang	" << endl;
		cout << " " << endl;
		cout << "Masukkan Pilihan : ";
		cin >> pil1;
		if (pil1 == 1){
			cout << " " << endl;
			tampilDepan();
		}
		else if (pil1 == 2){
			cout << " " << endl;
			tampilBelakang();
		}
		else {
			cout << " " << endl;
			cout << "Pilihan Tidak Tersedia" << endl;
		}
		break;
	}
	case 5 : system("cls"); {
		exit(0);
		break;
	}
	default: system("cls");
    {
    	cout << "Maaf, Pilihan yang anda pilih tidak tersedia! \n ";
    }
				
	}_getch();
	
	}while (pil !=6);
	
	return 0;
}
