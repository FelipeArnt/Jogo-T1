#ifndef ITEM_H
#define ITEM_H

#include <string>

class Player;   

class Item {
protected:
    std::string nome;
    int peso;

public:
    Item(std::string n, int p) : nome(std::move(n)), peso(p) {}
    virtual ~Item() = default;

    // Cada item decide o que fazer quando usado
    virtual void usar(Player& p) = 0;

    // Descrição curta (mostrada no inventário)
    virtual std::string descricao() const = 0;

    // Consumíveis somem após o uso; equipamentos/materiais ficam
    virtual bool consumivel() const { return false; }

    // Acesso aos atributos (usado por Inventario::listar)
    const std::string& getNome() const { return nome; }
    int getPeso() const { return peso; }
};

class Coco : public Item {
public:
    Coco();
    void usar(Player& p) override;
    std::string descricao() const override;
    bool consumivel() const override { return true; }
};

class Peixe : public Item {
public:
    Peixe();
    void usar(Player& p) override;
    std::string descricao() const override;
    bool consumivel() const override { return true; }
};

class Carne : public Item {
public:
    Carne();
    void usar(Player& p) override;
    std::string descricao() const override;
    bool consumivel() const override { return true; }
};

class Faca : public Item {
private:
    int bonusAtaque;
public:
    Faca();
    void usar(Player& p) override;
    std::string descricao() const override;
};

class Lanca : public Item {
private:
    int bonusAtaque;
public:
    Lanca();
    void usar(Player& p) override;
    std::string descricao() const override;
};


class Madeira : public Item {
public:
    Madeira();
    void usar(Player& p) override;
    std::string descricao() const override;
};

class Corda : public Item {
public:
    Corda();
    void usar(Player& p) override;
    std::string descricao() const override;
};

#endif // ITEM_H