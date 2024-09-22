package Pacote

import (
	"fmt"
)
type titular struct {
        nome string
        idade int
}
type ContaBancaria struct{
        titular
        saldo float64
}

func(conta *ContaBancaria)Cria_conta(nome string, idade int){

        conta.titular = titular{nome, idade} 
        conta.saldo = 0 
}

func(conta *ContaBancaria)Sacar(valor float64)(error){
        var err error = nil
        if conta.saldo < valor {
                err = fmt.Errorf("Vc n tem esse dinheiro")
        }else{
                conta.saldo -= valor
                fmt.Println("Operacao bem sucedida!")

        }
        return err 
}

func(conta *ContaBancaria)Depositar(valor float64){
        conta.saldo += valor
}

func(conta *ContaBancaria)Print_conta(){
        fmt.Printf("\n\nNome: %v\nIdade: %v\nSaldo: R$%.2f\n\n", conta.titular.nome, conta.titular.idade, conta.saldo)
}
