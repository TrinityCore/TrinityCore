/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
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
#include "DBCStores.h"
#include "WorldPacket.h"
#include "Player.h"
#include "Bag.h"
#include "Opcodes.h"
#include "Chat.h"
#include "Log.h"
#include "Language.h"
#include "BattleGroundMgr.h"
#include <fstream>
#include "ObjectMgr.h"
#include "ObjectGuid.h"
#include "SpellMgr.h"
#include "SpellModMgr.h"
#include "World.h"
#include "ScriptMgr.h"
#include "Conditions.h"
 // VMAPS
#include "VMapFactory.h"
#include "ModelInstance.h"
 // MMAPS
#include "MoveMap.h"                                        // for mmap manager
#include "PathFinder.h"                                     // for mmap commands
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"

bool ChatHandler::HandleSpellIconFixCommand(char *args)
{
    uint32 spellId = ExtractSpellIdFromLink(&args);
    if (!spellId)
        return false;
    WorldDatabase.PExecute("REPLACE INTO spell_mod SET SpellIconID=1, Comment='Fix SpellIconID', Id=%u;", spellId);
    sSpellModMgr.LoadSpellMods();
    return true;
}

bool ChatHandler::HandleSpellEffectsCommand(char *args)
{
    uint32 spellId = ExtractSpellIdFromLink(&args);
    if (!spellId)
        return false;
    SpellEntry const* pSpell = sSpellMgr.GetSpellEntry(spellId);
    if (!pSpell)
    {
        PSendSysMessage("Sort %u inexistant dans les DBCs.", spellId);
        SetSentErrorMessage(true);
        return false;
    }
    LocaleConstant loc = GetSessionDbcLocale();
    ShowSpellListHelper(nullptr, pSpell, loc);
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        if (pSpell->Effect[i] == 0)
        {
            PSendSysMessage("[*] Pas d'effet %u", i);
            continue;
        }
        PSendSysMessage("[*] Effect[%u] = %u", i, pSpell->Effect[i]);
        PSendSysMessage("- EffectBasePoints          : %i", pSpell->EffectBasePoints[i]);
        PSendSysMessage("- EffectMechanic            : %u", pSpell->EffectMechanic[i]);
        PSendSysMessage("- EffectApplyAuraName       : %u", pSpell->EffectApplyAuraName[i]);
        PSendSysMessage("- EffectAmplitude           : %u", pSpell->EffectAmplitude[i]);
        PSendSysMessage("- EffectMiscValue           : %i", pSpell->EffectMiscValue[i]);
        PSendSysMessage("- EffectPointsPerComboPoint : %f", pSpell->EffectPointsPerComboPoint[i]);
        PSendSysMessage("- CalculateSimpleValue      : %i", pSpell->CalculateSimpleValue(SpellEffectIndex(i)));
        PSendSysMessage("- EffectTriggerSpell        : %u", pSpell->EffectTriggerSpell[i]);
        PSendSysMessage("- EffectDieSides            : %i", pSpell->EffectDieSides[i]);
        PSendSysMessage("- EffectDicePerLevel        : %f", pSpell->EffectDicePerLevel[i]);
        PSendSysMessage("- EffectImplicitTarget [A=%u:B=%u]", pSpell->EffectImplicitTargetA[i], pSpell->EffectImplicitTargetB[i]);
        PSendSysMessage("- EffectRadiusIndex         : %u", pSpell->EffectRadiusIndex[i]);
        PSendSysMessage("- EffectItemType            : %u", pSpell->EffectItemType[i]);
        if (pSpell->Effect[i] == SPELL_EFFECT_ENCHANT_ITEM ||
                pSpell->Effect[i] == SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY ||
                pSpell->Effect[i] == SPELL_EFFECT_ENCHANT_HELD_ITEM)
        {
            SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(pSpell->EffectMiscValue[i]);
            if (pEnchant)
            {
                PSendSysMessage("* Enchantement id %u [Aura`%u`:Slot`%u]`", pSpell->EffectMiscValue[i], pEnchant->aura_id, pEnchant->slot);
                for (uint32 type_idx = 0; type_idx < 3; ++type_idx)
                    PSendSysMessage("** %u [type`%u`|amount`%u`|spellid`%u`]", type_idx, pEnchant->type[type_idx], pEnchant->amount[type_idx], pEnchant->spellid[type_idx]);
            }
            else
                PSendSysMessage("* Enchantement invalide (id %u)", pSpell->EffectMiscValue[i]);
        }

        if (SpellEntry const* pTriggered = sSpellMgr.GetSpellEntry(pSpell->EffectTriggerSpell[i]))
            ShowSpellListHelper(nullptr, pTriggered, loc);
        else
            PSendSysMessage("(existe pas)");
    }
    return true;
}

bool ChatHandler::HandleSpellInfosCommand(char *args)
{
    uint32 spellId = ExtractSpellIdFromLink(&args);
    if (!spellId)
        return false;
    SpellEntry const* pSpell = sSpellMgr.GetSpellEntry(spellId);
    if (!pSpell)
    {
        PSendSysMessage("Spell %u does not exist.", spellId);
        SetSentErrorMessage(true);
        return false;
    }
    LocaleConstant loc = GetSessionDbcLocale();
    ShowSpellListHelper(nullptr, pSpell, loc);

    PSendSysMessage("School%u:Category%u:Dispel%u:Mechanic%u", pSpell->School, pSpell->Category, pSpell->Dispel, pSpell->Mechanic);
    PSendSysMessage("Attributes0x%x:Ex[0x%x:0x%x:0x%x:0x%x]", pSpell->Attributes, pSpell->AttributesEx, pSpell->AttributesEx2, pSpell->AttributesEx3, pSpell->AttributesEx4);
    PSendSysMessage("RequiresSpellFocus%u:StackAmount%u", pSpell->RequiresSpellFocus, pSpell->StackAmount);
    PSendSysMessage("SpellIconID%u:SpellVisual%u:activeIconID%u", pSpell->SpellIconID, pSpell->SpellVisual, pSpell->activeIconID);
    PSendSysMessage("SpellFamilyName%u:SpellFamilyFlags0x%llx", pSpell->SpellFamilyName, pSpell->SpellFamilyFlags);
    PSendSysMessage("MaxTargetLevel%u:DmgClass%u:rangeIndex%u", pSpell->MaxTargetLevel, pSpell->DmgClass, pSpell->rangeIndex);
    PSendSysMessage("procChance%u:procFlags0x%x:procCharges%u", pSpell->procChance, pSpell->procFlags, pSpell->procCharges);
    PSendSysMessage("InterruptFlags0x%x:AuraInterruptFlags0x%x:PreventionType%x:spellLevel%u", pSpell->InterruptFlags, pSpell->AuraInterruptFlags, pSpell->PreventionType, pSpell->spellLevel);
    PSendSysMessage("SpellSpecific%u:Binaire%s:spellPriority%u:Positive%u", Spells::GetSpellSpecific(pSpell->Id), pSpell->IsBinary() ? "OUI" : "NON", pSpell->spellPriority, pSpell->IsPositiveSpell());
    PSendSysMessage("RecoveryTime%u:CategoryRecoveryTime%u:PvEHeartBeat%s", pSpell->RecoveryTime, pSpell->CategoryRecoveryTime, pSpell->IsPvEHeartBeat() ? "OUI" : "NON");
    return true;
}

bool ChatHandler::HandleSpellSearchCommand(char *args)
{
    if (!args)
        return false;

    uint32 familyName = 0;
    uint32 familyFlags = 0;
    uint32 results = 0;
    sscanf(args, "%u %x", &familyName, &familyFlags);
    if (!familyFlags)
        return false;
    PSendSysMessage("* Results for SpellFamilyName %u and SpellFamilyFlags & 0x%x", familyName, familyFlags);
    LocaleConstant loc = GetSessionDbcLocale();
    SpellEntry const* pSpell = nullptr;
    for (uint32 id = 0; id < sSpellMgr.GetMaxSpellId(); ++id)
    {
        pSpell = sSpellMgr.GetSpellEntry(id);
        if (!pSpell)
            continue;
        if (pSpell->SpellFamilyName == familyName && pSpell->SpellFamilyFlags & familyFlags)
        {
            ShowSpellListHelper(nullptr, pSpell, loc);
            ++results;
        }
    }
    if (results == 0)
        SendSysMessage("-- No spell found");
    else if (results == 1)
        SendSysMessage("-- 1 spell found.");
    else
        PSendSysMessage("-- %u spells found.", results);
    return true;
}

bool ChatHandler::HandleDebugSendSpellFailCommand(char* args)
{
    if (!*args)
        return false;

    uint32 failnum;
    if (!ExtractUInt32(&args, failnum) || failnum > 255)
        return false;

    uint32 failarg1;
    if (!ExtractOptUInt32(&args, failarg1, 0))
        return false;

    uint32 failarg2;
    if (!ExtractOptUInt32(&args, failarg2, 0))
        return false;

    char* unk = strtok(nullptr, " ");
    uint8 unkI = unk ? (uint8)atoi(unk) : 2;

    WorldPacket data(SMSG_CAST_RESULT, 4 + 1 + 1);
    data << uint32(133);
    data << uint8(unkI);
    data << uint8(failnum);
    if (failarg1 || failarg2)
        data << uint32(failarg1);
    if (failarg2)
        data << uint32(failarg2);

    m_session->SendPacket(&data);

    return true;
}

bool ChatHandler::HandleDebugSendNextChannelSpellVisualCommand(char *args)
{
    uint32 uiPlayId = 0;
    char* playIdStr = strtok(args, " ");
    if (playIdStr)
        uiPlayId = int32(atoi(playIdStr));

    if (uiPlayId == -1)
    {
        m_session->GetPlayer()->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
        WorldPacket data(MSG_CHANNEL_UPDATE, (4));
        data << uint32(0);
        m_session->GetPlayer()->SendDirectMessage(&data);
        PSendSysMessage("Sending channel stop");
        return true;
    }
    uint32 id = 0;
    SpellEntry const* spellInfo = nullptr;
    for (id = uiPlayId + 1; id <= sSpellMgr.GetMaxSpellId(); id++)
    {
        spellInfo = sSpellMgr.GetSpellEntry(id);
        if (!spellInfo || uiPlayId >= spellInfo->Id || !spellInfo->SpellVisual || !spellInfo->IsChanneledSpell())
            continue;
        else
            break;
    }
    if (id && id <= sSpellMgr.GetMaxSpellId())
    {
        WorldPacket data(MSG_CHANNEL_START, (4 + 4));
        data << uint32(id);
        data << uint32(60000);
        m_session->GetPlayer()->SendDirectMessage(&data);
        m_session->GetPlayer()->SetUInt32Value(UNIT_CHANNEL_SPELL, id);
        PSendSysMessage("Playing channel visual of spell %u %s %s", id, spellInfo->SpellName[0].c_str(), spellInfo->Rank[0].c_str());
        return true;
    }
    PSendSysMessage("Spell Id range 0 to %u, -1 to stop animation", sSpellMgr.GetMaxSpellId());
    return true;
}

bool ChatHandler::HandleSendSpellChannelVisualCommand(char *args)
{
    uint32 uiPlayId = 0;
    char* playIdStr = strtok(args, " ");
    if (playIdStr)
        uiPlayId = int32(atoi(playIdStr));

    if (uiPlayId && uiPlayId <= sSpellMgr.GetMaxSpellId())
    {
        WorldPacket data(MSG_CHANNEL_START, (4 + 4));
        data << uint32(uiPlayId);
        data << uint32(60000);
        m_session->GetPlayer()->SendDirectMessage(&data);
        m_session->GetPlayer()->SetUInt32Value(UNIT_CHANNEL_SPELL, uiPlayId);
        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(uiPlayId);
        PSendSysMessage("Playing channel visual of spell %u %s %s", uiPlayId, spellInfo->SpellName[0].c_str(), spellInfo->Rank[0].c_str());
        return true;
    }
    else if (!uiPlayId)
    {
        m_session->GetPlayer()->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
        WorldPacket data(MSG_CHANNEL_UPDATE, (4));
        data << uint32(0);
        m_session->GetPlayer()->SendDirectMessage(&data);
        PSendSysMessage("Sending channel stop");
        return true;
    }
    PSendSysMessage("Spell Id range 1 to %u, 0 to stop animation", sSpellMgr.GetMaxSpellId());
    return true;
}

