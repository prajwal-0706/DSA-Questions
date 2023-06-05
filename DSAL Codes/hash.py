class record:
    def __init__(self):
        self.number = None
        self.name = None
        
    
    def get_name(self):
        self.name = str(input("Enter Name :"))
        return self.name
    
    def get_number(self):
        self.number = int(input("Enter Number :"))
        return self.number
    

robj = record()

class hash:
    def __init__(self):
        self.n = int(input("Enter size of table :"))
        self.table = list(None for i in range(self.n))
        self.comparision =0
        self.elementcount= 0
        self.flag = None
    
    def hashfuc(self,elem):
        return elem%(self.n)
    
    def hash2(self,elem):
        return 5-(elem%5)
    
    def doublehash(self,i,elem):
        return (self.hashfuc(elem)+i*(self.hash2(elem)))%(self.n)
    
    def doublehashpos(self,elem):
        position = self.hashfuc(elem)
        if(self.table[position] != None):
            for i in range(1,self.n):
                position = self.doublehash(i,elem)
                if(self.table[position] == None):
                    self.table[position]=[elem,robj.name]
                    break


    def isfull(self):
        if(self.elementcount == self.n):
            return True
        else:
            return False
    
    def insert(self):
        for i in range(self.n):
            num = robj.get_number()
            robj.get_name()
            if( self.isfull() != True ):
                position = self.hashfuc(num)
                if(self.table[position] == None):
                    self.table[position] = [num,robj.name]
                else:
                    print("Collision has occured ")
                    print("choose the method to resolve collision ")
                    print("1: linear collision \n 2: Double hashing")
                    ch = int(input("Enter you choice: "))

                    if(ch == 1 or self.flag==1):
                        self.linear(num)
                        self.flag = 1 
                    elif(ch==2 or self.flag==2):
                        self.doublehashpos(num)
                        self.flag = 2
                    else:
                        print("OOPs please enter correct choice!!!")
    
    def linear(self, element):
        position = self.hashfuc(element)
        while( self.table[position]!= None):
            position=position+1
            if(position >= self.n):
                position = 0
        self.table[position] = [element,robj.name]
    
    def display(self):
        for i in range(self.n):
            print(self.table[i], end=" ")

    def search(self,key):
        if(self.flag ==1):
            position = self.hashfuc(key)
            if(self.table[position][0]==key):
                print("Key found at ",position)
                print("key ",self.table[position])
            else:
                i = 0
                while( self.table[position][0]!= key or i <= self.n):
                    position=position+1
                    i=i+1
                    if(position >= self.n):
                        position = 0
                    if(self.table[position][0]==key):
                        print("Key found at ",position)
                        print("key ",self.table[position])
                        self.comparision=i
                        break
                if(i == self.n):
                    print("Key is not in table.")
        
        if(self.flag == 2):
            position = self.hashfuc(key)
            if(self.table[position][0]==key):
                print("Key found at "+position)
                print("key ",self.table[position])
            else:
                j = 0
                for i in range(1,self.n):
                    j=j+1
                    position = self.doublehash(i,key)
                    if(self.table[position][0] == key):
                        print("Key found at "+position)
                        print("key ",self.table[position])
                        self.comparision = j
                        break
           



def main():
    obj1 = hash()
    obj1.insert()
    obj1.display()

    k = int(input("enter a search key:"))
    obj1.search(k)

main()
