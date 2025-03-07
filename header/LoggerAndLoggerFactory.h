//
// Created by chanbin on 25. 2. 27.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <memory>
#include <map>

class Logger
{
public:
    Logger() = default;
    ~Logger() = default;

    virtual void info(const std::string&) const = 0;
    virtual void warn(const std::string&) const = 0;
    virtual void error(const std::string&) const = 0;
};

class LoggerFactory
{

public:
    static std::map<std::string, std::unique_ptr<LoggerFactory>> LoggerFactoryHash;

    LoggerFactory() = default;
    ~LoggerFactory() = default;

    virtual std::unique_ptr<Logger> createLogger() const = 0;

    static std::unique_ptr<Logger> createLogger(const std::string& str);


};


#endif //LOGGER_H
