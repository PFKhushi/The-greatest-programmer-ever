package Exercicio_9;

public class Contrato implements Imprimiveis{

	private String conteudo;
	
	public Contrato(String conteudo) {
		this.conteudo = conteudo;
	}
	
	public void Imprimir() {
		System.out.println(this.conteudo);
	}
}
