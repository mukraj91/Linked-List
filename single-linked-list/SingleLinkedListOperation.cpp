/*
 * SingleLinkedListOperation.cpp
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

   void searchTheElementOfMukeshLinkedList();

   void updateTheElementOfMukeshLinkedList();

   void reverseTheMukeshLinkedList();

   void displayMukeshLinkedList();


   enum LinkedListErrorCode {

      LinkedList_Error_Code__INVALIDE = 0 ,
      LinkedList_Error_Code__EMPTY ,
      LinkedList_Error_Code__NOT_FOUND ,
      LinkedList_Error_Code__MOMORY_NOT_ALLOCATED ,
      LinkedList_Error_Code__POSITION_OUT_OF_RANGE

   };


   void toStringLinkedList(LinkedListErrorCode error) {

      switch(error) {

      case LinkedList_Error_Code__EMPTY :

         cout<<endl<<"***LinkedList empty***"<<endl;
         break;

      case LinkedList_Error_Code__NOT_FOUND :

         cout<<endl<<"***LinkedList not found***"<<endl;
         break;

      case LinkedList_Error_Code__MOMORY_NOT_ALLOCATED :

         cout<<endl<<"***Memory is not allocated***"<<endl;
         break;

      case LinkedList_Error_Code__POSITION_OUT_OF_RANGE :

         cout<<endl<<"***LinkedList Position out of range***"<<endl;
         break;

      case LinkedList_Error_Code__INVALIDE :

         cout<<endl<<"***LinkedList invalide***"<<endl;
         break;
      }
   }
};


/*Create a new Mukesh node*/
MukeshNode* MukeshLinkedList::createMukeshNode(int value) {

   struct MukeshNode *newMukeshNode = NULL;

   newMukeshNode = new MukeshNode();

   if (newMukeshNode == NULL) {

      toStringLinkedList(LinkedList_Error_Code__MOMORY_NOT_ALLOCATED);
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
      toStringLinkedList(LinkedList_Error_Code__POSITION_OUT_OF_RANGE);
   }


}


