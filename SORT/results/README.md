## Introdução
Nesta pasta ficarão os resultados do trabalho, sendo que este é coletar as informações sobre os métodos de ordenação, tais como complexidade dos mesmos.
Para tal, foi considerado o número de iterações realizadas no conjunto de dados para cada um dos métodos deles, sendo considerados 3 *tipos* de conjuntos, sendo:
- O primeiro, o melhor caso, caso esse em que o conjunto já está ordenado;
- O segundo, o caso médio, sendo este o conjunto arranjado de forma aleatória. Devida a natureza aleatória dos números gerados, para o número de iterações deste caso foi tirado uma média aritmética de 10 conjuntos de dados aleatórios diferentes;
- O último, o pior caso, em que o conjunto de dados está ordenado de maneira inversa. Como neste experimento estamos ordenando de forma crescente (não deveria haver diferença se fosse feito o contrário), neste caso se trata de um conjunto de dados ordenado de forma decrescente.
## Arquivos
Temos 6 arquivos, sendo cada um deles dedicados para um método de ordenação.
Cada um deles terá 3 linhas com cada um dos casos, sendo a primera o melhor caso, a segunda o caso médio e a terceira, o pior caso.
Cada linha, salvo a primeira, será da forma `num1\tnum2\tnum3\tnum4\tnum5\tnum6`, forma esta que o software utilizado para gerar os gráficos lê o conjunto de dados.
A primeira linha será composta da etiqueta (label) de cada curva do gráfico, também separadas por `\t`, sendo `nome1\tnome2\tnome3\tnome4\tnome5\tnome6`
## Gráficos
Ao final, serão gerados 3 gráficos diferentes, um para cada caso de ordenação, e cada um destes gráficos terá 6 curvas, sendo uma para cada método.
O eixo das abcsissas do gráfico representa o tamanho do conjunto, e o eixo das ordenadas o número de iterações necessárias para ordendar o conjunto, sendo assim, o par `(x, y)` indica o número de iterações realizadas `y` para determinado tamanho de vetor `x`.