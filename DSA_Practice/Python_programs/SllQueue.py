class SinglyLinkedList():
    class _Node:
        __slots__='_element','_next'
        def __init__(self,element, next):
            self._element=element
            self._next=next
    def __init__(self,max):
        self._head=None
        self._tail=None
        self._size=0
        self._maxsize=max
    def __len__(self):
        return self._size
    
    def traverselist(self):
        n=self._head
        while n is not None:
            print (n._element)
            n=n._next
        print ("\n")
    
    def is_empty(self):
        return True if self._head==None else False
    
    def enqueue(self,e):
        if self._size<self._maxsize:
            if self.is_empty():
                self._head=self._Node(e,self._tail)
                self._tail=self._head
                self._size+=1
            else:
                n=self._tail
                self._tail=self._Node(e,None)
                n._next=self._tail
                
                self._size+=1
        else:
            raise ValueError("List is full")
    def dequeue(self):
        if not self.is_empty:
            n=self._head._element
            self._head=self._head._next
            self._size-=1
            return n
        else:
            raise ValueError("List is empty")
            
    
sl=SinglyLinkedList(5)
sl.enqueue(5)
sl.enqueue(4)
sl.traverselist()
sl.enqueue(3)
sl.traverselist()
sl.enqueue(2)
sl.enqueue(1)
sl.traverselist()

print(sl.dequeue())
print(sl.dequeue())
