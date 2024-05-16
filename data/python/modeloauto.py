class Coche:
    def __init__(self, marca, modelo, año):
        self.marca = marca
        self.modelo = modelo
        self.año = año
        self.velocidad = 0

    def acelerar(self, incremento):
        self.velocidad += incremento

    def frenar(self, decremento):
        self.velocidad -= decremento
        if self.velocidad < 0:
            self.velocidad = 0

    def estado(self):
        print(f"Coche {self.marca} {self.modelo} del año {self.año}, velocidad {self.velocidad} km/h")

mi_coche = Coche("Toyota", "Corolla", 2022)
mi_coche.acelerar(50)
mi_coche.estado()
mi_coche.frenar(20)
mi_coche.estado()