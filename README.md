# 🐍 Snake em C

Um jogo clássico de Snake rodando no terminal, desenvolvido em C com a biblioteca **ncurses**.

## 📋 Sobre o projeto

O jogo é executado diretamente no terminal e utiliza ncurses para renderização em modo texto. A cobra cresce a cada fruta coletada, e o objetivo é acumular o maior score possível.

## 🎮 Como jogar

| Tecla        | Ação              |
|--------------|-------------------|
| ← (seta)     | Mover para a esquerda |
| → (seta)     | Mover para a direita  |
| ↑ (seta)     | Mover para cima       |
| ↓ (seta)     | Mover para baixo      |
| `ESC`        | Sair do jogo          |

- **`O`** — cabeça da cobra
- **`o`** — segmentos do corpo
- **`@`** — fruta

## ⚙️ Requisitos

- Compilador C (gcc ou clang)
- Biblioteca **ncurses** instalada

### Instalando o ncurses

**Debian/Ubuntu:**
```bash
sudo apt install libncurses5-dev libncursesw5-dev
```

**Arch Linux:**
```bash
sudo pacman -S ncurses
```

**macOS (Homebrew):**
```bash
brew install ncurses
```

## 🔧 Compilação e execução

```bash
# Compilar
gcc main.c -o snake -lncurses

# Executar
./snake
```

## 🗂️ Estrutura do projeto

```
snake_c/
├── main.c    # Código-fonte principal
└── a.out     # Binário compilado
```

## 🧠 Detalhes técnicos

- **Tela:** grade de 20×20 células
- **Velocidade:** atualização a cada 125ms (~8 FPS)
- **Corpo:** armazenado em um array de até 256 segmentos (`vec2 segments[256]`)
- **Movimento:** a cobra não pode inverter de direção instantaneamente
- **Fruta:** posição gerada aleatoriamente a cada coleta

## 📌 Observações

- O jogo não detecta colisão com as paredes nem com o próprio corpo — a cobra atravessa os limites e a si mesma sem encerrar o jogo.
- Possíveis melhorias futuras: detecção de colisão, tela de game over, exibição de score e suporte a múltiplos níveis de velocidade.