bool ChatHandler::HandleDebugSendPoiCommand(char* args)
{
    Player* pPlayer = m_session->GetPlayer();
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        return true;
    }

    uint32 icon;
    if (!ExtractUInt32(&args, icon))
        return false;

    uint32 flags;
    if (!ExtractUInt32(&args, flags))
        return false;

    DETAIL_LOG("Command : POI, NPC = %u, icon = %u flags = %u", target->GetGUIDLow(), icon, flags);
    pPlayer->PlayerTalkClass->SendPointOfInterest(target->GetPositionX(), target->GetPositionY(), Poi_Icon(icon), flags, 30, "Test POI");
    return true;
}

bool ChatHandler::HandleDebugSendEquipErrorCommand(char* args)
{
    if (!*args)
        return false;

    uint8 msg = atoi(args);
    m_session->GetPlayer()->SendEquipError(InventoryResult(msg), nullptr, nullptr);
    return true;
}

bool ChatHandler::HandleDebugSendMailErrorCommand(char* args)
{
    if (!*args)
        return false;

    uint32 mailId;
    if (!ExtractUInt32(&args, mailId))
        return false;

    uint32 mailAction;
    if (!ExtractUInt32(&args, mailAction))
        return false;

    uint32 mailError;
    if (!ExtractUInt32(&args, mailError))
        return false;

    uint8 msg = atoi(args);
    m_session->SendMailResult(mailId, MailResponseType(mailAction), MailResponseResult(mailError));
    return true;
}

bool ChatHandler::HandleDebugSendSellErrorCommand(char* args)
{
    if (!*args)
        return false;

    uint8 msg = atoi(args);
    m_session->GetPlayer()->SendSellError(SellResult(msg), 0, ObjectGuid(), 0);
    return true;
}

bool ChatHandler::HandleDebugSendBuyErrorCommand(char* args)
{
    if (!*args)
        return false;

    uint8 msg = atoi(args);
    m_session->GetPlayer()->SendBuyError(BuyResult(msg), 0, 0, 0);
    return true;
}

bool ChatHandler::HandleDebugSendOpenBagCommand(char *args)
{
    Player* pTarget = GetSelectedPlayer();
    if (!pTarget)
    {
        SendSysMessage(LANG_PLAYER_NOT_FOUND);
        SetSentErrorMessage(true);
        return false;
    }

    pTarget->SendOpenContainer();
    return true;
}

bool ChatHandler::HandleDebugSendOpcodeCommand(char* /*args*/)
{
    Unit* unit = GetSelectedUnit();
    if (!unit || (unit->GetTypeId() != TYPEID_PLAYER))
        unit = m_session->GetPlayer();

    std::ifstream ifs("opcode.txt");
    if (ifs.bad())
        return false;

    uint32 opcode;
    ifs >> opcode;

    WorldPacket data(opcode, 0);

    while (!ifs.eof())
    {
        std::string type;
        ifs >> type;

        if (type.empty())
            break;

        if (type == "uint8")
        {
            uint16 val1;
            ifs >> val1;
            data << uint8(val1);
        }
        else if (type == "uint16")
        {
            uint16 val2;
            ifs >> val2;
            data << val2;
        }
        else if (type == "uint32")
        {
            uint32 val3;
            ifs >> val3;
            data << val3;
        }
        else if (type == "uint64")
        {
            uint64 val4;
            ifs >> val4;
            data << val4;
        }
        else if (type == "float")
        {
            float val5;
            ifs >> val5;
            data << val5;
        }
        else if (type == "string")
        {
            std::string val6;
            ifs >> val6;
            data << val6;
        }
        else if (type == "pguid")
            data << unit->GetPackGUID();
        else
        {
            DEBUG_LOG("Sending opcode: unknown type '%s'", type.c_str());
            break;
        }
    }
    ifs.close();
    DEBUG_LOG("Sending opcode %u", data.GetOpcode());
    data.hexlike();
    m_session->SendPacket(&data);
    PSendSysMessage(LANG_COMMAND_OPCODESENT, data.GetOpcode(), unit->GetName());
    return true;
}

bool ChatHandler::HandleDebugUpdateWorldStateCommand(char* args)
{
    uint32 world;
    if (!ExtractUInt32(&args, world))
        return false;

    uint32 state;
    if (!ExtractUInt32(&args, state))
        return false;

    m_session->GetPlayer()->SendUpdateWorldState(world, state);
    return true;
}

bool ChatHandler::HandleDebugPlayCinematicCommand(char* args)
{
    // USAGE: .debug play cinematic #cinematicid
    // #cinematicid - ID decimal number from CinemaicSequences.dbc (1st column)
    uint32 dwId;
    if (!ExtractUInt32(&args, dwId))
        return false;

    if (!sCinematicSequencesStore.LookupEntry(dwId))
    {
        PSendSysMessage(LANG_CINEMATIC_NOT_EXIST, dwId);
        SetSentErrorMessage(true);
        return false;
    }

    m_session->GetPlayer()->SendCinematicStart(dwId);
    return true;
}

