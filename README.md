# TP3-TBO

## Instruções do Makefile
Para compilar normalmente:
```bash
    make
```
Para compilar no modo `dubug` (isso fará com que o programa imprima o tempo de execução quando rodar ele):
```bash
    make debug
```

Rodar o programa:
```bash
    make run
```

Rodar o programa com valgrind:
```bash
    make valgrind
```

## Atenção ao utilizar
Note que o buscador continuará rodando "inifinatamente" pois ele fica aguardando a digitar alguma coisa. Após digitar, ele processa, imprime o resultado (se houver) e em seguida alguarda por uma nova consulta.

Para evitar esse "loop infinito" crie um arquivo `txt` coloque uma consulta (alguma palavra ou conjunto de termos separados por espaço) e execute o comando:
```bash
    ./trab3 exemplo <arquivo.txt
```
Dessa forma o programa fará a consulta e será encerrado.

## Próximos passos:
- Otimização do código:
    - Apesar de ser um teste pequeno, o código está rápido, porém é possível melhorar. Abaixo alguns pontos que eu acho que podem ser melhorados.
    - O arquivo index.txt é aberto duas vezes, talvez fosse possivel fazer tudo abrindo apenas uma única vez.
    - StringMap (estrutura que representa todas as palavras dos arquivos utilizados) utiliza uma RBT, mas se fosse representado com uma TST eu acredito que daria um salto de desempenho considerável (já que as consultas são realizadas lá), além de economizar memória.
- Documentação do README e dos arquivos .h (padrão doxygen).
- Bem provável que seja possível melhorar a lógica do código, mas de início, o importante é que está funcionando e desalocando memória corretamente.