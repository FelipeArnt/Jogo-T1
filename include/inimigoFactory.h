#ifndef INIMIGOFACTORY_H
#define INIMIGOFACTORY_H

#include <memory>
#include <string>
#include "inimigo.h"
#include "caranguejo.h"
#include "javali.h"
#include "pirata.h"



class InimigoFactory{
public:
    static std::unique_ptr<Inimigo> criar(const std::string& tipo, int x, int y){
        if (tipo == "caranguejo") {return std::make_unique<Caranguejo>(x, y);}
        if (tipo == "pirata") {return std::make_unique<Pirata>(x,y);}
        if (tipo == "javali") {return std::make_unique<Javali>(x,y);}

        return std::make_unique<Javali>(x, y);
    }
};

#endif