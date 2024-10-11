package Exercicio_12;

import java.util.ArrayList;
import java.util.List;

public class ListaProduto {
    private List<Produto> itens;
    private double total;

    public ListaProduto() {
        this.itens = new ArrayList<>();
        this.total = 0.0;
    }
    
    public void preco(Produto... prods) {
        for (Produto item : prods) {
            this.itens.add(item);
            this.total += item.getPreco();
        }
    }

    public double getTotal() {
        return total;
    }

    public List<Produto> getItens() {
        return itens;
    }
}
