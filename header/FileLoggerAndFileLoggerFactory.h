//
// Created by chanbin on 25. 2. 27.
//

#ifndef FILELOGGER_FILELOGGERFACTORY_H
#define FILELOGGER_FILELOGGERFACTORY_H

#include <fstream>
#include "LoggerAndLoggerFactory.h"

class FileLogger : public Logger
{

public:
    FileLogger();
    ~FileLogger();

    void info(const std::string&) const override;

    void warn(const std::string&) const override;

    void error(const std::string&) const override;


private:
    std::unique_ptr<std::ofstream> ofs;
};

class FileLoggerFactory : public LoggerFactory
{
    std::unique_ptr<Logger> createLogger() const override;
};

#endif //FILELOGGER_FILELOGGERFACTORY_H
