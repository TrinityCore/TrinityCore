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
