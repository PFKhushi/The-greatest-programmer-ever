package main

import (
	"fmt"
	"math"
	"math/cmplx"
)

var idade = 28   // This global variable is declared as an int 

var (            // This is also a declaration of a global variable, but declaring a group of variables 
        booleano bool =false // boolean value
        maior_posi64 uint = 1 << 64 - 1 // Unsigned Integer 64 bits
        z complex128 = cmplx.Sqrt(-5 + 12i)     // complex numbers

)
var (
        a int 
        b float64
        c string
        d bool
)
const(
        Big = 1<<100 // Creates a big numer shifting binary 1 a hundred 0 to the left
        Small = Big>>99 // This shifts the binary Big 99 zeros to the right, making a binary 10 or a decimal 2 it would be the same as 1<<1
)
func needInt(x int) int {return x*10+1}
func needFloat(x float64) float64 {return x * 0.1}
func print_const(){
        fmt.Println(complex128(Big))
        fmt.Println(int(Small))
        fmt.Println(needInt(Small))
        fmt.Println(needFloat(Small))
        fmt.Println(needFloat(Big))
}
func type_conversion(){
        var x,y int = 3,4
        var f float64 = math.Sqrt(float64(x*x+y*y))
        var z uint = uint(f)

        fmt.Printf("z = %v", z)
}

func print_vars(){
        fmt.Printf("\n\nType: %T Value: %v\n\n", booleano, booleano) // %T masks the variable type and %v masks the value
        fmt.Printf("Type: %T Value: %v\n\n", maior_posi64, maior_posi64)
        fmt.Printf("Type: %T Value: %v\n\n", z, z)
        fmt.Printf("Empty types\n\tint: %T %v \nfloat64: %T %v \nstring: %T %v \n bool: %T %v", a, a, b, b, c, c, d, d)
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
        const greet = "E ai, " // this is a constant and can be defined as impossible to change
        var number int  // The type int is going to allocate memory for 
        number = 2      // int32 or  int 64 depending on your system
        print(number)   // int | int8 | int16 | int32 | int64
                        //       alias          alias   
                        //       byte           rune   
                        //                      represents an untyped constant that stores the unicode; rune = 'a'; rune == 97
                                                
                        // uint uint8 uint16 uint32 uint64


                        // float32 float64
                        // complex64 complex128
        type_conversion() 
        print("\n")
        print_vars()
        print("\n")
        print_const()
        fmt.Println("Digite seu nome:")
         
        _, err := fmt.Scanln(&test)     // Scan returns 2 values: 
                                        // "_" tells the program to ignore
                                        // "err" gets the error values
                                        // cannot print _ 
        ReadLine(test)                          
        if err != nil {
                print(err)
        }
        fmt.Println(greet + test + "?")
}

