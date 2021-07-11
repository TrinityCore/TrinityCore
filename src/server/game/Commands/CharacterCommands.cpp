/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "Database/DatabaseEnv.h"
#include "Database/DatabaseImpl.h"
#include "World.h"
#include "Player.h"
#include "PlayerAI.h"
#include "Group.h"
#include "Bag.h"
#include "Opcodes.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "Language.h"
#include "AccountMgr.h"
#include "ObjectMgr.h"
#include "SystemConfig.h"
#include "Util.h"
#include "AsyncCommandHandlers.h"
#include "WaypointMovementGenerator.h"
#include "PlayerDump.h"
#include "CharacterDatabaseCache.h"
#include "Config/Config.h"

#include <regex>

bool ChatHandler::HandleCharacterAIInfoCommand(char* /*args*/)
{
    Player* pTarget = GetSelectedPlayer();

    if (!pTarget)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage("AI info for %s", pTarget->GetObjectGuid().GetString().c_str());
    char const* cstrAIClass = pTarget->AI() ? typeid(*pTarget->AI()).name() : " - ";
    PSendSysMessage("Current AI: %s", cstrAIClass);
    MovementGeneratorType moveType = pTarget->GetMotionMaster()->GetCurrentMovementGeneratorType();
    PSendSysMessage(LANG_NPC_MOTION_TYPE, MotionMaster::GetMovementGeneratorTypeName(moveType), moveType);

    return true;
}

bool ChatHandler::HandleModifyXpRateCommand(char* args)
{
    // Only a GM can modify another player's rates.
    Player* pPlayer = (m_session->GetSecurity() < SEC_GAMEMASTER) ? m_session->GetPlayer() : GetSelectedPlayer();

    if (!pPlayer)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    float xp;
    if (!ExtractFloat(&args, xp))
        return false;

    if (xp < sWorld.getConfig(CONFIG_FLOAT_RATE_XP_PERSONAL_MIN))
    {
        PSendSysMessage(LANG_XP_RATE_MIN, sWorld.getConfig(CONFIG_FLOAT_RATE_XP_PERSONAL_MIN));
        return false;
    }

    if ((xp > sWorld.getConfig(CONFIG_FLOAT_RATE_XP_PERSONAL_MAX)) && (m_session->GetSecurity() < SEC_GAMEMASTER))
    {
        PSendSysMessage(LANG_XP_RATE_MAX, sWorld.getConfig(CONFIG_FLOAT_RATE_XP_PERSONAL_MAX));
        return false;
    }

    pPlayer->SetPersonalXpRate(xp);
    PSendSysMessage(LANG_XP_RATE_SET, (pPlayer != m_session->GetPlayer() ? (std::string(pPlayer->GetName()) + std::string("'s")).c_str() : "your"), xp);
    return true;
}

bool ChatHandler::HandleCheatGodCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }
        
        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatGod(value, true);

        PSendSysMessage(LANG_YOU_SET_GOD, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_GOD_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatCooldownCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatNoCooldown(value, true);

        PSendSysMessage(LANG_YOU_SET_NO_CD, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_NO_CD_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatCastTimeCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatInstantCast(value, true);

        PSendSysMessage(LANG_YOU_SET_INSTANT_CAST, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_INSTANT_CAST_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatPowerCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatNoPowerCost(value, true);

        PSendSysMessage(LANG_YOU_SET_NO_POWER_COST, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_NO_POWER_COST_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatDebuffImmunityCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatDebuffImmunity(value, true);

        PSendSysMessage(LANG_YOU_SET_DEBUFF_IMMUNITY, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_DEBUFF_IMMUNITY_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatAlwaysCritCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatAlwaysCrit(value, true);

        PSendSysMessage(LANG_YOU_SET_ALWAYS_CRIT, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_ALWAYS_CRIT_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatNoCastCheckCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatNoCastCheck(value, true);

        PSendSysMessage(LANG_YOU_SET_NO_CAST_CHECK, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_NO_CAST_CHECK_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatAlwaysProcCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatAlwaysProc(value, true);

        PSendSysMessage(LANG_YOU_SET_ALWAYS_PROC, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_ALWAYS_PROC_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatTriggerPassCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatTriggerPass(value, true);

        PSendSysMessage(LANG_YOU_SET_TRIGGER_PASS, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_TRIGGER_PASS_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatIgnoreTriggersCommand(char* args)
{
    if (*args)
    {
        bool value;
        if (!ExtractOnOff(&args, value))
        {
            SendSysMessage(LANG_USE_BOL);
            SetSentErrorMessage(true);
            return false;
        }

        Player* target;
        if (!ExtractPlayerTarget(&args, &target))
            return false;

        target->SetCheatIgnoreTriggers(value, true);

        PSendSysMessage(LANG_YOU_SET_IGNORE_TRIGGERS, value ? "on" : "off", GetNameLink(target).c_str());
        if (needReportToTarget(target))
            ChatHandler(target).PSendSysMessage(LANG_YOUR_IGNORE_TRIGGERS_SET, value ? "on" : "off", GetNameLink().c_str());
    }

    return true;
}

bool ChatHandler::HandleCheatWaterwalkCommand(char* args)
{
    bool value;
    if (!ExtractOnOff(&args, value))
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(player))
        return false;

    if (value)
        player->SetWaterWalking(true);
    else
        player->SetWaterWalking(false);

    PSendSysMessage(LANG_YOU_SET_WATERWALK, value ? "on" : "off", GetNameLink(player).c_str());
    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOUR_WATERWALK_SET, value ? "on" : "off", GetNameLink().c_str());
    return true;
}

bool ChatHandler::HandleCheatWallclimbCommand(char* args)
{
    bool value;
    if (!ExtractOnOff(&args, value))
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(player))
        return false;

    if (value)
        player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_0);
    else
        player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_0);

    PSendSysMessage(LANG_YOU_SET_WALLCLIMB, value ? "on" : "off", GetNameLink(player).c_str());
    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOUR_WALLCLIMB_SET, value ? "on" : "off", GetNameLink().c_str());
    return true;
}

bool ChatHandler::HandleCheatStatusCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;
    
    if (!target->GetCheatOptions())
    {
        PSendSysMessage("No cheats enabled on %s.", target->GetName());
        return true;
    }

    PSendSysMessage("Cheats active on %s:", target->GetName());
    if (target->HasCheatOption(PLAYER_CHEAT_GOD))
        SendSysMessage("- God");
    if (target->HasCheatOption(PLAYER_CHEAT_NO_COOLDOWN))
        SendSysMessage("- No cooldowns");
    if (target->HasCheatOption(PLAYER_CHEAT_NO_CAST_TIME))
        SendSysMessage("- No cast time");
    if (target->HasCheatOption(PLAYER_CHEAT_NO_POWER))
        SendSysMessage("- No power costs");
    if (target->HasCheatOption(PLAYER_CHEAT_DEBUFF_IMMUNITY))
        SendSysMessage("- Debuff immunity");
    if (target->HasCheatOption(PLAYER_CHEAT_ALWAYS_CRIT))
        SendSysMessage("- Always crit");
    if (target->HasCheatOption(PLAYER_CHEAT_NO_CHECK_CAST))
        SendSysMessage("- No cast checks");
    if (target->HasCheatOption(PLAYER_CHEAT_ALWAYS_PROC))
        SendSysMessage("- Always proc");
    if (target->HasCheatOption(PLAYER_CHEAT_TRIGGER_PASS))
        SendSysMessage("- Areatrigger pass");
    if (target->HasCheatOption(PLAYER_CHEAT_IGNORE_TRIGGERS))
        SendSysMessage("- Ignore areatriggers");
    if (target->HasMovementFlag(MOVEFLAG_WATERWALKING) && !target->HasAuraType(SPELL_AURA_WATER_WALK))
        SendSysMessage("- Water walking");
    if (target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_0))
        SendSysMessage("- Wall climbing");

    return true;
}

bool ChatHandler::HandleReviveCommand(char* args)
{
    Player* target;
    ObjectGuid target_guid;
    if (!ExtractPlayerTarget(&args, &target, &target_guid))
        return false;

    if (target)
    {
        target->ResurrectPlayer(0.5f);
        target->SpawnCorpseBones();
        PSendSysMessage(LANG_CHARACTER_REVIVED_ONLINE, playerLink(target->GetName()).c_str());
    }
    else
    {
        // will resurrected at login without corpse
        sObjectAccessor.ConvertCorpseForPlayer(target_guid);
        std::string playername;
        sObjectMgr.GetPlayerNameByGUID(target_guid, playername);
        PSendSysMessage(LANG_CHARACTER_REVIVED_OFFLINE, playerLink(playername).c_str());
    }

    return true;
}

bool ChatHandler::HandleExploreCheatCommand(char* args)
{
    if (!*args)
        return false;

    int flag = atoi(args);

    Player* chr = GetSelectedPlayer();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    if (flag != 0)
    {
        PSendSysMessage(LANG_YOU_SET_EXPLORE_ALL, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_EXPLORE_SET_ALL, GetNameLink().c_str());
    }
    else
    {
        PSendSysMessage(LANG_YOU_SET_EXPLORE_NOTHING, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_EXPLORE_SET_NOTHING, GetNameLink().c_str());
    }

    for (uint8 i = 0; i < PLAYER_EXPLORED_ZONES_SIZE; ++i)
    {
        if (flag != 0)
            m_session->GetPlayer()->SetFlag(PLAYER_EXPLORED_ZONES_1 + i, 0xFFFFFFFF);
        else
            m_session->GetPlayer()->SetFlag(PLAYER_EXPLORED_ZONES_1 + i, 0);
    }

    return true;
}

bool ChatHandler::HandleHoverCommand(char* args)
{
    uint32 flag;
    if (!ExtractOptUInt32(&args, flag, 1))
        return false;

    m_session->GetPlayer()->SetHover(flag);

    if (flag)
        SendSysMessage(LANG_HOVER_ENABLED);
    else
        SendSysMessage(LANG_HOVER_DISABLED);

    return true;
}

bool ChatHandler::HandleLevelUpCommand(char* args)
{
    int32 addlevel = 1;
    char* nameStr = nullptr;

    if (*args)
    {
        nameStr = ExtractOptNotLastArg(&args);

        // exception opt second arg: .levelup $name
        if (!ExtractInt32(&args, addlevel))
        {
            if (!nameStr)
                nameStr = ExtractArg(&args);
            else
                return false;
        }
    }

    if (Creature* pCreature = GetSelectedCreature())
    {
        int32 newlevel = pCreature->GetLevel() + addlevel;

        if (newlevel < 1)
            newlevel = 1;

        if (newlevel > PLAYER_STRONG_MAX_LEVEL)
            newlevel = PLAYER_STRONG_MAX_LEVEL;

        if (pCreature->IsPet())
            ((Pet*)pCreature)->GivePetLevel(newlevel);
        else
            pCreature->SetLevel(newlevel);

        PSendSysMessage(LANG_YOU_CHANGE_LVL, pCreature->GetName(), newlevel);
    }
    else
    {
        Player* target;
        ObjectGuid target_guid;
        std::string target_name;
        if (!ExtractPlayerTarget(&nameStr, &target, &target_guid, &target_name))
            return false;

        int32 oldlevel = target ? target->GetLevel() : Player::GetLevelFromDB(target_guid);
        int32 newlevel = oldlevel + addlevel;

        if (newlevel < 1)
            newlevel = 1;

        if (newlevel > PLAYER_STRONG_MAX_LEVEL)                        // hardcoded maximum level
            newlevel = PLAYER_STRONG_MAX_LEVEL;

        HandleCharacterLevel(target, target_guid, oldlevel, newlevel);

        if (!m_session || m_session->GetPlayer() != target)     // including chr==nullptr
        {
            std::string nameLink = playerLink(target_name);
            PSendSysMessage(LANG_YOU_CHANGE_LVL, nameLink.c_str(), newlevel);
        }
    }

    return true;
}

bool ChatHandler::HandleShowAreaCommand(char* args)
{
    if (!*args)
        return false;

    Player* chr = GetSelectedPlayer();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    int area = AreaEntry::GetFlagById(atoi(args));
    int offset = area / 32;
    uint32 val = (uint32)(1 << (area % 32));

    if (area < 0 || offset >= PLAYER_EXPLORED_ZONES_SIZE)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 currFields = chr->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);
    chr->SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, (uint32)(currFields | val));

    SendSysMessage(LANG_EXPLORE_AREA);
    return true;
}

bool ChatHandler::HandleHideAreaCommand(char* args)
{
    if (!*args)
        return false;

    Player* chr = GetSelectedPlayer();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    int area = AreaEntry::GetFlagById(atoi(args));
    int offset = area / 32;
    uint32 val = (uint32)(1 << (area % 32));

    if (area < 0 || offset >= PLAYER_EXPLORED_ZONES_SIZE)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 currFields = chr->GetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset);
    chr->SetUInt32Value(PLAYER_EXPLORED_ZONES_1 + offset, (uint32)(currFields ^ val));

    SendSysMessage(LANG_UNEXPLORE_AREA);
    return true;
}

bool ChatHandler::HandleMaxSkillCommand(char* /*args*/)
{
    Player* SelectedPlayer = GetSelectedPlayer();
    if (!SelectedPlayer)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // each skills that have max skill value dependent from level seted to current level max skill value
    SelectedPlayer->UpdateSkillsToMaxSkillsForLevel();
    return true;
}

bool ChatHandler::HandleSetSkillCommand(char* args)
{
    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hskill:skill_id|h[name]|h|r
    char* skill_p = ExtractKeyFromLink(&args, "Hskill");
    if (!skill_p)
        return false;

    int32 skill;
    if (!ExtractInt32(&skill_p, skill))
        return false;

    int32 level;
    if (!ExtractInt32(&args, level))
        return false;

    int32 maxskill;
    if (!ExtractOptInt32(&args, maxskill, target->GetSkillMaxPure(skill)))
        return false;

    if (skill <= 0)
    {
        PSendSysMessage(LANG_INVALID_SKILL_ID, skill);
        SetSentErrorMessage(true);
        return false;
    }

    SkillLineEntry const* sl = sSkillLineStore.LookupEntry(skill);
    if (!sl)
    {
        PSendSysMessage(LANG_INVALID_SKILL_ID, skill);
        SetSentErrorMessage(true);
        return false;
    }

    std::string tNameLink = GetNameLink(target);

    if (!target->GetSkillValue(skill))
    {
        PSendSysMessage(LANG_SET_SKILL_ERROR, tNameLink.c_str(), skill, sl->name[GetSessionDbcLocale()]);
        SetSentErrorMessage(true);
        return false;
    }

    if (level <= 0 || level > maxskill || maxskill <= 0)
        return false;

    target->SetSkill(skill, level, maxskill);
    PSendSysMessage(LANG_SET_SKILL, skill, sl->name[GetSessionDbcLocale()], tNameLink.c_str(), level, maxskill);

    return true;
}

