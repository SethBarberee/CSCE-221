#ifndef DEQUE_H
#define DEQUE_H

#include <exception>

class Empty_Deque_Exception{};

using namespace std;

template <class Type>
struct LinkedListNode{
    Type data;
    LinkedListNode<Type>* prev;
    LinkedListNode<Type>* next;

    LinkedListNode<Type>(Type a){
        data = a;
        prev = nullptr;
        next = nullptr;
    }
};

template <class Type>
class Deque
{
private:
	// data here
    LinkedListNode<Type>* head;
    LinkedListNode<Type>* tail;
    int count;

public:
   Deque<Type>(void){
        head = nullptr;
        tail = nullptr;
        count = 0;
   };

   ~Deque<Type>(void){
       LinkedListNode<Type>* current = head;
        for(int i = 0; i < count; i++){
            delete[] current->prev;
            current = current->next;
            if (current->next == nullptr){
                break;
            }
            delete[] current->prev->next;
        }
        delete[] current;
        delete[] head;
        delete[] tail;
   };

   bool isEmpty(void){
        if(count < 1){
            return true;
        }
        else{
            return false;
        }
   };

   int size(void){
        return count;
   };

   Type first(void){
        if(isEmpty()){
            throw Empty_Deque_Exception();
        }
        return head->data;
   };

   Type last(void){
        if(isEmpty()){
            throw Empty_Deque_Exception();
        }
        return tail->data;
   };

   void insertFirst(Type o){
       if (!isEmpty()){
            LinkedListNode<Type>* current = head;
            LinkedListNode<Type>* new_node = new LinkedListNode<Type>(o);
            current->prev = new_node;
            new_node->next = current;
            head = new_node;
            count++;
       }
       else {
            LinkedListNode<Type>* new_node = new LinkedListNode<Type>(o);
            head = new_node;
            tail = new_node;
            count++;
       }
   };

   void insertLast(Type o){
       if(!isEmpty()){
            LinkedListNode<Type>* current = tail;
            LinkedListNode<Type>* new_node = new LinkedListNode<Type>(o);
            current->next = new_node;
            new_node->prev = current;
            tail = new_node;
            count++;
       }
       else {
            LinkedListNode<Type>* new_node = new LinkedListNode<Type>(o);
            head = new_node;
            tail = new_node;
            count++;
       }
   };

   Type removeFirst(void){
        if(isEmpty()){
            throw Empty_Deque_Exception();
        }
        LinkedListNode<Type>* current = head;
        head = head->next;
        count--;
        return current->data;
   };

   Type removeLast(void){
        if(isEmpty()){
            throw Empty_Deque_Exception();
        }
        LinkedListNode<Type>* current = tail;
        tail = tail->prev;
        count--;
        return current->data;
   };
};

#endif
