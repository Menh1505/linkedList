#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
    linkedlist *list_ = new linkedlist();
    element *e;
    e = new element(9);
    list_->InsertTail(e);
    e = new element(10);
    list_->InsertTail(e);
    e = new element(8);
    list_->InsertTail(e);
    e = new element(11);
    list_->InsertTail(e);
    e = new element(20);
    list_->InsertTail(e);
    e = new element(3);
    list_->InsertTail(e);

    cout << "\n================================\n";
    cout << list_->Count();
    cout << "\n===============================\n";
    cout << list_->Max();
    cout << "\n===============================\n";
    list_->Travel();
    list_->DeleteFirst();
    cout << "\n================================\n";
    list_->Travel();
    cout << "\n================================\n";
    list_->Delete(new element(20));
    list_->Travel();
    cout << "\n================================\n";
    list_->RemoveAll();
    list_->Travel();
    return 0;
}