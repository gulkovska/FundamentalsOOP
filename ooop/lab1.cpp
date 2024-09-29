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
    
    // Швидке сортування
    void quicksort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quicksort(low, pi - 1);
            quicksort(pi + 1, high);
        }
    }
    
    // Злиття для сортування злиттям
    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }
    
private:
    vector<T>& arr;
    
    // Допоміжна функція для швидкого сортування
    int partition(int low, int high) {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    // Допоміжна функція для сортування злиттям
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<T> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    
};


//швидкі алгоритми
 
class BucketSorter {
private:
    vector<float> arr;

public:
    
    BucketSorter(const vector<float>& inputArr) : arr(inputArr) {}

    
    void bucketSort() {
        int n = arr.size();
        vector<vector<float>> b(n);

        // Розподіл елементів по кошиках
        for (int i = 0; i < n; ++i) {
            int bucketIndex = n * arr[i]; // Індекс кошика
            b[bucketIndex].push_back(arr[i]);
        }

        // Сортування кожного кошика
        for (auto& bucket : b) {
            sort(bucket.begin(), bucket.end());
        }

        //Об'єднання в єдиний відсортований масив
        int index = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < b[i].size(); ++j) {
                arr[index++] = b[i][j];
            }
        }
    }

    
    void printArray() const {
        cout << "The array after sorting is: " << endl;
        for (const auto& it : arr) {
            cout << it << ' ';
        }
        cout << endl;
    }
};

class CountSorter {
private:
    vector<int> inputArray;
public:
     
    CountSorter(const vector<int>& arr) : inputArray(arr) {}

    
    vector<int> sort() {
        int N = inputArray.size();

         
        int M = *max_element(inputArray.begin(), inputArray.end());

         
        vector<int> countArray(M + 1, 0);

         
        for (int i = 0; i < N; i++) {
            countArray[inputArray[i]]++;
        }

        
        for (int i = 1; i <= M; i++) {
            countArray[i] += countArray[i - 1];
        }

         
        vector<int> outputArray(N);
        for (int i = N - 1; i >= 0; i--) {
            outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
            countArray[inputArray[i]]--;
        }

        return outputArray;
    }

    
    void printArray(const vector<int>& arr) const {
        for (const auto& el : arr) {
            cout << el << " ";
        }
        cout << endl;
    }
};




// Механізм для динамічного підключення нових алгоритмів сортування
template<typename T>
class ISortAlgorithm {
public:
    virtual void sort(vector<T>& arr) = 0;
    //деструктор
    virtual ~ISortAlgorithm() = default;
};
// Реалізація бульбашкового сортування
template<typename T>
class BubbleSortAlg : public ISortAlgorithm<T> {
public:
    void sort(vector<T>& arr) override {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};
// Реалізація швидкого сортування
template<typename T>
class QuickSortAlg : public ISortAlgorithm<T> {
public:
    void sort(vector<T>& arr) override {
        quicksort(arr, 0, arr.size() - 1);
    }

private:
    void quicksort(vector<T>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi - 1);// cортування лівої частини
            quicksort(arr, pi + 1, high);// cортування правої частини
        }
    }
    
    // Метод для поділу масиву на частини
    int partition(vector<T>& arr, int low, int high) {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
};

// Клас для використання нового механізму
template<typename T>
class SortManager {
private:
    vector<T>& data;
    unique_ptr<ISortAlgorithm<T>> algorithm;

public:
    // Конструктор
    SortManager(vector<T>& data) : data(data) {}
//вибір алгоритму сортування
    void setAlgorithm(unique_ptr<ISortAlgorithm<T>> alg) {
        algorithm = move(alg);
    }

    void sort() {
        if (algorithm) {
            algorithm->sort(data);
        } else {
            cout << "Алгоритм сортування не вибраний!" << endl;
        }
    }

    void printArray() const {
        for (const T& elem : data) {
            cout << elem << " ";
        }
        cout << endl;
    }
};








// Клас для списку, який містить елементи у вигляді рядків
class Listt {
public:
    vector<string> items;
    // Метод toString перетворює список у рядковий формат для відображення
        string toString() const {
        string result = "List:\n";
            
            // Для кожного елемента списку додаю рядок з префіксом "-"
            for (const auto& item : items) {
            result += "- " + item + "\n";
        }
        return result;
    }
    // Статичний метод для генерації випадкового списку
       static Listt generateRandomList() {
        Listt list;
        
        // Додаю три випадкові елементи до списку
        list.items.push_back("Item 1");
        list.items.push_back("Item 2");
        list.items.push_back("Item 3");
        return list;
    }
};
class Image {
public:
    string fileName;  // Назва файлу зображення
    string caption;   // Підпис до зображення

    // Метод для перетворення зображення у рядок
        string toString() const {
        return "Image: " + fileName + "\nCaption: " + caption + "\n";
    }

    // Статичний метод для генерації випадкового зображення
    static Image generateRandomImage() {
        Image image;
        image.fileName = "image1.png";  // задана назва файлу
        image.caption = "Random Image Caption";  //  заданий підпис
        return image;
    }
};

