# Atividade: associar categorias e carros

## Objetivo

Completar a API para cadastrar categorias e associar uma categoria a um carro usando o relacionamento `ManyToMany` que ja existe entre `CarrosEntity` e `CategoriaEntity`.

Ao final, o endpoint `GET /carros` deve mostrar as categorias associadas a cada carro.

## Antes de iniciar

Configure a conexao com seu PostgreSQL no arquivo:

```text
src/main/resources/application.properties
```

Propriedades que podem ser alteradas:

```properties
spring.datasource.url=jdbc:postgresql://localhost:5432/uniamerica
spring.datasource.username=postgres
spring.datasource.password=postgres
```

O Hibernate criara e atualizara as tabelas automaticamente.

## Parte 1: criar o repository de categorias

Crie a interface `CategoriaRepository` dentro do pacote:

```text
com.example.demo.repository
```

Ela deve estender `JpaRepository<CategoriaEntity, Long>`.

## Parte 2: cadastrar uma categoria

Na classe `CarrosService`:

1. injete o `CategoriaRepository` pelo construtor;
2. crie um metodo que receba uma `CategoriaEntity`;
3. salve a categoria usando o repository;
4. devolva a categoria salva.

Na classe `CarrosController`, crie:

```http
POST /carros/categorias
```

Exemplo de JSON:

```json
{
  "nome": "SUV"
}
```

Resultado esperado: a categoria deve ser criada na tabela `categorias`.

## Parte 3: associar categoria e carro

Na classe `CarrosService`, crie um metodo transacional que:

1. receba `carroId` e `categoriaId`;
2. busque o carro com `carroRepository.findById()`;
3. busque a categoria com `categoriaRepository.findById()`;
4. adicione a categoria na colecao retornada por `carro.getCategorias()`.

Lembrete: `CarrosEntity` e o lado dono do relacionamento porque possui o `@JoinTable`.

Na classe `CarrosController`, crie:

```http
PATCH /carros/{carroId}/categorias/{categoriaId}
```

Exemplo:

```http
PATCH /carros/1/categorias/1
```

Resultado esperado: uma linha deve ser criada na tabela intermediaria `carro_categoria`.

## Parte 4: verificar no GET de carros

Execute:

```http
GET /carros
```

O carro associado deve apresentar a categoria dentro de `categorias`:

```json
{
  "idCarro": 1,
  "modelo": "Corolla",
  "endereco": null,
  "fabricante": {
    "id": 1,
    "nome": "Toyota"
  },
  "categorias": [
    {
      "id": 1,
      "nome": "SUV"
    }
  ]
}
```

## Ordem para testar

1. Inicie o PostgreSQL.
2. Execute `DemoApplication`.
3. Faça `POST /carros/categorias` para criar a categoria.
4. Anote o ID da categoria criada.
5. Faça `PATCH /carros/{carroId}/categorias/{categoriaId}`.
6. Faça `GET /carros`.
7. Confirme se a categoria aparece no carro correto.

## Critérios de conclusão

- A categoria e salva no PostgreSQL.
- O carro e a categoria sao encontrados pelos IDs.
- A tabela `carro_categoria` recebe a associacao.
- O `GET /carros` retorna a categoria associada.
- Uma categoria pode ser associada a varios carros.
- Um carro pode possuir varias categorias.
