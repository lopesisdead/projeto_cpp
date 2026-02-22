#include <iostream>
#include <string>
#include <cstdlib> // necessário para system()
#include "Personagem.h"
#include "Banco.h"
#include "Utils.h"

int main() {
    std::string primeiroNomePersonagem;
    std::string ultimoNomePersonagem;

    std::cout << "Digite o primeiro nome do personagem: ";
    std::cin >> primeiroNomePersonagem;

    std::cout << "Digite o sobrenome do personagem: ";
    std::cin >> ultimoNomePersonagem;

    long id_criacao = 0; 
    Personagem personagemSessao(primeiroNomePersonagem, ultimoNomePersonagem, id_criacao);
    Banco bancoCentral;

    int decisaoUsuario = 0;

    do {
        // limpa o console a cada iteração
        // se estiver no Windows, use system("cls");
        system("clear");

        // cabeçalho persistente
        std::cout << "====================================\n";
        std::cout << "Bem-vindo, " << personagemSessao.getNomeCompleto() << "\n";
        std::cout << "Dinheiro em mãos: US$ " << personagemSessao.getDinheiroNaMao() << "\n";

        long saldo = bancoCentral.getSaldoBancario(personagemSessao);
        if (saldo == -1) {
             std::cout << "Saldo Bancário: [Conta não criada]\n";
        } else {
             std::cout << "Saldo Bancário: US$ " << saldo << "\n";
        }
        std::cout << "====================================\n\n";

        std::cout << "1 - Definir dinheiro na mão\n";
        std::cout << "2 - Realizar saque\n";
        std::cout << "3 - Realizar depósito\n";
        std::cout << "4 - Criar conta bancária\n";
        std::cout << "5 - Verificar número da conta\n";
        std::cout << "6 - Sair\n";
        std::cout << "\nEscolha uma opção: ";
        std::cin >> decisaoUsuario;

        std::cout << "\n"; // apenas para pular uma linha e deixar mais organizado visualmente

        switch(decisaoUsuario) {
            case 1: {
                long valor;
                std::cout << "Digite a quantidade: ";
                std::cin >> valor;
                personagemSessao.setDinheiroNaMao(valor);
                std::cout << "Dinheiro em mãos definido para US$ " << valor << "." << std::endl;
                break;
            }
            case 2: {
                long valor;
                std::cout << "Digite o valor do saque: ";
                std::cin >> valor;
                
                StatusTransacao status = bancoCentral.sacar(personagemSessao, valor);
                
                if (status == StatusTransacao::SUCESSO) {
                    std::cout << "Saque de US$" << valor << " realizado com sucesso. Dinheiro adicionado à sua carteira." << std::endl;
                } else {
                    std::cout << getStatusMessage(status) << std::endl;
                }
                break;
            }
            case 3: {
                long valor;
                std::cout << "Digite o valor do depósito: ";
                std::cin >> valor;
                
                StatusTransacao status = bancoCentral.depositar(personagemSessao, valor);
                
                if (status == StatusTransacao::SUCESSO) {
                    std::cout << "Depósito de US$" << valor << " realizado com sucesso." << std::endl;
                } else {
                    std::cout << getStatusMessage(status) << std::endl;
                }
                break;
            }
            case 4: {
                StatusTransacao status = bancoCentral.criarConta(personagemSessao);
                
                if (status == StatusTransacao::SUCESSO) {
                    long numConta = bancoCentral.getConta(personagemSessao);
                    std::cout << "Conta bancária de #" << numConta << " criada no nome de " << personagemSessao.getNomeCompleto() << std::endl;
                } else {
                    std::cout << getStatusMessage(status) << std::endl;
                }
                break;
            }
            case 5: {
                long numConta = bancoCentral.getConta(personagemSessao);
                if(numConta != -1) {
                    std::cout << "O número da sua conta é: " << numConta << std::endl;
                } else {
                    // como getConta retorna -1, usa a função de UI existente no Banco
                    // que, idealmente, deveria ser movida.
                    bancoCentral.printContaInexistente(personagemSessao.getNomeCompleto());
                }
                break;
            }
            case 6:
                std::cout << "Encerrando sistema...\n";
                break;
            default:
                std::cout << "Opção inválida, tente novamente.\n";
        }

        // pausa para que o usuário possa ler o resultado antes de limpar a tela
        if (decisaoUsuario != 6) {
            std::cout << "\nPressione Enter para continuar...";
            std::cin.ignore(); // limpa o buffer do teclado
            std::cin.get();    // aguarda o Enter
        }

    } while (decisaoUsuario != 6);

    return 0;
}