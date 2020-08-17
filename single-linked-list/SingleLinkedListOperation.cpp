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
   void insertAtTailOfMukeshLinkedList();
   void insertAtParticularPositionOfMukeshList();
   void deleteAtSpecificPositionOfMukeshList();

   void sortTheMukeshLinkedList();

   void displayMukeshLinkedList();


};


/*Create a new Mukesh node*/
MukeshNode* MukeshLinkedList::createMukeshNode(int value) {

  struct MukeshNode *newMukeshNode = NULL;

   newMukeshNode = new MukeshNode();

   if (newMukeshNode == NULL) {

      cout<<"MukeshNode is not allocated : " <<endl;

     return 0;

   }
   else {

      newMukeshNode->data = value;
      newMukeshNode->next = NULL;
      return newMukeshNode;
  }

}

/* Insert at beginning*/
void MukeshLinkedList::insetAtBeginningOfMukeshLinkedList() {

  struct MukeshNode *mukeshNode, *temp;

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


void MukeshLinkedList::deleteAtSpecificPositionOfMukeshList() {

   int position, count= 0 , i ;

   if (start == NULL) {

      cout<<"Mukesh LinkedList is empty"<<endl;
      return ;
   }

   cout<<"Enter the position of node to be deleted"<<endl;
   cin>>position;

   MukeshNode *mukeshNode, *temp, *ptr;

   temp = start;

   /*If position is one and if you delete the node at first position.
    * You have to move the node pointer one step ahead  */

   if (position == 1) {

      start = temp->next;
   }
   else {

      /*You will count the number of the node present in Linkedlist*/

      while (temp != NULL) {

         temp = temp->next;

         count++;

      }
        /*You will check the position till the end of the node*/
      if (position > 0 && position <= count) {

         temp = start; // temp will point to start of the node.

         for (i = 1 ; i < position ; i++) {

            ptr = temp; // Ptr Pointer basically joinet the previous node of
                        //  the delete node to next node of position of the node to
                        // deleted from the LinkedList.
            temp  = temp->next;
         }

         ptr->next = temp->next;

      }
      else {

         cout<<"Position out of range"<<endl;
      }

      delete(temp);
      cout<<"Element of the LinkedList deleted"<<endl;
   }

}


void MukeshLinkedList::sortTheMukeshLinkedList() {

   MukeshNode *mukeshNode, *ptr;
   int value;

   /**Check the start of the linkedlist first**/
   if (start == NULL) {

      cout<<"Linkedlist is empty"<<endl;
      return;
}

   mukeshNode = start; // Mukeshnode Point to the first position of the linkedlist.

   while (mukeshNode != NULL) {

      for (ptr = mukeshNode->next; ptr != NULL ; ptr = ptr->next) {

         if (mukeshNode->data > ptr->data) {

            value = ptr->data;

            ptr->data = mukeshNode->data;

            mukeshNode->data = value;

         }
      }

      mukeshNode = mukeshNode->next;
   }

}


/*Display the Linkedlist Node*/
void MukeshLinkedList::displayMukeshLinkedList() {

   struct MukeshNode* mukeshNode;

   if(start == NULL) {

      cout<<"Mukesh LinkedList is empty"<<endl;
      return ;
   }
   else {

       mukeshNode = start;

      while(mukeshNode != NULL) {

         cout<< mukeshNode->data<<"->";
         mukeshNode = mukeshNode->next;
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

      cout<<"02. Insert at last"<<endl;

      cout<<"03. Insert at specific position"<<endl;

      cout<<"04. Delete at specific position"<<endl;

      cout<<"05. Sort the linkedlist"<<endl;

      cout<<"05. Display the nodes"<<endl;


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
        cout<<"2. Insert at last of the Mukesh LinkedList"<<endl;

         mukeshLinkedList.insertAtTailOfMukeshLinkedList();

         break;

      case 3 :
         cout<<"3. Insert at specific position of Mukesh LinkedList"<<endl;

         mukeshLinkedList.insertAtParticularPositionOfMukeshList();

         break;

      case 4 :
         cout<<"4. Delete from specific position"<<endl;

         mukeshLinkedList.deleteAtSpecificPositionOfMukeshList();

         break;

      case 5 :
         cout<<"5. Sort the linkedlist"<<endl;

         mukeshLinkedList.sortTheMukeshLinkedList();
         break;


      case 5 :
         cout <<"4. Display the Mukesh LinkedList"<<endl;

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