//Play sound
bool ChatHandler::HandleDebugPlaySoundCommand(char* args)
{
    // USAGE: .debug playsound #soundid
    // #soundid - ID decimal number from SoundEntries.dbc (1st column)
    uint32 dwSoundId;

    if (!ExtractUint32KeyFromLink(&args, "Hsound", dwSoundId))
    {
        PSendSysMessage(LANG_SOUND_NOT_EXIST, dwSoundId);
        SetSentErrorMessage(true);
        return false;
    }

    if (!sObjectMgr.GetSoundEntry(dwSoundId))
    {
        PSendSysMessage(LANG_SOUND_NOT_EXIST, dwSoundId);
        SetSentErrorMessage(true);
        return false;
    }

    Unit* unit = GetSelectedUnit();
    if (!unit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (m_session->GetPlayer()->GetSelectionGuid())
        unit->PlayDistanceSound(dwSoundId, m_session->GetPlayer());
    else
        unit->PlayDirectSound(dwSoundId, m_session->GetPlayer());

    PSendSysMessage(LANG_YOU_HEAR_SOUND, dwSoundId);
    return true;
}

bool ChatHandler::HandleDebugPlayMusicCommand(char* args)
{
    uint32 dwSoundId;

    if (!ExtractUint32KeyFromLink(&args, "Hsound", dwSoundId))
    {
        PSendSysMessage(LANG_SOUND_NOT_EXIST, dwSoundId);
        SetSentErrorMessage(true);
        return false;
    }

    if (!sObjectMgr.GetSoundEntry(dwSoundId))
    {
        PSendSysMessage(LANG_SOUND_NOT_EXIST, dwSoundId);
        SetSentErrorMessage(true);
        return false;
    }

    Player* target;

    if (!ExtractPlayerTarget(&args, &target, nullptr, nullptr))
        return false;

    if (target->GetSession() != GetSession() && GetSession()->GetSecurity() < SEC_ADMINISTRATOR)
    {
        PSendSysMessage(LANG_YOURS_SECURITY_IS_LOW);
        SetSentErrorMessage(true);
        return false;
    }

    WorldPacket data(SMSG_PLAY_MUSIC, 4);
    data << int32(dwSoundId);
    target->SendDirectMessage(&data);

    PSendSysMessage(LANG_YOU_HEAR_SOUND, dwSoundId);
    return true;
}

bool ChatHandler::HandleDebugPlayScriptText(char* args)
{
    int32 textId;

    if (!ExtractInt32(&args, textId))
        return false;

    Unit* pSource = GetSelectedUnit();
    Unit* pTarget = m_session->GetPlayer();

    if (pSource && pTarget)
        DoScriptText(textId, pSource, pTarget);

    return true;
}

bool ChatHandler::HandleDebugConditionCommand(char* args)
{
    int32 conditionId;

    if (!ExtractInt32(&args, conditionId))
        return false;

    Unit* pSource = GetSelectedUnit();
    Unit* pTarget = m_session->GetPlayer();

    if (pSource && pTarget)
    {
        if (IsConditionSatisfied(conditionId, pTarget, pSource->GetMap(), pSource, CONDITION_FROM_DBSCRIPTS))
            SendSysMessage("Condition is satisfied.");
        else
            SendSysMessage("Condition is not satisfied.");
    }

    return true;
}

//Send notification in channel
bool ChatHandler::HandleDebugSendChannelNotifyCommand(char* args)
{
    char const* name = "test";

    uint32 code;
    if (!ExtractUInt32(&args, code) || code > 255)
        return false;

    WorldPacket data(SMSG_CHANNEL_NOTIFY, (1 + 10));
    data << uint8(code);                                    // notify type
    data << name;                                           // channel name
    data << uint32(0);
    data << uint32(0);
    m_session->SendPacket(&data);
    return true;
}

//Send notification in chat
bool ChatHandler::HandleDebugSendChatMsgCommand(char* args)
{
    char const* msg = "testtest";

    uint32 type;
    if (!ExtractUInt32(&args, type) || type > 255)
        return false;

    WorldPacket data;
    ChatHandler::BuildChatPacket(data, ChatMsg(type), msg, LANG_UNIVERSAL, CHAT_TAG_NONE, m_session->GetPlayer()->GetObjectGuid(), m_session->GetPlayerName());
    m_session->SendPacket(&data);
    return true;
}

bool ChatHandler::HandleDebugSendQuestPartyMsgCommand(char* args)
{
    uint32 msg;
    if (!ExtractUInt32(&args, msg))
        return false;
    if (msg > 0xFF)
        return false;

    m_session->GetPlayer()->SendPushToPartyResponse(m_session->GetPlayer(), uint8(msg));
    return true;
}

bool ChatHandler::HandleDebugGetLootRecipientCommand(char* /*args*/)
{
    Creature* target = GetSelectedCreature();
    if (!target)
        return false;

    if (!target->HasLootRecipient())
        SendSysMessage("loot recipient: no loot recipient");
    else if (Player* recipient = target->GetLootRecipient())
        PSendSysMessage("loot recipient: %s with raw data %s from group %u",
                        recipient->GetGuidStr().c_str(),
                        target->GetLootRecipientGuid().GetString().c_str(),
                        target->GetLootGroupRecipientId());
    else
        SendSysMessage("loot recipient: offline ");

    return true;
}

bool ChatHandler::HandleDebugSendQuestInvalidMsgCommand(char* args)
{
    uint32 msg = atol(args);
    m_session->GetPlayer()->SendCanTakeQuestResponse(msg);
    return true;
}

bool ChatHandler::HandleDebugGetItemStateCommand(char* args)
{
    if (!*args)
        return false;

    ItemUpdateState state = ITEM_UNCHANGED;
    bool list_queue = false, check_all = false;

    std::string state_str;

    if (strncmp(args, "unchanged", strlen(args)) == 0)
    {
        state = ITEM_UNCHANGED;
        state_str = "unchanged";
    }
    else if (strncmp(args, "changed", strlen(args)) == 0)
    {
        state = ITEM_CHANGED;
        state_str = "changed";
    }
    else if (strncmp(args, "new", strlen(args)) == 0)
    {
        state = ITEM_NEW;
        state_str = "new";
    }
    else if (strncmp(args, "removed", strlen(args)) == 0)
    {
        state = ITEM_REMOVED;
        state_str = "removed";
    }
    else if (strncmp(args, "queue", strlen(args)) == 0)
        list_queue = true;
    else if (strncmp(args, "all", strlen(args)) == 0)
        check_all = true;
    else
        return false;

    Player* player = GetSelectedPlayer();
    if (!player) player = m_session->GetPlayer();

    if (!list_queue && !check_all)
    {
        state_str = "The player has the following " + state_str + " items: ";
        SendSysMessage(state_str.c_str());
        for (uint8 i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
        {
            if (i >= BUYBACK_SLOT_START && i < BUYBACK_SLOT_END)
                continue;

            Item *item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (!item) continue;
            if (!item->IsBag())
            {
                if (item->GetState() == state)
                    PSendSysMessage("%s bag: 255 slot: %u owner: %s",
                                    item->GetGuidStr().c_str(),  item->GetSlot(), item->GetOwnerGuid().GetString().c_str());
            }
            else
            {
                Bag *bag = (Bag*)item;
                for (uint8 j = 0; j < bag->GetBagSize(); ++j)
                {
                    Item* item2 = bag->GetItemByPos(j);
                    if (item2 && item2->GetState() == state)
                        PSendSysMessage("%s bag: %u slot: %u owner: %s",
                                        item2->GetGuidStr().c_str(), item2->GetBagSlot(), item2->GetSlot(),
                                        item2->GetOwnerGuid().GetString().c_str());
                }
            }
        }
    }

    if (list_queue)
    {
        std::vector<Item *>& updateQueue = player->GetItemUpdateQueue();
        for (const auto item : updateQueue)
        {
            if (!item) continue;

            Bag *container = item->GetContainer();
            uint8 bag_slot = container ? container->GetSlot() : uint8(INVENTORY_SLOT_BAG_0);

            std::string st;
            switch (item->GetState())
            {
                case ITEM_UNCHANGED:
                    st = "unchanged";
                    break;
                case ITEM_CHANGED:
                    st = "changed";
                    break;
                case ITEM_NEW:
                    st = "new";
                    break;
                case ITEM_REMOVED:
                    st = "removed";
                    break;
            }

            PSendSysMessage("%s bag: %u slot: %u - state: %s",
                            item->GetGuidStr().c_str(), bag_slot, item->GetSlot(), st.c_str());
        }
        if (updateQueue.empty())
            PSendSysMessage("updatequeue empty");
    }

    if (check_all)
    {
        bool error = false;
        std::vector<Item *>& updateQueue = player->GetItemUpdateQueue();
        for (uint8 i = PLAYER_SLOT_START; i < PLAYER_SLOT_END; ++i)
        {
            if (i >= BUYBACK_SLOT_START && i < BUYBACK_SLOT_END)
                continue;

            Item *item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
            if (!item) continue;

            if (item->GetSlot() != i)
            {
                PSendSysMessage("%s at slot %u has an incorrect slot value: %d",
                                item->GetGuidStr().c_str(), i, item->GetSlot());
                error = true;
                continue;
            }

            if (item->GetOwnerGuid() != player->GetObjectGuid())
            {
                PSendSysMessage("%s at slot %u owner (%s) and inventory owner (%s) don't match!",
                                item->GetGuidStr().c_str(), item->GetSlot(),
                                item->GetOwnerGuid().GetString().c_str(), player->GetGuidStr().c_str());
                error = true;
                continue;
            }

            if (Bag *container = item->GetContainer())
            {
                PSendSysMessage("%s at slot %u has a container %s from slot %u but shouldnt!",
                                item->GetGuidStr().c_str(), item->GetSlot(),
                                container->GetGuidStr().c_str(), container->GetSlot());
                error = true;
                continue;
            }

            if (item->IsInUpdateQueue())
            {
                uint16 qp = item->GetQueuePos();
                if (qp > updateQueue.size())
                {
                    PSendSysMessage("%s at slot %u has a queuepos (%d) larger than the update queue size! ",
                                    item->GetGuidStr().c_str(), item->GetSlot(), qp);
                    error = true;
                    continue;
                }

                if (updateQueue[qp] == nullptr)
                {
                    PSendSysMessage("%s at slot %u has a queuepos (%d) that points to nullptr in the queue!",
                                    item->GetGuidStr().c_str(), item->GetSlot(), qp);
                    error = true;
                    continue;
                }

                if (updateQueue[qp] != item)
                {
                    PSendSysMessage("%s at slot %u has a queuepos (%d) that points to %s in the queue (bag %u, slot %u)",
                                    item->GetGuidStr().c_str(), item->GetSlot(), qp,
                                    updateQueue[qp]->GetGuidStr().c_str(), updateQueue[qp]->GetBagSlot(), updateQueue[qp]->GetSlot());
                    error = true;
                    continue;
                }
            }
            else if (item->GetState() != ITEM_UNCHANGED)
            {
                PSendSysMessage("%s at slot %u is not in queue but should be (state: %d)!",
                                item->GetGuidStr().c_str(), item->GetSlot(), item->GetState());
                error = true;
                continue;
            }

            if (item->IsBag())
            {
                Bag *bag = (Bag*)item;
                for (uint8 j = 0; j < bag->GetBagSize(); ++j)
                {
                    Item* item2 = bag->GetItemByPos(j);
                    if (!item2) continue;

                    if (item2->GetSlot() != j)
                    {
                        PSendSysMessage("%s in bag %u at slot %u has an incorrect slot value: %u",
                                        item2->GetGuidStr().c_str(), bag->GetSlot(), j, item2->GetSlot());
                        error = true;
                        continue;
                    }

                    if (item2->GetOwnerGuid() != player->GetObjectGuid())
                    {
                        PSendSysMessage("%s in bag %u at slot %u owner (%s) and inventory owner (%s) don't match!",
                                        item2->GetGuidStr().c_str(), bag->GetSlot(), item2->GetSlot(),
                                        item2->GetOwnerGuid().GetString().c_str(), player->GetGuidStr().c_str());
                        error = true;
                        continue;
                    }

                    Bag *container = item2->GetContainer();
                    if (!container)
                    {
                        PSendSysMessage("%s in bag %u at slot %u has no container!",
                                        item2->GetGuidStr().c_str(), bag->GetSlot(), item2->GetSlot());
                        error = true;
                        continue;
                    }

                    if (container != bag)
                    {
                        PSendSysMessage("%s in bag %u at slot %u has a different container %s from slot %u!",
                                        item2->GetGuidStr().c_str(), bag->GetSlot(), item2->GetSlot(),
                                        container->GetGuidStr().c_str(), container->GetSlot());
                        error = true;
                        continue;
                    }

                    if (item2->IsInUpdateQueue())
                    {
                        uint16 qp = item2->GetQueuePos();
                        if (qp > updateQueue.size())
                        {
                            PSendSysMessage("%s in bag %u at slot %u has a queuepos (%d) larger than the update queue size! ",
                                            item2->GetGuidStr().c_str(), bag->GetSlot(), item2->GetSlot(), qp);
                            error = true;
                            continue;
                        }

                        if (updateQueue[qp] == nullptr)
                        {
                            PSendSysMessage("%s in bag %u at slot %u has a queuepos (%d) that points to nullptr in the queue!",
                                            item2->GetGuidStr().c_str(), bag->GetSlot(), item2->GetSlot(), qp);
                            error = true;
                            continue;
                        }

                        if (updateQueue[qp] != item2)
                        {
                            PSendSysMessage("%s in bag %u at slot %u has a queuepos (%d) that points to %s in the queue (bag %u slot %u)",
                                            item2->GetGuidStr().c_str(), bag->GetSlot(), item2->GetSlot(), qp,
                                            updateQueue[qp]->GetGuidStr().c_str(), updateQueue[qp]->GetBagSlot(), updateQueue[qp]->GetSlot());
                            error = true;
                            continue;
                        }
                    }
                    else if (item2->GetState() != ITEM_UNCHANGED)
                    {
                        PSendSysMessage("%s in bag %u at slot %u is not in queue but should be (state: %d)!",
                                        item2->GetGuidStr().c_str(), bag->GetSlot(), item2->GetSlot(), item2->GetState());
                        error = true;
                        continue;
                    }
                }
            }
        }

        for (size_t i = 0; i < updateQueue.size(); ++i)
        {
            Item *item = updateQueue[i];
            if (!item) continue;

            if (item->GetOwnerGuid() != player->GetObjectGuid())
            {
                PSendSysMessage("queue(" SIZEFMTD "): %s has the owner (%s) and inventory owner (%s) don't match!",
                                i, item->GetGuidStr().c_str(),
                                item->GetOwnerGuid().GetString().c_str(), player->GetGuidStr().c_str());
                error = true;
                continue;
            }

            if (item->GetQueuePos() != i)
            {
                PSendSysMessage("queue(" SIZEFMTD "): %s has queuepos doesn't match it's position in the queue!",
                                i, item->GetGuidStr().c_str());
                error = true;
                continue;
            }

            if (item->GetState() == ITEM_REMOVED) continue;
            Item *test = player->GetItemByPos(item->GetBagSlot(), item->GetSlot());

            if (test == nullptr)
            {
                PSendSysMessage("queue(" SIZEFMTD "): %s has incorrect (bag %u slot %u) values, the player doesn't have an item at that position!",
                                i, item->GetGuidStr().c_str(), item->GetBagSlot(), item->GetSlot());
                error = true;
                continue;
            }

            if (test != item)
            {
                PSendSysMessage("queue(" SIZEFMTD "): %s has incorrect (bag %u slot %u) values, the %s is there instead!",
                                i, item->GetGuidStr().c_str(), item->GetBagSlot(), item->GetSlot(),
                                test->GetGuidStr().c_str());
                error = true;
                continue;
            }
        }
        if (!error)
            SendSysMessage("All OK!");
    }

    return true;
}

bool ChatHandler::HandleDebugBattlegroundCommand(char* /*args*/)
{
    sBattleGroundMgr.ToggleTesting();
    return true;
}

bool ChatHandler::HandleDebugSpellCheckCommand(char* /*args*/)
{
    sLog.outString("Check expected in code spell properties base at table 'spell_check' content...");
    sSpellMgr.CheckUsedSpells("spell_check");
    return true;
}

bool ChatHandler::HandleDebugAnimCommand(char* args)
{
    uint32 emote_id;
    if (!ExtractUInt32(&args, emote_id))
        return false;

    m_session->GetPlayer()->HandleEmoteCommand(emote_id);
    return true;
}

bool ChatHandler::HandleDebugSetAuraStateCommand(char* args)
{
    int32 state;
    if (!ExtractInt32(&args, state))
        return false;

    Unit* unit = GetSelectedUnit();
    if (!unit)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    if (!state)
    {
        // reset all states
        for (int i = 1; i <= 32; ++i)
            unit->ModifyAuraState(AuraState(i), false);
        return true;
    }

    unit->ModifyAuraState(AuraState(abs(state)), state > 0);
    return true;
}

bool ChatHandler::HandleSetValueHelper(Object* target, uint32 field, char* typeStr, char* valStr)
{
    ObjectGuid guid = target->GetObjectGuid();

    // not allow access to nonexistent or critical for work field
    if (field >= target->GetValuesCount() || field <= OBJECT_FIELD_ENTRY)
    {
        PSendSysMessage(LANG_TOO_BIG_INDEX, field, guid.GetString().c_str(), target->GetValuesCount());
        return false;
    }

    uint32 base;                                            // 0 -> float
    if (!typeStr)
        base = 10;
    else if (strncmp(typeStr, "int", strlen(typeStr)) == 0)
        base = 10;
    else if (strncmp(typeStr, "hex", strlen(typeStr)) == 0)
        base = 16;
    else if (strncmp(typeStr, "bit", strlen(typeStr)) == 0)
        base = 2;
    else if (strncmp(typeStr, "float", strlen(typeStr)) == 0)
        base = 0;
    else
        return false;

    if (base)
    {
        uint32 iValue;
        if (!ExtractUInt32Base(&valStr, iValue, base))
            return false;

        DEBUG_LOG(GetMangosString(LANG_SET_UINT), guid.GetString().c_str(), field, iValue);
        target->SetUInt32Value(field , iValue);
        PSendSysMessage(LANG_SET_UINT_FIELD, guid.GetString().c_str(), field, iValue);
    }
    else
    {
        float fValue;
        if (!ExtractFloat(&valStr, fValue))
            return false;

        DEBUG_LOG(GetMangosString(LANG_SET_FLOAT), guid.GetString().c_str(), field, fValue);
        target->SetFloatValue(field , fValue);
        PSendSysMessage(LANG_SET_FLOAT_FIELD, guid.GetString().c_str(), field, fValue);
    }

    return true;
}

bool ChatHandler::HandleDebugSetItemValueCommand(char* args)
{
    uint32 guid;
    if (!ExtractUInt32(&args, guid))
        return false;

    uint32 field;
    if (!ExtractUInt32(&args, field))
        return false;

    char* typeStr = ExtractOptNotLastArg(&args);
    if (!typeStr)
        return false;

    char* valStr = ExtractLiteralArg(&args);
    if (!valStr)
        return false;

    Item *item = m_session->GetPlayer()->GetItemByGuid(ObjectGuid(HIGHGUID_ITEM, guid));
    if (!item)
        return false;

    return HandleSetValueHelper(item, field, typeStr, valStr);
}

bool ChatHandler::HandleDebugSetValueByIndexCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 field;
    if (!ExtractUInt32(&args, field))
        return false;

    char* typeStr = ExtractOptNotLastArg(&args);
    if (!typeStr)
        return false;

    char* valStr = ExtractLiteralArg(&args);
    if (!valStr)
        return false;

    return HandleSetValueHelper(target, field, typeStr, valStr);
}

bool ChatHandler::HandleDebugSetValueByNameCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    char* fieldName = ExtractQuotedOrLiteralArg(&args);
    if (!fieldName)
        return false;

    if (UpdateFieldData const* pField = UpdateFields::GetUpdateFieldDataByName(fieldName))
    {
        if ((pField->objectTypeMask & target->GetTypeMask()) == 0)
        {
            SendSysMessage("Target does have that field.");
            return true;
        }

        switch (pField->valueType)
        {
            case UF_TYPE_INT:
            {
                uint32 value;
                if (!ExtractUInt32(&args, value))
                    return false;

                target->SetUInt32Value(pField->offset, value);
                PSendSysMessage("Field %s of %s set to %u.", pField->name, target->GetName(), value);
                break;
            }
            case UF_TYPE_TWO_SHORT:
            {
                uint32 value1;
                if (!ExtractUInt32(&args, value1))
                    return false;

                uint32 value2;
                if (!ExtractUInt32(&args, value2))
                    return false;

                target->SetUInt16Value(pField->offset, 0, value1);
                target->SetUInt16Value(pField->offset, 1, value2);
                PSendSysMessage("Field %s of %s set to %u/%u.", pField->name, target->GetName(), value1, value2);
                break;
            }
            case UF_TYPE_FLOAT:
            {
                float value;
                if (!ExtractFloat(&args, value))
                    return false;

                target->SetFloatValue(pField->offset, value);
                PSendSysMessage("Field %s of %s set to %g.", pField->name, target->GetName(), value);
                break;
            }
            case UF_TYPE_BYTES:
            case UF_TYPE_BYTES2:
            {
                uint32 value1;
                if (!ExtractUInt32(&args, value1))
                    return false;

                uint32 value2;
                if (!ExtractUInt32(&args, value2))
                    return false;

                uint32 value3;
                if (!ExtractUInt32(&args, value3))
                    return false;

                uint32 value4;
                if (!ExtractUInt32(&args, value4))
                    return false;

                target->SetByteValue(pField->offset, 0, value1);
                target->SetByteValue(pField->offset, 1, value2);
                target->SetByteValue(pField->offset, 2, value3);
                target->SetByteValue(pField->offset, 3, value4);
                PSendSysMessage("Field %s of %s set to %u/%u/%u/%u.", pField->name, target->GetName(), value1, value2, value3, value4);
                break;
            }
            default:
            {
                SendSysMessage("Unsupported field type.");
                break;
            }
        }
       
    }
    else
        SendSysMessage("Wrong field name.");

    return true;
}

