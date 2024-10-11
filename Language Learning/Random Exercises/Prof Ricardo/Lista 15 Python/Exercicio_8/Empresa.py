class Empresa:
    def __init__(self, nome, prof=None):
        self.nome = nome
        self.funcionarios = prof if prof is not None else []
    def printFun(self):
        for i in self.funcionarios:
            print(i.nome)

class Funcionario:
    def __init__(self, nome):
        self.nome = nome
    
funcionario = Funcionario("Ms. Smith")
empresa = Empresa("John Doe")

empresa.funcionarios.append(empresa)


print(empresa.nome)
empresa.printFun()
print(funcionario.nome)
