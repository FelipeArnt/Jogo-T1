#include "jogo.h"
#include "estadoExploracao.h"
#include "excecoes.h"
#include "inimigoFactory.h"
#include "terminal.h"
#include <algorithm>
#include <iostream>

void Jogo::iniciar() {
  try {
    mapa.carregarArquivo("mapa_001.txt");
  } catch (const MapaNaoEncontradoException &e) {
    std::cerr << "ERRO FATAL: mapa '" << e.getCaminho()
              << "' nao encontrado.\n";
    rodando = false;
    return;
  } catch (const JogoException &e) {
    std::cerr << "ERRO FATAL: " << e.what() << '\n';
    rodando = false;
    return;
  }

  player.setPosicao(mapa.getSpawnX(), mapa.getSpawnY());

  for (int y = 0; y < mapa.getAltura(); ++y) {
    for (int x = 0; x < mapa.getLargura(); ++x) {
      if (mapa.getTile(x, y).getTipo() == TipoTile::SPAWN_INIMIGO) {
        inimigos.push_back(InimigoFactory::criar("caranguejo", x, y));
        mapa.getTile(x, y) = Tile(TipoTile::AREIA);
      }
    }
  }

  rodando = true;
  trocarEstado(std::make_unique<EstadoExploracao>());
}
/* Loop do jogo aasx*/

void Jogo::loop() {
  while (rodando && estado) {
    estado->renderizar(*this);
    Terminal::finalizarFrame();
    estado->atualizar(*this);
    limparInimigos();
  }
}

void Jogo::trocarEstado(std::unique_ptr<EstadoJogo> novo) {
  estado = std::move(novo);
}

/* Acesso que da pra modificar */
Player &Jogo::getPlayer() { return player; }
Mapa &Jogo::getMapa() { return mapa; }
std::vector<std::unique_ptr<Inimigo>> &Jogo::getInimigos() { return inimigos; }

/* Acesso const so leiotura*/
const Player &Jogo::getPlayer() const { return player; }
const Mapa &Jogo::getMapa() const { return mapa; }
const std::vector<std::unique_ptr<Inimigo>> &Jogo::getInimigos() const {
  return inimigos;
}

Inimigo *Jogo::inimigoEm(int x, int y) {
  for (auto &i : inimigos) {
    if (i->vivo() && i->getX() == x && i->getY() == y) {
      return i.get();
    }
  }
  return nullptr;
}

/* Consultar posicao dos inimigos */
const Inimigo *Jogo::inimigoEm(int x, int y) const {
  for (const auto &i : inimigos) {
    if (i->vivo() && i->getX() == x && i->getY() == y) {
      return i.get();
    }
  }
  return nullptr;
}

void Jogo::limparInimigos() {
  inimigos.erase(std::remove_if(inimigos.begin(), inimigos.end(),
                                [](const std::unique_ptr<Inimigo> &i) {
                                  return !i->vivo();
                                }),
                 inimigos.end());
}
