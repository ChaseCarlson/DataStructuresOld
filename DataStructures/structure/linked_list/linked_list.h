#include <malloc.h>

#ifndef DS_LINKED_LIST
typedef struct LinkedListNode {
	int data;
	struct LinkedListNode* prev;
	struct LinkedListNode* next;
} LinkedListNode;

LinkedListNode* linked_list_new(int data)
{
	LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = data;

	return newNode;
}

LinkedListNode* linked_list_insert_after(LinkedListNode* node, int data)
{
	LinkedListNode* newNode = linked_list_new(data);
	newNode->data = data;
	if (node->next)
	{
		newNode->next = node->next;
	}
	node->next = newNode;
	newNode->prev = node;

	return newNode;
}

LinkedListNode* linked_list_find_head(LinkedListNode* node)
{
	LinkedListNode* current = node;
	while (current->prev != NULL)
	{
		current = current->prev;
	}
	
	return current;
}

LinkedListNode* linked_list_find_tail(LinkedListNode* node)
{
	LinkedListNode* current = node;
	while (current->next != NULL)
	{
		current = current->next;
	}

	return current;
}

LinkedListNode* linked_list_find_at(LinkedListNode* node, int position)
{
	LinkedListNode* currentNode = linked_list_find_head(node); // node position 0
	int currentPos = 0;
	while (currentPos < position && currentNode != NULL)
	{
		currentNode = currentNode->next;
		currentPos++;
	}

	return currentNode;
}

LinkedListNode* linked_list_insert_at(LinkedListNode* node, int position, int data)
{
	LinkedListNode* nodeBefore = linked_list_find_at(node, position - 1);
	return linked_list_insert_after(nodeBefore, data);
}

void linked_list_remove(LinkedListNode* node)
{
	if (node->prev)
	{
		node->prev->next = node->next;
	}
	if (node->next)
	{
		node->next->prev = node->prev;
	}
	free(node);
}

void linked_list_remove_at(LinkedListNode* node, int position)
{
	LinkedListNode* toRemoveNode = linked_list_find_at(node, position);
	linked_list_remove(toRemoveNode);
}

LinkedListNode* linked_list_push(LinkedListNode* node, int data)
{
	LinkedListNode* endNode = linked_list_find_tail(node);
	linked_list_insert_after(node, data);
}

void linked_list_pop(LinkedListNode* node)
{
	LinkedListNode* endNode = linked_list_find_tail(node);
	linked_list_remove(linked_list_find_tail(node));
}

#endif