#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "..\Headers\linkedList.h"

Status InitList(LinkedList *L) {
	Status init = ERROR;
	(*L)->data = -22002072;
	(*L)->next = NULL;
	input(L);
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
	printf("Head node is recommanded\n");
	LNode *c = *L;
	LNode *n;
	while (c != NULL) {
		n = c->next;
		free(c);
		c = n;
	}
	(*L)->data = -22002072; //A special virtual node
	(*L)->next = NULL;
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
	printf("Head node is recommanded\n");
	LNode* temp = L;
	ElemType e = 0;
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

	if (IsLoopList(*L) == SUCCESS) { return *L;}
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


LNode* FindMidNode(LinkedList *L) {
	LinkedList slow = malloc(sizeof(LNode));
	LinkedList fast = malloc(sizeof(LNode));
	slow = *L;
	fast = *L;
	printf("Head node is recommanded\n");
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

Status input(LinkedList *head) {
	Status i = ERROR;
	char j; //input
	int num = 0;
	printf("# is end and * is quit\n");

	while ((j = getchar()) != '#' && j != '*') {
		if (isdigit(j)) {
			num = j - '0';
		}
		else if (num > 0) {
			if ((*head)->data == -22002072 && (*head)->next == NULL) {
				//Input to Headnode, I direactly change it's num instead of
				//insert a new node(Locating headnode by special num)
				(*head)->data = num;
			}
			else {
				LNode* new_node = malloc(sizeof(LNode));
				if (new_node == NULL) {
					printf("Memory allocation failed,please try again.\n");
					return i;
				}
				new_node->data = num;
				new_node->next = *head;
				*head = new_node;
				num = 0;
			}
		}
		else if (!isspace(j)) {
			if (j == '#' ||j == '*') { break; }
			else {
				printf("ERROR! PLEASE INPUT NUMBER\n");
				input(head);
				return i;
			}
		}
	}	
	if (j == '#') {
		if ((*head)->data == -22002072) {
			printf("Illegal Linkedlist!\nPlease try again!\n\n");
			input(head);
		}
		else {
			i = SUCCESS;
			return i; 
		}
	}
	else if (j == '*') {
		return i;
	}
}

/**
 *  @name        : Status JudgeList(LinkedList head)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node) judge(if it isn't inited truly, judge = ERROR)
 *	@return		 : Status
 *  @notice      : None
 */
Status JudgeList(LinkedList head) {
	Status judge = ERROR;
	if (head->data == -22002072) {
		printf("Illegal Linkedlist!\nPlease create it first!\n\n");
	}
	judge = SUCCESS;
	return judge;
}

void print(ElemType e) {
	printf("%d", e);
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : Gets the DATA of the specified node and save it to a new node
 *	@param		 : L, location
 *	@return		 : LNode*
 *  @notice      : None
 */
LNode* GetDataNode(LinkedList L, int location) {
	LNode* node = malloc(sizeof(LNode));
	for (int i = 0; i < location; i++) {
		node->data = L->next->data;
		node->next = NULL;
		if (node == NULL) {
			printf("ERROR!The num is greater than the linkedlist's length\n");
			printf("Return the last node...\n");
			return node; 
		}
	}
	return node;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : Gets the specified node
 *	@param		 : L, location
 *	@return		 : LNode*
 *  @notice      : None
 */
LNode* GetNode(LinkedList L, int location) {
	LNode* node = malloc(sizeof(LNode));
	for (int i = 0; i < location; i++) {
		node = L->next;
		if (node == NULL) {
			printf("ERROR!The num is greater than the linkedlist's length\n");
			printf("Return the last node...\n");
			return node;
		}
	}
	return node;
}

void main() {
	LinkedList L = malloc(sizeof(LNode));//Create a list
	L->next = NULL;
	char c = '0'; //Option
	int temp = 0,is = 0;
	void (*visit)(ElemType e);
	visit = &printf;
	printf("1.Create and init a list\n");
	printf("2.Destroy the recent list\n");
	printf("3.Insert a number in the recent list\n");
	printf("4.Delete a element\n");
	printf("5.Search the element in the list\n");
	printf("6.Reverse list\n");
	printf("7.Whether it is loop list\n");
	printf("8.Reverse the even num in the list\n");
	printf("9.Find the mid node\n");
	printf("\n-----------------\n");
	printf("Please chose mode(push * to quit):\n");
	while (c != '*') {
		c = getchar();
		is = isdigit(c); //check whether c is num
		if (is != 0) {
			if (c == '1') {
				InitList(&L);
			}

			if (JudgeList(L) != SUCCESS) {
				printf("Illegal/Empty list!\nPlease create it first!\n\n");
				InitList(&L);
			}

			if (c == '2') {
				DestroyList(&L);
			}
			if (c == '3') {
				printf("Input the num behind the linkedlist headnode:\n");
				
				scanf_s("%d", &temp);
				LNode* node = GetNode(L, temp);
				printf("Now input the insertnode's data:\n");
				LNode* insertnode = malloc(sizeof(LNode)); //It'll insert to another node.
				scanf_s("%d", &temp);
				insertnode->data = temp;
				InsertList(node, insertnode);
			}
			if (c == '4') {
				scanf_s("%d", &temp);
				DeleteList(&L, temp);
			}
			if (c == '5') {
				scanf_s("%d", &temp);
				SearchList(L, temp);
			}
			if (c == '6') {
				ReverseList(&L);
			}
			if (c == '7') {
				IsLoopList(L);
			}if (c == '8') {
				ReverseEvenList(&L);
			}if (c == '9') {
				FindMidNode(&L);
			}

		}
		else if (c!='*') { printf("PLEASE INPUT NUMBER(PUSH * TO QUIT)\n"); }
	}

	printf("\n%c\n", c);
	TraverseList(L, print);
}