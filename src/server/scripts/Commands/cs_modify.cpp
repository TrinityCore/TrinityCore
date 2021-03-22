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

/* ScriptData
Name: modify_commandscript
%Complete: 100
Comment: All modify related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "CharacterCache.h"
#include "Chat.h"
#include "DB2Stores.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Pet.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "RBAC.h"
#include "ReputationMgr.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "UpdateFields.h"
#include "WorldSession.h"

class modify_commandscript : public CommandScript
{
public:
    modify_commandscript() : CommandScript("modify_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> modifyspeedCommandTable =
        {
            { "all",      rbac::RBAC_PERM_COMMAND_MODIFY_SPEED_ALL,      false, &HandleModifyASpeedCommand, "" },
            { "backwalk", rbac::RBAC_PERM_COMMAND_MODIFY_SPEED_BACKWALK, false, &HandleModifyBWalkCommand,  "" },
            { "fly",      rbac::RBAC_PERM_COMMAND_MODIFY_SPEED_FLY,      false, &HandleModifyFlyCommand,    "" },
            { "walk",     rbac::RBAC_PERM_COMMAND_MODIFY_SPEED_WALK,     false, &HandleModifySpeedCommand,  "" },
            { "swim",     rbac::RBAC_PERM_COMMAND_MODIFY_SPEED_SWIM,     false, &HandleModifySwimCommand,   "" },
            { "",         rbac::RBAC_PERM_COMMAND_MODIFY_SPEED,          false, &HandleModifyASpeedCommand, "" },
        };
        static std::vector<ChatCommand> modifyCommandTable =
        {
            { "currency",     rbac::RBAC_PERM_COMMAND_MODIFY_CURRENCY,     false, &HandleModifyCurrencyCommand,      "" },
            { "drunk",        rbac::RBAC_PERM_COMMAND_MODIFY_DRUNK,        false, &HandleModifyDrunkCommand,         "" },
            { "energy",       rbac::RBAC_PERM_COMMAND_MODIFY_ENERGY,       false, &HandleModifyEnergyCommand,        "" },
            { "faction",      rbac::RBAC_PERM_COMMAND_MODIFY_FACTION,      false, &HandleModifyFactionCommand,       "" },
            { "gender",       rbac::RBAC_PERM_COMMAND_MODIFY_GENDER,       false, &HandleModifyGenderCommand,        "" },
            { "honor",        rbac::RBAC_PERM_COMMAND_MODIFY_HONOR,        false, &HandleModifyHonorCommand,         "" },
            { "hp",           rbac::RBAC_PERM_COMMAND_MODIFY_HP,           false, &HandleModifyHPCommand,            "" },
            { "mana",         rbac::RBAC_PERM_COMMAND_MODIFY_MANA,         false, &HandleModifyManaCommand,          "" },
            { "money",        rbac::RBAC_PERM_COMMAND_MODIFY_MONEY,        false, &HandleModifyMoneyCommand,         "" },
            { "mount",        rbac::RBAC_PERM_COMMAND_MODIFY_MOUNT,        false, &HandleModifyMountCommand,         "" },
            { "phase",        rbac::RBAC_PERM_COMMAND_MODIFY_PHASE,        false, &HandleModifyPhaseCommand,         "" },
            { "rage",         rbac::RBAC_PERM_COMMAND_MODIFY_RAGE,         false, &HandleModifyRageCommand,          "" },
            { "reputation",   rbac::RBAC_PERM_COMMAND_MODIFY_REPUTATION,   false, &HandleModifyRepCommand,           "" },
            { "runicpower",   rbac::RBAC_PERM_COMMAND_MODIFY_RUNICPOWER,   false, &HandleModifyRunicPowerCommand,    "" },
            { "scale",        rbac::RBAC_PERM_COMMAND_MODIFY_SCALE,        false, &HandleModifyScaleCommand,         "" },
            { "speed",        rbac::RBAC_PERM_COMMAND_MODIFY_SPEED,        false, nullptr,           "", modifyspeedCommandTable },
            { "spell",        rbac::RBAC_PERM_COMMAND_MODIFY_SPELL,        false, &HandleModifySpellCommand,         "" },
            { "standstate",   rbac::RBAC_PERM_COMMAND_MODIFY_STANDSTATE,   false, &HandleModifyStandStateCommand,    "" },
            { "talentpoints", rbac::RBAC_PERM_COMMAND_MODIFY_TALENTPOINTS, false, &HandleModifyTalentCommand,        "" },
            { "xp",           rbac::RBAC_PERM_COMMAND_MODIFY_XP,           false, &HandleModifyXPCommand,            "" },
            { "power",        rbac::RBAC_PERM_COMMAND_MODIFY_POWER,        false, &HandleModifyPowerCommand,         "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "morph",   rbac::RBAC_PERM_COMMAND_MORPH,   false, &HandleModifyMorphCommand,          "" },
            { "demorph", rbac::RBAC_PERM_COMMAND_DEMORPH, false, &HandleDeMorphCommand,              "" },
            { "modify",  rbac::RBAC_PERM_COMMAND_MODIFY,  false, nullptr,                 "", modifyCommandTable },
        };
        return commandTable;
    }

    template<typename... Args>
    static void NotifyModification(ChatHandler* handler, Unit* target, TrinityStrings resourceMessage, TrinityStrings resourceReportMessage, Args&&... args)
    {
        if (Player* player = target->ToPlayer())
        {
            handler->PSendSysMessage(resourceMessage, handler->GetNameLink(player).c_str(), args...);
            if (handler->needReportToTarget(player))
                ChatHandler(player->GetSession()).PSendSysMessage(resourceReportMessage, handler->GetNameLink().c_str(), std::forward<Args>(args)...);
        }
    }

    static bool CheckModifyResources(ChatHandler* handler, char const* args, Player* target, int32& res, int32& resmax, int8 const multiplier = 1)
    {
        if (!*args)
            return false;

        res = atoi((char*)args) * multiplier;
        resmax = atoi((char*)args) * multiplier;

        if (res < 1 || resmax < 1 || resmax < res)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        return true;
    }

    //Edit Player HP
    static bool HandleModifyHPCommand(ChatHandler* handler, char const* args)
    {
        int32 hp, hpmax;
        Player* target = handler->getSelectedPlayerOrSelf();
        if (CheckModifyResources(handler, args, target, hp, hpmax))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_HP, LANG_YOURS_HP_CHANGED, hp, hpmax);
            target->SetMaxHealth(hpmax);
            target->SetHealth(hp);
            return true;
        }
        return false;
    }

    //Edit Player Mana
    static bool HandleModifyManaCommand(ChatHandler* handler, char const* args)
    {
        int32 mana, manamax;
        Player* target = handler->getSelectedPlayerOrSelf();

        if (CheckModifyResources(handler, args, target, mana, manamax))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_MANA, LANG_YOURS_MANA_CHANGED, mana, manamax);
            target->SetMaxPower(POWER_MANA, manamax);
            target->SetPower(POWER_MANA, mana);
            return true;
        }
        return false;
    }

    //Edit Player Energy
    static bool HandleModifyEnergyCommand(ChatHandler* handler, char const* args)
    {
        int32 energy, energymax;
        Player* target = handler->getSelectedPlayerOrSelf();
        int8 const energyMultiplier = 10;
        if (CheckModifyResources(handler, args, target, energy, energymax, energyMultiplier))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_ENERGY, LANG_YOURS_ENERGY_CHANGED, energy / energyMultiplier, energymax / energyMultiplier);
            target->SetMaxPower(POWER_ENERGY, energymax);
            target->SetPower(POWER_ENERGY, energy);
            return true;
        }
        return false;
    }

    //Edit Player Rage
    static bool HandleModifyRageCommand(ChatHandler* handler, char const* args)
    {
        int32 rage, ragemax;
        Player* target = handler->getSelectedPlayerOrSelf();
        int8 const rageMultiplier = 10;
        if (CheckModifyResources(handler, args, target, rage, ragemax, rageMultiplier))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_RAGE, LANG_YOURS_RAGE_CHANGED, rage / rageMultiplier, ragemax / rageMultiplier);
            target->SetMaxPower(POWER_RAGE, ragemax);
            target->SetPower(POWER_RAGE, rage);
            return true;
        }
        return false;
    }

    // Edit Player Runic Power
    static bool HandleModifyRunicPowerCommand(ChatHandler* handler, char const* args)
    {
        int32 rune, runemax;
        Player* target = handler->getSelectedPlayerOrSelf();
        int8 const runeMultiplier = 10;
        if (CheckModifyResources(handler, args, target, rune, runemax, runeMultiplier))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_RUNIC_POWER, LANG_YOURS_RUNIC_POWER_CHANGED, rune / runeMultiplier, runemax / runeMultiplier);
            target->SetMaxPower(POWER_RUNIC_POWER, runemax);
            target->SetPower(POWER_RUNIC_POWER, rune);
            return true;
        }
        return false;
    }

    //Edit Player Faction
    static bool HandleModifyFactionCommand(ChatHandler* handler, char const* args)
    {
        char* pfactionid = handler->extractKeyFromLink((char*)args, "Hfaction");

        Creature* target = handler->getSelectedCreature();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!pfactionid)
        {
            uint32 factionid = target->GetFaction();
            uint32 flag      = target->m_unitData->Flags;
            uint64 npcflag;
            memcpy(&npcflag, target->m_unitData->NpcFlags.begin(), sizeof(uint64));
            uint32 dyflag    = target->m_objectData->DynamicFlags;
            handler->PSendSysMessage(LANG_CURRENT_FACTION, target->GetGUID().ToString().c_str(), factionid, flag, std::to_string(npcflag).c_str(), dyflag);
            return true;
        }

        uint32 factionid = atoul(pfactionid);
        uint32 flag;

        char *pflag = strtok(nullptr, " ");
        if (!pflag)
            flag = target->m_unitData->Flags;
        else
            flag = atoul(pflag);

        char* pnpcflag = strtok(nullptr, " ");

        uint64 npcflag;
        if (!pnpcflag)
            memcpy(&npcflag, target->m_unitData->NpcFlags.begin(), sizeof(uint64));
        else
            npcflag = atoull(pnpcflag);

        char* pdyflag = strtok(nullptr, " ");

        uint32  dyflag;
        if (!pdyflag)
            dyflag = target->m_objectData->DynamicFlags;
        else
            dyflag = atoul(pdyflag);

        if (!sFactionTemplateStore.LookupEntry(factionid))
        {
            handler->PSendSysMessage(LANG_WRONG_FACTION, factionid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_YOU_CHANGE_FACTION, target->GetGUID().ToString().c_str(), factionid, flag, std::to_string(npcflag).c_str(), dyflag);

        target->SetFaction(factionid);
        target->SetUnitFlags(UnitFlags(flag));
        target->SetNpcFlags(NPCFlags(npcflag & 0xFFFFFFFF));
        target->SetNpcFlags2(NPCFlags2(npcflag >> 32));
        target->SetDynamicFlags(dyflag);

        return true;
    }

    //Edit Player Spell
    static bool HandleModifySpellCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* pspellflatid = strtok((char*)args, " ");
        if (!pspellflatid)
            return false;

        char* pop = strtok(nullptr, " ");
        if (!pop)
            return false;

        char* pval = strtok(nullptr, " ");
        if (!pval)
            return false;

        uint16 mark;

        char* pmark = strtok(nullptr, " ");

        uint8 spellflatid = atoi(pspellflatid);
        uint8 op   = atoi(pop);
        uint16 val = atoi(pval);
        if (!pmark)
            mark = 65535;
        else
            mark = atoi(pmark);

        Player* target = handler->getSelectedPlayerOrSelf();
        if (target == nullptr)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        handler->PSendSysMessage(LANG_YOU_CHANGE_SPELLFLATID, spellflatid, val, mark, handler->GetNameLink(target).c_str());
        if (handler->needReportToTarget(target))
            ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_SPELLFLATID_CHANGED, handler->GetNameLink().c_str(), spellflatid, val, mark);

        WorldPackets::Spells::SetSpellModifier packet(SMSG_SET_FLAT_SPELL_MODIFIER);
        WorldPackets::Spells::SpellModifier spellMod;
        spellMod.ModIndex = op;
        WorldPackets::Spells::SpellModifierData modData;
        modData.ClassIndex = spellflatid;
        modData.ModifierValue = float(val);
        spellMod.ModifierData.push_back(modData);
        packet.Modifiers.push_back(spellMod);
        target->SendDirectMessage(packet.Write());

        return true;
    }

    //Edit Player TP
    static bool HandleModifyTalentCommand(ChatHandler* /*handler*/, char const* /*args*/)
    {
        /* TODO: 6.x remove this
        if (!*args)
            return false;

        int tp = atoi((char*)args);
        if (tp < 0)
            return false;

        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            // check online security
            if (handler->HasLowerSecurity(target->ToPlayer(), ObjectGuid::Empty))
                return false;
            target->ToPlayer()->SetFreeTalentPoints(tp);
            target->ToPlayer()->SendTalentsInfoData(false);
            return true;
        }
        else if (target->IsPet())
        {
            Unit* owner = target->GetOwner();
            if (owner && owner->GetTypeId() == TYPEID_PLAYER && ((Pet*)target)->IsPermanentPetFor(owner->ToPlayer()))
            {
                // check online security
                if (handler->HasLowerSecurity(owner->ToPlayer(), ObjectGuid::Empty))
                    return false;
                ((Pet*)target)->SetFreeTalentPoints(tp);
                owner->ToPlayer()->SendTalentsInfoData(true);
                return true;
            }
        }

        handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
        handler->SetSentErrorMessage(true);*/
        return false;
    }

    static bool CheckModifySpeed(ChatHandler* handler, char const* args, Unit* target, float& speed, float minimumBound, float maximumBound, bool checkInFlight = true)
    {
        if (!*args)
            return false;

        speed = (float)atof((char*)args);

        if (speed > maximumBound || speed < minimumBound)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Player* player = target->ToPlayer())
        {
            // check online security
            if (handler->HasLowerSecurity(player, ObjectGuid::Empty))
                return false;

            if (player->IsInFlight() && checkInFlight)
            {
                handler->PSendSysMessage(LANG_CHAR_IN_FLIGHT, handler->GetNameLink(player).c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
        }
        return true;
    }

    //Edit Player Aspeed
    static bool HandleModifyASpeedCommand(ChatHandler* handler, char const* args)
    {
        float allSpeed;
        Player* target = handler->getSelectedPlayerOrSelf();
        if (CheckModifySpeed(handler, args, target, allSpeed, 0.1f, 50.0f))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_ASPEED, LANG_YOURS_ASPEED_CHANGED, allSpeed);
            target->SetSpeedRate(MOVE_WALK, allSpeed);
            target->SetSpeedRate(MOVE_RUN, allSpeed);
            target->SetSpeedRate(MOVE_SWIM, allSpeed);
            target->SetSpeedRate(MOVE_FLIGHT, allSpeed);
            return true;
        }
        return false;
    }

    //Edit Player Speed
    static bool HandleModifySpeedCommand(ChatHandler* handler, char const* args)
    {
        float Speed;
        Player* target = handler->getSelectedPlayerOrSelf();
        if (CheckModifySpeed(handler, args, target, Speed, 0.1f, 50.0f))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_SPEED, LANG_YOURS_SPEED_CHANGED, Speed);
            target->SetSpeedRate(MOVE_RUN, Speed);
            return true;
        }
        return false;
    }

    //Edit Player Swim Speed
    static bool HandleModifySwimCommand(ChatHandler* handler, char const* args)
    {
        float swimSpeed;
        Player* target = handler->getSelectedPlayerOrSelf();
        if (CheckModifySpeed(handler, args, target, swimSpeed, 0.1f, 50.0f))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_SWIM_SPEED, LANG_YOURS_SWIM_SPEED_CHANGED, swimSpeed);
            target->SetSpeedRate(MOVE_SWIM, swimSpeed);
            return true;
        }
        return false;
    }

    //Edit Player Backwards Walk Speed
    static bool HandleModifyBWalkCommand(ChatHandler* handler, char const* args)
    {
        float backSpeed;
        Player* target = handler->getSelectedPlayerOrSelf();
        if (CheckModifySpeed(handler, args, target, backSpeed, 0.1f, 50.0f))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_BACK_SPEED, LANG_YOURS_BACK_SPEED_CHANGED, backSpeed);
            target->SetSpeedRate(MOVE_RUN_BACK, backSpeed);
            return true;
        }
        return false;
    }

    //Edit Player Fly
    static bool HandleModifyFlyCommand(ChatHandler* handler, char const* args)
    {
        float flySpeed;
        Player* target = handler->getSelectedPlayerOrSelf();
        if (CheckModifySpeed(handler, args, target, flySpeed, 0.1f, 50.0f, false))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_FLY_SPEED, LANG_YOURS_FLY_SPEED_CHANGED, flySpeed);
            target->SetSpeedRate(MOVE_FLIGHT, flySpeed);
            return true;
        }
        return false;
    }

    //Edit Player or Creature Scale
    static bool HandleModifyScaleCommand(ChatHandler* handler, char const* args)
    {
        float Scale;
        Unit* target = handler->getSelectedUnit();
        if (CheckModifySpeed(handler, args, target, Scale, 0.1f, 10.0f, false))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_SIZE, LANG_YOURS_SIZE_CHANGED, Scale);
            if (Creature* creatureTarget = target->ToCreature())
                creatureTarget->SetDisplayId(creatureTarget->GetDisplayId(), Scale);
            else
                target->SetObjectScale(Scale);
            return true;
        }
        return false;
    }

    //Enable Player mount
    static bool HandleModifyMountCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        const char* mount_cstr = strtok(const_cast<char*>(args), " ");
        const char* speed_cstr = strtok(nullptr, " ");

        if (!mount_cstr || !speed_cstr)
            return false;

        uint32 mount = atoul(args);
        if (!sCreatureDisplayInfoStore.HasRecord(mount))
        {
            handler->SendSysMessage(LANG_NO_MOUNT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        float speed;
        if (!CheckModifySpeed(handler, speed_cstr, target, speed, 0.1f, 50.0f))
            return false;

        NotifyModification(handler, target, LANG_YOU_GIVE_MOUNT, LANG_MOUNT_GIVED);
        target->Mount(mount);
        target->SetSpeedRate(MOVE_RUN, speed);
        target->SetSpeedRate(MOVE_FLIGHT, speed);
        return true;
    }

    //Edit Player money
    static bool HandleModifyMoneyCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        int64 moneyToAdd = 0;
        if (strchr(args, 'g') || strchr(args, 's') || strchr(args, 'c'))
            moneyToAdd = MoneyStringToMoney(std::string(args));
        else
            moneyToAdd = atoll(args);

        uint64 targetMoney = target->GetMoney();

        if (moneyToAdd < 0)
        {
            int64 newmoney = int64(targetMoney) + moneyToAdd;

            TC_LOG_DEBUG("misc", handler->GetTrinityString(LANG_CURRENT_MONEY), std::to_string(targetMoney).c_str(), std::to_string(moneyToAdd).c_str(), std::to_string(newmoney).c_str());
            if (newmoney <= 0)
            {
                NotifyModification(handler, target, LANG_YOU_TAKE_ALL_MONEY, LANG_YOURS_ALL_MONEY_GONE);
                target->SetMoney(0);
            }
            else
            {
                uint64 moneyToAddMsg = moneyToAdd * -1;
                if (newmoney > static_cast<int64>(MAX_MONEY_AMOUNT))
                    newmoney = MAX_MONEY_AMOUNT;

                handler->PSendSysMessage(LANG_YOU_TAKE_MONEY, std::to_string(moneyToAddMsg).c_str(), handler->GetNameLink(target).c_str());
                if (handler->needReportToTarget(target))
                    ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_MONEY_TAKEN, handler->GetNameLink().c_str(), std::to_string(moneyToAddMsg).c_str());
                target->SetMoney(newmoney);
            }
        }
        else
        {
            handler->PSendSysMessage(LANG_YOU_GIVE_MONEY, std::to_string(moneyToAdd).c_str(), handler->GetNameLink(target).c_str());
            if (handler->needReportToTarget(target))
                ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_MONEY_GIVEN, handler->GetNameLink().c_str(), std::to_string(moneyToAdd).c_str());

            if (moneyToAdd >= int64(MAX_MONEY_AMOUNT))
                moneyToAdd = MAX_MONEY_AMOUNT;

            moneyToAdd = std::min(moneyToAdd, int64(MAX_MONEY_AMOUNT - targetMoney));

            target->ModifyMoney(moneyToAdd);
        }

        TC_LOG_DEBUG("misc", handler->GetTrinityString(LANG_NEW_MONEY), std::to_string(targetMoney).c_str(), std::to_string(moneyToAdd).c_str(), std::to_string(target->GetMoney()).c_str());

        return true;
    }

    static bool HandleModifyHonorCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        int32 amount = atoi(args);

        handler->PSendSysMessage("NOT IMPLEMENTED: %d honor NOT added.", amount);

        //handler->PSendSysMessage(LANG_COMMAND_MODIFY_HONOR, handler->GetNameLink(target).c_str(), target->GetCurrency(CURRENCY_TYPE_HONOR_POINTS));

        return true;
    }

    static bool HandleModifyDrunkCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint8 drunklevel = (uint8)atoi(args);
        if (drunklevel > 100)
            drunklevel = 100;

        if (Player* target = handler->getSelectedPlayerOrSelf())
            target->SetDrunkValue(drunklevel);

        return true;
    }

    static bool HandleModifyRepCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        char* factionTxt = handler->extractKeyFromLink((char*)args, "Hfaction");
        if (!factionTxt)
            return false;

        uint32 factionId = atoi(factionTxt);

        int32 amount = 0;
        char *rankTxt = strtok(nullptr, " ");
        if (!factionId || !rankTxt)
            return false;

        amount = atoi(rankTxt);
        if ((amount == 0) && (rankTxt[0] != '-') && !isdigit(rankTxt[0]))
        {
            std::string rankStr = rankTxt;
            std::wstring wrankStr;
            if (!Utf8toWStr(rankStr, wrankStr))
                return false;
            wstrToLower(wrankStr);

            int r = 0;
            amount = -42000;
            for (; r < MAX_REPUTATION_RANK; ++r)
            {
                std::string rank = handler->GetTrinityString(ReputationRankStrIndex[r]);
                if (rank.empty())
                    continue;

                std::wstring wrank;
                if (!Utf8toWStr(rank, wrank))
                    continue;

                wstrToLower(wrank);

                if (wrank.substr(0, wrankStr.size()) == wrankStr)
                {
                    char *deltaTxt = strtok(nullptr, " ");
                    if (deltaTxt)
                    {
                        int32 delta = atoi(deltaTxt);
                        if ((delta < 0) || (delta > ReputationMgr::PointsInRank[r] -1))
                        {
                            handler->PSendSysMessage(LANG_COMMAND_FACTION_DELTA, (ReputationMgr::PointsInRank[r]-1));
                            handler->SetSentErrorMessage(true);
                            return false;
                        }
                        amount += delta;
                    }
                    break;
                }
                amount += ReputationMgr::PointsInRank[r];
            }
            if (r >= MAX_REPUTATION_RANK)
            {
                handler->PSendSysMessage(LANG_COMMAND_FACTION_INVPARAM, rankTxt);
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionId);

        if (!factionEntry)
        {
            handler->PSendSysMessage(LANG_COMMAND_FACTION_UNKNOWN, factionId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (factionEntry->ReputationIndex < 0)
        {
            handler->PSendSysMessage(LANG_COMMAND_FACTION_NOREP_ERROR, factionEntry->Name[handler->GetSessionDbcLocale()], factionId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        target->GetReputationMgr().SetOneFactionReputation(factionEntry, amount, false);
        target->GetReputationMgr().SendState(target->GetReputationMgr().GetState(factionEntry));
        handler->PSendSysMessage(LANG_COMMAND_MODIFY_REP, factionEntry->Name[handler->GetSessionDbcLocale()], factionId,
            handler->GetNameLink(target).c_str(), target->GetReputationMgr().GetReputation(factionEntry));
        return true;
    }

    //morph creature or player
    static bool HandleModifyMorphCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 display_id = atoul(args);

        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        // check online security
        else if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity(target->ToPlayer(), ObjectGuid::Empty))
            return false;

        target->SetDisplayId(display_id);

        return true;
    }

    // Toggles a phaseid on a player
    static bool HandleModifyPhaseCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* phaseText = strtok((char*)args, " ");
        if (!phaseText)
            return false;

        uint32 phaseId = uint32(strtoul(phaseText, nullptr, 10));
        uint32 visibleMapId = 0;

        char* visibleMapIdText = strtok(nullptr, " ");
        if (visibleMapIdText)
            visibleMapId = uint32(strtoul(visibleMapIdText, nullptr, 10));

        if (phaseId && !sPhaseStore.LookupEntry(phaseId))
        {
            handler->SendSysMessage(LANG_PHASE_NOTFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Unit* target = handler->getSelectedUnit();

        if (visibleMapId)
        {
            MapEntry const* visibleMap = sMapStore.LookupEntry(visibleMapId);
            if (!visibleMap || visibleMap->ParentMapID != int32(target->GetMapId()))
            {
                handler->SendSysMessage(LANG_PHASE_NOTFOUND);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (!target->GetPhaseShift().HasVisibleMapId(visibleMapId))
                PhasingHandler::AddVisibleMapId(target, visibleMapId);
            else
                PhasingHandler::RemoveVisibleMapId(target, visibleMapId);
        }

        if (phaseId)
        {
            if (!target->GetPhaseShift().HasPhase(phaseId))
                PhasingHandler::AddPhase(target, phaseId, true);
            else
                PhasingHandler::RemovePhase(target, phaseId, true);
        }

        return true;
    }

    //change standstate
    static bool HandleModifyStandStateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 anim_id = atoi((char*)args);
        handler->GetSession()->GetPlayer()->SetEmoteState(Emote(anim_id));

        return true;
    }

    static bool HandleModifyGenderCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        PlayerInfo const* info = sObjectMgr->GetPlayerInfo(target->getRace(), target->getClass());
        if (!info)
            return false;

        char const* gender_str = (char*)args;
        int gender_len = strlen(gender_str);

        Gender gender;

        if (!strncmp(gender_str, "male", gender_len))            // MALE
        {
            if (target->getGender() == GENDER_MALE)
                return true;

            gender = GENDER_MALE;
        }
        else if (!strncmp(gender_str, "female", gender_len))    // FEMALE
        {
            if (target->getGender() == GENDER_FEMALE)
                return true;

            gender = GENDER_FEMALE;
        }
        else
        {
            handler->SendSysMessage(LANG_MUST_MALE_OR_FEMALE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Set gender
        target->SetGender(gender);
        target->SetNativeSex(gender);

        // Change display ID
        target->InitDisplayIds();

        target->RestoreDisplayId(false);
        sCharacterCache->UpdateCharacterGender(target->GetGUID(), gender);

        // Generate random customizations
        std::vector<UF::ChrCustomizationChoice> customizations;

        Classes playerClass = Classes(target->getClass());
        std::vector<ChrCustomizationOptionEntry const*> const* options = sDB2Manager.GetCustomiztionOptions(target->getRace(), gender);
        WorldSession const* worldSession = target->GetSession();
        for (ChrCustomizationOptionEntry const* option : *options)
        {
            ChrCustomizationReqEntry const* optionReq = sChrCustomizationReqStore.LookupEntry(option->ChrCustomizationReqID);
            if (optionReq && !worldSession->MeetsChrCustomizationReq(optionReq, playerClass, false, MakeChrCustomizationChoiceRange(customizations)))
                continue;

            // Loop over the options until the first one fits
            std::vector<ChrCustomizationChoiceEntry const*> const* choicesForOption = sDB2Manager.GetCustomiztionChoices(option->ID);
            for (ChrCustomizationChoiceEntry const* choiceForOption : *choicesForOption)
            {
                ChrCustomizationReqEntry const* choiceReq = sChrCustomizationReqStore.LookupEntry(choiceForOption->ChrCustomizationReqID);
                if (choiceReq && !worldSession->MeetsChrCustomizationReq(choiceReq, playerClass, false, MakeChrCustomizationChoiceRange(customizations)))
                    continue;

                ChrCustomizationChoiceEntry const* choiceEntry = choicesForOption->at(0);
                UF::ChrCustomizationChoice choice;
                choice.ChrCustomizationOptionID = option->ID;
                choice.ChrCustomizationChoiceID = choiceEntry->ID;
                customizations.push_back(choice);
                break;
            }
        }

        target->SetCustomizations(Trinity::Containers::MakeIteratorPair(customizations.begin(), customizations.end()));

        char const* gender_full = gender ? "female" : "male";

        handler->PSendSysMessage(LANG_YOU_CHANGE_GENDER, handler->GetNameLink(target).c_str(), gender_full);

        if (handler->needReportToTarget(target))
            ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOUR_GENDER_CHANGED, gender_full, handler->GetNameLink().c_str());

        return true;
    }
//demorph player or unit
    static bool HandleDeMorphCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        // check online security
        else if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity(target->ToPlayer(), ObjectGuid::Empty))
            return false;

        target->DeMorph();

        return true;
    }

    static bool HandleModifyCurrencyCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 currencyId = atoi(strtok((char*)args, " "));
        const CurrencyTypesEntry* currencyType =  sCurrencyTypesStore.LookupEntry(currencyId);
        if (!currencyType)
            return false;

        uint32 amount = atoi(strtok(nullptr, " "));
        if (!amount)
            return false;

        target->ModifyCurrency(currencyId, amount, true, true);

        return true;
    }

    // mod xp command
    static bool HandleModifyXPCommand(ChatHandler *handler, char const* args)
    {
        if (!*args)
            return false;

        int32 xp = atoi((char*)args);

        if (xp < 1)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* target = handler->getSelectedPlayerOrSelf();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        // we can run the command
        target->GiveXP(xp, nullptr);
        return true;
    }

    // Edit Player Power
    static bool HandleModifyPowerCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayerOrSelf();
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        char* powerTypeToken = strtok((char*)args, " ");
        if (!powerTypeToken)
            return false;

        PowerTypeEntry const* powerType = sDB2Manager.GetPowerTypeByName(powerTypeToken);
        if (!powerType)
        {
            handler->SendSysMessage(LANG_INVALID_POWER_NAME);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->GetPowerIndex(Powers(powerType->PowerTypeEnum)) == MAX_POWERS)
        {
            handler->SendSysMessage(LANG_INVALID_POWER_NAME);
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* amount = strtok(nullptr, " ");
        if (!amount)
            return false;

        int32 powerAmount = atoi(amount);

        if (powerAmount < 1)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string formattedPowerName = powerType->NameGlobalStringTag;
        bool upperCase = true;
        for (char& c : formattedPowerName)
        {
            if (upperCase)
            {
                c = char(::toupper(c));
                upperCase = false;
            }
            else
                c = char(::tolower(c));

            if (c == '_')
            {
                c = ' ';
                upperCase = true;
            }
        }

        NotifyModification(handler, target, LANG_YOU_CHANGE_POWER, LANG_YOUR_POWER_CHANGED, formattedPowerName.c_str(), powerAmount, powerAmount);
        powerAmount *= powerType->DisplayModifier;
        target->SetMaxPower(Powers(powerType->PowerTypeEnum), powerAmount);
        target->SetPower(Powers(powerType->PowerTypeEnum), powerAmount);
        return true;
    }
};

void AddSC_modify_commandscript()
{
    new modify_commandscript();
}
