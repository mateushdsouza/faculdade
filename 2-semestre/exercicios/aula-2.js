function testeBloco(){
    console.log('antes >' , x);

    {
    var x = 'var dentro do bloco';
    let y = 'let dentro do bloco';
    console.log('dentro do bloco >', x, y);
    }

    console.log('Fora do bloco >' , x);
    console.log('Tipo de y fora >' , typeof y);
}

testeBloco();