#include "Stack.h"
#include <iostream>


// Top element is the first element in a list
// Runtime O(1)

class EmptyStackException{};

struct LinkListNode
{
    int data;
    LinkListNode* next;

    LinkListNode(int da){
        data = da;
        next = nullptr;
    }
};



class LinkListStack
{
    private:
    // data goes here
    LinkListNode* head;
    LinkListNode* tail;
    int count;

    public:
    LinkListStack(void) {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~LinkListStack(void) { 
        // TODO loop through list and delete
        delete[] head;
        delete[] tail;
    }
    
    bool isEmpty(void) { if(size() <= 0) return true; }
    
    int size(void) { return count; }

    LinkListNode* get_head(void){ return head; }
    LinkListNode* get_tail(void){ return tail; }
    LinkListNode* set_head(LinkListNode* new_head){ head = new_head; }
    LinkListNode* set_tail(LinkListNode* new_tail){ tail = new_tail; }
    
    LinkListNode* top() { return tail; }
    
    LinkListNode* pop() {
        if(isEmpty())
            throw EmptyStackException();
        // Loop to node to be popped off
        LinkListNode* current = this->head;
        for(int i = 1; i < count; i++){
            current = current->next;
        }
        // Reset tail to one before the most recent popped off
        tail = set_tail(get_head());
        for(int j = 1; j < count - 1; j++){
            tail = tail->next;
        }
        delete[] current;
        count--;
    }
    
    LinkListNode* push ( LinkListNode* e ){
         if(isEmpty()){
             set_head(e);
             set_tail(e);
             count++;
             return e;
         }
         else {
             LinkListNode* current = get_tail();
             current->next = e;
             set_tail(e); 
             count++;
             return tail;
         }
    }

    void print_stack(void){
        LinkListNode* current = get_head();

        for(int i = 0; i < count; i++){
            std::cout << current->data << "\n";
            current = current->next;
        }

        delete[] current;
    }

};

int main(){
    LinkListStack* LinkList = new LinkListStack();
    LinkListNode* Node1 = new LinkListNode(10);
    LinkListNode* Node2 = new LinkListNode(9);
    LinkListNode* Node3 = new LinkListNode(8);

    LinkList->push(Node1);
    LinkList->push(Node2);
    LinkList->push(Node3);
    LinkList->print_stack();
}
