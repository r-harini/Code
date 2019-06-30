#include<iostream>

using namespace std;
class Node{
        int element;
        Node next;
        public:
            Node(int element,Node next){
            element=element;
            next=next;
            }
            int ele(){
                return element;
            }
            Node nod(){
                return next;
            }
};

class SinglyLinkedList{
    
    Node head;
    int size;
    int maxsize;
    public:
        SinglyLinkedList(int max){
            //head=NULL;
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
        Node n=head;
        int s=
        while (){
            cout<<n.ele()<<endl;
            n=n.nod();
        }
    }
};

int main(){
    SinglyLinkedList sl(5);
    sl.push(3);
    sl.push(4);
    sl.push(5);
    sl.traverselist();
    return 0;
}