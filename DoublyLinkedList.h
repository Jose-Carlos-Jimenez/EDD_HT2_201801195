#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#endif // DOUBLYLINKEDLIST_H
template <class T>
class Node
{

public:
    /*Atributes*/
    T data;
    Node<T> *next;
    Node<T> *previous;
    int position;

    /*Constructor*/
    Node(T data):next(0),previous(0){this->data = data;};

    /*Methods*/

};

template<class T>
class DoublyLinkedList
{

public:
    /*Atributes*/
    int lenght;
    Node<T> *head;
    Node<T> *tail;

    /*Constructor*/
    DoublyLinkedList();

    /*Methods*/
    bool isEmpty();
    void insertFirst(T);
    void insertLast(T);
    void insertAt(T,int);
    void deleteFirst();
    void deleteLast();
    T getNode(int);
};

/*Constructor*/
template <class T> DoublyLinkedList<T>::DoublyLinkedList()
{
    lenght = 0;
}

/*Verify if list is empty*/
template <class T> bool DoublyLinkedList<T>::isEmpty()
{
    return this->lenght==0;
}

/*Insert on head of the list*/
template <class T> void DoublyLinkedList<T>::insertFirst(T value)
{
    Node<T> *newData = new Node<T>(value);
    if(this->isEmpty())
    {
        tail = newData;
        head = newData;
        tail->previous = 0;
        head->next = 0;
    }
    else
    {
        newData->previous = head;
        head->next = newData;
        head = newData;
    }
    lenght++;
}

/*Insert at tail the new node*/
template <class T> void DoublyLinkedList<T>::insertLast(T value)
{
    Node<T> *newData = new Node<T>(value);
    if(isEmpty())
    {
        head = newData;
    }
    else
    {
        tail->previous = newData;
        newData->next = tail;
    }
    tail = newData;
    lenght++;
    newData->position = lenght;
}

/*Delete a node at the first position*/
template <class T> void DoublyLinkedList<T>::deleteFirst()
{
    if(!isEmpty())
    {
        Node<T> *tmp = this->head;
        if(head == tail)
        {
            tail = 0;
        }
        else
        {
            head->next->previous = 0;
        }
        head = head->next;
        tmp->next = 0;
        lenght--;
        delete tmp;
    }
}

/*Delete a node at the last position*/
template <class T> void DoublyLinkedList<T>::deleteLast()
{
    if(!isEmpty())
    {
        Node<T> *tmp = tail;
        if(tail == head)
        {
            head = 0;
        }
        else
        {
            tail->previous->next = 0;
        }
        tail = tail->previous;
        tmp->previous = 0;
        lenght--;
        delete tmp;
    }
}

/*Get a node at n position*/
template <class T> T DoublyLinkedList<T>::getNode(int n)
{
    if(!isEmpty())
    {
        Node<T> *temp = head;
        for(int i = 0 ; i< n ; i++)
        {
            temp = temp->next;
        }
        return  temp->data;
    }
    return 0;
}

/*Insert a node at n position*/
template <class T> void DoublyLinkedList<T>::insertAt(T value,int n)
{
    Node<T> *newData = new Node<T>(value);
    Node<T> *aux = getNode(n);
    newData->previous = aux;
    newData->next = aux;
    if(aux->previous == 0)
    {
        head = newData;
    }
    else
    {
        aux->previous->next = newData;
    }
    aux->previous = newData;

}
