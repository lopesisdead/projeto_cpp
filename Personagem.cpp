#include "Personagem.h" // Inclui a declaração da classe

// construtor
Personagem::Personagem(std::string primeiroNome, std::string ultimoNome, long id_criacao)
    : primeiroNome(primeiroNome), ultimoNome(ultimoNome), descricao(""), vida(100), idade(0), id_faccao(0), id_criacao(id_criacao),
      dinheiro_em_maos(0){
    std::cout << "Personagem " << getNomeCompleto() << " criado." << std::endl;
}

// Getters
long Personagem::getDinheiroNaMao() {
    return dinheiro_em_maos;
}

long Personagem::getIdCriacao() {
    return id_criacao;
}

std::string Personagem::getPrimeiroNome(){
    return primeiroNome;
}

std::string Personagem::getUltimoNome(){
    return ultimoNome;
}

std::string Personagem::getNomeCompleto(){
    std::string nomeCompleto = primeiroNome + " " + ultimoNome;
    return nomeCompleto;
}

// Setters
void Personagem::setDinheiroNaMao(long quantidadeDinheiro) {
    dinheiro_em_maos = quantidadeDinheiro;
    std::cout << "US$ " << quantidadeDinheiro << " foram adicionados à carteira de " << getPrimeiroNome() << std::endl;
}

void Personagem::giveDinheiroNaMao(long quantidadeDinheiro) {
    dinheiro_em_maos += quantidadeDinheiro;
    std::cout << "US$ " << quantidadeDinheiro << " foram adicionados à carteira de " << getPrimeiroNome() << std::endl;
}

void Personagem::takeDinheiroNaMao(long quantidadeDinheiro) {
    dinheiro_em_maos -= quantidadeDinheiro;
    std::cout << "US$ " << quantidadeDinheiro << " foram removidos da carteira de " << getPrimeiroNome() << std::endl;
}