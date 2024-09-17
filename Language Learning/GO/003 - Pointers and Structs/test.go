package main

import(
        "fmt"
)

type Estrutura struct{  // Creating a structure that has 2 integers as members
        x int
        y int
}

type Pessoa struct{
        nome struct {
                primeiro_nome string
                ultimo_nome string
        }
        idade int
        altura float64 
}
type Pessoa1 struct{
        nome1
        idade int
        altura float64 
}

type nome1 struct {
        primeiro_nome string
        ultimo_nome string
}
func struct_test(){
        var test Estrutura  // Declaring a structure
        test.x = 5          // Setting individual variables of the structure
        test.y = 7

        var test2 Estrutura = Estrutura{7,5}    // Declaring a structure and assigning the values with the default constructor
        test3 := Estrutura{10, 10}              // Implicitly declaring a structure and using the constructor
        fmt.Printf("\n\nType: %T \nValue: %v\n\n", test, test)
        fmt.Printf("\n\nType: %T \nValue: %v\n\n", test2, test2)
        fmt.Printf("\n\nType: %T \nValue: %v\n\n", test3, test3)
        
        teste := Pessoa{
                nome: struct{primeiro_nome string; ultimo_nome string}{"Pedro","Firmino"},
                idade: 28, 
                altura: 1.79,
        }

        teste1 := Pessoa1{
                nome1: struct{primeiro_nome string; ultimo_nome string}{"Pedro","Firmino"},
                idade: 28, 
                altura: 1.79,
        }
        fmt.Println("",teste)
        fmt.Println("\n\n",teste1)

}

func main(){
        numero := 2                                                 // Here we declared an integer with value of 2
        var ponteiro *int = &numero                                 // Declaring a pointer to an integer and assigning the address of numero to it
        fmt.Printf("Type: %T\n Value: %v\n\n", ponteiro, *ponteiro) // Type of ponteiro is *int, and *ponteiro gets us the value of numero

        ponteirop := &ponteiro                                      // Since we assigning a pointer's address ponteirop'll be a **int

        **ponteirop = 3                                             // **ponteirop==numero so numero==3 now

        fmt.Printf("Type: %T\n *Type: %T\n **Type: %T\n Value: %v\n", ponteirop,*ponteirop, **ponteirop, **ponteirop)   // ponteirop->ponteiro->numero
                                                                                                                        // **int->*int->int
        struct_test()

}
