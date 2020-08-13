/*
 * InsertAtBeginning.cpp
 *
 *  Created on: 12-Aug-2020
 *      Author: MukeshRaj
 */

#include<iostream>
#include<stdlib.h>

using namespace std;

/* MukeshNode Declaration*/
struct MukeshNode {

   int data;
   struct MukeshNode *next;
} *start;


/*MukeshLinkedList Class Declation*/
class MukeshLinkedList {

public:

   // MukeshLinkedList Constructor
   MukeshLinkedList() {

      start = 0;
   }

   MukeshNode* createMukeshNode(int data);
   void insetAtBeginningOfMukeshLinkedList();
<<<<<<< HEAD
   void insertAtTailOfMukeshLinkedList();
   void insertAtParticularPositionOfMukeshList();
=======
>>>>>>> 6236b28... single linked list opeartion
   void displayMukeshLinkedList();


};


/*Create a new Mukesh node*/
MukeshNode* MukeshLinkedList::createMukeshNode(int value) {

<<<<<<< HEAD
  struct MukeshNode *newMukeshNode = NULL;
=======
   MukeshNode *newMukeshNode = NULL;
>>>>>>> 6236b28... single linked list opeartion
   newMukeshNode = new MukeshNode();

   if (newMukeshNode == NULL) {

<<<<<<< HEAD
      cout<<"MukeshNode is not allocated : " <<endl;
=======
      cout<<"MukeshNode is empty : " <<endl;
>>>>>>> 6236b28... single linked list opeartion
      return 0;

   }
   else {

      newMukeshNode->data = value;
      newMukeshNode->next = NULL;
      return newMukeshNode;
<<<<<<< HEAD
}
=======

   }

   return newMukeshNode;
>>>>>>> 6236b28... single linked list opeartion

}

/* Insert at beginning*/
void MukeshLinkedList::insetAtBeginningOfMukeshLinkedList() {

<<<<<<< HEAD
  struct MukeshNode *mukeshNode, *temp;
=======
   MukeshNode *mukeshNode, *temp;
>>>>>>> 6236b28... single linked list opeartion
   int value;

   cout<<"Enter the value to be inserted"<<endl;
   cin>>value;

   mukeshNode = createMukeshNode(value);

   if (start == NULL) {

      start = mukeshNode;
      start->next = NULL;

   }
   else {

      temp = start;
      start = mukeshNode;
      start->next = temp;
   }

   cout<<"Element inserted at beginning"<<endl;

}

<<<<<<< HEAD

void MukeshLinkedList::insertAtTailOfMukeshLinkedList() {
  struct MukeshNode *mukeshNode, *temp;
   int value;
   cout<<"Enter the value to be insert"<<endl;
   cin>>value;

   mukeshNode = createMukeshNode(value);

   /**
    * If there is no any element in Linkedlist
    * First element itself is called last element
    * that's why I have checking in if condition if start
    * is NULL then make start as last element, which is nothing but
    * first element
    **/

    if (start == NULL) {

       start = mukeshNode;
       start->next = NULL;
    }
    else {

     temp = start;

      while(temp->next != NULL) {

         temp = temp->next;
      }

      mukeshNode->next = NULL; // Last node next should be NULL
      temp->next = mukeshNode;
   }
      cout<<"Element inserted at last"<<endl;

}


void MukeshLinkedList::insertAtParticularPositionOfMukeshList() {

   struct MukeshNode* mukeshNode, *temp, *ptr;
   int value, position, count = 0, i;
   cout<<"Enter the element to be inserted"<<endl;
   cin>>value;
   mukeshNode = createMukeshNode(value);
   cout<<"Enter the position at which node to be inserted"<<endl;
   cin>>position;

   temp = start;

   /**
    * Count the number of the node present inside linkedlist
    **/
   while(temp != NULL) {
      temp = temp->next;
      count++;
   }

   /**
    * If the position is one, then insert the node at first place
    * **/

if (position == 1) {

   if (start == NULL) {

      start = mukeshNode;
      start->next = NULL;
   }
   else {
          ptr = start;
          start = mukeshNode;
          start->next = ptr;
   }
}
else if (position > 1 && position <= count) {

temp = start;

for (i = 1 ; i < position ; i++) {

   ptr = temp;
   temp = temp->next;

}

ptr->next = mukeshNode;
mukeshNode->next = temp;

}
else {
   cout<<"Position isout of range"<<endl;
}


}


/*Display the Linkedlist Node*/
void MukeshLinkedList::displayMukeshLinkedList() {

   struct MukeshNode* mukeshNode;
=======
/*Display the Linkedlist Node*/
void MukeshLinkedList::displayMukeshLinkedList() {

   MukeshNode* temp;
>>>>>>> 6236b28... single linked list opeartion

   if(start == NULL) {

      cout<<"Mukesh LinkedList is empty"<<endl;
      return ;
   }
   else {
<<<<<<< HEAD

      mukeshNode = start;

      while(mukeshNode != NULL) {

         cout<< mukeshNode->data<<"->";
         mukeshNode = mukeshNode->next;
=======
      temp = start;

      while(temp != NULL) {

         cout<< temp->data<<"->";
         temp = temp->next;
>>>>>>> 6236b28... single linked list opeartion
      }

   }

   cout<<"NULL"<<endl;
}


/* Main function*/
int main() {

   MukeshLinkedList mukeshLinkedList;
   int choice;

   while (1) {

      cout <<endl<<"================================"<<endl;
      cout <<endl<<"Perform operation on Mukesh SingleLinkedList"<<endl;
      cout <<endl<<"================================"<<endl;

      cout<<"01. Insert at beginning"<<endl;

<<<<<<< HEAD
      cout<<"02. Insert at last"<<endl;

      cout<<"03. Insert at specific position"<<endl;

      cout<<"04. Display the nodes"<<endl;
=======
      cout<<"02. Display the nodes"<<endl;
>>>>>>> 6236b28... single linked list opeartion

      cout<<"10. Exit the LinkedList Operation"<<endl;

      cout<<"Enter your choice:";
      cin>>choice;

      switch(choice)
      {

      case 1 :
         cout<<"1. Insert at beginning of the Mukesh LinkedList"<<endl;

         mukeshLinkedList.insetAtBeginningOfMukeshLinkedList();

         break;

      case 2 :
<<<<<<< HEAD
         cout<<"2. Insert at last of the Mukesh LinkedList"<<endl;

         mukeshLinkedList.insertAtTailOfMukeshLinkedList();

         break;

      case 3 :
         cout<<"3. Insert at specific position of Mukesh LinkedList"<<endl;

         mukeshLinkedList.insertAtParticularPositionOfMukeshList();

         break;

      case 4 :
         cout <<"4. Display the Mukesh LinkedList"<<endl;
=======
         cout <<"2. Display the Mukesh LinkedList"<<endl;
>>>>>>> 6236b28... single linked list opeartion

         mukeshLinkedList.displayMukeshLinkedList();

         break;

      case 10 :
         cout<<"Exit the Linkedlist Operation"<<endl;

         exit(1);

         break;

      default :
         cout <<"No choice is maching please enter correct choice"<<endl;

         break;

      } // switch close

   } // while close

} // main close
