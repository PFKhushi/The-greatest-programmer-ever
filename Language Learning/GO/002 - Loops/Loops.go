package main

import(
        "fmt"
        "runtime"
        "time"
)
func tell_days(){
        today := time.Now().Weekday()   // Gets the weekday from the time now 
        switch time.Saturday{           // This is a type representing the weekday, if we convert to a number we'll get that day's number from 0 to 6
        case today + 0:                 // Here we have 0 + 0; Saturday is 6; today is sunday
                fmt.Println("Eh hj")
        case today + 1:                 // 0 + 1 
                fmt.Println("Eh amnh")
        case today + 2:                 // 0 + 2
                fmt.Println("Eh depois de amanha")
        default:                        // Since today is 0, it will fall on default
                fmt.Printf("Ta longe demais. Faltam %v dias\n", int(time.Saturday)-int(today))   // Since we are on the same week, we can just subtract
                                                                                                 // the target day from today to get how many days are between
        }
        
}
func switch_true(){
        switch{         // When you ommit the condition on a switch case, you can use it as a long if else
        case false:     // None of the false statements are going to run and only the first true statement will run
                fmt.Println("Falso")
        case false:
                fmt.Println("Falso")
        case true:  // Runs
                fmt.Println("CARALHO")
        case true:  // Doesn't run
                fmt.Println("Caralho")
        }
}
func switch_case(){
     fmt.Println("GO is using ")   
     switch os := runtime.GOOS; os {
        case "darwin":
        fmt.Println("OS X")
        case "linux":
        fmt.Println("Linux")
        default:
        fmt.Println(os)
     }  
}
func infinit_loop(){
        for{
        }
}

func defer_test(){
        for i:=0;i<5;i++{
                defer fmt.Println("world hello", i)    // This will only print the 5 times when the for loop ends in a last-in-first-out order 4, 3, 2, 1, 0
                fmt.Println("hello world", i)          // This will be printed normally with the for execution 0, 1, 2, 3, 4
        }
}

func Sqrt(x float64) (z float64){   // Since i name the returned type, i dont need to declare nor specify on return
        z=1.0
        z-=(z*z-x)/(2*x)
        return
}
func main(){

        tell_days()
        switch_true()
        switch_case()

        defer fmt.Println("test") // This defers the print funtion until the surrounding first level function is finishe
        defer_test()              // Since this has a defer inside, it will execute 
        sum := 0 
        sum1 := 0
        sum2 := 0
        for i:=0;i<5;i++ {  // Paranthesis are not required, but braces are always required
                sum+=1
        }
        fmt.Println(" ")
        for ;sum1<5;{       // The init and the increment are optional
                sum1++
        }
        for sum2<5{         // Different than C in Go if you ommit the init and the post statement, you can ommit the semicolons
                sum2++      // This basically transforms a for in a while loop, and that's why while in written as for in Go
        }

        fmt.Println(sum, sum1, sum2)
}
