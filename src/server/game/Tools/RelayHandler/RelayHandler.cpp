#include "RelayHandler.h"

RelayHandler::RelayHandler()
{
    _data.resize(RELAYTARGETTYPE_MAX);
}

RelayHandler::~RelayHandler()
{
}

RelayHandler* RelayHandler::instance()
{
    static RelayHandler instance;
    return &instance;
}

void RelayHandler::Send(RelayTargetType const type, std::string const message)
{
    if (type >= RELAYTARGETTYPE_MAX || message.empty())
        return;

    _data[type].push(message);
}

std::string RelayHandler::GetNextMessage(RelayTargetType const type)
{
    if (type >= RELAYTARGETTYPE_MAX || _data[type].empty())
        return std::string();

    std::string temp = _data[type].front();
    _data[type].pop();

    return temp;
}
