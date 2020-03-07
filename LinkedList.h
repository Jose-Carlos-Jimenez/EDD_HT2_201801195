#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#endif // LINKEDLIST_H
template <class T>
class Node
{

public:
    /*Atributes*/
    T data;
    Node<T> *next;

    /*Constructor*/
    Node(T data):next(0){this->data = data;};

    /*Methods*/

};

template <class T>
class LinkedList
{
public:
    /*Atributes*/
    Node<T> *head;
    Node<T> *tail;
    int size;

    /*Constructor*/
    LinkedList();

    /*Methods*/
    void addLast(T);
    void addFirst(T);
    void deleteLast();
    void deleteFirst();
    void setEmpty();
    bool isEmpty();
    Node<T>* elementAt(int);
};

template <class T> void LinkedList<T>::setEmpty()
{
    this->head = 0;
}

template <class T> LinkedList<T>::LinkedList()
{
    head = 0;
    size = 0;
}

template <class T> Node<T>* LinkedList<T>::elementAt(int n)
{
    if(n < this->size)
    {
        Node<T> *tmp = this->head;
        for(int i = 0; i < n; i++)
        {
            tmp = tmp->next;
        }
        return  tmp;
    }
    return 0;
}

template <class T> bool LinkedList<T>::isEmpty()
{
    return size == 0;
}

template <class T> void LinkedList<T>::addLast(T value)
{
    Node<T> *newData = new Node<T>(value);
    if(isEmpty())
    {
        this->tail = newData;
    }
    else
    {
        this->head->next = newData;
    }
    this->head = newData;
    size++;
}

template <class T> void LinkedList<T>::addFirst(T value)
{
    Node<T> *newData = new Node<T>(value);
    if(isEmpty())
    {
        head = tail = newData;
    }
    else
    {
        newData->next =  head;
        head = newData;
    }
    size++;
}

template <class T> void LinkedList<T>::deleteLast()
{
    if(!isEmpty()&& size > 1)
    {
        Node<T> *tmp = this->elementAt(size-2);
        delete *tail;
        tail = tmp;
        size--;
    }
    else if(size == 1)
    {
        delete *tail;
        delete *head;
        tail = head = 0;
        size--;
    }
}
