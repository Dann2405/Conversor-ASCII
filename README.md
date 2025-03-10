# Conversor Binario para ASCII

Projeto desenvolvido como trabalho para a disciplina de Estrutura de Dados, utilizando C++. O objetivo deste programa é converter um arquivo contendo apenas 0's e 1's em texto legível. Para isso, o código realiza a leitura do arquivo, divide a sequência de bits em grupos de 8, converte cada grupo para o valor decimal correspondente e, posteriormente, para o caractere ASCII associado. O uso de pilhas foi implementado para inverter a ordem dos caracteres, atendendo aos requisitos propostos.

## Funcionalidades

- **Leitura de Arquivo:** Lê um arquivo de texto (`input.txt`) contendo somente 0's e 1's.
- **Processamento de Bits:** Divide a sequência em grupos de 8 bits para conversão.
- **Conversão Binário → Decimal → ASCII:** Converte cada grupo de bits para seu valor decimal e, em seguida, para o caractere ASCII correspondente.
- **Utilização de Pilhas:** Utiliza pilhas para empilhar e desempilhar os caracteres, garantindo a ordem correta do texto final.

## Requisitos

- Compilador C++ (por exemplo, g++)

## Compilação

Para compilar o projeto, abra o terminal no diretório onde se encontra o arquivo fonte (`main.cpp`) e execute o comando:

```bash
g++ -o conversao main.cpp
```

## Execução

Após a compilação, execute o programa com o comando:

```bash
./conversao
```

## Exemplo de Uso

Se o arquivo `input.txt` contiver a seguinte sequência:

```
010000010110110001101111
```

A saída do programa será:

```
Texto convertido: Alo
```

## Desenvolvedores

- Camila Ramos Gomes
- Daniel Soares Oliveira Santos
- Rauan Brandão Batista
