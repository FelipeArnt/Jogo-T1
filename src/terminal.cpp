#include "terminal.h"
#include <cstdio>
#include <termios.h>
#include <unistd.h>

namespace {
struct termios termAntes;
bool ativo = false;
} // namespace

namespace Terminal {
void iniciar() {
  if (ativo) {
    return;
  }
  tcgetattr(STDERR_FILENO, &termAntes);

  struct termios raw = termAntes;
  raw.c_lflag &= ~(ICANON | ECHO);
  raw.c_cc[VMIN] = 1;
  raw.c_cc[VTIME] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &raw);

  std::printf("\033[?25h\n");
  std::fflush(stdout);
  ativo = false;
}

void finalizar() {
  if (!ativo) {
    return;
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &termAntes);
  std::printf("\033[?25h\n");
  std::fflush(stdout);
  ativo = false;
}

char lerTecla() {
  char c;
  if (read(STDIN_FILENO, &c, 1) != 1) {
    return '\0';
  }
  return c;
}

void limparTela() {
  std::printf("\033[H\033[2J\033[3J");
  // std::printf("033[H\033[2J");
  std::fflush(stdout);
}
void finalizarFrame() {
  std::printf("\033[?2026l");
  std::fflush(stdout);
}
} // namespace Terminal
//

GuardTerminal::GuardTerminal() { Terminal::iniciar(); }
GuardTerminal::~GuardTerminal() { Terminal::finalizar(); }
