#include "RelayHandler.h"

RelayHandler::RelayHandler()
{
    _data.resize(RELAYTARGETTYPE_MAX, RelayData());
}

RelayHandler::~RelayHandler()
{
}

RelayHandler* RelayHandler::instance()
{
    static RelayHandler instance;
    return &instance;
}

bool RelayHandler::IsEnabled(RelayTargetType type)
{
    if (type >= RELAYTARGETTYPE_MAX)
        return false;

    return _data[type].enabled;
}

void RelayHandler::Enable(RelayTargetType type, bool value)
{
    if (type >= RELAYTARGETTYPE_MAX)
        return;

    _data[type].enabled = value;

    if (!value)
        _data[type].data.clear();
}

void RelayHandler::Send(RelayTargetType type, std::string const& message)
{
    if (type >= RELAYTARGETTYPE_MAX || message.empty() || !_data[type].enabled)
        return;

    _data[type].data.push_back(message);
}

std::string RelayHandler::GetNextMessage(RelayTargetType type)
{
    if (type >= RELAYTARGETTYPE_MAX || !_data[type].enabled || _data[type].data.empty())
        return std::string();

    std::string temp = _data[type].data.front();
    _data[type].data.pop_front();

    return temp;
}
