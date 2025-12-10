#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <iostream>
#include <map>
#include "Personagem.h"

struct ContaBancaria{
    long numero_conta;
    long saldo;
    long saldo_bancario;
};

class Banco {
private:
    // membros (atributos)
    //  mapa: id do personagem (chave) -> dados da conta (valor)
    std::map<long, ContaBancaria> contas;
    long proximo_numero_conta;

public:
    // construtor
    Banco();

    void printContaExistente(std::string nome_personagem);
    void printContaInexistente(std::string nome_personagem);

    // criação conta. associa ela ao ID do personagem
    void criarConta(Personagem& personagem);

    // transações/operações
    bool depositar(Personagem& personagem, long valor);
    bool sacar(Personagem& personagem, long valor);
    bool aumentarSaldo(long id_personagem, long valor);
    bool debitarSaldo(long id_personagem, long valor);

    // consulta
    long getSaldoBancario(Personagem& personagem);
    long getConta(Personagem& personagem);
    bool verificarExistenciaConta(long id_personagem);
};

#endif // BANCO_H