bool ChatHandler::HandleRemoveRidingCommand(char* args)
{
    static std::unordered_map<std::string, uint32> const skills
    {
        { "75", 33388 }, { "150", 33391 }, { "apprentice", 33388 }, { "journeyman", 33391 },
        { "horse", 824 }, { "kodo", 18995 }, { "ram", 826 }, { "raptor", 10861 },
        { "tiger", 828 }, { "wolf", 825 }
    };

    Player* player;
    ObjectGuid target_guid;
    std::string name;

    ExtractPlayerTarget(&args, &player, &target_guid, &name);

    if (!player && name.empty())
    {
        SetSentErrorMessage(true);
        return false;
    }

    auto it = skills.find(args);
    
    if (it == skills.end())
    {
        std::stringstream options;

        for (auto& entry : skills)
        {
            options << entry.first << " ";
        }

        PSendSysMessage(LANG_REMOVE_RIDING_WRONG_TYPE, options.str().c_str());
        SetSentErrorMessage(true);
        return false;
    }

    if (player)
    {
        player->RemoveSpell(it->second, false, false);
        player->SaveToDB(); // make sure we don't lose this change if the world crashes
    }
    else
    {
        QueryResult* result = nullptr;
        if (it->second == 33388) // When removing Apprentice Riding check for Journeyman too. It replaces the first spell.
            result = CharacterDatabase.PQuery("SELECT `spell` FROM `character_spell` WHERE `guid` = %u AND `spell` IN (33388, 33391)", target_guid.GetCounter());
        else
            result = CharacterDatabase.PQuery("SELECT `spell` FROM `character_spell` WHERE `guid` = %u AND `spell` = %u", target_guid.GetCounter(), it->second);

        if (!result)
        {
            PSendSysMessage(LANG_REMOVE_RIDING_NOT_HAVE, it->first.c_str());
            SetSentErrorMessage(true);
            return false;
        }

        // remove the riding skill
        switch (it->second)
        {
            // Horse Riding
            case 824:
            {
                if (!CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `skill` = 148 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
            // Wolf Riding
            case 825:
            {
                if (!CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `skill` = 149 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
            // Ram Riding
            case 826:
            {
                if (!CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `skill` = 152 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
            // Tiger Riding
            case 828:
            {
                if (!CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `skill` = 150 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
            // Raptor Riding
            case 10861:
            {
                if (!CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `skill` = 533 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
            // Kodo Riding
            case 18995:
            {
                if (!CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `skill` = 713 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
            // Apprentice Riding
            case 33388:
            {
                if (!CharacterDatabase.PExecute("DELETE FROM `character_skills` WHERE `skill` = 762 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
            // Journeyman Riding
            case 33391:
            {
                if (!CharacterDatabase.PExecute("UPDATE `character_skills` SET `value` = 75, `max` = 75 WHERE `skill` = 762 AND `value` = 150 AND `max` = 150 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
        }

        // remove the riding spell
        if (!CharacterDatabase.PExecute("DELETE FROM `character_spell` WHERE `spell` = %u AND `guid` = %u", it->second, target_guid.GetCounter()))
        {
            SendSysMessage(LANG_REMOVE_RIDING_ERROR);
            SetSentErrorMessage(true);
            return false;
        }

        switch (it->second)
        {
            // Apprentice Riding
            case 33388:
            {
                // Remove Journeyman Riding too or it does nothing if he has it.
                if (!CharacterDatabase.PExecute("DELETE FROM `character_spell` WHERE `spell` = 33391 AND `guid` = %u", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
            // Journeyman Riding
            case 33391:
            {
                // Add Apprentice Riding spell.
                if (!CharacterDatabase.PExecute("INSERT INTO `character_spell` VALUES (%u, 33388, 1, 0)", target_guid.GetCounter()))
                {
                    SendSysMessage(LANG_REMOVE_RIDING_ERROR);
                    SetSentErrorMessage(true);
                    return false;
                }
                break;
            }
        }
    }

    PSendSysMessage(LANG_REMOVE_RIDING_SUCCESS, name.c_str()); // check
    return true;
}

bool ChatHandler::HandleUnLearnCommand(char* args)
{
    if (!*args)
        return false;

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r
    uint32 spell_id = ExtractSpellIdFromLink(&args);
    if (!spell_id)
        return false;

    bool allRanks = ExtractLiteralArg(&args, "all") != nullptr;
    if (!allRanks && *args)                                 // can be fail also at syntax error
        return false;

    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    if (allRanks)
        spell_id = sSpellMgr.GetFirstSpellInChain(spell_id);

    if (target->HasSpell(spell_id))
        target->RemoveSpell(spell_id, false, !allRanks);
    else
        SendSysMessage(LANG_FORGET_SPELL);

    return true;
}

bool ChatHandler::HandleGroupInfoCommand(char* args)
{
    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&args, &target, &target_guid, &target_name))
        return false;

    if (!target)
    {
        PSendSysMessage(LANG_NO_CHAR_SELECTED);
        return false;
    }

    auto group = target->GetGroup();

    if (!group)
    {
        std::string nameLink = GetNameLink(target);
        PSendSysMessage(LANG_NOT_IN_GROUP, nameLink.c_str());
        return false;
    }

    std::vector<std::string> names;

    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        if (Player* player = itr->getSource())
        {
            names.emplace_back(player->GetName());
        }
    }

    std::stringstream stream;

    for (std::size_t i = 0, j = names.size(); i != j; ++i)
    {
        stream << names[i];
        
        if (i + 1 != j)
        {
            stream << ", ";
        }
    }
    
    PSendSysMessage(LANG_GROUP_INFO, (group->isRaidGroup() ? "Raid" : "Party"),
                    playerLink(std::to_string(group->GetId())).c_str(), playerLink(group->GetLeaderName()).c_str(),
                    group->GetMembersCount(), stream.str().c_str());
    return true;
}

bool ChatHandler::HandlePInfoCommand(char* args)
{
    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&args, &target, &target_guid, &target_name, true))
        return false;

    if (HasLowerSecurity(target, target ? ObjectGuid() : target_guid))
        return false;

    PInfoHandler::HandlePInfoCommand(m_session, target, target_guid, target_name);

    return true;
}

bool ChatHandler::HandleMountCommand(char* /*args*/)
{
    Player* player = m_session->GetPlayer();
    if (player->IsTaxiFlying())
    {
        SendSysMessage(LANG_YOU_IN_FLIGHT);
        SetSentErrorMessage(true);
        return false;
    }
    
    Creature* target = GetSelectedCreature();
    if (!target)
    {
        player->Unmount();
        player->UpdateSpeed(MOVE_RUN, false, 1.0F);
        PSendSysMessage("Nothing to ride on! Target any creature with mounting points.");
        SetSentErrorMessage(true);
        return false;
    }

    player->SetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID, target->GetUInt32Value(UNIT_FIELD_DISPLAYID));
    player->UpdateSpeed(MOVE_RUN, false, 2.0F);
    return true;
}

bool ChatHandler::HandleDismountCommand(char* /*args*/)
{
    Player* pPlayer = m_session->GetPlayer();

    //If player is not mounted, so go out :)
    if (!pPlayer->IsMounted())
    {
        SendSysMessage(LANG_CHAR_NON_MOUNTED);
        SetSentErrorMessage(true);
        return false;
    }

    if (pPlayer->IsTaxiFlying())
    {
        SendSysMessage(LANG_YOU_IN_FLIGHT);
        SetSentErrorMessage(true);
        return false;
    }

    pPlayer->Unmount();
    pPlayer->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
    return true;
}

bool ChatHandler::HandleSaveCommand(char* /*args*/)
{
    Player* player = m_session->GetPlayer();

    // save GM account without delay and output message (testing, etc)
    if (GetAccessLevel() > SEC_PLAYER)
    {
        player->SaveToDB();
        SendSysMessage(LANG_PLAYER_SAVED);
        return true;
    }

    // save or plan save after 20 sec (logout delay) if current next save time more this value and _not_ output any messages to prevent cheat planning
    uint32 save_interval = sWorld.getConfig(CONFIG_UINT32_INTERVAL_SAVE);
    if (save_interval == 0 || (save_interval > 20 * IN_MILLISECONDS && player->GetSaveTimer() <= save_interval - 20 * IN_MILLISECONDS))
        player->SaveToDB();
    SendSysMessage(LANG_PLAYER_SAVED);
    return true;
}

bool ChatHandler::HandleWhisperRestrictionCommand(char* args)
{
    if (!*args)
    {
        PSendSysMessage("Whisper restriction is %s", GetSession()->GetPlayer()->IsEnabledWhisperRestriction() ? "ON" : "OFF");
        return true;
    }

    bool value;
    if (!ExtractOnOff(&args, value))
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    GetSession()->GetPlayer()->SetWhisperRestriction(value);
    PSendSysMessage("Whisper restriction is %s", value ? "ON" : "OFF");
    return false;
}

//Enable\Disable accept whispers (for GM)
bool ChatHandler::HandleWhispersCommand(char* args)
{
    if (!*args)
    {
        PSendSysMessage(LANG_COMMAND_WHISPERACCEPTING, GetOnOffStr(m_session->GetMasterPlayer()->IsAcceptWhispers()));
        return true;
    }

    bool value;
    if (!ExtractOnOff(&args, value))
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    // whisper on
    if (value)
    {
        GetSession()->GetMasterPlayer()->SetAcceptWhispers(true);
        SendSysMessage(LANG_COMMAND_WHISPERON);
    }
    // whisper off
    else
    {
        GetSession()->GetMasterPlayer()->SetAcceptWhispers(false);
        GetSession()->GetMasterPlayer()->ClearAllowedWhisperers();
        SendSysMessage(LANG_COMMAND_WHISPEROFF);
    }

    return true;
}

//Enable On\OFF all taxi paths
bool ChatHandler::HandleTaxiCheatCommand(char* args)
{
    bool value;
    if (!ExtractOnOff(&args, value))
    {
        SendSysMessage(LANG_USE_BOL);
        SetSentErrorMessage(true);
        return false;
    }

    Player* chr = GetSelectedPlayer();
    if (!chr)
        chr = m_session->GetPlayer();
    // check online security
    else if (HasLowerSecurity(chr))
        return false;

    if (value)
    {
        chr->SetTaxiCheater(true);
        PSendSysMessage(LANG_YOU_GIVE_TAXIS, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_TAXIS_ADDED, GetNameLink().c_str());
    }
    else
    {
        chr->SetTaxiCheater(false);
        PSendSysMessage(LANG_YOU_REMOVE_TAXIS, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_TAXIS_REMOVED, GetNameLink().c_str());
    }

    return true;
}

/**
 * Collects all GUIDs (and related info) from deleted characters which are still in the database.
 *
 * @param foundList    a reference to an std::list which will be filled with info data
 * @param useName      use a name/guid search (true) or an account name / account id search (false)
 * @param searchString the search string which either contains a player GUID (low part) or a part of the character-name
 * @return             returns false if there was a problem while selecting the characters (e.g. player name not normalizeable)
 */
bool ChatHandler::GetDeletedCharacterInfoList(DeletedInfoList& foundList, bool useName, std::string searchString)
{
    QueryResult* resultChar = nullptr;
    if (!searchString.empty())
    {
        if (useName)
        {
            // search by GUID
            if (isNumeric(searchString))
                resultChar = CharacterDatabase.PQuery("SELECT `guid`, `deleted_name`, `deleted_account`, `deleted_time` FROM `characters` WHERE `deleted_time` IS NOT NULL AND `guid` = %u LIMIT 0,50", uint32(atoi(searchString.c_str())));
            // search by name
            else
            {
                if (!normalizePlayerName(searchString))
                    return false;

                CharacterDatabase.escape_string(searchString);

                resultChar = CharacterDatabase.PQuery("SELECT `guid`, `deleted_name`, `deleted_account`, `deleted_time` FROM `characters` WHERE `deleted_time` IS NOT NULL AND `deleted_name` " _LIKE_ " " _CONCAT2_("'%s'", "'%%'") " LIMIT 0,50", searchString.c_str());
            }
        }
        else
        {
            // search by account id
            if (isNumeric(searchString))
                resultChar = CharacterDatabase.PQuery("SELECT `guid`, `deleted_name`, `deleted_account`, `deleted_time` FROM `characters` WHERE `deleted_time` IS NOT NULL AND `deleted_account` = %u LIMIT 0,50", uint32(atoi(searchString.c_str())));
            // search by account name
            else
            {
                if (!AccountMgr::normalizeString(searchString))
                    return false;

                LoginDatabase.escape_string(searchString);
                QueryResult* result = LoginDatabase.PQuery("SELECT `id` FROM `account` WHERE `username` " _LIKE_ " " _CONCAT2_("'%s'", "'%%'"), searchString.c_str());
                std::list<uint32> list;
                if (result)
                {
                    do
                    {
                        Field* fields = result->Fetch();
                        uint32 acc_id = fields[0].GetUInt32();
                        list.push_back(acc_id);
                    } while (result->NextRow());

                    delete result;
                }

                if (list.empty())
                    return false;
                std::stringstream accountStream;
                std::copy(list.begin(), list.end(), std::ostream_iterator<int>(accountStream, ","));
                std::string accounts = accountStream.str();
                accounts.pop_back();
                resultChar = CharacterDatabase.PQuery("SELECT `guid`, `deleted_name`, `deleted_account`, `deleted_time` FROM `characters` WHERE `deleted_time` IS NOT NULL AND `deleted_account` IN (%s) LIMIT 0,50", accounts.c_str());
            }
        }
    }
    else
        resultChar = CharacterDatabase.Query("SELECT `guid`, `deleted_name`, `deleted_account`, `deleted_time` FROM `characters` WHERE `deleted_time` IS NOT NULL LIMIT 0,50");

    if (resultChar)
    {
        do
        {
            Field* fields = resultChar->Fetch();

            DeletedInfo info;

            info.lowguid    = fields[0].GetUInt32();
            info.name       = fields[1].GetCppString();
            info.accountId  = fields[2].GetUInt32();

            // account name will be empty for nonexistent account
            sAccountMgr.GetName (info.accountId, info.accountName);

            info.deleteDate = time_t(fields[3].GetUInt64());

            foundList.push_back(info);
        } while (resultChar->NextRow());

        delete resultChar;
    }

    return true;
}

/**
 * Generate WHERE guids list by deleted info in way preventing return too long where list for existed query string length limit.
 *
 * @param itr          a reference to an deleted info list iterator, it updated in function for possible next function call if list to long
 * @param itr_end      a reference to an deleted info list iterator end()
 * @return             returns generated where list string in form: 'guid IN (gui1, guid2, ...)'
 */
std::string ChatHandler::GenerateDeletedCharacterGUIDsWhereStr(DeletedInfoList::const_iterator& itr, DeletedInfoList::const_iterator const& itr_end)
{
    std::ostringstream wherestr;
    wherestr << "guid IN ('";
    for(; itr != itr_end; ++itr)
    {
        wherestr << itr->lowguid;

        if (wherestr.str().size() > MAX_QUERY_LEN - 50)     // near to max query
        {
            ++itr;
            break;
        }

        DeletedInfoList::const_iterator itr2 = itr;
        if (++itr2 != itr_end)
            wherestr << "','";
    }
    wherestr << "')";
    return wherestr.str();
}

/**
 * Shows all deleted characters which matches the given search string, expected non empty list
 *
 * @see ChatHandler::HandleCharacterDeletedListCommand
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 * @see ChatHandler::DeletedInfoList
 *
 * @param foundList contains a list with all found deleted characters
 */
void ChatHandler::HandleCharacterDeletedListHelper(DeletedInfoList const& foundList)
{
    if (!m_session)
    {
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_HEADER);
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
    }

    for (const auto& itr : foundList)
    {
        std::string dateStr = TimeToTimestampStr(itr.deleteDate);

        if (!m_session)
            PSendSysMessage(LANG_CHARACTER_DELETED_LIST_LINE_CONSOLE,
                itr.lowguid, itr.name.c_str(), itr.accountName.empty() ? "<nonexistent>" : itr.accountName.c_str(),
                itr.accountId, dateStr.c_str());
        else
            PSendSysMessage(LANG_CHARACTER_DELETED_LIST_LINE_CHAT,
                itr.lowguid, itr.name.c_str(), itr.accountName.empty() ? "<nonexistent>" : itr.accountName.c_str(),
                itr.accountId, dateStr.c_str());
    }

    if (!m_session)
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_BAR);
}

/**
 * Handles the '.character deleted list' command, which shows all deleted characters which matches the given search string
 *
 * @see ChatHandler::HandleCharacterDeletedListHelper
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 * @see ChatHandler::DeletedInfoList
 *
 * @param args the search string which either contains a player GUID or a part of the character-name
 */
bool ChatHandler::HandleCharacterDeletedListNameCommand(char * args)
{
    return HandleCharacterDeletedListCommand(args, true);
}
bool ChatHandler::HandleCharacterDeletedListAccountCommand(char * args)
{
    return HandleCharacterDeletedListCommand(args, false);
}
bool ChatHandler::HandleCharacterDeletedListCommand(char* args, bool useName)
{
    DeletedInfoList foundList;
    if (!GetDeletedCharacterInfoList(foundList, useName, args))
        return false;

    // if no characters have been found, output a warning
    if (foundList.empty())
    {
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
        return false;
    }

    HandleCharacterDeletedListHelper(foundList);
    return true;
}

/**
 * Restore a previously deleted character
 *
 * @see ChatHandler::HandleCharacterDeletedListHelper
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 * @see ChatHandler::DeletedInfoList
 *
 * @param delInfo the informations about the character which will be restored
 */
void ChatHandler::HandleCharacterDeletedRestoreHelper(DeletedInfo const& delInfo)
{
    if (delInfo.accountName.empty())                    // account not exist
    {
        PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_ACCOUNT, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
        return;
    }

    // check character count
    uint32 charcount = sAccountMgr.GetCharactersCount(delInfo.accountId);
    if (charcount >= 10)
    {
        PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_FULL, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
        return;
    }

    if (sObjectMgr.GetPlayerGuidByName(delInfo.name))
    {
        PSendSysMessage(LANG_CHARACTER_DELETED_SKIP_NAME, delInfo.name.c_str(), delInfo.lowguid, delInfo.accountId);
        return;
    }

    CharacterDatabase.PExecute("UPDATE `characters` SET `name`='%s', `account`='%u', `deleted_time`=NULL, `deleted_name`=NULL, `deleted_account`=NULL WHERE `deleted_time` IS NOT NULL AND `guid` = %u",
        delInfo.name.c_str(), delInfo.accountId, delInfo.lowguid);
}

/**
 * Handles the '.character deleted restore' command, which restores all deleted characters which matches the given search string
 *
 * The command automatically calls '.character deleted list' command with the search string to show all restored characters.
 *
 * @see ChatHandler::HandleCharacterDeletedRestoreHelper
 * @see ChatHandler::HandleCharacterDeletedListCommand
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 *
 * @param args the search string which either contains a player GUID or a part of the character-name
 */
bool ChatHandler::HandleCharacterDeletedRestoreCommand(char* args)
{
    // It is required to submit at least one argument
    if (!*args)
        return false;

    std::string searchString;
    std::string newCharName;
    uint32 newAccount = 0;

    // GCC by some strange reason fail build code without temporary variable
    std::istringstream params(args);
    params >> searchString >> newCharName >> newAccount;

    DeletedInfoList foundList;
    if (!GetDeletedCharacterInfoList(foundList, true, searchString))
        return false;

    if (foundList.empty())
    {
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
        return false;
    }

    SendSysMessage(LANG_CHARACTER_DELETED_RESTORE);
    HandleCharacterDeletedListHelper(foundList);

    if (newCharName.empty())
    {
        // Drop nonexistent account cases
        for (const auto& itr : foundList)
            HandleCharacterDeletedRestoreHelper(itr);
    }
    else if (foundList.size() == 1 && normalizePlayerName(newCharName))
    {
        DeletedInfo delInfo = foundList.front();

        // update name
        delInfo.name = newCharName;

        // if new account provided update deleted info
        if (newAccount && newAccount != delInfo.accountId)
        {
            delInfo.accountId = newAccount;
            sAccountMgr.GetName (newAccount, delInfo.accountName);
        }

        HandleCharacterDeletedRestoreHelper(delInfo);
    }
    else
        SendSysMessage(LANG_CHARACTER_DELETED_ERR_RENAME);

    return true;
}

/**
 * Handles the '.character deleted delete' command, which completely deletes all deleted characters which matches the given search string
 *
 * @see Player::GetDeletedCharacterGUIDs
 * @see Player::DeleteFromDB
 * @see ChatHandler::HandleCharacterDeletedListCommand
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 *
 * @param args the search string which either contains a player GUID or a part of the character-name
 */
bool ChatHandler::HandleCharacterDeletedDeleteCommand(char* args)
{
    // It is required to submit at least one argument
    if (!*args)
        return false;

    DeletedInfoList foundList;
    if (!GetDeletedCharacterInfoList(foundList, args))
        return false;

    if (foundList.empty())
    {
        SendSysMessage(LANG_CHARACTER_DELETED_LIST_EMPTY);
        return false;
    }

    SendSysMessage(LANG_CHARACTER_DELETED_DELETE);
    HandleCharacterDeletedListHelper(foundList);

    // Call the appropriate function to delete them (current account for deleted characters is 0)
    for(const auto & itr : foundList)
        Player::DeleteFromDB(ObjectGuid(HIGHGUID_PLAYER, itr.lowguid), 0, false, true);

    return true;
}

/**
 * Handles the '.character deleted old' command, which completely deletes all deleted characters deleted with some days ago
 *
 * @see Player::DeleteOldCharacters
 * @see Player::DeleteFromDB
 * @see ChatHandler::HandleCharacterDeletedDeleteCommand
 * @see ChatHandler::HandleCharacterDeletedListCommand
 * @see ChatHandler::HandleCharacterDeletedRestoreCommand
 *
 * @param args the search string which either contains a player GUID or a part of the character-name
 */
bool ChatHandler::HandleCharacterDeletedOldCommand(char* args)
{
    int32 keepDays = sWorld.getConfig(CONFIG_UINT32_CHARDELETE_KEEP_DAYS);

    if (!ExtractOptInt32(&args, keepDays, sWorld.getConfig(CONFIG_UINT32_CHARDELETE_KEEP_DAYS)))
        return false;

    if (keepDays < 0)
        return false;

    Player::DeleteOldCharacters((uint32)keepDays);
    return true;
}

bool ChatHandler::HandleCharacterEraseCommand(char* args)
{
    char* nameStr = ExtractLiteralArg(&args);
    if (!nameStr)
        return false;

    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&nameStr, &target, &target_guid, &target_name))
        return false;

    uint32 account_id;

    if (target)
    {
        account_id = target->GetSession()->GetAccountId();
        target->GetSession()->KickPlayer();
    }
    else
        account_id = sObjectMgr.GetPlayerAccountIdByGUID(target_guid);

    std::string account_name;
    sAccountMgr.GetName (account_id,account_name);

    Player::DeleteFromDB(target_guid, account_id, true, true);
    PSendSysMessage(LANG_CHARACTER_DELETED, target_name.c_str(), target_guid.GetCounter(), account_name.c_str(), account_id);
    return true;
}


bool ChatHandler::HandleCleanCharactersToDeleteCommand(char* args)
{
    QueryResult* toDeleteCharsResult = CharacterDatabase.Query("SELECT `guid` FROM `characters_guid_delete`;");
    if (!toDeleteCharsResult)
    {
        SendSysMessage("Table 'characters_guid_delete' is empty or does not exist.");
        SetSentErrorMessage(true);
        return false;
    }
    else
    {
        uint32 deleteCount = 0;
        Field* fields;
        do
        {
            fields = toDeleteCharsResult->Fetch();
            uint32 guid  = fields[0].GetUInt32();

            Player::DeleteFromDB(guid,
                                 0, // AccountID
                                 false, // Update realm characters count
                                 true // Delete finally
                                );

            ++deleteCount;
        }
        while (toDeleteCharsResult->NextRow());
        PSendSysMessage("%u characters have been deleted.", deleteCount);
        delete toDeleteCharsResult;
    }
    return true;
}

bool ChatHandler::HandleCleanCharactersItemsCommand(char* args)
{
    bool Real = false;
    if (m_session->GetSecurity() == SEC_CONSOLE)
        Real = true;

    QueryResult* listDeleteItems = CharacterDatabase.Query("SELECT `entry` FROM `characters_item_delete`;");
    if (!listDeleteItems)
    {
        SendSysMessage("Cannot find items to delete. Table 'characters_item_delete' is empty ?");
        SetSentErrorMessage(true);
        return false;
    }
    std::vector<uint32> lDeleteEntries;

    uint32 deleteCount = 0;
    Field* fields;
    do
    {
        fields = listDeleteItems->Fetch();
        uint32 entry  = fields[0].GetUInt32();

        lDeleteEntries.push_back(entry);

        ++deleteCount;
    }
    while (listDeleteItems->NextRow());
    PSendSysMessage("%u items to delete.", lDeleteEntries.size());
    delete listDeleteItems;

    QueryResult* allPlayersItems = CharacterDatabase.Query("SELECT `guid`, `item_id`, `owner_guid` FROM `item_instance`;");
    if (!allPlayersItems)
    {
        SendSysMessage("Unable to retrieve player items list.");
        SetSentErrorMessage(true);
        return false;
    }
    deleteCount = 0;
    uint32 totalItems = 0;
    std::vector<uint32>::iterator itr;
    CharacterDatabase.BeginTransaction();
    do
    {
        ++totalItems;
        fields = allPlayersItems->Fetch();
        uint32 itemGuid  = fields[0].GetUInt32();
        uint32 itemId = fields[1].GetUInt32();
        uint32 ownerGuid = fields[2].GetUInt32();

        for (itr = lDeleteEntries.begin(); itr != lDeleteEntries.end(); ++itr)
        {
            if ((*itr) == itemId)
            {
                if (Real)
                {
                    // InGame ?
                    if (Player* pPlayer = sObjectMgr.GetPlayer(ownerGuid))
                        pPlayer->DestroyItemCount(itemId, 255, true);
                    else
                        Item::DeleteAllFromDB(itemGuid);
                }
                ++deleteCount;
                break;
            }
        }

    }
    while (allPlayersItems->NextRow());
    CharacterDatabase.CommitTransaction();

    SendSysMessage("==== Statistiques ====");
    PSendSysMessage("- %u items entries", totalItems);
    PSendSysMessage("- %u items deleted", deleteCount);
    if (!Real)
        SendSysMessage("-> Not executed. (for security purposes).");
    delete allPlayersItems;
    return true;
}

void ChatHandler::HandleCharacterLevel(Player* player, ObjectGuid player_guid, uint32 oldlevel, uint32 newlevel)
{
    if (player)
    {
        player->GiveLevel(newlevel);
        player->InitTalentForLevel();
        player->SetUInt32Value(PLAYER_XP, 0);

        if (needReportToTarget(player))
        {
            if (oldlevel == newlevel)
                ChatHandler(player).PSendSysMessage(LANG_YOURS_LEVEL_PROGRESS_RESET, GetNameLink().c_str());
            else if (oldlevel < newlevel)
                ChatHandler(player).PSendSysMessage(LANG_YOURS_LEVEL_UP, GetNameLink().c_str(), newlevel);
            else                                                // if (oldlevel > newlevel)
                ChatHandler(player).PSendSysMessage(LANG_YOURS_LEVEL_DOWN, GetNameLink().c_str(), newlevel);
        }
    }
    else
    {
        // update level and XP at level, all other will be updated at loading
        CharacterDatabase.PExecute("UPDATE `characters` SET `level` = '%u', `xp` = 0 WHERE `guid` = '%u'", newlevel, player_guid.GetCounter());
    }
}

bool ChatHandler::HandleCharacterLevelCommand(char* args)
{
    char* nameStr = ExtractOptNotLastArg(&args);

    int32 newlevel;
    bool nolevel = false;
    // exception opt second arg: .character level $name
    if (!ExtractInt32(&args, newlevel))
    {
        if (!nameStr)
        {
            nameStr = ExtractArg(&args);
            if (!nameStr)
                return false;

            nolevel = true;
        }
        else
            return false;
    }

    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&nameStr, &target, &target_guid, &target_name))
        return false;

    int32 oldlevel = target ? target->GetLevel() : Player::GetLevelFromDB(target_guid);
    if (nolevel)
        newlevel = oldlevel;

    if (newlevel < 1)
        return false;                                       // invalid level

    if (newlevel > PLAYER_STRONG_MAX_LEVEL)                 // hardcoded maximum level
        newlevel = PLAYER_STRONG_MAX_LEVEL;

    HandleCharacterLevel(target, target_guid, oldlevel, newlevel);

    if (!m_session || m_session->GetPlayer() != target)     // including player==nullptr
    {
        std::string nameLink = playerLink(target_name);
        PSendSysMessage(LANG_YOU_CHANGE_LVL, nameLink.c_str(), newlevel);
    }

    return true;
}

bool ChatHandler::HandleCharacterRenameCommand(char* args)
{
    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&args, &target, &target_guid, &target_name))
        return false;

    if (target)
    {
        // check online security
        if (HasLowerSecurity(target))
            return false;

        PSendSysMessage(LANG_RENAME_PLAYER, GetNameLink(target).c_str());
        target->SetAtLoginFlag(AT_LOGIN_RENAME);
        CharacterDatabase.PExecute("UPDATE `characters` SET `at_login_flags` = `at_login_flags` | '1' WHERE `guid` = '%u'", target->GetGUIDLow());
    }
    else
    {
        // check offline security
        if (HasLowerSecurity(nullptr, target_guid))
            return false;

        std::string oldNameLink = playerLink(target_name);

        PSendSysMessage(LANG_RENAME_PLAYER_GUID, oldNameLink.c_str(), target_guid.GetCounter());
        CharacterDatabase.PExecute("UPDATE `characters` SET `at_login_flags` = `at_login_flags` | '1' WHERE `guid` = '%u'", target_guid.GetCounter());
    }

    return true;
}

bool ChatHandler::HandleCharacterReputationCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    LocaleConstant loc = GetSessionDbcLocale();

    FactionStateList const& targetFSL = target->GetReputationMgr().GetStateList();
    for (const auto& itr : targetFSL)
    {
        FactionEntry const* factionEntry = sObjectMgr.GetFactionEntry(itr.second.ID);

        ShowFactionListHelper(factionEntry, loc, &itr.second, target);
    }
    return true;
}

bool ChatHandler::HandleCharacterHasItemCommand(char* args)
{
    if (!*args)
        return false;

    uint32 itemId = 0;
    if (!ExtractUInt32(&args, itemId))
        return false;

    Player* plTarget;
    ObjectGuid target_guid;
    std::string target_name;

    if (!ExtractPlayerTarget(&args, &plTarget, &target_guid, &target_name))
        return false;

    ItemPrototype const* pItem = ObjectMgr::GetItemPrototype(itemId);

    if (!pItem)
    {
        PSendSysMessage("Unknown item %u", itemId);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 itemCount = 0;

    if (plTarget)
    {
        itemCount = plTarget->GetItemCount(itemId, true);
    }
    else
    {
        std::unique_ptr<QueryResult> result(CharacterDatabase.PQuery(
            "SELECT SUM(`count`) AS item_count FROM `item_instance` ii WHERE `item_id` = %u and `owner_guid` = %u",
            itemId, target_guid.GetCounter()
        ));

        if (result)
        {
            auto fields = result->Fetch();
            itemCount = fields[0].GetUInt32();
        }
    }

    PSendSysMessage("%s's amount of %s (id %u) is: %u", target_name.c_str(), GetItemLink(pItem).c_str(), itemId, itemCount);
    return true;
}

bool ChatHandler::HandleCharacterPremadeGearCommand(char* args)
{
    Player* pPlayer = GetSelectedPlayer();
    if (!pPlayer)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        return false;
    }
        
    if (!*args)
    {
        PSendSysMessage("Listing available premade templates for %s:", pPlayer->GetName());
        for (auto itr : sObjectMgr.GetPlayerPremadeGearTemplates())
        {
            if (itr.second.requiredClass == pPlayer->GetClass())
            {
                PSendSysMessage("%u - %s (lvl %u)", itr.first, itr.second.name.c_str(), itr.second.level);
            }
        }
        return true;
    }

    uint32 entry = atoi(args);

    if (!entry)
    {
        std::string name = args;
        for (auto itr : sObjectMgr.GetPlayerPremadeGearTemplates())
        {
            if (itr.second.name == name && itr.second.requiredClass == pPlayer->GetClass())
            {
                entry = itr.first;
                break;
            }
        }
    }

    if (!entry)
    {
        SendSysMessage("No matching premade player template found.");
        return false;
    }

    sObjectMgr.ApplyPremadeGearTemplateToPlayer(entry, pPlayer);

    PSendSysMessage("Premade gear template %u applied to player %s.", entry, pPlayer->GetName());
    return true;
}

static std::string EscapeString(std::string unescapedString)
{
    char* escapedString = new char[unescapedString.length() * 2 + 1];
    mysql_escape_string(escapedString, unescapedString.c_str(), unescapedString.length());
    std::string returnString = escapedString;
    delete[] escapedString;
    return returnString;
}

bool ChatHandler::HandleCharacterPremadeSaveGearCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    if (!*args)
    {
        SendSysMessage("Incorrect syntax. Template name expected.");
        return false;
    }

    std::string templateName = args;
    if (templateName.find(" ") != std::string::npos)
    {
        SendSysMessage("Template name cannot contain spaces.");
        return false;
    }

    uint32 entry = 0;
    std::unique_ptr<QueryResult> result(WorldDatabase.Query("SELECT MAX(`entry`) FROM `player_premade_item_template`"));
    if (result)
    {
        Field* fields = result->Fetch();
        entry = fields[0].GetUInt32() + 1;
    }

    templateName = EscapeString(templateName);
    if (!WorldDatabase.PExecute("INSERT INTO `player_premade_item_template` (`entry`, `class`, `level`, `name`) VALUES (%u, %u, %u, '%s')", entry, pPlayer->GetClass(), pPlayer->GetLevel(), templateName.c_str()))
        return false;

    for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (Item* pItem = pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            WorldDatabase.DirectPExecute("INSERT INTO `player_premade_item` (`entry`, `item`, `enchant`) VALUES (%u, %u, %u)", entry, pItem->GetEntry(), pItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT));
        }
    }

    sObjectMgr.LoadPlayerPremadeTemplates();

    PSendSysMessage("Premade gear template %u saved to database.", entry);
    return true;
}

bool ChatHandler::HandleCharacterPremadeSpecCommand(char* args)
{
    Player* pPlayer = GetSelectedPlayer();
    if (!pPlayer)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        return false;
    }

    if (!*args)
    {
        PSendSysMessage("Listing available premade templates for %s:", pPlayer->GetName());
        for (auto itr : sObjectMgr.GetPlayerPremadeSpecTemplates())
        {
            if (itr.second.requiredClass == pPlayer->GetClass())
            {
                PSendSysMessage("%u - %s (lvl %u)", itr.first, itr.second.name.c_str(), itr.second.level);
            }
        }
        return true;
    }

    uint32 entry = atoi(args);

    if (!entry)
    {
        std::string name = args;
        for (auto itr : sObjectMgr.GetPlayerPremadeSpecTemplates())
        {
            if (itr.second.name == name && itr.second.requiredClass == pPlayer->GetClass())
            {
                entry = itr.first;
                break;
            }
        }
    }

    if (!entry)
    {
        SendSysMessage("No matching premade player template found.");
        return false;
    }

    sObjectMgr.ApplyPremadeSpecTemplateToPlayer(entry, pPlayer);

    PSendSysMessage("Premade spec template %u applied to player %s.", entry, pPlayer->GetName());
    return true;
}

bool ChatHandler::HandleCharacterPremadeSaveSpecCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();

    if (!*args)
    {
        SendSysMessage("Incorrect syntax. Template name expected.");
        return false;
    }

    std::string templateName = args;
    if (templateName.find(" ") != std::string::npos)
    {
        SendSysMessage("Template name cannot contain spaces.");
        return false;
    }

    uint32 entry = 0;
    std::unique_ptr<QueryResult> result(WorldDatabase.Query("SELECT MAX(`entry`) FROM `player_premade_spell_template`"));
    if (result)
    {
        Field* fields = result->Fetch();
        entry = fields[0].GetUInt32() + 1;
    }

    templateName = EscapeString(templateName);
    if (!WorldDatabase.PExecute("INSERT INTO `player_premade_spell_template` (`entry`, `class`, `level`, `name`) VALUES (%u, %u, %u, '%s')", entry, pPlayer->GetClass(), pPlayer->GetLevel(), templateName.c_str()))
        return false;

    PlayerInfo const* pInfo = sObjectMgr.GetPlayerInfo(pPlayer->GetRace(), pPlayer->GetClass());
    if (!pInfo)
        return false;

    result.reset(CharacterDatabase.PQuery("SELECT DISTINCT `spell` FROM `character_spell` WHERE `disabled`=0 && `active`=1 && `guid`=%u", pPlayer->GetGUIDLow()));

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 spellId = fields[0].GetUInt32();
            
            if (!sSpellMgr.GetSpellEntry(spellId))
                continue;

            if (std::find(pInfo->spell.begin(), pInfo->spell.end(), spellId) != pInfo->spell.end())
                continue;

            WorldDatabase.DirectPExecute("INSERT INTO `player_premade_spell` (`entry`, `spell`) VALUES (%u, %u)", entry, spellId);
        } while (result->NextRow());
    }

    sObjectMgr.LoadPlayerPremadeTemplates();

    PSendSysMessage("Premade spec template %u saved to database.", entry);
    return true;
}

