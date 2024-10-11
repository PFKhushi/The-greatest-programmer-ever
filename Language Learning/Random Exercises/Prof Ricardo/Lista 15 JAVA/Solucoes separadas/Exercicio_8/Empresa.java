package Exercicio_8;

public class Empresa {

	String nome;
	int num_empregados;
	Empregado[] empregados;
	double total_salario;
	
	public Empresa(String nome) {
		this.nome = nome;
		this.empregados = new Empregado[0];
		this.total_salario = 0;
	}
	public void addEmpregado(Empregado empregado) {
		this.aumentaLista();
		this.empregados[num_empregados] = empregado;
		this.total_salario += empregado.salario;
		this.num_empregados++;
		
	} 
	public void addEmpregado(Empregado[] empregados) {
		
		for(Empregado empregado : empregados) {
			addEmpregado(empregado);
		}
		
	}
	private String listaEmpregados() {
		String temp = "";
		for(Empregado emp : this.empregados) {
			temp += emp.toString();
		}
		return temp;
	}
	private void aumentaLista() {
		Empregado[] novaLista = new Empregado[num_empregados + 1];
		
		for(int i = 0; i < this.num_empregados; i++) {
			novaLista[i] = this.empregados[i];
		}
		this.empregados = novaLista;
		
	}
	@Override
	public String toString() {
		return "\nNome Empresa: " + nome + "\nNumero de Empregados: " + num_empregados + "\nTotal de salarios\n\n" + total_salario + listaEmpregados();
	}
}
