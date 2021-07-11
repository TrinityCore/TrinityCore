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
#include "SQLStorages.h"
#include "CreatureEventAI.h"
#include "CreatureEventAIMgr.h"
#include "ObjectMgr.h"
#include "ProgressBar.h"
#include "Policies/SingletonImp.h"
#include "ObjectGuid.h"
#include "GridDefines.h"
#include "Conditions.h"
#include "ScriptMgr.h"

INSTANTIATE_SINGLETON_1(CreatureEventAIMgr);

// -------------------
void CreatureEventAIMgr::LoadCreatureEventAI_Events()
{
    //Drop Existing EventAI List
    m_CreatureEventAI_Event_Map.clear();

    // Gather event data
    QueryResult* result = WorldDatabase.Query("SELECT id, creature_id, condition_id, event_type, event_inverse_phase_mask, event_chance, event_flags, "
                          "event_param1, event_param2, event_param3, event_param4, "
                          "action1_script, action2_script, action3_script "
                          "FROM creature_ai_events");
    if (result)
    {
        BarGoLink bar(result->GetRowCount());
        uint32 Count = 0;

        do
        {
            bar.step();
            Field* fields = result->Fetch();

            CreatureEventAI_Event temp;
            temp.event_id = EventAI_Type(fields[0].GetUInt32());
            uint32 i = temp.event_id;

            temp.creature_id = fields[1].GetUInt32();
            uint32 creature_id = temp.creature_id;

            temp.condition_id = fields[2].GetUInt32();

            uint32 e_type = fields[3].GetUInt32();
            //Report any errors in event
            if (e_type >= EVENT_T_END)
            {
                sLog.outErrorDb("CreatureEventAI:  Event %u with wrong type (%u), skipping.", i, e_type);
                continue;
            }
            temp.event_type = EventAI_Type(e_type);

            temp.event_inverse_phase_mask = fields[4].GetUInt32();
            temp.event_chance = fields[5].GetUInt8();
            temp.event_flags  = fields[6].GetUInt8();
            temp.raw.param1 = fields[7].GetUInt32();
            temp.raw.param2 = fields[8].GetUInt32();
            temp.raw.param3 = fields[9].GetUInt32();
            temp.raw.param4 = fields[10].GetUInt32();

            //Creature does not exist in database
            if (!sCreatureStorage.LookupEntry<CreatureInfo>(temp.creature_id))
            {
                if (!sObjectMgr.IsExistingCreatureId(temp.creature_id))
                    sLog.outErrorDb("CreatureEventAI:  Event %u has script for non-existing creature entry (%u), skipping.", i, temp.creature_id);
                continue;
            }

            //No chance of this event occuring
            if (temp.event_chance == 0)
                sLog.outErrorDb("CreatureEventAI:  Event %u has 0 percent chance. Event will never trigger!", i);
            //Chance above 100, force it to be 100
            else if (temp.event_chance > 100)
            {
                sLog.outErrorDb("CreatureEventAI:  Creature %u is using event %u with more than 100 percent chance. Adjusting to 100 percent.", temp.creature_id, i);
                temp.event_chance = 100;
            }

            if (temp.condition_id)
            {
                ConditionEntry const* condition = sConditionStorage.LookupEntry<ConditionEntry>(temp.condition_id);
                if (!condition)
                {
                    sLog.outErrorDb("CreatureEventAI: Creature %u has condition_id %u that does not exist in `conditions`, ignoring", temp.creature_id, temp.condition_id);
                    temp.condition_id = 0;
                }
            }          

            //Individual event checks
            switch (temp.event_type)
            {
                case EVENT_T_TIMER:
                case EVENT_T_TIMER_OOC:
                    if (temp.timer.initialMax < temp.timer.initialMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using timed event(%u) with param2 < param1 (InitialMax < InitialMin). Event will never repeat.", temp.creature_id, i);
                    if (temp.timer.repeatMax < temp.timer.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_HP:
                case EVENT_T_MANA:
                case EVENT_T_TARGET_HP:
                case EVENT_T_TARGET_MANA:
                    if (temp.percent_range.percentMax > 100)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using percentage event(%u) with param2 (MinPercent) > 100. Event will never trigger! ", temp.creature_id, i);

                    if (temp.percent_range.percentMax <= temp.percent_range.percentMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using percentage event(%u) with param1 <= param2 (MaxPercent <= MinPercent). Event will never trigger! ", temp.creature_id, i);

                    if ((temp.event_flags & EFLAG_REPEATABLE) && !temp.percent_range.repeatMin && !temp.percent_range.repeatMax)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has param3 and param4=0 (RepeatMin/RepeatMax) but cannot be repeatable without timers. Removing EFLAG_REPEATABLE for event %u.", temp.creature_id, i);
                        temp.event_flags &= ~EFLAG_REPEATABLE;
                    }
                    break;
                case EVENT_T_HIT_BY_SPELL:
                    if (temp.hit_by_spell.spellId)
                    {
                        SpellEntry const* pSpell = sSpellMgr.GetSpellEntry(temp.hit_by_spell.spellId);
                        if (!pSpell)
                        {
                            sLog.outErrorDb("CreatureEventAI:  Creature %u has nonexistent SpellID(%u) defined in event %u.", temp.creature_id, temp.hit_by_spell.spellId, i);
                            continue;
                        }

                        if ((temp.hit_by_spell.schoolMask & GetSchoolMask(pSpell->School)) != GetSchoolMask(pSpell->School))
                            sLog.outErrorDb("CreatureEventAI:  Creature %u has param1(spellId %u) but param2 is not -1 and not equal to spell's school mask. Event %u can never trigger.", temp.creature_id, temp.hit_by_spell.schoolMask, i);
                    }

                    if (!temp.hit_by_spell.schoolMask)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using invalid SpellSchoolMask(%u) defined in event %u.", temp.creature_id, temp.hit_by_spell.schoolMask, i);

                    if (temp.hit_by_spell.repeatMax < temp.hit_by_spell.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_RANGE:
                    if (temp.range.maxDist < temp.range.minDist)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using event(%u) with param2 < param1 (MaxDist < MinDist). Event will never repeat.", temp.creature_id, i);
                    if (temp.range.repeatMax < temp.range.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_OOC_LOS:
                    if (temp.ooc_los.reaction > ULR_NON_HOSTILE)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using invalid reaction (%u) defined in event %u.", temp.creature_id, temp.ooc_los.reaction, i);
                    if (temp.ooc_los.repeatMax < temp.ooc_los.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_SPAWNED:
                    break;
                case EVENT_T_FRIENDLY_HP:
                    if (temp.friendly_hp.repeatMax < temp.friendly_hp.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_FRIENDLY_IS_CC:
                    if (temp.friendly_is_cc.repeatMax < temp.friendly_is_cc.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_FRIENDLY_MISSING_BUFF:
                {
                    SpellEntry const* pSpell = sSpellMgr.GetSpellEntry(temp.friendly_buff.spellId);
                    if (!pSpell)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has nonexistent SpellID(%u) defined in event %u.", temp.creature_id, temp.friendly_buff.spellId, i);
                        continue;
                    }
                    if (temp.friendly_buff.radius <= 0)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has wrong radius (%u) for EVENT_T_FRIENDLY_MISSING_BUFF defined in event %u.", temp.creature_id, temp.friendly_buff.radius, i);
                        continue;
                    }
                    if (temp.friendly_buff.repeatMax < temp.friendly_buff.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                }
                case EVENT_T_KILL:
                    if (temp.kill.repeatMax < temp.kill.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using event(%u) with param2 < param1 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_TARGET_CASTING:
                    if (temp.target_casting.repeatMax < temp.target_casting.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using event(%u) with param2 < param1 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_SUMMONED_UNIT:
                case EVENT_T_SUMMONED_JUST_DIED:
                case EVENT_T_SUMMONED_JUST_DESPAWN:
                    if (!sCreatureStorage.LookupEntry<CreatureInfo>(temp.summoned.creatureId))
                    {
                        if (!sObjectMgr.IsExistingCreatureId(temp.group_member_died.creatureId))
                            sLog.outErrorDb("CreatureEventAI:  Creature %u is using event(%u) with nonexistent creature template id (%u) in param1, skipped.", temp.creature_id, i, temp.summoned.creatureId);
                        continue;
                    }
                    if (temp.summoned.repeatMax < temp.summoned.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using event(%u) with param2 < param1 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                case EVENT_T_QUEST_ACCEPT:
                case EVENT_T_QUEST_COMPLETE:
                    sLog.outErrorDb("CreatureEventAI: Creature %u using not implemented event (%u) in event %u.", temp.creature_id, temp.event_id, i);
                    continue;
                case EVENT_T_AGGRO:
                case EVENT_T_DEATH:
                case EVENT_T_EVADE:
                case EVENT_T_LEAVE_COMBAT:
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
                        sLog.outErrorDb("CreatureEventAI: Creature %u using event %u: param1 (EmoteTextId: %u) are not valid.", temp.creature_id, i, temp.receive_emote.emoteId);
                        continue;
                    }

                    if (!(temp.event_flags & EFLAG_REPEATABLE))
                    {
                        sLog.outErrorDb("CreatureEventAI: Creature %u using event %u: EFLAG_REPEATABLE not set. Event must always be repeatable. Flag applied.", temp.creature_id, i);
                        temp.event_flags |= EFLAG_REPEATABLE;
                    }

                    break;
                }

                case EVENT_T_AURA:
                case EVENT_T_TARGET_AURA:
                case EVENT_T_MISSING_AURA:
                case EVENT_T_TARGET_MISSING_AURA:
                {
                    SpellEntry const* pSpell = sSpellMgr.GetSpellEntry(temp.buffed.spellId);
                    if (!pSpell)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has nonexistent SpellID(%u) defined in event %u.", temp.creature_id, temp.buffed.spellId, i);
                        continue;
                    }
                    if (temp.buffed.amount < 1)
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has wrong spell stack size (%u) defined in event %u.", temp.creature_id, temp.buffed.amount, i);
                        continue;
                    }
                    if (temp.buffed.repeatMax < temp.buffed.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                }
                case EVENT_T_MOVEMENT_INFORM:
                {
                    if ((temp.move_inform.motionType > DISTANCING_MOTION_TYPE))
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using an invalid motion type. Event %u will never trigger! ", temp.creature_id, i);
                    if (temp.move_inform.repeatMax < temp.move_inform.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                }
                case EVENT_T_MAP_SCRIPT_EVENT:
                    break;
                case EVENT_T_GROUP_MEMBER_DIED:
                {
                    if (temp.group_member_died.creatureId)
                    {
                        if (!sCreatureStorage.LookupEntry<CreatureInfo>(temp.group_member_died.creatureId))
                        {
                            if (!sObjectMgr.IsExistingCreatureId(temp.group_member_died.creatureId))
                                sLog.outErrorDb("CreatureEventAI:  Creature %u is using event(%u) with nonexistent creature template id (%u) in param1, skipped.", temp.creature_id, i, temp.group_member_died.creatureId);
                            continue;
                        }
                    } 
                 break;
                }
                case EVENT_T_VICTIM_ROOTED:
                {
                    if (temp.victim_rooted.repeatMax < temp.victim_rooted.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param2 < param1 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                }
                case EVENT_T_HIT_BY_AURA:
                {
                    if (temp.hit_by_aura.auraType && (temp.hit_by_aura.auraType >= TOTAL_AURAS))
                    {
                        sLog.outErrorDb("CreatureEventAI:  Creature %u has nonexistent AuraType(%u) defined in event %u.", temp.creature_id, temp.hit_by_aura.auraType, i);
                        continue;
                    }
                    if (temp.hit_by_aura.repeatMax < temp.hit_by_aura.repeatMin)
                        sLog.outErrorDb("CreatureEventAI:  Creature %u is using repeatable event(%u) with param4 < param3 (RepeatMax < RepeatMin). Event will never repeat.", temp.creature_id, i);
                    break;
                }
                default:
                    sLog.outErrorDb("CreatureEventAI: Creature %u using not checked at load event (%u) in event %u. Need check code update?", temp.creature_id, temp.event_id, i);
                    break;
            }

            for (uint32 j = 0; j < MAX_ACTIONS; j++)
            {
                uint32 action_script = fields[11 + j].GetUInt32();
                temp.action[j] = nullptr;

                if (action_script)
                {
                    const auto& scriptIter = sCreatureAIScripts.find(action_script);

                    if (scriptIter != sCreatureAIScripts.end())
                    {
                        temp.action[j] = &scriptIter->second;
                    }
                    else
                    {
                        sLog.outErrorDb("CreatureEventAI: Event %u has a non-existent script = %u in action%u_script.", i, action_script, j+1);
                        continue;
                    }
                }
            }

            //Add to list
            m_CreatureEventAI_Event_Map[creature_id].push_back(temp);
            ++Count;
        }
        while (result->NextRow());

        delete result;

        sLog.outString();
        sLog.outString(">> Loaded %u CreatureEventAI events.", Count);
    }
    else
    {
        BarGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 CreatureEventAI events. DB table `creature_ai_events` is empty.");
    }
}
