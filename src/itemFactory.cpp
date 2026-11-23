#include "itemFactory.h"
#include <stdexcept>
#include "excecoes.h"

std::unique_ptr<Item> ItemFactory::criar(const std::string& tipo) {
    if (tipo == "coco")    return std::make_unique<Coco>();
    if (tipo == "peixe")   return std::make_unique<Peixe>();
    if (tipo == "carne")   return std::make_unique<Carne>();
    if (tipo == "faca")    return std::make_unique<Faca>();
    if (tipo == "lanca")   return std::make_unique<Lanca>();
    if (tipo == "madeira") return std::make_unique<Madeira>();
    if (tipo == "corda")   return std::make_unique<Corda>();

   throw ItemDesconhecidoException(tipo);
}
