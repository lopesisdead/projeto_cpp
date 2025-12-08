#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <iostream>
#include <map>
#include "Personagem.h"

struct ContaBancaria{
    long numero_conta;
    long saldo_bancario;
}

class Banco {
private:
    // membros (atributos)
    //  mapa: id do personagem (chave) -> dados da conta (valor)
    std::map<long, ContaBancaria> contas;
    long proximo_numero_conta;

public:
    // construtor
    Banco();

    // criação conta. associa ela ao ID do personagem
    long criarConta(const Personagem& personagem);

    // transações/operações
    bool depositar(int id_personagem, long valor);
    bool sacar(long id_personagem, long valor);

    // consulta
    int getSaldoBancario(long id_personagem);
};

#endif // BANCO_H