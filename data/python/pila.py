class Stack:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            raise IndexError("La pila está vacía")

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            raise IndexError("La pila está vacía")

# Uso del Stack
pila = Stack()
pila.push(1)
pila.push(2)
pila.push(3)

print("Elemento en la cima de la pila:", pila.peek())
print("Desapilando elementos:")
while not pila.is_empty():
    print(pila.pop())
