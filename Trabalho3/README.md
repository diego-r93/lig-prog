# Instruções sobre o Menu:

> A opção deve ser passada por linha de comando.
> Exemplo: ```./movie-manager 1```
> Executa a opção 1 do menu.

## Opções do Menu:

1. Inserir filme no catálogo.
2. Remover filme do catálogo.
3. Buscar filme.
4. Editar filme.
5. Imprimir o catálogo de filmes.
6. Buscar filme mais bem avaliado.

## Compilação:

> Para compilar digite ```make movie-manager``` ou ```make all```. 

> Para executar digite ```./movie-manager (OPTION)```

> Para remover os arquivos objetos e o executável digite ```make clean```.

> O Compilador default é o g++. Caso queira utilizar o clang++ digite ```make all compiler=CLANG```.

> O padrão default é o C++11. Caso queira utilizar outro digite ```make all dialect=C++14``` ou ```make all dialect=C++17```.

## Dados:

> O arquivo data.txt contém a lista de filmes.