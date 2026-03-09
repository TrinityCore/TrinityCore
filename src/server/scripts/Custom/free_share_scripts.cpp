/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Chat.h"
#include "ChatCommandTags.h"
#include "ChatCommand.h"
#include "DB2Stores.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "MiscPackets.h"
#include "MovementGenerator.h"
#include "ScriptMgr.h"
#include "WorldSession.h"
#include "RBAC.h"
#include "MotionMaster.h"
#include "Map.h"
#include "World.h"
#include "WorldPacket.h"
#include "GameTime.h"
#include "RoleplayDatabase.h"

class StaticTimeManager
{
private:
    static inline uint32 m_staticHour = 12;
    static inline uint32 m_staticMinute = 0;
    static inline uint32 m_staticYear = 1900;
    static inline uint32 m_staticMonth = 1;
    static inline uint32 m_staticMonthDay = 1;

    static inline bool m_timeFreezed = false;
    static inline bool m_timeTransitioning = false;

    static inline uint32 m_targetHour = 12;
    static inline uint32 m_targetMinute = 0;

    static inline uint32 m_transitionStepMs = 1000;
    static inline uint32 m_transitionTimer = 0;

public:

    static void SaveStaticTimeToDB()
    {
        using namespace std::string_view_literals;

        RoleplayDatabasePreparedStatement* stmt = RoleplayDatabase.GetPreparedStatement(Roleplay_DEL_SERVER_SETTINGS);
        RoleplayDatabase.Execute(stmt);

        stmt = RoleplayDatabase.GetPreparedStatement(Roleplay_REP_SERVER_SETTINGS);
        stmt->setString(0, "static_hour"sv);
        stmt->setString(1, std::to_string(m_staticHour));
        RoleplayDatabase.Execute(stmt);

        stmt = RoleplayDatabase.GetPreparedStatement(Roleplay_REP_SERVER_SETTINGS);
        stmt->setString(0, "static_minute"sv);
        stmt->setString(1, std::to_string(m_staticMinute));
        RoleplayDatabase.Execute(stmt);

        stmt = RoleplayDatabase.GetPreparedStatement(Roleplay_REP_SERVER_SETTINGS);
        stmt->setString(0, "time_freezed"sv);
        stmt->setString(1, std::to_string(m_timeFreezed ? 1 : 0));
        RoleplayDatabase.Execute(stmt);
    }

    static void LoadStaticTimeFromDB()
    {
        RoleplayDatabasePreparedStatement* stmt = RoleplayDatabase.GetPreparedStatement(Roleplay_SEL_SERVER_SETTINGS);
        PreparedQueryResult result = RoleplayDatabase.Query(stmt);

        if (!result)
        {
            ResetToServerTime();
            return;
        }

        bool hourSet = false, minuteSet = false, freezeSet = false;

        do
        {
            Field* fields = result->Fetch();
            std::string settingName = fields[0].GetString();
            std::string settingValue = fields[1].GetString();

            if (settingName == "static_hour")
            {
                m_staticHour = std::stoi(settingValue);
                hourSet = true;
            }
            else if (settingName == "static_minute")
            {
                m_staticMinute = std::stoi(settingValue);
                minuteSet = true;
            }
            else if (settingName == "time_freezed")
            {
                m_timeFreezed = (settingValue == "1");
                freezeSet = true;
            }

        } while (result->NextRow());

        if (!hourSet || !minuteSet || !freezeSet)
        {
            ResetToServerTime();
        }

        SendTimeSync();
    }

    static bool IsTimeFreezed()
    {
        return m_timeFreezed && !m_timeTransitioning;
    }

    static void SetStaticTimeSmooth(uint32 targetHour, uint32 targetMinute, uint32 stepMs = 1000)
    {
        if (targetHour > 23 || targetMinute > 59)
            return;

        m_targetHour = targetHour;
        m_targetMinute = targetMinute;
        m_transitionStepMs = stepMs;
        m_transitionTimer = 0;
        m_timeTransitioning = true;
        m_timeFreezed = false;

    }

    static void SetStaticTime(uint32 hour, uint32 minute, bool freeze = false)
    {
        m_staticHour = hour;
        m_staticMinute = minute;
        m_timeFreezed = freeze;
        m_timeTransitioning = false;

        SaveStaticTimeToDB();
        SendTimeSync();
    }

