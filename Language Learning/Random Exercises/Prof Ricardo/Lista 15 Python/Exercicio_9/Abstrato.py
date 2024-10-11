from abc import ABC, abstractmethod

class Imprimiveis(ABC):
    @abstractmethod
    def imprimir_papel(self):
        pass

class Relatorio(Imprimiveis):
    def __init__(self, content):
        self.content = content
    
    def imprimir_papel(self):
        print(self.content)

class Contrato(Imprimiveis):
    def __init__(self, content):
        self.content = content
    
    def imprimir_papel(self):
        print(self.content)


relatorio = Relatorio("Relatorio")
contrato = Contrato("Contrato")
relatorio.imprimir_papel()
contrato.imprimir_papel()


