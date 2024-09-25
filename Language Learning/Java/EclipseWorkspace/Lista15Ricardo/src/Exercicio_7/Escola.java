package Exercicio_7;

public class Escola {
	private String nome;
	private Professor[] professores;
	private int num_professores;
	public Escola(String nome) {
		this.nome = nome;
		this.num_professores = 0;
		this.professores = new Professor[0];
	}
	public String getNome() {
		return this.nome;
	}
	
	public void addProfessor(Professor professor) {
		this.aumentaLista();
		this.professores[num_professores] = professor;
		this.num_professores++;
		
	} 
	public void addEscola(Professor[] professores) {
		
		for(Professor professor : professores) {
			addProfessor(professor);
		}
		
	}
	private void aumentaLista() {
		Professor[] novaLista = new Professor[num_professores + 1];
		
		for(int i = 0; i < this.num_professores; i++) {
			novaLista[i] = this.professores[i];
		}
		this.professores = novaLista;
		
	}
}
