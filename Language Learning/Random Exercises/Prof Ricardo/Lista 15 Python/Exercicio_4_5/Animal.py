class Animal:
    def __init__(self, nome):
        self.nome = nome
    def emitir_som(self):
        pass  # Método a ser implementado nas subclasses
    def __str__(self) -> str:
        return self.nome
    
class Cao(Animal):
    def emitir_som(self):
        print("Latido")

class Gato(Animal):
    def emitir_som(self):
        print("miado")

def Fala(animal: Animal):
    print(animal)
    animal.emitir_som()

cao = Cao("Bob")
gato = Gato("Tat")

lista = {cao, gato}

for x in lista:
  Fala(x)