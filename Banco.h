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

    // criação conta. associa ela ao ID do personagem
    long criarConta(Personagem& personagem);

    // transações/operações
    bool depositar(long id_personagem, long valor);
    bool sacar(long id_personagem, long valor);

    // consulta
    long getSaldoBancario(long id_personagem);
    long getConta(Personagem& personagem);
    bool verificarExistenciaConta(Personagem& personagem);
};

#endif // BANCO_H