package Exercicio_1_2_6;

public class Carro {
	
	private String marca,modelo;
	private int ano;
	private double velocidade;
	private Motor motor;
	
	public Carro() {
		this.marca = "VolksWagen";
		this.modelo = "Golf";
		this.ano = 2015;
		this.velocidade = 0;
		this.motor = new Motor();
	}
	public Carro(String marca, String modelo, int ano, double velocidade, int cavalos) {
		this.marca = marca;
		this.modelo = modelo;
		this.ano = ano;
		this.velocidade = 0;
		this.motor.setCavalos(cavalos);
	}
	public void setModelo(String modelo) {
		this.modelo = modelo;
	}
	public void setMarca(String marca) {
		this.marca = marca;
	}
	public void setAno(int ano) {
		this.ano = ano;
	}	
	public void setMotor(int cavalos) {
		this.motor.setCavalos(cavalos);
	}
	public void setMotor(Motor motor) {
		this.motor = motor;
	}
	public Motor getMotor() {
		return this.motor;
	}
	public int getCavalos() {
		return this.motor.getCavalos();
	}
	public int getAno() {
		return this.ano;
	}
	public String getModelo() {
		return this.modelo;
	}
	public String getMarca() {
		return this.marca;
	}
	public void Frear(double frenagem) {
		if(frenagem < this.velocidade) {
			this.velocidade -= velocidade;
		}else {
			this.velocidade = 0;
		}
	}
	public void Acelerar(double acelero) {
		this.velocidade += acelero;
	}
	public double getVelo() {
		return this.velocidade;
	}
	
	@Override
	public String toString() {
		return "\nMarca: " + this.marca + "\nModelo: " + this.modelo + "\nAno: " + this.ano + this.motor.toString();
	}
	
}
