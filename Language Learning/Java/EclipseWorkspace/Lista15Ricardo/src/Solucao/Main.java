package Solucao;

import Exercicio_4_5.*;

public class Main {

	public static void main(String[] args) {
		
		Cachorro cao = new Cachorro("Bob", "Au au");
		Gato gato = new Gato("Xanin", "Miau");
		Animal[] animais = {gato, cao};
		ListaAnimais listAnimais = new ListaAnimais(animais);
		gato.FazSom();
		cao.FazSom();
		
		listAnimais.printAnimais();

	}

}
