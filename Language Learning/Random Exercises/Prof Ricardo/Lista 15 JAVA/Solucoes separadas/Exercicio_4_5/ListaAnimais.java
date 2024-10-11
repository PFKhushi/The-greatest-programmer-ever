package Exercicio_4_5;

public class ListaAnimais {
	private Animal[] animais;
	
	public ListaAnimais(Animal[] animais) {
		this.animais = animais;
	}
	public void printAnimais() {
		for (Animal animal : this.animais) {
			animal.FazSom();
		}
	}
	
}
