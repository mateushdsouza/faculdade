// EX1: Criando a primeira funcao!

function calcularDobro(numero){
    return numero * 2;
}

let resultado = calcularDobro(2);
console.log(`EX1: O dobro de 2 e: ${resultado}`);
console.log(`EX1: O dobro de 20 e: ${calcularDobro(20)}`);

// EX2: Crie uma função chamada calcularArea que receba largura e altura como parâmetros e retorne a área do retângulo.

function calcularArea(largura, altura){
    return largura * altura;
}

console.log(`EX2: A area do retangulo e: ${calcularArea(3, 5)}`);

// EX3: Crie uma função chamada ehPar que receba um número como parâmetro e retorne true se for par ou false se for ímpar.

function ehPar(numero){
    if(numero % 2 === 0){
        return true;
    }else{
        return false;
    }
}

console.log(`EX3: O valor do numero e: ${ehPar(3)}`);

// EX4: Crie uma função converterCelsiusParaFahrenheit que receba uma temperatura em Celsius e retorne o valor convertido para Fahrenheit.

function converterCelsiusParaFahrenheit(temperatura){
    return temperatura * 1.8 + 32;
}

console.log(`EX4: 10 Celsius e: ${converterCelsiusParaFahrenheit(10)} Fahrenheit`);

// EX5: Crie uma função primeiraLetra que receba uma string (nome) como parâmetro e retorne apenas a primeira letra.

function primeiraLetra(nome){
    return nome[0];
}

console.log(`EX5: A primeira letra de Mateus e: ${primeiraLetra("Mateus")}`);

// EX6: Crie uma função aoQuadrado que receba um número como parâmetro e retorne o quadrado dele.

function aoQuadrado(numero){
    return numero * numero;
}

console.log(`EX6: O quadrado de 3 e: ${aoQuadrado(3)}`);