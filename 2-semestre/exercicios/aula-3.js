// EXERCICIO 1
let n1 = 3;
let n2 = 4;

console.log("EX1: Soma: " + (n1 + n2));

// EXERCICIO 2
let valor = 10-2;
console.log("EX2: Valor: " + valor);

// EXERCICIO 3
valor = 10
valor += 2;
console.log("EX3: Valor: " + valor);

// EXERCICIO 4
n1 = 20;
n2 = 5;
console.log("EX4: Divisão: " + (n1 / n2));

// EXERCICIO 5
n1 = 10;
n2 = 3;
console.log("EX5: Resto da Divisão: " + (n1 % n2));

// EXERCICIO 6
n1 = 2;
n2 = 3;
    if(n1 == n2){
        console.log("EX6: Números são iguais");
    }else{
        console.log("EX6: Números são diferentes");
    }

// EXERCICIO 7
n1 = 2;
n2 = 2;

    if(n1 === n2){
        console.log("EX7: Os valores sao estritamente iguais");
    }else{
        console.log("EX7: Os valores sao estritamente diferentes");
    }

// EXERCICIO 8
n1 = 10;
n2 = 5;
    
    if(n1 > n2){
        console.log("EX8: O primeiro valor e maior que o segundo");
    }else{
        console.log("EX8: O segundo valor e maior que o primeiro");
    }

// EXERCICIO 9
n1 = 20;
n2 = '20';

    if(n1 !== n2){
        console.log("EX9: O primeiro valor e diferente do segundo");
    }else{
        console.log("EX9: Os valores sao iguais");
    }

// EXERCICIO 10
n1 = 10;
n2 = 10;
valor = "10";

    if(valor == n1 && valor == n2){
        console.log("EX10: Verdadeiro");
    }else{
        console.log("EX10: Falso");
    }

// EXERCICIO 11
n1 = 30;
n2 = 20;
valor = "10";

    if(valor == n1 || valor == n2){
        console.log("EX11: Verdadeiro");
    }else{
        console.log("EX11: Falso");
    }

// EXERCICIO 12
n1 = 10;
n2 = 10;
valor = n1 == n2;

    if(!valor){
        console.log("EX12: Verdade");
    }else{
        console.log("EX12: Falso");
    }

// EXERCICIO 13
let array = ['Laranja', ' Maca', ' Banana', ' Uva'];
    console.log("EX13: " + array[0]);

// EXERCICIO 14
console.log("EX14: Tamanho antes: " + array.length);
array.push('Amora');
console.log("EX14: Tamanho depois: " + array.length);

// EXERCICIO 15
array.pop();
console.log("EX15: " + array);

// EXERCICIO 16
let nome = "Mateus";
let idade = 18;

    console.log(`EX16: Meu nome e ${nome} e tenho ${idade} anos`);

// EXERCICIO 17
let preco = 10;
let qtd = 50;
let total = preco * qtd;

    console.log(`EX17: O total e ${total}`);

// EXERCICIO 18
let nota1 = 6;
let nota2 = 8;
let nota3 = 3;
let media = (nota1 + nota2 + nota3)/3

    if(media >= 6){
        console.log("EX18: O aluno foi aprovado!");
    }else{
        console.log("EX18: O aluno foi reprovado!");
    }

// EXERCICIO 19
idade = 20;

    if(idade >= 18 && idade <= 60){
        console.log("EX19: Verdadeiro");
    }else{
        console.log("EX19: Falso");
    }

// EXERCICIO 20
n1 = 100

    if(n1 % 2 == 0){
        console.log("O numero e par");
    }else{
        console.log("O numero e impar");
    }