namespace Luck{

    class Program
    {
        static void Main(string[] args)
        {
                int[] num_escolhidos = faz_enemy();
                print_list(num_escolhidos);
                
                

        }
        static int[] faz_enemy(){
                Random num_gen = new Random();
                Console.WriteLine("Qual o nivel de dificuldade? \n1-Facil\n2-Normal\n3-Dificil\n");
                int nivel = (int)(Console.ReadKey().KeyChar)-'0'+2;//(Convert.ToInt32(Console.ReadKey().Key))-Convert.ToInt32('0')+2;
                Console.WriteLine("\""+nivel+"\"");
                while(!(2<nivel && nivel<6)){   
                        Console.WriteLine(" "+nivel + " Numero errado. Digite novamente ou pressione \"Crtl+c\" para encerrar jogo"); // Quando tiver um menu, ele vai ter opcao de voltar
                        nivel = (Convert.ToInt32(Console.ReadKey().Key))-Convert.ToInt32('0')+2;
                }
                int temp;

                int [] lista = new int[nivel];
                for(int i=0;i<nivel;i++){
                        temp = num_gen.Next(100);
                        if(!lista.Contains(temp)){
                                lista[i] = temp;
                                continue;
                        }
                        i-=1;
                }
                return lista;
        }
        static void print_list(int[] lista){
                for(int i=0;i<lista.Length;i++){
                        Console.WriteLine(lista[i]);
                }        
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
        String name = "Mc King's hut";

        public void nome(){
                Console.WriteLine(name);
        }
        
    }
}
