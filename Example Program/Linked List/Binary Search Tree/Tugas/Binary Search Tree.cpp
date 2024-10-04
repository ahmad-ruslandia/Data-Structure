#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *root=NULL, *n=NULL, *temp=NULL;

Node *createNode(int data){
	n = new Node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void insert(Node *&root, int data){
	if (root==NULL){
		cout << "\nData berhasil dimasukkan" << endl;
		root = createNode(data);
	}
	
	else if (data <= root->data){
		insert(root->left, data);
	}
	else if (data > root->data){
		insert(root->right, data);
	}
}

bool cari(Node *root, int data){
	if (root==NULL){
    	cout << "\nData tidak ditemukan" << endl;
		return false;
	}
	else if(data < root->data){
		return cari(root->left, data);
	}
	else if(data > root->data){
		return cari(root->right, data);
	}
	else{
    	cout << "\nData " << root->data << " Ditemukan" << endl;
		return true;
	}
	
}

Node *cariMin(Node *root){
	if (root==NULL)
		return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

void levelOrder(){
	if (root==NULL) return;
	
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		cout << q.front()->data << " ";
		if(q.front()->left != NULL)
			q.push(q.front()->left);
		if(q.front()->right != NULL)
			q.push(q.front()->right);
		q.pop();
	}
}

void preOrder(Node *root){
	if (root==NULL) return;
	
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root){
	if (root==NULL) return;
	
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void inOrderDesc(Node *root){
	if (root==NULL) return;
	inOrderDesc(root->right);
	cout << root->data << " ";
	inOrderDesc(root->left);
}

void postOrder(Node *root){
	if (root==NULL) return;
	
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}


void hapus(Node *&root, int data){
	if (root==NULL){
		cout << "\nData tidak ditemukan" << endl;
		return;
	}
	else if(data < root->data)
		return hapus(root->left, data);
	else if(data > root->data)
		return hapus(root->right, data);
	else{
		cout << "\nData telah terhapus" << endl;
		
		// kasus I
		if (root->left == NULL && root->right == NULL){
			delete(root);
			root=NULL;
		}
		// kasus II
		else if (root->left == NULL){
			temp = root;
			root = root->right;
			delete(temp);
			temp=NULL;
		}
		else if (root->right == NULL){
			temp = root;
			root = root->left;
			delete(temp);
			temp=NULL;
		}
		// kasus III
		else{
			temp = cariMin(root->right);
			root->data = temp->data;
			hapus(root->right, data);
		}
	}
}


int main (){

	int pilihan, pil1, data;
	
	do {
	kembali :
	system("cls");
	cout << "\nMenu :\n" << endl;
	cout << "1. Insert Node				" << endl;
	cout << "2. Cari Data				" << endl;
	cout << "3. Hapus Data				" << endl;
	cout << "4. Binary Tree Transversal	" << endl;
	cout << "5. Keluar					\n" << endl;
	cout << "Masukkan Pilihan : ";
	cin >> pilihan;
	switch (pilihan)
	{
	case 1 : system("cls"); {
		cout << "\nMasukkan angka : ";
		cin >> data;
		insert(root, data);
		break;
	}
	case 2 : system("cls"); {
		cout << "\nMasukkan angka untuk yang akan dicari  : ";
		cin >> data;
		cari(root, data);
		break;	
	}
	case 3 : system("cls"); {
		cout << "\nMasukkan angka untuk yang akan dihapus  : ";
		cin >> data;
		hapus(root, data);
		break;
	}
	case 4 : system("cls"); {
      	cout << "\nTampilkan Binary Transfersal :\n" << endl;
        cout << "1. Level Order              " << endl;
        cout << "2. Pre Order         		 " << endl;
        cout << "3. In Order (ASC)           " << endl;
        cout << "4. In Order (DESC)          " << endl;
        cout << "5. Post Order             	 " << endl;
        cout << "6. Kembali				    \n" << endl;
        cout << "Masukan Pilihan : ";
        cin >> pil1;
        if (pil1 == 1) {
        	cout << "\nLevel Order : ";
            levelOrder();
        }
        else if (pil1 == 2) {
        	cout << "\nPre Order : ";
            preOrder(root);
        }
        else if (pil1 == 3) {
        	cout << "\nIn Order (ASC) : ";
            inOrder(root);
        }
        else if (pil1 == 4) {
        	cout << "\nIn Order (DESC) : ";
            inOrderDesc(root);
        }
        else if (pil1 == 5) {
        	cout << "\nPost Order : ";
            postOrder(root);
        }
        else if (pil1 == 6) {
        	goto kembali;
        }
        else
        {
            cout << "\nPilhan anda tidak tersedia" << endl;
        }
    	break;
	}
	case 5 : system("cls"); {
		exit(0); 
		break;
	}
	default: system("cls"); {
    	cout << "\nMaaf, Pilihan yang anda pilih tidak tersedia! \n " << endl;
    }
				
	}_getch();
	
	}while (pilihan != 5);
	
}
