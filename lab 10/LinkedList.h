#pragma once
#include <iostream>
using namespace std;
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    void add(T t) {  // Хүснэгтийн ард үзэх
        Node* newNode = new Node(t);
        if (!head) {
            head = newNode;
        } else {
            Node* p = head;
            while (p->next) p = p->next;
            p->next = newNode;
        }
        count++;
    }

    void insert(T t, int index) {  // Жагсаалтын "index"-дх дугаарт нэмэх
        if (index < 0 || index > count) return;
        Node* newNode = new Node(t);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* p = head; //Байрыг нь солиод ард байгаа элементийн хаяг өөрчлөх
            for (int i = 0; i < index - 1; i++) p = p->next;
            newNode->next = p->next;
            p->next = newNode;
        }
        count++;
    }

    T get(int index) {  // index-д утга олох
        Node* p = head;
        for (int i = 0; i < index; i++) p = p->next;
        return p->data;
    }

    void remove(int index) { // жагсаалтаас элемент устгах
        if (index < 0 || index >= count) return;
        Node* temp;
        if (index == 0) { //Эхний элементийг устгаад next элемент нь head болно.
            temp = head;
            head = head->next;
        } else { // Жагсаалтаар нэг нэгээр нь гүйж олно
            Node* p = head;
            for (int i = 0; i < index - 1; i++) p = p->next;
            temp = p->next;
            p->next = temp->next; // утгийг нь дарах
        }
        delete temp;
        count--;
    }

    int length() { // Уртыг олох
        return count;
    }

    void sortByArea() { //Bubble sort
        for (Node* i = head; i != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->data->getArea() > j->data->getArea()) {
                    T temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }

    void displayAll() {
        Node* p = head;
        while (p) {
            p->data->display();
            std::cout << "----------------------" << std::endl;
            p = p->next;
        }
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
