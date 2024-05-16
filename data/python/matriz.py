class Matriz:
    def __init__(self, filas, columnas):
        self.filas = filas
        self.columnas = columnas
        self.matriz = [[0 for _ in range(columnas)] for _ in range(filas)]

    def imprimir(self):
        for fila in self.matriz:
            print(fila)

    def asignar_valor(self, fila, columna, valor):
        self.matriz[fila][columna] = valor

    def sumar(self, otra_matriz):
        if self.filas == otra_matriz.filas and self.columnas == otra_matriz.columnas:
            resultado = Matriz(self.filas, self.columnas)
            for i in range(self.filas):
                for j in range(self.columnas):
                    resultado.matriz[i][j] = self.matriz[i][j] + otra_matriz.matriz[i][j]
            return resultado
        else:
            raise ValueError("Las dimensiones de las matrices no son compatibles para la suma")

# Uso de la clase Matriz
matriz1 = Matriz(2, 2)
matriz1.asignar_valor(0, 0, 1)
matriz1.asignar_valor(0, 1, 2)
matriz1.asignar_valor(1, 0, 3)
matriz1.asignar_valor(1, 1, 4)

matriz2 = Matriz(2, 2)
matriz2.asignar_valor(0, 0, 5)
matriz2.asignar_valor(0, 1, 6)
