﻿namespace Luck{

    class Program
    {
        static void Main(string[] args)
        {
                //int[] num_escolhidos = faz_enemy();
                //print_list(num_escolhidos);
                //Player test = new Player();
                //test.nome();
                //int [] tere = new int[5];
                //Console.WriteLine(":::\n"+tere.Length);
                menu();
                //Enemy test = new Enemy();  
                //List<int> tet = new List<int>();
                //Console.WriteLine("\n\n"+tet.Count);
                //tet.Add(1);
                //Console.WriteLine("\n"+tet.Count);
                //test.test();
                
                
                

        }
        public static void menu(){
                Console.WriteLine("Menu: \n1 - Jogar\n 2 - Sair");
                int op =(int)Console.ReadKey().KeyChar-'0';
                switch (op)
                {
                        case 1:
                        jogo();
                        menu();
                        break;
                        case 2:
                        return;
                }
                
        }
        public static void jogo(){
                Enemy boss = new Enemy();
                
        }
        public static void print_mesa_attack(Enemy boss)                                                 {
                Random rand = new Random();
                int[] mesa = new int[5]; 
                int test = rand.Next(boss.Count);
                int j = boss.Count;
                for(int i=0; i < j;i++){
                        mesa[i] = rand.Next(boss.Count());
                }//:lua vim.diagnostic.open_float()
        }
        public static List<int> faz_enemy(){
                Random num_gen = new Random();
                Console.WriteLine("Qual o nivel de dificuldade? \n1-Facil\n2-Normal\n3-Dificil\n");
                int nivel = (int)(Console.ReadKey().KeyChar)-'0'+2;
                Console.WriteLine("\""+nivel+"\"");
                while(!(2<nivel && nivel<6)){   
                        Console.WriteLine(" "+nivel + " Numero errado. Digite novamente ou pressione \"Crtl+c\" para encerrar jogo"); // Quando tiver um menu, ele vai ter opcao de voltar
                        nivel = (int)(Console.ReadKey().KeyChar)-'0'+2;
                }
                int temp;

                List<int> lista = new List<int>();
                for(int i=0;i<nivel;i++){
                        temp = num_gen.Next(100);
                        if(!lista.Contains(temp)){
                                lista.Add(temp);
                                continue;
                        }
                        i-=1;
                }
                return lista;
        }
        static void print_list(List<int> lista){
                for(int i=0;i<lista.Count;i++){
                        Console.WriteLine(lista[i]);
                }        
        }
    
        class Player{
                private String name = "Player";
                private int vida = 5;

                public Player(String new_name){
                        name = new_name;
                }
                public void nome(){
                        Console.WriteLine(name);
                }
                public void dano(){
                        vida--;
                }
                public void esqv_succss(){
                        vida++;
                }
                public void esqv_fail(){
                        vida-=2;
                }

        } 
        class Enemy{
                private String name = "Mc King's hut";
                private List<int> vida = faz_enemy();
                public void nome(){
                        Console.WriteLine(name);
                }
                public void test(){
                        print_list(vida);
                }
                public String get_name(){
                        return name;
                }
                public List<int> get_vida(){
                        return vida;
                }
        }
    }
    
}