void MukeshLinkedList::deleteAtSpecificPositionOfMukeshList() {

   int position, count= 0 , i ;

   if (start == NULL) {

      toStringLinkedList(LinkedList_Error_Code__EMPTY);

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

         toStringLinkedList(LinkedList_Error_Code__POSITION_OUT_OF_RANGE);
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

      toStringLinkedList(LinkedList_Error_Code__EMPTY);
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


void MukeshLinkedList::searchTheElementOfMukeshLinkedList() {

   int pos = 0 , value;

   MukeshNode *mukeshNode;

   bool flag = false;

   if (start == NULL) {

      toStringLinkedList(LinkedList_Error_Code__EMPTY);
      return ;
   }

   cout<<endl<<"Enter the value to be search"<<endl;
   cin>>value;

   mukeshNode = start;

   while (mukeshNode != NULL) {

      pos++; // Counting the position

      if (mukeshNode->data == value) {

         flag = true;
         cout<<endl<<"Element  "<<value<<"  is found at position  "<<pos<<endl;
      }

      mukeshNode = mukeshNode->next;
   }

   if (!flag) {

      cout<<endl<<"Element "<<value<<" not found in the list"<<endl;
   }

}


void MukeshLinkedList::updateTheElementOfMukeshLinkedList() {

   int value, pos, i;

   MukeshNode* mukeshNode;

   if (start == NULL) {

      toStringLinkedList(LinkedList_Error_Code__EMPTY);
      return ;
   }

   cout<<endl<<"Enter the node position to be updated"<<endl;
   cin>>pos;

   cout<<endl<<"Enter the new value of the node"<<endl;
   cin>>value;

   mukeshNode = start; // Assign the start of the node

   if (pos == 1) { /*If node position is one then insert the new value at the first node*/

      mukeshNode->data = value;

   }
   else {

      for (i = 0 ; i < pos -1 ; i++) {

         if (mukeshNode == NULL) {

            toStringLinkedList(LinkedList_Error_Code__POSITION_OUT_OF_RANGE);
            return ;
         }
         mukeshNode = mukeshNode->next;
      }

      mukeshNode->data = value;
   }

   cout<<endl<<"Node Updated"<<endl;
}

/*Display the Linkedlist Node*/
void MukeshLinkedList::displayMukeshLinkedList() {

   struct MukeshNode* mukeshNode;

   if(start == NULL) {

      toStringLinkedList(LinkedList_Error_Code__EMPTY);
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

void MukeshLinkedList::reverseTheMukeshLinkedList() {

   MukeshNode *prevNode = NULL, *currentNode = NULL, *nextNode = NULL;


   if (start == NULL) {

      toStringLinkedList(LinkedList_Error_Code__EMPTY);
      return ;

   }

   if (start->next == NULL) {

      return ; // Because only one node available
   }

   currentNode = start;

   while (currentNode != NULL) {

      nextNode = currentNode->next;

      currentNode->next = prevNode;

      prevNode = currentNode;

      currentNode = nextNode;

   }

   start = prevNode;

   cout<<endl<<"LinkedList Reversed Successful done"<<endl;

}

void linkedListUserDetails() {

   cout <<endl<<"================================"<<endl;
   cout <<endl<<"Perform operation on Mukesh SingleLinkedList"<<endl;
   cout <<endl<<"================================"<<endl;

   cout<<"01. Insert at beginning"<<endl;

   cout<<"02. Insert at last"<<endl;

   cout<<"03. Insert at specific position"<<endl;

   cout<<"04. Delete at specific position"<<endl;

   cout<<"05. Sort the linkedlist"<<endl;

   cout<<"06. Search the element in the linkedlist"<<endl;

   cout<<"07. Update node element with new value"<<endl;

   cout<<"08. Reverse the Linklist"<<endl;

   cout<<"09. Display the nodes"<<endl;

   cout<<"10. Exit the LinkedList Operation"<<endl;

}

/* Main function*/
int main() {

   MukeshLinkedList mukeshLinkedList;
   int choice;

   enum LinkedListOperationType {

      INSERT_AT_BEGINNING = 1,
      INSERT_AT_LAST,
      INSERT_AT_SPECIFIC_POSITION,
      DELETE_AT_SPECIFIC_POSITION,
      SORT_THE_LINKEDLIST,
      SEARCH_THE_ELEMENT_IN_LINKEDLIST,
      UPDATE_NODE_VALUE_WITH_NEW_VALUE,
      REVERSE_THE_LINKEDLIST,
      DISPLAY_THE_LINKEDLIST,
      EXIT_FROM_PROGRAM
   };


   while (1) {

      linkedListUserDetails();

      cout<<"Enter your choice:";
      cin>>choice;

      switch(choice)
      {

      case INSERT_AT_BEGINNING :
         cout<<"1. Insert at beginning of the Mukesh LinkedList"<<endl;

         mukeshLinkedList.insetAtBeginningOfMukeshLinkedList();

         break;

      case INSERT_AT_LAST :
         cout<<"2. Insert at last of the Mukesh LinkedList"<<endl;

         mukeshLinkedList.insertAtTailOfMukeshLinkedList();

         break;

      case INSERT_AT_SPECIFIC_POSITION :
         cout<<"3. Insert at specific position of Mukesh LinkedList"<<endl;

         mukeshLinkedList.insertAtParticularPositionOfMukeshList();

         break;

      case DELETE_AT_SPECIFIC_POSITION :
         cout<<"4. Delete from specific position"<<endl;

         mukeshLinkedList.deleteAtSpecificPositionOfMukeshList();

         break;

      case SORT_THE_LINKEDLIST :
         cout<<"5. Sort the linkedlist"<<endl;

         mukeshLinkedList.sortTheMukeshLinkedList();
         break;


      case SEARCH_THE_ELEMENT_IN_LINKEDLIST :

         cout<<"6. Search the element in the linkedlist"<<endl;

         mukeshLinkedList.searchTheElementOfMukeshLinkedList();
         break;


      case UPDATE_NODE_VALUE_WITH_NEW_VALUE :

         cout<<"7. Update node element with new value"<<endl;

         mukeshLinkedList.updateTheElementOfMukeshLinkedList();
         break;


      case REVERSE_THE_LINKEDLIST:

         cout<<"8. Reverse the linkedlist"<<endl;

         mukeshLinkedList.reverseTheMukeshLinkedList();
         break;

      case DISPLAY_THE_LINKEDLIST :
         cout <<"9. Display the Mukesh LinkedList"<<endl;

         mukeshLinkedList.displayMukeshLinkedList();

         break;

      case EXIT_FROM_PROGRAM :
         cout<<"10. Exit the Linkedlist Operation"<<endl;

         exit(1);

         break;

      default :
         cout <<"No choice is maching please enter correct choice"<<endl;

         break;

      } // switch close

   } // while close

} // main close
