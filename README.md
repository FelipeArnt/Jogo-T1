# 🏝️ Naufrago na ilha — Jogo de Sobrevivência em C++

Jogo no terminal de sobrevivência em turnos, inspirado em **Secret of Mana (1993)**.
Após um naufrágio, o jogador explora uma ilha em grid, gerencia recursos
(fome, sede, energia), coleta itens e enfrenta inimigos em **combate por turnos**.

Projeto desenvolvido para a disciplina de **Programação Orientada a Objetos**.

---

## 🎮 Funcionalidades

- **Mapa em grid** carregado de arquivo texto (`mapa_001.txt`)
- **Movimentação** com WASD, renderização em tempo real no terminal (ANSI escape codes)
- **Sistema de sobrevivência** — fome, sede e energia aumentam/diminuem com o tempo
- **Inventário** com capacidade limitada e itens consumíveis/equipáveis
- **Combate por turnos** com 3 ações (atacar / defender / fugir) e IA polimórfica
- **3 tipos de inimigo** com comportamentos distintos (Caranguejo, Javali, Pirata)
- **Interação com o ambiente** — água doce (sede), fogueira (fome), árvore (madeira)
- **Estado de Game Over** com retorno limpo ao terminal

---

## 🚀 Como compilar e rodar

### Pré-requisitos

- **g++** com suporte a C++17 (Linux, macOS, WSL)
- **make**

Instalação (Ubuntu/Debian):

```bash
sudo apt install build-essential
```

### Build e execução

- make          
- make run     
- make clean
- ./jogo

--- 

Desenvolvido por Felipe Arnt.
