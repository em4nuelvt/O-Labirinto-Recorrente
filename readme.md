# O Labirinto Recorrente
Após um aquecimento com um trabalho sobre caminhmaneto em matrizes, parte-se para uma nova proposta de  trabalho pela disciplina de Algoritmos e Estrutura de Dados I. Considere o seguinte problema:

- Um garoto se encontra perdido em um labirinto, o qual é compreendido por nós como sendo uma matriz cujas posição de sua localização é dada por um valor x,y dessa estrutura. Nesse labirinto há paredes que bloqueiam certos passos (#), perigos que consomem parte de sua vida (*) e trajetórias (valores positivos que devem ser subtraídos em 1 a cada passagem).

- Quanto as paredes #, não há muito o que fazer a não ser desviar e continuar a rota. Já os perigos, a cada passada, tende a subtrair 1 de vida de um total de 10. Assim, ao ficar sem pontos de vida o algoritmo deve parar e indicar fim de jogo.

- Ao decorrer do jogo, a cada passo correto sob uma estrada, o garoto consome um item, subtraindo esse do valor que compõe a posição x,y. Gravando nessa o valor resultante. A cada subtração bem sucedida é preciso, essa vai para um banco de vida que cheio (a cada 4 ações bem sucedidas) lhe retorna 1 de vida em seu contador. Contudo, pode haver partes do caminho com zero itens, esses devem continuar sendo utilizados, porém, sem computar pontuação.

- O labirinto deve ser lido do arquivo input.data, o qual apresentará várias matrizes, todas quadráticas conforme exercício anterior. Sua missão é percorrer as matrizes até que todo o caminho percorrido pelo garoto se torne zero ou que ele venha a morrer devido aos perigos enfrentados. No final é preciso apresentar como resultado: (a) quantas casas foram percorridas ao todo; (b) qual a soma de itens consumidos pelo caminho; (c) quantas casas da matriz ficaram sem serem exploradas; (d) quantos perigos foram enfrentados ao decorrer do percurso.

- Para essa atividade, considere selecionar um passo de cada vez de forma aleatória, ou seja, escolha um valor x,y aleatoriamente e vá para ele se possível ou descarte caso seja uma parede. Perigos não são evitados, então, se a posição escolhida for um, enfrente-o. Por fim, a intenção global do problema não é encontrar uma saída, mas sim, tentar consumir o máximo possível de itens até chegar a zerar as possibilidades desse tipo ou morrer tentando.

Qual o custo computacional da sua estratégia randômica? Se mostrou uma boa alternativa de execução?


# Visão Geral
A proposta consiste na utilização de uma estratégia de caminhamento randômica, de forma que as decisões de movimentação são geradas de forma aleatória e a execução do algoritmo persiste até encontrar algum dos critérios de parada. 
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

# Regra de teletransporte:
O personagem teletransporta para outra matriz sempre que estiver nas laterais do labirinto, isto é, primeira linha, primeira coluna, ultima linha ou ultima coluna.
Porém, o portal para teletransporte só é liberado se o personagem tiver realizado pelo menos 10 movimentos.
    
 ![image](https://user-images.githubusercontent.com/64996505/233798583-2048be29-d81b-4b79-9668-cb57dbf3d94a.png)

A passagem de um labirinto para outro consiste em um ciclo horário. Ou seja, da primeira para segunda matriz, da segunda para terceira, ... , da ultima retorna para a primeira. 

 ![ciclo de teletransporte](https://user-images.githubusercontent.com/64996505/233798511-51586485-2d1b-4885-beee-fc3762179016.png)






