#include "IRCBridgeHandler.h"

IRCBridgeHandler::IRCBridgeHandler()
{
}

IRCBridgeHandler::~IRCBridgeHandler()
{
}

IRCBridgeHandler* IRCBridgeHandler::instance()
{
    static IRCBridgeHandler instance;
    return &instance;
}

std::string IRCBridgeHandler::GetNext()
{
    if (_data.empty())
        return std::string();

    std::string temp = _data.front();
    _data.pop();

    return temp;
}
