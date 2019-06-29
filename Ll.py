class LinkedList():
    class _Node():
        def __init__(self,element,next):
            self._element=element
            self._next=next
    def __init__(self,max):
        self._head=None
        self._tail=None
        self._size=0
        self._maxsize=max
    def __len__(self):
        return self._size
    
    def push(self,e):
        if self._size<self._maxsize:
            if self.is_empty():
                self._head=self._Node(e,self._head)
                self._tail=self._head
                self._size+=1
            else:
                self._head=self._Node(e,self._head)
                self._size+=1
        else:
            raise ValueError ("List is full")
    def is_empty(self):
        return True if self._size==0 else False
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
            raise ValueError ("List is full")
    def traverselist(self):
        n=self._head
        while n is not None:
            print (n._element)
            n=n._next
        print ("\n")
    def count(self,m):
        c=0
        n=self._head
        while n is not None:
            if n._element==m:
                c+=1 
            n=n._next
        print (c)
    def getnth(self,m):
        if m<self._size:
            c=0
            n=self._head
            while n is not None:
                if c==m:
                    print (n._element)
                    break
                else:
                    c+=1
                n=n._next
        else:
            raise ValueError("Index beyond range")
    def insertnth(self,e,m):
        if self._size<self._maxsize:
            if m<self._size:
                c=0
                n=self._head
                while n is not None:
                    if c==m:
                        n._next=self._Node(e,n._next)
                        self._size+=1
                        self.traverselist()
                        break
                    else:
                        c+=1
                    n=n._next
            else:
                raise ValueError("Index out of range")
        else:
            raise ValueError("List is full")  
    def append(self,l):
        if not isinstance(l,LinkedList):
            raise TypeError("The argument is not of the same type")  
        else:
            self._tail._next=l._head
            self._size+=len(l)
            
        self.traverselist()
    def movenode(self,l):
        if not isinstance(l,LinkedList):
            raise TypeError("Value entered is not of same type")
        else:
            if self._size<self._maxsize:
                n=l._head
                l._head=n._next
                n._next=self._head
                self._head=n
                l._size-=1
                self._size+=1
            else:
                raise ValueError("List is full")
    def insertsort(self):
        if self.is_empty():
            raise ValueError("List is empty")
        else:
            n=self._head
            while n is not None:
                if n._next==None:
                    break
                elif n._next._element<n._element:
                    m=n._next
                    n._next=m._next
                    m._next=n
                    if n==self._head:
                        self._head=m
                else:
                    n=n._next
    def shufflemerge(self,d):
        if not isinstance(d,LinkedList):
            raise TypeError("Argument entered is not of same type")
        else:
            l=LinkedList(self._maxsize)
            c=0
            sn=self._size
            dn=d._size
            while c<sn or c<dn:
                if c<sn and c<dn:
                    l.movenode(self)
                    l.movenode(d)
                elif c>=sn and c<dn:
                    l.movenode(d)
                else:
                    l.movenode(self)
                c+=1
            l.traverselist() 
            print (len(l)) 
    
    def alternatingsplit(self):
        l=LinkedList(self._maxsize)
        d=LinkedList(self._maxsize)
        c=0
        n=self._size
        while c<n:
            if c%2==0:
                l.movenode(self)
                c+=1
            else:
                d.movenode(self)
                c+=1
                
        l.traverselist()
        d.traverselist()
    def reverse(self):
        n=self._head
        m=n._next
        n._next=None
        while n is not None:
            if m==None:
                self._head=n
                break
            else:
                o=m._next
                m._next=n
                n=m
                m=o
        self.traverselist()
        
        
ll=LinkedList(15)
ll.push(4)
ll.push(3)
ll.push(5)
dd=LinkedList(15)
ll.push(8)
ll.push(9)
ll.push(6)
ll.traverselist()
#dd.traverselist()
ll.reverse()

#ll.traverselist()
#dd.traverselist()
#ll.movenode(dd)
#ll.traverselist()
#dd.traverselist()
#print (len(ll))
#ll.count(3)
#ll.getnth(2)
#ll.getnth(20)
#print(len(ll))
#print ("\n")
#ll.insertnth(2,2)               
#print(len(ll))