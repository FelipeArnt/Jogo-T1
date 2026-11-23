#ifndef ESTADOJOGO_H
#define ESTADOJOGO_H

class Jogo;

class EstadoJogo {
public:
  virtual ~EstadoJogo() = default;

  virtual void atualizar(Jogo &jogo) = 0;
  virtual void renderizar(const Jogo &jogo) const = 0;
};

#endif
