/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/


Node* Reverse(Node *head)
{
    Node * temp = NULL;
    Node *current = head;
    Node * ahead ;
    while(current!=NULL)
    {
        ahead = current -> next;
        current -> next = temp;
        temp = current;
        current = ahead;
    }
    head = temp;
    return head;


}
