/*
 * Linked_List_Manipulation.cpp
 *
 *  Created on: 11-Aug-2020
 *      Author: MukeshRaj
 */

#include<iostream>
using namespace std;



struct Node {

   int data;
   Node *next;

   };


void displyList(Node* node) 
{

   while(node != NULL) {

      cout<<" "<< node->data;
      node = node->next;
   }
   cout<<endl;
}



int main () 
{

   Node *head = NULL;
   Node *second = NULL;
   Node *third = NULL;

   head = new Node();
   second = new Node();
   third = new Node();

   head->data = 1;
   head->next = second;

   second->data = 2;
   second->next = third;

   third->data = 3;
   third->next = NULL;

   displyList(head);

}
