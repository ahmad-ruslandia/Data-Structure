#include <iostream>
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
	if (root==NULL)
		root = createNode(data);
	else if (data <= root->data)
		insert(root->left, data);
	else if (data > root->data)
		insert(root->right, data);
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

bool cari(Node *root, int data){
	if (root==NULL)
		return false;
	else if(data < root->data)
		return cari(root->left, data);
	else if(data > root->data)
		return cari(root->right, data);
	else
		return true;
}

Node *cariMin(Node *root){
	if (root==NULL)
		return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

void hapus(Node *&root, int data){
	if (root==NULL)
		return;
	else if(data < root->data)
		return hapus(root->left, data);
	else if(data > root->data)
		return hapus(root->right, data);
	else{
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

int main(){
	insert(root, 50);
	insert(root, 35);
	insert(root, 70);
	insert(root, 29);
	insert(root, 49);
	insert(root, 60);
	insert(root, 72);
	insert(root, 27);
	insert(root, 30);
	insert(root, 50);
	
	hapus(root, 50);
	
	cout << "Level order   : "; levelOrder(); cout << "\n";
	cout << "Preorder      : "; preOrder(root); cout << "\n";
	cout << "Inorder       : "; inOrder(root); cout << "\n";
	cout << "Inorder (Desc): "; inOrderDesc(root); cout << "\n";
	cout << "Postorder     : "; postOrder(root); cout << "\n";
	
}

