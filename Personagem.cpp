#include "Personagem.h" // Inclui a declaração da classe

// Definição do Construtor
// Note o uso do operador de escopo (Personagem::) e a lista de inicialização
Personagem::Personagem(std::string nome, int id_criacao)
    : nome(nome), descricao(""), vida(100), idade(0), id_faccao(0), id_criacao(id_criacao),
      dinheiro_em_maos(0), saldo_bancario(0) {
    std::cout << "Personagem " << nome << " criado." << std::endl;
}

// Definição dos Getters
int Personagem::getDinheiroNaMao() {
    return dinheiro_em_maos;
}

int Personagem::getSaldoBancario() {
    return saldo_bancario;
}

// Definição dos Setters
void Personagem::setDinheiroNaMao(int quantidadeDinheiro) {
    dinheiro_em_maos = quantidadeDinheiro;
    std::cout << "US$ " << quantidadeDinheiro << " foram adicionados à carteira de " << nome << std::endl;
}

void Personagem::setDinheiroBanco(int quantidadeDinheiro) {
    saldo_bancario = quantidadeDinheiro;
    std::cout << "US$ " << quantidadeDinheiro << " foram adicionados ao saldo bancário de " << nome << std::endl;
}