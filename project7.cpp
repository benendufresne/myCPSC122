/*
Class: CPSC 122-01
Paul De Palma
GU Username: depalma
Submitted By: Paul De Palma
GU Username: depalma
File Name: ex26.h
Header file for a linked list with head and tail pointers  
To Build: g++ ex26Tst.cpp ex26.cpp 
To Execute: ./a.out
*/
#include "project7.h"
#include <iostream>


   List1::List1()
   {
       head = tail = NULL;
       length = 0;
   }

   List1::~List1()
   {
       node* del = head;
       while (del!= NULL)
       {
           node* tmp = del->next;
           delete del;
           del = tmp;
           length--;
       }
   }

   /*
   pre: an instance of lists exists
   post: returns true if list is empty, false otherwise
   */ 
   bool List1::IsEmpty() const
   {
       return true;
   }

   /*
   pre: an instance of list exists
   post: returns length of the list 
   */
   int List1::GetLength() const
   {
       return length;
   }

   /*
   pre: an instance of list exists
   post: newItem is at the head of the list 
   */
   void List1::PutItemH(const itemType newItem)
   {
       node* tmp = new node;
       tmp->item = newItem;
       tmp->next = head;
       head = tmp;
       length++;
       tmp = NULL;
   }

   /*
   pre: an instance of list exists and is not empty
   post: Returns the contents of the head of the list. 
   */
   itemType List1::GetItemH() const
   {
       return head->item;
   }

   /*
   pre: an instance of list exists and is not empty
   post: head of the list is deleted 
   */
   void List1::DeleteItemH()
   {
       node* tmp = head->next;
       delete head;
       head = tmp;
       length--;
   }

   /*
   pre: an instance of list exists
   post: newItem is at the tail of the list 
   */
   void List1::PutItemT(const itemType newItem)
   {
       node* tmp = new node;
       tmp->item = newItem;
       tail->next = tmp;
       tmp->next = NULL;
       tail = tmp;
       tmp = NULL;
       length++;
   }

   /*
   pre: an instance of list exists and is not empty
   post: Returns the contents of the tail of the list. 
   */
   itemType List1::GetItemT() const
   {
       return tail->item;
   }

   /*
   pre: an instance of list exists and is not empty
   post: tail of the list is deleted 
   */
   void List1::DeleteItemT()
   {
        node* tmp = head;
        while (tmp->next != tail)
            tmp = tmp->next;
        delete tail;
        tail = tmp;
        tmp = NULL;
        length--;
   }

   /*
   pre: an instance of list exists and is not empty
   post: contents of list nodes are displayed on subsequent lines 
   */
   void List1::Print() const
   {
        node* tmp = head;
        while (tmp != tail)
        {
            std::cout << tmp->item;
            tmp = tmp->next;
        }
   }
  
   /*
   pre: an instance of list exists and is not empty
   post: returns the number of nodes in the list that store target 
   */
   int List1::FindItem(const itemType target) const
   {
       node* tmp = head;
       int count = 0;
       while (tmp != NULL)
       {
           if (tmp->item == target)
            count++;
           tmp = tmp->next;
       }
       return count;
   }

   /*
   pre:  an instance of List exists and is not empty 
   post: deletes all nodes that store target.  Returns
         the number of nodes deleted 
   */
   int List1::DeleteItem(const itemType target)
   {
       node* tmp = head;
       int count = 0;
       if (head->item == target)
       {
           DeleteItemH();
           count++;
       }
       while (tmp != NULL)
       {
           if (tmp->next->item == target)
           {
               node* del = tmp->next;
               tmp->next = del->next;
               delete del;
               del = NULL; 
               length--;
               count++;
           }
           tmp = tmp->next;
       }
       return count;
   }