bool ChatHandler::HandleGetValueHelper(Object* target, uint32 field, char* typeStr)
{
    ObjectGuid guid = target->GetObjectGuid();

    if (field >= target->GetValuesCount())
    {
        PSendSysMessage(LANG_TOO_BIG_INDEX, field, guid.GetString().c_str(), target->GetValuesCount());
        return false;
    }

    uint32 base;                                            // 0 -> float
    if (!typeStr)
        base = 10;
    else if (strncmp(typeStr, "int", strlen(typeStr)) == 0)
        base = 10;
    else if (strncmp(typeStr, "hex", strlen(typeStr)) == 0)
        base = 16;
    else if (strncmp(typeStr, "bit", strlen(typeStr)) == 0)
        base = 2;
    else if (strncmp(typeStr, "float", strlen(typeStr)) == 0)
        base = 0;
    else
        return false;

    if (base)
    {
        uint32 iValue = target->GetUInt32Value(field);

        switch (base)
        {
            case 2:
            {
                // starting 0 if need as required bitstring format
                std::string res;
                res.reserve(1 + 32 + 1);
                res = iValue & (1 << (32 - 1)) ? "0" : " ";
                for (int i = 32; i > 0; --i)
                    res += iValue & (1 << (i - 1)) ? "1" : "0";
                DEBUG_LOG(GetMangosString(LANG_GET_BITSTR), guid.GetString().c_str(), field, res.c_str());
                PSendSysMessage(LANG_GET_BITSTR_FIELD, guid.GetString().c_str(), field, res.c_str());
                break;
            }
            case 16:
                DEBUG_LOG(GetMangosString(LANG_GET_HEX), guid.GetString().c_str(), field, iValue);
                PSendSysMessage(LANG_GET_HEX_FIELD, guid.GetString().c_str(), field, iValue);
                break;
            case 10:
            default:
                DEBUG_LOG(GetMangosString(LANG_GET_UINT), guid.GetString().c_str(), field, iValue);
                PSendSysMessage(LANG_GET_UINT_FIELD, guid.GetString().c_str(), field, iValue);
        }
    }
    else
    {
        float fValue = target->GetFloatValue(field);
        DEBUG_LOG(GetMangosString(LANG_GET_FLOAT), guid.GetString().c_str(), field, fValue);
        PSendSysMessage(LANG_GET_FLOAT_FIELD, guid.GetString().c_str(), field, fValue);
    }

    return true;
}

bool ChatHandler::HandleDebugGetItemValueCommand(char* args)
{
    uint32 guid;
    if (!ExtractUInt32(&args, guid))
        return false;

    uint32 field;
    if (!ExtractUInt32(&args, field))
        return false;

    char* typeStr = ExtractLiteralArg(&args);
    if (!typeStr && *args)                                  // optional arg but check format fail case
        return false;

    Item* item = m_session->GetPlayer()->GetItemByGuid(ObjectGuid(HIGHGUID_ITEM, guid));
    if (!item)
        return false;

    return HandleGetValueHelper(item, field, typeStr);
}

bool ChatHandler::HandleDebugGetValueByIndexCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 field;
    if (!ExtractUInt32(&args, field))
        return false;

    char* typeStr = ExtractLiteralArg(&args);
    if (!typeStr && *args)                                  // optional arg but check format fail case
        return false;

    return HandleGetValueHelper(target, field, typeStr);
}

bool ChatHandler::HandleDebugGetValueByNameCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    char* fieldName = ExtractQuotedOrLiteralArg(&args);
    if (!fieldName)
        return false;

    if (UpdateFieldData const* pField = UpdateFields::GetUpdateFieldDataByName(fieldName))
    {
        if ((pField->objectTypeMask & target->GetTypeMask()) == 0)
        {
            SendSysMessage("Target does have that field.");
            return true;
        }
        PSendSysMessage("Update field info for %s", target->GetGuidStr().c_str());
        ShowUpdateFieldHelper(target, pField->offset);
    }
    else
        SendSysMessage("Wrong field name.");

    return true;
}

void ChatHandler::ShowAllUpdateFieldsHelper(Object const* pTarget)
{
    PSendSysMessage("Update field info for %s", pTarget->GetGuidStr().c_str());

    for (uint16 index = 0; index < pTarget->GetValuesCount(); index++)
    {
        if (!pTarget->GetUInt32Value(index))
            continue;

        ShowUpdateFieldHelper(pTarget, index);
    }
}

void ChatHandler::ShowUpdateFieldHelper(Object const* pTarget, uint16 index)
{
    if (UpdateFieldData const* pField = UpdateFields::GetUpdateFieldDataByTypeMaskAndOffset(pTarget->GetTypeMask(), index))
    {
        std::string fieldName = pField->name;
        if (index > pField->offset)
            fieldName += "+" + std::to_string(index - pField->offset);

        switch (pField->valueType)
        {
            case UF_TYPE_INT:
                PSendSysMessage("%s: %u", fieldName.c_str(), pTarget->GetUInt32Value(index));
                break;
            case UF_TYPE_TWO_SHORT:
                PSendSysMessage("%s: %u/%u", fieldName.c_str(), pTarget->GetUInt16Value(index, 0), pTarget->GetUInt16Value(index, 1));
                break;
            case UF_TYPE_FLOAT:
                PSendSysMessage("%s: %g", fieldName.c_str(), pTarget->GetFloatValue(index));
                break;
            case UF_TYPE_GUID:
                if (index == pField->offset)
                    PSendSysMessage("%s: %s", fieldName.c_str(), pTarget->GetGuidValue(index).GetString().c_str());
                break;
            case UF_TYPE_BYTES:
            case UF_TYPE_BYTES2:
                PSendSysMessage("%s: %u/%u/%u/%u", fieldName.c_str(), pTarget->GetByteValue(index, 0), pTarget->GetByteValue(index, 1), pTarget->GetByteValue(index, 2), pTarget->GetByteValue(index, 3));
                break;
            default:
                SendSysMessage("Unsupported field type.");
                break;
        }
    }
}


bool ChatHandler::HandlerDebugModValueHelper(Object* target, uint32 field, char* typeStr, char* valStr)
{
    ObjectGuid guid = target->GetObjectGuid();
    char const* guidString = guid.GetString().c_str();

    // not allow access to nonexistent or critical for work field
    if (field >= target->GetValuesCount() || field <= OBJECT_FIELD_ENTRY)
    {
        PSendSysMessage(LANG_TOO_BIG_INDEX, field, guidString, target->GetValuesCount());
        return false;
    }

    uint32 type;                                            // 0 -> float 1 -> int add 2-> bit or 3 -> bit and  4 -> bit and not
    if (strncmp(typeStr, "int", strlen(typeStr)) == 0)
        type = 1;
    else if (strncmp(typeStr, "float", strlen(typeStr)) == 0)
        type = 0;
    else if (strncmp(typeStr, "|=", strlen("|=") + 1) == 0) // exactly copy
        type = 2;
    else if (strncmp(typeStr, "&=", strlen("&=") + 1) == 0) // exactly copy
        type = 3;
    else if (strncmp(typeStr, "&=~", strlen("&=~") + 1) == 0) // exactly copy
        type = 4;
    else
        return false;

    if (type)
    {
        uint32 iValue;
        if (!ExtractUInt32Base(&valStr, iValue, type == 1 ? 10 : 16))
            return false;

        uint32 value = target->GetUInt32Value(field);

        switch (type)
        {
            default:
            case 1:                                         // int +
                value = uint32(int32(value) + int32(iValue));
                DEBUG_LOG(GetMangosString(LANG_CHANGE_INT32), guidString, field, iValue, value, value);
                PSendSysMessage(LANG_CHANGE_INT32_FIELD, guidString, field, iValue, value, value);
                break;
            case 2:                                         // |= bit or
                value |= iValue;
                DEBUG_LOG(GetMangosString(LANG_CHANGE_HEX), guidString, field, typeStr, iValue, value);
                PSendSysMessage(LANG_CHANGE_HEX_FIELD, guidString, field, typeStr, iValue, value);
                break;
            case 3:                                         // &= bit and
                value &= iValue;
                DEBUG_LOG(GetMangosString(LANG_CHANGE_HEX), guidString, field, typeStr, iValue, value);
                PSendSysMessage(LANG_CHANGE_HEX_FIELD, guidString, field, typeStr, iValue, value);
                break;
            case 4:                                         // &=~ bit and not
                value &= ~iValue;
                DEBUG_LOG(GetMangosString(LANG_CHANGE_HEX), guidString, field, typeStr, iValue, value);
                PSendSysMessage(LANG_CHANGE_HEX_FIELD, guidString, field, typeStr, iValue, value);
                break;
        }

        target->SetUInt32Value(field, value);
    }
    else
    {
        float fValue;
        if (!ExtractFloat(&valStr, fValue))
            return false;

        float value = target->GetFloatValue(field);

        value += fValue;

        DEBUG_LOG(GetMangosString(LANG_CHANGE_FLOAT), guidString, field, fValue, value);
        PSendSysMessage(LANG_CHANGE_FLOAT_FIELD, guidString, field, fValue, value);

        target->SetFloatValue(field, value);
    }

    return true;
}

