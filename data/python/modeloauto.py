class Motor:
    def __init__(self, tipo, potencia):
        self.tipo = tipo
        self.potencia = potencia

    def encender(self):
        print(f"Motor {self.tipo} encendido")

    def apagar(self):
        print(f"Motor {self.tipo} apagado")


class Coche:
    def __init__(self, marca, modelo, año, motor):
        self.marca = marca
        self.modelo = modelo
        self.año = año
        self.motor = motor
        self.velocidad = 0

    def acelerar(self, incremento):
        self.velocidad += incremento

    def frenar(self, decremento):
        self.velocidad -= decremento
        if self.velocidad < 0:
            self.velocidad = 0

    def estado(self):
        print(f"Coche {self.marca} {self.modelo} del año {self.año}, velocidad {self.velocidad} km/h")

    def encender_motor(self):
        self.motor.encender()

    def apagar_motor(self):
        self.motor.apagar()


class Electrico(Coche):
    def __init__(self, marca, modelo, año, motor):
        super().__init__(marca, modelo, año, motor)
        self.carga_bateria = 100

    def cargar_bateria(self, porcentaje):
        self.carga_bateria += porcentaje
        if self.carga_bateria > 100:
            self.carga_bateria = 100

    def estado(self):
        super().estado()
        print(f"Carga de batería: {self.carga_bateria}%")


motor_gasolina = Motor("Gasolina", "150 CV")
mi_coche = Coche("Toyota", "Corolla", 2022, motor_gasolina)
mi_coche.encender_motor()
mi_coche.acelerar(50)
mi_coche.estado()
mi_coche.frenar(20)
mi_coche.estado()

mi_coche_electrico = Electrico("Tesla", "Model S", 2023, Motor("Eléctrico", "300 kW"))
mi_coche_electrico.encender_motor()
mi_coche_electrico.acelerar(70)
mi_coche_electrico.estado()
mi_coche_electrico.cargar_bateria(20)
mi_coche_electrico.estado()
mi_coche_electrico.apagar_motor()