bool ChatHandler::HandleCharacterChangeRaceCommand(char* args)
{
    if (Player* pPlayer = GetSelectedPlayer())
    {
        uint8 newRaceId = 0;

        char* newRaceStr = strtok(args, " ");
        if (newRaceStr)
            newRaceId = uint8(atoi(newRaceStr));

        if (pPlayer->ChangeRace(newRaceId))
            return true;

        PSendSysMessage("Cannot change race to %u", newRaceId);
        return true;
    }
    return false;
}

bool ChatHandler::HandleCharacterCopySkinCommand(char* args)
{
    if (Player* target = GetSelectedPlayer())
    {
        std::string plName(args);
        CharacterDatabase.escape_string(plName); // No SQL injection

        //                                                      0       1       2             3             4              5
        QueryResult* result = CharacterDatabase.PQuery("SELECT `skin`, `face`, `hair_style`, `hair_color`, `facial_hair`, `gender` FROM `characters` WHERE `name`='%s'", plName.c_str());
        if (!result)
        {
            PSendSysMessage("Player %s not found.", args);
            SetSentErrorMessage(true);
            return false;
        }
        Field* fields = result->Fetch();
        uint8 skin = fields[0].GetUInt32();
        uint8 face = fields[1].GetUInt32();
        uint8 hairStyle = fields[2].GetUInt32();
        uint8 hairColor = fields[3].GetUInt32();
        uint8 facialHair = fields[4].GetUInt32();
        uint8 gender = fields[5].GetUInt8();
        target->SetByteValue(PLAYER_BYTES, 0, skin);
        target->SetByteValue(PLAYER_BYTES, 1, face);
        target->SetByteValue(PLAYER_BYTES, 2, hairStyle);
        target->SetByteValue(PLAYER_BYTES, 3, hairColor);
        target->SetByteValue(PLAYER_BYTES_2, 0, facialHair);
        target->SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, gender);
        SendSysMessage("Modification du skin/genre OK.");
        return true;
    }
    return false;
}

bool ChatHandler::HandleCharacterFillFlysCommand(char* args)
{
    if (Player* player = GetSelectedPlayer())
    {
        if (player->GetTeam() == ALLIANCE)
            player->GetTaxi().LoadTaxiMask("3456411898 2148078928 49991 0 0 0 0 0 ");
        else
            player->GetTaxi().LoadTaxiMask("561714688 282102432 52408 0 0 0 0 0 ");
        PSendSysMessage("Fly paths unlocked for %s.", player->GetName());
        return true;
    }
    return false;
}

bool ChatHandler::HandleCharacterCityTitleCommand(char* args)
{
    Player* pPlayer = GetSelectedPlayer();
    if (!pPlayer)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        return false;
    }

    bool value;
    if (!ExtractOnOff(&args, value))
    {
        PSendSysMessage("Syntax: .title on | off");
        return false;
    }

    if (value)
        pPlayer->SetCityTitle();
    else
        pPlayer->RemoveCityTitle();

    return true;
}

