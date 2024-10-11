class Produto:
    def __init__(self, nome, preco):
        self.nome = nome
        self.preco = preco

class ListaProduto:
    def __init__(self):
        self.itens = []
        self.total = 0.0
    
    def _preco(self, *prods):
        for item in prods:
            self.itens.append(item)
            self.total += item.preco


produto1 = Produto("Maçã", 1.50)
produto2 = Produto("Banana", 2.00)
produto3 = Produto("Laranja", 1.75)
    
lista = ListaProduto()
lista._preco(produto1, produto2, produto3, produto1)
    
print(f"Total price: {lista.total}")
for item in lista.itens:
    print(f"Product: {item.nome}, Price: {item.preco}")