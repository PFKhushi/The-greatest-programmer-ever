
public class Classes{

///////////////////////////////////////// 12 ////////////////////////////////////////////////
///////////////////////////////////////// 12 ////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////// 11 ////////////////////////////////////////////////
        public abstract class Funcionaria{
                
                
                public abstract double calcPagamento(int multiplicador, double preco);
        }

        static class Horarista extends Funcionaria{
                private String nome;
                private int horasTrabalhadas;
                private double precoHoras;
                private double pagamento;
                

                public void initHorarista(){
                        this.nome = "Pedro";
                        this.horasTrabalhadas = 1000;
                        this.precoHoras = 100;
                        this.pagamento = calcPagamento(this.horasTrabalhadas, this.precoHoras);
                }
                public double calcPagamento(int multiplicador, double preco){
                        return preco * (double)multiplicador;
                }
                public String getNome(){
                        return this.nome;
                }
                public void setNome(String nome){
                        this.nome = nome;
                }
                public double getPagamento(){
                        return this.pagamento;
                }



        }
        static class Assalariado{
                private String nome;
                private int mesesTrabalhados;
                private double salario;
                private double pagamento;
                

                public void initHorarista(){
                        this.nome = "Pedro";
                        this.mesesTrabalhados = 12;
                        this.salario = 10000;
                        this.pagamento = calcPagamento(this.mesesTrabalhados, this.salario);
                }
                public double calcPagamento(int multiplicador, double preco){
                        return preco * (double)multiplicador;
                }
                public String getNome(){
                        return this.nome;
                }
                public void setNome(String nome){
                        this.nome = nome;
                }
                public double getPagamento(){
                        return this.pagamento;
                }




        }
//////////////////////////////////////// 11 ////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////// 10 ////////////////////////////////////////////////
        static class calculadora {
                public int soma(int a, int b){
                        return a+b;
                }
                public int soma(int a, int b, int c){
                        return a+b+c;
                }
                
        }
/////////////////////////////////////// 10 ////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////// 9 ////////////////////////////////////////////////
        static class Relatorio implements Impressora{
                private String conteudo;

                public void FazRelatorio(String relatorio){
                        this.conteudo = relatorio;
                }
                public String getRelatorio(){
                        return this.conteudo;
                }

                public void imprimir(){
                        System.out.println(this.conteudo);
                }

        }       
        static class Contrato implements Impressora{
                private String conteudo;

                public void FazContrato(String contrato){
                        this.conteudo = contrato;
                }
                public String getContrato(){
                        return this.conteudo;
                }

                public void imprimir(){
                        System.out.println(this.conteudo);
                }

        } 


/////////////////////////////////////// 9 ////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////// 8 ////////////////////////////////////////////////
        static class Empregado{
                private String nome, id;

                public void setNome(String nome){
                        this.nome = nome;
                        this.id = "9";
                }

                public String getNome(){
                        return this.nome;
                }
                public String getID(){
                        return this.id;
                }
        } 
        static class Empresa{
                private String nome;
                private int num_empregados;
                private Empregado[] empregados;
        
                public void CriaEmpresa(String nome){
                        this.nome = nome;
                        this.empregados = new Empregado[0];
                        this.num_empregados = 0;
                }
                public void AddEmpregado(Empregado empregado){
                        
                        Empregado[] temp = new Empregado[this.num_empregados+1];
                        for(int i = 0; i<this.num_empregados; i++){
                                temp[i] = this.empregados[i];
                        }                        
                        temp[this.num_empregados] = empregado;
                        empregados = temp;
                        this.num_empregados++;
                }

        }
/////////////////////////////////////// 8 ////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////// 7 /////////////////////////////////////////////////
        static class Professor{

                private String nome;
                private int num_esco;
                private Escola[] escolas;
                
                public void CriaProfessor(String nome){
                        this.nome = nome;
                        this.escolas = new Escola[0];
                        this.num_esco = 0;
                }
                public void AddEscola(Escola esco){
                        Escola[] temp = new Escola[this.num_esco+1];
                        for(int i = 0; i<this.num_esco; i++){
                                temp[i]=this.escolas[i];

                        }
                        temp[this.num_esco] = esco;
                        this.escolas = temp;
                        this.num_esco++;
                }

        }
        static class Escola{

                private String nome;
                private int num_prof;
                private Professor[] professores;

                public void CriaEscola(String nome){
                        this.nome = nome;
                        this.professores = new Professor[0];
                        this.num_prof = 0;
                }
                public void AddProfessor(Professor prof){
                        Professor[] temp = new Professor[this.num_prof+1];
                        for(int i = 0; i < this.num_prof; i++){
                                temp[i]= this.professores[i];

                        }
                        temp[this.num_prof] = prof;
                        this.professores = temp;
                        this.num_prof++;
                }

                
        }

/////////////////////////////////////// 7 ////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////// 4 / 5 //////////////////////////////////////////////
        static class Animal{
                private String som;

