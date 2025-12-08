#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <iostream>

class Personagem {
private:
    // Membros (atributos)
    std::string nome;
    std::string descricao;
    int vida;
    int idade;
    int id_faccao;
    int id_criacao;

    int dinheiro_em_maos;
    int saldo_bancario;

public:
    // Construtor - Apenas a declaração
    Personagem(std::string nome, int id_criacao);

    // Getters
    int getDinheiroNaMao();
    int getSaldoBancario();

    // Setters
    void setDinheiroNaMao(int quantidadeDinheiro);
    void setDinheiroBanco(int quantidadeDinheiro);
};

#endif // PERSONAGEM_H