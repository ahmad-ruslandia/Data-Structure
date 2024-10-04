#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
    int data;

    Node* link;
};

Node* top = NULL;

bool isempty()
{
    if (top == NULL)
        return true; else
        return false;
}

void push(int databaru)
{
    Node* n = new Node();
    n->data = databaru;
    n->link = top;
    top = n;
}

void pop()
{
    if (isempty())
        cout << " Stack Kosong \n";
    else
    {
        Node* x = top;
        top = top->link;
        delete(x);
    }
    cout << " Data top telah dihapus \n";

}

void tampiltop()
{
    if (isempty())
        cout << " Stack Kosong \n";
    else
        cout << " Tampilan data top adalah : " << top->data << "\n";
}



int main()
{

    int pilihan, databaru;

    do
    {
        system("cls");
        cout << "\n Menu : \n" << endl;
        cout << " 1. Push" << endl;
        cout << " 2. Pop" << endl;
        cout << " 3. Tampilkan Top" << endl;
        cout << " 4. Keluar" << endl;
        cout << "\n Masukkan Pilihan : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1: system("cls"); {
            cout << " Masukkan Data : ";
            cin >> databaru;
            push(databaru);
            break;
        }
        case 2: system("cls"); {
            pop();
            break;
        }
        case 3: system("cls"); {
            tampiltop();
            break;
        }
        case 4: system("cls"); {
            return 0;
            break;
        }
        default: system("cls");
        {
            cout << " Maaf, Pilihan yang anda pilih tidak tersedia! \n ";
        }

        }
        _getch();
    } while (pilihan != NULL);

    return 0;
}