//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#

class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     set<int> s;
     Node* p = head;
     Node* q = NULL;
     while(p){
         auto it = s.find(p->data);
         if(it == s.end()){
             s.insert(p->data);
             q = p;
             p = p->next;
         }
            
        else{
            q->next = p->next;
            p = p->next;
        }
     }
      return head;  
    }
};
