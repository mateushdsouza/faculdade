// EX1: Criando a primeira verificacao!

const prompt = require('prompt-sync')();

let nota = parseFloat(prompt("EX1: Digite a nota do aluno (0 a 10): "));

    if (isNaN(nota) || nota < 0 || nota > 10) {
        console.log("EX1: Por favor, digite uma nota valida entre 0 e 10.");
    }else{ 
        if (nota>= 7){
            console.log("EX1: Aprovado! parabéns");
        }else if( nota >= 5){
            console.log("EX1: Em recuperacao. Estude mais.");
        }else{
            console.log("EX1: Reprovado. Continue tentando!");
        }
    }

// EX2: Crie um programa que solicite um número ao usuário e informe se ele é positivo, negativo ou zero.

let numero = parseFloat(prompt(`EX2: Digite um numero: `));

    if(numero > 0){
        console.log(`EX2: Maior que zero!`);
    }else if(numero < 0){
        console.log(`EX2: Menor que zero!`);
    }else{
        console.log(`EX2: O numero e igual a zero!`);
    }

// EX3: Crie um programa que pergunte a idade de uma pessoa e informe se ela é maior de idade (18 anos ou mais) ou menor de idade.

let idade = prompt(`EX3: Digite sua idade: `);

    if(idade >= 18){
        console.log(`EX3: Voce e maior de idade!`);
    }else{
        console.log(`EX3: Voce ainda nao alcancou a maioridade!`);
    }

// EX4: Crie um programa que peça um número ao usuário e informe se ele é par ou ímpar.

numero = parseFloat(prompt(`EX4: Digite um numero: `));

    if(numero % 2 == 0){
        console.log(`EX4: O numero e par!`);
    }else{
        console.log(`EX4: O numero e impar!`);
    }

// EX5: Peça ao usuário um nome de usuário e uma senha. 
// Se o usuário digitar "admin" como nome e "1234" como senha, mostre "Login bem-sucedido!". Caso contrário, mostre "Usuário ou senha incorretos.".

let nome = prompt(`EX5: Digite um nome: `);
let senha = prompt(`EX5: Digite uma senha: `);

    if(nome == "admin" && senha == "1234"){
        console.log(`EX5: Login bem-sucedido!`);
    }else{
        console.log(`EX5: Usuário ou senha incorretos.`);
    }

// EX6: Solicite ao usuário o valor total da compra.
// Se for maior ou igual a 100, aplique 10% de desconto
// Caso contrário, aplique 5% de desconto
// Mostre o valor final com desconto.

let total = parseFloat(prompt(`EX6: Digite o valor total da compra: `));

    if(total >= 100){
        console.log(`EX6: O valor final fica ${total-(total/10)}`);
    }else{
        console.log(`EX6: O valor final fica ${total-(total/5)}`);
    }
