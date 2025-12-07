#include <iostream>
#include <string>

class Personagem{
private:
    std::string nome;
    std::string descricao;
    int vida;
    int idade;
    int id_faccao;
    int id_criacao;

    int dinheiro_em_maos; // Dinheiro que o personagem carrega
    int saldo_bancario; // Dinheiro na conta bancária

public:
    // Construtor
    Personagem(std::string n, std::string d, int v, int i, int f, int c)
        : nome(n), descricao(d), vida(v), idade(i), id_faccao(f), id_criacao(c),
          dinheiro_em_maos(0), saldo_bancario(0) {
        std::cout << "Personagem " << nome << " criado." << std::endl;
    }

    // Getters
    int getDinheiroNaMao() const {
        return dinheiro_em_maos;
    }

    int getSaldoBancario() const {
        return saldo_bancario;
    }
};


int main() {
    Personagem john_doe("John Doe", "Um cidadao comum", 100, 35, 0, 1001);
    
    std::cout << "Dinheiro na Mao: " << john_doe.getDinheiroNaMao() << std::endl; // 500 - 300 + 150 = 350
    std::cout << "Saldo Bancario: " << john_doe.getSaldoBancario() << std::endl; // 300 - 150 = 150

    return 0;
}