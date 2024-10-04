#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

void buatNodeBaru(int i){
	n = new Node;
	n->data = i;
	tail = n;
	head = n;
	tail->next = NULL;
}

void tambahDiBelakang(int i){
	n = new Node;
	n->data = i;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void tambahDiDepan(int i){
	n = new Node;
	n->data = i;
	n->next = head;
	head = n;
}

void tambahDiTengah(int i, int j){
	x = head;
	while(x->data != j) x=x->next;
	n = new Node;
	n->data = i;
	n->next = x->next;
	x->next = n;
}

void hapusDiDepan(){
	x = head;
	head = head->next;
	delete(x);
	x = NULL;
}

void hapusDiBelakang(){
	x = head;
	while(x->next != tail) x = x->next;
	tail = x;
	delete(x->next);
	tail->next = NULL;
}

void hapusDiTengah(int i){
	Node *temp=NULL;
	x = head;
	while(x->data !=i){
		temp = x;
		x = x->next;
	}
	temp->next = x->next;
	delete(x);
}

void tampilData(){
	x = head;
	while(x != NULL){
		cout << x->data << " ";
		x = x->next;
	}
}
int main(){
	
	buatNodeBaru(100);
	tambahDiBelakang(200);
	tambahDiBelakang(300);
	tambahDiBelakang(400);
	tambahDiDepan(500);
	tambahDiDepan(600);
	tambahDiTengah(700, 200);
	hapusDiDepan();
	hapusDiBelakang();
	hapusDiTengah(100);

	tampilData();
}
