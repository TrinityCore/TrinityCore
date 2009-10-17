/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "Database/SQLStorage.h"
#include "CreatureEventAI.h"
#include "CreatureEventAIMgr.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "Policies/SingletonImp.h"
#include "ObjectDefines.h"
#include "GridDefines.h"

INSTANTIATE_SINGLETON_1(CreatureEventAIMgr);

// -------------------
void CreatureEventAIMgr::LoadCreatureEventAI_Texts()
{
    // Drop Existing Text Map, only done once and we are ready to add data from multiple sources.
    m_CreatureEventAI_TextMap.clear();

    // Load EventAI Text
    objmgr.LoadTrinityStrings(WorldDatabase,"creature_ai_texts",MIN_CREATURE_AI_TEXT_STRING_ID,MAX_CREATURE_AI_TEXT_STRING_ID);

    // Gather Additional data from EventAI Texts
    QueryResult *result = WorldDatabase.Query("SELECT entry, sound, type, language, emote FROM creature_ai_texts");

    sLog.outString("Loading EventAI Texts additional data...");
    if (result)
    {
        barGoLink bar(result->GetRowCount());
        uint32 count = 0;

        do
        {
            bar.step();
            Field* fields = result->Fetch();
            StringTextData temp;

            int32 i             = fields[0].GetInt32();
            temp.SoundId        = fields[1].GetInt32();
            temp.Type           = fields[2].GetInt32();
            temp.Language       = fields[3].GetInt32();
            temp.Emote          = fields[4].GetInt32();

            // range negative
            if (i > MIN_CREATURE_AI_TEXT_STRING_ID || i <= MAX_CREATURE_AI_TEXT_STRING_ID)
            {
                sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` is not in valid range(%d-%d)",i,MIN_CREATURE_AI_TEXT_STRING_ID,MAX_CREATURE_AI_TEXT_STRING_ID);
                continue;
            }

            // range negative (don't must be happen, loaded from same table)
            if (!objmgr.GetTrinityStringLocale(i))
            {
                sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` not found",i);
                continue;
            }

            if (temp.SoundId)
            {
                if (!sSoundEntriesStore.LookupEntry(temp.SoundId))
                    sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` has Sound %u but sound does not exist.",i,temp.SoundId);
            }

            if (!GetLanguageDescByID(temp.Language))
                sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` using Language %u but Language does not exist.",i,temp.Language);

            if (temp.Type > CHAT_TYPE_ZONE_YELL)
                sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` has Type %u but this Chat Type does not exist.",i,temp.Type);

            if (temp.Emote)
            {
                if (!sEmotesStore.LookupEntry(temp.Emote))
                    sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` has Emote %u but emote does not exist.",i,temp.Emote);
            }

            m_CreatureEventAI_TextMap[i] = temp;
            ++count;
        } while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Loaded %u additional CreatureEventAI Texts data.", count);
    }
    else
    {
        barGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 additional CreatureEventAI Texts data. DB table `creature_ai_texts` is empty.");
    }

}

// -------------------
void CreatureEventAIMgr::LoadCreatureEventAI_Summons()
{

    //Drop Existing EventSummon Map
    m_CreatureEventAI_Summon_Map.clear();

    // Gather additional data for EventAI
    QueryResult *result = WorldDatabase.Query("SELECT id, position_x, position_y, position_z, orientation, spawntimesecs FROM creature_ai_summons");
    if (result)
    {
        barGoLink bar(result->GetRowCount());
        uint32 Count = 0;

        do
        {
            bar.step();
            Field *fields = result->Fetch();

            CreatureEventAI_Summon temp;

            uint32 i = fields[0].GetUInt32();
            temp.position_x = fields[1].GetFloat();
            temp.position_y = fields[2].GetFloat();
            temp.position_z = fields[3].GetFloat();
            temp.orientation = fields[4].GetFloat();
            temp.SpawnTimeSecs = fields[5].GetUInt32();

            if(!MaNGOS::IsValidMapCoord(temp.position_x,temp.position_y,temp.position_z,temp.orientation))
            {
                sLog.outErrorDb("CreatureEventAI:  Summon id %u have wrong coordinates (%f,%f,%f,%f), skipping.", i,temp.position_x,temp.position_y,temp.position_z,temp.orientation);
                continue;
            }

            //Add to map
            m_CreatureEventAI_Summon_Map[i] = temp;
            ++Count;
        } while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Loaded %u CreatureEventAI summon definitions", Count);
    }
    else
    {
        barGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 CreatureEventAI Summon definitions. DB table `creature_ai_summons` is empty.");
    }

}

