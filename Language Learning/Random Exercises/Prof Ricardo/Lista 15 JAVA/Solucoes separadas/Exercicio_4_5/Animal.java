package Exercicio_4_5;

public class Animal {
	private String som, nome;
	
	public Animal(String nome, String som) {
		
		this.som = som;
		this.nome = nome;
		
	}
	public void FazSom() {
		System.out.println(this.som);
		
	}
	public String getNome() {
		return this.nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public void setSom(String som) {
		this.som = nome;
	}
}
