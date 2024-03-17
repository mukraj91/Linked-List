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
   struct Node *next;

}*first = NULL; // Global varible of type struct Node



void create(int A[], int n)
{
	int i;
	
	struct Node *temp, *last;
	
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;
	
	
	for(i = 1 ; i<n ; i++)
	{
		temp  = (struct Node*)malloc(sizeof(struct Node));
		temp->data = A[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
	
}

void displyList(struct Node* node) 
{

   while(node != NULL) {

      cout<<" "<< node->data;
      
      node = node->next;
   }
   cout<<endl;
}



int main () 
{

  int A[] = {10 , 22 , 30 , 40 , 55};
  
  
  
  create(A, 5);
  
  displyList(first);
  

}
