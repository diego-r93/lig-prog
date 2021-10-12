# Instruções sobre o Menu:

> A opção deve ser passada por linha de comando.
> Exemplo: ./movie-manager 1
> Executa a opção 1 do menu.

## Opções do Menu:

1. Inserir filme no catálogo.
2. Remover filme do catálogo.
3. Buscar filme.
4. Editar filme.
5. Imprimir o catálogo de filmes.
6. Buscar filme mais bem avaliado.

## Compilação:

> Para compilar digite <i> make movie-manager </i> ou <i> make all </i>. 

> Para executar digite <i> ./movie-manager (OPTION) </i>

> Para remover os arquivos objetos e o executável digite <i> make clean </i>.

> O Compilador default é o g++. Caso queira utilizar o clang++ digite <i> make all compiler=CLANG </i>.

> O padrão default é o C++11. Caso queira utilizar outro digite <i> make all dialect=C++14 </i> ou <i> make all dialect=C++17 </i>.

## Dados:

> O arquivo data.txt contém a lista de filmes.