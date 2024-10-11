package Exercicio_12;

import java.util.ArrayList;
import java.util.List;

public class Produto {
    private String nome;
    private double preco;

    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
    }

    public String getNome() {
        return nome;
    }

    public double getPreco() {
        return preco;
    }
}


public Exercicio_12() {
    
        Produto produto1 = new Produto("Maçã", 1.50);
        Produto produto2 = new Produto("Banana", 2.00);
        Produto produto3 = new Produto("Laranja", 1.75);
        
        ListaProduto lista = new ListaProduto();
        lista.preco(produto1, produto2, produto3, produto1);
        
        System.out.printf("Total price: %.2f%n", lista.getTotal());
        for (Produto item : lista.getItens()) {
            System.out.printf("Product: %s, Price: %.2f%n", 
                             item.getNome(), item.getPreco());
        
    }
}