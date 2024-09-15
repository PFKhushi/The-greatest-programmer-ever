package main

import (
	"fmt"
    "math/cmplx"
)

var idade = 28   // This global variable is declared as an int 

var (
        booleano bool = false
        maior_posi64 uint = 1 << 64 - 1
        z complex128 = cmplx.Sqrt(-5 + 12i)

)
func print_vars(){
        fmt.Printf("\n\nType: %T Value: %v\n\n", booleano, booleano)
        fmt.Printf("Type: %T Value: %v\n\n", maior_posi64, maior_posi64)
        fmt.Printf("Type: %T Value: %v\n\n", z, z)
}

func ReadLine(input string){
        print(input)
        var test int = idade 
        print(test)
        input =  "test"
        print(input)
}
func Add(a, b int) int {// This function is getting two integers and returns one integer 
                        // Since the parameters are teh same type we can ommit all but
                        // the last type declaration
                        // The last type type declaration means what the function is returning 
        return a+b
}
func Swap(a, b string)(string, string){ // Swap get two strings and returns two strings
        return b, a
}
func Swap2(a, b string)(x, y string){

        return
}

func main() {
        var test string
        var number int  // The type int is going to allocate memory for 
        number = 2      // int32 or  int 64 depending on your system
        print(number)   // int | int8 | int16 | int32 | int64
                        //       alias          alias   
                        //       byte           rune   
                        //                      represents an untyped constant that stores the unicode; rune = 'a'; rune == 97
                                                
                        // uint uint8 uint16 uint32 uint64


                        // float32 float64
                        // complex64 complex128
         
        print_vars()
        print("\n")
        fmt.Println("Digite seu nome:")
         
        _, err := fmt.Scanln(&test)     // Scanln returns 2 values: _ gets something (?); err gets the error values
                                        // cannot print _;  
        ReadLine(test)
        if err != nil {
                print(err)
        }
        fmt.Println("E ai, "+test+"?")
}

