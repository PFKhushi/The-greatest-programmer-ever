package Exercicio_10;

public class Calculadora {
	public static int calcula(int... numeros) {
		int temp = 0;
		for (int i : numeros) {
			temp += i;
		}
		return temp;
	}
}
