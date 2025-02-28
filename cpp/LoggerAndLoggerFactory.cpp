//
// Created by chanbin on 25. 2. 27.
//
#include "../header/LoggerAndLoggerFactory.h"

#include "../header/DatabaseLoggerAndDatabaseLoggerFactory.h"
#include "../header/FileLoggerAndFileLoggerFactory.h"

std::map<std::string, std::unique_ptr<LoggerFactory>> LoggerFactory::LoggerFactoryHash;


std::unique_ptr<Logger> LoggerFactory::createLogger(const std::string &str)
{
    LoggerFactoryHash.insert({"File", std::make_unique<FileLoggerFactory>()});
    LoggerFactoryHash.insert({"Database", std::make_unique<DatabaseLoggerFactory>()});

    auto it = LoggerFactoryHash.find(str);

    if (it != LoggerFactoryHash.end())
    {
        return it->second->createLogger();
    }

    throw std::runtime_error("Is not exist Logger Type\n"
    "exist Type -> File, Database, Console\n"
    "Only First char UpperCase And rest LowerCase");
}
