#include<iostream>
#include "linkedList.h"
using namespace std;

int main()
{
    linkedList<int>* newList = new linkedList<int>;
    newList->insert(1);
    newList->insert(2);
    newList->insert(3);
    cout << newList->getItemAtIndex(1) << endl;
    newList->removeItemAtIndex(1);
    cout << newList->getItemAtIndex(1) << endl;
    return 0;
}
