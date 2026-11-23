#include "estadoCombate.h"
#include "estadoExploracao.h"
#include "estadoGameOver.h"
#include "inimigo.h"
#include "excecoes.h"
#include "itemFactory.h"
#include "jogo.h"
#include "player.h"
#include "terminal.h"
#include <cstdlib>
#include <iostream>

Acao EstadoCombate::lerAcaoPlayer() const {
  while (true) {
    std::cout << "\n[A] Atacar [D] Defender [F] Fugir\n";
    char c;
    c = Terminal::lerTecla();
    switch (c) {
    case 'a':
    case 'A':
      return Acao::ATACAR;
    case 'd':
    case 'D':
      return Acao::DEFENDER;
    case 'f':
    case 'F':
      return Acao::FUGIR;
    default:
      std::cout << "Opcao invalida!\n";
    }
  }
}

void EstadoCombate::atualizar(Jogo &jogo) {
  if (terminou || !inimigo) {
    return;
  }

  Player &plyr = jogo.getPlayer();
  defendendo = false;

  Acao a = lerAcaoPlayer();

  if (a == Acao::FUGIR) {
    /* static cast pq o atributo energia é unsigned int e o std::max precisa de
     * valores do mesmo tipo*/
    int energia = static_cast<int>(plyr.getEnergia());
    int chance = 50 + std::max(0, energia - 50);
    if ((std::rand() % 100) < chance) {
      std::cout << "Voce conseguiu escapar do inimigo!\n";
      finalizar(jogo);
      return;
    }
    std::cout << "Fuga falhou!\n";
  } else {
    executarAcaoPlayer(jogo, a);
  }

  if (!inimigo->vivo()) {
    std::cout << "Você derrotou o " << inimigo->getNome() << "!!\n";
    if (auto drop = inimigo->soltarMochila()) {
      try {
        plyr.getInventario().adicionar(std::move(drop));
        std::cout << "Você pegou um item!\n";
      } catch (const InventarioCheioException& e) {
        std::cout << "Inventario cheio (: " << e.getCapacidade() << ") - item descartado!"
                  << "\n";
      }
      catch(const JogoException& e){
        std::cout << "Erro: " << e.what() << "\n";
      }
    }
    finalizar(jogo);
    return;
  }

  Acao maquina = inimigo->decidirAcao();
  executarAcaoInimigo(jogo, maquina);

  if (!plyr.vivo()) {
    jogo.trocarEstado(
        std::make_unique<EstadoGameOver>("Você morreu em combate!\n"));
    terminou = true;
    return;
  }
}

void EstadoCombate::executarAcaoPlayer(Jogo &jogo, Acao a) {
  Player &plyr = jogo.getPlayer();
  switch (a) {
  case Acao::ATACAR:
    std::cout << "Você ataca o " << inimigo->getNome() << "!\n";
    inimigo->receberDano(plyr.getAtaque());
    break;
  case Acao::DEFENDER:
    std::cout << "Você se prepara para defender! \n";
    defendendo = true;
    break;
  case Acao::FUGIR:
    std::cout << "Você irá fugir!\n";
    break;
  }
}

void EstadoCombate::executarAcaoInimigo(Jogo &jogo, Acao a) {
  Player &plyr = jogo.getPlayer();
  switch (a) {
  case Acao::ATACAR:
    if (defendendo) {
      unsigned int dano = inimigo->getAtaque() / 2;
      if (dano == 0) {
        dano = 1;
      }
      std::cout << inimigo->getNome()
                << " ataca - você bloqueia parte do dano!\n";
      plyr.receberDano(dano);
    } else {
      std::cout << inimigo->getNome() << " ataca!\n";
      inimigo->agir(plyr);
    }
    break;

  case Acao::DEFENDER:
    std::cout << inimigo->getNome() << " se defende. \n";
    break;
  case Acao::FUGIR:
    std::cout << inimigo->getNome() << " foge do combate!\n";
    inimigo->receberDano(inimigo->getMaxVida());
    finalizar(jogo);
    break;
  }
}

void EstadoCombate::finalizar(Jogo &jogo) {
  terminou = true;
  jogo.trocarEstado(std::make_unique<EstadoExploracao>());
}
void EstadoCombate::renderizar(const Jogo &jogo) const {
  Terminal::limparTela();

  const auto &p = jogo.getPlayer();

  std::string out;
  out += "=== COMBATE ===\n\n";
  out += p.getNome() + "  HP " + std::to_string(p.getVida()) + "/" +
         std::to_string(p.getMaxVida()) + "\n";
  if (inimigo) {
    out += inimigo->getNome() + "  HP " + std::to_string(inimigo->getVida()) +
           "/" + std::to_string(inimigo->getMaxVida()) + "\n";
  }
  out += "\n[A] Atacar   [D] Defender   [F] Fugir\n";

  std::cout << out << std::flush;
}
