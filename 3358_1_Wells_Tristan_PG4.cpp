// A CPP program to demonstrate linked list
// based implementation of queue
#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;


// Driver code
int main()
{
    char choice;
    Queue* q = q->createQueue();
    Stack* s = s->createStack();

        cout << "A: Insert new element in the stack (LIFO)" << endl
             << "B: Remove an element from the stack (LIFO)" << endl
             << "C: Insert new element in the queue ( FIFO )" << endl
             << "D. Insert an element at specific location in the queue" << endl
             << "E. Remove an element from the queue ( FIFO )" << endl
             << "F. Remove a specific element from the queue" << endl
             << "G.Find Min element in the queue, Max element in the" << endl
             << "queue, and the Average of the queue" << endl
             << "H.Delete the entire stack" << endl
             << "I. Delete the entire queue" << endl
             << "X. Exit the program" << endl << endl;

        cout << "Enter letter choice (Capital Letters Only): -> ";
        cin >> choice;
        cout << endl;

        switch (choice){
            case 'A':
                cout << "A: Insert new element in the stack (LIFO)" << endl;
                s->push(s, 10);
            case 'B':
                cout << "B: Remove an element from the stack (LIFO)" << endl;
                s->pop(s);
            case 'C':
                cout << "C: Insert new element in the queue ( FIFO )" << endl;
                q->enQueue(q, 10);
            case 'D':
                cout << "D. Insert an element at specific location in the queue" << endl;
            case 'E':
                cout << "E. Remove an element from the queue ( FIFO )" << endl;
                q->deQueue(q);
            case 'F':
                cout << "F. Remove a specific element from the queue" << endl;
            case 'G':
                cout << "G. Find Min element in the queue, Max element in the queue, and the Average of the queue" << endl;
            case 'H':
                 cout << "H.Delete the entire stack" << endl;
            case 'I':
                cout << "I. Delete the entire queue" << endl;
            case 'X':
                cout << "X. Exit the program" << endl << endl;
            default:
                cout << "Enter ";
        }


	q->enQueue(q, 10);
	q->enQueue(q, 20);
	q->deQueue(q);
	q->deQueue(q);
	q->enQueue(q, 30);
	q->enQueue(q, 40);
	q->enQueue(q, 50);
	QNode* n = q->deQueue(q);
	if (n != NULL)
		cout << "Dequeued item is " << n->data;
	return 0;
}

