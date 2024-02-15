#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
	
{
	struct node  *temp = NULL;
	temp = head;
	int i = 0;
	while (temp != NULL){
		temp = temp ->next;
		i++;

	}
	return i;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int i = 0 ;
	struct node *temp1 = NULL;
	char *temp = (char*)malloc((length(head)+1)*sizeof(char));
	temp1 = head;
	//int i = length;
	while ( temp1 != NULL){
		temp[i] =temp1-> letter;
		temp1 = temp1 -> next;
		i++;
	}
	temp[i+1] = '\0';
	return temp;

}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node *tempnode = (node*)malloc(sizeof(node));
	tempnode->letter =c;
	tempnode -> next = NULL;
	if(*pHead == NULL){
		*pHead = tempnode;
	}

	else{
		node * tempnode2 = *pHead;
		while(tempnode2->next != NULL){
			tempnode2 =tempnode2->next;
		}
		tempnode2-> next = tempnode;

	}


}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* tmp = *pHead;
    while (tmp != NULL) {
        *pHead = tmp->next;
        free(tmp);
        tmp = *pHead;
    }
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}