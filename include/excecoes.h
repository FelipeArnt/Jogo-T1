#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

//  Exceção base do jogo
class JogoException : public std::runtime_error {
public:
    explicit JogoException(const std::string& msg)
        : std::runtime_error(msg) {}
};

//  Inventário sem espaço
class InventarioCheioException : public JogoException {
private:
    int capacidade;
public:
    explicit InventarioCheioException(int cap)
        : JogoException("Inventario cheio (capacidade " +
                        std::to_string(cap) + ")"),
          capacidade(cap) {}

    int getCapacidade() const { return capacidade; }
};

//  Mapa não pôde ser carregado
class MapaNaoEncontradoException : public JogoException {
private:
    std::string caminho;
public:
    explicit MapaNaoEncontradoException(const std::string& c)
        : JogoException("Mapa nao encontrado: " + c),
          caminho(c) {}

    const std::string& getCaminho() const { return caminho; }
};


//  Coordenada fora dos limites
class CoordenadaInvalidaException : public JogoException {
private:
    int x, y;
public:
    CoordenadaInvalidaException(int x_, int y_)
        : JogoException("Coordenada invalida: (" +
                        std::to_string(x_) + ", " +
                        std::to_string(y_) + ")"),
          x(x_), y(y_) {}

    int getX() const { return x; }
    int getY() const { return y; }
};

//  Tipo de item desconhecido na Factory
class ItemDesconhecidoException : public JogoException {
private:
    std::string tipo;
public:
    explicit ItemDesconhecidoException(const std::string& t)
        : JogoException("Item desconhecido: '" + t + "'"),
          tipo(t) {}

    const std::string& getTipo() const { return tipo; }
};

#endif // EXCECOES_H

