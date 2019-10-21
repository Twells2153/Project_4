#include <iostream>
using namespace std;

class SNode{
    public:
        int data;
        SNode* next;
};

struct SNode* top;
class Stack{
public:
    SNode *front;
    SNode *rear;

    SNode* newNode(int k)
    {

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

    void deleteStack(Stack* s){
        while(s->front != NULL){
            SNode* next = s->front->next;
            delete(s->front);
            s->front = next;
        }
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


class QNode {
public:
	int data;
	QNode* next;
};

class Queue {
public:
	QNode *front;
	QNode *rear;

    QNode* newNode(int k)
    {
        QNode* temp = new QNode();
        temp->data = k;
        temp->next = NULL;
        return temp;
    }

    Queue* createQueue()
    {
        Queue* q = new Queue();
        q->front = q->rear = NULL;
        return q;
    }

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
    void deleteQueue(Queue* q){
        while(q->front != NULL){
            QNode* next = q->front->next;
            delete(q->front);
            q->front = next;
        }
    }
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

// Driver code
int main()
{
    char choice;
    Queue* q = q->createQueue();
    Stack* s = s->createStack();

        cout << "A: Insert new element in the stack (LIFO)" << endl
             << "B: Remove an element from the stack (LIFO)" << endl
             << "C: Insert new element in the queue (FIFO)" << endl
             << "D. Insert an element at specific location in the queue" << endl
             << "E. Remove an element from the queue (FIFO)" << endl
             << "F. Remove a specific element from the queue (FIFO)" << endl
             << "G.Find Min element in the queue, Max element in the" << endl
             << "queue, and the Average of the queue" << endl
             << "H.Delete the entire stack" << endl
             << "I. Delete the entire queue" << endl
             << "X. Exit the program" << endl << endl;

        cout << "Enter letter choice (Capital Letters Only): -> ";
        cin >> choice;
        cout << endl;

        if(choice == 'A'){
            cout << "A: Insert new element in the stack (LIFO)" << endl;
                s->push(s, 10);
        }
        else if(choice == 'B'){
            cout << "B: Remove an element from the stack (LIFO)" << endl;
                s->pop(s);
        }
        else if(choice == 'C'){
            cout << "C: Insert new element in the queue ( FIFO )" << endl;
                q->enQueue(q, 10);
        }
        else if(choice == 'D'){
            cout << "D. Insert an element at specific location in the queue" << endl;
        }
        else if(choice == 'E'){
            cout << "E. Remove an element from the queue ( FIFO )" << endl;
                q->deQueue(q);
        }
        else if(choice == 'F'){
             cout << "F. Remove a specific element from the queue" << endl;
        }
        else if(choice == 'G'){
            cout << "G. Find Min element in the queue, Max element in the queue, and the Average of the queue" << endl;
        }
        else if(choice == 'H'){
            cout << "H.Delete the entire stack" << endl;
                 s->deleteStack(s);
        }
        else if(choice == 'I'){
            cout << "I. Delete the entire queue" << endl;
                q->deleteQueue(q);
        }
        else if(choice == 'X'){
            cout << "X. Exit the program" << endl << endl;
        }
        else {
            
        }

	q->enQueue(q, 10);
	q->enQueue(q, 20);
	q->deQueue(q);
	q->deQueue(q);
	q->enQueue(q, 30);
	q->enQueue(q, 40);
	q->enQueue(q, 50);
	q->deleteQueue(q);
	QNode* n = q->deQueue(q);
	if (n != NULL)
		cout << "Dequeued item is " << n->data;
	return 0;
}
