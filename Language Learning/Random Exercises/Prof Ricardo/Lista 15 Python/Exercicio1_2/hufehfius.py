class Carro:
    def __init__(self, marca, modelo, ano):
        self.marca = marca
        self.modelo = modelo
        self.ano = ano
    
    def __str__(self) -> str:
        return "Marca: " + self.marca + " Modelo: " + self.modelo + " Ano: " + str(self.ano)


for i in range(3):
    carro = Carro("marca" + str(i), "modelo" + str(i), 2020 + i)
    print(carro)
    