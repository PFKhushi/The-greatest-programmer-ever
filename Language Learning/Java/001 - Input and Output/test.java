import java.util.Scanner;

public class test{

       public static void main(String[] args) {
                
                Scanner scanner = new Scanner(System.in);
                System.out.println("Qual teu nome?");
                String nome = scanner.nextLine();
                System.out.println("Quantos anos vc tem?");
                int idade = scanner.nextInt();                      // nextInt n consome o char de nova linha ent el fica no buffer
                System.out.println("Qual a comida favorita?");      // e se n for limpo, pulara o proximo scan
                String comida = scanner.nextLine();
                System.out.println("Ola, "+nome+" .Vc tem "+idade+" anos e gosta de comer"+comida);

                System.out.println("Hello, motherfcker"); // A damn comment
                int x = 123;
                double y = 3.14;
                boolean z = true;
                char symbol = '@';
                String phrase = "Imma beat your ass";
                System.out.println(phrase + " " + symbol + " the beach, bitch " + (x+y) + z);
                                                          /*A
                                                           *damn
                                                           *longer
                                                           *comment
                                                           */
                

        }
        public static void Greeter() {

                System.out.println();
                
        }
        class Carro {
                private String marca, modelo;
                private int ano;

                public void name() {
                        
                }

        }
}
