#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

Node* createNode(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode ->data = value;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}

void insertHead(Node** head, int value){
	Node* newNode = createNode(value);
	newNode->next = *head;
	if(*head !=NULL){
		(*head)->prev = newNode;
	} 
	*head = newNode;
}

void insertLast(Node** head, int value){
	Node* newNode = createNode(value);
	Node* temp = *head;
	if(temp ==NULL){
		*head = newNode;
		return;
	}
	
	while(temp->next != NULL){
		temp = temp->next;
		
	}
	temp->next = newNode;
	newNode->prev = temp;
}

void insertAtPosition(Node** head,int position,int value){
	Node * newNode = createNode(value);
	Node* temp = *head;
	
	if(position == 0){
		*head = newNode;
		return;
	}
	int index = 0;
	while(temp->next != NULL && index <position-1){
		temp = temp->next;
		index++;
	}
	if(temp == NULL){
		printf("Qua");
		return;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	if(temp->next !=newNode){
		temp->next->prev = newNode;
		
	}
	temp->next = newNode;
}

void printList(Node* head){
	Node *temp = head;
	printf("NULL");
	
	while(temp !=NULL){
		printf("<-- -->%d",temp->data);
		temp = temp->next;
	}
	printf("<-- -->NULL\n");
}

void reverseList(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("NULL");
    while (temp != NULL) {
        printf(" <-- --> %d", temp->data);
        temp = temp->prev;
    }
    printf(" <-- --> NULL\n");
}

int main(){
	int value;
	int pos;
	Node* head = NULL;
	printf("Cac gia tri trong danh sach (nhap -1 de ket thuc):\n");
    while (1) {
        printf("Nhap gia tri: ");
        scanf("%d", &value);
        if (value == -1) break;
        insertLast(&head, value);
    }
	printList(head);
	printf("Danh sach da dao nguoc\n");
	reverseList(head);
	return 0;
}
