//
//  main.cpp
//  数据结构与算法
//
//  Created by 黄启明 on 2016/10/17.
//  Copyright © 2016年 huatengIOT. All rights reserved.
//

#include <iostream>
using namespace std;



//MARK: - 数组
void reverseArray(int array[], int length) {
    int left = 0;
    int right = length - 1;
    while (left < right) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }
}

//MARK: - 链表
struct Node {
    int m_iData;
    Node *next;
    Node(int num = 0) {
        m_iData = num;
    }
};

Node* reverseLinkedList(Node *head) {
    //使用递归
    if (head == nullptr || head -> next == nullptr) {
        return head;
    }
    else {
        Node *second = head -> next;
        Node *new_head = reverseLinkedList(second);
        second -> next = head;
        head -> next = nullptr;
        return new_head;
    }
}

Node* reverseLink(Node *head) {
    //不使用递归
    if (head == nullptr || head -> next == nullptr) {
        return head;
    } else {
        Node *p = head -> next;
        Node *p_p = head;
        head -> next = nullptr;
        while (p != nullptr) {
            Node *p_n = p -> next;
            p -> next = p_p;
            p_p = p;
            p = p_n;
        }
        return p_p;
    }
}

void linkedList() {
    Node *head = nullptr;
    for (int i = 0; i < 3; i++) {
        Node *new_node = new Node;
        new_node -> m_iData = i * 10;
        new_node -> next = head;
        head = new_node;
    }
    
    Node *iter = head;
    while (iter) {
        cout << iter -> m_iData << endl;
        iter = iter -> next;
    }
//    Node *newHead = reverseLinkedList(head);
    Node *newHead = reverseLink(head);

    while (newHead) {
        cout << newHead -> m_iData << endl;
        newHead = newHead -> next;
    }
}

//约瑟夫环问题
class JosephCircle {
    Node *tail;
    Node *deletenode;
public:
    JosephCircle() {
        tail = nullptr;
    }
    
    void add(int value) {
        if (tail == nullptr) {
            tail = new Node(value);
            tail -> next = tail;
        } else {
            Node *new_node = new Node(value);
            new_node -> next = tail -> next;
            tail -> next = new_node;
            tail = new_node;
        }
    }
    
    void elimate(int step) {
        Node *p = tail;
        while (p != nullptr && p -> next != p) {
            for (int i = 0; i < step - 2; i++) {
                p = p -> next;
            }
            Node *delete_node = p -> next;
            p -> next = p -> next -> next;
            
            if (delete_node == tail) {
                tail = p;
            }
            p = p -> next;
            
            cout << "delete:" << delete_node->m_iData << endl;
            delete delete_node;
            output();
        }
        
    }
    
    void output () {
        Node *p = tail;
        while (p != nullptr) {
            p = p -> next;
            cout << p -> m_iData << " ";
            if (p == tail) {
                break;
            }
        }
        cout << endl;
    }
};



//MARK: - 递归

int fib(int n) {
    if (n < 2) {
        return n;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main(int argc, const char * argv[]) {
    
//    linkedList();
    
//    int arr[] = {5,4,10,1,7,9,2};
//    reverseArray(arr, 7);
//    for (int i = 0; i < 7; i++) {
//        cout << arr[i] << " ";
//    }
    
//    for (int i = 0; i < 20; i++) {
//        cout << fib(i) << endl;
//    }
    
    JosephCircle circle;
    for (int i = 0; i < 17; i++) {
        circle.add(i);
    }
    circle.elimate(3);
    
    return 0;
}
