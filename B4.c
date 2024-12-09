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

int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
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

	value = countNodes(head);
	printf("So phan tu trong lien ket: %d",value);
	return 0;
}
