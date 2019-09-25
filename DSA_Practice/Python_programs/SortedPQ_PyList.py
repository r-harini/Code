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

class SortedPriorityQueue(PriorityQueueBase):
    def __init__(self):
        self._data=[]

    def __len__(self):
        return len(self._data)
    
    def add(self, key, value):
        new=self._Item(key,value)
        if len(self._data)==0:
            self._data.append(new)
        else:
            walk=self._data[len(self._data)-1]
            while walk is not None and new._key<walk._key:
                ind=self._data.index(walk)
                walk=self._data[ind-1]
                if walk is None:
                    self._data.insert(0,new)
                else:
                    self._data.insert(ind, new)
    
    def min(self):
        if self.is_empty():
            raise TypeError("List is empty")
        p=self._data[0]
        return (p._key, p._value)
    
    def remove_min(self):
        if self.is_empty():
            raise TypeError("List is empty")
        item=self._data[0]
        for i in range(len(self)):
            self._data[i]=self._data[i+1]
        return (item._key,item._value)
    
s=SortedPriorityQueue()
#s.add(1,"A")
s.add(3,"b")
s.add(2,"c")
print(s.min())
#print(s.remove_min())