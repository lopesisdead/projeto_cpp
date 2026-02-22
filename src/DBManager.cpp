#include "DBManager.h"
#include <cstdlib> 
/* 
biblioteca necessária para o comando std::getenv.
a configuração das variáveis de ambiente vai depender
do seu SO. no geral, para Linux, haverá um arquivo
de configuração na home (~) chamado .zshrc ou .bashrc
ou similar. para confirmar, use o comando ls -a e procure-o.

dentro deste arquivo, adicione, ao final dele, algo como:
export DB_NAME="mydb"
export DB_USER="postgres"
e assim por diante até completar todas as variáveis usadas
abaixo. em seguida, salve, feche o arquivo e use o comando 
source [NOME_ARQUIVO] para recarregar o terminal com as novas
variáveis do ambiente.

nota: também e possível (e mais recomendado) usar um arquivo .env.
*/
#include <iostream>

DBManager::DBManager() {
    // buscando os valores do sistema operacional
    const char* db = std::getenv("DB_NAME");
    const char* user = std::getenv("DB_USER");
    const char* pass = std::getenv("DB_PASS");
    const char* host = std::getenv("DB_HOST");
    const char* port = std::getenv("DB_PORT");

    // verificandp se as variáveis essenciais existem
    if (!db || !user || !pass) {
        throw std::runtime_error("Variáveis de ambiente do banco de dados não configuradas.");
    }

    // montando a string de conexão
    std::string str = "dbname=" + std::string(db) + 
                      " user=" + std::string(user) + 
                      " password=" + std::string(pass) + 
                      " host=" + (host ? host : "localhost") + 
                      " port=" + (port ? port : "5432");

    conn = std::make_unique<pqxx::connection>(str);
}