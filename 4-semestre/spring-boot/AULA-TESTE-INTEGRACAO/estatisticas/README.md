# API de estatísticas — projeto para alunos

## Requisitos

- JDK **17**, com JAVA_HOME apontando para a pasta do JDK.
- Internet na primeira execução, para baixar Maven e dependências.
- Uma IDE Java é opcional.

O Maven Wrapper está incluído: **não precisa instalar Maven**. Nenhum banco externo ou Docker é necessário; o projeto usa H2 em memória.

Extraia o ZIP e abra um terminal dentro da pasta que contém `pom.xml`, `mvnw` e `mvnw.cmd`.

## Windows — PowerShell

Confira o Java e execute:

```powershell
java -version
.\mvnw.cmd -version
.\mvnw.cmd clean verify
.\mvnw.cmd spring-boot:run
```

## macOS e Linux

```sh
java -version
chmod +x mvnw
./mvnw -version
./mvnw clean verify
./mvnw spring-boot:run
```

O comando de versão do Wrapper também deve mostrar Java 17. Para encerrar a aplicação, pressione Ctrl+C.

Se aparecer JAVA_HOME incorreto, configure essa variável para o diretório do JDK 17 instalado no seu computador, e abra um novo terminal. Não aponte para a subpasta bin.

## Abrir no IntelliJ

1. Abra a pasta do projeto ou seu `pom.xml` como projeto Maven.
2. Em Project Structure, selecione JDK 17 no Project SDK.
3. Em Modules → Dependencies, selecione Project SDK no Module SDK.
4. Recarregue o projeto no painel Maven. Selecione Java 17 também no Maven Runner, se necessário.

No VS Code ou Eclipse, importe o projeto Maven e configure JDK 17.

## Testar a API

A aplicação inicia em `http://localhost:8080`. O corpo dos POSTs é um array JSON direto.

| Método e caminho | Comportamento |
|---|---|
| POST /estatisticas/calcular | Calcula usando apenas service, sem repository |
| POST /estatisticas | Calcula e salva no repository |
| GET /estatisticas | Consulta histórico |

macOS/Linux:

```sh
curl -X POST http://localhost:8080/estatisticas/calcular \
  -H 'Content-Type: application/json' -d '[1,2,3]'
```

PowerShell:

```powershell
Invoke-RestMethod -Method Post -Uri 'http://localhost:8080/estatisticas/calcular' -ContentType 'application/json' -Body '[1,2,3]'
```

Para essa entrada, média e mediana são 2. A resposta inclui maior, menor, total, moda, soma e desvio padrão populacional. O cálculo sem persistência retorna ID nulo; o cálculo salvo retorna ID gerado. Lista inválida retorna 400 sem corpo. JSON ilegível retorna 400 com campo erro. O histórico desaparece ao encerrar a aplicação.

Se a porta 8080 estiver ocupada, encerre outra instância ou execute com `-Dspring-boot.run.arguments=--server.port=8081` após `spring-boot:run`.

## Atividade de testes

Abra `src/test/java/com/example/demo/controller/EstatisticaControllerTest.java`. Há um teste inicial com `@BeforeEach`, `setup()` e exercícios nos comentários. Complete os cenários na mesma classe, usando nomes como `cenario_02_calcular_mediana`. Nesta etapa não use Mockito: chame `calcularSemSalvar`, com controller e service reais.

Execute somente essa classe:

```sh
./mvnw -Dtest=EstatisticaControllerTest test
```

No Windows, troque `./mvnw` por `.\mvnw.cmd`.

`clean verify` executa testes e gera cobertura em `target/site/jacoco/index.html`. Como esta é uma atividade a completar, o exemplo inicial não cobre todos os comportamentos. Os testes chamam o controller diretamente e não exercitam rotas HTTP ou conversão de JSON.
