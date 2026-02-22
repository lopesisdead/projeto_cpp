#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <pqxx/pqxx>
#include <memory>
#include <string>

class DBManager {
public:
    static DBManager& getInstance();
    pqxx::connection& getConnection();

private:
    DBManager();
    std::unique_ptr<pqxx::connection> conn;
    DBManager(const DBManager&) = delete;
    void operator=(const DBManager&) = delete;
};

#endif