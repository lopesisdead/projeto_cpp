#include "Item.h"

// construtor
Item::Item(long id, std::string nome, std::string descricao, double peso) : id(id_criacao), nome(nome_item), descricao(descricao_item), peso(peso_em_kg){
    // mantém o std::cout no construtor, pois é o ponto de inicialização do sistema.
    std::cout << "Item " << getNomeItem() << " foi criado." << std::endl; 
}

// Getters
std::string Item::getNomeItem() {
    return nome;
}

long Item::getIdItem() {
    return id;
}

std::string Item::getDescricaoItem(){
    return descricao;
}

double Item::getPesoItem(){
    return peso;
}

// Setters
void Item::setNomeItem(std::string novo_nome_item) {
    nome = novo_nome_item;
}

void Item::setDescricaoItem(std::string nova_descricao_item) {
    descricao = nova_descricao_item;
}

void Item::setPesoItem(double novo_peso_item) {
    peso = novo_peso_item;
}