bool ChatHandler::HandleDebugModItemValueCommand(char* args)
{
    uint32 guid;
    if (!ExtractUInt32(&args, guid))
        return false;

    uint32 field;
    if (!ExtractUInt32(&args, field))
        return false;

    char* typeStr = ExtractLiteralArg(&args);
    if (!typeStr)
        return false;

    char* valStr = ExtractLiteralArg(&args);
    if (!valStr)
        return false;

    Item *item = m_session->GetPlayer()->GetItemByGuid(ObjectGuid(HIGHGUID_ITEM, guid));
    if (!item)
        return false;

    return HandlerDebugModValueHelper(item, field, typeStr, valStr);
}

bool ChatHandler::HandleDebugModValueCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 field;
    if (!ExtractUInt32(&args, field))
        return false;

    char* typeStr = ExtractLiteralArg(&args);
    if (!typeStr && *args)                                  // optional arg but check format fail case
        return false;

    char* valStr = ExtractLiteralArg(&args);
    if (!valStr)
        return false;

    return HandlerDebugModValueHelper(target, field, typeStr, valStr);
}

bool ChatHandler::HandleDebugSpellCoefsCommand(char* args)
{
    uint32 spellid = ExtractSpellIdFromLink(&args);
    if (!spellid)
        return false;

    SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(spellid);
    if (!spellEntry)
        return false;

    float direct_calc = spellEntry->CalculateDefaultCoefficient(SPELL_DIRECT_DAMAGE);
    float dot_calc = spellEntry->CalculateDefaultCoefficient(DOT);

    bool isDirectHeal = false;
    for (int i = 0; i < 3; ++i)
    {
        // Heals (Also count Mana Shield and Absorb effects as heals)
        if (spellEntry->Effect[i] == SPELL_EFFECT_HEAL || spellEntry->Effect[i] == SPELL_EFFECT_HEAL_MAX_HEALTH ||
                (spellEntry->Effect[i] == SPELL_EFFECT_APPLY_AURA && (spellEntry->EffectApplyAuraName[i] == SPELL_AURA_SCHOOL_ABSORB || spellEntry->EffectApplyAuraName[i] == SPELL_AURA_PERIODIC_HEAL)))
        {
            isDirectHeal = true;
            break;
        }
    }

    bool isDotHeal = false;
    for (int i = 0; i < 3; ++i)
    {
        // Periodic Heals
        if (spellEntry->Effect[i] == SPELL_EFFECT_APPLY_AURA && spellEntry->EffectApplyAuraName[i] == SPELL_AURA_PERIODIC_HEAL)
        {
            isDotHeal = true;
            break;
        }
    }

    char const* directHealStr = GetMangosString(LANG_DIRECT_HEAL);
    char const* directDamageStr = GetMangosString(LANG_DIRECT_DAMAGE);
    char const* dotHealStr = GetMangosString(LANG_DOT_HEAL);
    char const* dotDamageStr = GetMangosString(LANG_DOT_DAMAGE);

    PSendSysMessage(LANG_SPELLCOEFS, spellid, isDirectHeal ? directHealStr : directDamageStr,
                    direct_calc, direct_calc * 1.88f, spellEntry->EffectBonusCoefficient[0], 0.0f);
    PSendSysMessage(LANG_SPELLCOEFS, spellid, isDotHeal ? dotHealStr : dotDamageStr,
                    dot_calc, dot_calc * 1.88f, spellEntry->EffectBonusCoefficient[0], 0.0f);

    return true;
}

bool ChatHandler::HandleDebugSpellModsCommand(char* args)
{
    char* typeStr = ExtractLiteralArg(&args);
    if (!typeStr)
        return false;

    uint16 opcode;
    if (strncmp(typeStr, "flat", strlen(typeStr)) == 0)
        opcode = SMSG_SET_FLAT_SPELL_MODIFIER;
    else if (strncmp(typeStr, "pct", strlen(typeStr)) == 0)
        opcode = SMSG_SET_PCT_SPELL_MODIFIER;
    else
        return false;

    uint32 effidx;
    if (!ExtractUInt32(&args, effidx) || effidx >= 64)
        return false;

    uint32 spellmodop;
    if (!ExtractUInt32(&args, spellmodop) || spellmodop >= MAX_SPELLMOD)
        return false;

    int32 value;
    if (!ExtractInt32(&args, value))
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

    PSendSysMessage(LANG_YOU_CHANGE_SPELLMODS, opcode == SMSG_SET_FLAT_SPELL_MODIFIER ? "flat" : "pct",
                    spellmodop, value, effidx, GetNameLink(chr).c_str());
    if (needReportToTarget(chr))
        ChatHandler(chr).PSendSysMessage(LANG_YOURS_SPELLMODS_CHANGED, GetNameLink().c_str(),
                                         opcode == SMSG_SET_FLAT_SPELL_MODIFIER ? "flat" : "pct", spellmodop, value, effidx);

    WorldPacket data(opcode, (1 + 1 + 2 + 2));
    data << uint8(effidx);
    data << uint8(spellmodop);
    data << int32(value);
    chr->GetSession()->SendPacket(&data);

    return true;
}


bool ChatHandler::HandleDebugLoSCommand(char*)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        return false;
    }

    float x0, y0, z0;
    float x1, y1, z1;
    m_session->GetPlayer()->GetPosition(x0, y0, z0);
    target->GetPosition(x1, y1, z1);

    VMAP::ModelInstance* spawn = m_session->GetPlayer()->GetMap()->FindCollisionModel(x0, y0, z0, x1, y1, z1);

    if (!spawn)
        SendSysMessage("* No collision found.");
    else
        PSendSysMessage("* Collision at '%s' [%f %f %f]", spawn->name.c_str(), spawn->iPos.x, spawn->iPos.y, spawn->iPos.z);
    return true;
}

bool ChatHandler::HandleDebugLoSAllowCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    bool value;
    if (!target || !ExtractOnOff(&args, value))
        return false;

    float x0, y0, z0;
    float x1, y1, z1;
    m_session->GetPlayer()->GetPosition(x0, y0, z0);
    target->GetPosition(x1, y1, z1);

    VMAP::ModelInstance* spawn = m_session->GetPlayer()->GetMap()->FindCollisionModel(x0, y0, z0, x1, y1, z1);

    if (!spawn)
        SendSysMessage("* No collision found.");
    else if (((spawn->flags & VMAP::MOD_NO_BREAK_LOS) > 0) != value)
    {
        sLog.outInfo("[VMAPS] Collision for model '%s' %s by %s (guid %u)", spawn->name.c_str(), value ? "disabled" : "enabled", m_session->GetPlayer()->GetName(), m_session->GetPlayer()->GetGUIDLow());
        if (value)
        {
            spawn->flags |= VMAP::MOD_NO_BREAK_LOS;
            PSendSysMessage("'%s' will no longer break LOS.", spawn->name.c_str());
        }
        else
        {
            spawn->flags &= ~VMAP::MOD_NO_BREAK_LOS;
            PSendSysMessage("'%s' will break LOS.", spawn->name.c_str());
        }
        if (FILE* f = fopen("los_mods", "a"))
        {
            fprintf(f, "%u %u %s\n", !value, spawn->ID, spawn->name.c_str());
            fclose(f);
        }
    }
    else
        PSendSysMessage("Model '%s' already %s for LOS.", spawn->name.c_str(), value ? "disabled" : "enabled");
    return true;
}

bool ChatHandler::HandleSendSpellVisualCommand(char *args)
{
    Unit* pTarget = GetSelectedUnit();
    if (!pTarget)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 uiPlayId = 0;
    char* playIdStr = strtok(args, " ");
    if (playIdStr)
        uiPlayId = uint32(atoi(playIdStr));
    SpellEntry const* proto = sSpellMgr.GetSpellEntry(uiPlayId);
    if (!proto)
    {
        SendSysMessage(LANG_COMMAND_NOSPELLFOUND);
        SetSentErrorMessage(true);
        return false;
    }
    PSendSysMessage("Spell %u visual on target '%s'.", uiPlayId, pTarget->GetName());

    WorldPacket data(SMSG_PLAY_SPELL_VISUAL, 8 + 4);
    data << uint64(m_session->GetPlayer()->GetGUID());
    data << uint32(uiPlayId);                                // spell visual id?
    pTarget->SendMessageToSet(&data, true);
    m_session->GetPlayer()->SendSpellGo(pTarget, uiPlayId);

    // Channeled case
    if (proto->IsChanneledSpell())
    {
        m_session->GetPlayer()->SetUInt32Value(UNIT_CHANNEL_SPELL, uiPlayId);
        m_session->GetPlayer()->SetChannelObjectGuid(pTarget->GetObjectGuid());
    }
    return true;
}

bool ChatHandler::HandleSendSpellImpactCommand(char *args)
{
    Unit* pTarget = GetSelectedUnit();
    if (!pTarget)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 uiPlayId = 0;
    char* playIdStr = strtok(args, " ");
    if (playIdStr)
        uiPlayId = uint32(atoi(playIdStr));
    PSendSysMessage("Spell %u impact on target '%s'.", uiPlayId, pTarget->GetName());

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    WorldPacket data(SMSG_PLAY_SPELL_IMPACT, 8 + 4);
    data << uint64(pTarget->GetGUID());
    data << uint32(uiPlayId);                                // spell visual id?
    pTarget->SendMessageToSet(&data, true);
#endif
    return true;
}

bool ChatHandler::HandleDebugAssertFalseCommand(char*)
{
    ASSERT(false);
    return false;
}

bool ChatHandler::HandleDebugChatFreezeCommand(char* args)
{
    std::string message("| |01");

    MasterPlayer* pReceiver = GetSession()->GetMasterPlayer();

    if (Player* pPlayer = GetSelectedPlayer())
        if (pPlayer->GetSession()->GetSecurity() == SEC_PLAYER)
            pReceiver = pPlayer->GetSession()->GetMasterPlayer();

    pReceiver->Whisper(message, LANG_UNIVERSAL, pReceiver);

    return true;
}

bool ChatHandler::HandleDebugOverflowCommand(char* args)
{
    std::string name("\360\222\214\245\360\222\221\243\360\222\221\251\360\223\213\215\360\223\213\210\360\223\211\241\360\222\214\245\360\222\221\243\360\222\221\251\360\223\213\215\360\223\213\210\360\223\211\241");
    // Overflow: \xd808\xdf25\xd809\xdc63\xd809\xdc69\xd80c\xdecd\xd80c\xdec8\xd80c\xde61\000\xdf25\xd809\xdc63

    normalizePlayerName(name);

    return true;
}

