//
// Created by chanbin on 25. 2. 28.
//

#ifndef DATABASELOGGER_DATABASELOGGERFACTORY_H
#define DATABASELOGGER_DATABASELOGGERFACTORY_H
#include "LoggerAndLoggerFactory.h"
#include <mysqlx/xdevapi.h>


class DatabaseLogger : public Logger
{
private:
    std::string host;
    std::string user;
    std::string password;
    int port;
    std::unique_ptr<mysqlx::Session> session;
    std::unique_ptr<mysqlx::Schema> schema;
    std::unique_ptr<mysqlx::Table> table;

    bool connectInit(std::string , std::string , std::string , int );

public:
    DatabaseLogger();
    ~DatabaseLogger();


    void info(const std::string&) const override;
    void warn(const std::string&) const override;
    void error(const std::string&) const override;

    void typeReciveLogging(const std::string&, const std::string&) const;
};



class DatabaseLoggerFactory : public LoggerFactory
{
public:
    DatabaseLoggerFactory() = default;
    ~DatabaseLoggerFactory() = default;

    std::unique_ptr<Logger> createLogger() const;
};

#endif //DATABASELOGGER_DATABASELOGGERFACTORY_H
