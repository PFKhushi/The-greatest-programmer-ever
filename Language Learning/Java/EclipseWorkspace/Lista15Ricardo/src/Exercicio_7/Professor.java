package Exercicio_7;

public class Professor {
	private String nome;
	private Escola[] escolas;
	private int num_escolas;
	public Professor(String nome) {
		this.nome = nome;
		this.num_escolas = 0;
		this.escolas = new Escola[0];
	}
	public String getNome() {
		return this.nome;
	}
	public void addEscola(Escola escola) {
		this.aumentaLista();
		this.escolas[num_escolas] = escola;
		this.num_escolas++;
		
	} 
	public void addEscola(Escola[] escolas) {
		
		for(Escola escola : escolas) {
			addEscola(escola);
		}
		
	}
	private void aumentaLista() {
		Escola[] novaLista = new Escola[num_escolas + 1];
		
		for(int i = 0; i < this.num_escolas; i++) {
			novaLista[i] = this.escolas[i];
		}
		this.escolas = novaLista;
		
	}
}
