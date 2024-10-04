#include <iostream>
#define MAX_QUEUE 5
using namespace std;

struct Queue{
	int elemen[1000];
	int rear;
	int front;
	int jml;
};

void createQ(Queue &q){
	q.front = 0;
	q.rear  = -1;
	q.jml   = 0;
}

bool isEmpty(Queue q){
	return q.jml == 0;
}

bool isFull(Queue q){
	return q.jml == MAX_QUEUE;
}

void enQ(Queue &q, int i){
	if(isFull(q)) return;
	
	q.rear++;
	q.jml++;
	q.elemen[q.rear] = i;
}

void deQ(Queue &q, int &i){
	if(isEmpty(q)) return;
	
	i = q.elemen[q.front];
	q.front++;
	q.jml--;
	
}

int main(){
	Queue q;
	int x;
	createQ(q);
	
	enQ(q, 10);
	enQ(q, 2);
	enQ(q, 3);
	deQ(q, x);
	enQ(q, 15);
	enQ(q, 17);
	enQ(q, 22);
	enQ(q, 25);
	deQ(q, x);
	deQ(q, x);
	enQ(q, 21);
	
	cout << "Isi Queue: ";
	for(int i=q.rear; i>=q.front; i--) cout << q.elemen[i] << " ";
	
	cout <<"\nFront = " << q.front << endl;
	cout <<"Rear = " << q.rear << endl;
	cout <<"Jml Item = " << q.jml << endl;
	cout <<"Item yg dikeluarkan = " << x << endl;
}