bool ChatHandler::HandleDebugLootTableCommand(char* args)
{
    std::stringstream in(args);
    std::string tableName;
    int32 lootid = 0;
    int32 checkItem = 0;
    uint32 simCount = 0;
    in >> tableName >> lootid >> simCount >> checkItem;
    simCount = simCount ? simCount : 10000;
    SetSentErrorMessage(true);

    LootStore const* store = nullptr;
    if (tableName == "creature")
        store = &LootTemplates_Creature;
    else if (tableName == "reference")
        store = &LootTemplates_Reference;
    else if (tableName == "fishing")
        store = &LootTemplates_Fishing;
    else if (tableName == "gameobject")
        store = &LootTemplates_Gameobject;
    else if (tableName == "item")
        store = &LootTemplates_Item;
    else if (tableName == "mail")
        store = &LootTemplates_Mail;
    else if (tableName == "pickpocketing")
        store = &LootTemplates_Pickpocketing;
    else if (tableName == "skinning")
        store = &LootTemplates_Skinning;
    else if (tableName == "disenchant")
        store = &LootTemplates_Disenchant;
    else if (tableName == "enchant")
        return HandleDebugItemEnchantCommand(lootid, simCount);
    else
    {
        PSendSysMessage("Error: loot type \"%s\" unknown", tableName.c_str());
        return false;
    }

    LootTemplate const* tab = store->GetLootFor(lootid);
    if (!tab)
    {
        PSendSysMessage("Error: loot type \"%s\" has no lootid %u", tableName.c_str(), lootid);
        return false;
    }

    Player* lootOwner = GetSelectedPlayer();

    std::map<uint32, uint32> lootChances;
    if (checkItem)
        lootChances[checkItem] = 0;

    uint32 const MAX_TIME = 30;
    auto startTime = time(nullptr);

    for (uint32 i = 0; i < simCount; ++i)
    {
        Loot l(nullptr);
        if (lootOwner)
            l.SetTeam(lootOwner->GetTeam());
        tab->Process(l, *store, store->IsRatesAllowed());
        for (const auto& item : l.items)
            if (!lootOwner || !item.conditionId)
                lootChances[item.itemid]++;
        for (const auto& m_questItem : l.m_questItems)
            lootChances[m_questItem.itemid]++;
        if (lootOwner)
        {
            l.FillNotNormalLootFor(lootOwner);
            QuestItemMap::const_iterator itemsList = l.m_playerFFAItems.find(lootOwner->GetGUIDLow());
            if (itemsList != l.m_playerFFAItems.end())
                for (const auto& it : *itemsList->second)
                    lootChances[l.items[it.index].itemid]++;
            itemsList = l.m_playerQuestItems.find(lootOwner->GetGUIDLow());
            if (itemsList != l.m_playerQuestItems.end())
                for (const auto& it : *itemsList->second)
                    lootChances[l.m_questItems[it.index].itemid]++;
            itemsList = l.m_playerNonQuestNonFFAConditionalItems.find(lootOwner->GetGUIDLow());
            if (itemsList != l.m_playerNonQuestNonFFAConditionalItems.end())
                for (const auto& it : *itemsList->second)
                    lootChances[l.items[it.index].itemid]++;
        }

        if (i % 1000000 == 0) // check the time every million iterations
        {
            if (time(nullptr) - startTime > MAX_TIME)
            {
                PSendSysMessage("Error: Aborted loot simulation after %u runs for exceeding max allowed time of %us", i, MAX_TIME);
                simCount = i;
                break;
            }
        }
    }
    PSendSysMessage("%u items dropped after %u attempts for loot %s.%u", lootChances.size(), simCount, tableName.c_str(), lootid);
    for (const auto& itr : lootChances)
    {
        if (itr.first == checkItem || !checkItem)
        {
            ItemPrototype const* proto = sItemStorage.LookupEntry<ItemPrototype >(itr.first);
            if (!proto)
                continue;

            std::stringstream chance;
            chance << 100 * itr.second / float(simCount);
            chance << "%";
            if (m_session)
                PSendSysMessage(LANG_ITEM_LIST_CHAT, itr.first, itr.first, proto->Name1, chance.str().c_str());
            else
                PSendSysMessage(LANG_ITEM_LIST_CONSOLE, itr.first, proto->Name1, chance.str().c_str());
        }
    }
    return true;
}

bool ChatHandler::HandleDebugItemEnchantCommand(int lootid, uint32 simCount)
{
    std::map<uint32, uint32> lootChances;
    uint32 const MAX_TIME = 30;
    auto startTime = time(nullptr);

    ItemPrototype const* proto = sItemStorage.LookupEntry<ItemPrototype >(lootid);
    if (!proto)
    {
        PSendSysMessage("Error: invalid item id %u", lootid);
        return false;
    }
    if (!proto->RandomProperty)
    {
        PSendSysMessage("Error: item %u has no random enchantments", lootid);
        return false;
    }

    for (uint32 i = 0; i < simCount; ++i)
    {
        uint32 enchant = GetItemEnchantMod(proto->RandomProperty);
        lootChances[enchant]++;

        if (i % 1000000 == 0) // check the time every million iterations
        {
            if (time(nullptr) - startTime > MAX_TIME)
            {
                PSendSysMessage("Error: Aborted loot simulation after %u runs for exceeding max allowed time of %us", i, MAX_TIME);
                simCount = i;
                break;
            }
        }
    }

    PSendSysMessage("%u items dropped after %u attempts for item %s.", lootChances.size(), simCount, proto->Name1);
    for (const auto& itr : lootChances)
    {
        std::stringstream chance;
        chance << 100 * itr.second / float(simCount);
        chance << "%";
        ItemRandomPropertiesEntry const* randomProp = sItemRandomPropertiesStore.LookupEntry(itr.first);
        if (!randomProp)
            continue;
        if (m_session)
            PSendSysMessage(LANG_ITEM_LIST_CHAT, itr.first, lootid, randomProp->internalName, chance.str().c_str());
        else
            PSendSysMessage(LANG_ITEM_LIST_CONSOLE, itr.first, randomProp->internalName, chance.str().c_str());
    }
    return true;
}


bool IsSimilarItem(ItemPrototype const* proto1, ItemPrototype const* proto2)
{
    for (int i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        if (proto1->ItemStat[i].ItemStatType != proto2->ItemStat[i].ItemStatType ||
            proto1->ItemStat[i].ItemStatValue != proto2->ItemStat[i].ItemStatValue)
            return false;
    if (proto1->Quality != proto2->Quality)
        return false;
    if (proto1->Class != proto2->Class)
        return false;
    if (proto1->SubClass != proto2->SubClass)
        return false;
    if (proto1->InventoryType != proto2->InventoryType)
        return false;
    if (proto1->Armor != proto2->Armor)
        return false;
    if (proto1->AllowableClass != proto2->AllowableClass)
        return false;
    return true;
}

bool ChatHandler::HandleFactionChangeItemsCommand(char* c)
{
    for (uint32 id = 0; id < sItemStorage.GetMaxEntry(); id++)
    {
        ItemPrototype const* proto1 = sItemStorage.LookupEntry<ItemPrototype>(id);
        if (!proto1)
            continue;
        Races currMountRace;
        uint8 currRaceNum = 0;
        if (sObjectMgr.GetMountDataByEntry(id, currMountRace, currRaceNum))
            continue;
        if (proto1->Quality <= 1)
            continue;
        bool inDb = false;
        for (std::map<uint32, uint32>::const_iterator it2 = sObjectMgr.factionchange_items.begin(); it2 != sObjectMgr.factionchange_items.end(); ++it2)
        {
            if ((it2->first == id) || (it2->second == id))
            {
                inDb = true;
                break;
            }
        }
        if (inDb)
            continue;

        bool canEquip = true;
        if ((proto1->AllowableRace & RACEMASK_ALLIANCE) == 0 || (proto1->AllowableRace & RACEMASK_HORDE) == 0)
            canEquip = false;
        if (proto1->RequiredHonorRank != 0 &&
            (proto1->Class == ITEM_CLASS_WEAPON || proto1->Class == ITEM_CLASS_ARMOR))
            canEquip = false;

        if (!canEquip)
        {
            ItemPrototype const* similar = nullptr;
            for (uint32 id2 = 0; id2 < sItemStorage.GetMaxEntry(); id2++)
                if (ItemPrototype const* proto2 = sItemStorage.LookupEntry<ItemPrototype>(id2))
                    if (proto1 != proto2 && IsSimilarItem(proto1, proto2))
                    {
                        if (similar)
                        {
                            // Ambiguity. Other similar items.
                            similar = nullptr;
                            break;
                        }
                        similar = proto2;
                    }


            PSendSysMessage("Item %u not handled ! Similar item : %u", proto1->ItemId, similar ? similar->ItemId : 0);
        }
    }
    return true;
}

bool ChatHandler::HandleVideoTurn(char*)
{
    float const radiusBegin = 40.0f;
    float const radiusEnd = 10.0f;
    float const zBegin = 30.0f;
    float const zEnd = 10.0f;
    float const angleBegin = 0.0f;
    float const angleEnd = 10 * M_PI_F;
    float const moveSpeed = 30.0f;
    std::list<Creature*> targets;
    Unit* selection = GetSelectedUnit();
    if (!selection)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        return false;
    }

    PointsArray a;
    float x, y, z;
    selection->GetPosition(x, y, z);
    for (float t = 0; t < 1; t += 0.03f)
    {
        float angle = angleBegin * t + (1 - t) * angleEnd;
        float posZ = zBegin * t + (1 - t) * zEnd + z;
        float d = radiusBegin * t + (1 - t) * radiusEnd;
        sLog.outString("%f %f %f", angle, d, z);
        a.push_back(Vector3(x + d * cos(angle), y + d * sin(angle), posZ));
    }
    Movement::MoveSplineInit init(*m_session->GetPlayer());
    init.MovebyPath(a);
    init.SetFly();
    init.SetVelocity(moveSpeed);
    init.Launch();
    return true;
}

bool ChatHandler::HandleDebugExp(char*)
{
    float const moveDist = 80.0f;
    float const searchCreaturesRange = 60.0f;
    float const retournementRayon = 2.0f;
    float const moveSpeed = 6.0f;
    std::list<Creature*> targets;
    Unit* selection = GetSelectedUnit();
    if (!selection)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        return false;
    }
    CellPair pair(MaNGOS::ComputeCellPair(selection->GetPositionX(), selection->GetPositionY()));
    Cell cell(pair);
    cell.SetNoCreate();

    MaNGOS::AnyUnitInObjectRangeCheck check(selection, searchCreaturesRange);
    MaNGOS::CreatureListSearcher<MaNGOS::AnyUnitInObjectRangeCheck> searcher(targets, check);
    TypeContainerVisitor<MaNGOS::CreatureListSearcher<MaNGOS::AnyUnitInObjectRangeCheck>, GridTypeMapContainer> visitor(searcher);

    cell.Visit(pair, visitor, *(selection->GetMap()), *selection, searchCreaturesRange);

    for (const auto target : targets)
    {
        float x = target->GetPositionX() + moveDist * cos(target->GetOrientation());
        float y = target->GetPositionY() + moveDist * sin(target->GetOrientation());
        float z = target->GetPositionZ();
        target->UpdateGroundPositionZ(x, y, z);
        PointsArray a;
        for (int i = 10; i >= 0; --i)
        {
            float angle = target->GetOrientation() - M_PI / 2 + i * M_PI / 10.0f;
            float currx = x + retournementRayon * cos(angle);
            float curry = y + retournementRayon * sin(angle);
            float currz = z;
            target->UpdateGroundPositionZ(currx, curry, currz);
            a.push_back(Vector3(currx, curry, currz));
        }

        Movement::MoveSplineInit init(*target);
        init.MovebyPath(a);
        init.SetWalk(true);
        init.SetVelocity(moveSpeed);
        init.Launch();
    }
    return true;
}

bool ChatHandler::HandleDebugMoveCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    uint32 movetype = 0;

    if (!target || !ExtractUInt32(&args, movetype))
        return false;

    switch (movetype)
    {
        case 0:
            target->GetMotionMaster()->Clear(true, true);
            target->GetMotionMaster()->MoveIdle();
            break;
        case 1:
            target->GetMotionMaster()->MoveIdle();
            break;
        case 2:
            target->GetMotionMaster()->MoveRandom();
            break;
        case 3:
            target->GetMotionMaster()->MoveConfused();
            break;
        case 4:
            target->GetMotionMaster()->MoveFleeing(m_session->GetPlayer());
            break;
        case 5:
            target->GetMotionMaster()->MoveFeared(m_session->GetPlayer());
            break;
    }
    SendSysMessage("Debug Move.");
    return true;
}

bool ChatHandler::HandleDebugRecvPacketDumpWrite(char* c)
{
    WorldSession* sess = m_session;
    if (Player* player = GetSelectedPlayer())
        sess = player->GetSession();
    PSendSysMessage("Starting replay recording for %s", playerLink(sess->GetPlayerName()).c_str());
    sess->SetDumpRecvPackets(c);
    return true;
}

