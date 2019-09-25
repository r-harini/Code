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
        suc=node._next
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

class PositionalList(_DoublyLinkedBase):
    class Position:
        def __init__(self,container,node):
            self._container=container
            self._node=node

        def element(self):
            return self._node._element

        def __eq__(self,other):
            return type(other) is type(self) and other._node is self._node
        
        def __ne__(self,other):
            return not (self==other)
        
    def _validate(self, p):
        if not isinstance(p,self.Position):
            raise TypeError("p must be proper Position type")
        if p._container is not self:
            raise ValueError ("p doesnt belong to the container")
        if p._node._next is None:
            raise ValueError('p is no longer valid')
        return p._node
    
    def _make_position(self,node):
        if node is self._header or node is self._trailer:
            return None
        else:
            return self.Position(self,node)
        
    def first(self):
        return self._make_position(self._header._next)
    
    def last(self):
        return self._make_position(self._trailer._prev)
    
    def before(self,p):
        node=self._validate(p)
        return self._make_position(node._prev)

    def after(self,p):
        node=self._validate(p)
        return self._make_position(node._next)
    
    def __iter__(self):
        cursor=self.first()
        while cursor is not None:
            yield cursor.element()
            cursor=self.after(cursor)
    
    def _insert_between(self,e,pred,suc):
        node=super()._insert_between(e,pred,suc)
        return self._make_position(node) 
    
    def add_first(self,e):
        return self._insert_between(e,self._header,self._header._next)
    
    def add_last(self,e):
        return self._insert_between(e,self._trailer._prev,self._trailer)

    def add_before(self,p,e):
        node=self._validate(p)
        return self._insert_between(e,node._prev,node)
    
    def add_after(self,p,e):
        node=self._validate(p)
        return self._insert_between(e, node, node._next)

    def delete(self,p):
        node=self._validate(p)
        return self._delete_node(node)
    
    def replace(self,p,e):
        node=self._validate(p)
        old=node._element
        node._element=e
        return old
           
class PriorityQueueBase:
    class _Item:
        __slots__= '_key', '_value'
        def __init__(self,k,v):
            self._key=k
            self._value=v
        
        def __lt__(self,other):
            return self._key<other._key
    def is_empty(self):
        return len(self)==0

class UnsortedPriorityQueue(PriorityQueueBase):
    def __init__(self):
        self._data=PositionalList()

    def _find_min(self):
        if self.is_empty():
            raise ValueError("Priority Queue is empty")
        small=self._data.first()
        walk=self._data.after(small)
        while walk is not None:
            if walk.element()<small.element():
                small=walk
            walk=self._data.after(walk)
        return small

    def __len__(self):
        return len(self._data)

    def add(self,key,value):
        self._data.add_last(self._Item(key,value))

    def min(self):
        p=self._find_min()
        item=p.element
        return (item._key, item._value)
    
    def remove_min(self):
        p=self._find_min()
        item=self._data.delete(p)
        return(item._key, item._value)

u=UnsortedPriorityQueue()
u.add(3,"Hi")
u.add(1,"Lol")
u.add(4,"La")
print(u.remove_min())
print(u.remove_min())
print(u.remove_min())
print(u.remove_min())