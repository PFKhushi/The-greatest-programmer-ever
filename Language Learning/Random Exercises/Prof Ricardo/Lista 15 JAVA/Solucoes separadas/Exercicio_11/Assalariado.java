package Exercicio_11;

public class Assalariado extends Funcionario{
	
	private String nome;
	private double salarioMensal;
	private int mesesTrabalhados;
	public Assalariado(String nomi, double preco, int meses) {
		nome = nomi;
		preco = salarioMensal;
		mesesTrabalhados = meses;
	}
	public String getNome() {
		return nome;
	}
	public double calcSalario() {	
		return salarioMensal*mesesTrabalhados;
	}
}
