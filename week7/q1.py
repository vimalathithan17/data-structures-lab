class Stack:
    def __init__(self):
        self.stack=[]
        self.min_arr=[]
        self.top=-1
    def push(self,data):
        self.stack.append(data)
        self.top+=1
        if len(self.min_arr)==0 or self.min_arr[-1]>=data:
            self.min_arr.append(data)
    def peek(self):
        return self.stack[self.top]
    def pop(self):
        if self.top==-1:
            print("cant pop an empty stack")
            return
        if(self.peek()==self.min_arr[-1]):
            self.min_arr.pop()
        self.top-=1
        return self.stack.pop()
    def minval(self):
        if(self.top==-1):
            print("empty stack no minimum val")
            return
        return self.min_arr.pop()
stack1=Stack()
size=int(input("Enter the size:"))
operations=eval(input("Enter the list of operations:"))
values=eval(input("Enter list of the values:"))
output=[]
while size!=0:
    operation=operations.pop(0)
    value=values.pop(0)
    if operation=="push":
        stack1.push(value)
    elif operation=="pop":
        output.append(stack1.pop())
    elif operation=="minval":
        output.append(stack1.minval())
    size-=1
print("the output is:",output)
