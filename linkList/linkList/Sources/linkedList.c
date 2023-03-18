#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\linkedList.h"

Status InitList(LinkedList *L) {
	Status init = ERROR;
	(*L)->data = 0;
	(*L)->next = NULL;
	init = SUCCESS;
	return init;
}

Status InsertList(LNode *p, LNode *q) {
	Status insert = ERROR;
	q->next = p->next;
	p->next = q;
	insert = SUCCESS;
	return insert;
}

void DestroyList(LinkedList *L) {
	printf("It will start from the L's position.\n");
	printf("Head node is recommanded");
	LNode *c = *L;
	LNode *n;
	while (c != NULL) {
		n = c->next;
		free(c);
		c = n;
	}
	*L = NULL;
}

Status DeleteList(LNode *p, ElemType* e) {
	Status del = ERROR;
	LNode *next = p->next;
	if (next != NULL) {
		*e = next->data;
		p->next = p->next->next;
		free(next);
		del = SUCCESS;
		return del;
	}
	else { return del; }
}

void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	printf("It will start from the L's position.\n");
	printf("Head node is recommanded");
	LNode* temp = L;
	ElemType e;
	if (L != NULL) {
		while (temp != NULL) {
			e = temp->data;
			visit(e);
			temp = temp->next;
		}
	}
	else {
		printf("Don't input Nullptr!");
	}
}

Status SearchList(LinkedList L, ElemType e) {
	printf("It will start from the L's position.\n");
	printf("Head node is recommanded\n");
	Status search = ERROR;
	while (L != NULL) {
		if (L->data == e) {
			printf("Now L->data is e");
			search = SUCCESS;
			return search;
		}
		else {
			L = L->next;
		}
	}
	printf("Couldn't find e\n");
	return search;
}

Status ReverseList(LinkedList *L) {
	Status rev = ERROR;
	LinkedList previous = NULL;
	LinkedList current = *L;
	LinkedList next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	previous = *L;
	rev = SUCCESS;
	return rev;
}

Status IsLoopList(LinkedList L) {
	Status loop = ERROR;
	LinkedList slow = L;
	LinkedList fast = L;
	while (fast != NULL && fast->next != slow) {
		if (fast->next == NULL) {
			fast = NULL;
		}
		else {
			fast = fast->next->next;
		}
		slow = slow->next;
	}
	if (fast == NULL) {
		printf("Isn't looplist: ERROR\n");
	}
	else {
		printf("LoopList: SUCCESS\n");
		loop = SUCCESS;
	}
	return loop;
}

LNode* ReverseEvenList(LinkedList *L) {
	LinkedList previous = *L;
	LinkedList current = (*L)->next;
	LinkedList next = current->next;

	if (IsLoopList(*L) == SUCCESS) { return *L;//儉桟全燕。。。。。。。}
	while (next != NULL) {
		current->next = next->next;
		next->next = previous->next;
		previous->next = next;

		previous = current;
		current = next;
		next = next->next;
	}
	return *L;
}


LNode* FindMidNode(LinkedList * L) {
	printf("Head node is recommanded\n");
	LinkedList slow = (*L);
	LinkedList fast = (*L);
	while (fast != NULL) {
		if (fast->next == NULL) {
			fast = NULL;
		}
		else {
			fast = fast->next->next;
		}
		slow = slow->next;
	}
	return slow;
}

void main() {
	int c; //Option
	//void (*visit)(ElemType e);
	//visit = &printf;
	printf("1.Create a list\n");
	printf("2.Destroy the recent list\n");
	printf("3.Insert a number in the recent list\n");
	printf("4.Delete a element\n");
	printf("5.Search the element in the list\n");
	printf("6.Reverse list\n");
	printf("7.Whether it is loop list\n");
	printf("8.Reverse the even num in the list\n");
	printf("9.Find the mid node\n");
	printf("\n-----------------\n");
	while (scanf("%d", &c) == 0) {
		printf("Please input number!\n");
	}
	printf("%d", c);
}