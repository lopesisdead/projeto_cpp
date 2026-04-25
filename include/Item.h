#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    long id;
    std::string nome;
    std::string descricao;
    double peso;

public:
    Item(long id, std::string nome, std::string descricao, double peso);
    
    long getIdItem();
    std::string getNomeItem();
    double getPesoItem();

    void setNomeItem(std::string novo_nome_item);
    void setDescricaoItem(std::string nova_descricao_item);
    void setPesoItem(double novo_peso_item);
    
}

#endif