// Клас для таблиць
class Table {
public:
     vector<vector<string>> data;
    // Метод для перетворення таблиці у рядковий формат
    string toString() const {
         string result = "Table:\n";
        
        for (const auto& row : data) { //прохід по кожному рядку таблиці
            for (const auto& cell : row) { //  // Прохід по кожній клітинці в рядку
                result += cell + " "; // Додаю клітинку та пробіл між клітинками
                           }
            result += "\n"; // перехід на новий рядок
        }
        return result;
    }

    static Table generateRandomTable() { //Статичний метод для генерації випадкової таблиці
        Table table;
        table.data = {{"Cell1", "Cell2"}, {"Cell3", "Cell4"}};// два рядки таблиці з двома клітинками у кожному
        return table;
    }
};


// Клас для формул
class Formula {
public:
    string expression;  // Рядок для збереження формули
    
    // Метод для перетворення формули у рядковий формат
    string toString() const {
        return "Formula: " + expression + "\n";
    }
    // Статичний метод для генерації випадкової формули
    static Formula generateRandomFormula() {
        Formula formula;
        formula.expression = "E = mc^2"; // Випадкова формула (у даному випадку фіксована)
        return formula;
    }
};

// Клас для представлення посилань на джерела
class Reference {
public:
     string source;        // URL або інше джерело
     string description;   // Опис джерела

    // Метод для перетворення посилання у рядковий формат
     string toString() const {
        return "Reference: " + source + "\nDescription: " + description + "\n";
    }

    // Статичний метод для генерації випадкового посилання
    static Reference generateRandomReference() {
        Reference reference;
        reference.source = "https://example.com";         // Випадкове джерело
        reference.description = "Example Source";         // Випадковий опис
        return reference;
    }
};

// Клас для секцій документа
class Section {
public:
    string title;  // Назва секції
    vector<string> paragraphs;  // Вектор текстових абзаців у секції
    Listt list;  // Список
    Image image;  // Зображення з підписом
    Table table;  // Таблиця з даними
    Formula formula;  //  формула

    // Метод для перетворення секції в рядок (формат для виведення)
    string toString() const {
        string result = "Section: " + title + "\n";
        for (const auto& paragraph : paragraphs) {
            result += paragraph + "\n";
        }
        result += list.toString();
        result += image.toString();
        result += table.toString();
        result += formula.toString();
        return result;
    }

    // Статичний метод для генерації випадкової секції
    static Section generateRandomSection() {
        Section section;
        section.title = "Random Section Title";  // "Випадкова" назва секції
        section.paragraphs.push_back("Random paragraph 1...");  // Додаємо "випадковий" абзац
        section.paragraphs.push_back("Random paragraph 2...");  // Додаємо ще один "випадковий" абзац
        section.list = Listt::generateRandomList();  //   "випадковий" список
        section.image = Image::generateRandomImage();  //  "випадкове" зображення
        section.table = Table::generateRandomTable();  //"випадкова" таблиця
        section.formula = Formula::generateRandomFormula();  //  "випадкова" формула
        return section;   
    }
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
  /*  vector<int> data = {5, 2, 9, 1, 5, 6};

         
        Sorter<int> sorter(data);
    
        cout << "Масив до сортування: ";
        for (int num : data) {
            cout << num << " ";
        }
        cout << endl;
*/
         
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
        
       /*sorter.selectionSort();
       cout << "Масив після сортування вибором: ";
       for (int num : data) {
           cout << num << " ";
       }
       cout << endl;
*/
   /* sorter.quicksort(0, data.size() - 1);
    cout << "Масив після швидкого сортування: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
    */
    
  /*  sorter.mergeSort(0, data.size() - 1);
    cout << "Масив після сортування злиттям: ";
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;*/
     
    
    /* vector<float> v = { 0.3465, 0.632, 0.667, 0.565, 0.1253, 0.667, 0.888 };

     
     BucketSorter sorter(v);

     
     sorter.bucketSort();

    
     sorter.printArray();*/
     
     
    /* vector<int> inputArray = { 4, 3, 12, 1, 5, 5, 3, 9 };
     CountSorter sorter(inputArray);
     vector<int> outputArray = sorter.sort();
     sorter.printArray(outputArray);*/
     
     
  /*   // Генерація випадкового списку
         Listt list = Listt::generateRandomList();

         // Виведення списку на екран
         cout << list.toString();
     
     // Генерація випадкового зображення
        Image img = Image::generateRandomImage();
        
        // Виведення зображення на екран
         cout << img.toString();
    
    // Генерація випадкової таблиці
        Table table = Table::generateRandomTable();
        
        // Виведення таблиці на екран
        cout << table.toString();

    // Генерація випадкової формули
        Formula formula = Formula::generateRandomFormula();
        
        // Виведення формули на екран
         cout << formula.toString();
    
    // Генерація випадкового посилання
       Reference ref = Reference::generateRandomReference();
       
       // Виведення посилання на екран
        cout << ref.toString();
    */
    // Генеруємо випадкову секцію
        Section randomSection = Section::generateRandomSection();
        
        // Виводимо на екран результат перетворення секції у рядок
         cout << randomSection.toString() << std::endl;
    return 0;
    
    
}
