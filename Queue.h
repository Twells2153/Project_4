#include <iostream>
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H

class QNode {
public:
	int data;
	QNode* next;
};

class Queue {
public:
	QNode *front, *rear;

// A utility function to create
// a new linked list node.
QNode* newNode(int k)
{
	QNode* temp = new QNode();
	temp->data = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty queue
Queue* createQueue()
{
	Queue* q = new Queue();
	q->front = q->rear = NULL;
	return q;
}

// The function to add a data k to q
void enQueue(Queue* q, int k)
{
	// Create a new LL node
	QNode* temp = newNode(k);

	// If queue is empty, then
	// new node is front and rear both
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	// Add the new node at
	// the end of queue and change rear
	q->rear->next = temp;
	q->rear = temp;
}

// Function to remove
// a data from given queue q
QNode* deQueue(Queue* q)
{
	// If queue is empty, return NULL.
	if (q->front == NULL)
		return NULL;

	// Store previous front and
	// move front one node ahead
	QNode* temp = q->front;
	delete(temp);

	q->front = q->front->next;

	// If front becomes NULL, then
	// change rear also as NULL
	if (q->front == NULL)
		q->rear = NULL;
	return temp;
}

};
#endif // QUEUE_H
