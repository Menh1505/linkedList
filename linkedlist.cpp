#include "linkedlist.h"
#include <iostream>
using namespace std;

linkedlist::linkedlist()
{
    //ctor
    this->head=nullptr;
    this->tail=nullptr;
    this->nNum=0;
}

linkedlist::~linkedlist()
{
    //dtor
}
void linkedlist::InsertFirst(element* e){
      if(this->head==nullptr)
        this->head=this->tail=e;
        else{
            e->Setpointer(this->head);
            this->head=e;
        }
       this->nNum++;

}
 void linkedlist::InsertTail(element*e){
     if(this->head==nullptr)
        this->head=this->tail=e;
        else{
            this->tail->Setpointer(e);
            this->tail=e;
        }
     this->nNum++;
 }
void linkedlist::Travel(){
     element* p=this->head;
     while(p!=nullptr){
        cout<<p->Getdata()<<"\t";
        p=p->GetPointer();
     }
}
  bool linkedlist::DeleteFirst(){
      if(this->head==nullptr) return false;
      else{
      element*p=this->head;
      this->head=this->head->GetPointer();
      delete p;
      return true;
      }
  }
