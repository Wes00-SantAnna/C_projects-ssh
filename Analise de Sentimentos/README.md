## 📄 Analisador de Sentimentos em C

Este projeto em C realiza uma **análise de sentimentos simples** sobre trechos de texto divididos em parágrafos. A análise é feita com base em listas de palavras positivas e negativas, fornecidas pelo usuário. O programa também identifica a **frase mais curta** e a **mais longa** dentro do texto, além de responder a questões específicas sobre a polaridade de parágrafos ou frases.

---

### ✅ Funcionalidades

- Converte texto para letras minúsculas.
- Identifica a frase mais **longa** e a mais **curta** no texto (separadas por `.`).
- Conta palavras positivas e negativas no texto.
- Determina a **polaridade** de:
    - Todo o texto;
    - Um parágrafo específico;
    - A frase mais longa;
    - A frase mais curta.

A polaridade pode ser:

- `positiva` ✅
- `negativa` ❌
- `neutra` ⚪

---

### 📥 Entrada

A entrada deve seguir esta ordem:

1. Número de parágrafos (`int`)
2. Os parágrafos (um por linha)
3. Lista de palavras **positivas** (uma linha contendo palavras separadas por espaço)
4. Lista de palavras **negativas** (uma linha contendo palavras separadas por espaço)
5. Número de questões (`int`)
6. Lista de questões (uma por linha, podendo conter um número extra dependendo do tipo)

### Tipos de questão:

| Código | Ação |
| --- | --- |
| 1 | Analisar polaridade do texto completo |
| 2 x | Analisar polaridade do parágrafo de índice x |
| 3 | Analisar polaridade da **frase mais longa** |
| 4 | Analisar polaridade da **frase mais curta** |

---

### 📤 Saída

1. A frase mais curta (`curta: ...`)
2. A frase mais longa (`longa: ...`)
3. Para cada questão, imprime:
    
    ```
    X Palavras positivas, Y Palavras negativas: Polaridade [positiva|negativa|neutra]
    ```
    

---

### 📌 Exemplo de Entrada

```
2
Like Xenogears, you also pilot mechs though they are less important in this game, and are more a background theme than being the focus. Music was done by Yasunori Mitsuda and performed by the London Philharmonic Orchestra and it definitely shows. While much of the game is just ambient sounds, whenever the music does take over it brings with it the magic of what a truly well-composed and performed orchestrated soundtrack can do for a game. The graphics are well done, and animated very smoothly and the effects during battles are very pretty. Being a little older than some recent RPG's (Was released over a year ago in Japan and the translation took forever) the graphics seem slightly dated but they are still beautiful.
And now the bad news: For me this game possesses only one flaw in that the English dubbing of it is only average, sounding like a dubbed anime. Many characters are over acting and it pains me to see this in such a quality RPG. It doesn't help that during the cut scenes the dialogue is subtitled right along with the actors speaking the same language which would be fine if they sounded better, but since they don't it's annoying to read it before they say it, and hear them say it with forced emotion or non at all. It is a minor flaw in a near flawless RPG. The other concern is the editing. There is one cut scene that was altered and it only involves the placement of a hand. Nothing to worry about.
well important magic well-composed smoothly beautiful flawless quality fine
less background average overacting pains annoying forced concern altered worry flaw
2
2 0
2 1
```

---

### 📌 Exemplo de Saída

```
curta: the editing
longa: like xenogears, you also pilot mechs though they are less important in this game, and are more a background theme than being the focus
4 Palavras positivas, 5 Palavras negativas: Polaridade neutra
4 Palavras positivas, 10 Palavras negativas: Polaridade negativa

```

---

### 🛠️ Compilação e Execução

```bash
gcc analisador.c -o analisador
./analisador < entrada.txt
```

---

### 🧠 Observações

- A análise de sentimentos é baseada **apenas na contagem** de palavras positivas e negativas.
- A polaridade depende da diferença entre contagens:
    - Se a diferença for maior que 3 ou só houver um tipo de palavra, a polaridade é definida.
    - Diferença pequena ou ausência de termos relevantes resulta em polaridade neutra.
- No diretório tem algumas opções de entrada

---