class SinglyLinkedList():
    class _Node:
        __slots__='_element','_next'
        def __init__(self,element, next):
            self._element=element
            self._next=next
    def __init__(self):
        self._head=None
        self._size=0
    def __len__(self):
        return self._size
    def push(self,e):
        self._head=self._Node(e,self._head)
        self._size+=1
    def top(self):
        return self._head._element
    def traverselist(self):
        n=self._head
        while n is not None:
            print (n._element)
            n=n._next
    def secondlast(self):
        n=self._head._next
        while n is not None:
            m=n
            n=n._next._next
        print (m._element)
sl=SinglyLinkedList()
sl.push(5)
sl.push(4)
sl.push(3)
sl.traverselist()
sl.secondlast()
