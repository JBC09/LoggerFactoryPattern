//
// Created by chanbin on 25. 2. 27.
//


#include "../header/FileLoggerAndFileLoggerFactory.h"

#include "../header/Time.h"


void FileLogger::info(const std::string& str) const
{
    if (ofs->is_open())
    {
        *ofs << " [ Infomation ] -> " << str << std::endl;
    }
}

void FileLogger::warn(const std::string& str) const
{

    if (ofs->is_open())
    {
        *ofs << " [ Warnning ] -> " << str <<  std::endl;
    }
}

void FileLogger::error(const std::string& str) const
{
    if (ofs->is_open())
    {
        *ofs << " [ Error ] -> " << str << std::endl;
    }
}

FileLogger::FileLogger()
{

    ofs = std::make_unique<std::ofstream>();
    ofs->open( std::format("{}Log.txt", Time::nowDate()));
}

FileLogger::~FileLogger()
{
    ofs.reset();
}

std::unique_ptr<Logger> FileLoggerFactory::createLogger() const
{
    return std::make_unique<FileLogger>();
}

