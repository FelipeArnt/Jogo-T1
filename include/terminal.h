#ifndef TERMINAL_H
#define TERMINAL_H

namespace Terminal {
void iniciar();
void finalizar();
char lerTecla();
void limparTela();
void finalizarFrame();
} // namespace Terminal

struct GuardTerminal {
  GuardTerminal();
  ~GuardTerminal();
  GuardTerminal(const GuardTerminal &) = delete;
  GuardTerminal &operator=(const GuardTerminal &) = delete;
};

#endif
