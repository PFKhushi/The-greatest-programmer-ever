class SaldoInsuficiente:
    def __init__(self) -> None:
        self.err = "vc nao tem dinheiro"
    def __str__(self) -> str:
        return self.err
    
class ContaBancaria:
    
    def __init__ (self, nome):
        self.__nome = nome
        self.__saldo = 0
        self.__err = SaldoInsuficiente()
    def __str__(self):
        return "\n\nNome: " + self.__nome + "\nSaldo: " + str(self.__saldo)

    def depositar(self, quantidade):
        self.__saldo += quantidade
    def sacar(self, quantidade):
        if quantidade>self.__saldo:
            print(self.__err)
            return 0
        else:
            self.__saldo -= quantidade
            return quantidade
            
conta = ContaBancaria("Pedro")
print(conta)
conta.sacar(10)