                public void Falar(){
                        System.out.println(this.som);
                }
                public void CriaSom(String som){
                        this.som = som;
                }
                public String getFala(){
                        return this.som;
                }
        }
        static class Cachorro extends Animal{
                private String nome;
                private int idade;
                private Animal animal;

                public void CriaCao(String nome){
                        this.nome = nome;
                        this.idade = 0;
                        this.animal = new Animal();
                        this.animal.CriaSom("Au au!");
                }
                public void PrintCao(){
                        System.out.println("Nome: " + this.nome + "\nIdade: " + this.idade + "\nFala: " + this.animal.getFala());
                        Falar();
                }
                public void setNome(String nome){
                        this.nome = nome;
                }
                public String getNome(){
                        return this.nome;
                }
                public void setIdade(int idade){
                        this.idade = idade;
                }
                public int getIdade(){
                        return this.idade;
                }
                public void Falar(){
                        this.animal.Falar();
                }
                public void setFala(String fala){
                        this.animal.CriaSom(fala);
                }
        }
        static class Gato extends Animal{
                private String nome;
                private int idade;
                private Animal animal;

                public void CriaGato(String nome){
                        this.nome = nome;
                        this.idade = 0;
                        this.animal = new Animal();
                        this.animal.CriaSom("Miau!");
                }
                public void PrintGato(){
                        System.out.println("Nome: " + this.nome + "\nIdade: " + this.idade + "\nFala: " + this.animal.getFala());
                        Falar();
                }
                public void setNome(String nome){
                        this.nome = nome;
                }
                public String getNome(){
                        return this.nome;
                }
                public void setIdade(int idade){
                        this.idade = idade;
                }
                public int getIdade(){
                        return this.idade;
                }
                public void Falar(){
                        this.animal.Falar();
                }
                public void setFala(String fala){
                        this.animal.CriaSom(fala);
                }
                
        }
///////////////////////////////////// 4 / 5 /////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////// 3 ////////////////////////////////////////////////

        static class ContaBancaria{

               private String titular;
               private double saldo;

               public void criaConta(String titular){
                        this.titular = titular;
                        this.saldo = 0;
               }
               public void printConta(){
                        System.out.println("Titular: " + this.titular + "\nSaldo: R$" + this.saldo);
               }
               public String getTitular(){
                        return this.titular;
               }
               public double getSaldo(){
                        return this.saldo;
               }
               public void depositar(double deposito){
                        this.saldo += deposito;
               }
               public int sacar(double saque){
                        if (saque > this.saldo){
                                return -1;
                        }else{
                                this.saldo -= saque;
                                return 0;
                        }
               }
        }
///////////////////////////////////// 3 /////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////// 1 / 2 / 6 ///////////////////////////////////////////
        static class Motor{
                private int cavalos;

                public void setCavalos(int cavalos){
                        this.cavalos = cavalos;
                }
                public int getCavalos(){
                        return this.cavalos;
                }
                public void printCavalos(){
                        System.out.println("O motor tem " + cavalos + " cavalos de potencia");
                }
        }
        static class Carro{
                private String marca, modelo;
                private int ano;
                private double velocidade;
                private Motor motor;
                
                public void FazCarro(String marca, String modelo, int ano, int cavalos) {
                      this.marca = marca;  
                      this.modelo = modelo;
                      this.ano = ano;
                      this.velocidade = 0;
                      this.motor = new Motor();
                      this.motor.setCavalos(cavalos);
                }
                public void setMarca(String marca){
                        this.marca = marca;
                }
                public void serModelo(String modelo){
                        this.modelo = modelo;
                }
                public void setAno(int ano){
                        this.ano = ano;
                }
                public void setVelocidade(double velocidade){
                        this.velocidade = velocidade;
                }
                public String getMarca(){
                        return this.marca;
                }
                public String getModelo(){
                        return this.modelo;
                }
                public int getAno(){
                        return this.ano;
                }
                public double getVelo(){
                        return this.velocidade;
                }
                public void Acelerar(double velocidade){
                        this.velocidade += velocidade;
                }
                public void Desacelerar(double velocidade){
                        this.velocidade = this.velocidade < velocidade ? 0 : (this.velocidade - velocidade); 
                }
                public void setCavalos(int cavalos){
                        this.motor.setCavalos(cavalos);
                }
                public int getCavalos(){
                        return this.motor.getCavalos();
                }
                public void printMotor(){
                        this.motor.printCavalos();
                }

        }
       
/////////////////////////////////// 1 / 2 / 6 ////////////////////////////////////////////
}
