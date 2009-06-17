/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Mob_Event_AI
SD%Complete: 90
SDComment: Database Event AI
SDCategory: Creatures
EndScriptData */

#include "precompiled.h"
#include "mob_event_ai.h"
#include "ObjectMgr.h"

#define EVENT_UPDATE_TIME               500
#define SPELL_RUN_AWAY                  8225

struct EventHolder
{
    EventHolder(EventAI_Event p) : Event(p), Time(0), Enabled(true){}

    EventAI_Event Event;
    uint32 Time;
    bool Enabled;
};

struct TRINITY_DLL_DECL Mob_EventAI : public ScriptedAI
{
    Mob_EventAI(Creature *c, std::list<EventHolder> pEventList) : ScriptedAI(c)
    {
        EventList = pEventList;
        Phase = 0;
        CombatMovementEnabled = true;
        MeleeEnabled = true;
        AttackDistance = 0;
        AttackAngle = 0.0f;

        //Handle Spawned Events
        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
                case EVENT_T_SPAWNED:
                    ProcessEvent(*i);
                    break;
            }
        }
    }

    ~Mob_EventAI()
    {
        EventList.clear();
    }

    //Variables used by EventAI for handling events
    std::list<EventHolder> EventList;                       //Holder for events (stores enabled, time, and eventid)
    uint32 EventUpdateTime;                                 //Time between event updates
    uint32 EventDiff;                                       //Time between the last event call

    //Variables used by Events themselves
    uint8 Phase;                                            //Current phase, max 32 phases
    bool CombatMovementEnabled;                             //If we allow targeted movment gen (movement twoards top threat)
    bool MeleeEnabled;                                      //If we allow melee auto attack
    uint32 AttackDistance;                                  //Distance to attack from
    float AttackAngle;                                      //Angle of attack
    uint32 TimetoFleeLeft;                                  //For fleeing

    bool ProcessEvent(EventHolder& pHolder, Unit* pActionInvoker = NULL)
    {
        if (!pHolder.Enabled || pHolder.Time)
            return false;

        //Check the inverse phase mask (event doesn't trigger if current phase bit is set in mask)
        if (pHolder.Event.event_inverse_phase_mask & (1 << Phase))
            return false;

        //Store random here so that all random actions match up
        uint32 rnd = rand();

        //Return if chance for event is not met
        if (pHolder.Event.event_chance <= rnd % 100)
            return false;

        union
        {
            uint32 param1;
            int32 param1_s;
        };

        union
        {
            uint32 param2;
            int32 param2_s;
        };

        union
        {
            uint32 param3;
            int32 param3_s;
        };

        union
        {
            uint32 param4;
            int32 param4_s;
        };

        param1 = pHolder.Event.event_param1;
        param2 = pHolder.Event.event_param2;
        param3 = pHolder.Event.event_param3;
        param4 = pHolder.Event.event_param4;

        //Check event conditions based on the event type, also reset events
        switch (pHolder.Event.event_type)
        {
        case EVENT_T_TIMER:
            {
                if (!m_creature->isInCombat())
                    return false;

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_TIMER_OOC:
            {
                if (m_creature->isInCombat())
                    return false;

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_HP:
            {
                if (!m_creature->isInCombat() || !m_creature->GetMaxHealth())
                    return false;

                uint32 perc = (m_creature->GetHealth()*100) / m_creature->GetMaxHealth();

                if (perc > param1 || perc < param2)
                    return false;

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_MANA:
            {
                if (!m_creature->isInCombat() || !m_creature->GetMaxPower(POWER_MANA))
                    return false;

                uint32 perc = (m_creature->GetPower(POWER_MANA)*100) / m_creature->GetMaxPower(POWER_MANA);

                if (perc > param1 || perc < param2)
                    return false;

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_AGGRO:
            {
            }
            break;
        case EVENT_T_KILL:
            {
                //Repeat Timers
                if (param1 == param2)
                {
                    pHolder.Time = param1;

                }else if (param2 > param1)
                    pHolder.Time = urand(param1, param2);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
        case EVENT_T_DEATH:
            {
            }
            break;
        case EVENT_T_EVADE:
            {
            }
            break;
        case EVENT_T_SPELLHIT:
            {
                //Spell hit is special case, param1 and param2 handled within EventAI::SpellHit

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_RANGE:
            {
                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_OOC_LOS:
            {
                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_SPAWNED:
            {
            }
            break;
        case EVENT_T_TARGET_HP:
            {
                if (!m_creature->isInCombat() || !m_creature->getVictim() || !m_creature->getVictim()->GetMaxHealth())
                    return false;

                uint32 perc = (m_creature->getVictim()->GetHealth()*100) / m_creature->getVictim()->GetMaxHealth();

                if (perc > param1 || perc < param2)
                    return false;

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_TARGET_CASTING:
            {
                if (!m_creature->isInCombat() || !m_creature->getVictim() || !m_creature->getVictim()->IsNonMeleeSpellCasted(false, false, true))
                    return false;

                //Repeat Timers
                if (param1 == param2)
                {
                    pHolder.Time = param1;

                }else if (param2 > param1)
                    pHolder.Time = urand(param1, param2);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_FRIENDLY_HP:
            {
                if (!m_creature->isInCombat())
                    return false;

                Unit* pUnit = DoSelectLowestHpFriendly(param2, param1);

                if (!pUnit)
                    return false;

                pActionInvoker = pUnit;

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_FRIENDLY_IS_CC:
            {
                if (!m_creature->isInCombat())
                    return false;

                std::list<Creature*> pList = DoFindFriendlyCC(param2);

                //List is empty
                if (pList.empty())
                    return false;

                //We don't really care about the whole list, just return first available
                pActionInvoker = *(pList.begin());

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_FRIENDLY_MISSING_BUFF:
            {
                std::list<Creature*> pList = DoFindFriendlyMissingBuff(param2, param1);

                //List is empty
                if (pList.empty())
                    return false;

                //We don't really care about the whole list, just return first available
                pActionInvoker = *(pList.begin());

                //Repeat Timers
                if (param3 == param4)
                {
                    pHolder.Time = param3;

                }else if (param4 > param3)
                    pHolder.Time = urand(param3, param4);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_SUMMONED_UNIT:
            {
                //Prevent event from occuring on no unit or non creatures
                if (!pActionInvoker || pActionInvoker->GetTypeId()!=TYPEID_UNIT)
                    return false;

                //Creature id doesn't match up
                if (param1 && ((Creature*)pActionInvoker)->GetEntry() != param1)
                    return false;

                //Repeat Timers
                if (param2 == param3)
                {
                    pHolder.Time = param2;

                }else if (param3 > param2)
                    pHolder.Time = urand(param2, param3);
                else
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has RandomMax < RandomMin. Event repeating disabled.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
                    pHolder.Enabled = false;
                }
            }
            break;
        case EVENT_T_REACHED_HOME:
            {
            }
            break;
        default:
            if (EAI_ErrorLevel > 0)
                error_db_log("TSCR: Creature %u using Event %u has invalid Event Type(%u), missing from ProcessEvent() Switch.", m_creature->GetEntry(), pHolder.Event.event_id, pHolder.Event.event_type);
            break;
        }

        //Disable non-repeatable events
        if (!(pHolder.Event.event_flags & EFLAG_REPEATABLE))
            pHolder.Enabled = false;

        //Process actions
        for (uint32 j = 0; j < MAX_ACTIONS; j++)
            ProcessAction(pHolder.Event.action[j].type, pHolder.Event.action[j].param1, pHolder.Event.action[j].param2, pHolder.Event.action[j].param3, rnd, pHolder.Event.event_id, pActionInvoker);

        return true;
    }

    inline uint32 GetRandActionParam(uint32 rnd, uint32 param1, uint32 param2, uint32 param3)
    {
        switch (rnd % 3)
        {
        case 0:
            return param1;
            break;
        case 1:
            return param2;
            break;
        case 2:
            return param3;
            break;
        }
        return 0;
    }

    inline Unit* GetTargetByType(uint32 Target, Unit* pActionInvoker)
    {
        switch (Target)
        {
        case TARGET_T_SELF:
            return m_creature;
            break;
        case TARGET_T_HOSTILE:
            return m_creature->getVictim();
            break;
        case TARGET_T_HOSTILE_SECOND_AGGRO:
            return SelectUnit(SELECT_TARGET_TOPAGGRO,1);
            break;
        case TARGET_T_HOSTILE_LAST_AGGRO:
            return SelectUnit(SELECT_TARGET_BOTTOMAGGRO,0);
            break;
        case TARGET_T_HOSTILE_RANDOM:
            return SelectUnit(SELECT_TARGET_RANDOM,0);
            break;
        case TARGET_T_HOSTILE_RANDOM_NOT_TOP:
            return SelectUnit(SELECT_TARGET_RANDOM,1);
            break;
        case TARGET_T_ACTION_INVOKER:
            return pActionInvoker;
            break;
        default:
            return NULL;
            break;
        };
    }

    void ProcessAction(uint16 type, uint32 param1, uint32 param2, uint32 param3, uint32 rnd, uint32 EventId, Unit* pActionInvoker)
    {
        switch (type)
        {
        case ACTION_T_TEXT:
            {
                if (!param1)
                    return;

                uint32 temp = 0;

                if (param2 && param3)
                {
                    switch( rand()%3 )
                    {
                        case 0: temp = param1; break;
                        case 2: temp = param2; break;
                        case 3: temp = param3; break;
                    }
                }else if ( param2 && urand(0,1) )
                {
                    temp = param2;
                }else
                {
                    temp = param1;
                }

                if (temp)
                {
                    Unit* target = NULL;
                    Unit* owner = NULL;

                    if (pActionInvoker)
                    {
                        if (pActionInvoker->GetTypeId() == TYPEID_PLAYER)
                            target = pActionInvoker;
                        else if (owner = pActionInvoker->GetOwner())
                        {
                            if (owner->GetTypeId() == TYPEID_PLAYER)
                                target = owner;
                        }
                    }
                    else if (target = m_creature->getVictim())
                    {
                        if (target->GetTypeId() != TYPEID_PLAYER)
                        {
                            if (owner = target->GetOwner())
                            {
                                if (owner->GetTypeId() == TYPEID_PLAYER)
                                    target = owner;
                            }
                        }
                    }

                    DoScriptText(temp, m_creature, target);
                }
            }
            break;
        case ACTION_T_SET_FACTION:
            {
                if (param1)
                    m_creature->setFaction(param1);
                else
                {
                    if (CreatureInfo const* ci = GetCreatureTemplateStore(m_creature->GetEntry()))
                    {
                        //if no id provided, assume reset and then use default
                        if (m_creature->getFaction() != ci->faction_A)
                            m_creature->setFaction(ci->faction_A);
                    }
                }
            }
            break;
        case ACTION_T_MORPH_TO_ENTRY_OR_MODEL:
            {
                if (param1 || param2)
                {
                    //set model based on entry from creature_template
                    if (param1)
                    {
                        if (CreatureInfo const* ci = GetCreatureTemplateStore(param1))
                        {
                            //use default display
                            if (ci->Modelid_A1)
                                m_creature->SetDisplayId(ci->Modelid_A1);
                        }
                    }
                    //if no param1, then use value from param2 (modelId)
                    else
                        m_creature->SetDisplayId(param2);
                }
                else
                    m_creature->DeMorph();
            }
            break;
        case ACTION_T_SOUND:
            DoPlaySoundToSet(m_creature, param1);
            break;
        case ACTION_T_EMOTE:
            m_creature->HandleEmoteCommand(param1);
            break;
        case ACTION_T_RANDOM_SOUND:
            {
                uint32 temp = GetRandActionParam(rnd, param1, param2, param3);

                if (temp != 0xffffffff)
                    DoPlaySoundToSet(m_creature, temp);
            }
            break;
        case ACTION_T_RANDOM_EMOTE:
            {
                uint32 temp = GetRandActionParam(rnd, param1, param2, param3);

                if (temp != 0xffffffff)
                    m_creature->HandleEmoteCommand(temp);
            }
            break;
        case ACTION_T_CAST:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);
                Unit* caster = m_creature;

                if (!target)
                    return;

                //Cast is always triggered if target is forced to cast on self
                if (param3 & CAST_FORCE_TARGET_SELF)
                {
                    param3 |= CAST_TRIGGERED;
                    caster = target;
                }

                //Allowed to cast only if not casting (unless we interrupt ourself) or if spell is triggered
                bool canCast = !(caster->IsNonMeleeSpellCasted(false) && (param3 & CAST_TRIGGERED | CAST_INTURRUPT_PREVIOUS));

                // If cast flag CAST_AURA_NOT_PRESENT is active, check if target already has aura on them
                if(param3 & CAST_AURA_NOT_PRESENT)
                {
                    for(uint8 i = 0; i < 3; ++i)
                        if(target->HasAura(param1, i))
                            return;
                }

                if (canCast)
                {
                    const SpellEntry* tSpell = GetSpellStore()->LookupEntry(param1);

                    //Verify that spell exists
                    if (tSpell)
                    {
                        //Check if cannot cast spell
                        if (!(param3 & (CAST_FORCE_TARGET_SELF | CAST_FORCE_CAST)) &&
                            !CanCast(target, tSpell, (param3 & CAST_TRIGGERED)))
                        {
                            //Melee current victim if flag not set
                            if (!(param3 & CAST_NO_MELEE_IF_OOM))
                            {
                                AttackDistance = 0;
                                AttackAngle = 0;

                                m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim(), AttackDistance, AttackAngle);
                            }

                        }else
                        {
                            //Interrupt any previous spell
                            if (caster->IsNonMeleeSpellCasted(false) && param3 & CAST_INTURRUPT_PREVIOUS)
                                caster->InterruptNonMeleeSpells(false);

                            caster->CastSpell(target, param1, (param3 & CAST_TRIGGERED));
                        }

                    }else if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: EventAI event %d creature %d attempt to cast spell that doesn't exist %d", EventId, m_creature->GetEntry(), param1);
                }
            }
            break;
        case ACTION_T_SUMMON:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);

                Creature* pCreature = NULL;

                if (param3)
                    pCreature = DoSpawnCreature(param1, 0, 0, 0, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, param3);
                else pCreature = pCreature = DoSpawnCreature(param1, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

                if (!pCreature)
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log( "TSCR: EventAI failed to spawn creature %u. Spawn event %d is on creature %d", param1, EventId, m_creature->GetEntry());
                }
                else if (param2 != TARGET_T_SELF && target)
                    pCreature->AI()->AttackStart(target);
            }
            break;
        case ACTION_T_THREAT_SINGLE_PCT:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);

                if (target)
                    DoModifyThreatPercent(target, param1);
            }
            break;
        case ACTION_T_THREAT_ALL_PCT:
            {
                Unit* Temp = NULL;

                std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
                for (; i != m_creature->getThreatManager().getThreatList().end(); ++i)
                {
                    Temp = Unit::GetUnit((*m_creature),(*i)->getUnitGuid());
                    if (Temp)
                        DoModifyThreatPercent(Temp, param1);
                }
            }
            break;
        case ACTION_T_QUEST_EVENT:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);

                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    ((Player*)target)->AreaExploredOrEventHappens(param1);
            }
            break;
        case ACTION_T_CASTCREATUREGO:
            {
                Unit* target = GetTargetByType(param3, pActionInvoker);

                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    ((Player*)target)->CastedCreatureOrGO(param1, m_creature->GetGUID(), param2);
            }
            break;
        case ACTION_T_SET_UNIT_FIELD:
            {
                Unit* target = GetTargetByType(param3, pActionInvoker);

                if (param1 < OBJECT_END || param1 >= UNIT_END)
                    return;

                if (target)
                    target->SetUInt32Value(param1, param2);
            }
            break;
        case ACTION_T_SET_UNIT_FLAG:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);

                if (target)
                    target->SetFlag(UNIT_FIELD_FLAGS, param1);
            }
            break;
        case ACTION_T_REMOVE_UNIT_FLAG:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);

                if (target)
                    target->RemoveFlag(UNIT_FIELD_FLAGS, param1);
            }
            break;
        case ACTION_T_AUTO_ATTACK:
            {
                if (param1)
                    MeleeEnabled = true;
                else MeleeEnabled = false;
            }
            break;
        case ACTION_T_COMBAT_MOVEMENT:
            {
                CombatMovementEnabled = param1;

                //Allow movement (create new targeted movement gen if none exist already)
                if (CombatMovementEnabled)
                {
                    m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim(), AttackDistance, AttackAngle);
                }
                else
                {
                    m_creature->GetMotionMaster()->MoveIdle();
                }
            }
            break;
        case ACTION_T_SET_PHASE:
            {
                Phase = param1;
            }
            break;
        case ACTION_T_INC_PHASE:
            {
                Phase += param1;

                if (Phase > 31)
                    if (EAI_ErrorLevel > 0)
                        error_db_log( "TSCR: Event %d incremented Phase above 31. Phase mask cannot be used with phases past 31. CreatureEntry = %d", EventId, m_creature->GetEntry());
            }
            break;
        case ACTION_T_EVADE:
            {
                EnterEvadeMode();
            }
            break;
        case ACTION_T_FLEE:
            {
                if(m_creature->HasAuraType(SPELL_AURA_PREVENTS_FLEEING))
                    break;
                TimetoFleeLeft = 8000;
                m_creature->DoFleeToGetAssistance();
                IsFleeing = true;
            }
            break;
        case ACTION_T_QUEST_EVENT_ALL:
            {
                Unit* Temp = NULL;
                if( pActionInvoker && pActionInvoker->GetTypeId() == TYPEID_PLAYER )
                {
                    Temp = Unit::GetUnit((*m_creature),pActionInvoker->GetGUID());
                    if( Temp )
                        ((Player*)Temp)->GroupEventHappens(param1,m_creature);
                }
            }
            break;
        case ACTION_T_CASTCREATUREGO_ALL:
            {
                Unit* Temp = NULL;

                std::list<HostilReference*>::iterator i = m_creature->getThreatManager().getThreatList().begin();
                for (; i != m_creature->getThreatManager().getThreatList().end(); ++i)
                {
                    Temp = Unit::GetUnit((*m_creature),(*i)->getUnitGuid());
                    if (Temp && Temp->GetTypeId() == TYPEID_PLAYER)
                        ((Player*)Temp)->CastedCreatureOrGO(param1, m_creature->GetGUID(), param2);
                }
            }
            break;
        case ACTION_T_REMOVEAURASFROMSPELL:
            {
                Unit* target = GetTargetByType(param1, pActionInvoker);

                if (target)
                    target->RemoveAurasDueToSpell(param2);
            }
            break;
        case ACTION_T_RANGED_MOVEMENT:
            {
                AttackDistance = param1;
                AttackAngle = ((float)param2/180)*M_PI;

                if (CombatMovementEnabled)
                {
                    m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim(), AttackDistance, AttackAngle);
                }
            }
            break;
        case ACTION_T_RANDOM_PHASE:
            {
                uint32 temp = GetRandActionParam(rnd, param1, param2, param3);

                Phase = temp;
            }
            break;
        case ACTION_T_RANDOM_PHASE_RANGE:
            {
                if (param2 > param1)
                {
                    Phase = param1 + (rnd % (param2 - param1));
                }
                else if (EAI_ErrorLevel > 0)
                    error_db_log( "TSCR: ACTION_T_RANDOM_PHASE_RANGE cannot have Param2 <= Param1. Divide by Zero. Event = %d. CreatureEntry = %d", EventId, m_creature->GetEntry());
            }
            break;
        case ACTION_T_SUMMON_ID:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);

                //Duration
                Creature* pCreature = NULL;

                UNORDERED_MAP<uint32, EventAI_Summon>::iterator i = EventAI_Summon_Map.find(param3);

                if (i == EventAI_Summon_Map.end())
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log( "TSCR: EventAI failed to spawn creature %u. Summon map index %u does not exist. EventID %d. CreatureID %d", param1, param3, EventId, m_creature->GetEntry());
                    return;
                }

                if ((*i).second.SpawnTimeSecs)
                    pCreature = m_creature->SummonCreature(param1, (*i).second.position_x, (*i).second.position_y, (*i).second.position_z, (*i).second.orientation, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, (*i).second.SpawnTimeSecs);
                else pCreature = m_creature->SummonCreature(param1, (*i).second.position_x, (*i).second.position_y, (*i).second.position_z, (*i).second.orientation, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0);

                if (!pCreature)
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log( "TSCR: EventAI failed to spawn creature %u. EventId %d.Creature %d", param1, EventId, m_creature->GetEntry());
                }
                else if (param2 != TARGET_T_SELF && target)
                pCreature->AI()->AttackStart(target);
            }
            break;
        case ACTION_T_KILLED_MONSTER:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);

                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    ((Player*)target)->KilledMonster(param1, m_creature->GetGUID());
            }
            break;
        case ACTION_T_SET_INST_DATA:
            {
                ScriptedInstance* pInst = (ScriptedInstance*)m_creature->GetInstanceData();
                if (!pInst)
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Event %d attempt to set instance data without instance script. Creature %d", EventId, m_creature->GetEntry());
                    return;
                }

                pInst->SetData(param1, param2);
            }
            break;
        case ACTION_T_SET_INST_DATA64:
            {
                Unit* target = GetTargetByType(param2, pActionInvoker);

                if (!target)
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Event %d attempt to set instance data64 but Target == NULL. Creature %d", EventId, m_creature->GetEntry());
                    return;
                }

                ScriptedInstance* pInst = (ScriptedInstance*)m_creature->GetInstanceData();

                if (!pInst)
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Event %d attempt to set instance data64 without instance script. Creature %d", EventId, m_creature->GetEntry());
                    return;
                }

                pInst->SetData64(param1, target->GetGUID());
            }
            break;
        case ACTION_T_UPDATE_TEMPLATE:
            {
                if (m_creature->GetEntry() == param1)
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Event %d ACTION_T_UPDATE_TEMPLATE call with param1 == current entry. Creature %d", EventId, m_creature->GetEntry());
                    return;
                }

                m_creature->UpdateEntry(param1, param2 ? HORDE : ALLIANCE);
            }
            break;
        case ACTION_T_DIE:
            {
                if (m_creature->isDead())
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Event %d ACTION_T_DIE on dead creature. Creature %d", EventId, m_creature->GetEntry());
                    return;
                }
                m_creature->DealDamage(m_creature, m_creature->GetMaxHealth(),NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
            break;
        case ACTION_T_ZONE_COMBAT_PULSE:
            {
                if (!m_creature->isInCombat() || !m_creature->GetMap()->IsDungeon())
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Event %d ACTION_T_ZONE_COMBAT_PULSE on creature out of combat or in non-dungeon map. Creature %d", EventId, m_creature->GetEntry());
                    return;
                }

                DoZoneInCombat();
            }
            break;
            case ACTION_T_SUMMON_GO:
            {
                GameObject* pObject = NULL;

                float x,y,z;
                m_creature->GetPosition(x,y,z);
                pObject = m_creature->SummonGameObject(param1, x, y, z, 0, 0, 0, 0, 0, param2);
                if (!pObject)
                {
                    if (EAI_ErrorLevel > 0)
                        error_db_log( "TSCR: EventAI failed to spawn object %u. Spawn event %d is on creature %d", param1, EventId, m_creature->GetEntry());
                }
            }
            break;

        // TRINITY ONLY
        case ACTION_T_SET_ACTIVE:
            m_creature->setActive(param1 ? true : false);
            break;
        case ACTION_T_SET_AGGRESSIVE:
            m_creature->SetReactState(ReactStates(param1));
            break;
        case ACTION_T_ATTACK_START_PULSE:
            AttackStart(m_creature->SelectNearestTarget((float)param1));
            break;
        }
    }

    void JustRespawned()
    {
        IsFleeing = false;
        Reset();

        //Handle Spawned Events
        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
            case EVENT_T_SPAWNED:
                ProcessEvent(*i);
                break;
            }
        }
    }

    void Reset()
    {
        EventUpdateTime = EVENT_UPDATE_TIME;
        EventDiff = 0;

        //Reset all events to enabled
        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
                //Reset all out of combat timers
                case EVENT_T_TIMER_OOC:
                    {
                        if ((*i).Event.event_param2 == (*i).Event.event_param1)
                        {
                            (*i).Time = (*i).Event.event_param1;
                            (*i).Enabled = true;
                        }else if ((*i).Event.event_param2 > (*i).Event.event_param1)
                        {
                            (*i).Time = urand((*i).Event.event_param1, (*i).Event.event_param2);
                            (*i).Enabled = true;
                        }else if (EAI_ErrorLevel > 0)
                            error_db_log("TSCR: Creature %u using Event %u (Type = %u) has InitialMax < InitialMin. Event disabled.", m_creature->GetEntry(), (*i).Event.event_id, (*i).Event.event_type);
                    }
                    break;
                //default:
                    //TODO: enable below code line / verify this is correct to enable events previously disabled (ex. aggro yell), instead of enable this in void Aggro()
                    //(*i).Enabled = true;
                    //(*i).Time = 0;
                    //break;
            }
        }
    }

    //when creature reach home after EnterEvadeMode
    void JustReachedHome()
    {
        m_creature->LoadCreaturesAddon();

        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            if ((*i).Event.event_type == EVENT_T_REACHED_HOME)
                ProcessEvent(*i);
        }

        Reset();
    }

    void EnterEvadeMode()
    {
        ScriptedAI::EnterEvadeMode();

        IsFleeing = false;

        //Handle Evade events
        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            if ((*i).Event.event_type == EVENT_T_EVADE)
                ProcessEvent(*i);
        }
    }

    void JustDied(Unit* killer)
    {
        IsFleeing = false;
        Reset();

        //Handle Evade events
        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
                //Evade
                case EVENT_T_DEATH:
                    ProcessEvent(*i, killer);
                    break;
            }
        }
    }

    void KilledUnit(Unit* victim)
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
                //Kill
                case EVENT_T_KILL:
                    ProcessEvent(*i, victim);
                    break;
            }
        }

    }

    void JustSummoned(Creature* pUnit)
    {
        if (!pUnit)
            return;

        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
                //Summoned
                case EVENT_T_SUMMONED_UNIT:
                    ProcessEvent(*i, pUnit);
                    break;
            }
        }
    }

    void Aggro(Unit *who)
    {
        //Check for on combat start events
        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
                case EVENT_T_AGGRO:
                    (*i).Enabled = true;
                    ProcessEvent(*i, who);
                    break;
                //Reset all in combat timers
                case EVENT_T_TIMER:
                    if ((*i).Event.event_param2 == (*i).Event.event_param1)
                    {
                        (*i).Time = (*i).Event.event_param1;
                        (*i).Enabled = true;
                    }else if ((*i).Event.event_param2 > (*i).Event.event_param1)
                    {
                        (*i).Time = urand((*i).Event.event_param1, (*i).Event.event_param2);
                        (*i).Enabled = true;
                    }else if (EAI_ErrorLevel > 0)
                        error_db_log("TSCR: Creature %u using Event %u (Type = %u) has InitialMax < InitialMin. Event disabled.", m_creature->GetEntry(), (*i).Event.event_id, (*i).Event.event_type);
                    break;
                //All normal events need to be re-enabled and their time set to 0
                default:
                    (*i).Enabled = true;
                    (*i).Time = 0;
                    break;
            }
        }

        EventUpdateTime = EVENT_UPDATE_TIME;
        EventDiff = 0;
    }

    void AttackStart(Unit *who)
    {
        if (!who)
            return;

        if (m_creature->Attack(who, MeleeEnabled))
         {
            //Begin melee attack if we are within range

            if (!m_creature->isInCombat())
            {
                Aggro(who);
            }

            if (CombatMovementEnabled)
            {
                m_creature->GetMotionMaster()->MoveChase(who, AttackDistance, AttackAngle);
            }
            else
            {
                m_creature->GetMotionMaster()->MoveIdle();
            }
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->isInCombat())
            return;

        //Check for OOC LOS Event
        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
            case EVENT_T_OOC_LOS:
                {
                    if ((*i).Event.event_param1 && m_creature->IsHostileTo(who))
                        break;

                    if ((*i).Event.event_param2 && !m_creature->IsHostileTo(who))
                        break;

                    ProcessEvent(*i, who);
                }
                break;
            }
        }

        // do we need this?
        //if (m_creature->isCivilian() && m_creature->IsNeutralToAll())
        //    return;

        if(m_creature->canStartAttack(who))
            AttackStart(who);
    }

    void SpellHit(Unit* pUnit, const SpellEntry* pSpell)
    {
        for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
        {
            switch ((*i).Event.event_type)
            {
                //Spell hit
                case EVENT_T_SPELLHIT:
                    {
                        //If spell id matches (or no spell id) & if spell school matches (or no spell school)
                        if (!(*i).Event.event_param1 || pSpell->Id == (*i).Event.event_param1)
                            if ((*i).Event.event_param2_s == -1 || pSpell->SchoolMask == (*i).Event.event_param2)
                                ProcessEvent(*i, pUnit);
                    }
                    break;
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Check if we are in combat (also updates calls threat update code)
        bool Combat = m_creature->isInCombat() ? UpdateVictim() : false;

        //Must return if creature isn't alive. Normally select hostil target and get victim prevent this
        if (!m_creature->isAlive())
            return;

        if (IsFleeing)
        {
            if(TimetoFleeLeft < diff)
            {
                m_creature->SetControlled(false, UNIT_STAT_FLEEING);
                m_creature->SetNoCallAssistance(false);
                m_creature->CallAssistance();
                if(m_creature->getVictim())
                    m_creature->GetMotionMaster()->MoveChase(m_creature->getVictim());
                IsFleeing = false;
            }
            else
                TimetoFleeLeft -= diff;

            return;
        }

        //Events are only updated once every EVENT_UPDATE_TIME ms to prevent lag with large amount of events
        if (EventUpdateTime < diff)
        {
            EventDiff += diff;

            //Check for range based events
            //if (m_creature->GetDistance(m_creature->getVictim()) >
            if (Combat)
            {
                for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
                {
                    switch ((*i).Event.event_type)
                    {
                        case EVENT_T_RANGE:
                            // in some cases this is called twice and victim may not exist in the second time
                            if(m_creature->getVictim())
                            {
                                float dist = m_creature->GetDistance(m_creature->getVictim());
                                if (dist > (*i).Event.event_param1 && dist < (*i).Event.event_param2)
                                    ProcessEvent(*i);
                            }
                            break;
                    }
                }
            }

            //Check for time based events
            for (std::list<EventHolder>::iterator i = EventList.begin(); i != EventList.end(); ++i)
            {
                //Decrement Timers
                if ((*i).Time)
                {
                    if ((*i).Time > EventDiff)
                    {
                        //Do not decrement timers if event cannot trigger in this phase
                        if (!((*i).Event.event_inverse_phase_mask & (1 << Phase)))
                            (*i).Time -= EventDiff;

                        //Skip processing of events that have time remaining
                        continue;
                    }
                    else (*i).Time = 0;
                }

                //Events that are updated every EVENT_UPDATE_TIME
                switch ((*i).Event.event_type)
                {
                    case EVENT_T_TIMER_OOC:
                        ProcessEvent(*i);
                        break;
                    case EVENT_T_TIMER:
                    case EVENT_T_MANA:
                    case EVENT_T_HP:
                    case EVENT_T_TARGET_HP:
                    case EVENT_T_TARGET_CASTING:
                    case EVENT_T_FRIENDLY_HP:
                        if (Combat)
                            ProcessEvent(*i);
                        break;
                    case EVENT_T_RANGE:
                        if (Combat)
                        {
                            if (m_creature->IsWithinDistInMap(m_creature->getVictim(),(float)(*i).Event.event_param2))
                            {
                                if (m_creature->GetDistance(m_creature->getVictim()) >= (float)(*i).Event.event_param1)
                                    ProcessEvent(*i);
                            }
                        }
                        break;
                }
            }

            EventDiff = 0;
            EventUpdateTime = EVENT_UPDATE_TIME;
        }
        else
        {
            EventDiff += diff;
            EventUpdateTime -= diff;
        }

        //Melee Auto-Attack
        if (Combat && MeleeEnabled)
            DoMeleeAttackIfReady();

    }
};

CreatureAI* GetAI_Mob_EventAI(Creature *pCreature)
{
    //Select events by creature id
    std::list<EventHolder> EventList;

    //Find creature id in the Event map
    UNORDERED_MAP<uint32, std::vector<EventAI_Event> >::iterator CreatureEvents = EventAI_Event_Map.find(pCreature->GetEntry());

    if (CreatureEvents != EventAI_Event_Map.end())
    {
        std::vector<EventAI_Event>::iterator i;

        for (i = (*CreatureEvents).second.begin(); i != (*CreatureEvents).second.end(); ++i)
        {
            //Debug check
#ifndef _DEBUG
            if ((*i).event_flags & EFLAG_DEBUG_ONLY)
                continue;
#endif
            if( pCreature->GetMap()->IsDungeon() )
            {
                if ((pCreature->GetMap()->IsHeroic() && (*i).event_flags & EFLAG_HEROIC) || (!pCreature->GetMap()->IsHeroic() && (*i).event_flags & EFLAG_NORMAL))
                    EventList.push_back(EventHolder(*i));
                continue;
            }

            EventList.push_back(EventHolder(*i));
        }

         //EventMap had events but they were not added because they must be for instance
         if (EventList.empty())
         {
             if (EAI_ErrorLevel > 1)
                 error_db_log("TSCR: CreatureId has events but no events added to list because of instance flags.", pCreature->GetEntry());
         }
      }
     else
      {
          if (EAI_ErrorLevel > 1)
             error_db_log("TSCR: EventMap for Creature %u is empty but creature is using Mob_EventAI.", pCreature->GetEntry());
      }

    return new Mob_EventAI (pCreature, EventList);
}

void AddSC_mob_event()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "mob_eventai";
    newscript->GetAI = &GetAI_Mob_EventAI;
    newscript->RegisterSelf();
}

