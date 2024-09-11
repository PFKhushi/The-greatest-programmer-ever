namespace Luck{

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
                //menu();
                Enemy test = new Enemy();  
                make_mesa_attack(test);
                //List<int> tet = new List<int>();
                //Console.WriteLine("\n\n"+tet.Count);
                //tet.Add(1);
                //Console.WriteLine("\n"+tet.Count);
                //test.test();
                
                
                

        }
        public static void menu(){
                Console.WriteLine("Menu: \n1 - Jogar\n2 - Sair");
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
                Console.Write("Digite seu nome: ");
                String? nome = Console.ReadLine();
                Player? player = new Player(nome);
                
        }
        public static List<int> make_mesa_attack(Enemy boss){
                
                Random rand = new Random();
                List<int> mesa = new List<int>();
                for(int i = 0; i<5; i++){
                        mesa.Add(-1);
                }
                int vida_boss = boss.get_vida().Count;

                mesa[rand.Next(mesa.Count)] = boss.get_vida()[rand.Next(vida_boss)];
                int temp;
                for(int i = 0; i<mesa.Count; i++){
                        if(mesa[i]==-1){
                                temp = rand.Next(100);
                                if(!mesa.Contains(temp) && !boss.get_vida().Contains(temp)){
                                        mesa[i]=temp;
                                }else{
                                        i-=1;
                                }
                        }
                }
                print_list(mesa);
                Console.WriteLine("\n");
                print_list(boss.get_vida());
                return mesa;

                
                
                //:lua vim.diagnostic.open_float()
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
    
        public class Player{
                private String name = "Player";
                private int vida = 5;

                public Player(String? new_name){
                        if(new_name!=null){
                                name = new_name;
                        }
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
        public class Enemy{
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
