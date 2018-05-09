/*==========================================================
* Created       : 2017-05-31 12:15
* Last modified : 2017-05-31 12:15
* Filename      : linkedlist_2.cpp
* Description   : 双向链表
==========================================================*/

#include<iostream>
using namespace std;

template <class T>
class Node {
  public:
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template <class T>
class LinkedList {
  private :
    Node<T> *head;	// 链表头节点

  public:
    LinkedList();	// 构造函数
    ~LinkedList();	// 析构函数

    bool insertNode(const T &, int insert_pos);
    bool deleteNode(int del_pos);

    int getSize(); // 获取当前链表中节点数量
    Node<T>* search(const T &);

    void printLinkedList();	// 打印链表内容
    void printReverseLinkedList();	// 打印链表内容
};

// 构造函数，初始化链表头节点
template <class T>
LinkedList<T>::LinkedList() {
    head = new Node<T>();
    cout << "链表初始化" << endl << endl;
};

// 析构函数，释放链表空间
template <class T>
LinkedList<T>::~LinkedList() {
    int node_count = 0;
    Node<T> *p = head->next;
    while(head->next != NULL) {
        Node<T> *p = head->next;
        head->next = p->next;
        delete p;
        node_count++;
    }

    delete head;

    cout << endl << "链表空间释放，共 " << node_count << " 个节点" << endl;
};

// 计算当前链表大小
template <class T>
int LinkedList<T>::getSize() {
    int size = 0;

    Node<T> *p = head->next;
    while(p != NULL) {
        size++;
        p = p->next;
    }

    return size;
}

// 搜索节点，返回节点指针
template <class T>
Node<T>* LinkedList<T>::search(const T &a ) {
    Node<T> *temp = head->next;
    int pos = 0;
    while(temp != NULL) {
        if(temp->data == a) {
            break;
        }

        temp = temp->next;
        pos++;
    }

    if(temp == NULL) {
        cout << "搜索: " << a << "，未找到该节点" << endl;
    } else {
        cout << "搜索: " << a << "，找到该节点，位置: " << pos + 1 << endl;
    }

    return temp;
}

// 打印链表中节点内容
template <class T>
void LinkedList<T>::printLinkedList() {
    Node<T> *p = head->next;
    cout << endl << "链表内容:(头节点————>尾节点)" << endl << "[ ";
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "]" << endl << endl;
};

// 反向打印链表内容
template <class T>
void LinkedList<T>::printReverseLinkedList() {
    Node<T> *p = head;
    while(p->next != NULL) {
        p = p->next;
    }

    cout << endl << "链表内容:(尾节点————>头节点)" << endl << "[ ";
    while(p != head) {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << "]" << endl << endl;
}

// 增加节点，insert_pos 表示加在链表的第几个节点的后面
// 1表示加上当前链表第一个节点的后面，0表示加在head的后面
template <class T>
bool LinkedList<T>::insertNode(const T &a, int insert_pos) {
    if(insert_pos < 0) {
        cout << "加入位置不合法" << endl;
        return false;
    }

    Node<T> *insert_pre = head;
    while(insert_pos > 0 && insert_pre->next != NULL) {
        insert_pos--;
        insert_pre = insert_pre->next;
    }

    if(insert_pos > 0) {
        cout << "插入位置超过当前链表大小" << endl;
        return false;
    }

    Node<T> *new_node = new Node<T>();
    new_node->data = a;

    Node<T> *insert_next = insert_pre->next;
    new_node->next = insert_next;
    insert_pre->next = new_node;

    new_node->prev = insert_pre;
    if(insert_next != NULL) {
        insert_next->prev = new_node;
    }

    cout << "插入元素: " << a << endl;
    return true;
}

// 删除节点，del_pos表示要删除的节点位置(1表示链表不包括头节点的第一个节点)
template <class T>
bool LinkedList<T>::deleteNode(int del_pos) {
    Node<T> *pre = head;
    while(del_pos > 1 && pre->next != NULL) {
        del_pos--;
        pre = pre->next;
    }

    if(del_pos > 1 || pre->next == NULL || del_pos <= 0) {
        cout << "删除位置不合法" << endl;
        return false;
    }

    Node<T> *del_node = pre->next;
    Node<T> *temp = del_node->next;
    pre->next = del_node->next;
    if(temp != NULL) {
        temp->prev = pre;
    }

    cout << "删除节点：" << del_node->data << endl;
    delete del_node;
    return true;
}

int main() {
    LinkedList<int> *my_list = new LinkedList<int>();

    my_list->insertNode(1, 0);
    my_list->insertNode(2, 0);
    my_list->insertNode(3, 0);

    my_list->search(3);

    my_list->printLinkedList();
    my_list->printReverseLinkedList();

    my_list->deleteNode(1);
    my_list->printLinkedList();

    delete my_list;
    return 0;
}
