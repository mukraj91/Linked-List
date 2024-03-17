/*
 * Linked_List_Manipulation.cpp
 *
 *  Created on: 11-Aug-2020-2014
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


void displyList_in_reverse(struct Node* node)
{
   if(node == 0) 
   	 return ;

    else {
	
	displyList_in_reverse(node->next);
	cout<<" "<< node->data;
   }
}


int count(struct Node *node)
{
	
	int count = 0;
	
	while(node!= NULL)
	{		
		count++;
		node = node->next;
	}
	
	return count;
}


int recursive_count(struct Node *node)
{
	if(node != NULL)
	return 1 + recursive_count(node->next);
	else
	return 0;
}


int sum_of_all_the_element(struct Node*node)
{
	int sum = 0;
	
	while(node)
	{
		sum = sum + node->data;
		node = node->next;
	}
	return sum;
}


int recursive_sum_of_all_the_element(struct Node*node)
{
	
	if(node!=NULL)
	 return recursive_sum_of_all_the_element(node->next) + node->data; 
	else
	return 0;
}



int main () 
{

  int A[] = {10 , 22 , 30 , 40 , 55};
  
  
  
  create(A, 5);
  
  displyList(first);
  
  displyList_in_reverse(first);
  
  
  // Count
  cout<<endl;
  cout<<"Node Count = "<<count(first)<<endl;
  
  cout<<endl;
  cout<<"Recursive Node Count = "<<recursive_count(first)<<endl;
  

  // Sum of all the elemnt
  
  
  cout<<"Sum of all the element = "<< sum_of_all_the_element(first)<<endl;
  
  cout<<"Recursive sum of all the element = "<< recursive_sum_of_all_the_element(first)<<endl;
  
  

}
