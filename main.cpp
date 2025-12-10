#include <iostream>
#include <string>
#include "Personagem.h"
#include "Banco.h"


int main() {

    std::cout << "Digite o primeiro nome do personagem: " << std::endl << std::endl;
    std::string primeiroNomePersonagem;
    std::cin >> primeiroNomePersonagem;

    std::cout << "Digite o sobrenome do personagem: " << std::endl << std::endl;
    std::string ultimoNomePersonagem;
    std::cin >> ultimoNomePersonagem;

    int id_criacao = 0; // fixo agora, mas depois será automaticamente incrementado

    Personagem personagemSessao(primeiroNomePersonagem, ultimoNomePersonagem, id_criacao);

    Banco bancoCentral;

    std::cout << "Dinheiro na mão: " << personagemSessao.getDinheiroNaMao() << std::endl; // por padrão, 0
    personagemSessao.setDinheiroNaMao(250);
    
    std::cout << "Dinheiro na mão: US$" << personagemSessao.getDinheiroNaMao() << std::endl;
    
    bancoCentral.depositar(personagemSessao.getIdCriacao(), 200);
    bancoCentral.criarConta(personagemSessao);

    bancoCentral.depositar(personagemSessao.getIdCriacao(), 200);
    bancoCentral.getSaldoBancario(personagemSessao.getIdCriacao());


    return 0;

}