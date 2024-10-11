package Exercicio_3_15;

public class ContaBancaria {
	private double saldo;
	private String titular;
	
	public ContaBancaria() {
		this.saldo = 0;
		this.titular = "Fulano";
	}
	public ContaBancaria(double saldo, String titular) {
		this.saldo = saldo;
		this.titular = titular;
	}
	public void Depositar(double valor) {
		this.saldo += valor;
	}
	public double Sacar(double valor) {
		try {
			if(valor<=this.saldo) {
			this.saldo -= valor;
			return valor;
			}else {
				throw new SaldoInsuficiente(this.saldo, valor);
			}
			
		} catch (Exception e) {
			return 0;
		}
	}
	public String getTitular() {
		return this.titular;
	}
	public double getSaldo() {
		return this.saldo;
	}
}
