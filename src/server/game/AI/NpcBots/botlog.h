#ifndef BOTLOG_H_
#define BOTLOG_H_

#include "Define.h"

#include "botlogtraits.h"

class Creature;

constexpr uint32 BOT_LOG_KEEP_DAYS = 30;

enum BotLogType : uint16
{
    NPCBOT_LOG_SPAWN                    = 1,
    NPCBOT_LOG_TELEPORT_START           = 2,
    NPCBOT_LOG_TELEPORT_FINISH          = 3,
    NPCBOT_LOG_INIT_EQUIP               = 4,
    NPCBOT_LOG_EQUIP                    = 5,
    NPCBOT_LOG_UNEQUIP                  = 6,
    NPCBOT_LOG_EQUIP_RESET              = 7,

    NPCBOT_LOG_SYSTEM_START             = 100,
    NPCBOT_LOG_CONFIG_RELOAD            = 101,

    NPCBOT_LOG_END
};

class BotLogger
{
    public:
        template<typename... Args>
        requires NPCBots::LoggableArguments<Args...>
        static void Log(uint16 log_type, Creature const* bot, Args&&... params);
        template<typename... Args>
        requires NPCBots::LoggableArguments<Args...>
        static void Log(uint16 log_type, uint32 entry, Args&&... params);
};

#endif //BOTLOG_H_
