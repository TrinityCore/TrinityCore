#include "Log.h"
#include "World.h"
#include "Config.h"
#include "IRCBridge.h"

IRCBridge::IRCBridge() : _active(false), _connected(false)
{
}

IRCBridge::~IRCBridge()
{
    Stop();
}

void IRCBridge::Run()
{
    if (!LoadConfigurations())
        return;

}

void IRCBridge::Stop()
{

}

bool IRCBridge::LoadConfigurations()
{
    SetConfiguration(CONFIGURATION_IRCBRIDGE_HOST, sConfigMgr->GetStringDefault("IRCBridge.Host", ""));
    if (GetConfiguration(CONFIGURATION_IRCBRIDGE_HOST).empty())
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: missing IRCBridge.Host value on configuration file.");
        return false;
    }
    SetConfiguration(CONFIGURATION_IRCBRIDGE_PORT, LoadConfiguration(CONFIGURATION_IRCBRIDGE_PORT, "IRCBridge.Port", 6667));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_USERNAME, LoadConfiguration(CONFIGURATION_IRCBRIDGE_USERNAME, "IRCBridge.Username", "IRCBridge"));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_NICKNAME, LoadConfiguration(CONFIGURATION_IRCBRIDGE_NICKNAME, "IRCBridge.Nickname", "IRCBridge"));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_PASSWORD, sConfigMgr->GetStringDefault("IRCBridge.Password", ""));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD, LoadConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD, "IRCBridge.Authentication.Method", 0));
    if (uint32 temp = GetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD) > 4)
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: incorrect IRCBridge.Authentication.Method value (%u) on configuration file, using default value instead.", temp);
        SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD, 0);
    }
    SetConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_NICKNAME, LoadConfiguration(CONFIGURATION_IRCBRIDGE_AUTHENTICATION_NICKNAME, "IRCBridge.Authentication.Nickname", "NickServ"));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_CODE, LoadConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_CODE, "IRCBridge.Connection.Code", 001));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_WAIT, LoadConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_WAIT, "IRCBridge.Connection.Wait", 10000));
    SetConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_ATTEMPTS, LoadConfiguration(CONFIGURATION_IRCBRIDGE_CONNECTION_ATTEMPTS, "IRCBridge.Connection.Attempts", 20));

    return true;
}

uint32 IRCBridge::LoadConfiguration(IRCBridgeConfigurationUintValues index, char const * fieldname, uint32 defvalue) const
{
    int32 temp = sConfigMgr->GetIntDefault(fieldname, defvalue);
    if (temp < 0)
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: %s value (%i) can't be negative, using default value %u instead.", fieldname, temp, defvalue);
        temp = defvalue;
    }

    return uint32(temp);
}

std::string IRCBridge::LoadConfiguration(IRCBridgeConfigurationStringValues index, char const * fieldname, std::string defvalue) const
{
    std::string temp = sConfigMgr->GetStringDefault(fieldname, defvalue);
    if (temp.empty())
    {
        TC_LOG_ERROR("IRCBridge", "IRCBridge::LoadConfigurations: %s value is empty, using default value %u instead.", fieldname, defvalue);
        temp = defvalue;
    }

    return temp;
}
