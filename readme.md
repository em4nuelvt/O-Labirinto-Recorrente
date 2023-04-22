# O Labirinto Recorrente
Após um aquecimento com um trabalho sobre caminhmaneto em matrizes, parte-se para uma nova proposta de  trabalho pela disciplina de Algoritmos e Estrutura de Dados I. Considere o seguinte problema:

- Um garoto se encontra perdido em um labirinto, o qual é compreendido por nós como sendo uma matriz cujas posição de sua localização é dada por um valor x,y dessa estrutura. Nesse labirinto há paredes que bloqueiam certos passos (#), perigos que consomem parte de sua vida (*) e trajetórias (valores positivos que devem ser subtraídos em 1 a cada passagem).

- Quanto as paredes #, não há muito o que fazer a não ser desviar e continuar a rota. Já os perigos, a cada passada, tende a subtrair 1 de vida de um total de 10. Assim, ao ficar sem pontos de vida o algoritmo deve parar e indicar fim de jogo.

- Ao decorrer do jogo, a cada passo correto sob uma estrada, o garoto consome um item, subtraindo esse do valor que compõe a posição x,y. Gravando nessa o valor resultante. A cada subtração bem sucedida é preciso, essa vai para um banco de vida que cheio (a cada 4 ações bem sucedidas) lhe retorna 1 de vida em seu contador. Contudo, pode haver partes do caminho com zero itens, esses devem continuar sendo utilizados, porém, sem computar pontuação.

- O labirinto deve ser lido do arquivo input.data, o qual apresentará várias matrizes, todas quadráticas conforme exercício anterior. Sua missão é percorrer as matrizes até que todo o caminho percorrido pelo garoto se torne zero ou que ele venha a morrer devido aos perigos enfrentados. No final é preciso apresentar como resultado: (a) quantas casas foram percorridas ao todo; (b) qual a soma de itens consumidos pelo caminho; (c) quantas casas da matriz ficaram sem serem exploradas; (d) quantos perigos foram enfrentados ao decorrer do percurso.

- Para essa atividade, considere selecionar um passo de cada vez de forma aleatória, ou seja, escolha um valor x,y aleatoriamente e vá para ele se possível ou descarte caso seja uma parede. Perigos não são evitados, então, se a posição escolhida for um, enfrente-o. Por fim, a intenção global do problema não é encontrar uma saída, mas sim, tentar consumir o máximo possível de itens até chegar a zerar as possibilidades desse tipo ou morrer tentando.

Qual o custo computacional da sua estratégia randômica? Se mostrou uma boa alternativa de execução?



# Qual a ultima coisa que eu fiz?
Fiz a função write output maze que salva a saída de uma matriz

# Qual a ultima coisa que eu fiz? #2
Hoje eu fiz as funções que definem em qual caso a posição corrente da matriz está para gerar possíveis caminhos que a posição pode tentar explorar.
Fiz a função que gera qual caminho. Nessa função, deve ser chamada a função de movimentação. Entretanto as funções devem ser implementadas e substituído os couts da função "generate next move" pelas respectivas funçoes de movimentação que os couts indicam.
as funções de movimentação ja foram declaradas no hpp e implementadas no cpp.
é bom encontrar uma forma de testar essa movimentação e tentar startar o código para resolver seus problemas.

ler o problema pra pensar na solução. escrever a ideia e so depois implementar

# Qual a ultima coisa que eu fiz?#3
Hoje eu reestrturei ocódigo pra deixar a main mais limpa, coloquei as funções de movimentação sendo chamadas na função "generate next move"  e criei uma função que printa a matrix colorida em uma posição específica.
Iniciei a função start que começa a execução do jogo, mas dentro dela por enquanto so estou testando se os movimentos gerados estão corespondendo e se estou conseguindo caminhar aleatoriamente dentro da matriz. Até então isso está funcionando. 

preciso começar a validar o caminhamento, adquirir as vidas, tomar dano. ou seja,implementar as ações do jogo de acordo com a posição. testarofuncionamento de cada ação e se funcionar tentar implementar o teletransporte;
gerar a matriz de contagem.

# Qual a ultima coisa que eu fiz? #4
Implementei o teletransporte e também tratei o caso de não movimentar para paredes. 
Testar as implementações de teletransporte, tentar ler as funções no hpp e entender a execução para então partir para as ações do jogo: consumir item, perder vidas, trabalhar com os contadores.
Hoje estou cansado, mas amanha vai dar certo.




![caso1](https://user-images.githubusercontent.com/64996505/233795540-9f95c754-6296-42fd-aa98-9d6187f15405.jpg)
![caso2](https://user-images.githubusercontent.com/64996505/233795552-4b3398ae-1ce5-4c2e-852d-772b59cbd647.jpg)
![caso3](https://user-images.githubusercontent.com/64996505/233795554-f1e68fa9-7fbf-4019-9077-73f1b69fce52.jpg)

![caso4](https://user-images.githubusercontent.com/64996505/233795563-442eef40-bda3-4dba-9ae7-7127b17fcd92.jpg)
![caso 5](https://user-images.githubusercontent.com/64996505/233795566-53501e2b-cc11-4e5a-9e78-861e18f05a50.jpg)
![caso 6](https://user-images.githubusercontent.com/64996505/233795570-fc452b8f-ea42-4ab4-b8bf-d723f28f4aae.jpg)

![caso 7](https://user-images.githubusercontent.com/64996505/233795578-810fe610-b5be-49d7-9ac1-e6fcb10ab2d2.jpg)
![caso 8](https://user-images.githubusercontent.com/64996505/233795580-a68dcc69-cf39-41c1-9a3e-c216d2e8a213.jpg)
![caso 9](https://user-images.githubusercontent.com/64996505/233795585-31de85e5-8989-492e-a0e9-635a7be6fe80.jpg)







