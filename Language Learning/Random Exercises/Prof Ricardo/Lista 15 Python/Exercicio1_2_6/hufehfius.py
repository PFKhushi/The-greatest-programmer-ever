class Motor:
    def __init__(self, tipo):
        self.tipo = tipo
    def __str__(self):
        return "\nO tipo de motor é " + self.tipo
        
class Carro:
    
    def __init__(self, marca, modelo, ano, motor):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
        self.velocidade = 0.0
        self.motor = motor
    
    def __str__(self):
        return "Marca: " + self.marca + " Modelo: " + self.modelo + " Ano: " + str(self.ano) + str(self.motor)
    def acelerar(self, velocidade):
        self.velocidade += velocidade
    def frear(self, frenagem):
        if self.velocidade < frenagem:
            self.velocidade = 0
        else:
            self.velocidade -= frenagem
    def showVelo(self):
        return self.velocidade
    

for i in range(3):
    carro = Carro("marca" + str(i), "modelo" + str(i), 2020 + i, Motor("Gasolina"))
    print(carro)


    