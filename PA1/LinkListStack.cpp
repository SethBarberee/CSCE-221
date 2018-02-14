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
    int count;

    public:
    LinkListStack(void) {
        head = nullptr;
        count = -1;
    }

    ~LinkListStack(void) { 
        // TODO loop through list and delete
        LinkListNode* current = head;
        LinkListNode* prev = nullptr;
        for(int i = 0; i < count; i++){
            prev = current;
            current = current->next;
            delete[] prev;
        }
        delete[] head;
    }
    
    bool isEmpty(void) { 
        if(count < 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    int size(void) { return count; }
    
    LinkListNode* top() { return head; }
    
    LinkListNode* pop() {
        if(isEmpty()){
            throw EmptyStackException();
        }
        // Get current head;
        LinkListNode* current = head;
        // If it's the only node in the stack, set head to null
        if(!(current->next)){
            head = nullptr;
        }
        else{
            head = current->next;
        }
        delete[] current;
        count--;
    }
    
    void push ( LinkListNode* e ){
         if(isEmpty()){
             head = e;
             count++;
         }
         else {
             LinkListNode* current = head;
             e->next = current;
             head = e; 
             count++;
         }
    }

    void print_stack(void){
        LinkListNode* current = head;

        for(int i = 0; i < count; i++){
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

    for(int i = 0; i < 400000; i++){
        LinkListNode* Node1 = new LinkListNode(i);
        LinkList->push(Node1);
    }

    Timer_program.stop();
    std::cout << "Time taken was " << Timer_program.ms() << " ms" << "\n";
}
