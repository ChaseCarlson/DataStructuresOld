#include "linked_list_test.h"
#include "linked_list.h"
#include "assert.h"

void test_linked_list_insert_after()
{
	LinkedListNode* head = linked_list_new(4);
	LinkedListNode* n1 = linked_list_insert_after(head, 5);
	LinkedListNode* n2 = linked_list_insert_after(n1, 6);
	LinkedListNode* n3 = linked_list_insert_after(n2, 7);
	LinkedListNode* n4 = linked_list_insert_after(n3, 8);
	LinkedListNode* n5 = linked_list_insert_after(n4, 9);

	assert(linked_list_find_at(head, 0)->data == 4);
	assert(linked_list_find_at(head, 1)->data == 5);
	assert(linked_list_find_at(head, 2)->data == 6);
	assert(linked_list_find_at(head, 3)->data == 7);
	assert(linked_list_find_at(head, 4)->data == 8);
	assert(linked_list_find_at(head, 5)->data == 9);
}

void test_linked_list_find_head()
{
	LinkedListNode* head = linked_list_new(4);
	LinkedListNode* n1 = linked_list_insert_after(head, 5);
	LinkedListNode* n2 = linked_list_insert_after(n1, 6);
	LinkedListNode* n3 = linked_list_insert_after(n2, 7);
	LinkedListNode* n4 = linked_list_insert_after(n3, 8);
	LinkedListNode* n5 = linked_list_insert_after(n4, 9);

	assert(linked_list_find_head(head) == head);
	assert(linked_list_find_head(n1) == head);
	assert(linked_list_find_head(n2) == head);
	assert(linked_list_find_head(n3) == head);
	assert(linked_list_find_head(n4) == head);
	assert(linked_list_find_head(n5) == head);
}

void test_linked_list_find_tail()
{
	LinkedListNode* head = linked_list_new(4);
	LinkedListNode* n1 = linked_list_insert_after(head, 5);
	LinkedListNode* n2 = linked_list_insert_after(n1, 6);
	LinkedListNode* n3 = linked_list_insert_after(n2, 7);
	LinkedListNode* n4 = linked_list_insert_after(n3, 8);
	LinkedListNode* n5 = linked_list_insert_after(n4, 9);

	assert(linked_list_find_tail(head) == n5);
	assert(linked_list_find_tail(n1) == n5);
	assert(linked_list_find_tail(n2) == n5);
	assert(linked_list_find_tail(n3) == n5);
	assert(linked_list_find_tail(n4) == n5);
	assert(linked_list_find_tail(n5) == n5);
}

void test_linked_list_insert_at()
{
	LinkedListNode* head = linked_list_new(4);
	LinkedListNode* n2 = linked_list_insert_after(head, 6);
	LinkedListNode* n3 = linked_list_insert_after(n2, 7);
	LinkedListNode* n1 = linked_list_insert_at(head, 1, 5);
	LinkedListNode* n5 = linked_list_insert_after(n3, 9);
	LinkedListNode* n4 = linked_list_insert_at(head, 4, 8);

	assert(linked_list_find_at(head, 0) == head);
	assert(linked_list_find_at(head, 1) == n1);
	assert(linked_list_find_at(head, 2) == n2);
	assert(linked_list_find_at(head, 3) == n3);
	assert(linked_list_find_at(head, 4) == n4);
	assert(linked_list_find_at(head, 5) == n5);
}

void test_linked_list_remove_at()
{
	LinkedListNode* head = linked_list_new(4);
	LinkedListNode* n1 = linked_list_insert_after(head, 5);
	LinkedListNode* n2 = linked_list_insert_after(n1, 6);
	LinkedListNode* n3 = linked_list_insert_after(n2, 7);
	LinkedListNode* n4 = linked_list_insert_after(n3, 8);
	LinkedListNode* n5 = linked_list_insert_after(n4, 9);

	linked_list_remove_at(head, 3);

	assert(linked_list_find_at(head, 0)->data == 4);
	assert(linked_list_find_at(head, 1)->data == 5);
	assert(linked_list_find_at(head, 2)->data == 6);
	assert(linked_list_find_at(head, 3)->data == 8);
	assert(linked_list_find_at(head, 4)->data == 9);

	linked_list_remove_at(n4, 1);
	assert(linked_list_find_at(head, 0)->data == 4);
	assert(linked_list_find_at(head, 1)->data == 6);
	assert(linked_list_find_at(head, 2)->data == 8);
	assert(linked_list_find_at(head, 3)->data == 9);

	linked_list_remove_at(head, 0);
	assert(linked_list_find_at(n4, 0)->data == 6);
	assert(linked_list_find_at(n4, 1)->data == 8);
	assert(linked_list_find_at(n4, 2)->data == 9);
}

void test_linked_list()
{
	test_linked_list_insert_after();
	test_linked_list_find_head();
	test_linked_list_find_tail();
	test_linked_list_insert_at();
	test_linked_list_remove_at();

	printf("LinkedList Tests Passing\n");
}