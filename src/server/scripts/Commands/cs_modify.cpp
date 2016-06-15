/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Chat.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Pet.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"


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
            { "arenapoints",  rbac::RBAC_PERM_COMMAND_MODIFY_ARENAPOINTS,  false, &HandleModifyArenaCommand,         "" },
            { "bit",          rbac::RBAC_PERM_COMMAND_MODIFY_BIT,          false, &HandleModifyBitCommand,           "" },
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
            { "speed",        rbac::RBAC_PERM_COMMAND_MODIFY_SPEED,        false, NULL,           "", modifyspeedCommandTable },
            { "spell",        rbac::RBAC_PERM_COMMAND_MODIFY_SPELL,        false, &HandleModifySpellCommand,         "" },
            { "standstate",   rbac::RBAC_PERM_COMMAND_MODIFY_STANDSTATE,   false, &HandleModifyStandStateCommand,    "" },
            { "talentpoints", rbac::RBAC_PERM_COMMAND_MODIFY_TALENTPOINTS, false, &HandleModifyTalentCommand,        "" },
            { "xp",           rbac::RBAC_PERM_COMMAND_MODIFY_XP,           false, &HandleModifyXPCommand,            "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "morph",   rbac::RBAC_PERM_COMMAND_MORPH,   false, &HandleModifyMorphCommand,          "" },
            { "demorph", rbac::RBAC_PERM_COMMAND_DEMORPH, false, &HandleDeMorphCommand,              "" },
            { "modify",  rbac::RBAC_PERM_COMMAND_MODIFY,  false, NULL,                 "", modifyCommandTable },
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

    static bool CheckModifyResources(ChatHandler* handler, const char* args, Player* target, int32& res, int32& resmax, int8 const multiplier = 1)
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
    static bool HandleModifyHPCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifyManaCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifyEnergyCommand(ChatHandler* handler, const char* args)
    {
        int32 energy, energymax;
        Player* target = handler->getSelectedPlayerOrSelf();
        int8 const energyMultiplier = 10;
        if (CheckModifyResources(handler, args, target, energy, energymax, energyMultiplier))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_ENERGY, LANG_YOURS_ENERGY_CHANGED, energy / energyMultiplier, energymax / energyMultiplier);
            target->SetMaxPower(POWER_ENERGY, energymax);
            target->SetPower(POWER_ENERGY, energy);
            TC_LOG_DEBUG("misc", handler->GetTrinityString(LANG_CURRENT_ENERGY), target->GetMaxPower(POWER_ENERGY));
            return true;
        }
        return false;
    }

    //Edit Player Rage
    static bool HandleModifyRageCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifyRunicPowerCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifyFactionCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

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
            uint32 factionid = target->getFaction();
            uint32 flag      = target->GetUInt32Value(UNIT_FIELD_FLAGS);
            uint32 npcflag   = target->GetUInt32Value(UNIT_NPC_FLAGS);
            uint32 dyflag    = target->GetUInt32Value(UNIT_DYNAMIC_FLAGS);
            handler->PSendSysMessage(LANG_CURRENT_FACTION, target->GetGUID().GetCounter(), factionid, flag, npcflag, dyflag);
            return true;
        }

        uint32 factionid = atoi(pfactionid);
        uint32 flag;

        char *pflag = strtok(NULL, " ");
        if (!pflag)
            flag = target->GetUInt32Value(UNIT_FIELD_FLAGS);
        else
            flag = atoi(pflag);

        char* pnpcflag = strtok(NULL, " ");

        uint32 npcflag;
        if (!pnpcflag)
            npcflag = target->GetUInt32Value(UNIT_NPC_FLAGS);
        else
            npcflag = atoi(pnpcflag);

        char* pdyflag = strtok(NULL, " ");

        uint32  dyflag;
        if (!pdyflag)
            dyflag = target->GetUInt32Value(UNIT_DYNAMIC_FLAGS);
        else
            dyflag = atoi(pdyflag);

        if (!sFactionTemplateStore.LookupEntry(factionid))
        {
            handler->PSendSysMessage(LANG_WRONG_FACTION, factionid);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_YOU_CHANGE_FACTION, target->GetGUID().GetCounter(), factionid, flag, npcflag, dyflag);

        target->setFaction(factionid);
        target->SetUInt32Value(UNIT_FIELD_FLAGS, flag);
        target->SetUInt32Value(UNIT_NPC_FLAGS, npcflag);
        target->SetUInt32Value(UNIT_DYNAMIC_FLAGS, dyflag);

        return true;
    }

    //Edit Player Spell
    static bool HandleModifySpellCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* pspellflatid = strtok((char*)args, " ");
        if (!pspellflatid)
            return false;

        char* pop = strtok(NULL, " ");
        if (!pop)
            return false;

        char* pval = strtok(NULL, " ");
        if (!pval)
            return false;

        uint16 mark;

        char* pmark = strtok(NULL, " ");

        uint8 spellflatid = atoi(pspellflatid);
        uint8 op   = atoi(pop);
        uint16 val = atoi(pval);
        if (!pmark)
            mark = 65535;
        else
            mark = atoi(pmark);

        Player* target = handler->getSelectedPlayerOrSelf();
        if (target == NULL)
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

        WorldPacket data(SMSG_SET_FLAT_SPELL_MODIFIER, (1+1+2+2));
        data << uint8(spellflatid);
        data << uint8(op);
        data << uint16(val);
        data << uint16(mark);
        target->GetSession()->SendPacket(&data);

        return true;
    }

    //Edit Player TP
    static bool HandleModifyTalentCommand (ChatHandler* handler, const char* args)
    {
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
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool CheckModifySpeed(ChatHandler* handler, const char* args, Unit* target, float& speed, float minimumBound, float maximumBound, bool checkInFlight = true)
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
    static bool HandleModifyASpeedCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifySpeedCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifySwimCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifyBWalkCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifyFlyCommand(ChatHandler* handler, const char* args)
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
    static bool HandleModifyScaleCommand(ChatHandler* handler, const char* args)
    {
        float Scale;
        Unit* target = handler->getSelectedUnit();
        if (CheckModifySpeed(handler, args, target, Scale, 0.1f, 10.0f, false))
        {
            NotifyModification(handler, target, LANG_YOU_CHANGE_SIZE, LANG_YOURS_SIZE_CHANGED, Scale);
            target->SetObjectScale(Scale);
            return true;
        }
        return false;
    }

    //Enable Player mount
    static bool HandleModifyMountCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint16 mId = 1147;
        float speed = (float)15;
        uint32 num = 0;

        num = atoi((char*)args);
        switch (num)
        {
        case 1:
            mId=14340;
            break;
        case 2:
            mId=4806;
            break;
        case 3:
            mId=6471;
            break;
        case 4:
            mId=12345;
            break;
        case 5:
            mId=6472;
            break;
        case 6:
            mId=6473;
            break;
        case 7:
            mId=10670;
            break;
        case 8:
            mId=10719;
            break;
        case 9:
            mId=10671;
            break;
        case 10:
            mId=10672;
            break;
        case 11:
            mId=10720;
            break;
        case 12:
            mId=14349;
            break;
        case 13:
            mId=11641;
            break;
        case 14:
            mId=12244;
            break;
        case 15:
            mId=12242;
            break;
        case 16:
            mId=14578;
            break;
        case 17:
            mId=14579;
            break;
        case 18:
            mId=14349;
            break;
        case 19:
            mId=12245;
            break;
        case 20:
            mId=14335;
            break;
        case 21:
            mId=207;
            break;
        case 22:
            mId=2328;
            break;
        case 23:
            mId=2327;
            break;
        case 24:
            mId=2326;
            break;
        case 25:
            mId=14573;
            break;
        case 26:
            mId=14574;
            break;
        case 27:
            mId=14575;
            break;
        case 28:
            mId=604;
            break;
        case 29:
            mId=1166;
            break;
        case 30:
            mId=2402;
            break;
        case 31:
            mId=2410;
            break;
        case 32:
            mId=2409;
            break;
        case 33:
            mId=2408;
            break;
        case 34:
            mId=2405;
            break;
        case 35:
            mId=14337;
            break;
        case 36:
            mId=6569;
            break;
        case 37:
            mId=10661;
            break;
        case 38:
            mId=10666;
            break;
        case 39:
            mId=9473;
            break;
        case 40:
            mId=9476;
            break;
        case 41:
            mId=9474;
            break;
        case 42:
            mId=14374;
            break;
        case 43:
            mId=14376;
            break;
        case 44:
            mId=14377;
            break;
        case 45:
            mId=2404;
            break;
        case 46:
            mId=2784;
            break;
        case 47:
            mId=2787;
            break;
        case 48:
            mId=2785;
            break;
        case 49:
            mId=2736;
            break;
        case 50:
            mId=2786;
            break;
        case 51:
            mId=14347;
            break;
        case 52:
            mId=14346;
            break;
        case 53:
            mId=14576;
            break;
        case 54:
            mId=9695;
            break;
        case 55:
            mId=9991;
            break;
        case 56:
            mId=6448;
            break;
        case 57:
            mId=6444;
            break;
        case 58:
            mId=6080;
            break;
        case 59:
            mId=6447;
            break;
        case 60:
            mId=4805;
            break;
        case 61:
            mId=9714;
            break;
        case 62:
            mId=6448;
            break;
        case 63:
            mId=6442;
            break;
        case 64:
            mId=14632;
            break;
        case 65:
            mId=14332;
            break;
        case 66:
            mId=14331;
            break;
        case 67:
            mId=8469;
            break;
        case 68:
            mId=2830;
            break;
        case 69:
            mId=2346;
            break;
        default:
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

        NotifyModification(handler, target, LANG_YOU_GIVE_MOUNT, LANG_MOUNT_GIVED);

        target->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP);
        target->Mount(mId);

        WorldPacket data(SMSG_FORCE_RUN_SPEED_CHANGE, (8+4+1+4));
        data << target->GetPackGUID();
        data << (uint32)0;
        data << (uint8)0;                                       //new 2.1.0
        data << float(speed);
        target->SendMessageToSet(&data, true);

        data.Initialize(SMSG_FORCE_SWIM_SPEED_CHANGE, (8+4+4));
        data << target->GetPackGUID();
        data << (uint32)0;
        data << float(speed);
        target->SendMessageToSet(&data, true);

        return true;
    }

    //Edit Player money
    static bool HandleModifyMoneyCommand(ChatHandler* handler, const char* args)
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

        int32 moneyToAdd = 0;
        if (strchr(args, 'g') || strchr(args, 's') || strchr(args, 'c'))
            moneyToAdd = MoneyStringToMoney(std::string(args));
        else
            moneyToAdd = atoi(args);

        uint32 targetMoney = target->GetMoney();

        if (moneyToAdd < 0)
        {
            int32 newmoney = int32(targetMoney) + moneyToAdd;

            TC_LOG_DEBUG("misc", handler->GetTrinityString(LANG_CURRENT_MONEY), targetMoney, moneyToAdd, newmoney);
            if (newmoney <= 0)
            {
                NotifyModification(handler, target, LANG_YOU_TAKE_ALL_MONEY, LANG_YOURS_ALL_MONEY_GONE);
                target->SetMoney(0);
            }
            else
            {
                if (newmoney > static_cast<int32>(MAX_MONEY_AMOUNT))
                    newmoney = MAX_MONEY_AMOUNT;

                handler->PSendSysMessage(LANG_YOU_TAKE_MONEY, abs(moneyToAdd), handler->GetNameLink(target).c_str());
                if (handler->needReportToTarget(target))
                    ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_MONEY_TAKEN, handler->GetNameLink().c_str(), abs(moneyToAdd));
                target->SetMoney(newmoney);
            }
        }
        else
        {
            handler->PSendSysMessage(LANG_YOU_GIVE_MONEY, moneyToAdd, handler->GetNameLink(target).c_str());
            if (handler->needReportToTarget(target))
                ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOURS_MONEY_GIVEN, handler->GetNameLink().c_str(), moneyToAdd);

            if (targetMoney >= MAX_MONEY_AMOUNT - moneyToAdd)
                moneyToAdd -= targetMoney;

            target->ModifyMoney(moneyToAdd);
        }

        TC_LOG_DEBUG("misc", handler->GetTrinityString(LANG_NEW_MONEY), targetMoney, moneyToAdd, target->GetMoney());

        return true;
    }

    //Edit Unit field
    static bool HandleModifyBitCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity(target->ToPlayer(), ObjectGuid::Empty))
            return false;

        char* pField = strtok((char*)args, " ");
        if (!pField)
            return false;

        char* pBit = strtok(NULL, " ");
        if (!pBit)
            return false;

        uint16 field = atoi(pField);
        uint32 bit   = atoi(pBit);

        if (field < OBJECT_END || field >= target->GetValuesCount())
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (bit < 1 || bit > 32)
        {
            handler->SendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->HasFlag(field, (1<<(bit-1))))
        {
            target->RemoveFlag(field, (1<<(bit-1)));
            handler->PSendSysMessage(LANG_REMOVE_BIT, bit, field);
        }
        else
        {
            target->SetFlag(field, (1<<(bit-1)));
            handler->PSendSysMessage(LANG_SET_BIT, bit, field);
        }
        return true;
    }

    static bool HandleModifyHonorCommand (ChatHandler* handler, const char* args)
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

        int32 amount = (uint32)atoi(args);

        target->ModifyHonorPoints(amount);

        handler->PSendSysMessage(LANG_COMMAND_MODIFY_HONOR, handler->GetNameLink(target).c_str(), target->GetHonorPoints());

        return true;
    }

    static bool HandleModifyDrunkCommand(ChatHandler* handler, const char* args)
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

    static bool HandleModifyRepCommand(ChatHandler* handler, const char* args)
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
        char *rankTxt = strtok(NULL, " ");
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
                    char *deltaTxt = strtok(NULL, " ");
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

        if (factionEntry->reputationListID < 0)
        {
            handler->PSendSysMessage(LANG_COMMAND_FACTION_NOREP_ERROR, factionEntry->name[handler->GetSessionDbcLocale()], factionId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        target->GetReputationMgr().SetOneFactionReputation(factionEntry, amount, false);
        target->GetReputationMgr().SendState(target->GetReputationMgr().GetState(factionEntry));
        handler->PSendSysMessage(LANG_COMMAND_MODIFY_REP, factionEntry->name[handler->GetSessionDbcLocale()], factionId,
            handler->GetNameLink(target).c_str(), target->GetReputationMgr().GetReputation(factionEntry));
        return true;
    }

    //morph creature or player
    static bool HandleModifyMorphCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint16 display_id = (uint16)atoi((char*)args);

        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        // check online security
        else if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity(target->ToPlayer(), ObjectGuid::Empty))
            return false;

        target->SetDisplayId(display_id);

        return true;
    }

    //set temporary phase mask for player
    static bool HandleModifyPhaseCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 phasemask = (uint32)atoi((char*)args);

        Unit* target = handler->getSelectedUnit();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        // check online security
        else if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity(target->ToPlayer(), ObjectGuid::Empty))
            return false;

        target->SetPhaseMask(phasemask, true);

        return true;
    }

    //change standstate
    static bool HandleModifyStandStateCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        uint32 anim_id = atoi((char*)args);
        handler->GetSession()->GetPlayer()->SetUInt32Value(UNIT_NPC_EMOTESTATE, anim_id);

        return true;
    }

    static bool HandleModifyArenaCommand(ChatHandler* handler, const char* args)
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

        int32 amount = (uint32)atoi(args);

        target->ModifyArenaPoints(amount);

        handler->PSendSysMessage(LANG_COMMAND_MODIFY_ARENA, handler->GetNameLink(target).c_str(), target->GetArenaPoints());

        return true;
    }

    static bool HandleModifyGenderCommand(ChatHandler* handler, const char* args)
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
        target->SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, gender);
        target->SetByteValue(PLAYER_BYTES_3, PLAYER_BYTES_3_OFFSET_GENDER, gender);

        // Change display ID
        target->InitDisplayIds();

        char const* gender_full = gender ? "female" : "male";

        handler->PSendSysMessage(LANG_YOU_CHANGE_GENDER, handler->GetNameLink(target).c_str(), gender_full);

        if (handler->needReportToTarget(target))
            ChatHandler(target->GetSession()).PSendSysMessage(LANG_YOUR_GENDER_CHANGED, gender_full, handler->GetNameLink().c_str());

        return true;
    }
//demorph player or unit
    static bool HandleDeMorphCommand(ChatHandler* handler, const char* /*args*/)
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

    // mod xp command
    static bool HandleModifyXPCommand(ChatHandler *handler, const char* args)
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
};

void AddSC_modify_commandscript()
{
    new modify_commandscript();
}
