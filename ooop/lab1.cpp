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
    void push_back(T data); // Вставка в кінець списку
    int GetSize() { return Size; } // Отримання розміру списку
    T& operator[](const int index); // Доступ до елемента за індексом
    
    void push_front(T data);// вставка в початок
    void insert(T value, int index); // вставка
    void removeAt(int index);//видаляє елемент за вказаним індексом у списку.
    void pop_back();//видаляє останній елемент у списку.

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
    clear();  
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
        Node* temp = head;
        head = head->pNext;
        delete temp;
        Size--;
    }
}

// Додавання елемента в кінець списку
template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr){
        head = new Node(data);
    }
    else{
        Node* current = this->head;
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    Size++;
}

 

// Оператор доступу до елемента за індексом
template<typename T>
T& List<T>::operator[](const int index){
    int counter = 0;
    Node* current = this->head;
    while (current != nullptr){
        if (counter == index){
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
    throw out_of_range("Індекс за межами списку");
}

// вставка елемента на початок
template<typename T>
void List<T>::push_front(T data){
    head = new Node(data, head);
    Size++;
}


// Вставка елемента за індексом
template<typename T>
void List<T>::insert(T data, int index){
    if (index==0){
        push_front(data);
    }
    else{
        Node *previous = this->head;
        for( int i = 0 ; i<index-1; i++){
            previous = previous->pNext;
        }
        Node *newNode = new Node(data, previous->pNext);
        previous->pNext = newNode;
        Size++;
    }
    
}

// Видалення елемента за індексом
    template<typename T>
    void List<T>::removeAt(int index)
{
        if(index==0)
        {
            pop_front();
        }
        else
        {
            Node *previous = this->head;
            for(int i = 0; i<index-1; i++)
            {
                previous = previous->pNext;
            }
            
            Node *toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            delete toDelete;
            
            Size--;
        }
}
// Видалення останнього елемента зі списку
template<typename T>
void List<T>::pop_back()
{
    removeAt(Size-1);
}


int main()
{
    List<int> lst;
    
    // Додавання елементів
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    cout << "Елементи після додавання в кінець: ";
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    // Додавання на початок
    lst.push_front(5);
    cout << "Елементи після додавання на початок: ";
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    // Вставка за індексом
    lst.insert(15, 2);
    cout << "Елементи після вставки на 2-й індекс: ";
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    // Видалення елемента за індексом
    lst.removeAt(2);
    cout << "Елементи після видалення 2-го індексу: ";
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    // Видалення першого елемента
    lst.pop_front();
    cout << "Елементи після видалення першого елемента: ";
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

    // Видалення останнього елемента
    lst.pop_back();
    cout << "Елементи після видалення останнього елемента: ";
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << " ";
    }
    cout << endl;

//Очищення списку
  lst.clear();
   cout << "Розмір після очищення: " << lst.GetSize() << endl;

    
    return 0;
}
