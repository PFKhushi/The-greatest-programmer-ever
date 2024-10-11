package Exercicio_13;

public class Matematica {
	public static int Fatorial(int num) { 
		return num > 1 ? num * Fatorial(num - 1) : num;
	}
	public static int Fib(int num) {
		return num < 2 ? 1 : Fib(num - 1) + Fib(num - 2); 
	}
}
