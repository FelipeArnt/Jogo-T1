#ifndef JOGO_H
#define JOGO_H

#include "estadoJogo.h"
#include "inimigo.h"
#include "mapa.h"
#include "player.h"
#include <memory>
#include <vector>

class Jogo {
private:
  Player player;
  Mapa mapa;
  std::vector<std::unique_ptr<Inimigo>> inimigos;
  std::unique_ptr<EstadoJogo> estado;
  bool rodando = false;

public:
  void iniciar();
  void loop();
  void encerrar() { rodando = false;}
  void trocarEstado(std::unique_ptr<EstadoJogo> novo);

  Player &getPlayer();
  Mapa &getMapa();
  std::vector<std::unique_ptr<Inimigo>> &getInimigos();
  
  const Player& getPlayer() const;
  const Mapa& getMapa() const;
  const std::vector<std::unique_ptr<Inimigo>>& getInimigos() const;
  
  Inimigo *inimigoEm(int x, int y);
  const Inimigo *inimigoEm(int x, int y) const;
  void limparInimigos();
};

#endif // !JOGO_H
