package Exercicio_3_15;

public class SaldoInsuficiente extends Exception{
	
	private double saldo, saque;
	
	public SaldoInsuficiente (double saldo, double saque) {
		super();
		this.saldo = saldo;
		this.saque = saque;
	}
	
	@Override
	public String toString() {
		return "Você não consegue sacar R$" + this.saque + " de R$" + this.saldo + "\n Saldo insuficiente.";
	}
}
