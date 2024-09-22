import java.util.Scanner;


public class Solucoes{

        public static void main(String[] args) {

               Exercicio_4_5(); 

        }

////////////////////////////////////////////// 12 /////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////// 12 /////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////// 11 /////////////////////////////////////////////////////////////////////////

        public static void Exercicio_11(){

                Classes.Horarista horarista = new Classes.Horarista(); // Aqui o mesmo codigo q a jdtls indica como errado no outro arquivo, aqui n tem nada
                Classes.Assalariado assalariado = new Classes.Assalariado();    // talvez tenha alguma coisa a ver com o diretorio, mas ainda n tenho certeza


                horarista.initHorarista();
                assalariado.initHorarista();
                
                horarista.getPagamento();
                assalariado.getPagamento();

        }

////////////////////////////////////////////// 11 /////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////// 10 /////////////////////////////////////////////////////////////////////////

       public static void calc (){
                Classes.calculadora calcu = new Classes.calculadora();
                System.out.println(calcu.soma(1,2));
                System.out.println(calcu.soma(1,2,3));


       } 
///////////////////////////////////////////// 10 /////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////// 9 /////////////////////////////////////////////////////////////////////////
        public static void Exercicio_9(){
                Classes.Relatorio relatorio = new Classes.Relatorio();
                Classes.Contrato contrato = new Classes.Contrato();

                relatorio.FazRelatorio("Relatorio");
                contrato.FazContrato("Contrato");

                relatorio.imprimir();
                contrato.imprimir();
        }
///////////////////////////////////////////// 9 /////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////// 8 /////////////////////////////////////////////////////////////////////////
        public static void Exercicio_8(){
                Classes.Empregado empregado = new Classes.Empregado();
                Classes.Empresa empresa = new Classes.Empresa();

                empregado.setNome("Pedro");
                empresa.CriaEmpresa("Google");

                empresa.AddEmpregado(empregado);

        }
///////////////////////////////////////////// 8 /////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////// 7 /////////////////////////////////////////////////////////////////////////////
        public static void Exercicio_7(){
                Classes.Escola escola = new Classes.Escola();
                Classes.Professor professor = new Classes.Professor();
        }
////////////////////////////////////////////// 7 /////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////// 4 / 5 /////////////////////////////////////////////////////////////////////////
        public static void Exercicio_4_5(){
                Classes.Cachorro cao = new Classes.Cachorro();
                Classes.Gato gato = new Classes.Gato();
                cao.CriaCao("Bob");
                gato.CriaGato("Xaninha");
                cao.PrintCao();
                gato.PrintGato();
                cao.Falar(); // Eu n sei se entendi como era pra ser o polymorphism
                gato.Falar();
        }
///////////////////////////////////////////// 4 / 5 /////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////// 3 /////////////////////////////////////////////////////////////////////////////

        public static void Exercicio_3(){
                Classes.ContaBancaria conta = new Classes.ContaBancaria();
                conta.criaConta("Pedro Firmino");
                
                conta.printConta();
                
                if(conta.sacar(100) == 0){
                        System.out.println("Saque bem sucedido");
                        conta.printConta();
                }else{
                        System.out.println("Voce n tem dinheiro");
                        conta.printConta();
                }
                
                conta.depositar(1000);
                conta.printConta();
                
                if(conta.sacar(100) == 0){
                        System.out.println("Saque bem sucedido");
                        conta.printConta();
                }else{
                        System.out.println("Voce n tem dinheiro");
                        conta.printConta();
                }               
                conta.sacar(100);
        
        }

///////////////////////////////////////////// 3 /////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////// 1 / 2 / 6 /////////////////////////////////////////////////////////////////////////

        public static void Exercicio_1_2_6(){

                Classes.Carro carr = new Classes.Carro();
                Classes.Carro carr1 = new Classes.Carro();

                carr.FazCarro("Volkswagen", "Golf", 2022, 240);
                carr1.FazCarro("Volkswagen", "Polo", 2024, 300);

                System.out.println(carr.getMarca() + " " + carr.getModelo() + " " + String.valueOf(carr.getAno()) + " " + String.valueOf(carr.getVelo()));
                carr.printMotor();
                System.out.println(carr1.getMarca() + " " + carr1.getModelo() + " " + String.valueOf(carr1.getAno()) + " " + String.valueOf(carr1.getVelo()));
                carr1.printMotor();
                
                carr.Acelerar(250);
                carr1.Acelerar(200);

                System.out.println(carr.getMarca() + " " + carr.getModelo() + " " + String.valueOf(carr.getAno()) + " " + String.valueOf(carr.getVelo()));
                carr.printMotor();
                System.out.println(carr1.getMarca() + " " + carr1.getModelo() + " " + String.valueOf(carr1.getAno()) + " " + String.valueOf(carr1.getVelo()));
                carr1.printMotor();
                
                carr.Desacelerar(1000);
                carr1.Desacelerar(200);

                System.out.println(carr.getMarca() + " " + carr.getModelo() + " " + String.valueOf(carr.getAno()) + " " + String.valueOf(carr.getVelo()));
                carr.printMotor();
                System.out.println(carr1.getMarca() + " " + carr1.getModelo() + " " + String.valueOf(carr1.getAno()) + " " + String.valueOf(carr1.getVelo()));
                carr1.printMotor();
   

        }
}


