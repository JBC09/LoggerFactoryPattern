//
// Created by chanbin on 25. 2. 28.
//


#include "../header/DatabaseLoggerAndDatabaseLoggerFactory.h"
#include <format> // In order to have a string system

#include "../header/Time.h"

DatabaseLogger::DatabaseLogger()
{
    connectInit("localhost", "root", "1234", 33060);
}

DatabaseLogger::~DatabaseLogger() {
    session.reset();
}

bool DatabaseLogger::connectInit(std::string host, std::string user, std::string password, int port)
{

    // Data migration
    this->host = host;
    this->user = user;
    this->password = password;
    this->port = port;


    // DB Connect And Setting
    try
    {
        session = std::make_unique<mysqlx::Session>(std::format("mysqlx://{}:{}@{}:{}/", user, password, host, port));

        std::cout << "Connect Success" << std::endl;

        schema = std::make_unique<mysqlx::Schema>(session->getSchema("log"));

        table = std::make_unique<mysqlx::Table>(schema->getTable("logTable"));

        return true;
    }
    catch (const mysqlx::Error& err)
    {
        std::cout << "Database Error: " << err.what() << std::endl;
        return false;
    }
}

void DatabaseLogger::info(const std::string &str) const
{
    typeReciveLogging("Infotmation", str);
}

void DatabaseLogger::warn(const std::string &str) const
{
    typeReciveLogging("Warnning", str);
}

void DatabaseLogger::error(const std::string &str) const
{
    typeReciveLogging("Error", str);
}

void DatabaseLogger::typeReciveLogging(const std::string& type, const std::string& str) const
{
    try {
        mysqlx::TableInsert insert = table->insert("idlogTable", "logType", "description", "logDate")
                .values(NULL, type, str, Time::nowDate());

        insert.execute();
        std::cout << "ok" << std::endl;
    }
    catch (const mysqlx::Error &err) {
        std::cout << "Insert failed: " << err.what() << std::endl;
    }


}

std::unique_ptr<Logger> DatabaseLoggerFactory::createLogger() const
{
    return std::make_unique<DatabaseLogger>();
}


