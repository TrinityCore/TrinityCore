#include "bot_ai.h"
#include "botdatamgr.h"
#include "botmgr.h"
#include "botlog.h"
#include "Creature.h"
#include "DatabaseEnvFwd.h"
#include "Log.h"

template<typename... Args>
static void BotLogImpl(uint16 log_type, uint32 entry, int32 owner, int32 mapid, int8 inmap, int8 inworld, Args&&... params)
{
    std::vector<std::string> sparams;
    sparams.reserve(MAX_BOT_LOG_PARAMS);
    using compounder = int[];
    (void)compounder { 0, ((void)sparams.push_back(NPCBots::StringConvert::ToString(params)), 0) ... };
    sparams.resize(MAX_BOT_LOG_PARAMS, {});
    for (uint8 i = 0; i < MAX_BOT_LOG_PARAMS; ++i)
    {
        if (sparams[i].size() > MAX_BOT_LOG_PARAM_LENGTH)
        {
            TC_LOG_DEBUG("npcbots", "Bot logger: while writing type {} entry {} owner {} param {} '{}' was truncated to {} symbols!",
                log_type, entry, owner, uint32(i+1), sparams[i], MAX_BOT_LOG_PARAM_LENGTH);
            sparams[i] = sparams[i].substr(0, MAX_BOT_LOG_PARAM_LENGTH);
        }
    }

    CharacterDatabasePreparedStatement* bstmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_NPCBOT_LOG);
    //"INSERT INTO characters_npcbot_logs (entry, owner, mapid, inmap, inworld, type, param1, param2, param3, param4, param5) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC
    uint32 index = 0;
    bstmt->setUInt32(  index, entry);
    bstmt->setInt32 (++index, owner);
    bstmt->setInt32 (++index, mapid);
    bstmt->setInt8  (++index, inmap);
    bstmt->setInt8  (++index, inworld);
    bstmt->setUInt16(++index, log_type);
    for (std::string const& param : sparams)
        bstmt->setString(++index, param);
    CharacterDatabase.Execute(bstmt);
}

template<typename... Args>
inline static void BotLogImpl(uint16 log_type, Creature const* bot, int32 owner, Args&&... params)
{
    BotLogImpl(log_type, bot->GetEntry(), owner, (int32)bot->GetMapId(), (int8)!!bot->FindMap(), (int8)bot->IsInWorld(), std::forward<Args>(params)...);
}

template<typename... Args>
requires NPCBots::LoggableArguments<Args...>
void BotLogger::Log(uint16 log_type, Creature const* bot, Args&&... params)
{
    if (!BotMgr::IsNpcBotLogEnabled())
        return;

    BotLogImpl(log_type, bot, int32(bot->GetBotAI() ? bot->GetBotAI()->GetBotOwnerGuid() : -1), std::forward<Args>(params)...);
}

template<typename... Args>
requires NPCBots::LoggableArguments<Args...>
void BotLogger::Log(uint16 log_type, uint32 entry, Args&&... params)
{
    if (!BotMgr::IsNpcBotLogEnabled())
        return;

    if (Creature const* bot = entry ? BotDataMgr::FindBot(entry) : nullptr)
        BotLogger::Log(log_type, bot, std::forward<Args>(params)...);
    else
    {
        if (entry)
        {
            std::stringstream ss;
            using compounder = int[];
            (void)compounder { 0, ((void)(ss << ' ' << params), 0) ... };
            TC_LOG_DEBUG("npcbots", "Logging unregistered bot entry {}: type {} params:{}", entry, log_type, ss.str());
        }
        BotLogImpl(log_type, entry, -1, -1, -1, -1, std::forward<Args>(params)...);
    }
}

template void BotLogger::Log(uint16, Creature const*);
template void BotLogger::Log(uint16, Creature const*, bool&&, bool&&, bool&&);
template void BotLogger::Log(uint16, Creature const*, bool&&, bool&&, bool&&, uint32&&, bool&&);
template void BotLogger::Log(uint16, Creature const*, uint32&&, uint32&&, uint32&&);
template void BotLogger::Log(uint16, Creature const*, uint32&&, uint32&&, uint32&&, uint32&&);
template void BotLogger::Log(uint16, Creature const*, uint32&&, uint32&&, uint32&&, uint32&&, uint32&&);
template void BotLogger::Log(uint16, uint32);
template void BotLogger::Log(uint16, uint32, std::string_view&&);
template void BotLogger::Log(uint16, uint32, std::string&, std::string&, std::string&, std::string&, std::string&);
