// Serial Number / s : 72 & 75
//
// Author : Tristan Wells & Connor Widder
//
// Programming Assignment Number 4
//
// Fall 2019 - CS 3358 - 1
//
// Due Date : 9-21-2019
//
// Instructor: Husain Gholoom.
//
// Program will interact with user to create a linked list format of a stack
// and queue. User will be able to add onto either and manipulate them as far
// as specific placement/deletion, complete deletion, and queue information
// for maximum, minimum, and averages.

#include <iostream>
using namespace std;

class SNode{ //node allocated for the stack
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
    { //allocates a new node with "k" for data

        SNode* temp = new SNode();
            temp->data = k;
            temp->next = NULL;
            return temp;
    }

    void display()
    {//iterates through all nodes to display list
        SNode* s;
        s = front;

        while (s != NULL) {
            cout<< s->data <<" ";
            s = s->next;
        }
    }

    Stack* createStack()
    {//creates an object as a template for nodes to stack onto
        Stack* s = new Stack();
        s->front = s->rear = NULL;
        return s;
    }

    void deleteStack(Stack* s)
    {//iterates through all nodes to delete them
        while(s->front != NULL){
            SNode* next = s->front->next;
            delete(s->front);
            s->front = next;
        }
    }

    void push(Stack* s, int k)
    {//adds stack to end of list with "k" as its data
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
    {//deletes a node from the beginning of the list
        // If stack is empty, return NULL.
        if (s->front == NULL)
            return NULL;

        SNode* temp = s->rear;
        delete(s->front);

        s->front = s->front->next;


        // If front becomes NULL, then
        // change rear also as NULL
        if (s->front == NULL)
            s->rear = NULL;
        return temp;
    }
};


class QNode { //node allocated for the queue
public:
	int data;
	QNode* next;
};

class Queue {
public:
	QNode *front; //first in line
	QNode *rear; //last in line

    QNode* newNode(int k)
    {//creates new node for queue
        QNode* temp = new QNode();
        temp->data = k;
        temp->next = NULL;
        return temp;
    }
    void display()
    {//displays each node through iteration
        QNode* q;
        q = front;

        while (q != NULL) {
            cout<< q->data <<" ";
            q = q->next;
        }
    }

    Queue* createQueue()
    {//funciton to develop housing for queue nodes
        Queue* q = new Queue();
        q->front = q->rear = NULL;
        return q;
    }

     void after(QNode* q, QNode* x, int k)
    {//specific queue placement
        //QNode* temp = newNode(k);

        while(q->data != k){
            q = q->next;
        }

        x->next = q->next;
        q->next = x;
    }

    Queue* min(Queue* q)
    {//Function to find the min value in the queue
        int min = 0;
        QNode* startNode = q->front;
        min = startNode->data;
        QNode* currentNode = q->front;

        while (currentNode != NULL){

            if (currentNode->data < min){
                min = currentNode->data;
            }

            currentNode = currentNode->next;
        }
        return q;
    }

    Queue* max(Queue* q)
    {//Function to find the max value in the queue
        int max = 0;
        QNode* startNode = q->front;
        max = startNode->data;
        QNode* currentNode = q->front;

        while (currentNode != NULL){
            if (currentNode->data > max){
                max = currentNode->data;
            }

            currentNode = currentNode->next;
        }

        return q;
    }

    int average(Queue* q)
    {//Function to find the average value in the queue
        int average = 0;
        int total = 0;
        int cnt = 0;

        QNode* currentNode = q->front;

        while (currentNode != NULL){
            total += currentNode->data;
            cnt++;
        }
        average = total/cnt;
        return average;

    }

    void enQueue(Queue* q, int k)
    {//adds node onto queue list
        // Create a new LL node
        QNode* temp = newNode(k);

        // If queue is empty, then
        // new node is front and rear both
        if (q->rear == NULL)
        {
            q->front = q->rear = temp;
            return;
        }
        // Add the new node at
        // the end of queue and change rear
        q->rear->next = temp;
        q->rear = temp;
    }

