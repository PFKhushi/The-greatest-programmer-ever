package main
import(
        "fmt"
        "lista/pkgs"
)
func main(){

        singlezao()
}
// ======================= 15 =========================== 

// ======================= 15 =========================== 

//==============================================================================================================

// ======================= 14 =========================== 
func singlezao(){
        ss := struct{
                nome string 
                idade int}{
                        nome: "Pedro", 
                        idade: 28,
                }
        fmt.Printf("Meu nome eh %v e eu tenho %v anos\n", ss.nome, ss.idade)
}
// ======================= 14 =========================== 

//==============================================================================================================

// ======================= 13 =========================== 
func fibonacci(fib int)(int){
        if fib<2 {
                return 1
        }else{
                return fibonacci(fib-1)+fibonacci(fib-2)
        }
}
func fatorial(fator int)(int){
        if fator > 1{
                fator *= fatorial(fator-1)
        }
        return fator
}
// ======================= 13 =========================== 

//==============================================================================================================

// ======================= 12 =========================== 
type lista_produto struct{
        itens []produto
        total_price float64
}
type produto struct{
        nome string
        preco float64
}
func (lp *lista_produto)_preco(prods ...produto){
        for _, elemt := range prods{
                lp.itens = append(lp.itens, elemt)
                lp.total_price += elemt.preco
        }

}
// ======================= 12 =========================== 

//==============================================================================================================

// ======================= 11 =========================== 
type funcionoriu interface{
        calc_salario()
        print_salario()
}      
type horarista struct{
        preco_hora, salario float64
        horas int
}
func(h *horarista)calc_salario(){
        h.salario = h.preco_hora*float64(h.horas)
}
func (h horarista)print_salario(){
        fmt.Printf("O salario do horaris por %v horas trabalhadas, sera de R$%v.", h.horas, h.salario)
}

type assalariado struct{
        salario, preco_contrato float64
        meses int
}
func (a *assalariado)calc_salario(){
        a.salario = a.preco_contrato*float64(a.meses)
}
func (a assalariado)print_salario(){
        fmt.Printf("O salario do assalariado por %v meses trabalhados, sera de R$%v.", a.meses, a.salario)
}

// ======================= 11 =========================== 

//==============================================================================================================

// ======================= 10 =========================== calc_sum(int,int,int,.....,int) para executar funcao 
func calc_sum(nums ...int){
        total := 0
        for _, num := range nums{
                total += num
        }
        fmt.Println("Total da soma:",total)
}
// ======================= 10 =========================== 

//==============================================================================================================

// ======================= 9 =========================== 

type imprimiveis interface{
        imprimir_papel()
}
type relatorio struct{
        content string
}
func (r relatorio)imprimir_papel(){
        fmt.Println(r.content)
}
type contrato struct{
        content string
}
func (c contrato)imprimir_papel(){
        fmt.Println(c.content)
}
func exercicio9(){
        relatorio := relatorio{"Relatorio"}
        contrato := contrato{"Contrato"}
        relatorio.imprimir_papel()
        contrato.imprimir_papel()

}
// ======================= 9 =========================== 

//==============================================================================================================

// ======================= 8 =========================== 
type empresa struct{
        funcionarios []funcionario
}
type funcionario struct{
        nomes, cargo string
        salario float64
}
// ======================= 8 =========================== 

//==============================================================================================================

// ======================= 7 =========================== 
type aluno struct{
        nome string
        professores []professor
}
type professor struct{
        nome string
        alunos []aluno
}
// ======================= 7 =========================== 

//==============================================================================================================

// ======================= 6 =========================== 
// Adicionei a solucao desse exercicio ao exercicio 1 e 2
// ======================= 6 =========================== 

//==============================================================================================================

// ======================= 5 =========================== 
// Exercicio 4 e 5 tem solucoes conjuntas
type Animals interface{
        Print_animal()

}
func (cao Cao)Print_animal(){
        fmt.Printf("O cachorro faz: \"%v\", pesa %v e se chama %v!", cao.fala, cao.peso, cao.nome)
 }
func (gato Gato)Print_animal(){
        fmt.Printf("O gato faz: \"%v\", pesa %v e se chama %v!", gato.fala, gato.peso, gato.nome)
}
func imprimir_animais(animals []Animals){
        for _, animal := range animals{
                fmt.Println(animal)
                animal.Print_animal()
                fmt.Printf("\n\n\n")
                
        }
}

// ======================= 5 =========================== 

//==============================================================================================================

// ======================= 4 =========================== exercicio4() para executar exercicio 
// Exercicio 4 e 5 tem solucoes conjuntas

type Cao struct {
        Animal
        fala string
}

type Gato struct {
        Animal
        fala string
}

type Animal struct{
        nome string
        peso float64
}

func (cao *Cao)cria_cao(nome string, peso float64){
        cao.Animal = Animal{nome, peso}
        cao.fala = "woof"
}
func (gato *Gato)cria_gato(nome string, peso float64){
        gato.Animal = Animal{nome, peso}
        gato.fala = "miau"
}

func cria_animais()(gato Gato, cao Cao){
        gato.cria_gato("Xana", 15.76)
        cao.cria_cao("Dogao", 23.65)
        return
}
func exercicio4(){
        gato, cao := cria_animais()
        lista_animais := []Animals{gato,cao}
        imprimir_animais(lista_animais)


        


}

// ======================= 4 =========================== 

//==============================================================================================================

// ======================= 3 =========================== 
//
// Go n eh oop e parece q encapsulamento n eh encorajado
// mas se eu colocar a estrutura em um package separado e
// deixar as veriaveis comecando com minusculas para q n
// sejam exportadas, estarao disponiveis apenas dentro do 
// package e as funcoes exportadas nos dao acesso aos valores 
//
// Esse package esta disponivel em "./pkgs/test.go"
func ContadoBanco(){
        var err error
        var conta Pacote.ContaBancaria
        conta.Cria_conta("Pedro", 28)
        conta.Depositar(100)
        conta.Print_conta()
        err = conta.Sacar(57.83)
        if err == nil{
                fmt.Println(err)
        }
        conta.Print_conta()
}

// ======================= 3 =========================== 


//==============================================================================================================


// ====================== 1; 2; 6 ========================== Imprimir_Carro() para executar exercicio
type motor struct {
        cavalos int 
}
type Carro struct{
        marca string
        modelo string
        ano int
        motor
        velocidade int

}
func (car Carro) Print_Carro(){
        fmt.Println("\n\nModelo:", car.modelo)
        fmt.Println("Marca:", car.marca)
        fmt.Println("Ano:", car.ano)
        fmt.Printf("Motor com %v cavalos\n", car.motor.cavalos)
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
        
        carro1 := Carro{"VolksWagen","Golf", 2022, motor{150}, 0}
        carro2 := Carro{"VolksWagen","Polo", 2024, motor{120}, 0}
        carro3 := Carro{"Citroen","Saxo", 2002, motor{200}, 0}
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

