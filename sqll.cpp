#include "sqll.h"
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>

//======================= STACK ===========================

Stack::Stack()
{
    top = nullptr; 
}

Stack::~Stack() 
{
    while (!isEmpty()) 
    {
        pop();
    }
}

void Stack::push(string& value) 
{
    // complete this
    /*
    creating new node with the value
    setting new node's next to current top
    updating top to new node
    */
    node* newNode = new node(value);
    newNode->next = top; 
    top = newNode; 
}

string Stack::pop() 
{
    // complete this
    /*
    if function is empty, throw runtime error
    else, temp holds current top, value holds data of temp
    update top to next node, delete temp, return value
    */
    if (isEmpty())
    {
        throw runtime_error("Stack is empty");
    }
    node* temp = top; 
    string value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

string Stack::peek() 
{
    if (isEmpty()) 
    {
        throw runtime_error("Stack is empty");
    }

    return top->data;  
}

bool Stack::isEmpty() 
{
    return top == nullptr;
}

void Stack::display()
{
    node* current = top;
    cout << "Stack: ";
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//======================= QUEUE ===========================

Queue::Queue()
{
    front = nullptr;
    rear = nullptr; 
}

Queue::~Queue() 
{
    while (!isEmpty()) 
    {
        dequeue();
    }
}

void Queue::enqueue(string& value) 
{
    // complete this
    /*
    create new node with the value, new node's next is nullptr
    if queue is empty, set front and rear to new node
    else, set rear's next to new node, update rear to new node
    */
    node* newNode = new node(value);
    newNode->next = nullptr;
    if (isEmpty()) 
    {
        front = rear = newNode;
    }
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
}

string Queue::dequeue() 
{
    // complete this
    /*
    if function is empty, throw runtime error
    else, temp holds current front, value holds data of temp
    update front to next node
    if front is nullptr, set rear to nullptr
    delete temp, return value
    */
    if (isEmpty()) 
    {
        throw runtime_error("Queue is empty");
    }
    node* temp = front;
    string value = temp->data;
    front = front->next;
    if (front == nullptr) 
    {
        rear = nullptr;
    }
    delete temp;
    return value;
}

bool Queue::isEmpty() 
{
    return front == nullptr;
}

void Queue::display()
{
    node* current = front;
    cout << "Queue: ";
    
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//======================= DIJKSTRA'S TWO STACK ===========================
double evaluateExpression(string& expr) 
{
    // complete this using stacks
    stack<string> operators;
    stack<double> values;
    
    stringstream ss(expr);
    string token;

    while (ss >> token) // read each token from the expression
    {
        if (token == "(") 
        {
            // does nothing
        } 
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") 
        {
            operators.push(token); // push operator onto the stack
        } 
        else if (token == ")") 
        {
            string op = operators.top(); // get the operator
            operators.pop(); // pop the operator
            
            double num2 = values.top(); // get the second value and pops it
            values.pop();
            double num1 = values.top(); // get the first value and pops it
            values.pop();

            // does operations then pushes result onto stack
            if (op == "+") values.push(num1 + num2);
            else if (op == "-") values.push(num1 - num2);
            else if (op == "*") values.push(num1 * num2);
            else if (op == "/") values.push(num1 / num2);
            else if (op == "^") values.push(pow(num1, num2));
        } 
        else 
        {
            values.push(stod(token)); // convert token to double and push onto the stack
        }
    }

    return values.top();

}

// ============= JOSEPHUS PROBLEM ===========================
void josephus(int n, int k) 
{
    // complete this using queue
    std::queue<int> q;
    // fills queue with people numbered 1 to n
    for (int i = 1; i <= n; ++i) 
    {
        q.push(i);
    }

    std::cout << "Elimination order: ";
    // when more than one person remains, loop runs
    while (q.size() > 1) 
    {
        for (int i = 0; i < k - 1; ++i) 
        {
            int person = q.front(); // gets person from front of queue
            q.pop(); // removes person from front of queue
            q.push(person); // adds person to back of queue
        }
        std::cout << q.front() << " "; 
        q.pop(); // removes the kth person from the queue
    }
    std::cout << "\nSurvivor: " << q.front() << std::endl;
}