    static void ResetToServerTime()
    {
        time_t now = time(nullptr);
        struct tm* localTime = localtime(&now);

        m_staticHour = localTime->tm_hour;
        m_staticMinute = localTime->tm_min;
        m_timeFreezed = false;
        m_timeTransitioning = false;

        RoleplayDatabasePreparedStatement* stmt = RoleplayDatabase.GetPreparedStatement(Roleplay_DEL_SERVER_SETTINGS);
        RoleplayDatabase.Execute(stmt);

        SendTimeSync();
    }

    static void UnfreezeTime()
    {
        m_timeFreezed = false;
        m_timeTransitioning = false;

        SaveStaticTimeToDB();
        SendTimeSync();
    }

    static void SendTimeSync()
    {
        WowTime custom;
        WorldPackets::Misc::LoginSetTimeSpeed timePacket;

        time_t nowYM = time(nullptr);
        struct tm* localTimeYM = localtime(&nowYM);

        m_staticYear = (localTimeYM->tm_year + 1900) % 100;
        m_staticMonth = localTimeYM->tm_mon;
        m_staticMonthDay = localTimeYM->tm_mday;

        custom.SetHour(m_staticHour);
        custom.SetMinute(m_staticMinute);
        custom.SetYear(m_staticYear);
        custom.SetMonth(m_staticMonth);
        custom.SetMonthDay(m_staticMonthDay);
        timePacket.GameTime = custom;
        timePacket.ServerTime = custom;

        // Normal game time speed (1 minute game time = ~1 second real time)
        static float const NormalTimeSpeed = 0.01666667f;
        // Frozen time speed - stops sun/moon visual movement
        static float const FrozenTimeSpeed = 0.0f;

        // When time is frozen, set speed to 0 to stop visual time progression
        // This stops sun/moon movement but doesn't affect game mechanics
        // (mechanics use GameTime::GetGameTime() which is independent)
        timePacket.NewSpeed = m_timeFreezed ? FrozenTimeSpeed : NormalTimeSpeed;

        sWorld->SendGlobalMessage(timePacket.Write());
    }

    static void Update(uint32 diff)
    {
        if (!m_timeTransitioning)
            return;

        m_transitionTimer += diff;

        if (m_transitionTimer >= m_transitionStepMs)
        {
            m_transitionTimer = 0;

            m_staticMinute++;
            if (m_staticMinute >= 60)
            {
                m_staticMinute = 0;
                m_staticHour++;
                if (m_staticHour >= 24)
                    m_staticHour = 0;
            }

            if (m_staticHour == m_targetHour && m_staticMinute == m_targetMinute)
            {
                m_timeTransitioning = false;
                m_timeFreezed = true;
                SaveStaticTimeToDB();
            }

            SendTimeSync();
        }
    }
};

