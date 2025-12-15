#include "Utils.h"
#include <sstream>

// implementando função que traduz o Status para uma string.
std::string getStatusMessage(StatusTransacao status) {
    switch (status) {
        case StatusTransacao::SUCESSO:
            return "Operação realizada com sucesso.";
        case StatusTransacao::CONTA_INEXISTENTE:
            return "Erro: Conta bancária não existe para este personagem.";
        case StatusTransacao::VALOR_NEGATIVO:
            return "Erro: O valor da transação não pode ser negativo ou zero.";
        case StatusTransacao::SALDO_INSUFICIENTE:
            return "Erro: Saldo bancário insuficiente para esta operação.";
        case StatusTransacao::DINHEIRO_EM_MAOS_INSUFICIENTE:
            return "Erro: Você não tem essa quantidade de dinheiro em mãos.";
        case StatusTransacao::CONTA_EXISTENTE:
            return "Erro: Este personagem já possui uma conta bancária.";
        default:
            return "Erro desconhecido na transação.";
    }
}