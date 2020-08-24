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

   EXIT_FROM_THE_PROGRAM = 10
};

// MukeshDoubleLinkedList contation all the double linkedlist information

class MukeshDoubleLinkedList {

public:

   MukeshDoubleLinkedList() {

      start = 0; // Initialize the start of the node
   }

   MukeshNode* createNode(int value);

   void insertAtBeginning();


   enum DoubleLinkedListError {

      DOUBLE_LINKEDLIST_ERROR__INVALIDE = 0 ,
      DOUBLE_LINKEDLIST_ERROR__EMPTY ,
      DOUBLE_LINKEDLIST_ERROR__NOT_FOUND ,
      DOUBLE_LINKEDLIST_ERROR__MEMORY_NOT_ALLOCATED ,
      DOUBLE_LINKEDLIST_ERROR__POSITION_OUT_RANGE
   };

   void toStringDoubleLinkedList(DoubleLinkedListError error)  {

      switch(error) {

      case DOUBLE_LINKEDLIST_ERROR__INVALIDE :
         cout<<"Double LinkedList Invalide"<<endl;
         break;

      case DOUBLE_LINKEDLIST_ERROR__EMPTY :
         cout<<"Double LinkedList Empty"<<endl;
         break;

      case  DOUBLE_LINKEDLIST_ERROR__NOT_FOUND :
         cout<<"Double LinkedList Not Found "<<endl;
         break;

      case DOUBLE_LINKEDLIST_ERROR__MEMORY_NOT_ALLOCATED :
         cout<<"Double LinkedList Memory Not Allocated"<<endl;
         break;

      case DOUBLE_LINKEDLIST_ERROR__POSITION_OUT_RANGE :
         cout<<"Double LinkedList Position Out Of Range"<<endl;
         break;

      }
   }

};

MukeshNode*MukeshDoubleLinkedList::createNode(int value) {

   MukeshNode *mukeshNode;

   return mukeshNode;


}

void MukeshDoubleLinkedList::insertAtBeginning() {

   int value;

   cout<<"Enter the value to insert in node"<<endl;
   cin>>value;

   MukeshNode *temp = createNode(value);

   cout<<"Created Node :" <<temp<<endl;

}


// For user details

void doubleLinkedListUserDetails() {

   cout<<endl<<"*******************************************"<<endl;
   cout<<endl<<"Perform Operation On Double LinkedList"<<endl;
   cout<<endl<<"*******************************************"<<endl;
   cout<<"01. Insert the at beginning"<<endl;

   cout<<"10. Exit from the program"<<endl;
}

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

      case EXIT_FROM_THE_PROGRAM :
         cout<<endl<<"Exit The Double LinkedList Operation"<<endl;
         exit(1);

      }
   }

   return 0;
}
