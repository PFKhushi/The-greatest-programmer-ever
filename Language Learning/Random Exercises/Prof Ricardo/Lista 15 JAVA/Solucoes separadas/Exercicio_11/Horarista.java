package Exercicio_11;

public class Horarista extends Funcionario{
	
	private String nome;
	private double precoHoras;
	private int horasTrabalhadas;
	public Horarista(String nomi, double preco, int meses) {
		nome = nomi;
		precoHoras = horasTrabalhadas;
		horasTrabalhadas = meses;
	}
	public String getNome() {
		return nome;
	}
	public double calcSalario() {	
		return precoHoras*horasTrabalhadas;
	}

}
