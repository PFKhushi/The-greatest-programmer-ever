package Exercicio_1_2_6;

public class Motor {
	
	private int cavalos;
	
	public Motor() {
		this.cavalos = 150;
	}
	public Motor(int cavalos) {
		this.cavalos = cavalos;		
	}
	public void setCavalos(int cavalos) {
		this.cavalos = cavalos;
	}
	public int getCavalos() {
		return this.cavalos;
	}
	@Override
	public String toString() {
		return "\nCavalos: " + this.cavalos;
	}
}
