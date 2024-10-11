package Pacote

import (
	"errors"
	"fmt"
)

type SaldoInsuficiente struct {
	Err error
}

func (r *SaldoInsuficiente) Error() string {
	return fmt.Sprintf("err %v", r.Err)
}

func doRequest() error {
	return &SaldoInsuficiente{Err: errors.New("Sem dinheiro")}
}

type titular struct {
	nome  string
	idade int
}
type ContaBancaria struct {
	titular
	saldo float64
}

func (conta *ContaBancaria) Cria_conta(nome string, idade int) {

	conta.titular = titular{nome, idade}
	conta.saldo = 0
}

func (conta *ContaBancaria) Sacar(valor float64) error {
	err := doRequest()
	if conta.saldo < valor {
		fmt.Println(err)
	} else {
		conta.saldo -= valor
		fmt.Println("Operacao bem sucedida!")

	}
	return err
}

func (conta *ContaBancaria) Depositar(valor float64) {
	conta.saldo += valor
}

func (conta *ContaBancaria) Print_conta() {
	fmt.Printf("\n\nNome: %v\nIdade: %v\nSaldo: R$%.2f\n\n", conta.titular.nome, conta.titular.idade, conta.saldo)
}