class free_share_scripts : public CommandScript
{
public:
    free_share_scripts() : CommandScript("free_share_scripts") {}

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> typimgCommandTable =
        {
            { "on",              rbac::RBAC_PERM_COMMAND_TYPING_ON,     false,      &HandleTipingOnCommand,     ""},
            { "off",             rbac::RBAC_PERM_COMMAND_TYPING_OFF,    false,      &HandleTipingOffCommand,    ""},
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "barbershop",      rbac::RBAC_PERM_COMMAND_BARBER,        false,      &HandleBarberCommand,       ""},
            { "castgroup",       rbac::RBAC_PERM_COMMAND_CAST_GROUP,    false,      &HandleCastGroupCommand,    ""},
            { "castgroupscene",  rbac::RBAC_PERM_COMMAND_CAST_SCENE,    false,      &HandleCastSceneCommand,    ""},
            { "npcmoveto",       rbac::RBAC_PERM_COMMAND_NPC_MOVE,      false,      &HandleNpcMoveTo,           ""},
            { "npcguidsay",      rbac::RBAC_PERM_COMMAND_NPC_SAY,       false,      &HandleNpcGuidSay,          ""},
            { "npcguidyell",     rbac::RBAC_PERM_COMMAND_NPC_YELL,      false,      &HandleNpcGuidYell,         ""},
            { "settime",         rbac::RBAC_PERM_COMMAND_NPC_YELL,      false,      &HandleSetTimeCommand,      "<hour> <minute> [instant|smooth|unfreeze] <ms shift>"},
            { "typing",          typimgCommandTable },
        };

        return commandTable;
    }

    // custom command .typing on
    static bool HandleTipingOnCommand(ChatHandler* handler)
    {
        Player* plr = handler->GetSession()->GetPlayer();

        if (!plr)
            return false;

        plr->CastSpell(plr, 156354, false);

        return true;
    }

    // custom command .typing off
    static bool HandleTipingOffCommand(ChatHandler* handler)
    {
        Player* plr = handler->GetSession()->GetPlayer();

        if (!plr)
            return false;

        if (plr->HasAura(156354))
            plr->RemoveAura(156354);

        return true;
    }

    // custom command .barber
    static bool HandleBarberCommand(ChatHandler* handler)
    {
        WorldPackets::Misc::EnableBarberShop packet;
        handler->GetSession()->GetPlayer()->SendDirectMessage(packet.Write());

        return true;
    }

    // custom command .castgroup
    static bool HandleCastGroupCommand(ChatHandler* handler, SpellInfo const* spellInfo)
    {
        uint32 spellId = spellInfo->Id;

        if (!spellId)
            return false;

        if (!handler->GetSession()->GetPlayer()->GetGroup())
            return false;

        for (GroupReference const& itr : handler->GetSession()->GetPlayer()->GetGroup()->GetMembers())
        {
            Player* plr = itr.GetSource();
            if (!plr || !plr->GetSession())
                continue;

            plr->CastSpell(plr, spellId, false);
        }

        return true;
    }

    // custom command .castscene
    static bool HandleCastSceneCommand(ChatHandler* handler, char const* args)
    {

        if (!*args)
            return false;

        char const* scenePackageIdStr = strtok((char*)args, " ");
        char const* flagsStr = strtok(NULL, "");

        if (!scenePackageIdStr)
            return false;

        uint32 scenePackageId = atoi(scenePackageIdStr);
        uint32 flags = flagsStr ? atoi(flagsStr) : 0;

        if (!handler->GetSession()->GetPlayer()->GetGroup())
            return false;

        for (GroupReference const& itr : handler->GetSession()->GetPlayer()->GetGroup()->GetMembers())
        {
            Player* plr = itr.GetSource();
            if (!plr || !plr->GetSession())
                continue;

            if (!sSceneScriptPackageStore.HasRecord(scenePackageId))
                return false;

            plr->GetSceneMgr().PlaySceneByPackageId(scenePackageId, SceneFlag(flags));
        }

        return true;
    }

    // custom command .npcmoveto
    static bool HandleNpcMoveTo(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        char* guid = strtok((char*)args, " ");

        if (!guid)
            return false;

        char* x = strtok(nullptr, " ");
        char* y = strtok(nullptr, " ");
        char* z = strtok(nullptr, " ");

        if (!x || !y || !z)
            return false;

        float x2, y2, z2;
        x2 = (float)atof(x);
        y2 = (float)atof(y);
        z2 = (float)atof(z);

        Creature* creature = nullptr;

        char* cId = handler->extractKeyFromLink((char*)guid, "Hcreature");

        ObjectGuid::LowType lowguid = Trinity::StringTo<ObjectGuid::LowType>(cId).value_or(UI64LIT(0));

        creature = handler->GetCreatureFromPlayerMapByDbGuid(lowguid);

        if (!creature)
        {
            return false;
        }

        uint32 MapIdPlayer = player->GetMapId();

        uint32 MapIdCreature = creature->GetMapId();

        if (MapIdPlayer != MapIdCreature)
        {
            return false;
        }
        else
        {
            creature->GetMotionMaster()->MovePoint(0, x2, y2, z2);
        }

        return true;
    }

    // custom command .npcguidsay
    static bool HandleNpcGuidSay(ChatHandler* handler, char const* args)
    {

        char* guid = strtok((char*)args, " ");

        if (!guid)
            return false;

        char* say = strtok(nullptr, "");

        if (!say)
            return false;

        Creature* creature = nullptr;

        char* cId = handler->extractKeyFromLink((char*)guid, "Hcreature");

        ObjectGuid::LowType lowguid = Trinity::StringTo<ObjectGuid::LowType>(cId).value_or(UI64LIT(0));

        creature = handler->GetCreatureFromPlayerMapByDbGuid(lowguid);

        if (!creature)
        {
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        uint32 MapIdPlayer = player->GetMapId();
        uint32 MapIdCreature = creature->GetMapId();

        if (MapIdPlayer != MapIdCreature)
        {
            return false;
        }
        else
        {
            creature->Say(say, LANG_UNIVERSAL);

            char lastchar = args[strlen(args) - 1];
            switch (lastchar)
            {
            case '?':   creature->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);      break;
            case '!':   creature->HandleEmoteCommand(EMOTE_ONESHOT_EXCLAMATION);   break;
            default:    creature->HandleEmoteCommand(EMOTE_ONESHOT_TALK);          break;
            }
        }

        return true;
    }

    // custom command .npcguidyell
    static bool HandleNpcGuidYell(ChatHandler* handler, char const* args)
    {
        char* guid = strtok((char*)args, " ");

        if (!guid)
            return false;

        char* yell = strtok(nullptr, "");

        if (!yell)
            return false;

        Creature* creature = nullptr;

        char* cId = handler->extractKeyFromLink((char*)guid, "Hcreature");

        ObjectGuid::LowType lowguid = Trinity::StringTo<ObjectGuid::LowType>(cId).value_or(UI64LIT(0));

        creature = handler->GetCreatureFromPlayerMapByDbGuid(lowguid);

        if (!creature)
        {
            return false;
        }

        Player* player = handler->GetSession()->GetPlayer();
        uint32 MapIdPlayer = player->GetMapId();
        uint32 MapIdCreature = creature->GetMapId();

        if (MapIdPlayer != MapIdCreature)
        {
            return false;
        }
        else
        {
            creature->Yell(yell, LANG_UNIVERSAL);

            creature->HandleEmoteCommand(EMOTE_ONESHOT_SHOUT);
        }

        return true;
    }

    // custom command .settime
    static bool HandleSetTimeCommand(ChatHandler* handler, Optional<uint32> hour, Optional<uint32> minute, Optional<std::string> mode, Optional<uint32> speedMs)
    {
        std::string modeStr = mode ? *mode : "instant";

        // .settime 999 - reset to server time (unfreeze)
        if (hour && *hour == 999)
        {
            StaticTimeManager::ResetToServerTime();
            handler->PSendSysMessage("Time reset to server time (unfrozen).");
            return true;
        }

        // .settime unfreeze - just unfreeze without changing time
        // This works even without hour/minute parameters
        if (modeStr == "unfreeze")
        {
            StaticTimeManager::UnfreezeTime();
            handler->PSendSysMessage("Time unfrozen - now follows server time.");
            return true;
        }

        uint32 setHour = hour && *hour >= 0 ? *hour : 15;
        uint32 setMinute = minute && *minute >= 0 ? *minute : 30;

        if (setHour > 23 || setMinute > 59)
        {
            handler->SendSysMessage("Incorrect time. Use hours 0-23, minutes 0-59.");
            return false;
        }

        if (modeStr == "smooth")
        {
            uint32 stepMs = speedMs ? *speedMs : 1000;
            StaticTimeManager::SetStaticTimeSmooth(setHour, setMinute, stepMs);
            handler->PSendSysMessage("Smooth time transition started to %02u:%02u.", setHour, setMinute);
        }
        else
        {
            StaticTimeManager::SetStaticTime(setHour, setMinute, true);
            handler->PSendSysMessage("Server time is set to %02u:%02u (frozen).", setHour, setMinute);
        }

        return true;
    }
};

class PlayerScript_TimeSync : public PlayerScript
{
public:
    PlayerScript_TimeSync() : PlayerScript("PlayerScript_TimeSync") {}

    void OnLogin(Player* /*player*/, bool /*firstLogin*/) override
    {
        StaticTimeManager::LoadStaticTimeFromDB();
    }
};

class WorldScript_TimeSync : public WorldScript
{
public:
    WorldScript_TimeSync() : WorldScript("WorldScript_TimeSync") {}

    void OnUpdate(uint32 diff) override
    {
        StaticTimeManager::Update(diff);

        // Only send periodic sync when time is NOT frozen
        // When frozen (speed = 0), client time stays fixed and doesn't drift
        // so we don't need to constantly resync
        if (!StaticTimeManager::IsTimeFreezed())
        {
            static uint32 timeCheckTimer = 0;
            timeCheckTimer += diff;

            if (timeCheckTimer >= 30 * IN_MILLISECONDS)
            {
                StaticTimeManager::SendTimeSync();
                timeCheckTimer = 0;
            }
        }
    }
};

void AddSC_free_share_scripts()
{
    new free_share_scripts();
    new PlayerScript_TimeSync();
    new WorldScript_TimeSync();
}