bool ChatHandler::HandleDebugControlCommand(char *args)
{
    Player* pTarget = GetSelectedPlayer();
    if (!pTarget)
        return false;
    bool control = false;
    if (!ExtractOnOff(&args, control))
        return false;
    pTarget->SetClientControl(pTarget, control);
    return true;
}

bool ChatHandler::HandleDebugMonsterChatCommand(char* args)
{
    Unit* pTarget = GetSelectedUnit();
    if (!pTarget)
        return false;
    for (uint8 i = 0; i < 0xFF; ++i)
    {
        std::ostringstream oss;
        oss << "Chat" << int(i);
        std::string rightText = oss.str();
        WorldPacket data(SMSG_MESSAGECHAT, 200);
        data << (uint8)i;
        data << (uint32)LANG_UNIVERSAL;
        data << (uint32)(strlen(pTarget->GetName()) + 1);
        data << pTarget->GetName();
        data << (uint64)0;
        data << (uint32)(rightText.length() + 1);
        data << rightText;
        data << (uint8)0;                       // ChatTag
        pTarget->SendMessageToSet(&data, true);
    }

    pTarget->MonsterTextEmote("Testing WorldObject::MonsterTextEmote", m_session->GetPlayer());
    pTarget->MonsterTextEmote("Testing WorldObject::MonsterTextEmote(boss)", m_session->GetPlayer(), true);
    pTarget->MonsterWhisper("Testing WorldObject::MonsterWhisper", m_session->GetPlayer());
    return true;
}

bool ChatHandler::HandleDebugUnitCommand(char* args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
        return false;
    uint32 flags = 0;
    if (ExtractUInt32(&args, flags))
        target->SetDebugger(m_session->GetPlayer()->GetObjectGuid(), flags);

    PSendSysMessage("Debugs on target [%s]%s", target->GetName(), (target->GetDebuggerGuid() == m_session->GetPlayer()->GetObjectGuid()) ? " ATTACHE" : "");
#define HANDLE_DEBUG(flag, nom) PSendSysMessage("[%s] %6u \"" nom "\"", (target->GetDebugFlags() & flag) ? "ON" : "OFF", flag);
    HANDLE_DEBUG(DEBUG_SPELL_COMPUTE_RESISTS, "Spell Resist Calculations");
    HANDLE_DEBUG(DEBUG_PACKETS_RECV, "Packet received by the server");
    HANDLE_DEBUG(DEBUG_PACKETS_SEND, "Packets send by the server");
    HANDLE_DEBUG(DEBUG_AI, "Various AI debug");
    HANDLE_DEBUG(DEBUG_DR, "Diminishing returns");
    HANDLE_DEBUG(DEBUG_CHEAT, "Anticheat");
    HANDLE_DEBUG(DEBUG_PROCS, "Proc system");
    HANDLE_DEBUG(DEBUG_SPELLS_DAMAGE, "Spells damage and healing bonus");

    return true;
}

bool ChatHandler::HandleDebugTimeCommand(char* args)
{
    float rate = 1.0f;

    if (ExtractFloat(&args, rate))
        PSendSysMessage("Time rate: x %f", rate);
    else
        SendSysMessage("Time is back to normal.");

    sWorld.SetTimeRate(rate);
    return true;
}

bool ChatHandler::HandleDebugMoveFlagsCommand(char* args)
{
    Unit* unit = GetSelectedUnit();
    if (!unit)
        return false;
    uint32 flags = MOVEFLAG_NONE;
    if (ExtractUInt32Base(&args, flags, 16))
    {
        PSendSysMessage("moveFlags = 0x%x", flags);
        unit->m_movementInfo.moveFlags = flags;
        unit->SendHeartBeat(true);
    }
    else
    {
        PSendSysMessage("moveFlags = 0x%x", unit->GetUnitMovementFlags());
    }
    return true;
}

bool ChatHandler::HandleDebugMoveSplineCommand(char* args)
{
    Unit* unit = GetSelectedUnit();
    if (!unit)
        return false;
    PSendSysMessage("Target: %s", unit->GetGuidStr().c_str());
    PSendSysMessage("MoveSpline: %s", unit->movespline->Finalized() ? "finalized" : "running");
    PSendSysMessage("MvtOrigin: %s", unit->movespline->GetMovementOrigin());
    std::vector<Vector3> const& path = unit->movespline->getPath();
    for (size_t i = 0; i < path.size(); ++i)
        PSendSysMessage("Point%u %f %f %f", i, path[i].x, path[i].y, path[i].z);
    return true;
}

bool ChatHandler::HandleUnitStatCommand(char *args)
{
    Unit* pTarget = GetSelectedUnit();
    if (!pTarget)
        return false;
    uint32 unitStat = 0x0;
    for (int i = 1; i < UNIT_STAT_IGNORE_PATHFINDING; i *= 2)
        if (pTarget->HasUnitState(i))
            unitStat |= i;
    PSendSysMessage("UnitState = 0x%x (%u)", unitStat, unitStat);
    if (ExtractUInt32(&args, unitStat))
    {
        pTarget->ClearUnitState(UNIT_STAT_ALL_STATE);
        pTarget->AddUnitState(unitStat);
        PSendSysMessage("UnitState changed to 0x%x (%u)", unitStat, unitStat);
    }
    return true;
}

bool ChatHandler::HandleDebugPvPCreditCommand(char *args)
{
    Unit* pSelection = GetSelectedUnit();
    if (!pSelection)
        pSelection = m_session->GetPlayer();

    uint32 uiRankValue = urand(1, 14);
    /*
    Arguments :
    * uiHonorValue = Honor Gained
    * uiGradeValue = Honor Rank of Victim
    If uiHonorValue=0 : "Dishonorable Kill"
    */
    WorldPacket data(SMSG_PVP_CREDIT, 4 + 8 + 4);

    if (pSelection->GetTypeId() == TYPEID_PLAYER)
    {
        uint32 uiHonorValue = urand(1, 100);
        data << uiHonorValue;
        data << pSelection->GetGUID();
        PSendSysMessage("Honorable Kill : Rank %3u and Honor %3u.", uiRankValue, uiHonorValue);
    }
    else // Victoire deshonorante
    {
        data << uint32(0);
        data << pSelection->GetGUID();
        PSendSysMessage("Dishonorable Kill.");
        uiRankValue = 0;
    }
    data << uiRankValue;
    m_session->SendPacket(&data);

    return true;
}

bool ChatHandler::HandleDebugMoveToCommand(char* args)
{
    Player* player = m_session->GetPlayer();
    Unit* target = GetSelectedUnit();
    if (!player || !target || player == target)
    {
        PSendSysMessage("Invalid target/source selection.");
        return true;
    }

    // Determination of flags
    uint32 flags = 0;
    sscanf(args, "%x", &flags);
    player->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), flags);
    PSendSysMessage("Moving to \"%s\" (flags 0x%x)", target->GetName(), flags);
    return true;
}

bool ChatHandler::HandleDebugMoveDistanceCommand(char* args)
{
    Player* player = m_session->GetPlayer();
    Unit* target = GetSelectedUnit();
    if (!player || !target || player == target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        return true;
    }

    float distance = 10.0f;
    ExtractFloat(&args, distance);
    target->GetMotionMaster()->MoveDistance(player, distance);
    PSendSysMessage("%s is moving %g yards away from you.", target->GetName(), distance);
    return true;
}

bool ChatHandler::HandleDebugFaceMeCommand(char* args)
{
    Player* player = m_session->GetPlayer();
    Unit* target = GetSelectedUnit();
    if (!player || !target || player == target)
    {
        PSendSysMessage("Invalid target/source selection.");
        return true;
    }

    target->SetFacingTo(target->GetAngle(player));
    return true;
}


bool ChatHandler::HandleDebugForceUpdateCommand(char *args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    char* indexStr = strtok((char*)args, " ");

    if (!indexStr)
    {
        SendSysMessage("Syntax : .debug forceupdate $field");
        SetSentErrorMessage(true);
        return false;
    }

    uint16 index = (uint16)atoi(indexStr);
    target->ForceValuesUpdateAtIndex(index);
    PSendSysMessage("Update sent for field %u", index);
    return true;
}


// --------------------------------
// MMAPS
// --------------------------------

bool ChatHandler::HandleMmap(char* args)
{
    bool on;
    if (ExtractOnOff(&args, on))
    {
        if (on)
        {
            sWorld.setConfig(CONFIG_BOOL_MMAP_ENABLED, true);
            SendSysMessage("WORLD: mmaps are now ENABLED (individual map settings still in effect)");
        }
        else
        {
            sWorld.setConfig(CONFIG_BOOL_MMAP_ENABLED, false);
            SendSysMessage("WORLD: mmaps are now DISABLED");
        }
        return true;
    }

    on = sWorld.getConfig(CONFIG_BOOL_MMAP_ENABLED);
    PSendSysMessage("mmaps are %sabled", on ? "en" : "dis");

    return true;
}

enum MmapConnectionStep
{
    FIRST_STEP,
    SECOND_STEP,
};

bool ChatHandler::HandleMmapConnection(char* args)
{
    FILE* fOffmeshFile = fopen("offmesh_conn", "a");
    if (!fOffmeshFile)
    {
        SendSysMessage("Unable to open file.");
        return true;
    }
    // map tileY,X (X,Y,Z) (X,Y,Z) Size
    // 0 31,59 (-14429.889648 450.344452 15.430828) (-14424.218750 444.332855 12.773965) 2.5 // booty bay dock
    static MmapConnectionStep step = FIRST_STEP;
    static float firstX = 0.0f, firstY = 0.0f, firstZ = 0.0f;
    Player* pPlayer = m_session->GetPlayer();
    if (step == FIRST_STEP)
    {
        pPlayer->GetPosition(firstX, firstY, firstZ);
        step = SECOND_STEP;
        SendSysMessage("Enregistre ...");
    }
    else
    {
        int32 gx = 32 - pPlayer->GetPositionX() / SIZE_OF_GRIDS;
        int32 gy = 32 - pPlayer->GetPositionY() / SIZE_OF_GRIDS;
        PSendSysMessage("%u %u,%u (%f %f %f) (%f %f %f) %f",
                        pPlayer->GetMapId(), gy, gx, firstX, firstY, firstZ,
                        pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(),
                        pPlayer->GetObjectScale());
        fprintf(fOffmeshFile, "%u %u,%u (%f %f %f) (%f %f %f) %f\n",
                pPlayer->GetMapId(), gy, gx, firstX, firstY, firstZ,
                pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(),
                pPlayer->GetObjectScale());

        step = FIRST_STEP;
        firstX = firstY = firstZ = 0.0f;
    }
    fclose(fOffmeshFile);
    return true;
}

typedef std::list<Creature*> MmapTestUnitList;

bool ChatHandler::HandleMmapTestArea(char* args)
{
    float radius = 40.0f;
    ExtractFloat(&args, radius);

    CellPair pair(MaNGOS::ComputeCellPair(m_session->GetPlayer()->GetPositionX(), m_session->GetPlayer()->GetPositionY()));
    Cell cell(pair);
    cell.SetNoCreate();

    std::list<Creature*> creatureList;

    MaNGOS::AnyUnitInObjectRangeCheck go_check(m_session->GetPlayer(), radius);
    MaNGOS::CreatureListSearcher<MaNGOS::AnyUnitInObjectRangeCheck> go_search(creatureList, go_check);
    TypeContainerVisitor<MaNGOS::CreatureListSearcher<MaNGOS::AnyUnitInObjectRangeCheck>, GridTypeMapContainer> go_visit(go_search);

    // Get Creatures
    cell.Visit(pair, go_visit, *(m_session->GetPlayer()->GetMap()), *(m_session->GetPlayer()), radius);
    if (!creatureList.empty())
    {
        PSendSysMessage("%u creatures found in %g yards.", creatureList.size(), radius);

        uint32 paths = 0;
        uint32 uStartTime = WorldTimer::getMSTime();

        float x, y, z;
        m_session->GetPlayer()->GetPosition(x, y, z);
        for (const auto& itr : creatureList)
        {
            if (itr->GetTypeId() != TYPEID_UNIT)
                continue;
            Creature* target = itr->ToCreature();
            if (target->IsTrigger() || target->GetEntry() <= 2)
                continue;
            PathInfo path(target);
            path.calculate(x, y, z, false);
            if ((path.getPathType() & PATHFIND_NORMAL) == 0)
            {
                PSendSysMessage("-> Mob GUID %u entry %u pathtype 0x%x", target->GetDBTableGUIDLow(), target->GetEntry(), path.getPathType());
                continue;
            }
            ++paths;
        }

        uint32 uPathLoadTime = WorldTimer::getMSTimeDiff(uStartTime, WorldTimer::getMSTime());
        PSendSysMessage("%u paths generated in %u ms", paths, uPathLoadTime);
    }
    else
        PSendSysMessage("No creatures found within %g yards.", radius);

    return true;
}

