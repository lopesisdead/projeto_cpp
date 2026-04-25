#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Item.h"
#include "Utils.h"

class Inventario {
private:
    std::vector<Item> itens;
    double pesoMaximo;
    double pesoAtual;

public:
    Inventario(double pesoMaximo);

    StatusTransacao adicionarItem(const Item& item);
    StatusTransacao removerItem(int idItem);
    
    void listarItens() const;
    double getPesoAtual() const;
};

#endif