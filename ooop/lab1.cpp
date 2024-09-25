//
//  lab1.cpp
//  ooop
//
//  Created by Sasha Gylkovska on 25.09.2024.
//

#include <iostream>
#include <string>

using namespace std;

 
// Однозв'язний список
template<typename T>
class List
{
public:
    List();
    ~List();
    void pop_front(); // Видалення першого елемента списку
    void clear(); // Очищення всього списку
    
private:
    
    class Node
    {
    public:
        Node *pNext;
        T data;
        
        Node(T data = T(), Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node *head;
};

// Конструктор
template<typename T>
List<T>::List(){
    Size = 0;
    head = nullptr;
}

// Деструктор
template<typename T>
List<T>::~List(){
    clear(); // Видаляємо всі елементи
}

// Очищення списку
template<typename T>
void List<T>::clear(){
    while (Size)
        pop_front();
}

// Видалення першого елемента
template<typename T>
void List<T>::pop_front(){
    if (head != nullptr) {
        Node* temp = head; // Зберігаємо адресу першого елемента
        head = head->pNext; // Зсуваємо голову до наступного елемента
        delete temp; // Видаляємо стару голову
        Size--;
    }
}

int main()
{
    List<int> lst;
    return 0;
}
