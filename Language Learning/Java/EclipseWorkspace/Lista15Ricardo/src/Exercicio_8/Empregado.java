package Exercicio_8;

public class Empregado {
	
	String nome, cargo;
	double salario;
	
	public Empregado() {
		this.nome = "test";
		this.cargo = "tester";
		this.salario = -1;
	}
	@Override
	public String toString() {
		return "\nNome: " + nome + "\nCargo: " + cargo + "\nSalario: " + salario; 
	}
}
