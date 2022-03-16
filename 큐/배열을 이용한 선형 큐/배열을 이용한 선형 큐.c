#include <stdio.h>
#include <stdlib.h>
typedef int ELEMENT ;
typedef struct queue{
	ELEMENT * buf;
	int front;
	int rear;
	int size;
}QUEUE;
QUEUE * createQueue( int n );
int isFull( QUEUE *q );
void enQueue( QUEUE *q, ELEMENT data );
int isEmpty( QUEUE *q );
ELEMENT deQueue( QUEUE *q );
void destroyQueue( QUEUE * q );
void printAll( QUEUE *q );
int main() {
	QUEUE *q;
	ELEMENT data;
	
	q = createQueue( 5 );
	enQueue( q, 10 ) ;
	enQueue( q, 20 ) ;
	enQueue( q, 30 ) ;
	enQueue( q, 40 ) ;
	enQueue( q, 50 ) ;
	data = deQueue( q );
	if( data ) printf("%d\n", data );
	enQueue( q, 60 ) ;
	printAll( q );
	destroyQueue( q );
	return 0;
}
QUEUE * createQueue( int n ){
	QUEUE *temp = (QUEUE *) malloc( sizeof(QUEUE) );
	temp -> size = n;
	temp -> rear = -1;
	temp -> front = -1;
	temp -> buf = (ELEMENT *) malloc( sizeof(ELEMENT) * n);
	return temp;
}
int isFull( QUEUE *q ){
	return q -> rear == q -> size - 1;
}
void enQueue( QUEUE *q, ELEMENT data ){
	if (isFull(q)) {
		printf("Queue is full\n");
		return ;
	}
	q -> buf[++(q -> rear)] = data;
}
int isEmpty( QUEUE *q ){
	return q -> rear == q -> front;
}
ELEMENT deQueue( QUEUE *q ){
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return 0;
	}
	return q -> buf[++(q -> front)];
}
void printAll( QUEUE *q ){
	for (int i = ++(q -> front); i <= q -> rear; i++) {
		printf("%d ", q -> buf[i]);
	}
	printf("\n");
}

void destroyQueue( QUEUE * q ){
	free(q -> buf);
	free(q);
}