bool ChatHandler::HandleHonorShow(char* /*args*/)
{
    Player* target = GetSelectedPlayer();
    if (!target)
        target = m_session->GetPlayer();

    int8 highest_rank               = target->GetHonorMgr().GetHighestRank().visualRank;
    uint32 dishonorable_kills       = target->GetUInt32Value(PLAYER_FIELD_LIFETIME_DISHONORBALE_KILLS);
    uint32 honorable_kills          = target->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS);
    uint32 today_honorable_kills    = target->GetUInt16Value(PLAYER_FIELD_SESSION_KILLS, 0);
    uint32 today_dishonorable_kills = target->GetUInt16Value(PLAYER_FIELD_SESSION_KILLS, 1);
    uint32 yesterday_kills          = target->GetUInt32Value(PLAYER_FIELD_YESTERDAY_KILLS);
    uint32 yesterday_honor          = target->GetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION);
    uint32 this_week_kills          = target->GetUInt32Value(PLAYER_FIELD_THIS_WEEK_KILLS);
    uint32 this_week_honor          = target->GetUInt32Value(PLAYER_FIELD_THIS_WEEK_CONTRIBUTION);
    uint32 last_week_kills          = target->GetUInt32Value(PLAYER_FIELD_LAST_WEEK_KILLS);
    uint32 last_week_honor          = target->GetUInt32Value(PLAYER_FIELD_LAST_WEEK_CONTRIBUTION);
    uint32 last_week_standing       = target->GetUInt32Value(PLAYER_FIELD_LAST_WEEK_RANK);

    static int16 alliance_ranks[HONOR_RANK_COUNT] =
    {
        LANG_NO_RANK,
        LANG_RANK_PARIAH,
        LANG_RANK_OUTLAW,
        LANG_RANK_EXILED,
        LANG_RANK_DISHONORED,
        LANG_ALI_PRIVATE,
        LANG_ALI_CORPORAL,
        LANG_ALI_SERGEANT,
        LANG_ALI_MASTER_SERGEANT,
        LANG_ALI_SERGEANT_MAJOR,
        LANG_ALI_KNIGHT,
        LANG_ALI_KNIGHT_LIEUTENANT,
        LANG_ALI_KNIGHT_CAPTAIN,
        LANG_ALI_KNIGHT_CHAMPION,
        LANG_ALI_LIEUTENANT_COMMANDER,
        LANG_ALI_COMMANDER,
        LANG_ALI_MARSHAL,
        LANG_ALI_FIELD_MARSHAL,
        LANG_ALI_GRAND_MARSHAL,
        //LANG_GAME_MASTER
    };
    static int16 horde_ranks[HONOR_RANK_COUNT] =
    {
        LANG_NO_RANK,
        LANG_RANK_PARIAH,
        LANG_RANK_OUTLAW,
        LANG_RANK_EXILED,
        LANG_RANK_DISHONORED,
        LANG_HRD_SCOUT,
        LANG_HRD_GRUNT,
        LANG_HRD_SERGEANT,
        LANG_HRD_SENIOR_SERGEANT,
        LANG_HRD_FIRST_SERGEANT,
        LANG_HRD_STONE_GUARD,
        LANG_HRD_BLOOD_GUARD,
        LANG_HRD_LEGIONNARE,
        LANG_HRD_CENTURION,
        LANG_HRD_CHAMPION,
        LANG_HRD_LIEUTENANT_GENERAL,
        LANG_HRD_GENERAL,
        LANG_HRD_WARLORD,
        LANG_HRD_HIGH_WARLORD,
        //LANG_GAME_MASTER
    };
    char const* rank_name = nullptr;
    char const* hrank_name = nullptr;

    uint32 honor_rank = target->GetHonorMgr().GetRank().visualRank;

    if (honor_rank >= HONOR_RANK_COUNT || highest_rank >= HONOR_RANK_COUNT)
    {
        PSendSysMessage("CrashAlert : R%u et HR%u", honor_rank, highest_rank);
        return false;
    }

    if (target->GetTeam() == ALLIANCE)
    {
        rank_name = GetMangosString(alliance_ranks[ honor_rank ]);
        hrank_name = GetMangosString(alliance_ranks[ highest_rank ]);
    }
    else if (target->GetTeam() == HORDE)
    {
        rank_name = GetMangosString(horde_ranks[ honor_rank ]);
        hrank_name = GetMangosString(horde_ranks[ highest_rank ]);
    }
    else
    {
        rank_name = GetMangosString(LANG_NO_RANK);
        hrank_name = GetMangosString(LANG_NO_RANK);
    }

    PSendSysMessage(LANG_RANK, target->GetName(), rank_name, honor_rank);
    PSendSysMessage(LANG_HONOR_TODAY, today_honorable_kills, today_dishonorable_kills);
    PSendSysMessage(LANG_HONOR_YESTERDAY, yesterday_kills, yesterday_honor);
    PSendSysMessage(LANG_HONOR_THIS_WEEK, this_week_kills, this_week_honor);
    PSendSysMessage(LANG_HONOR_LAST_WEEK, last_week_kills, last_week_honor, last_week_standing);
    PSendSysMessage(LANG_HONOR_LIFE, target->GetHonorMgr().GetRankPoints(), honorable_kills, dishonorable_kills, highest_rank, hrank_name);

    return true;
}

bool ChatHandler::HandleHonorAddCommand(char* args)
{
    if (!*args)
        return false;

    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target))
        return false;

    float amount = (float)atof(args);
    target->GetHonorMgr().Add(amount, OTHER);
    return true;
}

bool ChatHandler::HandleHonorAddKillCommand(char* /*args*/)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    if (target == m_session->GetPlayer())
        return false;

    m_session->GetPlayer()->RewardHonor(target, 1);
    return true;
}

bool ChatHandler::HandleModifyHonorCommand(char* args)
{
    if (!*args)
        return false;

    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    char* field = ExtractLiteralArg(&args);
    if (!field)
        return false;

    int32 amount;
    if (!ExtractInt32(&args, amount))
        return false;

    // hack code
    if (hasStringAbbr(field, "points"))
    {
        if (amount < 0 || amount > 255)
            return false;
        // rank points is sent to client with same size of uint8(255) for each rank
        target->SetByteValue(PLAYER_FIELD_BYTES2, 0, amount);
    }
    else if (hasStringAbbr(field, "rank"))
    {
        if (amount < 0 || amount >= HONOR_RANK_COUNT)
            return false;
        target->SetByteValue(PLAYER_BYTES_3, 3, amount);
    }
    else if (hasStringAbbr(field, "todaykills"))
        target->SetUInt16Value(PLAYER_FIELD_SESSION_KILLS, 0, (uint32)amount);
    else if (hasStringAbbr(field, "yesterdaykills"))
        target->SetUInt32Value(PLAYER_FIELD_YESTERDAY_KILLS, (uint32)amount);
    else if (hasStringAbbr(field, "yesterdayhonor"))
        target->SetUInt32Value(PLAYER_FIELD_YESTERDAY_CONTRIBUTION, (uint32)amount);
    else if (hasStringAbbr(field, "thisweekkills"))
        target->SetUInt32Value(PLAYER_FIELD_THIS_WEEK_KILLS, (uint32)amount);
    else if (hasStringAbbr(field, "thisweekhonor"))
        target->SetUInt32Value(PLAYER_FIELD_THIS_WEEK_CONTRIBUTION, (uint32)amount);
    else if (hasStringAbbr(field, "lastweekkills"))
        target->SetUInt32Value(PLAYER_FIELD_LAST_WEEK_KILLS, (uint32)amount);
    else if (hasStringAbbr(field, "lastweekhonor"))
        target->SetUInt32Value(PLAYER_FIELD_LAST_WEEK_CONTRIBUTION, (uint32)amount);
    else if (hasStringAbbr(field, "lastweekstanding"))
        target->SetUInt32Value(PLAYER_FIELD_LAST_WEEK_RANK, (uint32)amount);
    else if (hasStringAbbr(field, "lifetimedishonorablekills"))
        target->SetUInt32Value(PLAYER_FIELD_LIFETIME_DISHONORBALE_KILLS, (uint32)amount);
    else if (hasStringAbbr(field, "lifetimehonorablekills"))
        target->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORBALE_KILLS, (uint32)amount);

    PSendSysMessage(LANG_COMMAND_MODIFY_HONOR, field, target->GetName(), hasStringAbbr(field, "rank") ? amount : (uint32)amount);

    return true;
}

bool ChatHandler::HandleHonorResetCommand(char* /*args*/)
{
    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    target->GetHonorMgr().Reset();
    return true;
}

bool ChatHandler::HandleHonorSetRPCommand(char *args)
{
    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    float value;
    if (!ExtractFloat(&args, value))
        return false;
    
    target->GetHonorMgr().SetRankPoints(value);
    target->GetHonorMgr().Update();
    PSendSysMessage("You have changed rank points of %s to %g.", target->GetName(), value);
    return true;
}

bool ChatHandler::HandleLearnAllCommand(char* /*args*/)
{
    Player* pPlayer = GetSelectedPlayer();
    if (!pPlayer)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    for (uint32 i = 0; i < sSpellMgr.GetMaxSpellId(); i++)
    {
        SpellEntry const* pSpellInfo = sSpellMgr.GetSpellEntry(i);
        if (!pSpellInfo)
            continue;

        for (uint32 j = 0; j < MAX_SPELL_EFFECTS; j++)
        {
            if ((pSpellInfo->Effect[j] == SPELL_EFFECT_LEARN_SPELL) &&
                (pSpellInfo->EffectImplicitTargetA[j] == TARGET_NONE))
            {
                uint32 spellId = pSpellInfo->EffectTriggerSpell[j];
                SpellEntry const* pNewSpell = sSpellMgr.GetSpellEntry(spellId);

                // skip broken spells
                if (!SpellMgr::IsSpellValid(pNewSpell, pPlayer, false))
                    continue;

                // skip spells with first rank learned as talent (and all talents then also)
                uint32 firstRankId = sSpellMgr.GetFirstSpellInChain(spellId);
                if (GetTalentSpellCost(firstRankId) > 0)
                    continue;

                if (!pNewSpell->HasEffect(SPELL_EFFECT_PROFICIENCY))
                {
                    // only class spells
                    if (!pNewSpell->SpellFamilyName)
                        continue;

                    // skip passives
                    if (pNewSpell->HasAttribute(SPELL_ATTR_PASSIVE) ||
                        pNewSpell->HasAttribute(SPELL_ATTR_HIDDEN_CLIENTSIDE) ||
                        pNewSpell->HasAttribute(SPELL_ATTR_EX2_DISPLAY_IN_STANCE_BAR))
                        continue;
                } 

                pPlayer->LearnSpell(spellId, false);
            }  
        }
    }

    SendSysMessage(LANG_COMMAND_LEARN_MANY_SPELLS);

    return true;
}

static uint32 gmSpellList[] =
{
    5,      // Death Touch
    265,    // Area Death (TEST)
    30879,  // Permanent Area Damage 50k
    7482,   // dmg
    8295,   // dmg2
    10073,  // dmg3
    11821,  // dmg4
    18389,  // dmg5
    18390,  // dmg6
    19901,  // dmg7
    27254,  // dmg8
    27255,  // dmg9
    27258,  // dmg10
    27261,  // dmg11
    25059,  // Dmg Shield
    26666,  // Dmg Shield2
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
    456,    // SHOWLABEL Only OFF
    2765,   // SHOWLABEL Only ON
    1509,   // GM Only OFF
    18139,  // GM Only ON
    6147,   // INVIS Only OFF
    2763,   // INVIS Only ON
    20114,  // BM Only OFF
    20115,  // BM Only ON
#endif
    24341,  // Revive
    29313,  // CooldownAll
    1302,   // Damage Immunity Test
    9454,   // Freeze
    31366,  // Root Anybody Forever
    1908,   // Uber Heal Over Time
    8358,   // Mana Spike
    23965,  // Instant Heal
};

bool ChatHandler::HandleLearnAllGMCommand(char* /*args*/)
{
    for (uint32 spell : gmSpellList)
    {
        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spell);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, m_session->GetPlayer()))
        {
            PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spell);
            continue;
        }

        m_session->GetPlayer()->LearnSpell(spell, false);
    }

    SendSysMessage(LANG_LEARNING_GM_SKILLS);
    return true;
}

bool ChatHandler::HandleUnLearnAllGMCommand(char* /*args*/)
{
    for (uint32 spell : gmSpellList)
    {
        m_session->GetPlayer()->RemoveSpell(spell, false, false);
    }

    SendSysMessage("You have forgotten all gm spells.");
    return true;
}

bool ChatHandler::HandleLearnAllMyClassCommand(char* /*args*/)
{
    HandleLearnAllMySpellsCommand((char*)"");
    HandleLearnAllMyTalentsCommand((char*)"");
    return true;
}

bool ChatHandler::HandleLearnAllMySpellsCommand(char* /*args*/)
{
    Player* pPlayer = m_session->GetPlayer();
    ChrClassesEntry const* clsEntry = sChrClassesStore.LookupEntry(pPlayer->GetClass());
    if (!clsEntry)
        return true;
    uint32 family = clsEntry->spellfamily;

    for (uint32 i = 0; i < sObjectMgr.GetMaxSkillLineAbilityId(); ++i)
    {
        SkillLineAbilityEntry const* entry = sObjectMgr.GetSkillLineAbility(i);
        if (!entry)
            continue;

        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(entry->spellId);
        if (!spellInfo)
            continue;

        // skip server-side/triggered spells
        if (spellInfo->spellLevel == 0)
            continue;

        // skip wrong class/race skills
        if (!pPlayer->IsSpellFitByClassAndRace(spellInfo->Id))
            continue;

        // skip other spell families
        if (spellInfo->SpellFamilyName != family)
            continue;

        // skip spells with first rank learned as talent (and all talents then also)
        uint32 first_rank = sSpellMgr.GetFirstSpellInChain(spellInfo->Id);
        if (GetTalentSpellCost(first_rank) > 0)
            continue;

        // skip broken spells
        if (!SpellMgr::IsSpellValid(spellInfo, pPlayer, false))
            continue;

        pPlayer->LearnSpell(spellInfo->Id, false);
    }

    SendSysMessage(LANG_COMMAND_LEARN_CLASS_SPELLS);
    return true;
}

bool ChatHandler::HandleLearnAllMyTalentsCommand(char* /*args*/)
{
    Player* pPlayer = m_session->GetPlayer();
    uint32 classMask = pPlayer->GetClassMask();

    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
        if (!talentInfo)
            continue;

        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
        if (!talentTabInfo)
            continue;

        if ((classMask & talentTabInfo->ClassMask) == 0)
            continue;

        // search highest talent rank
        uint32 spellid = 0;

        for (int rank = MAX_TALENT_RANK - 1; rank >= 0; --rank)
        {
            if (talentInfo->RankID[rank] != 0)
            {
                spellid = talentInfo->RankID[rank];
                break;
            }
        }

        if (!spellid)                                       // ??? none spells in talent
            continue;

        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellid);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, pPlayer, false))
            continue;

        // learn highest rank of talent and learn all non-talent spell ranks (recursive by tree)
        pPlayer->LearnSpellHighRank(spellid);
    }

    SendSysMessage(LANG_COMMAND_LEARN_CLASS_TALENTS);
    return true;
}

bool ChatHandler::HandleLearnAllMyTaxisCommand(char* /*args*/)
{
    Player* player = m_session->GetPlayer();

    for (uint32 i = 0; i < sCreatureStorage.GetMaxEntry(); ++i)
    {
        if (CreatureInfo const* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(i))
            if (cInfo->npc_flags & UNIT_NPC_FLAG_FLIGHTMASTER)
            {
                FindCreatureData worker(cInfo->entry, player);
                sObjectMgr.DoCreatureData(worker);
                if (CreatureDataPair const* dataPair = worker.GetResult())
                    if (CreatureData const* data = &dataPair->second)
                        if (uint32 taxiNode = sObjectMgr.GetNearestTaxiNode(data->position.x, data->position.y, data->position.z, data->position.mapId, player->GetTeam()))
                            if (player->GetTaxi().SetTaximaskNode(taxiNode))
                            {
                                WorldPacket msg(SMSG_NEW_TAXI_PATH, 0);
                                GetSession()->SendPacket(&msg);
                            }
            }
    }
    SendSysMessage(LANG_COMMAND_LEARN_TAXIS);
    return true;
}

bool ChatHandler::HandleLearnAllLangCommand(char* /*args*/)
{
    Player* pPlayer = m_session->GetPlayer();

    // skipping UNIVERSAL language (0)
    for (int i = 1; i < LANGUAGES_COUNT; ++i)
        pPlayer->LearnSpell(lang_description[i].spell_id, false);

    SendSysMessage(LANG_COMMAND_LEARN_ALL_LANG);
    return true;
}

bool ChatHandler::HandleLearnAllDefaultCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    target->LearnDefaultSpells();
    target->LearnQuestRewardedSpells();

    PSendSysMessage(LANG_COMMAND_LEARN_ALL_DEFAULT_AND_QUEST, GetNameLink(target).c_str());
    return true;
}

void ChatHandler::HandleLearnSkillRecipesHelper(Player* player, uint32 skill_id)
{
    uint32 classmask = player->GetClassMask();

    for (uint32 j = 0; j < sObjectMgr.GetMaxSkillLineAbilityId(); ++j)
    {
        SkillLineAbilityEntry const* skillLine = sObjectMgr.GetSkillLineAbility(j);
        if (!skillLine)
            continue;

        // wrong skill
        if (skillLine->skillId != skill_id)
            continue;

        // not high rank
        if (skillLine->forward_spellid)
            continue;

        // skip racial skills
        if (skillLine->racemask != 0)
            continue;

        // skip wrong class skills
        if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
            continue;

        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(skillLine->spellId);
        if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
            continue;

        player->LearnSpell(skillLine->spellId, false);
    }
}

void ChatHandler::HandleUnLearnSkillRecipesHelper(Player* player, uint32 skill_id)
{
    for (uint32 j = 0; j < sObjectMgr.GetMaxSkillLineAbilityId(); ++j)
    {
        SkillLineAbilityEntry const* skillLine = sObjectMgr.GetSkillLineAbility(j);
        if (!skillLine)
            continue;

        // wrong skill
        if (skillLine->skillId != skill_id)
            continue;

        player->RemoveSpell(skillLine->spellId, false, false);
    }
}

bool ChatHandler::HandleLearnAllCraftsCommand(char* /*args*/)
{
    for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i)
    {
        SkillLineEntry const* skillInfo = sSkillLineStore.LookupEntry(i);
        if (!skillInfo)
            continue;

        if (skillInfo->categoryId == SKILL_CATEGORY_PROFESSION || skillInfo->categoryId == SKILL_CATEGORY_SECONDARY)
            HandleLearnSkillRecipesHelper(m_session->GetPlayer(), skillInfo->id);
    }

    SendSysMessage(LANG_COMMAND_LEARN_ALL_CRAFT);
    return true;
}

