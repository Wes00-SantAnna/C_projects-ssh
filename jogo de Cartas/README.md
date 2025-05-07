# 🃏 Jogo de Cartas — Simulador em C

Este programa em C simula um jogo de cartas entre quatro jogadores (A, B, C e D), baseado em regras especiais de pontuação envolvendo a carta 12 de Espadas e cartas do naipe de Copas. O jogo prossegue por rodadas até que algum jogador atinja **100 pontos ou mais**, momento em que o jogo termina e é declarado o vencedor e o perdedor.

## 📋 Regras do Jogo

- Cada jogador começa com 0 pontos.
- A entrada define quantas cartas cada jogador recebe em uma rodada.
- Para cada carta:
    - Se for **12-E** (Dama de Espadas), o jogador recebe **13 pontos**.
    - Cada **carta de Copas** vale **1 ponto**.
- Se um jogador tiver **a 12-E** **e** **todas as 13 cartas de Copas**, ele faz os outros 3 jogadores receberem **26 pontos** cada, e ele não recebe nada na rodada.
- A pontuação é cumulativa.
- O jogo termina quando qualquer jogador atinge ou ultrapassa **100 pontos**.

## ✅ Exemplo de Entrada

```
3 2 4 3
12-E C-C C-C
12-O C-C
2-E 5-C 7-C 12-E
C-C C-C C-C

```

Cada linha representa a entrada das cartas de um jogador, na ordem A, B, C, D.

## ✅ Exemplo de Saída

```
A: 2 B: 1 C: 14 D: 3
Vencedor: jogador B; Ultimo lugar: jogador C

```

## 🧠 Lógica Interna

- O programa usa:
    - Vetores para armazenar as cartas dos jogadores e as pontuações.
    - Uma matriz `caso[4][2]` para verificar:
        - Se o jogador tem a 12-E.
        - Quantas cartas de Copas possui.
- O loop principal roda rodadas sucessivas até um jogador atingir 100 pontos.

## 🛠️ Compilação e Execução

Compile com `gcc`:

```bash
gcc -o jogo_cartas jogo_cartas.c
./jogo_cartas

```

## 🧾 Saída Final

Ao fim do jogo, é impresso:

```
Vencedor: jogador <X>; Ultimo lugar: jogador <Y>

```

Com o jogador de menor pontuação como vencedor e o de maior pontuação como último lugar.

---