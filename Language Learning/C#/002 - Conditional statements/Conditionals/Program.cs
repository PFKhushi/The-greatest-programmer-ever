namespace Condicional
{
    class Condicionals 
    {
       static void Main(String[] args){
                char resp = 'a';
                double a, b;
                char [] operacoes = {'+','-','*','/'};
                while (true)
                {
                        Console.WriteLine("Vc quer fazer um calculo? y/n ");
                        resp = Console.ReadKey().KeyChar;
                        if (resp == 'n')
                        {
                                return;
                        }
                        else
                        {
                                Console.Clear();
                                Console.WriteLine("Digite o numero a sofre a ser operado: ");
                                a = Convert.ToDouble(Console.ReadLine());
                                Console.WriteLine("Digite a operecao: |+|-|*|/| ");
                                resp = Console.ReadKey().KeyChar;
                                if (!operacoes.Contains(resp))
                                {
                                    Console.WriteLine("Operacao nao identificada!");
                                    break;
                                }
                                Console.WriteLine("\nDigite o numero q vai operar:");
                                b = Convert.ToDouble(Console.ReadLine());
                                Console.WriteLine("Resposta: "+Calcula(a,resp,b));
                                Console.WriteLine("\n");

                        }  
                }        
       }
       static double Calcula(double a, char op, double b){
               switch (op)
               {
                       case '+':
                               return a+b;
                       case '-':
                               return a-b;
                       case '*':
                               return a*b;
                       case '/':
                               return a/b;
                       default:
                               Console.WriteLine("Algo deu errado!");
                               return -1;

               }

       }
    }
}
