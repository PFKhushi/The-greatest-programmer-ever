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
                menu();
                
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
                Player player = new Player(nome);
                
                for(int i = 0; (boss.get_vida().Count>=0 && player.get_vida()>=0); i++ ){
                        
                        current_round(player, boss, i);
                        Console.WriteLine("Boss: "+boss.get_vida().Count);
                        Console.WriteLine("Player: "+player.get_vida());

                        
                }
                if(boss.get_vida().Count>player.get_vida()){
                        Console.WriteLine(player.get_nome() + " perdeu!");        
                }else{
                        Console.WriteLine(player.get_nome() + " ganhou!");        
                        
                }

                
        }
        public static void current_round(Player player, Enemy boss, int round_number){
                List<int> mesa = make_mesa_attack(boss);
                Console.WriteLine("Round: " + round_number + " iniciado!\n");
                Console.WriteLine("O q vc quer fazer?\n");
                int resp;
                while(true){
                
                        Console.WriteLine("\n1 - Atacar\n2 - Esquivar\n3 - Desistir"); 
                        resp = (int)(Console.ReadKey().KeyChar)-'0';
                        Console.WriteLine("dsfadsf"+resp);
                        if(resp>0 && resp<4){
                                break;
                        }
                        Console.WriteLine("Nao entendi..");
                }
                switch (resp){
                case 1:
                        Atacar(boss, player, mesa);
                        break;
                case 2:
                        Esquivar(boss, player);
                        break;
                case 3:
                        Desistir(player);
                        break;
                }

                
                

        }
        public static void Atacar(Enemy boss, Player player, List<int> mesa){
                
                String? temp;
                int resp = -1;
                while(true){
                        try{    
                                print_list(mesa);
                                Console.WriteLine("Qual dos numeros da mesa pertence ao boss? ou Digite sair para voltar ao menu\n");
                                temp = Console.ReadLine();
                                if(temp == "sair"){
                                        menu();
                                }
                                resp = temp is null ? -1 : Int32.Parse(temp);
                                if(resp == -1){
                                        Console.WriteLine("Digite algum numero");
                                        continue;
                                }
                                if(!mesa.Contains(resp)){
                                        Console.WriteLine("Numero n faz parte da mesa");
                                        continue;
                                }
                                break;
                        }
                        catch(FormatException){
                                Console.Write("Digite apenas numeros");

                        }
                }
                if(boss.get_vida().Contains(resp)){
                        boss.remove_life(resp);
                }else{
                        player.dano();
                }
                
        }
        public static void Esquivar(Enemy boss, Player player){
                Random rand = new Random();
                if(rand.Next(100)<50){
                        player.esqv_fail();
                }else{
                        player.esqv_succss();
                }
        }
        public static void Desistir(Player player){
                player.player_scd();
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
                Console.Write("| ");
                for(int i=0;i<lista.Count;i++){
                        Console.Write(lista[i]);
                        Console.Write(" | ");
                }       
                Console.WriteLine(" ");
        }
        public class Player{
                private String name = "Player";
                private String[] players_mdls = {" (ง ͠°_°)ง "," ( ･益･)ﾉ⌒●* "," [¬ºд °] ¬ "," (´×︹×`) ",""};
                private int vida = 5;

                public Player(String? new_name){
                        if(new_name!=null){
                                name = new_name;
                        }
                }
                public String get_nome(){
                        return name;
                }
                public int get_vida(){
                        return vida;
                }
                public void player_scd(){
                        vida=-1;
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
                private String[] enemy_mdls = {"(＾⌣＾)","╭∩╮(´• ᴗ •`˵)╭∩╮", "﴾⨱﹏⨱﴿","ヽ(ｏ`д′ｏ) ﾉ"};
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
                public void remove_life(int ponto){
                        vida.Remove(ponto);
                }
        }
    }
    
}

