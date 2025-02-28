// 수정된 코드
#include <iostream>
#include "./header/LoggerAndLoggerFactory.h"
#include <memory>

int main()
{
    std::unique_ptr<Logger> FileLogger = LoggerFactory::createLogger("File");

    // 따옴표가 제대로 닫혔는지 확인
    FileLogger->info("hello");

    std::unique_ptr<Logger> DatabaseLogger = LoggerFactory::createLogger("Database");

    DatabaseLogger->info("asdasdas");

    return 0;
}