#include "Appender.h"
#include "Common.h"

std::string LogMessage::getTimeStr(time_t time)
{
    tm* aTm = localtime(&time);
    char buf[20];
    snprintf(buf, 20, "%04d-%02d-%02d_%02d:%02d:%02d", aTm->tm_year+1900, aTm->tm_mon+1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    return std::string(buf);
}

std::string LogMessage::getTimeStr()
{
    return getTimeStr(mtime);
}

Appender::Appender(uint8 _id, std::string const& _name, AppenderType _type /* = APPENDER_NONE*/, LogLevel _level /* = LOG_LEVEL_DISABLED */):
id(_id), name(_name), type(_type), level(_level)
{
}

Appender::~Appender()
{
}

uint8 Appender::getId() const
{
    return id;
}

std::string const& Appender::getName() const
{
    return name;
}

AppenderType Appender::getType() const
{
    return type;
}

LogLevel Appender::getLogLevel() const
{
    return level;
}

void Appender::setLogLevel(LogLevel _level)
{
    level = _level;
}

void Appender::write(LogMessage& message)
{
    if (level && level <= message.level)
        _write(message);
    //else fprintf(stderr, "Appender::write: Appender %s, Level %s. Msg %s Level %s Type %s WRONG LEVEL MASK\n", getName().c_str(), getLogLevelString(level), message.text.c_str(), getLogLevelString(message.level), getLogFilterTypeString(message.type)); // DEBUG - RemoveMe
}

const char* Appender::getLogLevelString(LogLevel level)
{
    switch (level)
    {
        case LOG_LEVEL_FATAL:
            return "FATAL";
        case LOG_LEVEL_ERROR:
            return "ERROR";
        case LOG_LEVEL_WARN:
            return "WARN";
        case LOG_LEVEL_INFO:
            return "INFO";
        case LOG_LEVEL_DEBUG:
            return "DEBUG";
        case LOG_LEVEL_TRACE:
            return "TRACE";
        default:
            return "DISABLED";
    }
}

char const* Appender::getLogFilterTypeString(LogFilterType type)
{
    switch (type)
    {
        case LOG_FILTER_GENERAL:
            return "GENERAL";
        case LOG_FILTER_UNITS:
            return "UNITS";
        case LOG_FILTER_PETS:
            return "PETS";
        case LOG_FILTER_VEHICLES:
            return "VEHICLES";
        case LOG_FILTER_TSCR:
            return "TSCR";
        case LOG_FILTER_DATABASE_AI:
            return "DATABASE_AI";
        case LOG_FILTER_MAPSCRIPTS:
            return "MAPSCRIPTS";
        case LOG_FILTER_NETWORKIO:
            return "NETWORKIO";
        case LOG_FILTER_SPELLS_AURAS:
            return "SPELLS_AURAS";
        case LOG_FILTER_ACHIEVEMENTSYS:
            return "ACHIEVEMENTSYS";
        case LOG_FILTER_CONDITIONSYS:
            return "CONDITIONSYS";
        case LOG_FILTER_POOLSYS:
            return "POOLSYS";
        case LOG_FILTER_AUCTIONHOUSE:
            return "AUCTIONHOUSE";
        case LOG_FILTER_BATTLEGROUND:
            return "BATTLEGROUND";
        case LOG_FILTER_OUTDOORPVP:
            return "OUTDOORPVP";
        case LOG_FILTER_CHATSYS:
            return "CHATSYS";
        case LOG_FILTER_LFG:
            return "LFG";
        case LOG_FILTER_MAPS:
            return "MAPS";
        case LOG_FILTER_PLAYER:
            return "PLAYER";
        case LOG_FILTER_PLAYER_LOADING:
            return "PLAYER_LOADING";
        case LOG_FILTER_PLAYER_ITEMS:
            return "PLAYER_ITEMS";
        case LOG_FILTER_PLAYER_SKILLS:
            return "PLAYER_SKILLS";
        case LOG_FILTER_PLAYER_CHATLOG:
            return "PLAYER_CHATLOG";
        case LOG_FILTER_LOOT:
            return "LOOT";
        case LOG_FILTER_GUILD:
            return "GUILD";
        case LOG_FILTER_TRANSPORTS:
            return "TRANSPORTS";
        case LOG_FILTER_SQL:
            return "SQL";
        case LOG_FILTER_GMCOMMAND:
            return "GMCOMMAND";
        case LOG_FILTER_REMOTECOMMAND:
            return "REMOTECOMMAND";
        case LOG_FILTER_WARDEN:
            return "WARDEN";
        case LOG_FILTER_AUTHSERVER:
            return "AUTHSERVER";
        case LOG_FILTER_WORLDSERVER:
            return "WORLDSERVER";
        case LOG_FILTER_GAMEEVENTS:
            return "GAMEEVENTS";
        default:
            break;
    }
    return "???";
}
