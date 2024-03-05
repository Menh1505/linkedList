#include "linkedlist.h"
#include <iostream>
using namespace std;

linkedlist::linkedlist()
{
    // ctor
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}

linkedlist::~linkedlist()
{
    // dtor
}
void linkedlist::InsertFirst(element *e)
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        e->Setpointer(this->head);
        this->head = e;
    }
    this->nNum++;
}
void linkedlist::InsertTail(element *e)
{
    if (this->head == nullptr)
        this->head = this->tail = e;
    else
    {
        this->tail->Setpointer(e);
        this->tail = e;
    }
    this->nNum++;
}
void linkedlist::Travel()
{
    element *p = this->head;
    while (p != nullptr)
    {
        cout << p->Getdata() << "\t";
        p = p->GetPointer();
    }
}
bool linkedlist::DeleteFirst()
{
    if (this->head == nullptr)
        return false;
    else
    {
        element *p = this->head;
        this->head = this->head->GetPointer();
        delete p;
        return true;
    }
}
bool linkedlist::DeleteTail()
{
    if (this->tail == nullptr)
        return false;
    else
    {
        element *p = this->head;
        while (p->GetPointer() != this->tail)
            p = p->GetPointer();
        this->tail->Setpointer(p);
        p = p->GetPointer();
        delete p;
        this->nNum--;
        return true;
    }
}
bool linkedlist::RemoveAll()
{
    if (this->head == nullptr)
        return false;
    else
    {
        do
        {
            element *tmp = this->head;
            this->head = this->head->GetPointer();
            delete tmp;
        } while (this->head != this->tail);
        delete this->head;
    }
    return true;
}
int linkedlist::SumList()
{
    int res = 0;
    element *p = this->head;
    while (p != nullptr)
    {
        res += p->Getdata();
        p = p->GetPointer();
    }
    return res;
}
int linkedlist::Max()
{
    element *p = this->head;
    int res = p->Getdata();
    p = p->GetPointer();
    while (p != nullptr)
    {
        if (res < p->Getdata())
        {
            res = p->Getdata();
        }
        p = p->GetPointer();
    }
    return res;
}
int linkedlist::Count()
{
    int res = 0;
    element *p = this->head;
    while (p != nullptr)
    {
        res++;
        p = p->GetPointer();
    }
    return res;
}
bool linkedlist::Add(element *pos, element *val)
{
    bool success = false;
    element *p = this->head;
    while (p != nullptr)
    {
        if (p->Getdata() == pos->Getdata())
        {
            success = true;
            val->Setpointer(p->GetPointer());
            p->Setpointer(val);
            break;
        }
        p = p->GetPointer();
    }
    if(success)
        this->nNum++;
    return success;
}
bool linkedlist::Delete(element* pos)
{
    bool success = false;
    element* p = this->head;
    while (p != nullptr)
    {
        if(p->GetPointer()->Getdata() == pos->Getdata())
        {
            element* tmp = p->GetPointer();
            if(p->GetPointer()->GetPointer() != nullptr)
            {
                p->Setpointer(tmp->GetPointer());
            }
            else
            {
                p->Setpointer(nullptr);
            }
            delete tmp;
            success = true;
            break;
        }
        p = p->GetPointer();
    }
    if(success)
        this->nNum--;
    return success;
}