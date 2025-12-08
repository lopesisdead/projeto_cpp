#include "Banco.h"


// construtor
Banco::Banco() : proximo_numero_conta(100000) {
    std::cout << "Sistema bancário iniciado." << std::endl;
}

// 1. cria conta e a associa a um personagem
int Banco::criarConta(const Personagem& personagem) {

    int id_personagem = personagem.getIdCriacao();
    
    // verifica se o personagem já tem uma conta
    if (contas.count(id_personagem)) {
        std::cout << "Erro: " << personagem.getNomeCompleto() << " já tem uma conta bancária (Número: " 
                  << contas[id_personagem].numero_conta << ")." << std::endl;
        return contas[id_personagem].numero_conta;
    }

    // cria a nova conta
    ContaBancaria novaConta;
    novaConta.numero_conta = proximo_numero_conta++;
    novaConta.saldo = 0;

    // associa o ID do Personagem ao objeto ContaBancaria no mapa
    contas[id_personagem] = novaConta;

    std::cout << "Conta bancária #" << novaConta.numero_conta 
              << " criada com sucesso para " << personagem.getNomeCompleto() 
              << " (ID: " << id_personagem << ")." << std::endl;
    return novaConta.numero_conta;
}

// 2. depositar Dinheiro
bool Banco::depositar(int id_personagem, int valor) {
    if (!contas.count(id_personagem)) {
        std::cout << "Erro: Personagem com ID " << id_personagem << " não possui conta bancária." << std::endl;
        return false;
    }
    if (valor <= 0) {
        std::cout << "Depósito falhou: O valor deve ser positivo." << std::endl;
        return false;
    }
    
    // aumentar o saldo
    contas[id_personagem].saldo += valor;
    std::cout << "Conta No " << contas[id_personagem].numero_conta << ": Depósito de US$" << valor 
              << " realizado. Novo saldo: US$" << contas[id_personagem].saldo << "." << std::endl;
    return true;
}

// 3. verificar Saldo
int Banco::verificarSaldo(int id_personagem) const {
    if (!contas.count(id_personagem)) {
        std::cout << "Erro: Personagem de ID " << id_personagem << " não possui uma conta bancária." << std::endl;
        return -1; // retorna -1 para indicar erro
    }
    return contas.at(id_personagem).saldo;
}