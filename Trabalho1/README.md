# Instruções sobre o Menu:

1. Mostra a media movel do Brasil
2. Mostra media movel dos estados
3. Mostra a estabilidade do Brasil
4. Mostra a estabilidade dos estados
5. Mostra estados com maior alta e maior baixa
6. Mostra o numero de obitos no Brasil
7. Mostra o numero de obitos em cada estado
8. Sair 

> Os itens 1, 2, 3, e 4 podem que o usuário digite também a quantidade dos 'n' dias considerados na média móvel e também digite o dia atual da média móvel. O usuário pode, por exemplo, digitar 3 e 10, ou seja: média móvel dos últimos 3 dias e considerando o dia atual como o dia 10.

## Compilação:

> Para compilar digite <i> make covid-update </i> ou <i> make all </i>. 

> Para executar digite <i> ./covid-update </i>

> Para remover os arquivos objetos e o executável digite <i> make clean </i>.

> O Compilador default é o g++. Caso queira utilizar o clang++ digite <i> make all compiler=CLANG </i>.

## Dados:

> O arquivo dados.csv contém os dados para compor a média histórica de cada estado.
> Este foi gerado de forma aleatória e não condiz com a a realidade.