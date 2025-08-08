const prompt = require('prompt-sync')();

// Atividades para switch
// EX1: Atividade 1: Identificando o Mês
// Dado um número de 1 a 12, imprima o nome do mês

let mes;
do{
    mes = parseInt(prompt("EX1: Digite um numero! (1 a 12)(0 para ir pro proximo exercicio): "));

        switch(mes) { 
            case 1:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Janeiro!`);
                break;

            case 2:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Fevereiro!`);
                break;

            case 3:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Marco!`);
                break;

            case 4:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Abril!`);
                break;

            case 5:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Maio!`);
                break;

            case 6:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Junho!`);
                break;
                
            case 7:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Julho!`);
                break;

            case 8:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Agosto!`);
                break;

            case 9:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Setembro!`);
                break;

            case 10:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Outubro!`);
                break;

            case 11:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Novembro!`);
                break;

            case 12:
                console.log(`EX1: O numero ${mes} se refere ao mesm de Dezembro!`);
                break;

            case 0: 
                console.log(`EX1: Saindo...`);
                break;

            default:
                console.log(`EX1: Opcao invalida!`);
        }
}while (mes !== 0);


// EX2: Receber dois números e uma operação (+, -, *, /) e usar switch para mostrar o resultado da operação.

let n1 = parseFloat(prompt(`EX2: Digite o primeiro numero: `));
let n2 = parseFloat(prompt(`EX2: Digite o segundo numero: `));
do{
    console.log(`EX2: Escolha um opcao: `);
    console.log(`EX2: 1 - Soma`);
    console.log(`EX2: 2 - Subtracao`);
    console.log(`EX2: 3 - Multiplicacao`);
    console.log(`EX2: 4 - Divisao`);
    console.log(`EX2: 0 - Ir para o proximo exercicio!`);
    opcao = parseInt(prompt(`EX2: Escolha uma opcao: `));

    switch(opcao){
        case 1:
            console.log(`EX2: A soma dos dois numero e: ${n1 + n2}`);
            break;

        case 2:
            console.log(`EX2: A subtracao dos dois numero e: ${n1 - n2}`);
            break;

        case 3:
            console.log(`EX2: A multiplicacao dos dois numero e: ${n1 * n2}`);
            break;

        case 4:
            console.log(`EX2: A divisao dos dois numero e: ${n1 / n2}`);
            break;

        case 0:
            console.log(`EX2: Saindo...`);
            break;

        default:
            console.log(`EX2: Opcao invalida!`);
    }
}while(opcao !== 0);

// Atividades para while
// EX3: Contagem até 10
// Escreva um programa que use while para imprimir os números de 1 a 10.

let contador = 1;
    while(contador <= 10){
        console.log(`EX3: ${contador}`);
        contador++
    }

// EX4: Somando Números até Parar
// O programa deve continuar pedindo números ao usuário até que ele digite 0. No fim, mostrar a soma total.

let soma = 0;
let numero = -1;

    while(numero !== 0){
        console.log(`EX4: Digite um numero (0 para parar): `);
        numero = parseFloat(prompt());
        soma += numero;
    }

    console.log(`EX4: A soma dos numeros e: ${soma}`);

// Atividades para for
// EX5: Tabuada de um Número
// Mostrar a tabuada de um número usando for.

n1 = parseFloat(prompt(`EX5: Digite um numero para receber sua tabuada: `));

    for(let i = 1; i <= 10; i++){
        console.log(`EX5: ${i} x ${n1} = ${i * n1}`);
    }

// EX6: Números Pares de 1 a 20
// Utilize for para imprimir todos os números pares de 1 até 20.

    for(i = 1; i <= 20; i++){
        if(i % 2 == 0){
            console.log(`EX6: O numero ${i} e par!`);
        }
    }