#include<iostream>

using namespace std;

class SinglyLinkedList{
    class Node{
        int element;
        Node next;
        public:
            Node(element,next){
            element=element;
            next=next;
            }
            int ele(){
                return element;
            }
            Node nod(){
                return next;
            }
    }
    Node head;
    int size;
    int maxsize;
    public:
        SinglyLinkedList(max){
            head=NULL;
            size=0;
            maxsize=max;
        }
    int sizeofList(){
        return size;
    }
    void push(int e){
        if (size<maxsize){
            head=Node(e,head);
            size+=1
        }
    }
    void traverselist(){
        n=head;
        while (n!=NULL){
            cout<<n.ele()<<endl;
            n=n.nod();
        }
    }
}

main(){
    SinglyLinkedList sl(5);
    sl.push(3);
    sl.push(4);
    sl.push(5);
    sl.traverselist();
}