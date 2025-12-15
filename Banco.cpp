#include "Banco.h"

namespace {
    bool isPositive(long valor){
        return valor > 0;
    }
}

// construtor
Banco::Banco() : proximo_numero_conta(100000) {
    // mantém o std::cout no construtor, pois é o ponto de inicialização do sistema.
    std::cout << "Sistema bancário iniciado." << std::endl; 
}

void Banco::printContaExistente(std::string nome_personagem){
    std::cout << nome_personagem << " já tem uma conta bancária em seu nome." << std::endl;
}

void Banco::printContaInexistente(std::string nome_personagem){
    std::cout << "Erro: " << nome_personagem << " não tem uma conta bancária em seu nome." << std::endl;
}

// --------------------------------------------------------------------

// criação conta. associa ela ao ID do personagem
StatusTransacao Banco::criarConta(Personagem& personagem){

    long id_personagem = personagem.getIdCriacao();

    if(verificarExistenciaConta(id_personagem)){
        return StatusTransacao::CONTA_EXISTENTE; // status de erro
    }

    ContaBancaria novaConta;
    novaConta.numero_conta = proximo_numero_conta++;
    novaConta.saldo_bancario = 0;

    // associa o ID do Personagem ao objeto ContaBancaria no mapa
    contas[id_personagem] = novaConta;

    return StatusTransacao::SUCESSO;
}

// --------------------------------------------------------------------

StatusTransacao Banco::verificaDinheiroEmMaos(Personagem& personagem, long valor){
    long quantidade_dinheiro_em_maos = personagem.getDinheiroNaMao();

    if(valor > quantidade_dinheiro_em_maos){
        return StatusTransacao::DINHEIRO_EM_MAOS_INSUFICIENTE;
    }

    return StatusTransacao::SUCESSO;
}

StatusTransacao Banco::verificaSaldoBancario(Personagem& personagem, long valor){
    long saldo_bancario_personagem = getSaldoBancario(personagem);

    // Nota: getSaldoBancario retorna -1 se a conta não existe, o que funciona aqui,
    // mas se a conta existe e o saldo for insuficiente, retorna o erro correto.
    if(valor > saldo_bancario_personagem){ 
        return StatusTransacao::SALDO_INSUFICIENTE;
    }

    return StatusTransacao::SUCESSO;
}

// transações/operações
StatusTransacao Banco::aumentarSaldo(long id_personagem, long valor){
    contas[id_personagem].saldo_bancario += valor;

    return StatusTransacao::SUCESSO;
}

StatusTransacao Banco::debitarSaldo(long id_personagem, long valor){
    contas[id_personagem].saldo_bancario -= valor;
    return StatusTransacao::SUCESSO;
}

StatusTransacao Banco::depositar(Personagem& personagem, long valor){
    long id_personagem = personagem.getIdCriacao();

    // 1. verifica existência da conta
    if (!verificarExistenciaConta(id_personagem)) {
        return StatusTransacao::CONTA_INEXISTENTE;
    }

    // 2. verifica valor positivo
    if (!isPositive(valor)) {
        return StatusTransacao::VALOR_NEGATIVO;
    }

    // 3. verifica dinheiro em mãos
    StatusTransacao statusDinheiro = verificaDinheiroEmMaos(personagem, valor);
    if(statusDinheiro != StatusTransacao::SUCESSO){
        // std::cout << "Erro. Você não tem essa quantidade de dinheiro em mãos..."; // REMOVIDO!
        return statusDinheiro;
    }

    // execução
    aumentarSaldo(id_personagem, valor);
    personagem.takeDinheiroNaMao(valor);
    return StatusTransacao::SUCESSO;
}

StatusTransacao Banco::sacar(Personagem& personagem, long valor){
    long id_personagem = personagem.getIdCriacao();

    // 1. Verifica existência da conta
    if(!verificarExistenciaConta(id_personagem)){
        return StatusTransacao::CONTA_INEXISTENTE;
    }

    // 2. Verifica valor positivo
    if (!isPositive(valor)) {
        return StatusTransacao::VALOR_NEGATIVO;
    }

    // 3. verifica saldo bancário
    StatusTransacao statusSaldo = verificaSaldoBancario(personagem, valor);
    if(statusSaldo != StatusTransacao::SUCESSO){
        return statusSaldo;
    }

    // execução
    debitarSaldo(id_personagem, valor);
    personagem.giveDinheiroNaMao(valor);
    return StatusTransacao::SUCESSO;

}

// --------------------------------------------------------------------

// 3. verificar Saldo
long Banco::getSaldoBancario(Personagem& personagem) {
    long id_personagem = personagem.getIdCriacao();

    if (verificarExistenciaConta(id_personagem)) {
        return contas.at(id_personagem).saldo_bancario;
    }

    return -1; // indicativo erro
}

long Banco::getConta(Personagem& personagem) {

    long id_personagem = personagem.getIdCriacao();
    
    if (verificarExistenciaConta(id_personagem)) {
        return contas[id_personagem].numero_conta;
    }

    return -1; // indica erro. usuário precisa criar a conta primeiro.
}

bool Banco::verificarExistenciaConta(long id_personagem){
    if(contas.count(id_personagem)){
        return true;
    }
    
    return false;
}