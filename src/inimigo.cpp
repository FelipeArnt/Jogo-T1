#include "inimigo.h"
#include "item.h"
#include "personagem.h"

void Inimigo::agir(Personagem &alvo) { alvo.receberDano(getAtaque()); }
std::unique_ptr<Item> Inimigo::soltarMochila() { return nullptr; }
