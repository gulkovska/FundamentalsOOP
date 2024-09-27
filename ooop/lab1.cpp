//
//  lab1.cpp
//  ooop
//
//  Created by Sasha Gylkovska on 25.09.2024.
//

#include <iostream>
#include <string>
#include <vector>

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


//двозв'язний список

template<typename T>
class list{
public:
list();
   ~list();
   
   void push_front(T data);// вставка на початок списку
   void push_back(T data);// вставка в кінець списку
   void clear(); // Очищення всього списку
   int size() { return Size; } // Отримання розміру
   T& operator[](const int index); // Доступ до елемента за індексом
   void insert(T data, int index); // вставка за індексом
   void pop_front();// видалення першого елемета
   void pop_back();// видалення останнього елемента
   void removeAt(int index);// видалення за індексом
   
   
private:
   class Node{
   public:
       Node *next;
       Node* prev;
       T data;
       
       Node(T data = T(), Node* next = nullptr, Node* prev = nullptr){
           this->data = data;
           this->next = next;
           this->prev = prev;
       }
   };
   
   int Size;
   Node *head;
   Node *tail;
};

// Конструктор
template<typename T>
list<T>::list(){
   Size = 0;
   head = nullptr;
   tail = nullptr;
}

// Деструктор
template<typename T>
list<T>::~list(){
   clear();
}

// Очищення списку
template<typename T>
void list<T>::clear(){
   while (head != nullptr){
       Node* temp = head;
       head = head->next;
       delete temp;
   }
   tail = nullptr;
   Size = 0;
}


// Додавання елемента на початок списку
template<typename T>
void list<T>::push_front(T data){
   Node* new_node = new Node(data, head, nullptr);
   if (head != nullptr){
       head->prev = new_node;
   }
   head = new_node;
   
   if (tail == nullptr) {
       tail = new_node;
   }
   Size++;
}

//додає елемент в кінець
template<typename T>
void list<T>::push_back(T data){
   Node* new_node = new Node(data, nullptr, tail);
   if(tail!= nullptr){
       tail->next = new_node;
   }
   tail = new_node;
   
   if(head == nullptr){
       head = new_node;
   }
   Size++;
}


//повертає значення за вказаним індексом
template<typename T>
T& list<T>::operator[](const int index){
   int counter = 0;
   Node* current = this->head;
   while (current != nullptr){
       if (counter == index){
           return current->data;
       }
       current = current->next;
       counter++;
   }
   throw out_of_range("Індекс за межами списку");
}

//Вставляє елемент на вказану позицію в списку
template<typename T>
void list<T>::insert(T data, int index) {
   if (index == 0) {
       push_front(data);
   }
   else if (index == Size) {
       push_back(data);
   }
   else {
       Node* previous = head;
       
       for (int i = 0; i < index - 1; i++) {
           previous = previous->next;
       }
       
       
       Node* newNode = new Node(data, previous->next, previous);
       
       
       previous->next->prev = newNode;
       previous->next = newNode;

       Size++;
   }
}

//видаляє перший елемент
template<typename T>
void list<T>::pop_front() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        Size--;
    }
}


//видаляє останній елемент
template<typename T>
void list<T>::pop_back(){
   if(tail != nullptr) {
       Node* temp = tail;
       tail = tail->prev;
       
       if(tail !=nullptr){
           tail->next = nullptr;
       }
       else {
           head = nullptr;
       }
       delete temp;
       Size--;
   }
   
   
}

//Видаляє елемент за вказаним індексом.
template<typename T>
void list<T>::removeAt(int index) {
   if (index == 0) {
       pop_front();
   } else if (index == Size - 1) {
       pop_back();
   } else {
       Node* previous = this->head;
       for (int i = 0; i < index - 1; i++) {
           previous = previous->next;
       }
       
       Node* toDelete = previous->next;
       previous->next = toDelete->next;
       if (toDelete->next != nullptr) {
           toDelete->next->prev = previous;
       }
       delete toDelete;
       Size--;
   }
}

//cписок на основі масиву
template<typename T>
class ArrayList {
public:
    ArrayList();
    ~ArrayList();
    
    void push_back(T value);   // Додавання елемента в кінець
    void insert(T value, int index); // Вставка елемента в заданий індекс
    void removeAt(int index);  // Видалення елемента за індексом
    void pop_back();           // Видалення останнього елемента
    int size() const;          // Повертає кількість елементів у списку
    T& operator[](int index);  // Оператор доступу до елемента за індексом
    
private:
    void resize(); // Допоміжний метод для розширення масиву

    T* data;
    int capacity;
    int currentSize;
};

// Конструктор
template<typename T>
ArrayList<T>::ArrayList() {
    capacity = 10;
    currentSize = 0;
    data = new T[capacity];
}

// Деструктор
template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

// Додавання елемента в кінець списку
template<typename T>
void ArrayList<T>::push_back(T value) {
    if (currentSize == capacity) {
        resize();
    }
    data[currentSize++] = value;
}

