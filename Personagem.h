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
    long id_faccao;
    long id_criacao;

    long dinheiro_em_maos;

public:
    // Construtor - Apenas a declaração
    Personagem(std::string primeiroNome, std::string ultimoNome, long id_criacao);

    // Getters
    long getDinheiroNaMao();
    long getIdCriacao();

    std::string getPrimeiroNome();
    std::string getUltimoNome();
    std::string getNomeCompleto();

    // Setters
    void setDinheiroNaMao(long quantidadeDinheiro);
    void giveDinheiroNaMao(long quantidadeDinheiro);
    void takeDinheiroNaMao(long quantidadeDinheiro);

};

#endif // PERSONAGEM_H