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

INSTANTIATE_SINGLETON_1(CreatureEventAIMgr);

// -------------------
void CreatureEventAIMgr::LoadCreatureEventAI_Texts()
{
    // Drop Existing Text Map, only done once and we are ready to add data from multiple sources.
    m_CreatureEventAI_TextMap.clear();

    // Load EventAI Text
    LoadTrinityStrings(WorldDatabase,"creature_ai_texts",-1,1+(TEXT_SOURCE_RANGE));

    // Gather Additional data from EventAI Texts
    QueryResult *result = WorldDatabase.PQuery("SELECT entry, sound, type, language, emote FROM creature_ai_texts");

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

            if (i >= 0)
            {
                sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` is not a negative value.",i);
                continue;
            }

            if (i <= TEXT_SOURCE_RANGE)
            {
                sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` is out of accepted entry range for table.",i);
                continue;
            }

            if (temp.SoundId)
            {
                if (!GetSoundEntriesStore()->LookupEntry(temp.SoundId))
                    sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` has soundId %u but sound does not exist.",i,temp.SoundId);
            }

            if (!GetLanguageDescByID(temp.Language))
                sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` using Language %u but Language does not exist.",i,temp.Language);

            if (temp.Type > CHAT_TYPE_BOSS_WHISPER)
                sLog.outErrorDb("CreatureEventAI:  Entry %i in table `creature_ai_texts` has Type %u but this Chat Type does not exist.",i,temp.Type);

            m_CreatureEventAI_TextMap[i] = temp;
            ++count;
        } while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Loaded %u additional CreatureEventAI Texts data.", count);
    }else
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

    //Gather additional data for EventAI
    QueryResult *result = WorldDatabase.PQuery("SELECT id, position_x, position_y, position_z, orientation, spawntimesecs FROM creature_ai_summons");
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

            //Add to map
            m_CreatureEventAI_Summon_Map[i] = temp;
            ++Count;
        }while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Loaded %u CreatureEventAI summon definitions", Count);
    }else
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

    //Gather event data
    QueryResult *result = WorldDatabase.PQuery("SELECT id, creature_id, event_type, event_inverse_phase_mask, event_chance, event_flags, "
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

            temp.event_id = fields[0].GetUInt32();
            uint32 i = temp.event_id;
            temp.creature_id = fields[1].GetUInt32();
            uint32 creature_id = temp.creature_id;
            temp.event_type = fields[2].GetUInt16();
            temp.event_inverse_phase_mask = fields[3].GetUInt32();
            temp.event_chance = fields[4].GetUInt8();
            temp.event_flags = fields[5].GetUInt8();
            temp.event_param1 = fields[6].GetUInt32();
            temp.event_param2 = fields[7].GetUInt32();
            temp.event_param3 = fields[8].GetUInt32();
            temp.event_param4 = fields[9].GetUInt32();

            CreatureInfo const* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(temp.creature_id);
            //Creature does not exist in database
            if (!cInfo)
            {
                sLog.outErrorDb("CreatureEventAI:  Event %u has script for non-existing creature.", i);
                continue;
            }

            //Report any errors in event
            if (temp.event_type >= EVENT_T_END)
                sLog.outErrorDb("CreatureEventAI:  Event %u has incorrect event type. Maybe DB requires updated version of SD2.", i);

            //No chance of this event occuring
            if (temp.event_chance == 0)
                sLog.outErrorDb("CreatureEventAI:  Event %u has 0 percent chance. Event will never trigger!", i);

            //Chance above 100, force it to be 100
            if (temp.event_chance > 100)
            {
                sLog.outErrorDb("CreatureEventAI:  Creature %u are using event %u with more than 100 percent chance. Adjusting to 100 percent.", temp.creature_id, i);
                temp.event_chance = 100;
            }

            //Individual event checks
            switch (temp.event_type)
            {
                case EVENT_T_HP:
                case EVENT_T_MANA:
                case EVENT_T_TARGET_HP:
                {
                    if (temp.event_param2 > 100)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using percentage event(%u) with param2 (MinPercent) > 100. Event will never trigger! ", temp.creature_id, i);

                    if (temp.event_param1 <= temp.event_param2)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using percentage event(%u) with param1 <= param2 (MaxPercent <= MinPercent). Event will never trigger! ", temp.creature_id, i);

                    if (temp.event_flags & EFLAG_REPEATABLE && !temp.event_param3 && !temp.event_param4)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has param3 and param4=0 (RepeatMin/RepeatMax) but cannot be repeatable without timers. Removing EFLAG_REPEATABLE for event %u.", temp.creature_id, i);
                        temp.event_flags &= ~EFLAG_REPEATABLE;
                    }
                }
                break;

                case EVENT_T_SPELLHIT:
                {
                    if (temp.event_param1)
                    {
                        SpellEntry const* pSpell = GetSpellStore()->LookupEntry(temp.event_param1);
                        if (!pSpell)
                        {
                            sLog.outErrorDb("CreatureEventAI:  Creature %u has non-existant SpellID(%u) defined in event %u.", temp.creature_id, temp.event_param1, i);
                            continue;
                        }

                        if (temp.event_param2_s != -1 && temp.event_param2 != pSpell->SchoolMask)
                            sLog.outErrorDb("CreatureEventAI:  Creature %u has param1(spellId %u) but param2 is not -1 and not equal to spell's school mask. Event %u can never trigger.", temp.creature_id, temp.event_param1, i);
                    }

                    //TODO: fix this system with SPELL_SCHOOL_MASK. Current complicate things, using int32(-1) instead of just 0
                    //SPELL_SCHOOL_MASK_NONE = 0 and does not exist, thus it can not ever trigger or be used in SpellHit()
                    if (temp.event_param2_s != -1 && temp.event_param2_s > SPELL_SCHOOL_MASK_ALL)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using invalid SpellSchoolMask(%u) defined in event %u.", temp.creature_id, temp.event_param2, i);

                    if (temp.event_param4 < temp.event_param3)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                }
                break;

                case EVENT_T_RANGE:
                case EVENT_T_OOC_LOS:
                case EVENT_T_FRIENDLY_HP:
                case EVENT_T_FRIENDLY_IS_CC:
                case EVENT_T_FRIENDLY_MISSING_BUFF:
                {
                    if (temp.event_param4 < temp.event_param3)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                }
                break;

                case EVENT_T_TIMER:
                case EVENT_T_TIMER_OOC:
                {
                    if (temp.event_param2 < temp.event_param1)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using timed event(%u) with param2 < param1 (InitialMax < InitialMin). Event will never repeat.", temp.creature_id, i);

                    if (temp.event_param4 < temp.event_param3)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                }
                break;

                case EVENT_T_KILL:
                case EVENT_T_TARGET_CASTING:
                {
                    if (temp.event_param2 < temp.event_param1)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u are using event(%u) with param2 < param1 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                }
                break;

                case EVENT_T_AGGRO:
                case EVENT_T_DEATH:
                case EVENT_T_EVADE:
                case EVENT_T_SPAWNED:
                case EVENT_T_REACHED_HOME:
                {
                    if (temp.event_flags & EFLAG_REPEATABLE)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has EFLAG_REPEATABLE set. Event can never be repeatable. Removing flag for event %u.", temp.creature_id, i);
                        temp.event_flags &= ~EFLAG_REPEATABLE;
                    }
                }
                break;
            }

            for (uint32 j = 0; j < MAX_ACTIONS; j++)
            {
                temp.action[j].type = fields[10+(j*4)].GetUInt16();
                temp.action[j].param1 = fields[11+(j*4)].GetUInt32();
                temp.action[j].param2 = fields[12+(j*4)].GetUInt32();
                temp.action[j].param3 = fields[13+(j*4)].GetUInt32();

                //Report any errors in actions
                switch (temp.action[j].type)
                {
                    case ACTION_T_TEXT:
                    {
                        if (temp.action[j].param1_s < 0)
                        {
                            if (m_CreatureEventAI_TextMap.find(temp.action[j].param1_s) == m_CreatureEventAI_TextMap.end())
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param1 refrences non-existing entry in texts table.", i, j+1);
                        }
                        if (temp.action[j].param2_s < 0)
                        {
                            if (m_CreatureEventAI_TextMap.find(temp.action[j].param2_s) == m_CreatureEventAI_TextMap.end())
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param2 refrences non-existing entry in texts table.", i, j+1);

                            if (!temp.action[j].param1_s)
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u has param2, but param1 is not set. Required for randomized text.", i, j+1);
                        }
                        if (temp.action[j].param3_s < 0)
                        {
                            if (m_CreatureEventAI_TextMap.find(temp.action[j].param3_s) == m_CreatureEventAI_TextMap.end())
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param3 refrences non-existing entry in texts table.", i, j+1);

                            if (!temp.action[j].param1_s || !temp.action[j].param2_s)
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u has param3, but param1 and/or param2 is not set. Required for randomized text.", i, j+1);
                        }
                    }
                    break;
                    case ACTION_T_SET_FACTION:
                        if (temp.action[j].param1 !=0 && !GetFactionStore()->LookupEntry(temp.action[j].param1))
                        {
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant FactionId %u.", i, j+1, temp.action[j].param1);
                            temp.action[j].param1 = 0;
                        }
                        break;
                    case ACTION_T_MORPH_TO_ENTRY_OR_MODEL:
                        if (temp.action[j].param1 !=0 || temp.action[j].param2 !=0)
                        {
                            if (temp.action[j].param1 && !GetCreatureTemplateStore(temp.action[j].param1))
                            {
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant Creature entry %u.", i, j+1, temp.action[j].param1);
                                temp.action[j].param1 = 0;
                            }

                            if (temp.action[j].param2 && !GetCreatureDisplayStore()->LookupEntry(temp.action[j].param2))
                            {
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant ModelId %u.", i, j+1, temp.action[j].param2);
                                temp.action[j].param2 = 0;
                            }
                        }
                        break;
                    case ACTION_T_SOUND:
                        if (!GetSoundEntriesStore()->LookupEntry(temp.action[j].param1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant SoundID %u.", i, j+1, temp.action[j].param1);
                        break;
/*
                    case ACTION_T_RANDOM_SOUND:
                    {
                        if(!GetSoundEntriesStore()->LookupEntry(temp.action[j].param1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param1 uses non-existant SoundID %u.", i, j+1, temp.action[j].param1);
                        if(!GetSoundEntriesStore()->LookupEntry(temp.action[j].param2))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param2 uses non-existant SoundID %u.", i, j+1, temp.action[j].param2);
                        if(!GetSoundEntriesStore()->LookupEntry(temp.action[j].param3))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param3 uses non-existant SoundID %u.", i, j+1, temp.action[j].param3);
                    }
                    break;
 */
                    case ACTION_T_CAST:
                    {
                        const SpellEntry *spell = GetSpellStore()->LookupEntry(temp.action[j].param1);
                        if (!spell)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant SpellID %u.", i, j+1, temp.action[j].param1);
                        else
                        {
                            if (spell->RecoveryTime > 0 && temp.event_flags & EFLAG_REPEATABLE)
                            {
                                //output as debug for now, also because there's no general rule all spells have RecoveryTime
                                if (temp.event_param3 < spell->RecoveryTime)
                                    debug_log("CreatureEventAI:  Event %u Action %u uses SpellID %u but cooldown is longer(%u) than minumum defined in event param3(%u).", i, j+1,temp.action[j].param1, spell->RecoveryTime, temp.event_param3);
                            }
                        }

                        if (temp.action[j].param2 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                    }
                    break;
                    case ACTION_T_REMOVEAURASFROMSPELL:
                    {
                        if (!GetSpellStore()->LookupEntry(temp.action[j].param2))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant SpellID %u.", i, j+1, temp.action[j].param2);

                        if (temp.action[j].param1 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                    }
                    break;
                    case ACTION_T_QUEST_EVENT:
                    {
                        if (Quest const* qid = GetQuestTemplateStore(temp.action[j].param1))
                        {
                            if (!qid->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u. SpecialFlags for quest entry %u does not include |2, Action will not have any effect.", i, j+1, temp.action[j].param1);
                        }
                        else
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant Quest entry %u.", i, j+1, temp.action[j].param1);

                        if (temp.action[j].param2 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                    }
                    break;
                    case ACTION_T_QUEST_EVENT_ALL:
                    {
                        if (Quest const* qid = GetQuestTemplateStore(temp.action[j].param1))
                        {
                            if (!qid->HasFlag(QUEST_TRINITY_FLAGS_EXPLORATION_OR_EVENT))
                                sLog.outErrorDb("CreatureEventAI:  Event %u Action %u. SpecialFlags for quest entry %u does not include |2, Action will not have any effect.", i, j+1, temp.action[j].param1);
                        }
                        else
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant Quest entry %u.", i, j+1, temp.action[j].param1);
                    }
                    break;
                    case ACTION_T_CASTCREATUREGO:
                    {
                        if (!GetCreatureTemplateStore(temp.action[j].param1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant creature entry %u.", i, j+1, temp.action[j].param1);

                        if (!GetSpellStore()->LookupEntry(temp.action[j].param2))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant SpellID %u.", i, j+1, temp.action[j].param2);

                        if (temp.action[j].param3 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                    }
                    break;
                    case ACTION_T_CASTCREATUREGO_ALL:
                    {
                        if (!GetQuestTemplateStore(temp.action[j].param1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant Quest entry %u.", i, j+1, temp.action[j].param1);

                        if (!GetSpellStore()->LookupEntry(temp.action[j].param2))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant SpellID %u.", i, j+1, temp.action[j].param2);
                    }
                    break;

                    //2nd param target
                    case ACTION_T_SUMMON_ID:
                    {
                        if (!GetCreatureTemplateStore(temp.action[j].param1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant creature entry %u.", i, j+1, temp.action[j].param1);

                        if (m_CreatureEventAI_Summon_Map.find(temp.action[j].param3) == m_CreatureEventAI_Summon_Map.end())
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u summons missing CreatureEventAI_Summon %u", i, j+1, temp.action[j].param3);

                        if (temp.action[j].param2 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                    }
                    break;
                    case ACTION_T_KILLED_MONSTER:
                    {
                        if (!GetCreatureTemplateStore(temp.action[j].param1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant creature entry %u.", i, j+1, temp.action[j].param1);

                        if (temp.action[j].param2 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                    }
                    break;
                    case ACTION_T_SUMMON:
                    {
                        if (!GetCreatureTemplateStore(temp.action[j].param1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant creature entry %u.", i, j+1, temp.action[j].param1);

                        if (temp.action[j].param2 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                    }
                    break;
                    case ACTION_T_THREAT_SINGLE_PCT:
                    case ACTION_T_SET_UNIT_FLAG:
                    case ACTION_T_REMOVE_UNIT_FLAG:
                        if (temp.action[j].param2 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;

                        //3rd param target
                    case ACTION_T_SET_UNIT_FIELD:
                        if (temp.action[j].param1 < OBJECT_END || temp.action[j].param1 >= UNIT_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u param1 (UNIT_FIELD*). Index out of range for intended use.", i, j+1);
                        if (temp.action[j].param3 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                        break;

                    case ACTION_T_SET_PHASE:
                        if (temp.action[j].param1 > 31)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set phase > 31. Phase mask cannot be used past phase 31.", i, j+1);
                        break;

                    case ACTION_T_INC_PHASE:
                        if (!temp.action[j].param1)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u is incrementing phase by 0. Was this intended?", i, j+1);
                        break;

                    case ACTION_T_SET_INST_DATA:
                    {
                        if (!(temp.event_flags & EFLAG_NORMAL) && !(temp.event_flags & EFLAG_HEROIC))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u. Cannot set instance data without event flags (normal/heroic).", i, j+1);

                        if (temp.action[j].param2 > 4/*SPECIAL*/)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u attempts to set instance data above encounter state 4. Custom case?", i, j+1);
                    }
                    break;
                    case ACTION_T_SET_INST_DATA64:
                    {
                        if (!(temp.event_flags & EFLAG_NORMAL) && !(temp.event_flags & EFLAG_HEROIC))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u. Cannot set instance data without event flags (normal/heroic).", i, j+1);

                        if (temp.action[j].param2 >= TARGET_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses incorrect Target type", i, j+1);
                    }
                    break;
                    case ACTION_T_UPDATE_TEMPLATE:
                    {
                        if (!GetCreatureTemplateStore(temp.action[j].param1))
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u uses non-existant creature entry %u.", i, j+1, temp.action[j].param1);
                    }
                    break;
                    case ACTION_T_RANDOM_SAY:
                    case ACTION_T_RANDOM_YELL:
                    case ACTION_T_RANDOM_TEXTEMOTE:
                        sLog.outErrorDb("CreatureEventAI:  Event %u Action %u currently unused ACTION type. Did you forget to update database?", i, j+1);
                        break;

                    default:
                        if (temp.action[j].type >= ACTION_T_END)
                            sLog.outErrorDb("CreatureEventAI:  Event %u Action %u has incorrect action type. Maybe DB requires updated version of SD2.", i, j+1);
                        break;
                }
            }

            //Add to list
            m_CreatureEventAI_Event_Map[creature_id].push_back(temp);
            ++Count;
        } while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Loaded %u CreatureEventAI scripts", Count);
    }else
    {
        barGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 CreatureEventAI scripts. DB table `creature_ai_scripts` is empty.");
    }
}
