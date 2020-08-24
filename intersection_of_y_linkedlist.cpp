#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	struct Node* next;
};

// Helper function to print given linked list
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}

// Helper function to insert new Node in the beginning of the linked list
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

// Compute a new sorted list that represents the intersection
// of the two given sorted lists without using dummy node
struct Node* SortedIntersect(struct Node* a, struct Node* b)
{
	struct Node *head = NULL;
	struct Node* tail = NULL;

	// Once one or the other list runs out -- we're done
	while (a != NULL && b != NULL)
	{
		if (a->data == b->data)
		{
			if (head == NULL)
			{
				push(&head, a->data);
				tail=head;
			}
			else
			{
				push(&tail->next, a->data);
				tail=tail->next;
			}

			a = a->next;
			b = b->next;
		}

		// advance the smaller list
		else if (a->data < b->data)
			a = a->next;
		else
			b = b->next;
	}
	return head;
}

// main method
int main(void)
{
	int n,m;
	cin>>n>>m;
	int f[n+1],s[m+1];
	for (int i=n-1;i>=0;i--)
		cin>>f[i];
		for (int i=m-1;i>=0;i--)
		cin>>s[i];

	struct Node *a = NULL;
	for (int i=0;i<n;i++)
		push(&a, f[i]);
		
	struct Node *b = NULL;
	for (int i=0;i<m;i++)
		push(&b, s[i]);

	// print both linked list
	printf("First List  :  ");
	printList(a);

	printf("Second List : ");
	printList(b);

	struct Node *head = SortedIntersect(a, b);

	printf("\nAfter Intersection - ");
	printList(head);

	return 0;
}
