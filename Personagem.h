#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <iostream>

class Personagem {
private:
    // Membros (atributos)
    std::string primeiroNome;
    std::string ultimoNome;
    std::string descricao;
    
    int vida;
    int idade;
    int id_faccao;
    int id_criacao;

    int dinheiro_em_maos;

public:
    // Construtor - Apenas a declaração
    Personagem(std::string primeiroNome, std::string ultimoNome, int id_criacao);

    // Getters
    int getDinheiroNaMao();
    int getIdCriacao();

    std::string getPrimeiroNome();
    std::string getUltimoNome();
    std::string getNomeCompleto();

    // Setters
    void setDinheiroNaMao(int quantidadeDinheiro);
    void setDinheiroBanco(int quantidadeDinheiro);

};

#endif // PERSONAGEM_H