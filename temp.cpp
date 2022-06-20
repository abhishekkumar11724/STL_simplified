
#include <cstdio>
#include <iostream>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};
struct Node* getTail(struct Node* cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}
struct Node* partition(struct Node* head, struct Node* end,struct Node** newHead,struct Node** newEnd)
{
	struct Node* pivot = end;
	struct Node *prev = NULL, *cur = head, *tail = pivot;
	while (cur != pivot) {
		if (cur->data < pivot->data) {
			if ((*newHead) == NULL)
				(*newHead) = cur;
			prev = cur;
			cur = cur->next;
		}
		else{
			if (prev)
				prev->next = cur->next;
			struct Node* tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}
	if ((*newHead) == NULL)
		(*newHead) = pivot;
	(*newEnd) = tail;
	return pivot;
}
struct Node* quickSortRecur(struct Node* head,struct Node* end)
{
	if (!head || head == end)
		return head;

	Node *newHead = NULL, *newEnd = NULL;
	struct Node* pivot = partition(head, end, &newHead, &newEnd);

	if (newHead != pivot) {
		struct Node* tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		newHead = quickSortRecur(newHead, tmp);
		tmp = getTail(newHead);
		tmp->next = pivot;
	}
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}
void quickSort(struct Node** headRef)
{
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}
int main()
{
	struct Node* a = NULL;
	push(&a, 7);
	push(&a, 0);
	push(&a, 6);
	push(&a, 2);
	push(&a, 3);

	cout << "Linked List before sorting \n";
	printList(a);

	quickSort(&a);

	cout << "Linked List after sorting \n";
	printList(a);

	return 0;
}
