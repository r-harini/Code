class SinglyLinkedList():
    class _Node:
        __slots__='_element','_next'
        def __init__(self,element, next):
            self._element=element
            self._next=next
    def __init__(self,max):
        self._head=None
        
        self._size=0
        self._maxsize=max
    def __len__(self):
        return self._size
    def push(self,e):
        if self._size<self._maxsize:
            self._head=self._Node(e,self._head)
            self._size+=1
        else:
            raise ValueError("You have reached the max size")
    def top(self):
        return self._head._element
    def traverselist(self):
        n=self._head
        while n is not None:
            print (n._element)
            n=n._next
        print ("\n")
    def secondlast(self):
        n=self._head._next
        while n is not None:
            m=n
            n=n._next._next
        print (m._element)
    def is_empty(self):
        return True if self._head==None else False
    def pop(self):
        if not self.is_empty():
            n=self._head._element
            self._head=self._head._next
            self._size-=1
            return n
        else:
            raise ValueError("List is empty")
    

        
    
sl=SinglyLinkedList(5)
sl.push(5)
sl.push(4)
sl.push(3)
sl.traverselist()
sl.push(2)
sl.push(1)
sl.traverselist()
sl.push(0)
sl.traverselist()

#sl.secondlast()
"""print(sl.pop())
print ("\n")
sl.traverselist()
print(sl.pop())
print ("\n")
sl.traverselist()
print(sl.pop())
sl.traverselist()
print(sl.pop())"""
