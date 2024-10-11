package Exercicio_9;


public class Relatorio implements Imprimiveis{
	
	private String conteudo;
	
	public Relatorio(String conteudos) { // A keyword this. so é necessaria para acessar variavel, quando a funcao
										 // tem uma variavel de nome conflitante 
		conteudo = conteudos;
	}
	
	public void Imprimir() {
		System.out.println(conteudo);
	}
	

}
