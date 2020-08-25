// Welcome Double Linkedlist

#include <iostream>
#include <stdlib.h>

using namespace std;


// Node class which contain node information
struct MukeshNode {

   int data;

   struct MukeshNode* prev; // Point to Previous node
   struct MukeshNode* next; // Point to Next node

} *start;


// Double Linkedlist operationType

enum DoubleLinkedListOperationType {

   INSERT_AT_BEGINNING = 1 ,
   INSERT_AT_LAST ,
   INSERT_AT_SPECIFIC_POSITION ,

   DISPLAY_THE_LIST = 9 ,

   EXIT_FROM_THE_PROGRAM
};

// MukeshDoubleLinkedList contation all the double linkedlist information

class MukeshDoubleLinkedList {

public:

   MukeshDoubleLinkedList() {

      start = 0; // Initialize the start of the node
   }

   MukeshNode* createNode(int value);

   void insertAtBeginning();
   void displayList();


   enum DoubleLinkedListError {

      DOUBLE_LINKEDLIST_ERROR__INVALIDE = 0 ,
      DOUBLE_LINKEDLIST_ERROR__EMPTY ,
      DOUBLE_LINKEDLIST_ERROR__NOT_FOUND ,
      DOUBLE_LINKEDLIST_ERROR__MEMORY_NOT_ALLOCATED ,
      DOUBLE_LINKEDLIST_ERROR__POSITION_OUT_RANGE
   };

   void handleDoubleLinkedListError(DoubleLinkedListError error)  {

      switch(error) {

      case DOUBLE_LINKEDLIST_ERROR__INVALIDE :
         cout<<endl<<"Double LinkedList Invalide"<<endl;
         break;

      case DOUBLE_LINKEDLIST_ERROR__EMPTY :
         cout<<endl<<"Double LinkedList Empty"<<endl;
         break;

      case  DOUBLE_LINKEDLIST_ERROR__NOT_FOUND :
         cout<<endl<<"Double LinkedList Not Found "<<endl;
         break;

      case DOUBLE_LINKEDLIST_ERROR__MEMORY_NOT_ALLOCATED :
         cout<<endl<<"Double LinkedList Memory Not Allocated"<<endl;
         break;

      case DOUBLE_LINKEDLIST_ERROR__POSITION_OUT_RANGE :
         cout<<endl<<"Double LinkedList Position Out Of Range"<<endl;
         break;

      }
   }

};


/**
 ******************************************************************************
 * Description     : create a new node of the double linkedlist
 * Function name   : createNode
 * Parameters Type : int
 * Return Type     : MukeshNode
 ******************************************************************************
 **/


MukeshNode*MukeshDoubleLinkedList::createNode(int value) {

   MukeshNode *mukeshNode = NULL;

   mukeshNode = new MukeshNode();

   if (mukeshNode == NULL) {
      handleDoubleLinkedListError(DOUBLE_LINKEDLIST_ERROR__MEMORY_NOT_ALLOCATED);
      return 0;
   }
   else {
      mukeshNode->data = value;
      mukeshNode->next = NULL; // Right hand side of the double linkedlist
      mukeshNode->prev = NULL; // Left hand side of the double linkedlist

      return mukeshNode;
   }
}


/**
 ******************************************************************************
 * Description     : Insert the element at the beginning of the linkedlist
 * Function name   : insertAtBeginning
 * Parameters Type : void
 * Return Type     : void
 ******************************************************************************
 **/


void MukeshDoubleLinkedList::insertAtBeginning() {

   MukeshNode *mukeshNode, *temp;

   int value;

   cout<<"Enter the value to insert in node"<<endl;
   cin>>value;

   mukeshNode = createNode(value);

   /*Here we are checking start node is empty or not.
    * If empty then point the newly created node to start of the node.
    * Else Insert the newly created node at first place */
   if (start == NULL) {

      start = mukeshNode;
      start->next = NULL;
      start->prev = NULL;
   }
   else {

      temp = start;       // Hold the start node in temp variable
      start = mukeshNode; // Newly created node become start of the linkedlist
      start->next = temp; // start of next will be the next node of the start.
      start->prev = NULL; // start of prev will be NULL.
   }

   cout<<endl<<"Element inserted at beginning"<<endl;

}


/**
 ******************************************************************************
 * Description     : Need to be display the element of the linkedlist
 * Function name   : displayList
 * Parameters Type : void
 * Return Type     : void
 ******************************************************************************
 **/


void MukeshDoubleLinkedList::displayList() {

   MukeshNode *temp;

   if (start == NULL) {

      handleDoubleLinkedListError(DOUBLE_LINKEDLIST_ERROR__EMPTY);
   }
   else
   {
      temp = start; // Start poin to the temp varible of type double linkedlist;

      while(temp != NULL) {

         cout<<temp->data<<"->";

         temp = temp->next;
      }
   }

   cout<<"NULL"<<endl;
}


/**
 ******************************************************************************
 * Description     : User details operation for double linkedlist
 * Function name   : doubleLinkedListUserDetails
 * Parameters Type : void
 * Return Type     : void
 ******************************************************************************
 **/


void doubleLinkedListUserDetails() {

   cout<<endl<<"*******************************************"<<endl;
   cout<<endl<<"Perform Operation On Double LinkedList"<<endl;
   cout<<endl<<"*******************************************"<<endl;
   cout<<"01. Insert the at beginning. "<<endl;
   cout<<"09. Display the double linkedlist. "<<endl;

   cout<<"10. Exit from the program"<<endl;
}


/**
 ******************************************************************************
 * Description     : Main funtion of the code
 * Function name   : main
 * Parameters Type : void
 * Return Type     : int
 ******************************************************************************
 **/


int main() {

   MukeshDoubleLinkedList mukeshDoubleLinkedList;
   int choice;

   while(1) {

      doubleLinkedListUserDetails();

      cout<<"Enter your choice:  ";
      cin>>choice;

      switch(choice) {

      case INSERT_AT_BEGINNING :

         cout<<endl<<"Insert the element at beginnning of the linkedlist"<<endl;

         mukeshDoubleLinkedList.insertAtBeginning();
         break;

      case DISPLAY_THE_LIST :

         mukeshDoubleLinkedList.displayList();
         break;

      case EXIT_FROM_THE_PROGRAM :
         cout<<endl<<"Exit The Double LinkedList Operation"<<endl;
         exit(1);

      }
   }

   return 0;
}
