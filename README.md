**Problemas NP-Difíceis e NP-Completos**
=

Trabalho elaborado no Centro Federal de Educação Tecnológica de Minas Gerais, com intuito de discutir sobre os algorítmos da computação que, ainda não se sabe ao certo se são capazes de atuar em um tempo polinomial.

<h3>Integrantes:</h3>

<li>Daniel Alves Sanches</li>
<li>Jorge Vitor Gonçalves de souza</li>
<li>Julia Mello Lopes</li>
<li>Leonardo de Oliveira Campos</li>
<li>Lucas de Souza Gontijo</li>
<li>Lucas Ribeiro Silva</li>

## **PROBLEMA**
- O problema escolhido por nosso grupo para demonstrar a capacidade de se resolver algo sem uma solução fixa, ou seja, um problema não polinomial, foi o "problema do caixeiro viajante" (traveling salesman problem - TSP). De acordo com o site Wikipedia, nele tentamos "determinar a menor rota para percorrer uma série de cidades (visitando uma única vez cada uma delas), retornando à cidade de origem. Ele é um problema de otimização NP-difícil inspirado na necessidade dos vendedores em realizar entregas em diversos locais (as cidades) percorrendo o menor caminho possível, reduzindo o tempo necessário para a viagem e os possíveis custos com transporte e combustível".

Para ilustrar o problema, observe a imagem:
<p align = "center">
    <img src="./img/caixeiro_viajante.jpeg" alt="caixeiro viajante" width="450"></img>
</p>
*Tradução: "Eu quero visitar cada cidade uma única vez terminando no mesmo local em que comecei, pegando o menor caminho."

## **COMPILAÇÃO**
- Construído utilizando a linguagem C através do sistema operacional Windows 11 operando em ambiente Linux (WSL2 - Ubuntu-20.04). Para execução do programa siga os comandos abaixo:

> make clean

> make

> make run

## **EXECUÇÃO**
- Ao iniciar o programa serão exibidas três opções
    - 1 - Redireciona para o menu de grafos da opção Brute Force
    - 2 - Redireciona para o menu de grafos da opção Busca rápida
    - 0 - Finaliza o programa

![menu1](./img/primeiro_menu.png)<br>

- Menu de opções de entrada para utilizar o Brute Force

![menu2.1](./img/menu_brute_force.png)<br>

- Menu de opções de entrada para utilizar o Busca Rápida

![menu2.2](./img/menu_busca_simples.png)<br>

- Exemplo utilizando o método Brute Force (10 vértices)

![ex1](./img/ex_brute_force_10.png)<br>

- Exemplo utilizando o método Busca Rápida (10 vértices)

![ex2](./img/ex_busca_simples_10.png)<br>

## **FUNCIONAMENTO**

- O método de Busca Rápida para resolver o problema utiliza o sistema de backtracking, que auxilia ao percorrer o grafo fazendo isso uma única vez e em um único caminho, que já indica o menor caminho possível. Porém, fazendo isso ele descarta outras possibilidades por elas serem "redundantes" já que mudam a rota mas não o tamanho. Desse modo, essa é a explicação resumida do motivo de sua execução levar um tempo inferior, principalmente considerando os grafos com maiores quantidades de vértices. Já o método Brute Force testa todas as possibilidades da menor rota entre os vértices e por isso leva um tempo superior de execução.

## **REFERÊNCIAS**

- https://pt.wikipedia.org/wiki/Problema_do_caixeiro-viajante

- https://github.com/kelvins/Algoritmos-e-Estruturas-de-Dados/blob/main/src/c/CaixeiroViajante.c

- https://pt.stackoverflow.com/questions/103184/o-que-%C3%A9-um-algoritmo-backtracking