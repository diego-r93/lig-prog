# Instruções sobre o Menu:

> A opção deve ser passada por linha de comando.
> Exemplo: ```./symmetric-graph 1```
> Executa a opção 1 do menu.

## Opções do Menu:

1. Imprime o número de vértices e de enlaces do grafo.
2. Imprime todos os vértices existentes no grafo.
3. Imprime o caminho e custo total do caminho com o menor custo.
4. Imprime o diâmetro do grafo.
5. Imprime o vértice com a maior centralidade de grau.
6. Imprime o vértice com a maior centralidade de intermediação.

## Compilação:

> Para compilar digite ```make symmetric-graph``` ou ```make all```. 

> Para executar digite ```./symmetric-graph (OPTION)```

> Para remover os arquivos objetos e o executável digite ```make clean```.

> O Compilador default é o g++. Caso queira utilizar o clang++ digite ```make all compiler=CLANG```.

## Dados:

> O arquivo dados.txt contém os dados para compor o grafo.