bool ChatHandler::HandleMmapPathCommand(char* args)
{
    Player* player = m_session->GetPlayer();
    if (GenericTransport* transport = player->GetTransport())
    {
        if (!MMAP::MMapFactory::createOrGetMMapManager()->GetGONavMesh(transport->GetDisplayId()))
        {
            PSendSysMessage("NavMesh not loaded for current map.");
            return true;
        }
    }
    else
    {
        if (!MMAP::MMapFactory::createOrGetMMapManager()->GetNavMesh(m_session->GetPlayer()->GetMapId()))
        {
            PSendSysMessage("NavMesh not loaded for current map.");
            return true;
        }
    }

    PSendSysMessage("mmap path:");

    // units
    Unit* target = GetSelectedUnit();
    if (!player || !target)
    {
        PSendSysMessage("Invalid target/source selection.");
        return true;
    }

    char* para = strtok(args, " ");

    bool useStraightPath = false;
    if (para && strcmp(para, "true") == 0)
        useStraightPath = true;

    // unit locations
    float x, y, z;
    player->GetPosition(x, y, z);

    // path
    PathInfo path(target);
    GenericTransport* transport = target->GetTransport();
    if (!transport && player->GetTransport())
        transport = player->GetTransport();
    path.SetTransport(transport);
    path.calculate(x, y, z, useStraightPath);
    PointsArray pointPath = path.getFullPath();
    PSendSysMessage("%s's path to %s:", target->GetName(), player->GetName());
    PSendSysMessage("Building %s", useStraightPath ? "StraightPath" : "SmoothPath");
    PSendSysMessage("length %i (dist %f) type %u", pointPath.size(), path.Length(), path.getPathType());

    for (auto& i : pointPath)
    {
        if (transport)
            transport->CalculatePassengerPosition(i.x, i.y, i.z);
        if (Creature* wp = player->SummonCreature(VISUAL_WAYPOINT, i.x, i.y, i.z, 0, TEMPSUMMON_TIMED_DESPAWN, 18000))
        {
            wp->SetFly(true);
            if (transport)
            {
                transport->AddPassenger(wp);
                Movement::MoveSplineInit init(*wp);
                init.SetTransport(transport->GetGUIDLow());
                init.SetFacing(wp->GetOrientation());
                init.Launch();
            }
            else
                wp->SendHeartBeat();
        }
    }

    return true;
}

bool ChatHandler::HandleMmapLocCommand(char* /*args*/)
{
    SendSysMessage("mmap tileloc:");

    // grid tile location
    Unit* unit = GetSelectedUnit();
    dtQueryFilter filter = dtQueryFilter();
    float closestPoint[3] = {0.0f, 0.0f, 0.0f}; // Y, Z, X
    float x, y, z;
    unit->GetPosition(x, y, z);
    float location[VERTEX_SIZE] = {y, z, x};

    if (GenericTransport* transport = unit->GetTransport())
    {
        transport->CalculatePassengerOffset(location[2], location[0], location[1]);
        PSendSysMessage("* On transport navmesh 'go%03u.mmap' offsets [%f %f %f]", transport->GetDisplayId(), location[2], location[0], location[1]);
        dtNavMeshQuery const* navmeshquery = MMAP::MMapFactory::createOrGetMMapManager()->GetModelNavMeshQuery(transport->GetDisplayId());
        if (!navmeshquery)
        {
            SendSysMessage("No navmeshloaded");
            return true;
        }
        dtPolyRef polyRef = PathInfo::FindWalkPoly(navmeshquery, location, filter, closestPoint);
        if (!polyRef)
        {
            SendSysMessage("No polygon found");
            return true;
        }
        PSendSysMessage("Closest point on poly %f %f %f", closestPoint[2], closestPoint[0], closestPoint[1]);
        transport->CalculatePassengerPosition(closestPoint[2], closestPoint[0], closestPoint[1]);
        if (Creature* wp = unit->SummonCreature(1, closestPoint[2], closestPoint[0], closestPoint[1], 0.0f, TEMPSUMMON_TIMED_DESPAWN, 50000, true))
        {
            transport->AddPassenger(wp);
            wp->SetFly(true);
            wp->StopMoving();
        }
        return true;
    }

    int32 gx = 32 - unit->GetPositionX() / SIZE_OF_GRIDS;
    int32 gy = 32 - unit->GetPositionY() / SIZE_OF_GRIDS;

    PSendSysMessage("%03u%02i%02i.mmtile", unit->GetMapId(), gx, gy);
    PSendSysMessage("tile [%i,%i]", gy, gx); // Recast coords are swapped.

    // calculate navmesh tile location
    dtNavMesh const* navmesh = MMAP::MMapFactory::createOrGetMMapManager()->GetNavMesh(unit->GetMapId());
    dtNavMeshQuery const* navmeshquery = MMAP::MMapFactory::createOrGetMMapManager()->GetNavMeshQuery(unit->GetMapId());
    if (!navmesh || !navmeshquery)
    {
        PSendSysMessage("NavMesh not loaded for current map.");
        return true;
    }

    float const* min = navmesh->getParams()->orig;
    int32 tilex = int32((y - min[0]) / SIZE_OF_GRIDS);
    int32 tiley = int32((x - min[2]) / SIZE_OF_GRIDS);

    PSendSysMessage("Calc   [%02i,%02i]", tilex, tiley);

    // navmesh poly -> navmesh tile location
    dtPolyRef polyRef = PathInfo::FindWalkPoly(navmeshquery, location, filter, closestPoint);

    if (polyRef == INVALID_POLYREF)
        PSendSysMessage("Dt     [??,??] (invalid poly, probably no tile loaded)");
    else
    {
        dtMeshTile const* tile;
        dtPoly const* poly;
        navmesh->getTileAndPolyByRef(polyRef, &tile, &poly);
        if (tile)
            PSendSysMessage("Dt     [%02i,%02i]", tile->header->x, tile->header->y);
        else
            PSendSysMessage("Dt     [??,??] (no tile loaded)");
        if (poly)
            PSendSysMessage("Poly flags x%x area 0x%x", poly->flags, poly->getArea());
        if (Creature* wp = unit->SummonCreature(1, closestPoint[2], closestPoint[0], closestPoint[1], 0.0f, TEMPSUMMON_TIMED_DESPAWN, 5000, true))
        {
            wp->SetFly(true);
            wp->SendHeartBeat();
        }
    }

    return true;
}

bool ChatHandler::HandleMmapLoadedTilesCommand(char* /*args*/)
{
    uint32 mapid = m_session->GetPlayer()->GetMapId();

    dtNavMesh const* navmesh = MMAP::MMapFactory::createOrGetMMapManager()->GetNavMesh(mapid);
    dtNavMeshQuery const* navmeshquery = MMAP::MMapFactory::createOrGetMMapManager()->GetNavMeshQuery(mapid);
    if (!navmesh || !navmeshquery)
    {
        PSendSysMessage("NavMesh not loaded for current map.");
        return true;
    }

    PSendSysMessage("mmap loadedtiles:");

    for (int32 i = 0; i < navmesh->getMaxTiles(); ++i)
    {
        dtMeshTile const* tile = navmesh->getTile(i);
        if (!tile || !tile->header)
            continue;

        PSendSysMessage("[%02i,%02i]", tile->header->x, tile->header->y);
    }

    return true;
}

bool ChatHandler::HandleMmapStatsCommand(char* /*args*/)
{
    PSendSysMessage("mmap stats:");
    PSendSysMessage("  global mmap pathfinding is %sabled", sWorld.getConfig(CONFIG_BOOL_MMAP_ENABLED) ? "en" : "dis");

    MMAP::MMapManager *manager = MMAP::MMapFactory::createOrGetMMapManager();
    PSendSysMessage(" %u maps loaded with %u tiles overall", manager->getLoadedMapsCount(), manager->getLoadedTilesCount());

    dtNavMesh const* navmesh = manager->GetNavMesh(m_session->GetPlayer()->GetMapId());
    if (GenericTransport* transport = m_session->GetPlayer()->GetTransport())
    {
        dtNavMeshQuery const* navmeshquery = MMAP::MMapFactory::createOrGetMMapManager()->GetModelNavMeshQuery(transport->GetDisplayId());
        navmesh = navmeshquery ? navmeshquery->getAttachedNavMesh() : nullptr;
    }

    if (!navmesh)
    {
        PSendSysMessage("NavMesh not loaded for current map.");
        return true;
    }

    uint32 tileCount = 0;
    uint32 nodeCount = 0;
    uint32 polyCount = 0;
    uint32 vertCount = 0;
    uint32 triCount = 0;
    uint32 triVertCount = 0;
    uint32 dataSize = 0;
    for (int32 i = 0; i < navmesh->getMaxTiles(); ++i)
    {
        dtMeshTile const* tile = navmesh->getTile(i);
        if (!tile || !tile->header)
            continue;

        tileCount ++;
        nodeCount += tile->header->bvNodeCount;
        polyCount += tile->header->polyCount;
        vertCount += tile->header->vertCount;
        triCount += tile->header->detailTriCount;
        triVertCount += tile->header->detailVertCount;
        dataSize += tile->dataSize;
    }

    PSendSysMessage("Navmesh stats on current map:");
    PSendSysMessage(" %u tiles loaded", tileCount);
    PSendSysMessage(" %u BVTree nodes", nodeCount);
    PSendSysMessage(" %u polygons (%u vertices)", polyCount, vertCount);
    PSendSysMessage(" %u triangles (%u vertices)", triCount, triVertCount);
    PSendSysMessage(" %.2f MB of data (not including pointers)", ((float)dataSize / sizeof(unsigned char)) / 1048576);

    return true;
}

bool ChatHandler::HandleMmapUnload(char* args)
{
    PSendSysMessage("* Unload map %u", m_session->GetPlayer()->GetMapId());
    MMAP::MMapFactory::createOrGetMMapManager()->unloadMap(m_session->GetPlayer()->GetMapId());
    return true;
}

bool ChatHandler::HandleMmapLoad(char* args)
{
    Player* pl = m_session->GetPlayer();
    int gx, gy;
    gx = 32 - pl->GetPositionX() / SIZE_OF_GRIDS;
    gy = 32 - pl->GetPositionY() / SIZE_OF_GRIDS;
    PSendSysMessage("* Load tile [%u:%u]", gx, gy);
    MMAP::MMapFactory::createOrGetMMapManager()->loadMap(pl->GetMapId(), gx, gy);
    return true;
}

bool ChatHandler::HandleDebugUnitBytes1Command(char *args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 offset;
    if (!ExtractUInt32(&args, offset))
        return false;

    if (offset > 3)
        return false;

    uint32 value;
    if (!ExtractUInt32(&args, value))
        return false;

    target->SetByteValue(UNIT_FIELD_BYTES_1, offset, value);

    return true;
}

bool ChatHandler::HandleDebugUnitBytes2Command(char *args)
{
    Unit* target = GetSelectedUnit();
    if (!target)
    {
        SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
        SetSentErrorMessage(true);
        return false;
    }

    uint32 offset;
    if (!ExtractUInt32(&args, offset))
        return false;

    if (offset > 3)
        return false;

    uint32 value;
    if (!ExtractUInt32(&args, value))
        return false;

    target->SetByteValue(UNIT_FIELD_BYTES_2, offset, value);

    return true;
}
