# O Labirinto Recorrente
Trabalho pela disciplina de Algoritmos e Estrutura de Dados I. 

# O problema 
- Um garoto se encontra perdido em um labirinto, o qual é compreendido por nós como sendo uma matriz cujas posição de sua localização é dada por um valor x,y dessa estrutura. Nesse labirinto há paredes que bloqueiam certos passos (#), perigos que consomem parte de sua vida (*) e trajetórias (valores positivos que devem ser subtraídos em 1 a cada passagem).

- Quanto as paredes #, não há muito o que fazer a não ser desviar e continuar a rota. Já os perigos, a cada passada, tende a subtrair 1 de vida de um total de 10. Assim, ao ficar sem pontos de vida o algoritmo deve parar e indicar fim de jogo.

- Ao decorrer do jogo, a cada passo correto sob uma estrada, o garoto consome um item, subtraindo esse do valor que compõe a posição x,y. Gravando nessa o valor resultante. A cada subtração bem sucedida é preciso, essa vai para um banco de vida que cheio (a cada 4 ações bem sucedidas) lhe retorna 1 de vida em seu contador. Contudo, pode haver partes do caminho com zero itens, esses devem continuar sendo utilizados, porém, sem computar pontuação.

- O labirinto deve ser lido do arquivo input.data, o qual apresentará várias matrizes, todas quadráticas conforme exercício anterior. Sua missão é percorrer as matrizes até que todo o caminho percorrido pelo garoto se torne zero ou que ele venha a morrer devido aos perigos enfrentados. No final é preciso apresentar como resultado: (a) quantas casas foram percorridas ao todo; (b) qual a soma de itens consumidos pelo caminho; (c) quantas casas da matriz ficaram sem serem exploradas; (d) quantos perigos foram enfrentados ao decorrer do percurso.

- Para essa atividade, considere selecionar um passo de cada vez de forma aleatória, ou seja, escolha um valor x,y aleatoriamente e vá para ele se possível ou descarte caso seja uma parede. Perigos não são evitados, então, se a posição escolhida for um, enfrente-o. Por fim, a intenção global do problema não é encontrar uma saída, mas sim, tentar consumir o máximo possível de itens até chegar a zerar as possibilidades desse tipo ou morrer tentando.

Qual o custo computacional da sua estratégia randômica? Se mostrou uma boa alternativa de execução?


# Visão Geral
A proposta consiste na utilização de uma estratégia de caminhamento randômica em uma espécie de jogo, de forma que as decisões de movimentação são geradas de forma aleatória e a execução do algoritmo persiste até encontrar algum dos critérios de parada. 
As decisões de caminhamento são tomadas de acordo com a posição que o personagem se encontra dentro do labirinto. 
O personagem sempre inicia na posição (0,0) da primeira matriz (0).
As regras de execução adotadas são as seguintes:

## Caminhamento dentro de cada matriz (labirinto):
As decisões de movimentação são baseadas na posição que o personagem se encontra na matriz, pois as possibilidades de movimento vão depender se ele se encontra em algum vértice, nas laterais(primeiras e ultimas linhas e colunas) ou no centro do labirinto.
Essa posição relativa foi subdividida em 9 casos. São eles:

1. Vertice superior esquerdo: movimenta para a direita, para diagonal inferior direita ou para baixo.

2. Vertice superior direito: Movimenta para esquerda, para diagonal inferior esquerda e para baixo

3. Vertice inferior esquerdo: Movimenta para direita, para diagonal superior direita e para cima.

4. Vertice inferior direito: Movimenta para esquerda, para diagonal superior esquerda e para cima.

5. Primeira Linha: Movimenta para esquerda, para direita, para baixo e para as diagonais inferiores.

6. Primeira Coluna: Movimenta para cima, para baixo, bara direita, para diagonal inferior direita e para diagonal superior direita.

7. Ultima linha: Movimenta para direita, para a esquerda, para cima e para as diagonais superiores.

8. Ultima coluna: Movimenta para cima, para baixo, para a esquerda, para diagonal inferior esquerda e para a diagonal superior esquerda.

9. Meio da matriz: Movimenta em todas as direções

    
  Os casos estão representados a seguir:
  
  ![caso1](https://user-images.githubusercontent.com/64996505/233795540-9f95c754-6296-42fd-aa98-9d6187f15405.jpg)
  ![caso2](https://user-images.githubusercontent.com/64996505/233795552-4b3398ae-1ce5-4c2e-852d-772b59cbd647.jpg)
  ![caso3](https://user-images.githubusercontent.com/64996505/233795554-f1e68fa9-7fbf-4019-9077-73f1b69fce52.jpg)

  ![caso4](https://user-images.githubusercontent.com/64996505/233795563-442eef40-bda3-4dba-9ae7-7127b17fcd92.jpg)
  ![caso 5](https://user-images.githubusercontent.com/64996505/233795566-53501e2b-cc11-4e5a-9e78-861e18f05a50.jpg)
  ![caso 6](https://user-images.githubusercontent.com/64996505/233795570-fc452b8f-ea42-4ab4-b8bf-d723f28f4aae.jpg)

  ![caso 7](https://user-images.githubusercontent.com/64996505/233795578-810fe610-b5be-49d7-9ac1-e6fcb10ab2d2.jpg)
  ![caso 8](https://user-images.githubusercontent.com/64996505/233795580-a68dcc69-cf39-41c1-9a3e-c216d2e8a213.jpg)
  ![caso 9](https://user-images.githubusercontent.com/64996505/233795585-31de85e5-8989-492e-a0e9-635a7be6fe80.jpg)

## Regra de teletransporte:
O personagem teletransporta para outra matriz sempre que estiver nas laterais do labirinto, isto é, primeira linha, primeira coluna, ultima linha ou ultima coluna.
Porém, o portal para teletransporte só é liberado se o personagem tiver realizado pelo menos 10 movimentos. Essa decisão foi tomada para garantir que o personagem movimente-se algumas vezes no mesmo labirinto antes de partir para outro.
    
 ![image](https://user-images.githubusercontent.com/64996505/233798583-2048be29-d81b-4b79-9668-cb57dbf3d94a.png)

A passagem de um labirinto para outro consiste em um ciclo horário. Ou seja, da primeira para segunda matriz, da segunda para terceira, ... , da ultima retorna para a primeira. Sempre nessa ordem, como mostra a imagem:

 ![ciclo de teletransporte](https://user-images.githubusercontent.com/64996505/233798511-51586485-2d1b-4885-beee-fc3762179016.png)
 
 ## Critérios de parada de execução:
 1. Vitória: para vencer o personagem precisa passar por todas as matrizes e retornar para a posição inicial sem ter pegado itens, ou seja, passando por caminhos dos quais ele ja percorreu.
 2. Derrota: independetemente do quando o personagem percorreu ou quais matrizes percorreu, se tiver zerado sua vida, o personagem "morre" e a execução chega ao fim, o que implica na derrota.
 
 ## Vida e Itens:
 O personagem inicia o jogo com 8 pontos de saúde (HP) e com sua mochila zerada.
 
# Entrada
A entrada consiste de um arquivo "input.data" que se encontra no diretório "dataset" do projeto. O arquivo foi gerado a partir de um apicativo gerador disponibilizado pelo professor.
O arquivo apresenta em sua primeira linha as informações da dimensão do mapa: número de linhas de cada matriz, número de colunas de cada matriz e quantidade de matrizes. Em seguida apresenta as matrizes separadas por espaços. 
Exemplo de entrada: 

3 matrizes de dimensão 3x3:

![image](https://user-images.githubusercontent.com/64996505/233800002-2e9bc4fc-bd46-4291-9413-95751656d266.png)

# Implementação
A implentação da soluão foi feita em c++ para a utilização da biblioteca fstream para leitura de arquivos. O algoritmo apresenta várias funções auxiliares de execução, mas o "cérebro" do algoritmo se encontra na função "start" que lida com toda a execução.
Ao fim do algoritmo, será necessário informar quantas casas não foram visitadas pelo personagens. Para isso foi utilizada uma matriz que marca as posições que ja foram percorridas. Cada vez que se muda de labirinto, a matriz de caminho é salva em arquivo. Dessa forma, ao fim do algoritmo conta se a quantidade de posições não foram acessadas.

## Leitura do arquivo
Para fins de organização do código, no início da execução, o arquivo "input.data" é lido com a função "generateIndividualMazeFiles" e novos arquivos individuais são gerados para cada matriz. Dessa forma, arquivos com nome "Save.dat" são adicionados ao diretório outputFiles presente no projeto. Dessa forma, é possível ler os dados individuais e quando for "teletransportar" entre as matrizes, salvar as modificações sobrescrevendo o arquivo individal referente a matriz corrente.

![image](https://user-images.githubusercontent.com/64996505/233801163-26c79a32-e13b-45c4-98e9-89e4bf978a8f.png)

## O ciclo de execução. 
Como o problema é recorrente, sua execução e critérios de parada são definidos numa função chamada "start". Essa função define os contadores e as variáveis referente ao personagem e apresenta um loop while que continua executando até que o personagem acabe ficando sem vidas ou que atenda aos critérios de vitória.
O de execução do algoritmo dentro do while se orienta pelos seguintes passos a cada iteração:

* Verifica se atende ao critério de vitória;
  * Caso atenda, sai do loop.
* Imprime o labirinto, informações sobre a matriz, informações sobre o personagem e as informações de execução;
* Verifica a posição atual da matriz para executar alguma ação: 
  * Capturar item para adicionar a sacola;
  * Tomar dano em caso de perigo;
    * Se zerar a vida, sai do loop.
  * Aumentar vida caso personagem atinja 4 items na mochila;
  * Zerar mochila;
  * Adminstração de contadores;
* Verifica a condição de teletransporte. Caso possa teletraportar os seguintes passos são atendidos:
  * Reescreve o arquivo da matriz n que está sendo trabalhada;
  * Define para qual labirinto o personagem será teletranportado;
  * Atualiza o contador de matriz corrente (atual)
  * Leitura da nova matriz;
* Gera um novo movimento aletoriamente com uma função;
      * Verificar se é parede, caso seja, entra em um ciclo até gerar um caminho do qual o personagem pode seguir;
      
# Saída
A cada iteração do ciclo de execução do algoritmo, é impresso as informações referentes à matriz, ao personagem e também o que deve acontecer na próxima iteração.
Obs.: são impressas duas matrizes: uma que representa o labirinto e outra que representa o caminho que o personagem ja percorreu.

![image](https://user-images.githubusercontent.com/64996505/233803128-badbeeab-5981-4b71-ae80-32afd4e2685f.png)
![image](https://user-images.githubusercontent.com/64996505/233803141-9d895d35-f2d2-4f11-9b17-e7afdadfcd9c.png)
![image](https://user-images.githubusercontent.com/64996505/233803166-b75a91b1-cb94-4bb0-9770-e23d96b594cf.png)

      
## Impressão das estatísticas de execução;
Ao fim do loop, as seguintes informações são impressas:
* Número de posições que não foram visitadas;
* Total de itens capturados;
* Total de perigos enfrentados;
* Total de casas visitadas (obs.: as paredes estão inclusas na contagem);

![image](https://user-images.githubusercontent.com/64996505/233803284-16cbbc24-00a3-4e8e-ab40-ab39fe808415.png)


# Testes
Durante a execução de testes foi possivel constatar que o algortimo tende a perder na maioria dos casos. Para tamanhos superiores de matriz, a chance derrota aumenta significativamente. 
Para testar critérios de vitória em matrizes de ordem superior, foi utilizado 3 matrizes de ordem 10 no arquivo "input.data" com todas as posiçẽs sendo '0' e o seguinte resultado foi obtido para uma das execuções:

![image](https://user-images.githubusercontent.com/64996505/233803673-1e52dc6f-8d74-4d00-a7b7-66e20059093c.png)

Em ordem inferior, ordem 3, por exemplo, casos de vitória são mais comuns. 
Teste com 3 matrizes de ordem 3:

![image](https://user-images.githubusercontent.com/64996505/233803783-a26c5651-9c6c-4bd8-a7c0-c906633ab8dd.png)

Entretanto, de qualquer forma, vitória e derrota dependem não somente do tamanho da matriz, mas da configuração dela, ou seja, das paredes e perigos e também da distribuição de itens.

## Casos que não foram considerados:
Há casos que não foram tratados separadamente nesse algoritmo, a exemplo de quando o personagem cair direto em um mapa cercado por paredes. Nessa situação o algoritmo pode vir a ser executado infinitamente sem nenhuma saída de execução. Como se trata de um caso muito específico, não tem prejuízo para a grande maioria dos arquivos de labirinto que forem testados nesse algoritmo.

# Conclusão
Portanto, considerando as regras de implementação e execução apresentadas, é possível observar que o resultado da execução do algoritmo pode variar bastate. Nesse caso, não somente as direções de movimentação são aleatórias, mas também o número de matrizes, dimensão delas, assim como a disposição do labirinto em cada matriz, que influenciam no tempo de execução. Para os vários testes executados, o comportamento do algoritmo variou, mas alcançou o critério de parada em menos de 1000 iterações no loop principal para matrizes de ordem inferiores a 10;
Dessa forma, torna-se difícil estimar o custo computacional exato desse algoritmo, exatamente por esse comportamento aleatório, principalmente nas decisões de movimentação. 


# Compilação e Execução

O projeto possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

Os testes de execução foram gerados aleatoriamente, partindo do código que gerou o arquivo "input.data" presente no repositório do projeto.






