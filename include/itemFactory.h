#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "item.h"
#include <memory>
#include <string>


class ItemFactory{
public:
    static std::unique_ptr<Item> criar(const std::string& tipo);
};

#endif