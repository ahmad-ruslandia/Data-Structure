#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

	Node *head=NULL, *tail=NULL, *x=NULL, *acuan=NULL;

int isEmpty() {
    if (tail == NULL)return 1;
    else return 0;
}

//Node Awal
void buatNodeAwal(int i) {
    if (isEmpty() == 0)
    {
        cout << "\nNode awal telah terisi" << endl;
    }
    else {
  	 	Node* awal;
   		awal = new Node;
  		awal->data = i;
    	tail = awal;
    	head = awal;
    	tail->next = NULL;
        cout << "\nNode awal berhasil di buat" << endl;
	}
}


//Tambahkan Node
void tambahDepan(int i)
{
	if (isEmpty() == 0)
    {
       	Node* depan;
    	depan = new Node;
    	depan->data = i;
    	depan->next = NULL;
    	tail->next = NULL;
    	depan->next = head;
    	head = depan;
    
    	cout << "\nAngka telah di input pada node depan";
    }
    else {
		cout << "\nSilahkan buat node awal terlebih dahulu" << endl;
	}

}

void tambahBelakang(int i)
{
	if (isEmpty() == 0)
    {
    Node* belakang;
    belakang = new Node;
    belakang->data = i;
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
void tambahTengah(int i, int j)
{
	if (isEmpty() == 0)
    {	
    Node* tengah;
    tengah = new Node;
    tengah->data = i;
    x = head;
    int nomor = 1;
    while (nomor < j - 1) {
        x = x->next;
        nomor++;
    }
    tengah->next = x->next;
    x->next = tengah;

    cout << "\nAngka telah di input pada node tengah";
	}
	else {
		cout << "\nSilahkan buat node awal terlebih dahulu" << endl;
	}
}


//Tampilkan Node
void tampil() {
  	if (isEmpty() == 0)
    {
 		x = head;
		while(x != NULL){
			cout <<  " "  << x->data << " ";
			x = x->next;
		}
	}
	else {
		cout << "\nMasih kosong";	
	}
}


//Hapus Node
void hapusDepan()
{
	if (isEmpty() == 0)
    {
    	if (head != tail)
        {
			x = head;
			head = head->next;
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

void hapusBelakang()
{
	if (isEmpty() == 0)
    {
    	if (head != tail)
        {
			x = head;
			while(x->next != tail) x = x->next;
			tail = x;
			delete(x->next);
			tail->next = NULL;
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

void hapusTengah(int j)
{
    Node* hapus;
    if (isEmpty() == 0)
    {
        if (head != tail)
        {
            hapus = head;
            x = head;
            int nomor = 1;
            while (nomor < j - 1) {
                x = x->next;
                nomor++;
            }
            hapus = x->next;
            x->next = hapus->next;
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


//Main
int main()
{
    int pil, pil1, i;
    do
    {
        system("cls");
        cout << "\nMenu :\n" << endl;
        cout << "1. Buat Node Awal                 " << endl;
        cout << "2. Tambah Node                    " << endl;
        cout << "3. Tampilkan Node                 " << endl;
        cout << "4. Hapus Node                     " << endl;
        cout << "5. Keluar                         \n" << endl;
        cout << " " << endl;
        cout << "Masukan Pilihan : ";
        cin >> pil;
        switch (pil)
        {
        case 1: system("cls"); {
            cout << "\nMasukkan angka untuk mengisi node baru : ";
            cin >> i;
            buatNodeAwal(i);
            break;
        }
        case 2: system("cls"); {
      		cout << "\nMenu :\n" << endl;
            cout << "1. Tambah Node Depan              " << endl;
            cout << "2. Tambah Node Belakang           " << endl;
            cout << "3. Tambah Node Tengah             \n" << endl;
            cout << " " << endl;
            cout << "Masukan Pilihan : ";
            cin >> pil1;
            if (pil1 == 1) {
              	cout << "\nMasukkan angka untuk mengisi node depan : ";
               	cin >> i;
               	tambahDepan(i);
            }
            else if (pil1 == 2) {
             	cout << "\nMasukkan angka untuk mengisi node belakang : ";
               	cin >> i;
               	tambahBelakang(i);
            }
            else if (pil1 == 3) {
                cout << "\nMasukkan angka untuk mengisi node tengah : ";
               	cin >> i;
               	tambahTengah(i, j);
            }
            else
            {
                cout << "\nPilhan anda tidak tersedia" << endl;
            }
            break;
        }
        case 3: system("cls"); {
            tampil();
            break;
        }
        case 4: system("cls"); {
     		cout << "\nMenu :\n" << endl;
            cout << "1. Hapus Node Depan               " << endl;
            cout << "2. Hapus Node Belakang            " << endl;
            cout << "3. Hapus Node Tengah              \n" << endl;
            cout << " " << endl;
            cout << "Masukan Pilihan : ";
            cin >> pil1;
            if (pil1 == 1) {
                hapusDepan();
            }
            else if (pil1 == 2) {
                hapusBelakang();
            }
            else if (pil1 == 3) {
                hapusTengah(j);
            }
            else
            {
                cout << "\nPilhan anda tidak tersedia" << endl;
            }
            break;
        }
        case 5: system("cls"); {
            exit(0);
            break;
        }
        default: system("cls");
        {
            cout << "\nMaaf, Pilihan yang anda pilih tidak tersedia! \n ";
        }
        }
        _getch();
    } while (pil != 6);
    
    return 0;
}
