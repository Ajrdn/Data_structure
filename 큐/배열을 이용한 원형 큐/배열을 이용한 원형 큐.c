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
	int menu = 1;
	q = createQueue( 5 );
	
	while( menu ){
		printf("1:enQueue, 2:deQueue, 3:printAll... ");
		scanf("%d", &menu);
		switch (menu) {
			case 1 : scanf("%d", &data);
				enQueue( q, data );
				break;
			case 2 : data = deQueue( q );
				if(data )printf("%d\n", data);
				break;
			case 3 : printAll(q);
				break;
			default : break;
		}
	}
	
	destroyQueue( q );
	return 0;
}
QUEUE * createQueue( int n ){
	QUEUE *temp = (QUEUE *) malloc( sizeof(QUEUE) );
	temp -> size = n+1;   // 한 칸을 비워 놓기 위함
	temp -> rear = 0;
	temp -> front = 0;
	temp -> buf = (ELEMENT *)malloc(sizeof(ELEMENT)*temp->size);
	return temp;
}
int isFull( QUEUE *q ){
	return (q -> rear + 1) % q -> size == q -> front;
}
void enQueue( QUEUE *q, ELEMENT data ){
	if( isFull( q ) ) printf("Queue is full\n");
	else {
		q -> rear = (q -> rear + 1) % q -> size;
		q->buf[ q->rear ] = data;
	}
}
int isEmpty( QUEUE *q ){
		return q -> rear == q -> front;
}
ELEMENT deQueue( QUEUE *q ){
	if( isEmpty( q ) ){
		printf("Queue is empty");
		return 0;
	}
	q -> front = (q -> front + 1) % q -> size;
	return q->buf[ q->front ];
}
void destroyQueue( QUEUE * q ){
	free( q->buf );
	free( q );
}
void printAll( QUEUE *q ){
	if( isEmpty(q)) return;
	int i = (q -> front + 1) % q -> size;
	while(1) {
		printf("%d ", q -> buf[i]);
		if (i == q -> rear)
			break;
		i = (i + 1) % q -> size;
	}
	printf("\n");
}