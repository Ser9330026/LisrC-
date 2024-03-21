#include <iostream>
#include <string>

template<typename T>
class List
{
private:
    template<typename T>
    class Node //Создание узла
    {
    public:
        Node* pNext;//Указатель на следующий элемент
        T data;
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;//Количество элементов в односвязном списке
    Node<T> *head;//Голова
public:
    List();
    ~List();

    void pop_front();
    void push_back(T data);
    void clear();
    int getSize() { return Size; }
    void push_front(T data);
    void insert(T value, int index);
    void removeAt(int index);
    void pop_back();

    T& operator[](const int index);
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

//удаление элементов из списка
template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;

    Size--;
}

//Добавление элементов в конец списка
template<typename T>
void List<T>::push_back(T data)//data - данные, которые мы будем добавлять в список
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

//Очистка списка
template<typename T>
void List<T>::clear()
{
    while(Size)
    {
        pop_front();
    }
}

//Добавлять элементы в начало списка
template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

//Вставка элементов в список по индексу
template<typename T>
void List<T>::insert(T value, int index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
        previous = previous->pNext;
        }
        Node<T>* newNode = new Node<T>(value, previous->pNext);
        previous->pNext = newNode;
    }
    Size++;
}

//Удаление элемента по индексу
template<typename T>
void List<T>::removeAt(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }    
}

//Удаление последнего элемента списка
template<typename T>
void List<T>::pop_back()
{
    removeAt(Size - 1);
}


int main()
{
    setlocale(LC_ALL, "rus");
    List<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22);
    lst.push_front(33);
    std::cout << lst.getSize() << std::endl;
    for (int i = 0; i < lst.getSize(); i++) {
        std::cout << lst[i] << ' ';
    }
    std::cout << std::endl;

    

    lst.pop_front();
    for (int i = 0; i < lst.getSize(); i++) {
        std::cout << lst[i] << ' ';
    }
    std::cout << std::endl;
    
    lst.insert(33, 1);
    for (int i = 0; i < lst.getSize(); i++) {
        std::cout << lst[i] << ' ';
    }
    std::cout << std::endl;

    lst.removeAt(1);
    for (int i = 0; i < lst.getSize(); i++) {
        std::cout <<  lst[i] << ' ';
    }
    std::cout << std::endl;

    lst.pop_back();
    for (int i = 0; i < lst.getSize(); i++) {
        std::cout << lst[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << lst[2] << std::endl;
    lst.clear();
    for (int i = 0; i < lst.getSize(); i++) {
        std::cout << "Количество элементов: " << lst[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

