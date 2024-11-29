# doubly-linked-list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
struct Node* prev;
int data;
struct Node* next;
};

typedef struct Node node;

node* createDNode(int value)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->prev = NULL;
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}
node* createDLL()
{
  int sizeDLL;
  printf("Enter size:\n");
  scanf("%d", &sizeDLL);
  
  int tempValue;
  printf("Enter value:\n");
  scanf("%d", &tempValue);
  
  node* head = createDNode(tempValue);
  node* tail = head;
  
  for(int i=1; i<sizeDLL; i++)
  {
    int value;
    printf("Enter value:\n");
    scanf("%d", &value);
    tail->next = createDNode(value);
    tail->next->prev = tail;
    tail = tail->next;
  }
  return head;
}
void traverse(node* head)
{
  if (head == NULL)
  {    
    printf("Doubly linked list is empty.\n");
    return;
  }
  node* iterator = head;
  while(iterator != NULL)
  {
    printf("%d<->",iterator->data);
    iterator = iterator->next;
  }
}

node* deleteNode(node** head, int value)
{ 
  if(*head == NULL)
  {
   printf("Empty DLL");
  }
  if((*head)->data == value)
  {
    node* ptr = (*head);
    *head = (*head)->next;
    free(ptr);
  }
  
  node* current = (*head);
  while(current != NULL && current->data != value)
  {
  current = current->next;
  }
  if (current == NULL)
  {
    printf("Value not found in the list.\n");
    return *head;
  }
  if (current->next == NULL)
  {
    current->prev->next = NULL;
    free(current);
    return *head;
  }
  node* previous = current->prev;
  current = current->next;
  node* temp = current;
  current->prev = previous->next;
  previous->next = current->prev;
  free(current);
  return *head;
}

int main(void)
{
  node* doublyLinkedList = createDLL();
  traverse(doublyLinkedList);
  int value;
  printf("Enter value:\n");
  scanf("%d", &value);
  deleteNode(&doublyLinkedList, value);
  traverse(doublyLinkedList);
  return 0;
}
