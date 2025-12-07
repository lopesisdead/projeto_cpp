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
    int getDinheiroNaMao() {
        return dinheiro_em_maos;
    }

    void setDinheiroNaMao(int quantidadeDinheiro) {
        dinheiro_em_maos = quantidadeDinheiro;
        std::cout << quantidadeDinheiro << " foram adicionados à carteira de " << nome << std::endl;
    }

    int getSaldoBancario() {
        return saldo_bancario;
    }

    void setDinheiroBanco(int quantidadeDinheiro) {
        saldo_bancario = quantidadeDinheiro;
        std::cout << quantidadeDinheiro << " foram adicionados ao saldo bancário de " << nome << std::endl;
    }
};


int main() {
    Personagem john_doe("John Doe", "Um cidadao comum", 100, 35, 0, 1001);

    std::cout << "Dinheiro na mão: " << john_doe.getDinheiroNaMao() << std::endl; // 500 - 300 + 150 = 350
    std::cout << "Saldo bancário: " << john_doe.getSaldoBancario() << std::endl; // 300 - 150 = 150

    john_doe.setDinheiroBanco(1000);
    john_doe.setDinheiroNaMao(250);
    
    std::cout << "Dinheiro na mão: " << john_doe.getDinheiroNaMao() << std::endl; // 500 - 300 + 150 = 350
    std::cout << "Saldo bancário: " << john_doe.getSaldoBancario() << std::endl; // 300 - 150 = 150

    return 0;
}