class _DoublyLinkedBase:
    class _Node:
        __slots__='_element','_prev','_next'
        def __init__(self,element,prev,next):
            self._element=element
            self._prev=prev
            self._next=next
    def __init__(self):
        self._header=self._Node(None,None,None)
        self._trailer=self._Node(None,None,None)
        self._header._next=self._trailer
        self._trailer._prev=self._header
        self._size=0

    def __len__(self):
        return self._size
    def is_empty(self):
        return len(self)==0
    def _insert_between(self,e,pred,suc):
        newest=self._Node(e,pred,suc)
        pred._next=newest
        suc._prev=newest
        self._size+=1
        return newest
    def _delete_node(self,node):
        pred=node._prev
        suc=node._suc
        pred._next=suc
        suc._prev=pred
        self._size-=1
        element=node._element
        return element
    def traverselist(self):
        n=self._header._next
        while n is not self._trailer:
            print (n._element)
            n=n._next

dl=_DoublyLinkedBase()
#print (len(dl))
#print (dl.is_empty())
#print (dl._insert_between(
n1=dl._insert_between(3,dl._header,dl._trailer)
n2=dl._insert_between(4,n1,dl._trailer)
dl.traverselist()
