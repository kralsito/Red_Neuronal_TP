class Empleado:
    def __init__(self, nombre, salario):
        self.nombre = nombre
        self.salario = salario
        self.departamento = "Sin asignar"
        self.antiguedad = 0

    def asignar_departamento(self, departamento):
        self.departamento = departamento

    def aumentar_antiguedad(self, años):
        self.antiguedad += años

    def mostrar_informacion(self):
        print(f"Nombre: {self.nombre}")
        print(f"Departamento: {self.departamento}")
        print(f"Salario: ${self.salario}")
        print(f"Antigüedad: {self.antiguedad} años")

# Uso de la clase Empleado
empleado1 = Empleado("Juan Pérez", 50000)
empleado2 = Empleado("María García", 60000)

empleado1.asignar_departamento("Ventas")
empleado2.asignar_departamento("Marketing")

empleado1.aumentar_antiguedad(3)
empleado2.aumentar_antiguedad(5)

print("Información de Empleado 1:")
empleado1.mostrar_informacion()

print("\nInformación de Empleado 2:")
empleado2.mostrar_informacion()