bool ChatHandler::HandleUnLearnAllCraftsCommand(char* /*args*/)
{
    for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i)
    {
        SkillLineEntry const* skillInfo = sSkillLineStore.LookupEntry(i);
        if (!skillInfo)
            continue;

        if (skillInfo->categoryId == SKILL_CATEGORY_PROFESSION || skillInfo->categoryId == SKILL_CATEGORY_SECONDARY)
            HandleUnLearnSkillRecipesHelper(m_session->GetPlayer(), skillInfo->id);
    }

    // Some of these are removed for some reason.
    m_session->GetPlayer()->LearnDefaultSpells();

    SendSysMessage("You have forgotten all crafts.");
    return true;
}

SkillLineEntry const* ChatHandler::FindSkillLineEntryFromProfessionName(char* args, std::string& nameOut)
{
    if (!*args)
        return nullptr;

    std::wstring wnamepart;

    if (!Utf8toWStr(args, wnamepart))
        return nullptr;

    // converting string that we try to find to lower case
    wstrToLower(wnamepart);

    SkillLineEntry const* targetSkillInfo = nullptr;
    for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
    {
        SkillLineEntry const* skillInfo = sSkillLineStore.LookupEntry(i);
        if (!skillInfo)
            continue;

        if (skillInfo->categoryId != SKILL_CATEGORY_PROFESSION && skillInfo->categoryId != SKILL_CATEGORY_SECONDARY)
            continue;

        int loc = GetSessionDbcLocale();
        nameOut = skillInfo->name[loc];
        if (nameOut.empty())
            continue;

        if (!Utf8FitTo(nameOut, wnamepart))
        {
            loc = 0;
            for (; loc < MAX_DBC_LOCALE; ++loc)
            {
                if (loc == GetSessionDbcLocale())
                    continue;

                nameOut = skillInfo->name[loc];
                if (nameOut.empty())
                    continue;

                if (Utf8FitTo(nameOut, wnamepart))
                    break;
            }
        }

        if (loc < MAX_DBC_LOCALE)
        {
            targetSkillInfo = skillInfo;
            break;
        }
    }

    return targetSkillInfo;
}

bool ChatHandler::HandleLearnAllRecipesCommand(char* args)
{
    //  Learns all recipes of specified profession and sets skill to max
    //  Example: .learn all_recipes enchanting

    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        return false;
    }

    std::string name;
    SkillLineEntry const* targetSkillInfo = FindSkillLineEntryFromProfessionName(args, name);
    if (!targetSkillInfo)
        return false;

    HandleLearnSkillRecipesHelper(target, targetSkillInfo->id);

    uint16 maxLevel = target->GetSkillMaxPure(targetSkillInfo->id);
    target->SetSkill(targetSkillInfo->id, maxLevel, maxLevel);
    PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, name.c_str());
    return true;
}

bool ChatHandler::HandleUnLearnAllRecipesCommand(char* args)
{
    //  Unlearns all recipes of specified profession
    //  Example: .unlearn all_recipes enchanting

    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        return false;
    }

    std::string name;
    SkillLineEntry const* targetSkillInfo = FindSkillLineEntryFromProfessionName(args, name);
    if (!targetSkillInfo)
        return false;

    HandleUnLearnSkillRecipesHelper(target, targetSkillInfo->id);

    PSendSysMessage("%s has forgotten all %s recipes.", target->GetName(), name.c_str());
    return true;
}

bool ChatHandler::HandleLearnCommand(char* args)
{
    Player* player = m_session->GetPlayer();
    Player* targetPlayer = GetSelectedPlayer();

    if (!targetPlayer)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
    uint32 spell = ExtractSpellIdFromLink(&args);
    if (!spell || !sSpellMgr.GetSpellEntry(spell))
        return false;

    bool allRanks = ExtractLiteralArg(&args, "all") != nullptr;
    if (!allRanks && *args)                                 // can be fail also at syntax error
        return false;

    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spell);
    if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player))
    {
        PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spell);
        SetSentErrorMessage(true);
        return false;
    }

    if (!allRanks && targetPlayer->HasSpell(spell))
    {
        if (targetPlayer == player)
            SendSysMessage(LANG_YOU_KNOWN_SPELL);
        else
            PSendSysMessage(LANG_TARGET_KNOWN_SPELL, targetPlayer->GetName());
        SetSentErrorMessage(true);
        return false;
    }

    if (allRanks)
        targetPlayer->LearnSpellHighRank(spell);
    else
        targetPlayer->LearnSpell(spell, false);

    return true;
}

bool ChatHandler::HandleItemMoveCommand(char* args)
{
    if (!*args)
        return false;
    uint8 srcslot, dstslot;

    char* pParam1 = strtok(args, " ");
    if (!pParam1)
        return false;

    char* pParam2 = strtok(nullptr, " ");
    if (!pParam2)
        return false;

    srcslot = (uint8)atoi(pParam1);
    dstslot = (uint8)atoi(pParam2);

    if (srcslot == dstslot)
        return true;

    Player* pPlayer = m_session->GetPlayer();
    if (!pPlayer->IsValidPos(INVENTORY_SLOT_BAG_0, srcslot, true))
        return false;

    // can be autostore pos
    if (!pPlayer->IsValidPos(INVENTORY_SLOT_BAG_0, dstslot, false))
        return false;

    uint16 src = ((INVENTORY_SLOT_BAG_0 << 8) | srcslot);
    uint16 dst = ((INVENTORY_SLOT_BAG_0 << 8) | dstslot);

    pPlayer->SwapItem(src, dst);

    return true;
}

bool ChatHandler::HandleAddItemCommand(char* args)
{
    char* cId = ExtractKeyFromLink(&args, "Hitem");
    if (!cId)
        return false;

    uint32 itemId = 0;
    if (!ExtractUInt32(&cId, itemId))                       // [name] manual form
    {
        std::string itemName = cId;
        WorldDatabase.escape_string(itemName);
        QueryResult* result = WorldDatabase.PQuery("SELECT `entry` FROM `item_template` WHERE `name` = '%s'", itemName.c_str());
        if (!result)
        {
            PSendSysMessage(LANG_COMMAND_COULDNOTFIND, cId);
            SetSentErrorMessage(true);
            return false;
        }
        itemId = result->Fetch()->GetUInt16();
        delete result;
    }

    int32 count;
    if (!ExtractOptInt32(&args, count, 1))
        return false;

    Player* pl = m_session->GetPlayer();
    Player* plTarget = GetSelectedPlayer();
    if (!plTarget)
        plTarget = pl;

    DETAIL_LOG(GetMangosString(LANG_ADDITEM), itemId, count);

    if (!ObjectMgr::GetItemPrototype(itemId))
    {
        PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
        SetSentErrorMessage(true);
        return false;
    }

    //Subtract
    if (count < 0)
    {
        // Is the item actually?
        if (!plTarget->HasItemCount(itemId, -count, true))
        {
            PSendSysMessage("Le joueur a l'objet %ux%u. Ne peut en retirer %u. Banque inclue.", itemId, plTarget->GetItemCount(itemId, true), -count);
            SetSentErrorMessage(true);
            return false;
        }
        plTarget->DestroyItemCount(itemId, -count, true, false);
        PSendSysMessage(LANG_REMOVEITEM, itemId, -count, GetNameLink(plTarget).c_str());
        return true;
    }

    //Adding items
    uint32 noSpaceForCount = 0;

    // check space and find places
    ItemPosCountVec dest;
    uint8 msg = plTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, count, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)                                // convert to possible store amount
        count -= noSpaceForCount;

    if (count == 0 || dest.empty())                         // can't add any
    {
        PSendSysMessage(LANG_ITEM_CANNOT_CREATE, itemId, noSpaceForCount);
        SetSentErrorMessage(true);
        return false;
    }

    Item* item = plTarget->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));

    // remove binding (let GM give it to another player later)
    if (pl == plTarget)
        for (const auto& itr : dest)
            if (Item* item1 = pl->GetItemByPos(itr.pos))
                item1->SetBinding(false);

    if (count > 0 && item)
    {
        pl->SendNewItem(item, count, false, true);
        if (pl != plTarget)
            plTarget->SendNewItem(item, count, true, false);
    }

    if (noSpaceForCount > 0)
        PSendSysMessage(LANG_ITEM_CANNOT_CREATE, itemId, noSpaceForCount);

    return true;
}

bool ChatHandler::HandleDeleteItemCommand(char* args)
{
    char* cId = ExtractKeyFromLink(&args, "Hitem");

    if (!cId)
    {
        return false;
    }

    uint32 itemId = 0;

    if (!ExtractUInt32(&cId, itemId))
    {
        std::string itemName = cId;
        WorldDatabase.escape_string(itemName);

        std::unique_ptr<QueryResult> result(WorldDatabase.PQuery("SELECT `entry` FROM `item_template` WHERE `name` = '%s'", itemName.c_str()));

        if (!result)
        {
            PSendSysMessage(LANG_COMMAND_COULDNOTFIND, cId);
            SetSentErrorMessage(true);
            return false;
        }

        itemId = result->Fetch()->GetUInt16();
    }

    uint32 count;

    if (!ExtractOptUInt32(&args, count, 1))
    {
        return false;
    }

    Player* player;
    ObjectGuid target_guid;
    std::string target_name;

    if (!ExtractPlayerTarget(&args, &player, &target_guid, &target_name))
    {
        return false;
    }

    DETAIL_LOG(GetMangosString(LANG_REMOVEITEM), itemId, count);

    if (player)
    {
        if (!player->HasItemCount(itemId, count, true))
        {
            PSendSysMessage("Cannot remove %u instances of %u - maximum value is %u", count, itemId, player->GetItemCount(itemId, true));
            SetSentErrorMessage(true);
            return false;
        }

        player->DestroyItemCount(itemId, count, true, false, true);
        player->SaveInventoryAndGoldToDB();
    }
    else
    {
        std::unique_ptr<QueryResult> result(CharacterDatabase.PQuery(
            "SELECT SUM(`count`) AS item_count FROM `item_instance` ii WHERE `item_id` = %u and `owner_guid` = %u",
            itemId, target_guid.GetCounter()
        ));

        uint32 maxItemCount = 0;

        if (result)
        {
            auto fields = result->Fetch();
            maxItemCount = fields[0].GetUInt32();
        }

        if (count > maxItemCount)
        {
            PSendSysMessage("Cannot remove %u instances of %u - maximum value is %u", count, itemId, maxItemCount);
            SetSentErrorMessage(true);
            return false;
        }

        uint32 stacksToRemove = count;

        while (stacksToRemove)
        {
            result.reset(CharacterDatabase.PQuery(
                "SELECT `guid`, `count` FROM `item_instance` ii WHERE `item_id` = %u and `owner_guid` = %u ORDER BY `count` DESC",
                itemId, target_guid.GetCounter()
            ));

            if (!result)
            {
                SendSysMessage("Encountered an error while attempting to locate items to remove - race condition?");
                SetSentErrorMessage(true);
                return false;
            }

            auto fields = result->Fetch();
            auto guid = fields[0].GetUInt32();
            auto stackCount = fields[1].GetUInt32();

            if (stackCount > stacksToRemove) // make sure we don't delete more than requested
            {
                if (!CharacterDatabase.PExecute("UPDATE `item_instance` SET `count` = %u WHERE `guid` = %u",
                    stackCount - stacksToRemove, guid))
                {
                    SendSysMessage("Encountered an error while attempting to adjust item stack count");
                    SetSentErrorMessage(true);
                    return false;
                }

                break;
            }
            else
            {
                if (!CharacterDatabase.DirectPExecute("DELETE FROM `item_instance` WHERE `guid` = %u", guid))
                {
                    SendSysMessage("Encountered an error while attempting to remove item instance");
                    SetSentErrorMessage(true);
                    return false;
                }
                
                if (!CharacterDatabase.DirectPExecute("DELETE FROM `character_inventory` WHERE `item_guid` = %u", guid))
                {
                    SendSysMessage("Encountered an error while attempting to remove item from inventory");
                    SetSentErrorMessage(true);
                    return false;
                }

                if (!CharacterDatabase.DirectPExecute("DELETE FROM `character_gifts` WHERE `item_guid` = %u", guid))
                {
                    SendSysMessage("Encountered an error while attempting to remove item from gifts");
                    SetSentErrorMessage(true);
                    return false;
                }

                if (!CharacterDatabase.DirectPExecute("DELETE FROM `mail_items` WHERE `item_guid` = %u", guid))
                {
                    SendSysMessage("Encountered an error while attempting to remove item from mail");
                    SetSentErrorMessage(true);
                    return false;
                }

                stacksToRemove -= stackCount;
            }
        }
    }

    PSendSysMessage(LANG_REMOVEITEM, itemId, count, target_name.c_str());
    return true;
}

bool ChatHandler::HandleAddItemSetCommand(char* args)
{
    uint32 itemsetId;
    if (!ExtractUint32KeyFromLink(&args, "Hitemset", itemsetId))
        return false;

    // prevent generation all items with itemset field value '0'
    if (itemsetId == 0)
    {
        PSendSysMessage(LANG_NO_ITEMS_FROM_ITEMSET_FOUND, itemsetId);
        SetSentErrorMessage(true);
        return false;
    }

    Player* pl = m_session->GetPlayer();
    Player* plTarget = GetSelectedPlayer();
    if (!plTarget)
        plTarget = pl;

    DETAIL_LOG(GetMangosString(LANG_ADDITEMSET), itemsetId);

    bool found = false;
    for (uint32 id = 0; id < sItemStorage.GetMaxEntry(); id++)
    {
        ItemPrototype const* pProto = sItemStorage.LookupEntry<ItemPrototype>(id);
        if (!pProto)
            continue;

        if (pProto->ItemSet == itemsetId)
        {
            found = true;
            ItemPosCountVec dest;
            InventoryResult msg = plTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, pProto->ItemId, 1);
            if (msg == EQUIP_ERR_OK)
            {
                Item* item = plTarget->StoreNewItem(dest, pProto->ItemId, true);

                // remove binding (let GM give it to another player later)
                if (pl == plTarget)
                    item->SetBinding(false);

                pl->SendNewItem(item, 1, false, true);
                if (pl != plTarget)
                    plTarget->SendNewItem(item, 1, true, false);
            }
            else
            {
                pl->SendEquipError(msg, nullptr, nullptr, pProto->ItemId);
                PSendSysMessage(LANG_ITEM_CANNOT_CREATE, pProto->ItemId, 1);
            }
        }
    }

    if (!found)
    {
        PSendSysMessage(LANG_NO_ITEMS_FROM_ITEMSET_FOUND, itemsetId);

        SetSentErrorMessage(true);
        return false;
    }

    return true;
}

bool ChatHandler::HandleListItemCommand(char* args)
{
    uint32 item_id;
    if (!ExtractUint32KeyFromLink(&args, "Hitem", item_id))
        return false;

    if (!item_id)
    {
        PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, item_id);
        SetSentErrorMessage(true);
        return false;
    }

    ItemPrototype const* itemProto = ObjectMgr::GetItemPrototype(item_id);
    if (!itemProto)
    {
        PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, item_id);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 count;
    if (!ExtractOptUInt32(&args, count, 10))
        return false;

    QueryResult* result;

    // inventory case
    uint32 inv_count = 0;
    result = CharacterDatabase.PQuery("SELECT COUNT(`item_id`) FROM `character_inventory` WHERE `item_id`='%u'", item_id);
    if (result)
    {
        inv_count = (*result)[0].GetUInt32();
        delete result;
    }

    result = CharacterDatabase.PQuery(
                 //          0                  1                 2          3                    4                       5
                 "SELECT ci.`item_guid`, cibag.`slot` AS bag, ci.`slot`, ci.`guid`, `characters`.`account`, `characters`.`name` "
                 "FROM `character_inventory` AS ci LEFT JOIN `character_inventory` AS cibag ON (cibag.`item_guid`=ci.`bag`), `characters` "
                 "WHERE ci.`item_id`='%u' AND ci.`guid` = `characters`.`guid` LIMIT %u ",
                 item_id, uint32(count));

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 item_guid = fields[0].GetUInt32();
            uint32 item_bag = fields[1].GetUInt32();
            uint32 item_slot = fields[2].GetUInt32();
            uint32 owner_guid = fields[3].GetUInt32();
            uint32 owner_acc = fields[4].GetUInt32();
            std::string owner_name = fields[5].GetCppString();

            char const* item_pos = 0;
            if (Player::IsEquipmentPos(item_bag, item_slot))
                item_pos = "[equipped]";
            else if (Player::IsInventoryPos(item_bag, item_slot))
                item_pos = "[in inventory]";
            else if (Player::IsBankPos(item_bag, item_slot))
                item_pos = "[in bank]";
            else
                item_pos = "";

            PSendSysMessage(LANG_ITEMLIST_SLOT,
                            item_guid, owner_name.c_str(), owner_guid, owner_acc, item_pos);
        }
        while (result->NextRow());

        uint32 res_count = uint32(result->GetRowCount());

        delete result;

        if (count > res_count)
            count -= res_count;
        else if (count)
            count = 0;
    }

    // mail case
    uint32 mail_count = 0;
    result = CharacterDatabase.PQuery("SELECT COUNT(`item_id`) FROM `mail_items` WHERE `item_id`='%u'", item_id);
    if (result)
    {
        mail_count = (*result)[0].GetUInt32();
        delete result;
    }

    if (count > 0)
    {
        result = CharacterDatabase.PQuery(
                     //                    0                   1                     2                  3                 4              5                 6
                     "SELECT `mail_items`.`item_guid`, `mail`.`sender_guid`, `mail`.`receiver_guid`, char_s.`account`, char_s.`name`, char_r.`account`, char_r.`name` "
                     "FROM `mail`, `mail_items`, `characters` as char_s, `characters` as char_r "
                     "WHERE `mail_items`.`item_id`='%u' AND char_s.`guid` = `mail`.`sender_guid` AND char_r.`guid` = `mail`.`receiver_guid` AND `mail`.`id`=`mail_items`.`mail_id` LIMIT %u",
                     item_id, uint32(count));
    }
    else
        result = nullptr;

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 item_guid        = fields[0].GetUInt32();
            uint32 item_s           = fields[1].GetUInt32();
            uint32 item_r           = fields[2].GetUInt32();
            uint32 item_s_acc       = fields[3].GetUInt32();
            std::string item_s_name = fields[4].GetCppString();
            uint32 item_r_acc       = fields[5].GetUInt32();
            std::string item_r_name = fields[6].GetCppString();

            char const* item_pos = "[in mail]";

            PSendSysMessage(LANG_ITEMLIST_MAIL,
                            item_guid, item_s_name.c_str(), item_s, item_s_acc, item_r_name.c_str(), item_r, item_r_acc, item_pos);
        }
        while (result->NextRow());

        uint32 res_count = uint32(result->GetRowCount());

        delete result;

        if (count > res_count)
            count -= res_count;
        else if (count)
            count = 0;
    }

    // auction case
    uint32 auc_count = 0;
    result = CharacterDatabase.PQuery("SELECT COUNT(`item_id`) FROM `auction` WHERE `item_id`='%u'", item_id);
    if (result)
    {
        auc_count = (*result)[0].GetUInt32();
        delete result;
    }

    if (count > 0)
    {
        result = CharacterDatabase.PQuery(
                     //                  0                      1                           2                       3
                     "SELECT  `auction`.`item_guid`, `auction`.`seller_guid`, `characters`.`account`, `characters`.`name` "
                     "FROM `auction`, `characters` WHERE `auction`.`item_id`='%u' AND `characters`.`guid` = `auction`.`seller_guid` LIMIT %u",
                     item_id, uint32(count));
    }
    else
        result = nullptr;

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 item_guid       = fields[0].GetUInt32();
            uint32 owner           = fields[1].GetUInt32();
            uint32 owner_acc       = fields[2].GetUInt32();
            std::string owner_name = fields[3].GetCppString();

            char const* item_pos = "[in auction]";

            PSendSysMessage(LANG_ITEMLIST_AUCTION, item_guid, owner_name.c_str(), owner, owner_acc, item_pos);
        }
        while (result->NextRow());

        delete result;
    }

    if (inv_count + mail_count + auc_count == 0)
    {
        SendSysMessage(LANG_COMMAND_NOITEMFOUND);
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_COMMAND_LISTITEMMESSAGE, item_id, inv_count + mail_count + auc_count, inv_count, mail_count, auc_count);

    return true;
}


