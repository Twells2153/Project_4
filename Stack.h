#include <iostream>
using namespace std;
#ifndef STACK_H
#define STACK_H

class SNode{
    public:
        int data;
        SNode* next;
};
// C program to Implement a stack
//using singly linked list

// Declare linked list SNode

struct SNode* top;
class Stack{
public:
SNode *front, *rear;

SNode* newNode(int k){

    SNode* temp = new SNode();
        temp->data = k;
        temp->next = NULL;
        return temp;
}
Stack* createStack()
{
	Stack* s = new Stack();
	s->front = s->rear = NULL;
	return s;
}
void push(Stack* s, int k)
{
	// Create a new LL node
	SNode* temp = newNode(k);

	// If queue is empty, then
	// new node is front and rear both
	if (s->rear == NULL) {
		s->front = s->rear = temp;
		return;
	}
	s->rear->next = temp;
	s->rear = temp;
}
SNode* pop(Stack* s)
{
	// If queue is empty, return NULL.
	if (s->front == NULL)
		return NULL;

	// Store previous front and
	// move front one node ahead
	SNode* temp = s->rear;
	delete(temp);

	s->rear = s->rear->next;

	// If front becomes NULL, then
	// change rear also as NULL
	if (s->rear == NULL)
		s->front = NULL;
	return temp;
}
};

#endif // STACK_H
