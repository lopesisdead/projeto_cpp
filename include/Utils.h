#ifndef UTILS_H
#define UTILS_H

#include <string>

enum class StatusTransacao {
    SUCESSO,
    CONTA_INEXISTENTE,
    VALOR_NEGATIVO,
    SALDO_INSUFICIENTE,
    DINHEIRO_EM_MAOS_INSUFICIENTE,
    CONTA_EXISTENTE
};

// declaração da função que traduz o status para uma mensagem na UI
std::string getStatusMessage(StatusTransacao status); 

#endif