    void deleteQueue(Queue* q)
    {//iterates through all nodes for deletion
        while(q->front != NULL){
            QNode* next = q->front->next;
            delete(q->front);
            q->front = next;
        }
    }

    QNode* deQueue(Queue* q)
    {//deletes proper node
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
    char choice; //menu options
    Queue* q = q->createQueue();
    Queue* x = x->createQueue();
    Stack* s = s->createStack();
    int number; //data to be used in node insertion

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

        do {
        cout << "Enter letter choice (Capital Letters Only): -> ";
        cin >> choice;
        cout << endl;

        if(choice == 'A'){
            cout << "A: Insert new element in the stack (LIFO)" << endl;
            cout << "Which number: -> ";
            cin >> number;
                s->push(s, number);
	    cout << endl;
	    cout << "Queue: "; q->display();
            cout << endl;
            cout << "Stack: "; s->display();
            cout << endl
        }
        else if(choice == 'B'){
            cout << "B: Remove an element from the stack (LIFO)" << endl;
                s->pop(s);
	    cout << endl;
	    cout << "Queue: "; q->display();
            cout << endl;
            cout << "Stack: "; s->display();
            cout << endl
        }
        else if(choice == 'C'){
            cout << "C: Insert new element in the queue ( FIFO )" << endl;
            cout << "Which number: -> ";
            cin >> number;
                q->enQueue(q, number);
	    cout << endl;
	    cout << "Queue: "; q->display();
            cout << endl;
            cout << "Stack: "; s->display();
            cout << endl
        }
        else if(choice == 'D'){
            cout << "D. Insert an element at specific location in the queue" << endl;
            cout << "Which number: -> ";
            cin >> number;
	    cout << endl;
	    cout << "Queue: "; q->display();
            cout << endl;
            cout << "Stack: "; s->display();
            cout << endl
        }
        else if(choice == 'E'){
            cout << "E. Remove an element from the queue ( FIFO )" << endl;
                q->deQueue(q);
	    cout << endl;
	    cout << "Queue: "; q->display();
            cout << endl;
            cout << "Stack: "; s->display();
            cout << endl
        }
        else if(choice == 'F'){
             cout << "F. Remove a specific element from the queue" << endl;
             cout << "Which number: -> ";
             cin >> number;
	     cout << endl;
	     cout << "Queue: "; q->display();
             cout << endl;
             cout << "Stack: "; s->display();
             cout << endl
        }
        else if(choice == 'G'){
            cout << "G. Find Min element in the queue, Max element in the queue, and the Average of the queue" << endl;
            cout << "Min: " << q->min(q) << " Max: " << q->max(q) << " Average: " << q->average(q);
        }
        else if(choice == 'H'){
            cout << "H.Delete the entire stack" << endl;
                 s->deleteStack(s);
	    cout << endl;
	    cout << "Queue: "; q->display();
            cout << endl;
            cout << "Stack: "; s->display();
            cout << endl
        }
        else if(choice == 'I'){
            cout << "I. Delete the entire queue" << endl;
                q->deleteQueue(q);
	    cout << endl;
	    cout << "Queue: "; q->display();
            cout << endl;
            cout << "Stack: "; s->display();
            cout << endl
        }
        else if(choice == 'X'){
            cout << "X. Exit the program" << endl << endl;
            cout << "Queue: "; q->display();
            cout << endl;
            cout << "Stack: "; s->display();
            cout << endl << endl;
            cout << "This LL / Stack & Queue Program is Implemented By : "
                 << "Connor Widder & Tristan Wells - October 21st , 2019" << endl;
            return 0;
        }
        else {
            cout << "****Please enter one of the CAPITAL letter options****" << endl;
        }
            }while(choice != 'X');

	return 0;
}

