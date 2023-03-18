#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hnode {
	int client;
	int length;
	char *line;
	struct hnode* next;
} hnode;

hnode *head = NULL, *tail = NULL;

void addAtFront(int client, int length, char *line)
{
	hnode *tmp = (hnode*)malloc(sizeof(hnode));

	tmp->client = client;
	tmp->length = length;
	tmp->line = (char *)malloc((length + 1) * sizeof(char));
	memcpy(tmp->line, line, length);
	if (tail == NULL)
	{
		tmp->next = tmp;
		head = tail = tmp;
	}
	else
	{
		tmp->next = tail->next;
		head = tail->next = tmp;
	}
}

void addAtLast(int client, int length, char *line)
{
	hnode *tmp = (hnode *)malloc(sizeof(hnode));

	tmp->client = client;
	tmp->length = length;
	tmp->line = (char *)malloc((length + 1) * sizeof(char));
	memcpy(tmp->line, line, length);
	if (tail == NULL)
	{
		tmp->next = tmp;
		head = tail = tmp;
	}
	else
	{
		head = tmp->next = tail->next;
		tail->next = tmp;
		tail = tmp;
	}
}

void deleteFirst()
{
	if (tail == NULL) printf("\nList is empty.\n");
	else
	{
		hnode *tmp = tail->next;
		head = tail->next = tmp->next;
		free(tmp->line);
		free(tmp);
	}
}

void deleteLast()
{
	if (tail == NULL) printf("\nList is empty\n");
	else
	{
		hnode *tmp = tail;
		while (tmp->next != tmp)
			tmp = tmp->next;
		head = tmp->next = tail->next;
		tail = tmp->next;
		free(tmp->line);
		free(tmp);
	}
}

void viewList()
{
	if (tail == NULL) printf("\nList i empty\n");
	else
	{
		printf("\33[2K\rHistory message :\n");
		hnode *tmp = tail->next;
		do
		{
			printf("cli-%03d(%d) says: %s", tmp->client, tmp->length, tmp->line);
			fflush(stdout);
			tmp = tmp->next;
		} while (tmp != tail->next);
	}
}
