from abc import ABC, abstractmethod

class Funcionario(ABC):
    @abstractmethod
    def calc_salario(self):
        pass
    
    @abstractmethod
    def print_salario(self):
        pass

class Horarista(Funcionario):
    def __init__(self, preco_hora, horas):
        self.preco_hora = preco_hora
        self.horas = horas
        self.salario = 0.0
    
    def calc_salario(self):
        self.salario = self.preco_hora * float(self.horas)
    
    def print_salario(self):
        print(f"O salario do horaris por {self.horas} horas trabalhadas, sera de R${self.salario}.")

class Assalariado(Funcionario):
    def __init__(self, preco_contrato, meses):
        self.preco_contrato = preco_contrato
        self.meses = meses
        self.salario = 0.0
    
    def calc_salario(self):
        self.salario = self.preco_contrato * float(self.meses)
    
    def print_salario(self):
        print(f"O salario do assalariado por {self.meses} meses trabalhados, sera de R${self.salario}.")


horista = Horarista(50.0, 160)
horista.calc_salario()
horista.print_salario()
    
assalariado = Assalariado(5000.0, 12)
assalariado.calc_salario()
assalariado.print_salario()