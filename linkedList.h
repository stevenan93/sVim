#ifndef _linked_lists
#define _linked_lists
/*
Written by Steven An, Computer Engineering B.S Sacramento State
Created February 23rd, 2015

using the bare necessities of C++
hopefully may be useful to anyone out there. As long as credit is due 
you can use it for whatever you like. Implements a standard linked list along with 
functions. General features are being added on as they come to mind
As of creation, a singly linked list comes to mind. will break that barrier
later with doubly, etc. 
*/

template <class T>
class linkedList
{
    private:
        struct node
	{
	    T item;
	    node* next;
        node* prev;
    };
	int itemCount;
	node* head;
    node* tail;

    public:
        linkedList();   //ctor
        ~linkedList();  //dtor
    	int getItemCount() const;
        void insert(T valIn);
        T removeItemAtIndex(int index);
        T getItemAtIndex(int index) const;
        T getItemAtHead() const;
};

template <class T>
T linkedList<T>::removeItemAtIndex(int index)
{
    if(index > getItemCount() || index < 0)
    {
        node* newNode = new node;
        newNode->item = "FAIL";
        return newNode->item;
    }
    node* curPtr = head->next;
    for(int i = 0 ;i < index; i++)
    {
        curPtr = curPtr->next;
    }
    curPtr->prev->next = curPtr->next;
    curPtr->next->prev = curPtr->prev;
    T item = curPtr->item;
    delete curPtr;
    --itemCount;
    return item;
}

template <class T>
int linkedList<T>::getItemCount() const
{
    return itemCount;
}

template <class T>
linkedList<T>::linkedList()
{
    itemCount = 0;
    //initialize sentinels
    head = new node;
    tail = new node;
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;
    	
}

template <class T>
void linkedList<T>::insert(T valIn)
{
    //creates new item and inserts into node
    node* newNode = new node;
    newNode->item = valIn;

    //linked node to list
    node* temp = tail->prev;
    tail->prev = newNode;
    temp->next = newNode;
    newNode->next = tail;
    newNode->prev = temp;


    ++itemCount;
}

template <class T>
T linkedList<T>::getItemAtIndex(int index) const
{
    if(index >= itemCount)
    {
        std::cout << "Index out of range\n";
        return 0;
    }
    node* curPtr = head->next;
    for(int i = 0; i < index; i++)
    {
        curPtr = curPtr->next;      
    }
    return curPtr->item;
}

template <class T>
T linkedList<T>::getItemAtHead() const
{
    return head->next->item;
}

template <class T>
linkedList<T>::~linkedList()
{
    node* cur = head->next;
    node* temp = NULL;
    for(int i = 0; i < itemCount; i++)
    {
        temp = cur->next;
        delete cur;
        cur = temp;               
    } 
    delete head;
    delete tail;
}
#endif
