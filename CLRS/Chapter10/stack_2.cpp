/*============================================================================
* Author        : vitah
* Mail          : linw1225@163.com
* Created       : 2017-05-23 17:20
* Last modified : 2017-05-23 17:20
* Filename      : stack_2.cpp
* Description   : C++链表实现栈模版
=============================================================================*/

#include<iostream>
using namespace std;

// 栈中每个元素的节点
template <class T>
class Node {
  public:
    T data;
    Node<T> *next;
};

template <class T>
class Stack {
  public:
    Stack();
    ~Stack();

    bool pop();
    void push(const T&);

    bool isEmpty();
    void printStack();

  private:
    Node<T> *top;
};

// 构造函数，初始化空栈
template <class T>
Stack<T>::Stack() {
    top = NULL;
    cout << endl << "初始化空栈" << endl;
}

// 栈析构函数，需要释放栈中的每个节点
template <class T>
Stack<T>::~Stack() {
    int node_count = 0;
    Node<T> *p = NULL;
    while(top) {
        p = top;
        top = top->next;
        delete p;
        node_count++;
    }

    cout << endl << "栈空间释放，共 " << node_count << " 个节点" << endl;
}

// 判断栈是否为空
template <class T>
bool Stack<T>::isEmpty() {
    if(top) {
        return false;
    }

    return true;
}

// 出栈
template <class T>
bool Stack<T>::pop() {
    if(!isEmpty()) {
        Node<T> * p = top;

        cout << "出栈 : " << p->data << endl;

        top = top->next;
        delete p;
        return true;
    }

    return false;
}

// 入栈
template <class T>
void Stack<T>::push(const T &a) {
    Node<T> *p = new Node<T>();

    p->next = top;
    p->data = a;
    top = p;

    cout << "入栈 : " << a << endl;
}

template <class T>
void Stack<T>::printStack() {
    Node<T> *p = top;
    cout << endl << "栈顶 ————> 栈底" << endl << "[ ";
    while(p) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << "]" << endl << endl;
}


int main() {
    Stack<int> *my_stack = new Stack<int>();
    my_stack->printStack();

    my_stack->push(5);
    my_stack->push(50);
    my_stack->push(500);

    my_stack->printStack();

    my_stack->pop();
    my_stack->printStack();


    my_stack->pop();
    my_stack->printStack();

    delete my_stack;
    return 0;
}
