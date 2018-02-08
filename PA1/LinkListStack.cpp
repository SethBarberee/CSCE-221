#include <iostream>
#include "Timer.cpp"

class EmptyStackException{};

// Top element is the first element in a list
// Runtime O(1)

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
        count = -1;
    }

    ~LinkListStack(void) { 
        // TODO loop through list and delete
        delete[] head;
        delete[] tail;
    }
    
    bool isEmpty(void) { if(size() < 0) return true; }
    
    int size(void) { return count; }

    LinkListNode* get_head(void){ return head; }
    LinkListNode* get_tail(void){ return tail; }
    void set_head(LinkListNode* new_head){ head = new_head; }
    void set_tail(LinkListNode* new_tail){ tail = new_tail; }
    
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
        set_tail(get_head());
        for(int j = 1; j < count - 1; j++){
            tail = tail->next;
        }
        delete[] current;
        count--;
    }
    
    void push ( LinkListNode* e ){
         if(isEmpty()){
             set_head(e);
             set_tail(e);
             count++;
         }
         else {
             LinkListNode* current = get_tail();
             current->next = e;
             set_tail(e); 
             count++;
         }
    }

    void print_stack(void){
        LinkListNode* current = get_head();

        for(int i = 0; i <= count; i++){
            std::cout << current->data << "\n";
            current = current->next;
        }

        delete[] current;
    }

};

int main(){
    Timer Timer_program = Timer();
    Timer_program.start();
    LinkListStack* LinkList = new LinkListStack();

    for(int i = 0; i < 100000; i++){
        LinkListNode* Node1 = new LinkListNode(i);
        LinkList->push(Node1);
    }
    Timer_program.stop();
    std::cout << "Time taken was " << Timer_program.ms() << " ms" << "\n";
}
