#include "Banco.h"

// construtor
Banco::Banco() : proximo_numero_conta(100000) {
    std::cout << "Sistema bancário iniciado." << std::endl;
}

void Banco::printContaExistente(std::string nome_personagem){
    std::cout << nome_personagem << " já tem uma conta bancária em seu nome." << std::endl;
}

void Banco::printContaInexistente(std::string nome_personagem){
    std::cout << "Erro: " << nome_personagem << " não tem uma conta bancária em seu nome." << std::endl;
}

bool isPositive(long valor){
    if(valor > 0){
        return true;
    }

    return false;
}

// --------------------------------------------------------------------

void Banco::criarConta(Personagem& personagem){

    long id_personagem = personagem.getIdCriacao();
    std::string nome_personagem = personagem.getNomeCompleto();

    if(verificarExistenciaConta(id_personagem)){
        printContaExistente(nome_personagem);
        return; // indicativo erro
    }

    ContaBancaria novaConta;
    novaConta.numero_conta = proximo_numero_conta++;
    novaConta.saldo = 0;

    // associa o ID do Personagem ao objeto ContaBancaria no mapa
    contas[id_personagem] = novaConta;

    std::cout << "Conta bancária de #" << novaConta.numero_conta << " criada no nome de " << nome_personagem << std::endl;

    return;
}

// --------------------------------------------------------------------

bool Banco::verificaDinheiroEmMaos(Personagem& personagem, long valor){
    long quantidade_dinheiro_em_maos = personagem.getDinheiroNaMao();

    if(valor > quantidade_dinheiro_em_maos){
        return false;
    }

    return true;
}

bool Banco::verificaSaldoBancario(Personagem& personagem, long valor){
    long saldo_bancario_personagem = getSaldoBancario(personagem);

    if(valor > saldo_bancario_personagem){
        return false;
    }

    return true;
}

bool Banco::aumentarSaldo(long id_personagem, long valor){
    contas[id_personagem].saldo += valor;

    std::cout << "Conta #" << contas[id_personagem].numero_conta << ": Depósito de US$" << valor 
              << " realizado. Novo saldo: US$" << contas[id_personagem].saldo << "." << std::endl;

    return true;
}

bool Banco::debitarSaldo(long id_personagem, long valor){
    contas[id_personagem].saldo -= valor;

    std::cout << "Conta #" << contas[id_personagem].numero_conta << ": Saque de US$" << valor 
              << " realizado. Novo saldo: US$" << contas[id_personagem].saldo << "." << std::endl;

    return true;
}

bool Banco::depositar(Personagem& personagem, long valor){
    long id_personagem = personagem.getIdCriacao();
    std::string nome_personagem = personagem.getNomeCompleto();

    if (!verificarExistenciaConta(id_personagem)) {
        printContaInexistente(nome_personagem);
        return false;
    }

    if (!isPositive(valor)) {
        std::cout << "Erro. O valor a ser depositado não pode ser negativo." << std::endl;
        return false;
    }

    if(!verificaDinheiroEmMaos(personagem, valor)){
        std::cout << "Erro. Você não tem essa quantidade de dinheiro em mãos para depositar.";
        return false;
    }

    aumentarSaldo(id_personagem, valor);
    personagem.takeDinheiroNaMao(valor);
    return true;
}

bool Banco::sacar(Personagem& personagem, long valor){
    long id_personagem = personagem.getIdCriacao();
    std::string nome_personagem = personagem.getNomeCompleto();

    if(!verificarExistenciaConta(id_personagem)){
        printContaInexistente(nome_personagem);
        return false;
    }

    if (!isPositive(valor)) {
        std::cout << "Erro. O valor a ser sacado não pode ser negativo." << std::endl;
        return false;
    }

    if(!verificaSaldoBancario(personagem, valor)){
        std::cout << "Erro. O valor é maior do que o disponível nesta conta bancária.";
        return false;
    }

    debitarSaldo(id_personagem, valor);
    personagem.giveDinheiroNaMao(valor);
    return true;

}

// --------------------------------------------------------------------

// 3. verificar Saldo
long Banco::getSaldoBancario(Personagem& personagem) {
    long id_personagem = personagem.getIdCriacao();

    if (verificarExistenciaConta(id_personagem)) {
        return contas.at(id_personagem).saldo;
    }

    return -1; // indicativo erro
}

long Banco::getConta(Personagem& personagem) {

    long id_personagem = personagem.getIdCriacao();
    
    // verifica se o personagem já tem uma conta
    if (verificarExistenciaConta(id_personagem)) {
        return contas[id_personagem].numero_conta;
    }

    printContaInexistente(personagem.getNomeCompleto());
    return -1; // indica erro. usuário precisa criar a conta primeiro.
}

bool Banco::verificarExistenciaConta(long id_personagem){
    if(contas.count(id_personagem)){
        return true;
    }
    
    return false;
}