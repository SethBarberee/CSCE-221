#include <iostream>
#include "Timer.cpp"

class EmptyStackException{};

// Top element is the first element in a list
// Runtime O(1)

template <class Type>
struct LinkListNode
{
    Type data;
    LinkListNode<Type>* next;

    LinkListNode<Type>(Type da){
        data = da;
        next = nullptr;
    }
};


template <class Type>
class LinkListStack
{
    private:
    // data goes here
    LinkListNode<Type>* head;
    int count;

    public:
    LinkListStack(void) {
        head = nullptr;
        count = -1;
    }

    ~LinkListStack(void) { 
        LinkListNode<Type>* current = head;
        LinkListNode<Type>* prev = nullptr;
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
    
    LinkListNode<Type>* top() { return head; }
    
    LinkListNode<Type>* pop() {
        if(isEmpty()){
            throw EmptyStackException();
        }
        // Get current head;
        LinkListNode<Type>* current = head;
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
    
    void push ( LinkListNode<Type>* e ){
         if(isEmpty()){
             head = e;
             count++;
         }
         else {
             LinkListNode<Type>* current = head;
             e->next = current;
             head = e; 
             count++;
         }
    }

    void print_stack(void){
        LinkListNode<Type>* current = head;

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
    LinkListStack<int>* LinkList = new LinkListStack<int>();

    for(int i = 0; i < 3000000; i++){
        LinkListNode<int>* Node1 = new LinkListNode<int>(i);
        LinkList->push(Node1);
    }

    Timer_program.stop();
    std::cout << "Time taken was " << Timer_program.ms() << " ms" << "\n";
}