bool ChatHandler::HandleListTalentsCommand(char* /*args*/)
{
    Player* player = GetSelectedPlayer();
    if (!player)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    SendSysMessage(LANG_LIST_TALENTS_TITLE);
    uint32 count = 0;
    uint32 cost = 0;
    PlayerSpellMap const& uSpells = player->GetSpellMap();
    for (const auto& itr : uSpells)
    {
        if (itr.second.state == PLAYERSPELL_REMOVED || itr.second.disabled)
            continue;

        uint32 cost_itr = GetTalentSpellCost(itr.first);

        if (cost_itr == 0)
            continue;

        SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(itr.first);
        if (!spellEntry)
            continue;

        ShowSpellListHelper(player, spellEntry, GetSessionDbcLocale());
        ++count;
        cost += cost_itr;
    }
    PSendSysMessage(LANG_LIST_TALENTS_COUNT, count, cost);

    return true;
}

bool ChatHandler::HandleResetHonorCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    target->GetHonorMgr().Reset();
    return true;
}

static bool HandleResetStatsOrLevelHelper(Player* player)
{
    ChrClassesEntry const* cEntry = sChrClassesStore.LookupEntry(player->GetClass());
    if (!cEntry)
    {
        sLog.outError("Class %u not found in DBC (Wrong DBC files?)", player->GetClass());
        return false;
    }

    uint8 powertype = cEntry->powerType;

    // reset m_form if no aura
    if (!player->HasAuraType(SPELL_AURA_MOD_SHAPESHIFT))
        player->SetShapeshiftForm(FORM_NONE);

    player->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, DEFAULT_WORLD_OBJECT_SIZE);
    player->SetFloatValue(UNIT_FIELD_COMBATREACH, 1.5f);

    player->SetFactionForRace(player->GetRace());

    player->SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_POWER_TYPE, powertype);

    // reset only if player not in some form;
    if (player->GetShapeshiftForm() == FORM_NONE)
        player->InitPlayerDisplayIds();

    // is it need, only in pre-2.x used and field byte removed later?
    if (powertype == POWER_RAGE || powertype == POWER_MANA)
        player->SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_PET_LOYALTY, 0xEE);

    player->SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_MISC_FLAGS, UNIT_BYTE2_FLAG_UNK3 | UNIT_BYTE2_FLAG_UNK5);

    player->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    //-1 is default value
    player->SetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, -1);
#endif

    //player->SetUInt32Value(PLAYER_FIELD_BYTES, 0xEEE00000);
    return true;
}

bool ChatHandler::HandleResetLevelCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    if (!HandleResetStatsOrLevelHelper(target))
        return false;

    // set starting level
    uint32 start_level = sWorld.getConfig(CONFIG_UINT32_START_PLAYER_LEVEL);

    target->SetLevel(start_level);
    target->InitStatsForLevel(true);
    target->InitTaxiNodes();
    target->InitTalentForLevel();
    target->SetUInt32Value(PLAYER_XP, 0);

    // reset level for pet
    if (Pet* pet = target->GetPet())
        pet->SynchronizeLevelWithOwner();

    return true;
}

bool ChatHandler::HandleResetStatsCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    if (!HandleResetStatsOrLevelHelper(target))
        return false;

    target->InitStatsForLevel(true);
    target->InitTalentForLevel();

    return true;
}

bool ChatHandler::HandleResetSpellsCommand(char* args)
{
    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&args, &target, &target_guid, &target_name))
        return false;

    if (target)
    {
        target->ResetSpells();

        ChatHandler(target).SendSysMessage(LANG_RESET_SPELLS);
        if (!m_session || m_session->GetPlayer() != target)
            PSendSysMessage(LANG_RESET_SPELLS_ONLINE, GetNameLink(target).c_str());
    }
    else
    {
        CharacterDatabase.PExecute("UPDATE `characters` SET `at_login_flags` = `at_login_flags` | '%u' WHERE `guid` = '%u'", uint32(AT_LOGIN_RESET_SPELLS), target_guid.GetCounter());
        PSendSysMessage(LANG_RESET_SPELLS_OFFLINE, target_name.c_str());
    }

    return true;
}

bool ChatHandler::HandleResetTalentsCommand(char* args)
{
    Player* target;
    ObjectGuid target_guid;
    std::string target_name;
    if (!ExtractPlayerTarget(&args, &target, &target_guid, &target_name))
        return false;

    if (target)
    {
        target->ResetTalents(true);

        ChatHandler(target).SendSysMessage(LANG_RESET_TALENTS);
        if (!m_session || m_session->GetPlayer() != target)
            PSendSysMessage(LANG_RESET_TALENTS_ONLINE, GetNameLink(target).c_str());
    }
    else if (target_guid)
    {
        uint32 at_flags = AT_LOGIN_RESET_TALENTS;
        CharacterDatabase.PExecute("UPDATE `characters` SET `at_login_flags` = `at_login_flags` | '%u' WHERE `guid` = '%u'", at_flags, target_guid.GetCounter());
        std::string nameLink = playerLink(target_name);
        PSendSysMessage(LANG_RESET_TALENTS_OFFLINE, nameLink.c_str());
    }

    return true;
}

bool ChatHandler::HandleResetItemsCommand(char* args)
{
    Player* pTarget;
    ObjectGuid targetGuid;
    std::string targetName;
    if (!ExtractPlayerTarget(&args, &pTarget, &targetGuid, &targetName))
        return false;

    if (!pTarget)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 count = 0;
    for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
    {
        if (Item* pItem = pTarget->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            pTarget->DestroyItem(INVENTORY_SLOT_BAG_0, i, true);
            ++count;
        }
    }
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        if (Item* pItem = pTarget->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            pTarget->DestroyItem(INVENTORY_SLOT_BAG_0, i, true);
            ++count;
        }
    }
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = (Bag*)pTarget->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item* pItem = pBag->GetItemByPos(j))
                {
                    pTarget->DestroyItem(i, j, true);
                    ++count;
                }
            }
        }
    }

    PSendSysMessage("Removed all items from %s.", targetName.c_str());
    return true;
}

bool ChatHandler::HandleResetAllCommand(char* args)
{
    if (!*args)
        return false;

    std::string casename = args;

    AtLoginFlags atLogin;

    // Command specially created as single command to prevent using short case names
    if (casename == "spells")
    {
        atLogin = AT_LOGIN_RESET_SPELLS;
        sWorld.SendWorldText(LANG_RESETALL_SPELLS);
        if (!m_session)
            SendSysMessage(LANG_RESETALL_SPELLS);
    }
    else if (casename == "talents")
    {
        atLogin = AT_LOGIN_RESET_TALENTS;
        sWorld.SendWorldText(LANG_RESETALL_TALENTS);
        if (!m_session)
            SendSysMessage(LANG_RESETALL_TALENTS);
    }
    else
    {
        PSendSysMessage(LANG_RESETALL_UNKNOWN_CASE, args);
        SetSentErrorMessage(true);
        return false;
    }

    CharacterDatabase.PExecute("UPDATE `characters` SET `at_login_flags` = `at_login_flags` | '%u' WHERE (`at_login_flags` & '%u') = '0'", atLogin, atLogin);
    HashMapHolder<Player>::MapType const& plist = sObjectAccessor.GetPlayers();
    for (const auto& itr : plist)
        itr.second->SetAtLoginFlag(atLogin);

    return true;
}

bool ChatHandler::HandleModifyBlockCommand(char *args)
{
    if (!*args)
        return false;

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    float amount;
    if (!ExtractFloat(&args, amount))
        return false;

    if (amount < 0 || amount > 100)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    player->SetStatFloatValue(PLAYER_BLOCK_PERCENTAGE, amount);

    PSendSysMessage(LANG_YOU_CHANGE_BLOCK, player->GetName(), amount);

    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOURS_BLOCK_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyDodgeCommand(char *args)
{
    if (!*args)
        return false;

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    float amount;
    if (!ExtractFloat(&args, amount))
        return false;

    if (amount < 0 || amount > 100)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    player->SetStatFloatValue(PLAYER_DODGE_PERCENTAGE, amount);

    PSendSysMessage(LANG_YOU_CHANGE_DODGE, player->GetName(), amount);

    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOURS_DODGE_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyParryCommand(char *args)
{
    if (!*args)
        return false;

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    float amount;
    if (!ExtractFloat(&args, amount))
        return false;

    if (amount < 0 || amount > 100)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    player->SetStatFloatValue(PLAYER_PARRY_PERCENTAGE, amount);

    PSendSysMessage(LANG_YOU_CHANGE_PARRY, player->GetName(), amount);

    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOURS_PARRY_CHANGED, GetNameLink().c_str(), amount);

    return true;
}


bool ChatHandler::HandleModifyMeleeCritCommand(char *args)
{
    if (!*args)
        return false;

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    float amount;
    if (!ExtractFloat(&args, amount))
        return false;

    if (amount < 0 || amount > 100)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    player->SetStatFloatValue(PLAYER_CRIT_PERCENTAGE, amount);

    PSendSysMessage(LANG_YOU_CHANGE_MCRIT, player->GetName(), amount);

    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOURS_MCRIT_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyRangedCritCommand(char *args)
{
    if (!*args)
        return false;

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    float amount;
    if (!ExtractFloat(&args, amount))
        return false;

    if (amount < 0 || amount > 100)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    player->SetStatFloatValue(PLAYER_RANGED_CRIT_PERCENTAGE, amount);

    PSendSysMessage(LANG_YOU_CHANGE_RCRIT, player->GetName(), amount);

    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOURS_RCRIT_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifySpellCritCommand(char *args)
{
    if (!*args)
        return false;

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    float amount;
    if (!ExtractFloat(&args, amount))
        return false;

    if (amount < 0 || amount > 100)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    player->SetSpellCritPercent(SPELL_SCHOOL_NORMAL, amount);
    player->SetSpellCritPercent(SPELL_SCHOOL_HOLY, amount);
    player->SetSpellCritPercent(SPELL_SCHOOL_FIRE, amount);
    player->SetSpellCritPercent(SPELL_SCHOOL_NATURE, amount);
    player->SetSpellCritPercent(SPELL_SCHOOL_FROST, amount);
    player->SetSpellCritPercent(SPELL_SCHOOL_SHADOW, amount);
    player->SetSpellCritPercent(SPELL_SCHOOL_ARCANE, amount);

    PSendSysMessage(LANG_YOU_CHANGE_SCRIT, player->GetName(), amount);

    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOURS_SCRIT_CHANGED, GetNameLink().c_str(), amount);

    return true;
}

bool ChatHandler::HandleModifyGenderCommand(char *args)
{
    if (!*args)
        return false;

    Player* player = GetSelectedPlayer();

    if (!player)
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    PlayerInfo const* info = sObjectMgr.GetPlayerInfo(player->GetRace(), player->GetClass());
    if (!info)
        return false;

    char* gender_str = args;
    int gender_len = strlen(gender_str);

    Gender gender;

    if (!strncmp(gender_str, "male", gender_len))            // MALE
    {
        if (player->GetGender() == GENDER_MALE)
            return true;

        gender = GENDER_MALE;
    }
    else if (!strncmp(gender_str, "female", gender_len))    // FEMALE
    {
        if (player->GetGender() == GENDER_FEMALE)
            return true;

        gender = GENDER_FEMALE;
    }
    else
    {
        SendSysMessage(LANG_MUST_MALE_OR_FEMALE);
        SetSentErrorMessage(true);
        return false;
    }

    // Set gender
    player->SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, gender);
    player->SetUInt16Value(PLAYER_BYTES_3, 0, uint16(gender) | (player->GetDrunkValue() & 0xFFFE));

    // Change display ID
    player->InitPlayerDisplayIds();

    char const* gender_full = gender ? "female" : "male";

    PSendSysMessage(LANG_YOU_CHANGE_GENDER, player->GetName(), gender_full);

    if (needReportToTarget(player))
        ChatHandler(player).PSendSysMessage(LANG_YOUR_GENDER_CHANGED, gender_full, GetNameLink().c_str());

    return true;
}

bool ChatHandler::HandleModifyDrunkCommand(char* args)
{
    if (!*args)
        return false;

    Player* target =  GetSelectedPlayer();

    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 drunklevel = (uint32)atoi(args);
    if (drunklevel > 100)
        drunklevel = 100;

    uint16 drunkMod = drunklevel * 0xFFFF / 100;

    target->SetDrunkValue(drunkMod);

    return true;
}

bool ChatHandler::HandleModifyExhaustionCommand(char* args)
{
    if (!*args)
        return false;

    uint32 exhaustion_state = (uint32)atoi(args);
    Player* target = GetSelectedPlayer();

    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    target->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_PARTIAL_PLAY_TIME);
    target->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_PLAY_TIME);

    switch (exhaustion_state)
    {
        case 0: break;
        case 1: target->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_NO_PLAY_TIME); break;
        case 2: target->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_PARTIAL_PLAY_TIME); break;
    }
    return true;
}

static uint32 ReputationRankStrIndex[MAX_REPUTATION_RANK] =
{
    LANG_REP_HATED,    LANG_REP_HOSTILE, LANG_REP_UNFRIENDLY, LANG_REP_NEUTRAL,
    LANG_REP_FRIENDLY, LANG_REP_HONORED, LANG_REP_REVERED,    LANG_REP_EXALTED
};

bool ChatHandler::HandleModifyRepCommand(char* args)
{
    if (!*args)
        return false;

    Player* target = GetSelectedPlayer();

    if (!target)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target))
        return false;

    uint32 factionId;
    if (!ExtractUint32KeyFromLink(&args, "Hfaction", factionId))
        return false;

    if (!factionId)
        return false;

    int32 amount = 0;
    if (!ExtractInt32(&args, amount))
    {
        char *rankTxt = ExtractLiteralArg(&args);
        if (!rankTxt)
            return false;

        std::string rankStr = rankTxt;
        std::wstring wrankStr;
        if (!Utf8toWStr(rankStr, wrankStr))
            return false;
        wstrToLower(wrankStr);

        int r = 0;
        amount = -42000;
        for (; r < MAX_REPUTATION_RANK; ++r)
        {
            std::string rank = GetMangosString(ReputationRankStrIndex[r]);
            if (rank.empty())
                continue;

            std::wstring wrank;
            if (!Utf8toWStr(rank, wrank))
                continue;

            wstrToLower(wrank);

            if (wrank.substr(0, wrankStr.size()) == wrankStr)
            {
                int32 delta;
                if (!ExtractOptInt32(&args, delta, 0) || (delta < 0) || (delta > ReputationMgr::PointsInRank[r] - 1))
                {
                    PSendSysMessage(LANG_COMMAND_FACTION_DELTA, (ReputationMgr::PointsInRank[r] - 1));
                    SetSentErrorMessage(true);
                    return false;
                }
                amount += delta;
                break;
            }
            amount += ReputationMgr::PointsInRank[r];
        }
        if (r >= MAX_REPUTATION_RANK)
        {
            PSendSysMessage(LANG_COMMAND_FACTION_INVPARAM, rankTxt);
            SetSentErrorMessage(true);
            return false;
        }
    }

    FactionEntry const* factionEntry = sObjectMgr.GetFactionEntry(factionId);

    if (!factionEntry)
    {
        PSendSysMessage(LANG_COMMAND_FACTION_UNKNOWN, factionId);
        SetSentErrorMessage(true);
        return false;
    }

    if (factionEntry->reputationListID < 0)
    {
        PSendSysMessage(LANG_COMMAND_FACTION_NOREP_ERROR, factionEntry->name[GetSessionDbcLocale()].c_str(), factionId);
        SetSentErrorMessage(true);
        return false;
    }

    target->GetReputationMgr().SetReputation(factionEntry, amount);
    PSendSysMessage(LANG_COMMAND_MODIFY_REP, factionEntry->name[GetSessionDbcLocale()].c_str(), factionId,
                    GetNameLink(target).c_str(), target->GetReputationMgr().GetReputation(factionEntry));
    return true;
}

bool ChatHandler::HandleModifyMountCommand(char* args)
{
    if (!*args)
        return false;

    uint32 mountId = atoi(args);
    
    if (!sObjectMgr.GetCreatureDisplayInfoAddon(mountId))
    {
        SendSysMessage(LANG_NO_MOUNT);
        SetSentErrorMessage(true);
        return false;
    }

    Player* pPlayer = GetSelectedPlayer();
    if (!pPlayer)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(pPlayer))
        return false;

    pPlayer->Mount(mountId);

    PSendSysMessage(LANG_YOU_GIVE_MOUNT, GetNameLink(pPlayer).c_str());
    if (needReportToTarget(pPlayer))
        ChatHandler(pPlayer).PSendSysMessage(LANG_MOUNT_GIVED, GetNameLink().c_str());

    return true;
}

