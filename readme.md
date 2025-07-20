# Trabalho de Estrutura de Dados - ÁRVORE BINÁRIA DE PESQUISA

**Aluna:** Brendda Thamyres Mendes Rodrigues  
**Professor:** Anselmo Cardoso de Paiva (ACP)  
**Data:** Julho de 2025

**Universidade Federal do Maranhão**  
**Curso de Ciência da Computação**

---

### Sobre o projeto

Esse trabalho implementa um Tipo Abstrato de Dados (TAD) para uma Árvore Binária de Pesquisa modular, o que permite flexibilidade de armazenamento de dados e reciclagem de código.

Este projeto é uma simulação de registro de animais, onde o tipo específico de dado faz parte da estrutura `Aniamal`, que contém:

- Nome: `char nome[30]`
- Idade: `int idade`
- Peso: `float renda_mensal`

Para maior facilidade ao utilizar o TAD, o programa oferece um menu interativo, permitindo que o usuário escolha qual operação realizar:
    - 1: Criar arvore de registro
    - 2: Cadastrar animal
    - 3: Listar animais registrados
    - 4: Consultar animal
    - 5: Remover animal
    - 6: Esvaziar registro
    - 7: Destruir arvore de registros
    - 0: Sair do programa

---

**Sistema:** Windows 10  
**Terminal:** MYSYS2  
**Ambiente:** UCRT64  
**Compilador:** GCC  
**Método de compilação:** via Makefile  

---

### Como rodar o projeto

#### Pré-requisitos

- Ter o MYSYS2 UCRT64 instalado (também é possível utilizar via prompt de comando)
- Ter o GCC instalado
- Ter o Make instalado

---

#### Clone o repositório no terminal (powershell ou prompt de comando)

```bash
git clone https://github.com/brendda-thamyres/Arvore_Binaria_Pesquisa.git
````

### Via MYSYS2

#### Vá até a pasta do projeto

```bash
cd Arvore_Binaria_Pesquisa
```

#### Compile no terminal

```bash
make
```

#### Execute:

```bash
./main.exe
```

---

### Via Prompt de Comando

#### Vá até a pasta do projeto

```bash
cd Arvore_Binaria_Pesquisa
```

#### Compile:

```bash
gcc -Wall -Wextra -g3 abp.c main.c -o main.exe
```

#### Execute:

```bash
./main.exe
```

--- 
Este trabalho foi feito somente para fins acadêmicos.
