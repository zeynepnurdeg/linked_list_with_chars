#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedList_char.h"

node_t* createList(node_t* tp) {
	LType ch;
	node_t* p = NULL;
	printf("Enter a character (or ! to stop): ");
	scanf(" %c", &ch);
	while (ch != '!')
	{
		if (tp == NULL)
		{
			tp = addBeginning(tp, ch);
			p = tp;
		}
		else
		{
			addAfter(p, ch);
			p = p->next;
		}
		printf("Enter a character (or ! to stop): ");
		scanf(" %c", &ch);
	}
	return (tp);
}

int removeChar(node_t* tp, LType* delItem) {
	node_t* p = NULL;
	int found = 0;
	if (tp->data == *delItem)
	{
		tp = deleteFirst(tp, delItem);
		p = tp;
		found = 1;
	}
	else
	{
		p = tp;
		while (p->next != NULL)
		{
			if (p->next->data == *delItem)
			{
				deleteAfter(p, delItem);
				found = 1;
			}
			p = p->next;
		}
	}
	return (found);
}

void displayRec(node_t* tp) {
	if (tp != NULL)
	{
		printf("%c -> ", tp->data);
		displayRec(tp->next);
	}
	else
	{
		printf("NULL\n");
	}
}

int main(void)
{
	node_t* headp = NULL;
	headp = createList(headp);
	printf("\n");
	displayRec(headp);

	char delLet;
	printf("Enter a char to delete: ");
	scanf(" %c", &delLet);

	int found = removeChar(headp, &delLet);
	if (found == 1)
		displayRec(headp);
	else
		printf("The character <%c> is NOT found on the list!!!\n", delLet);

	return 0;
}