#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <iostream>
#include <map>
#include "Personagem.h"

enum class StatusTransacao {
    SUCESSO,
    CONTA_INEXISTENTE,
    VALOR_NEGATIVO,
    SALDO_INSUFICIENTE,
    DINHEIRO_EM_MAOS_INSUFICIENTE,
    CONTA_JA_EXISTENTE
};

class Banco {
private:
    // membros (atributos)
    //  mapa: id do personagem (chave) -> dados da conta (valor)
    struct ContaBancaria{
        long numero_conta;
        long saldo_bancario;
    };


    std::map<long, ContaBancaria> contas;
    long proximo_numero_conta;

public:
    // construtor
    Banco();

    void printContaExistente(std::string nome_personagem);
    void printContaInexistente(std::string nome_personagem);

    // criação conta. associa ela ao ID do personagem
    StatusTransacao criarConta(Personagem& personagem);

    // transações/operações
    StatusTransacao depositar(Personagem& personagem, long valor);
    StatusTransacao sacar(Personagem& personagem, long valor);
    StatusTransacao aumentarSaldo(long id_personagem, long valor);
    StatusTransacao debitarSaldo(long id_personagem, long valor);

    // consulta
    long getSaldoBancario(Personagem& personagem);
    long getConta(Personagem& personagem);
    bool verificarExistenciaConta(long id_personagem);
    StatusTransacao verificaDinheiroEmMaos(Personagem& personagem, long valor);
    StatusTransacao verificaSaldoBancario(Personagem& personagem, long valor);
};

#endif // BANCO_H