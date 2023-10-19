class Node:
    def __init__(self,url):
        self.url=url
        self.next=None
        self.prev=None
    def __str__(self):
        return self.url

class BrowserHistory:
    def __init__(self,url):
        self.history=Node(url)
        self.current=self.history
    def visit(self,url):
        if(self.current!=None):
            new_node=Node(url)
            new_node.prev=self.current
            self.current.next=new_node
            self.current=self.current.next
    def back(self,num):
        i=0
        while(self.current.prev!=None and i!=num):
            self.current=self.current.prev
            i+=1
        return self.current.url
    def forward(self,num):
        i=0
        while(self.current.next!=None and i!=num):
            self.current=self.current.next
            i+=1
        return self.current.url
browser_history=None
output=[]
size=int(input("Enter size:"))
operations=eval(input("Enter the operations:"))
urls=eval(input("Enter urls:"))
while size!=0:
    operation=operations.pop(0)
    val=urls.pop(0)
    if operation=="BrowserHistory":
        browser_history=BrowserHistory(val)
        output.append("null")
    elif operation=="visit":
        browser_history.visit(val)
        output.append("null")
    elif operation=="back":
        output.append(browser_history.back(val))
    elif operation=="forward":
        output.append(browser_history.forward(val))
    size-=1
print("The output is:",output)
    
