#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef	struct Node node;
struct Node
{
	int  *data; //数据域
	node *next; //指针域
};

struct List
{
	node *head;
	node *tail;
	unsigned int length;
};

typedef struct List LinkList;

int in_set(LinkList *,int *);
void add(LinkList *, int *);
int main (int argc, char const *argv[])
{
		LinkList *L = calloc(1, sizeof(LinkList*));
		// int i=1;
		// L = memset(L, 0, sizeof(LinkList*));
		int a = 1;
		int b = 1;
		int c = 2;
		int d = 3;
		if (in_set(L, &a))
			add(L, &a);
		if (in_set(L, &b))
			add(L, &b);
		if (in_set(L, &c))
			add(L, &c);
		if (in_set(L, &d))
			add(L, &d);
	return 0;
}
int in_set(LinkList *l,int * n)
{
	// int i;
	node *head = l->head;
	node *first_node = NULL;
	while(head != NULL && (first_node = head->next) != NULL) {
		if(*(first_node->data) == *n)
		{
			printf("已经存在\n");
			return 0;
		}
	}
	
	return 1;
}
void add(LinkList *l, int *data)
{
	node *current_node = NULL;
	current_node = calloc(1, sizeof(node*));
	current_node->data = data;
	if(l->length == 0)
	{
		l->tail->next = current_node;
		l->tail = current_node;
	} else {
		l->head = current_node;
		l->tail = current_node;
	}
	
	l->length++;
	printf(" done\n");
	
}