// Вставка елемента за індексом
template<typename T>
void ArrayList<T>::insert(T value, int index) {
    if (index < 0 || index > currentSize) {
        throw out_of_range("Індекс поза межами списку");
    }

    if (currentSize == capacity) {
        resize();
    }

    for (int i = currentSize; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = value;
    currentSize++;
}

// Видалення елемента за індексом
template<typename T>
void ArrayList<T>::removeAt(int index) {
    if (index < 0 || index >= currentSize) {
        throw out_of_range("Індекс поза межами списку");
    }

    for (int i = index; i < currentSize - 1; i++) {
        data[i] = data[i + 1];
    }

    currentSize--;
}

// Видалення останнього елемента
template<typename T>
void ArrayList<T>::pop_back() {
    if (currentSize > 0) {
        currentSize--;
    }
}

// Повертає кількість елементів у списку
template<typename T>
int ArrayList<T>::size() const {
    return currentSize;
}

// Оператор доступу до елемента за індексом
template<typename T>
T& ArrayList<T>::operator[](int index) {
    if (index < 0 || index >= currentSize) {
        throw out_of_range("Індекс поза межами списку");
    }

    return data[index];
}

// Допоміжний метод для розширення масиву
template<typename T>
void ArrayList<T>::resize() {
    capacity *= 2;
    T* newData = new T[capacity];

    for (int i = 0; i < currentSize; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}


// Клас "Масив" на основі vector
template<typename T>
class MyArray {
private:
    vector<T> data;

public:
    // Додавання елемента в кінець масиву
    void push_back(T value) {
        data.push_back(value);
    }

    // Видалення елемента з кінця масиву
    void pop_back() {
        if (data.empty()) {
            throw out_of_range("Масив порожній, неможливо видалити елемент.");
        }
        data.pop_back();
    }

    // Доступ до елемента за індексом
    T& operator[](int index) {
        if (index < 0 || index >= data.size()) {
            throw out_of_range("Індекс за межами масиву.");
        }
        return data[index];
    }

    // Отримання розміру масиву
    int size() const {
        return data.size();
    }

    // Перевірка на порожність масиву
    bool empty() const {
        return data.empty();
    }

    // Очищення всього масиву
    void clear() {
        data.clear();
    }

    // Виведення вмісту масиву
    void print() const {
        for (const T& elem : data) {
            cout << elem << " ";
        }
        cout << endl;
    }
};


template<typename T>
class Sorter {
public:
    Sorter(vector<T>& data) : arr(data) {}
    
    // Сортування вставками
    void insertionSort() {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            T key = arr[i];
            int j = i - 1;
            
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
    // Сортування бульбашкою
    void bubbleSort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Сортування вибором
    void selectionSort() {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
    
private:
    vector<T>& arr;
};



int main()
{
   /* List<int> lst;
    
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
*/
  /*  list<int> lstt;

    // Додавання елементів в кінець
    lstt.push_back(10);
    lstt.push_back(20);
    lstt.push_back(30);
    cout << "Елементи після додавання в кінець: ";
    for (int i = 0; i < lstt.size(); i++) {
        cout << lstt[i] << " ";
    }
    cout << endl;

    // Додавання елемента на початок
    lstt.push_front(5);
    cout << "Елементи після додавання на початок: ";
    for (int i = 0; i < lstt.size(); i++) {
        cout << lstt[i] << " ";
    }
    cout << endl;

    // Вставка за індексом
    lstt.insert(15, 2);
    cout << "Елементи після вставки на 2-й індекс: ";
    for (int i = 0; i < lstt.size(); i++) {
        cout << lstt[i] << " ";
    }
    cout << endl;

    // Видалення елемента за індексом
    lstt.removeAt(2);
    cout << "Елементи після видалення 2-го індексу: ";
    for (int i = 0; i < lstt.size(); i++) {
        cout << lstt[i] << " ";
    }
    cout << endl;

    // Видалення першого елемента
    lstt.pop_front();
    cout << "Елементи після видалення першого елемента: ";
    for (int i = 0; i < lstt.size(); i++) {
        cout << lstt[i] << " ";
    }
    cout << endl;

    // Видалення останнього елемента
    lstt.pop_back();
    cout << "Елементи після видалення останнього елемента: ";
    for (int i = 0; i < lstt.size(); i++) {
        cout << lstt[i] << " ";
    }
    cout << endl;

    // Очищення списку
    lstt.clear();
    cout << "Розмір після очищення: " << lstt.size() << endl;

 */
    
   
        
     /*   ArrayList<int> list;

 
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        cout << "Елементи після додавання в кінець: ";
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;

         
        list.insert(15, 1);
        cout << "Елементи після вставки 15 на 1-й індекс: ";
        for (int i = 0; i < list.size(); i++) {
           cout << list[i] << " ";
        }
       cout << endl;

         
        list.removeAt(2);
        cout << "Елементи після видалення 2-го індексу: ";
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;

         
        list.pop_back();
        cout << "Елементи після видалення останнього елемента: ";
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;

        // Очищення списку
        while (list.size() > 0) {
            list.pop_back();
        }
        cout << "Розмір після очищення: " << list.size() << endl;
*/
    
  /*  MyArray<int> arr;

        
       arr.push_back(10);
       arr.push_back(20);
       arr.push_back(30);

       cout << "Елементи масиву: ";
       arr.print();

       
       cout << "Елемент за індексом 1: " << arr[1] << endl;

       
       arr.pop_back();
       cout << "Елементи після видалення останнього: ";
       arr.print();

        
       cout << "Масив порожній? " << (arr.empty() ? "Так" : "Ні") << endl;

        
       arr.clear();
       cout << "Масив очищено. Порожній? " << (arr.empty() ? "Так" : "Ні") << endl;
*/
    vector<int> data = {5, 2, 9, 1, 5, 6};

         
        Sorter<int> sorter(data);
    
        cout << "Масив до сортування: ";
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;

         
     /*   sorter.insertionSort();
        cout << "Масив після сортування: ";
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;*/

    
     
     /*  sorter.bubbleSort();
       cout << "Масив після сортування бульбашкою: ";
       for (int num : data) {
           cout << num << " ";
       }
       cout << endl;
*/
        
       sorter.selectionSort();
       cout << "Масив після сортування вибором: ";
       for (int num : data) {
           cout << num << " ";
       }
       cout << endl;

    return 0;
}
