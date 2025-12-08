#include <iostream>
#include <string>
#include "Personagem.h"


int main() {

    std::cout << "Digite o nome do personagem: " << std::endl << std::endl;

    std::string nome_personagem;
    std::cin >> nome_personagem;

    int id_criacao = 0; // fixo agora, mas depois será automaticamente incrementado

    Personagem personagemSessao(nome_personagem, id_criacao);

    std::cout << "Dinheiro na mão: " << personagemSessao.getDinheiroNaMao() << std::endl; // por padrão, 0
    std::cout << "Saldo bancário: " << personagemSessao.getSaldoBancario() << std::endl << std::endl; // 0

    personagemSessao.setDinheiroBanco(1000);
    personagemSessao.setDinheiroNaMao(250);
    
    std::cout << "Dinheiro na mão: US$ " << personagemSessao.getDinheiroNaMao() << std::endl;
    std::cout << "Saldo bancário: US$ " << personagemSessao.getSaldoBancario() << std::endl << std::endl;

    return 0;

}