// -------------------
void CreatureEventAIMgr::LoadCreatureEventAI_Scripts()
{
    //Drop Existing EventAI List
    m_CreatureEventAI_Event_Map.clear();

    // Gather event data
    QueryResult *result = WorldDatabase.Query("SELECT id, creature_id, event_type, event_inverse_phase_mask, event_chance, event_flags, "
        "event_param1, event_param2, event_param3, event_param4, "
        "action1_type, action1_param1, action1_param2, action1_param3, "
        "action2_type, action2_param1, action2_param2, action2_param3, "
        "action3_type, action3_param1, action3_param2, action3_param3 "
        "FROM creature_ai_scripts");
    if (result)
    {
        barGoLink bar(result->GetRowCount());
        uint32 Count = 0;

        do
        {
            bar.step();
            Field *fields = result->Fetch();

            CreatureEventAI_Event temp;
            temp.event_id = EventAI_Type(fields[0].GetUInt32());
            uint32 i = temp.event_id;

            temp.creature_id = fields[1].GetUInt32();
            uint32 creature_id = temp.creature_id;

            uint32 e_type = fields[2].GetUInt32();
            //Report any errors in event
            if (e_type >= EVENT_T_END)
            {
                sLog.outErrorDb("CreatureEventAI:  Event %u have wrong type (%u), skipping.", i,e_type);
                continue;
            }
            temp.event_type = EventAI_Type(e_type);

            temp.event_inverse_phase_mask = fields[3].GetUInt32();
            temp.event_chance = fields[4].GetUInt8();
            temp.event_flags  = fields[5].GetUInt8();
            temp.raw.param1 = fields[6].GetUInt32();
            temp.raw.param2 = fields[7].GetUInt32();
            temp.raw.param3 = fields[8].GetUInt32();
            temp.raw.param4 = fields[9].GetUInt32();

            //Creature does not exist in database
            if (!sCreatureStorage.LookupEntry<CreatureInfo>(temp.creature_id))
            {
                sLog.outErrorDb("CreatureEventAI:  Event %u has script for non-existing creature entry (%u), skipping.", i, temp.creature_id);
                continue;
            }

            //No chance of this event occuring
            if (temp.event_chance == 0)
                sLog.outErrorDb("CreatureEventAI:  Event %u has 0 percent chance. Event will never trigger!", i);
            //Chance above 100, force it to be 100
            else if (temp.event_chance > 100)
            {
                sLog.outErrorDb("CreatureEventAI:  Creature %u are using event %u with more than 100 percent chance. Adjusting to 100 percent.", temp.creature_id, i);
                temp.event_chance = 100;
            }

            //Individual event checks
            switch (temp.event_type)
            {
                case EVENT_T_TIMER:
                case EVENT_T_TIMER_OOC:
                    if (temp.timer.initialMax < temp.timer.initialMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using timed event(%u) with param2 < param1 (InitialMax < InitialMin). Event will never repeat.", temp.creature_id, i);
                    if (temp.timer.repeatMax < temp.timer.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_HP:
                case EVENT_T_MANA:
                case EVENT_T_TARGET_HP:
                case EVENT_T_TARGET_MANA:
                    if (temp.percent_range.percentMax > 100)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using percentage event(%u) with param2 (MinPercent) > 100. Event will never trigger! ", temp.creature_id, i);

                    if (temp.percent_range.percentMax <= temp.percent_range.percentMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using percentage event(%u) with param1 <= param2 (MaxPercent <= MinPercent). Event will never trigger! ", temp.creature_id, i);

                    if (temp.event_flags & EFLAG_REPEATABLE && !temp.percent_range.repeatMin && !temp.percent_range.repeatMax)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has param3 and param4=0 (RepeatMin/RepeatMax) but cannot be repeatable without timers. Removing EFLAG_REPEATABLE for event %u.", temp.creature_id, i);
                        temp.event_flags &= ~EFLAG_REPEATABLE;
                    }
                    break;
                case EVENT_T_SPELLHIT:
                    if (temp.spell_hit.spellId)
                    {
                        SpellEntry const* pSpell = sSpellStore.LookupEntry(temp.spell_hit.spellId);
                        if (!pSpell)
                        {
                            sLog.outErrorDb("CreatureEventAI:  Creature %u has non-existant SpellID(%u) defined in event %u.", temp.creature_id, temp.spell_hit.spellId, i);
                            continue;
                        }

                        if ((temp.spell_hit.schoolMask & pSpell->SchoolMask) != pSpell->SchoolMask)
                            sLog.outErrorDb("CreatureEventAI:  Creature %u has param1(spellId %u) but param2 is not -1 and not equal to spell's school mask. Event %u can never trigger.", temp.creature_id, temp.spell_hit.schoolMask, i);
                    }

                    if (!temp.spell_hit.schoolMask)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using invalid SpellSchoolMask(%u) defined in event %u.", temp.creature_id, temp.spell_hit.schoolMask, i);

                    if (temp.spell_hit.repeatMax < temp.spell_hit.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_RANGE:
                    if (temp.range.maxDist < temp.range.minDist)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using event(%u) with param2 < param1 (MaxDist < MinDist). Event will never repeat.", temp.creature_id, i);
                    if (temp.range.repeatMax < temp.range.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_OOC_LOS:
                    if (temp.ooc_los.repeatMax < temp.ooc_los.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_SPAWNED:
                    switch(temp.spawned.condition)
                    {
                        case SPAWNED_EVENT_ALWAY:
                            break;
                        case SPAWNED_EVENT_MAP:
                            if(!sMapStore.LookupEntry(temp.spawned.conditionValue1))
                                sLog.outErrorDb("CreatureEventAI:  Creature %u are using spawned event(%u) with param1 = %u 'map specific' but with not existed map (%u) in param2. Event will never repeat.", temp.creature_id, i, temp.spawned.condition, temp.spawned.conditionValue1);
                            break;
                        case SPAWNED_EVENT_ZONE:
                            if(!GetAreaEntryByAreaID(temp.spawned.conditionValue1))
                                sLog.outErrorDb("CreatureEventAI:  Creature %u are using spawned event(%u) with param1 = %u 'area specific' but with not existed area (%u) in param2. Event will never repeat.", temp.creature_id, i, temp.spawned.condition, temp.spawned.conditionValue1);
                        default:
                            sLog.outErrorDb("CreatureEventAI:  Creature %u are using invalid spawned event %u mode (%u) in param1", temp.creature_id, i, temp.spawned.condition);
                            break;
                    }
                    break;
                case EVENT_T_FRIENDLY_HP:
                    if (temp.friendly_hp.repeatMax < temp.friendly_hp.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_FRIENDLY_IS_CC:
                    if (temp.friendly_is_cc.repeatMax < temp.friendly_is_cc.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_FRIENDLY_MISSING_BUFF:
                {
                    SpellEntry const* pSpell = sSpellStore.LookupEntry(temp.spell_hit.spellId);
                    if (!pSpell)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has non-existant SpellID(%u) defined in event %u.", temp.creature_id, temp.spell_hit.spellId, i);
                        continue;
                    }
                    if (temp.friendly_buff.repeatMax < temp.friendly_buff.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                }
                case EVENT_T_KILL:
                    if (temp.kill.repeatMax < temp.kill.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using event(%u) with param2 < param1 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_TARGET_CASTING:
                    if (temp.target_casting.repeatMax < temp.target_casting.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using event(%u) with param2 < param1 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_SUMMONED_UNIT:
                    if (!sCreatureStorage.LookupEntry<CreatureInfo>(temp.summon_unit.creatureId))
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using event(%u) with not existed creature template id (%u) in param1, skipped.", temp.creature_id, i, temp.summon_unit.creatureId);
                    if (temp.summon_unit.repeatMax < temp.summon_unit.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using event(%u) with param2 < param1 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_QUEST_ACCEPT:
                case EVENT_T_QUEST_COMPLETE:
                    if (!objmgr.GetQuestTemplate(temp.quest.questId))
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using event(%u) with not existed qyest id (%u) in param1, skipped.", temp.creature_id, i, temp.quest.questId);
                    sLog.outErrorDb("CreatureEventAI: Creature %u using not implemented event (%u) in event %u.", temp.creature_id, temp.event_id, i);
                    continue;

                case EVENT_T_AGGRO:
                case EVENT_T_DEATH:
                case EVENT_T_EVADE:
                case EVENT_T_REACHED_HOME:
                {
                    if (temp.event_flags & EFLAG_REPEATABLE)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has EFLAG_REPEATABLE set. Event can never be repeatable. Removing flag for event %u.", temp.creature_id, i);
                        temp.event_flags &= ~EFLAG_REPEATABLE;
                    }

                    break;
                }

                case EVENT_T_RECEIVE_EMOTE:
                {
                    if (!sEmotesTextStore.LookupEntry(temp.receive_emote.emoteId))
                    {
                        sLog.outErrorDb("CreatureEventAI: Creature %u using event %u: param1 (EmoteTextId: %u) are not valid.",temp.creature_id, i, temp.receive_emote.emoteId);
                        continue;
                    }

                    if (!PlayerCondition::IsValid(ConditionType(temp.receive_emote.condition), temp.receive_emote.conditionValue1, temp.receive_emote.conditionValue2))
                    {
                        sLog.outErrorDb("CreatureEventAI: Creature %u using event %u: param2 (Condition: %u) are not valid.",temp.creature_id, i, temp.receive_emote.condition);
                        continue;
                    }

                    if (!(temp.event_flags & EFLAG_REPEATABLE))
                    {
                        sLog.outErrorDb("CreatureEventAI: Creature %u using event %u: EFLAG_REPEATABLE not set. Event must always be repeatable. Flag applied.", temp.creature_id, i);
                        temp.event_flags |= EFLAG_REPEATABLE;
                    }

                    break;
                }

                case EVENT_T_BUFFED:
                case EVENT_T_TARGET_BUFFED:
                {
                    SpellEntry const* pSpell = sSpellStore.LookupEntry(temp.buffed.spellId);
                    if (!pSpell)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has non-existant SpellID(%u) defined in event %u.", temp.creature_id, temp.spell_hit.spellId, i);
                        continue;
                    }
                    if (temp.buffed.repeatMax < temp.buffed.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                }

                default:
                    sLog.outErrorDb("CreatureEventAI: Creature %u using not checked at load event (%u) in event %u. Need check code update?", temp.creature_id, temp.event_id, i);
                    break;
            }

            for (uint32 j = 0; j < MAX_ACTIONS; j++)
            {
                uint16 action_type = fields[10+(j*4)].GetUInt16();
                if (action_type >= ACTION_T_END)
                {
                    sLog.outErrorDb("CreatureEventAI:  Event %u Action %u has incorrect action type (%u), replace by ACTION_T_NONE.", i, j+1, action_type);
                    temp.action[j].type = ACTION_T_NONE;
                    continue;
                }

                CreatureEventAI_Action& action = temp.action[j];

                action.type = EventAI_ActionType(action_type);
                action.raw.param1 = fields[11+(j*4)].GetUInt32();
                action.raw.param2 = fields[12+(j*4)].GetUInt32();
                action.raw.param3 = fields[13+(j*4)].GetUInt32();

                //Report any errors in actions
                switch (action.type)
                {
                    case ACTION_T_NONE:
                        break;
                    case ACTION_T_TEXT:
                    {
                        if (action.text.TextId1 < 0)
                        {
                            if (m_CreatureEventAI_TextMap.find(action.text.TextId1) == m_CreatureEventAI_TextMap.end())
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param1 refrences non-existing entry in texts table.", i, j+1);
                        }
                        if (action.text.TextId2 < 0)
                        {
                            if (m_CreatureEventAI_TextMap.find(action.text.TextId2) == m_CreatureEventAI_TextMap.end())
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param2 refrences non-existing entry in texts table.", i, j+1);

                            if (!action.text.TextId1)
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u has param2, but param1 is not set. Required for randomized text.", i, j+1);
                        }
                        if (action.text.TextId3 < 0)
                        {
                            if (m_CreatureEventAI_TextMap.find(action.text.TextId3) == m_CreatureEventAI_TextMap.end())
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param3 refrences non-existing entry in texts table.", i, j+1);

                            if (!action.text.TextId1 || !action.text.TextId2)
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u has param3, but param1 and/or param2 is not set. Required for randomized text.", i, j+1);
                        }
                        break;
                    }
                    case ACTION_T_SET_FACTION:
                        if (action.set_faction.factionId !=0 && !sFactionStore.LookupEntry(action.set_faction.factionId))
                        {
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent FactionId %u.", i, j+1, action.set_faction.factionId);
                            action.set_faction.factionId = 0;
                        }
                        break;
                    case ACTION_T_MORPH_TO_ENTRY_OR_MODEL:
                        if (action.morph.creatureId !=0 || action.morph.modelId !=0)
                        {
                            if (action.morph.creatureId && !sCreatureStorage.LookupEntry<CreatureInfo>(action.morph.creatureId))
                            {
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant Creature entry %u.", i, j+1, action.morph.creatureId);
                                action.morph.creatureId = 0;
                            }

                            if (action.morph.modelId)
                            {
                                if (action.morph.creatureId)
                                {
                                    sLog.outErrorDb("CreatureEventAI:  Event %u Action %u have unused ModelId %u with also set creature id %u.", i, j+1, action.morph.modelId,action.morph.creatureId);
                                    action.morph.modelId = 0;
                                }
                                else if (!sCreatureDisplayInfoStore.LookupEntry(action.morph.modelId))
                                {
                                    sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant ModelId %u.", i, j+1, action.morph.modelId);
                                    action.morph.modelId = 0;
                                }
                            }
                        }
                        break;
                    case ACTION_T_SOUND:
                        if (!sSoundEntriesStore.LookupEntry(action.sound.soundId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant SoundID %u.", i, j+1, action.sound.soundId);
                        break;
                    case ACTION_T_EMOTE:
                        if (!sEmotesStore.LookupEntry(action.emote.emoteId))
                            sLog.outErrorDb("CreatureEventAI: Event %u Action %u param1 (EmoteId: %u) are not valid.", i, j+1, action.emote.emoteId);
                        break;
                    case ACTION_T_RANDOM_SOUND:
                        if (!sSoundEntriesStore.LookupEntry(action.random_sound.soundId1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param1 uses non-existant SoundID %u.", i, j+1, action.random_sound.soundId1);
                        if (action.random_sound.soundId2 >= 0 && !sSoundEntriesStore.LookupEntry(action.random_sound.soundId2))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param2 uses non-existant SoundID %u.", i, j+1, action.random_sound.soundId2);
                        if (action.random_sound.soundId3 >= 0 && !sSoundEntriesStore.LookupEntry(action.random_sound.soundId3))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param3 uses non-existant SoundID %u.", i, j+1, action.random_sound.soundId3);
                        break;
                    case ACTION_T_RANDOM_EMOTE:
                        if (!sEmotesStore.LookupEntry(action.random_emote.emoteId1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param1 (EmoteId: %u) are not valid.", i, j+1, action.random_emote.emoteId1);
                        if (action.random_emote.emoteId2 >= 0 && !sEmotesStore.LookupEntry(action.random_emote.emoteId2))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param2 (EmoteId: %u) are not valid.", i, j+1, action.random_emote.emoteId2);
                        if (action.random_emote.emoteId3 >= 0 && !sEmotesStore.LookupEntry(action.random_emote.emoteId3))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param3 (EmoteId: %u) are not valid.", i, j+1, action.random_emote.emoteId3);
                        break;
                    case ACTION_T_CAST:
                    {
                        const SpellEntry *spell = sSpellStore.LookupEntry(action.cast.spellId);
                        if (!spell)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent SpellID %u.", i, j+1, action.cast.spellId);
                        /* FIXME: temp.raw.param3 not have event tipes with recovery time in it....
                        else
                        {
                            if (spell->RecoveryTime > 0 && temp.event_flags & EFLAG_REPEATABLE)
                            {
                                //output as debug for now, also because there's no general rule all spells have RecoveryTime
                                if (temp.event_param3 < spell->RecoveryTime)
                                    sLog.outDebug("CreatureEventAI:  Event %u Action %u uses SpellID %u but cooldown is longer(%u) than minumum defined in event param3(%u).", i, j+1,action.cast.spellId, spell->RecoveryTime, temp.event_param3);
                            }
                        }
                        */

                        //Cast is always triggered if target is forced to cast on self
                        if (action.cast.castFlags & CAST_FORCE_TARGET_SELF)
                            action.cast.castFlags |= CAST_TRIGGERED;

                        if (action.cast.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    }
                    case ACTION_T_SUMMON:
                        if (!sCreatureStorage.LookupEntry<CreatureInfo>(action.summon.creatureId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent creature entry %u.", i, j+1, action.summon.creatureId);

                        if (action.summon.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    case ACTION_T_THREAT_SINGLE_PCT:
                        if (std::abs(action.threat_single_pct.percent) > 100)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses invalid percent value %u.", i, j+1, action.threat_single_pct.percent);
                        if (action.threat_single_pct.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    case ACTION_T_THREAT_ALL_PCT:
                        if (std::abs(action.threat_all_pct.percent) > 100)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses invalid percent value %u.", i, j+1, action.threat_all_pct.percent);
                        break;
                    case ACTION_T_QUEST_EVENT:
                        if (Quest const* qid = objmgr.GetQuestTemplate(action.quest_event.questId))
                        {
                            if (!qid->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u. SpecialFlags for quest entry %u does not include |2, Action will not have any effect.", i, j+1, action.quest_event.questId);
                        }
                        else
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent Quest entry %u.", i, j+1, action.quest_event.questId);

                        if (action.quest_event.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);

                        break;
                    case ACTION_T_CAST_EVENT:
                        if (!sCreatureStorage.LookupEntry<CreatureInfo>(action.cast_event.creatureId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent creature entry %u.", i, j+1, action.cast_event.creatureId);
                        if (!sSpellStore.LookupEntry(action.cast_event.spellId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent SpellID %u.", i, j+1, action.cast_event.spellId);
                        if (action.cast_event.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    case ACTION_T_SET_UNIT_FIELD:
                        if (action.set_unit_field.field < OBJECT_END || action.set_unit_field.field >= UNIT_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param1 (UNIT_FIELD*). Index out of range for intended use.", i, j+1);
                        if (action.set_unit_field.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    case ACTION_T_SET_UNIT_FLAG:
                    case ACTION_T_REMOVE_UNIT_FLAG:
                        if (action.unit_flag.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    case ACTION_T_SET_PHASE:
                        if (action.set_phase.phase >= MAX_PHASE)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set phase >= %u. Phase mask cannot be used past phase %u.", i, j+1, MAX_PHASE, MAX_PHASE-1);
                        break;
                    case ACTION_T_INC_PHASE:
                        if (action.set_inc_phase.step == 0)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u is incrementing phase by 0. Was this intended?", i, j+1);
                        else if (std::abs(action.set_inc_phase.step) > MAX_PHASE-1)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u is change phase by too large for any use %i.", i, j+1, action.set_inc_phase.step);
                        break;
                    case ACTION_T_QUEST_EVENT_ALL:
                        if (Quest const* qid = objmgr.GetQuestTemplate(action.quest_event_all.questId))
                        {
                            if (!qid->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u. SpecialFlags for quest entry %u does not include |2, Action will not have any effect.", i, j+1, action.quest_event_all.questId);
                        }
                        else
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent Quest entry %u.", i, j+1, action.quest_event_all.questId);
                        break;
                    case ACTION_T_CAST_EVENT_ALL:
                        if (!sCreatureStorage.LookupEntry<CreatureInfo>(action.cast_event_all.creatureId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent creature entry %u.", i, j+1, action.cast_event_all.creatureId);
                        if (!sSpellStore.LookupEntry(action.cast_event_all.spellId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent SpellID %u.", i, j+1, action.cast_event_all.spellId);
                        break;
                    case ACTION_T_REMOVEAURASFROMSPELL:
                        if (!sSpellStore.LookupEntry(action.remove_aura.spellId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existent SpellID %u.", i, j+1, action.remove_aura.spellId);
                        if (action.remove_aura.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    case ACTION_T_RANDOM_PHASE:             //PhaseId1, PhaseId2, PhaseId3
                        if (action.random_phase.phase1 >= MAX_PHASE)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set phase1 >= %u. Phase mask cannot be used past phase %u.", i, j+1, MAX_PHASE, MAX_PHASE-1);
                        if (action.random_phase.phase2 >= MAX_PHASE)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set phase2 >= %u. Phase mask cannot be used past phase %u.", i, j+1, MAX_PHASE, MAX_PHASE-1);
                        if (action.random_phase.phase3 >= MAX_PHASE)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set phase3 >= %u. Phase mask cannot be used past phase %u.", i, j+1, MAX_PHASE, MAX_PHASE-1);
                        break;
                    case ACTION_T_RANDOM_PHASE_RANGE:       //PhaseMin, PhaseMax
                        if (action.random_phase_range.phaseMin >= MAX_PHASE)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set phaseMin >= %u. Phase mask cannot be used past phase %u.", i, j+1, MAX_PHASE, MAX_PHASE-1);
                        if (action.random_phase_range.phaseMin >= MAX_PHASE)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set phaseMax >= %u. Phase mask cannot be used past phase %u.", i, j+1, MAX_PHASE, MAX_PHASE-1);
                        if (action.random_phase_range.phaseMin >= action.random_phase_range.phaseMax)
                        {
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set phaseMax <= phaseMin.", i, j+1);
                            std::swap(action.random_phase_range.phaseMin,action.random_phase_range.phaseMax);
                            // equal case processed at call
                        }
                        break;
                    case ACTION_T_SUMMON_ID:
                        if (!sCreatureStorage.LookupEntry<CreatureInfo>(action.summon_id.creatureId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant creature entry %u.", i, j+1, action.summon_id.creatureId);
                        if (action.summon_id.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        if (m_CreatureEventAI_Summon_Map.find(action.summon_id.spawnId) == m_CreatureEventAI_Summon_Map.end())
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u summons missing CreatureEventAI_Summon %u", i, j+1, action.summon_id.spawnId);
                        break;
                    case ACTION_T_KILLED_MONSTER:
                        if (!sCreatureStorage.LookupEntry<CreatureInfo>(action.killed_monster.creatureId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant creature entry %u.", i, j+1, action.killed_monster.creatureId);
                        if (action.killed_monster.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    case ACTION_T_SET_INST_DATA:
                        if (!(temp.event_flags & EFLAG_NORMAL) && !(temp.event_flags & EFLAG_HEROIC))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u. Cannot set instance data without event flags (normal/heroic).", i, j+1);
                        if (action.set_inst_data.value > 4/*SPECIAL*/)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set instance data above encounter state 4. Custom case?", i, j+1);
                        break;
                    case ACTION_T_SET_INST_DATA64:
                        if (!(temp.event_flags & EFLAG_NORMAL) && !(temp.event_flags & EFLAG_HEROIC))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u. Cannot set instance data without event flags (normal/heroic).", i, j+1);
                        if (action.set_inst_data64.target >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;
                    case ACTION_T_UPDATE_TEMPLATE:
                        if (!sCreatureStorage.LookupEntry<CreatureInfo>(action.update_template.creatureId))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant creature entry %u.", i, j+1, action.update_template.creatureId);
                        break;
                    case ACTION_T_SET_SHEATH:
                        if (action.set_sheath.sheath >= MAX_SHEATH_STATE)
                        {
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses wrong sheath state %u.", i, j+1, action.set_sheath.sheath);
                            action.set_sheath.sheath = SHEATH_STATE_UNARMED;
                        }
                        break;
                    case ACTION_T_SET_INVINCIBILITY_HP_LEVEL:
                        if(action.invincibility_hp_level.is_percent)
                        {
                            if(action.invincibility_hp_level.hp_level > 100)
                            {
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses wrong percent value %u.", i, j+1, action.invincibility_hp_level.hp_level);
                                action.invincibility_hp_level.hp_level = 100;
                            }
                        }
                        break;
                    case ACTION_T_EVADE:                    //No Params
                    case ACTION_T_FLEE_FOR_ASSIST:          //No Params
                    case ACTION_T_DIE:                      //No Params
                    case ACTION_T_ZONE_COMBAT_PULSE:        //No Params
                    case ACTION_T_FORCE_DESPAWN:            //No Params
                    case ACTION_T_AUTO_ATTACK:              //AllowAttackState (0 = stop attack, anything else means continue attacking)
                    case ACTION_T_COMBAT_MOVEMENT:          //AllowCombatMovement (0 = stop combat based movement, anything else continue attacking)
                    case ACTION_T_RANGED_MOVEMENT:          //Distance, Angle
                    case ACTION_T_CALL_FOR_HELP:            //Distance
                        break;

                    case ACTION_T_RANDOM_SAY:
                    case ACTION_T_RANDOM_YELL:
                    case ACTION_T_RANDOM_TEXTEMOTE:
                        sLog.outErrorDb("CreatureEventAI:  Event %u Action %u currently unused ACTION type. Did you forget to update database?", i, j+1);
                        break;

                    case ACTION_T_SET_ACTIVE:
                    case ACTION_T_SET_AGGRESSIVE:
                    case ACTION_T_ATTACK_START_PULSE:
                    case ACTION_T_SUMMON_GO:
                        break;

                    default:
                        sLog.outErrorDb("CreatureEventAI:  Event %u Action %u have currently not checked at load action type (%u). Need check code update?", i, j+1, temp.action[j].type);
                        break;
                }
            }

            //Add to list
            m_CreatureEventAI_Event_Map[creature_id].push_back(temp);
            ++Count;

            if(CreatureInfo const* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(temp.creature_id))
            {
                if(!cInfo->AIName || !cInfo->AIName[0])
                {
                    //sLog.outErrorDb("CreatureEventAI: Creature Entry %u has EventAI script but its AIName is empty. Set to EventAI as default.", cInfo->Entry);
                    size_t len = strlen("EventAI")+1;
                    const_cast<CreatureInfo*>(cInfo)->AIName = new char[len];
                    strncpy(const_cast<char*>(cInfo->AIName), "EventAI", len);
                }
                if(strcmp(cInfo->AIName, "EventAI"))
                {
                    //sLog.outErrorDb("CreatureEventAI: Creature Entry %u has EventAI script but it has AIName %s. EventAI script will be overriden.", cInfo->Entry, cInfo->AIName);
                }
                if(cInfo->ScriptID)
                {
                    //sLog.outErrorDb("CreatureEventAI: Creature Entry %u has EventAI script but it also has C++ script. EventAI script will be overriden.", cInfo->Entry);
                }
            }
        } while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Loaded %u CreatureEventAI scripts", Count);
    }
    else
    {
        barGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 CreatureEventAI scripts. DB table `creature_ai_scripts` is empty.");
    }
}
