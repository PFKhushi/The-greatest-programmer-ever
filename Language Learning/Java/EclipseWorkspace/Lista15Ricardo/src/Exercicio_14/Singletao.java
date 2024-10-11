package Exercicio_14;

public class Singletao {
	private static Singletao instancia;
	private String data;
	private Singletao(String data) { // O construtor tem q ser privado para garantir q haja apenas uma instancia
		this.data = data;			 // q sera retornada por uma funcao publica e estatica 
	}
	public static Singletao getInstance(String data) {
		synchronized (Singletao.class) { 			// Serve para impedir q duas threads tentem criar
			if(instancia == null) {					// mais de uma instancia ao mesmo tempo
				instancia = new Singletao(data);  	// pois o acesso é limitado por turnos
			}
		}
		return instancia;
		//return instancia == null ? new Singletao(data) : instancia; // Se instancia for nula, sera criada uma nova instancia
	}															   	  // se houver instancia, ela sera retornada
	public String getData() {
		return data;
	}
}
