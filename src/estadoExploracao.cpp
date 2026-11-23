#include "estadoExploracao.h"
#include "estadoCombate.h"
#include "estadoGameOver.h"
#include "jogo.h"
#include "terminal.h"
#include <iostream>

void EstadoExploracao::atualizar(Jogo &jogo) {
  char t = Terminal::lerTecla();
  if (t == '\0')
    return;

  auto &p = jogo.getPlayer();
  int nx = p.getX(), ny = p.getY();

  switch (t) {
  case 'w':
  case 'W':
    ny--;
    break;
  case 's':
  case 'S':
    ny++;
    break;
  case 'a':
  case 'A':
    nx--;
    break;
  case 'd':
  case 'D':
    nx++;
    break;
  case 'e':
  case 'E':
    interagir(jogo);
    return;
  case 'q':
  case 'Q':
    jogo.encerrar();
    return;
  default:
    return;
  }

  tentarMover(jogo, nx, ny);
}
void EstadoExploracao::tentarMover(Jogo &jogo, int nx, int ny) {
  auto &p = jogo.getPlayer();
  auto &m = jogo.getMapa();

  if (m.bloqueado(nx, ny))
    return; // sem mensagem — o mapa já mostra

  p.setPosicao(nx, ny);
  p.passarTempo();

  if (Inimigo *inimigo = jogo.inimigoEm(nx, ny)) {
    jogo.trocarEstado(std::make_unique<EstadoCombate>(inimigo));
  }
}

void EstadoExploracao::interagir(Jogo &jogo) {
  auto &p = jogo.getPlayer();
  auto &m = jogo.getMapa();

  int px = p.getX(), py = p.getY();
  if (px < 0 || py < 0 || px >= m.getLargura() || py >= m.getAltura())
    return;

  Tile &t = m.getTile(px, py);
  if (!t.isInteragivel())
    return;
  t.interagir(p);
}

void EstadoExploracao::renderizar(const Jogo &jogo) const {
  Terminal::limparTela();

  const auto &m = jogo.getMapa();
  const auto &p = jogo.getPlayer();

  std::string out;
  out.reserve((m.getLargura() + 1) * m.getAltura() + 256);

  for (int y = 0; y < m.getAltura(); ++y) {
    for (int x = 0; x < m.getLargura(); ++x) {
      char c = m.getTile(x, y).simbolo();

      if (x == p.getX() && y == p.getY())
        c = '@';
      else if (jogo.inimigoEm(x, y))
        c = 'E';

      out += c;
    }
    out += '\n';
  }

  out += '\n';
  out += "HP: " + std::to_string(p.getVida()) + "/" +
         std::to_string(p.getMaxVida()) +
         "  Fome: " + std::to_string(p.getFome()) +
         "  Sede: " + std::to_string(p.getSede()) +
         "  Energia: " + std::to_string(p.getEnergia()) + '\n';
  out += "[WASD] mover   [E] interagir   [Q] sair\n";

  std::cout << out << std::flush;
}
