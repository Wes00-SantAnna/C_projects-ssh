---

## 🔢 **Conversão TMTL para Decimal**

### 🎯 **Objetivo:**

Criar um programa que converta números da notação **TMTL** (Tenho-Muito-Tempo-Livre) para a notação decimal.

---

### 🧠 **Descrição da Notação TMTL:**

- Utiliza os dígitos decimais `0` a `9`.
- Cada dígito `aᵢ` (começando da esquerda, com índice `i = 1`) tem peso `i!` (fatorial de `i`).
- O valor total é a soma dos termos `aᵢ × i!`.

---

### 📌 **Exemplo de Conversão:**

```
719_TMTL = 7 × 3! + 1 × 2! + 9 × 1! = 7 × 6 + 1 × 2 + 9 × 1 = 53
```

---

### 📥 **Entrada:**

- Vários números inteiros positivos (com no máximo 4 dígitos).
- A entrada termina com o número `1`.

---

### 📤 **Saída:**

- Um número decimal por linha, correspondente à conversão de cada número TMTL.
- Deve haver **uma quebra de linha no final**.

---

### 🧪 **Exemplo:**

### **Entrada:**

```
719
15
-1
```

### **Saída:**

```
53
7
```

---

### 🛠️ **Compilação e Execução no Terminal:**

```bash
gcc tmtl_dec.c -o tmtl
./tmtl
```

---