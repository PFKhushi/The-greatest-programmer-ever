package main
import(
        "fmt"
        "lista/pkgs"
)
func main(){

        
        ContadoBanco()
}

// ======================= 3 =========================== 
// Go n eh oop e parece q encapsulamento n eh encorajado
// mas se eu colocar a estrutura em um package separado e
// deixar as veriaveis comecando com minusculas para q n
// sejam exportadas, estarao disponiveis apenas dentro do 
// package e as funcoes exportadas nos dao acesso aos valores 
//
// Esse package esta disponivel em "./pkgs/test.go"
func ContadoBanco(){
        var conta Pacote.ContaBancaria
        conta.Cria_conta("Pedro", 28)
        conta.Depositar(100)
        conta.Print_conta()
        conta.Sacar(57.83)
        conta.Print_conta()
}
// ======================= 3 =========================== 





// ====================== 1; 2 ========================== Imprimir_Carro() para executar exercicio

type Carro struct{
        marca string
        modelo string
        ano int

        velocidade int

}
func (car Carro) Print_Carro(){
        fmt.Println("\n\nModelo:", car.modelo)
        fmt.Println("Marca:", car.marca)
        fmt.Println("Ano:", car.ano)
        fmt.Println("Velocidade: ", car.velocidade, "Km/h"); fmt.Println("test") // Problema de seguranca caso o editor n tenha wrap ativado, escondivel
}

func (car *Carro) Acelerar(velocidade int){
        car.velocidade+=velocidade
}
func (car *Carro) Desacelerar(velocidade int){
        car.velocidade-=velocidade
}
func (car *Carro) Parar(){
        car.velocidade=0
}

func Imprimir_Carro(){
        
        carro1 := Carro{"VolksWagen","Golf", 2022, 0}
        carro2 := Carro{"VolksWagen","Polo", 2024, 0}
        carro3 := Carro{"Citroen","Saxo", 2002, 0}
        carro1.Print_Carro()
        carro2.Print_Carro()
        carro3.Print_Carro()
        carro1.Acelerar(200)
        carro2.Acelerar(180)
        carro3.Acelerar(120)
        carro1.Print_Carro()
        carro2.Print_Carro()
        carro3.Print_Carro()      
        carro1.Desacelerar(120)
        carro2.Desacelerar(85)
        carro3.Desacelerar(30)
        carro1.Print_Carro()
        carro2.Print_Carro()
        carro3.Print_Carro()
        carro1.Parar()
        carro2.Parar()
        carro3.Parar()
        carro1.Print_Carro()
        carro2.Print_Carro()
        carro3.Print_Carro()
}
// ======================1==========================

