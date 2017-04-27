#include "RelayHandler.h"

RelayHandler::RelayHandler()
{
}

RelayHandler::~RelayHandler()
{
}

RelayHandler* RelayHandler::instance()
{
    static RelayHandler instance;
    return &instance;
}

std::string RelayHandler::GetNext()
{
    if (_data.empty())
        return std::string();

    std::string temp = _data.front();
    _data.pop();

    return temp;
}