bool ChatHandler::HandleModifyMoneyCommand(char* args)
{
    if (!*args)
        return false;

    Player* chr = GetSelectedPlayer();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(chr))
        return false;

    int32 addmoney = atoi(args);

    uint32 moneyuser = chr->GetMoney();

    if (addmoney < 0)
    {
        int32 newmoney = int32(moneyuser) + addmoney;

        DETAIL_LOG(GetMangosString(LANG_CURRENT_MONEY), moneyuser, addmoney, newmoney);
        if (newmoney <= 0)
        {
            PSendSysMessage(LANG_YOU_TAKE_ALL_MONEY, GetNameLink(chr).c_str());
            if (needReportToTarget(chr))
                ChatHandler(chr).PSendSysMessage(LANG_YOURS_ALL_MONEY_GONE, GetNameLink().c_str());

            chr->SetMoney(0);
        }
        else
        {
            if (newmoney > MAX_MONEY_AMOUNT)
                newmoney = MAX_MONEY_AMOUNT;

            PSendSysMessage(LANG_YOU_TAKE_MONEY, abs(addmoney), GetNameLink(chr).c_str());
            if (needReportToTarget(chr))
                ChatHandler(chr).PSendSysMessage(LANG_YOURS_MONEY_TAKEN, GetNameLink().c_str(), abs(addmoney));
            chr->SetMoney(newmoney);
        }
    }
    else
    {
        PSendSysMessage(LANG_YOU_GIVE_MONEY, addmoney, GetNameLink(chr).c_str());
        if (needReportToTarget(chr))
            ChatHandler(chr).PSendSysMessage(LANG_YOURS_MONEY_GIVEN, GetNameLink().c_str(), addmoney);

        if (addmoney >= MAX_MONEY_AMOUNT)
            chr->SetMoney(MAX_MONEY_AMOUNT);
        else
            chr->LogModifyMoney(addmoney, "GM", m_session->GetPlayer()->GetObjectGuid());
    }

    DETAIL_LOG(GetMangosString(LANG_NEW_MONEY), moneyuser, addmoney, chr->GetMoney());

    return true;
}

bool ChatHandler::HandleModifyTalentCommand(char* args)
{
    if (!*args)
        return false;

    int tp = atoi(args);
    if (tp < 0)
        return false;

    Player* target = GetSelectedPlayer();
    if (!target)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(target))
        return false;

    target->SetFreeTalentPoints(tp);
    return true;
}

bool ChatHandler::HandleModifySpeedCommand(char* args)
{
    if (!*args)
        return false;

    float modSpeed = (float)atof(args);

    if (modSpeed > 4.0f && GetAccessLevel() < SEC_BASIC_ADMIN)
        modSpeed = 4.0f;

    if (m_session->IsReplaying())
    {
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        WorldPacket dataForMe(SMSG_FORCE_RUN_SPEED_CHANGE, 18);
        dataForMe << m_session->GetRecorderGuid().WriteAsPacked();
        dataForMe << uint32(0);
#else
        WorldPacket dataForMe(SMSG_FORCE_RUN_SPEED_CHANGE, 14);
        dataForMe << m_session->GetRecorderGuid().WriteAsPacked();
#endif
        dataForMe << float(7 * modSpeed);
        m_session->SendPacket(&dataForMe);
        return true;
    }

    if (modSpeed > 100 || modSpeed < 0.1)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Player* chr = GetSelectedPlayer();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(chr))
        return false;

    std::string chrNameLink = GetNameLink(chr);

    if (chr->IsTaxiFlying())
    {
        PSendSysMessage(LANG_CHAR_IN_FLIGHT, chrNameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_YOU_CHANGE_SPEED, modSpeed, chrNameLink.c_str());
    if (needReportToTarget(chr))
        ChatHandler(chr).PSendSysMessage(LANG_YOURS_SPEED_CHANGED, GetNameLink().c_str(), modSpeed);

    chr->UpdateSpeed(MOVE_RUN, false, modSpeed);

    return true;
}

bool ChatHandler::HandleModifySwimCommand(char* args)
{
    if (!*args)
        return false;

    float modSpeed = (float)atof(args);

    if (modSpeed > 4.0f && GetAccessLevel() < SEC_BASIC_ADMIN)
        modSpeed = 4.0f;

    if (m_session->IsReplaying())
    {
        
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        WorldPacket dataForMe(SMSG_FORCE_SWIM_SPEED_CHANGE, 18);
        dataForMe << m_session->GetRecorderGuid().WriteAsPacked();
        dataForMe << uint32(0);
#else
        WorldPacket dataForMe(SMSG_FORCE_SWIM_SPEED_CHANGE, 14);
        dataForMe << m_session->GetRecorderGuid().WriteAsPacked();
#endif
        dataForMe << float(4.722222f * modSpeed);
        m_session->SendPacket(&dataForMe);
        return true;
    }
    if (modSpeed > 100.0f || modSpeed < 0.01f)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Player* chr = GetSelectedPlayer();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(chr))
        return false;

    std::string chrNameLink = GetNameLink(chr);

    if (chr->IsTaxiFlying())
    {
        PSendSysMessage(LANG_CHAR_IN_FLIGHT, chrNameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_YOU_CHANGE_SWIM_SPEED, modSpeed, chrNameLink.c_str());
    if (needReportToTarget(chr))
        ChatHandler(chr).PSendSysMessage(LANG_YOURS_SWIM_SPEED_CHANGED, GetNameLink().c_str(), modSpeed);

    chr->UpdateSpeed(MOVE_SWIM, false, modSpeed);

    return true;
}

