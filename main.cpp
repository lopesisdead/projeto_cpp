#include <iostream>
#include <string>
#include <cstdlib> // Necessário para system()
#include "Personagem.h"
#include "Banco.h"

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
        // Limpa o console a cada iteração
        // Se estiver no Windows, use system("cls");
        system("clear");

        // Cabeçalho persistente
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

        std::cout << "\n"; // Pula linha para organização visual

        switch(decisaoUsuario) {
            case 1: {
                long valor;
                std::cout << "Digite a quantidade: ";
                std::cin >> valor;
                personagemSessao.setDinheiroNaMao(valor);
                break;
            }
            case 2: {
                long valor;
                std::cout << "Digite o valor do saque: ";
                std::cin >> valor;
                bancoCentral.sacar(personagemSessao, valor);
                break;
            }
            case 3: {
                long valor;
                std::cout << "Digite o valor do depósito: ";
                std::cin >> valor;
                bancoCentral.depositar(personagemSessao, valor);
                break;
            }
            case 4:
                bancoCentral.criarConta(personagemSessao);
                break;
            case 5: {
                long numConta = bancoCentral.getConta(personagemSessao);
                if(numConta != -1) {
                    std::cout << "O número da sua conta é: " << numConta << std::endl;
                }
                break;
            }
            case 6:
                std::cout << "Encerrando sistema...\n";
                break;
            default:
                std::cout << "Opção inválida, tente novamente.\n";
        }

        // Pausa para que o usuário possa ler o resultado antes de limpar a tela
        if (decisaoUsuario != 6) {
            std::cout << "\nPressione Enter para continuar...";
            std::cin.ignore(); // Limpa o buffer do teclado
            std::cin.get();    // Aguarda o Enter
        }

    } while (decisaoUsuario != 6);

    return 0;
}