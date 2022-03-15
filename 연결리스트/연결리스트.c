#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{
	char data[4];
	struct listNode *link;
}listNode;

typedef struct {
	listNode * head;
}linkedList_h;

linkedList_h *createLinkedList_h();
void freeLinkedList_h(linkedList_h* L);
void printList(linkedList_h *L);
void insertFirstNode(linkedList_h *L, char *x);
void insertMiddleNode( linkedList_h *L, listNode *pre, char *x);
void insertLastNode( linkedList_h *L, char *x);
listNode *searchNode(linkedList_h *L, char *x);
int main(){
	linkedList_h * L;
	listNode * p;

	printf("(1) 공백리스트 생성하기! \n");
	L = createLinkedList_h();
	printList( L );
	
	printf("(2) 리스트 처음에 [수]노드 삽입하기! \n");
	insertFirstNode( L, "수");
	printList( L );
	
	printf("(3) 리스트 마지막에 [금]노드 삽입하기! \n");
	insertLastNode( L, "금");
	printList( L );
	
	printf("(4) 리스트 첫 번째에 [월]노드 삽입하기! \n");
	insertFirstNode( L, "월");
	printList( L );
	
	printf("(5) 리스트에서 [수] 노드를 찾아 그 뒤에 [목] 삽입하기! \n");
	p = searchNode( L, "수");
	if( p == NULL ) printf("찾는 데이터가 없습니다.\n");
	else 	insertMiddleNode( L, p, "목");
	printList( L );
	
	printf("(6) 리스트 공간을 해제하여 공백 리스트로 만들기! \n");
	freeLinkedList_h(L);
	printList( L );
	return 0;
}

linkedList_h *createLinkedList_h(){
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L -> head = NULL;
	return L;
}

void freeLinkedList_h(linkedList_h* L){
	listNode* p;
	while (L -> head != NULL) {
		p = L -> head;
		L -> head = L -> head -> link;
		free(p);
		p = NULL;
	}
}

void printList(linkedList_h *L){
	listNode* p;
	printf ("L = (");
	p = L -> head;
	while (p != NULL) {
		printf ("%s", p -> data);
		p = p -> link;
		if (p != NULL) printf (", ");
	}
	printf (") \n");
}

void insertFirstNode(linkedList_h *L, char *x){
	listNode* newnode;
	newnode = (listNode*)malloc(sizeof(listNode));
	strcpy(newnode -> data, x);
	newnode -> link = L -> head;
	L -> head = newnode;
}

void insertMiddleNode( linkedList_h *L, listNode *pre, char *x){
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode -> data, x);
	if (L->head == NULL) {
		newNode -> link = NULL;
		L -> head = newNode;
	}
	else if (pre == NULL) {
		L -> head = newNode;
	}
	else {
		newNode -> link = pre -> link;
		pre -> link = newNode;
	}
}

void insertLastNode( linkedList_h *L, char *x){
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
  newNode -> link = NULL;
	strcpy(newNode -> data, x);
	if (L -> head == NULL) {
		L -> head = newNode;
		return;
	}
	
	temp = L -> head;
	while (temp -> link != NULL) temp = temp -> link;
	temp -> link = newNode;
}	

listNode *searchNode(linkedList_h *L, char *x){
	listNode *temp;
	temp = L -> head;
	while (temp != NULL) {
		if (strcmp(temp -> data, x) == 0) return temp;
		else temp = temp -> link;
	}
	return temp;
}