bool ChatHandler::HandleModifyBWalkCommand(char* args)
{
    if (!*args)
        return false;

    float modSpeed = (float)atof(args);

    if (modSpeed > 4.0f && GetAccessLevel() < SEC_BASIC_ADMIN)
        modSpeed = 4.0f;

    if (modSpeed > 100.0f || modSpeed < 0.1f)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Player* chr = GetSelectedPlayer();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(chr))
        return false;

    std::string chrNameLink = GetNameLink(chr);

    if (chr->IsTaxiFlying())
    {
        PSendSysMessage(LANG_CHAR_IN_FLIGHT, chrNameLink.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    PSendSysMessage(LANG_YOU_CHANGE_BACK_SPEED, modSpeed, chrNameLink.c_str());
    if (needReportToTarget(chr))
        ChatHandler(chr).PSendSysMessage(LANG_YOURS_BACK_SPEED_CHANGED, GetNameLink().c_str(), modSpeed);

    chr->UpdateSpeed(MOVE_RUN_BACK, false, modSpeed);

    return true;
}

bool ChatHandler::HandleModifyFlyCommand(char* args)
{
    if (!*args)
        return false;

    float modSpeed = (float)atof(args);

    if (modSpeed > 100.0f || modSpeed < 0.1f)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Player* chr = GetSelectedPlayer();
    if (!chr)
        chr = m_session->GetPlayer();
    if (!chr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(chr))
        return false;

    if (!chr->IsTaxiFlying())
        return false;

    std::string chrNameLink = GetNameLink(chr);

    PSendSysMessage(LANG_YOU_CHANGE_FLY_SPEED, modSpeed, chrNameLink.c_str());
    if (needReportToTarget(chr))
        ChatHandler(chr).PSendSysMessage(LANG_YOURS_FLY_SPEED_CHANGED, GetNameLink().c_str(), modSpeed);

    FlightPathMovementGenerator* flight = (FlightPathMovementGenerator*)(chr->GetMotionMaster()->top());
    flight->Reset(*chr, modSpeed);

    return true;
}

bool ChatHandler::HandleModifyEnergyCommand(char* args)
{
    if (!*args)
        return false;

    int32 energy = atoi(args) * 10;
    int32 energym = atoi(args) * 10;

    if (energy <= 0 || energym <= 0 || energym < energy)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Player* chr = GetSelectedPlayer();
    if (!chr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(chr))
        return false;

    PSendSysMessage(LANG_YOU_CHANGE_ENERGY, GetNameLink(chr).c_str(), energy / 10, energym / 10);
    if (needReportToTarget(chr))
        ChatHandler(chr).PSendSysMessage(LANG_YOURS_ENERGY_CHANGED, GetNameLink().c_str(), energy / 10, energym / 10);

    chr->SetMaxPower(POWER_ENERGY, energym);
    chr->SetPower(POWER_ENERGY, energy);

    DETAIL_LOG(GetMangosString(LANG_CURRENT_ENERGY), chr->GetMaxPower(POWER_ENERGY));

    return true;
}

bool ChatHandler::HandleModifyRageCommand(char* args)
{
    if (!*args)
        return false;

    int32 rage = atoi(args) * 10;
    int32 ragem = atoi(args) * 10;

    if (rage <= 0 || ragem <= 0 || ragem < rage)
    {
        SendSysMessage(LANG_BAD_VALUE);
        SetSentErrorMessage(true);
        return false;
    }

    Player* chr = GetSelectedPlayer();
    if (chr == nullptr)
    {
        SendSysMessage(LANG_NO_CHAR_SELECTED);
        SetSentErrorMessage(true);
        return false;
    }

    // check online security
    if (HasLowerSecurity(chr))
        return false;

    PSendSysMessage(LANG_YOU_CHANGE_RAGE, GetNameLink(chr).c_str(), rage / 10, ragem / 10);
    if (needReportToTarget(chr))
        ChatHandler(chr).PSendSysMessage(LANG_YOURS_RAGE_CHANGED, GetNameLink().c_str(), rage / 10, ragem / 10);

    chr->SetMaxPower(POWER_RAGE, ragem);
    chr->SetPower(POWER_RAGE, rage);

    return true;
}

// This is the first id in the dbc and exists in all clients.
#define DISPLAY_ID_BOX 4

bool ChatHandler::HandleModifyHairStyleCommand(char* args)
{
    if (!*args)
        return false;

    uint8 hairstyle = (uint8)atoi(args);
    Player* target = GetSelectedPlayer();

    if (!target)
        target = m_session->GetPlayer();

    target->SetByteValue(PLAYER_BYTES, 2, hairstyle);
    target->SetDisplayId(DISPLAY_ID_BOX);
    target->DirectSendPublicValueUpdate(UNIT_FIELD_DISPLAYID);
    target->DeMorph();

    PSendSysMessage("Character's hair style has been changed to: %u", hairstyle);
    return true;
}

bool ChatHandler::HandleModifyHairColorCommand(char* args)
{
    if (!*args)
        return false;

    uint8 haircolor = (uint8)atoi(args);
    Player* target = GetSelectedPlayer();

    if (!target)
        target = m_session->GetPlayer();

    target->SetByteValue(PLAYER_BYTES, 3, haircolor);
    target->SetDisplayId(DISPLAY_ID_BOX);
    target->DirectSendPublicValueUpdate(UNIT_FIELD_DISPLAYID);
    target->DeMorph();

    PSendSysMessage("Character's hair color has been changed to: %u", haircolor);
    return true;
}

bool ChatHandler::HandleModifySkinColorCommand(char* args)
{
    if (!*args)
        return false;

    uint8 skincolor = (uint8)atoi(args);
    Player* target = GetSelectedPlayer();

    if (!target)
        target = m_session->GetPlayer();

    target->SetByteValue(PLAYER_BYTES, 0, skincolor);
    target->SetDisplayId(DISPLAY_ID_BOX);
    target->DirectSendPublicValueUpdate(UNIT_FIELD_DISPLAYID);
    target->DeMorph();

    PSendSysMessage("Character's skin color has been changed to: %u", skincolor);
    return true;
}

bool ChatHandler::HandleModifyAccessoriesCommand(char* args)
{
    if (!*args)
        return false;

    uint8 accessories = (uint8)atoi(args);
    Player* target = GetSelectedPlayer();

    if (!target)
        target = m_session->GetPlayer();

    target->SetByteValue(PLAYER_BYTES_2, 0, accessories);
    target->SetDisplayId(DISPLAY_ID_BOX);
    target->DirectSendPublicValueUpdate(UNIT_FIELD_DISPLAYID);
    target->DeMorph();

    PSendSysMessage("Character's facial hair / markings / hooves have been changed to: %u", accessories);
    return true;
}

bool ChatHandler::HandlePDumpLoadCommand(char *args)
{
    char* file = ExtractQuotedOrLiteralArg(&args);
    if (!file)
        return false;

    std::string account_name;
    uint32 account_id = ExtractAccountId(&args, &account_name);
    if (!account_id)
        return false;

    char* name_str = ExtractLiteralArg(&args);

    uint32 lowguid = 0;
    std::string name;

    if (name_str)
    {
        name = name_str;
        // normalize the name if specified and check if it exists
        if (!normalizePlayerName(name))
        {
            PSendSysMessage(LANG_INVALID_CHARACTER_NAME);
            SetSentErrorMessage(true);
            return false;
        }

        if (ObjectMgr::CheckPlayerName(name, true) != CHAR_NAME_SUCCESS)
        {
            PSendSysMessage(LANG_INVALID_CHARACTER_NAME);
            SetSentErrorMessage(true);
            return false;
        }

        if (*args)
        {
            if (!ExtractUInt32(&args, lowguid))
                return false;

            if (!lowguid)
            {
                PSendSysMessage(LANG_INVALID_CHARACTER_GUID);
                SetSentErrorMessage(true);
                return false;
            }

            ObjectGuid guid = ObjectGuid(HIGHGUID_PLAYER, lowguid);

            if (sObjectMgr.GetPlayerAccountIdByGUID(guid))
            {
                PSendSysMessage(LANG_CHARACTER_GUID_IN_USE, lowguid);
                SetSentErrorMessage(true);
                return false;
            }
        }
    }

    switch (PlayerDumpReader().LoadDump(file, account_id, name, lowguid))
    {
        case DUMP_SUCCESS:
            PSendSysMessage(LANG_COMMAND_IMPORT_SUCCESS);
            break;
        case DUMP_FILE_OPEN_ERROR:
            PSendSysMessage(LANG_FILE_OPEN_FAIL, file);
            SetSentErrorMessage(true);
            return false;
        case DUMP_FILE_BROKEN:
            PSendSysMessage(LANG_DUMP_BROKEN, file);
            SetSentErrorMessage(true);
            return false;
        case DUMP_TOO_MANY_CHARS:
            PSendSysMessage(LANG_ACCOUNT_CHARACTER_LIST_FULL, account_name.c_str(), account_id);
            SetSentErrorMessage(true);
            return false;
        default:
            PSendSysMessage(LANG_COMMAND_IMPORT_FAILED);
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

bool ChatHandler::HandlePDumpWriteCommand(char *args)
{
    if (!*args)
        return false;

    char* file = ExtractQuotedOrLiteralArg(&args);
    if (!file)
        return false;

    char* p2 = ExtractLiteralArg(&args);

    uint32 lowguid;
    ObjectGuid guid;
    // character name can't start from number
    if (!ExtractUInt32(&p2, lowguid))
    {
        std::string name = ExtractPlayerNameFromLink(&p2);
        if (name.empty())
        {
            SendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }

        guid = sObjectMgr.GetPlayerGuidByName(name);
        if (!guid)
        {
            PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            SetSentErrorMessage(true);
            return false;
        }

        lowguid = guid.GetCounter();
    }
    else
        guid = ObjectGuid(HIGHGUID_PLAYER, lowguid);

    if (!sObjectMgr.GetPlayerAccountIdByGUID(guid))
    {
        PSendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    switch (PlayerDumpWriter().WriteDump(file, lowguid))
    {
        case DUMP_SUCCESS:
            PSendSysMessage(LANG_COMMAND_EXPORT_SUCCESS);
            break;
        case DUMP_FILE_OPEN_ERROR:
            PSendSysMessage(LANG_FILE_OPEN_FAIL, file);
            SetSentErrorMessage(true);
            return false;
        default:
            PSendSysMessage(LANG_COMMAND_EXPORT_FAILED);
            SetSentErrorMessage(true);
            return false;
    }

    return true;
}

bool ChatHandler::HandleQuestAddCommand(char* args)
{
    // .addquest #entry'
    // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
    uint32 entry;
    if (!ExtractUint32KeyFromLink(&args, "Hquest", entry))
        return false;

    Player* player;
    if (!ExtractPlayerTarget(&args, &player, nullptr, nullptr))
        return false;

    Quest const* pQuest = sObjectMgr.GetQuestTemplate(entry);
    if (!pQuest)
    {
        PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
        SetSentErrorMessage(true);
        return false;
    }

    // check item starting quest (it can work incorrectly if added without item in inventory)
    for (uint32 id = 0; id < sItemStorage.GetMaxEntry(); ++id)
    {
        ItemPrototype const* pProto = sItemStorage.LookupEntry<ItemPrototype>(id);
        if (!pProto)
            continue;

        if (pProto->StartQuest == entry)
        {
            PSendSysMessage(LANG_COMMAND_QUEST_STARTFROMITEM, entry, pProto->ItemId);
            SetSentErrorMessage(true);
            return false;
        }
    }

    // ok, normal (creature/GO starting) quest
    if (player->CanAddQuest(pQuest, true))
    {
        player->AddQuest(pQuest, nullptr);

        if (player->CanCompleteQuest(entry))
            player->CompleteQuest(entry);
    }

    PSendSysMessage("Quest %u added for %s.", entry, player->GetName());
    return true;
}

bool ChatHandler::HandleQuestRemoveCommand(char* args)
{
    // .removequest #entry'
    // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
    uint32 entry;
    if (!ExtractUint32KeyFromLink(&args, "Hquest", entry))
        return false;

    Player* player;
    if (!ExtractPlayerTarget(&args, &player, nullptr, nullptr))
        return false;

    Quest const* pQuest = sObjectMgr.GetQuestTemplate(entry);

    if (!pQuest)
    {
        PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
        SetSentErrorMessage(true);
        return false;
    }

    player->RemoveQuest(entry);

    // set quest status to not started (will updated in DB at next save)
    player->SetQuestStatus(entry, QUEST_STATUS_NONE);

    // reset rewarded for restart repeatable quest
    player->getQuestStatusMap()[entry].m_rewarded = false;

    SendSysMessage(LANG_COMMAND_QUEST_REMOVED);
    return true;
}

QuestStatusData HandleQuestStatusCommandHelper(uint32 quest_id, Player const* player,
    ObjectGuid const* guid)
{
    QuestStatusData data;
    data.m_status = QuestStatus::QUEST_STATUS_NONE;

    if (player)
    {
        auto tmpQuestData = player->GetQuestStatusData(quest_id);

        if (tmpQuestData)
        {
            data = *tmpQuestData;
        }
    }
    else
    {
        std::unique_ptr<QueryResult> result(CharacterDatabase.PQuery(
            "SELECT `status`, `rewarded`, `reward_choice` FROM `character_queststatus` WHERE `guid` = %u AND `quest` = %u",
            guid->GetCounter(), quest_id
        ));

        if (!result || result->GetRowCount() == 0)
        {
            return data;
        }

        auto fields = result->Fetch();
        data.m_status = QuestStatus(fields[0].GetUInt32());
        data.m_rewarded = fields[1].GetBool();
        data.m_reward_choice = fields[2].GetUInt32();
    }

    return data;
}

bool ChatHandler::HandleQuestStatusCommand(char* args)
{
    // .quest complete #entry
    // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
    uint32 entry;
    if (!ExtractUint32KeyFromLink(&args, "Hquest", entry))
        return false;

    Player* player;
    std::string name;
    ObjectGuid guid;

    if (!ExtractPlayerTarget(&args, &player, &guid, &name))
        return false;

    Quest const* quest = sObjectMgr.GetQuestTemplate(entry);

    if (!quest)
    {
        PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
        SetSentErrorMessage(true);
        return false;
    }

    QuestStatusData questData = HandleQuestStatusCommandHelper(entry, player, &guid);

    std::stringstream rewardInfo;

    if (questData.m_rewarded && questData.m_reward_choice)
    {
        rewardInfo << "item: " << questData.m_reward_choice << " ";

        const auto itemProto = sItemStorage.LookupEntry<ItemPrototype>(questData.m_reward_choice);

        if (itemProto)
        {
            rewardInfo << "[" << itemProto->Name1 << "]";
        }
        else
        {
            rewardInfo << "[invalid item entry?]";
        }
    }
    else
    {
        rewardInfo << "no reward data recorded";
    }

    PSendSysMessage("Quest ID: %u - [%s] - Rewarded: %s (%s)", entry, QuestStatusToString(questData.m_status),
        questData.m_rewarded? "Yes" : "No", rewardInfo.str().c_str());

    Quest const* prevQuest = quest;

    uint8 pos = 1;
    while (prevQuest->GetPrevQuestId())
    {
        if (Quest const* quest = sObjectMgr.GetQuestTemplate(prevQuest->GetPrevQuestId()))
        {
            questData = HandleQuestStatusCommandHelper(quest->GetQuestId(), player, &guid);

            if (quest->GetNextQuestInChain() == prevQuest->GetQuestId())
            {
                uint32 id = quest->GetQuestId();
                PSendSysMessage("%u. [PreventInChain] Quest ID: %u - [%s]", pos, id, QuestStatusToString(questData.m_status));
                prevQuest = quest;
            }
            else
            {
                uint32 id = quest->GetQuestId();
                PSendSysMessage("%u. [Prevent] Quest ID: %u - [%s]", pos, id, QuestStatusToString(questData.m_status));
                prevQuest = quest;
            }
        } else break;
        ++pos;
    }
    return true;
}

bool ChatHandler::HandleQuestCompleteCommand(char* args)
{
    // .quest complete #entry
    // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
    uint32 entry;
    if (!ExtractUint32KeyFromLink(&args, "Hquest", entry))
        return false;

    Player* player;
    if (!ExtractPlayerTarget(&args, &player, nullptr, nullptr))
        return false;

    Quest const* pQuest = sObjectMgr.GetQuestTemplate(entry);

    // If player doesn't have the quest
    if (!pQuest || player->GetQuestStatus(entry) == QUEST_STATUS_NONE)
    {
        PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
        SetSentErrorMessage(true);
        return false;
    }
    player->FullQuestComplete(entry);

    PSendSysMessage("Quest %u completed for %s.", entry, player->GetName());
    return true;
}

bool ChatHandler::HandlePetListCommand(char* args)
{
    std::string charName(args);
    normalizePlayerName(charName);
    ObjectGuid playerGuid = sObjectMgr.GetPlayerGuidByName(charName);
    if (!playerGuid)
    {
        SendSysMessage(LANG_NON_EXIST_CHARACTER);
        SetSentErrorMessage(true);
        return false;
    }
    CharPetMap const& petsMap = sCharacterDatabaseCache.GetCharPetsMap();
    CharPetMap::const_iterator charPets = petsMap.find(playerGuid.GetCounter());
    uint32 count = 0;
    if (charPets != petsMap.end())
        for (const auto it : charPets->second)
        {
            PSendSysMessage("#%u: \"%s\" (%s)", it->id, it->name.c_str(), it->slot == PET_SAVE_AS_CURRENT ? "Current pet" : "In stable");
            ++count;
        }
    PSendSysMessage("Found %u pets for character %s (#%u).", count, charName.c_str(), playerGuid.GetCounter());
    return true;
}

bool ChatHandler::HandlePetRenameCommand(char* args)
{
    uint32 petId;
    std::string newName;
    if (!ExtractUInt32(&args, petId))
        return false;
    newName = args;
    PetNameInvalidReason res = ObjectMgr::CheckPetName(newName);
    if (res != PET_NAME_SUCCESS)
    {
        PSendSysMessage("\"%s\" is not a valid pet name", newName.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    std::unique_ptr<QueryResult> result(CharacterDatabase.PQuery("SELECT `owner_guid`, `name` FROM `character_pet` WHERE `id` = %u", petId));

    if (!result)
    {
        PSendSysMessage("Pet #%u not found", petId);
        SetSentErrorMessage(true);
        return false;
    }

    auto fields = result->Fetch();
    auto owner_guid = fields[0].GetUInt32();
    auto pet_name = fields[1].GetString();

    PSendSysMessage("Pet #%u (\"%s\", owner #%u) renamed to \"%s\"", petId, pet_name, owner_guid, newName.c_str());
    CharacterDatabase.escape_string(newName);
    CharacterDatabase.PExecute("UPDATE character_pet SET name = \"%s\" WHERE id = %u", newName.c_str(), petId);

    CharacterPetCache* petData = sCharacterDatabaseCache.GetCharacterPetById(petId);

    if (petData)
    {
        petData->name = newName;
    }

    return true;
}

bool ChatHandler::HandlePetDeleteCommand(char* args)
{
    uint32 petId;
    if (!ExtractUInt32(&args, petId))
        return false;
    CharacterPetCache* petData = sCharacterDatabaseCache.GetCharacterPetById(petId);
    if (!petData)
    {
        PSendSysMessage("Pet #%u not found", petId);
        SetSentErrorMessage(true);
        return false;
    }
    PSendSysMessage("Pet #%u (\"%s\", owner #%u) deleted.", petData->id, petData->name.c_str(), petData->ownerGuid);
    CharacterDatabase.PExecute("DELETE FROM `character_pet` WHERE `id` = %u", petId);
    sCharacterDatabaseCache.DeleteCharacterPetById(petId);
    return true;
}

bool ChatHandler::HandlePetLoyaltyCommand(char* args)
{
    if (!*args)
        return false;

    Pet* pet = GetSelectedPet();
    if (!pet)
        return false;

    if (pet->getPetType() != HUNTER_PET)
        return false;

    int32 loyaltyPoints;
    if (!ExtractOptInt32(&args, loyaltyPoints, 1))
        return false;

    pet->ModifyLoyalty(loyaltyPoints);
    
    return true;
}

bool ChatHandler::HandlePetInfoCommand(char* args)
{
    Pet* pPet = GetSelectedPet();
    if (!pPet)
        return false;

    PSendSysMessage("Info for %s", pPet->GetObjectGuid().GetString().c_str());
    PSendSysMessage("Owner: %s", pPet->GetOwnerGuid().GetString().c_str());
    PSendSysMessage("Pet type: %u", pPet->getPetType());
    PSendSysMessage("Loyalty level: %hhu", pPet->GetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_PET_LOYALTY));
    PSendSysMessage("Pet number: %u", pPet->GetUInt32Value(UNIT_FIELD_PETNUMBER));
    PSendSysMessage("Pet name timestamp: %u", pPet->GetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP));
    PSendSysMessage("Pet experience: %u", pPet->GetUInt32Value(UNIT_FIELD_PETEXPERIENCE));
    PSendSysMessage("Pet next level xp: %u", pPet->GetUInt32Value(UNIT_FIELD_PETNEXTLEVELEXP));
    PSendSysMessage("Training points: %u", pPet->GetUInt32Value(UNIT_TRAINING_POINTS));

    return true;
}

bool ChatHandler::HandleChannelJoinCommand(char* c)
{
    WorldPacket pkt(CMSG_JOIN_CHANNEL, 4);
    pkt << c;
    pkt << ""; // Pass
    m_session->HandleJoinChannelOpcode(pkt);
    PSendSysMessage("Joined channel \"%s\"", c);
    return true;
}

bool ChatHandler::HandleChannelLeaveCommand(char* c)
{
    WorldPacket pkt(CMSG_LEAVE_CHANNEL, 4);
    pkt << c;
    m_session->HandleLeaveChannelOpcode(pkt);
    PSendSysMessage("Left channel \"%s\"", c);
    return true;
}

enum ServiceDeleteFlags
{
    SDF_NONE            = 0x00,
    SDF_MAX_LEVEL       = 0x01,
    SDF_MAX_MONEY       = 0x02,
    SDF_MAX_ITEMS       = 0x04,
    SDF_MAX_PLAYED_TIME = 0x08,
    SDF_PERM_BANNED     = 0x10,
    SDF_LAST_LOGIN      = 0x20,
    SDF_GM              = 0x40
};

bool ChatHandler::HandleServiceDeleteCharacters(char* args)
{
    uint32 flags = 0;
    if (!ExtractUInt32(&args, flags))
        return false;

    Tokens tokens = StrSplit(sConfig.GetStringDefault("LoginDatabase.Info", ""), ";");

    std::string dblogon;
    auto i = 0;
    for (auto& token : tokens)
    {
        if (i == 4)
        {
            dblogon = token;
            break;
        }
        else
            ++i;
    }

    std::ostringstream s;

    if (flags & SDF_PERM_BANNED)
    {
        s << "SELECT `guid`, `account` FROM `characters` WHERE `account` IN (SELECT `id` FROM `" << dblogon << "`.`account_banned` WHERE `bandate` = `unbandate` AND `active` = 1) ";

        uint32 maxLevel = 0;
        if (ExtractUInt32(&args, maxLevel))
            s << "AND `level` <= " << maxLevel << " ";
    }
    else if (flags & SDF_GM)
    {
        s << "SELECT `guid`, `account` FROM `characters` WHERE `account` IN (SELECT `id` FROM `" << dblogon << "`.`account` WHERE `gmlevel` > 0)";
    }
    else
    {
        s << "SELECT `characters`.`guid`,"
             "    `characters`.`account`,"
             "    `characters`.`level` AS `level`,"
             "    `characters`.`money` AS `money`,"
             "    `characters`.`played_time_total` AS `played_time_total`,"
             "    COUNT(`characters`.`guid`) AS `items`,"
             "    `characters`.`logout_time` AS `logout_time` "
             "FROM `characters` "
             "INNER JOIN `character_inventory` USING(`guid`) "
             "GROUP BY `characters`.`guid` HAVING ";

        bool _and = false;
        if (flags & SDF_MAX_LEVEL)
        {
            uint32 maxLevel = 0;
            if (!ExtractUInt32(&args, maxLevel))
                return false;

            s << (_and ? "AND " : "") << "`level` <= " << maxLevel << " ";
            _and = true;
        }

        if (flags & SDF_MAX_MONEY)
        {
            uint32 maxMoney = 0;
            if (!ExtractUInt32(&args, maxMoney))
                return false;

            s << (_and ? "AND " : "") << "`money` <= " << maxMoney << " ";
            _and = true;
        }

        if (flags & SDF_MAX_ITEMS)
        {
            uint32 maxItems = 0;
            if (!ExtractUInt32(&args, maxItems))
                return false;

            s << (_and ? "AND " : "") << "`items` <= " << maxItems << " ";
            _and = true;
        }

        if (flags & SDF_MAX_PLAYED_TIME)
        {
            uint32 maxPlayedTime = 0;
            if (!ExtractUInt32(&args, maxPlayedTime))
                return false;

            s << (_and ? "AND " : "") << "`played_time_total` <= " << maxPlayedTime << " ";
            _and = true;
        }

        if (flags & SDF_LAST_LOGIN)
        {
            uint32 logoutTime = 0;
            if (!ExtractUInt32(&args, logoutTime))
                return false;

            s << (_and ? "AND " : "") << "`logout_time` <= " << logoutTime << " ";
            _and = true;
        }
    }

    QueryResult* result = CharacterDatabase.Query(s.str().c_str());
    uint32 count = 0;
    if (result)
    {
        count = result->GetRowCount();
        do
        {
            Field* fields = result->Fetch();
            uint32 lowGuid = fields[0].GetUInt32();
            uint32 accountId = fields[1].GetUInt32();

            ObjectGuid guid = ObjectGuid(HIGHGUID_PLAYER, lowGuid);

            Player::DeleteFromDB(guid, accountId, true, true);
        } while (result->NextRow());

        delete result;
    }

    sLog.outString("Service: Removed %u characters", count);
    return true;
}

bool ChatHandler::HandleGoldRemoval(char* args)
{
    std::string error("Illformed gold removal command. Format is: name #g #s #c"); // move?

    std::string input(args);
    // I'm bad at regex - feel free to improve this
    std::regex pattern(R"(([a-zA-Z]{3,}) (\d{1,5})(g|s|c)\s?(\d{1,2})(g|s|c)\s?(\d{1,2})(g|s|c)\s?)");
    std::smatch matches;

    if (!std::regex_match(input, matches, pattern))
    {
        PSendSysMessage(error.c_str());
        SetSentErrorMessage(true);
        return false;
    }

    unsigned long gold = 0;
    unsigned long silver = 0;
    unsigned long copper = 0;

    std::string name = matches[1];

    for (auto i = matches.begin() + 2; i != matches.end(); i += 2)
    {
        try
        {
            auto type = (i + 1)->str();

            if (type == "g" && !gold)
            {
                gold += std::stoul(*i);
            }
            else if (type == "s" && !silver)
            {
                silver += std::stoul(*i);
            }
            else if (type == "c" && !copper)
            {
                copper += std::stoul(*i);
            }
            else
            {
                PSendSysMessage(error.c_str());
                SetSentErrorMessage(true);
                return false;
            }
        }
        catch (std::runtime_error&)
        {
            PSendSysMessage(error.c_str());
            SetSentErrorMessage(true);
            return false;
        }
    }

    uint32_t prevMoney = 0;
    uint32_t newMoney = 0;

    Player* player = sObjectMgr.GetPlayer(name.c_str());

    uint32 removalAmount = (gold * GOLD) + (silver * SILVER) + copper;

    if (player)
    {
        prevMoney = player->GetMoney();
        player->ModifyMoney(-static_cast<int32>(removalAmount));
        newMoney = player->GetMoney();

        PSendSysMessage("Removed %ug %us %uc from %s", gold, silver, copper, name.c_str());
        PSendSysMessage("%s previously had %ug %us %uc", name.c_str(), prevMoney / GOLD, (prevMoney % GOLD) / SILVER, (prevMoney % GOLD) % SILVER);
        PSendSysMessage("%s now has %ug %us %uc", name.c_str(), newMoney / GOLD, (newMoney % GOLD) / SILVER, (newMoney % GOLD) % SILVER);
    }
    else
    {
        CharacterDatabase.escape_string(name);
        CharacterDatabase.AsyncPQueryUnsafe(&PlayerGoldRemovalHandler::HandleGoldLookupResult,
            GetAccountId(), removalAmount,
            "SELECT money, guid, name FROM characters WHERE name = '%s'",
            name.c_str());
    }
    return true;
}

bool ChatHandler::HandleRepairitemsCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    // check online security
    if (HasLowerSecurity(target))
        return false;

    // Repair items
    target->DurabilityRepairAll(false, 0);

    PSendSysMessage(LANG_YOU_REPAIR_ITEMS, GetNameLink(target).c_str());
    if (needReportToTarget(target))
        ChatHandler(target).PSendSysMessage(LANG_YOUR_ITEMS_REPAIRED, GetNameLink().c_str());
    return true;
}

bool ChatHandler::HandleCombatStopCommand(char* args)
{
    Player* target;
    if (!ExtractPlayerTarget(&args, &target))
        return false;

    // check online security
    if (HasLowerSecurity(target))
        return false;

    target->CombatStop();
    target->GetHostileRefManager().deleteReferences();
    return true;
}

bool ChatHandler::HandleGroupAddItemCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();
    Group* pGroup = pPlayer->GetGroup();
    if (!pGroup)
    {
        SendSysMessage("You are not in a group.");
        SetSentErrorMessage(true);
        return false;
    }

    uint32 itemId = 0;
    if (!ExtractUInt32(&args, itemId))
        return false;

    if (!ObjectMgr::GetItemPrototype(itemId))
    {
        PSendSysMessage(LANG_COMMAND_ITEMIDINVALID, itemId);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 count = 1;
    ExtractOptUInt32(&args, count, 1);

    for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        if (Player* pMember = itr->getSource())
        {
            if (pMember == pPlayer)
                continue;

            if (Item* pItem = pMember->StoreNewItemInInventorySlot(itemId, count))
                pMember->SendNewItem(pItem, count, true, false);
        }
    }

    PSendSysMessage("Added item %u to all group members.", itemId);
    return true;
}

bool ChatHandler::HandleGroupReviveCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();
    Group* pGroup = pPlayer->GetGroup();
    if (!pGroup)
    {
        SendSysMessage("You are not in a group.");
        SetSentErrorMessage(true);
        return false;
    }

    for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        if (Player* pMember = itr->getSource())
        {
            if (pMember == pPlayer)
                continue;

            if (pMember->IsDead())
            {
                pMember->ResurrectPlayer(0.5f);
                pMember->SpawnCorpseBones();
            }
        }
    }

    PSendSysMessage("Revived all dead group members.");
    return true;
}

bool ChatHandler::HandleGroupReplenishCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();
    Group* pGroup = pPlayer->GetGroup();
    if (!pGroup)
    {
        SendSysMessage("You are not in a group.");
        SetSentErrorMessage(true);
        return false;
    }

    for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        if (Player* pMember = itr->getSource())
        {
            if (pMember == pPlayer)
                continue;

            if (pMember->IsAlive())
            {
                pMember->SetHealth(pMember->GetMaxHealth());
                if (pMember->GetPowerType() == POWER_MANA)
                    pMember->SetPower(POWER_MANA, pMember->GetMaxPower(POWER_MANA));
            }
        }
    }

    PSendSysMessage("Replenished all group members.");
    return true;
}

bool ChatHandler::HandleGroupSummonCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();
    Group* pGroup = pPlayer->GetGroup();
    if (!pGroup)
    {
        SendSysMessage("You are not in a group.");
        SetSentErrorMessage(true);
        return false;
    }

    for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        if (Player* pMember = itr->getSource())
        {
            if (pMember == pPlayer)
                continue;

            pMember->SendSummonRequest(pPlayer->GetObjectGuid(), pPlayer->GetMapId(), pPlayer->GetZoneId(), pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ());
        }
    }

    PSendSysMessage("Sent summon request to all group members.");
    return true;
}
