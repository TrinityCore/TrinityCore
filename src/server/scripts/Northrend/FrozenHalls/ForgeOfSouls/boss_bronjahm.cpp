/* Copyright (C) 2008 - 2010 TrinityCore <https://www.trinitycore.org/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ScriptPCH.h"
#include "forge_of_souls.h"

/*
 * TODO:
 * - Fix Soul Storm spell and remove work around.
 */

enum Yells
{
    SAY_AGGRO                                     = -1632001,
    SAY_SLAY_1                                    = -1632002,
    SAY_SLAY_2                                    = -1632003,
    SAY_DEATH                                     = -1632004,
    SAY_SOUL_STORM                                = -1632005,
    SAY_CORRUPT_SOUL                              = -1632006,
};

enum Spells
{
    SPELL_MAGIC_S_BANE                            = 68793,
    SPELL_CORRUPT_SOUL                            = 68839,
    SPELL_CONSUME_SOUL                            = 68858,
    SPELL_TELEPORT                                = 68988,
    SPELL_FEAR                                    = 68950,
    SPELL_SOULSTORM                               = 68872,
    SPELL_SOULSTORM_AURA                          = 68921,
    SPELL_SHADOW_BOLT                             = 70043,
};

enum Events
{
    EVENT_NONE,
    EVENT_SHADOW_BOLT,
    EVENT_MAGIC_BANE,
    EVENT_CORRUPT_SOUL,
    EVENT_SOUL_STORM,
    EVENT_SOUL_STORM_AURA,
    EVENT_FEAR,
};

enum CombatPhases
{
    PHASE_1,
    PHASE_2
};

struct boss_bronjahmAI : public ScriptedAI
{
    boss_bronjahmAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = me->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    EventMap events;

    CombatPhases phase;

    void Reset()
    {
        phase = PHASE_1;
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

        events.Reset();
        events.ScheduleEvent(EVENT_SHADOW_BOLT, 2000);
        events.ScheduleEvent(EVENT_MAGIC_BANE, urand(8000,15000));
        events.ScheduleEvent(EVENT_CORRUPT_SOUL, urand(25000,35000));

        if (pInstance)
            pInstance->SetData(DATA_BRONJAHM_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);

        if (pInstance)
            pInstance->SetData(DATA_BRONJAHM_EVENT, IN_PROGRESS);
    }

    void JustDied(Unit* /*killer*/)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
            pInstance->SetData(DATA_BRONJAHM_EVENT, DONE);
    }

    void KilledUnit(Unit * /*who*/)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
    }

    // Cast aura spell on all players farther than 10y
    void ApplySoulStorm()
    {
        std::list<Unit*> targetList;

        SelectTargetList(targetList, 100, SELECT_TARGET_TOPAGGRO, -10.0f);
        if (targetList.empty())
            return;

        for (std::list<Unit *>::const_iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
        {
            Unit* pUnit = (*itr);
            if (pUnit && pUnit->isAlive())
                me->CastSpell(pUnit, SPELL_SOULSTORM_AURA, true);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        if (phase == PHASE_1 && HealthBelowPct(30))
        {
            phase = PHASE_2;
            DoCast(me,SPELL_TELEPORT);
            me->GetMotionMaster()->Clear();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            events.CancelEvent(EVENT_CORRUPT_SOUL);
            events.ScheduleEvent(EVENT_SOUL_STORM, 1000);
            events.ScheduleEvent(EVENT_FEAR, urand(8000,12000));
            return;
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_CORRUPT_SOUL:
                    if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                    {
                        DoScriptText(SAY_CORRUPT_SOUL, me);
                        DoCast(pTarget,SPELL_CORRUPT_SOUL);
                    }
                    events.ScheduleEvent(EVENT_CORRUPT_SOUL, urand(25000,35000));
                    break;
                case EVENT_SOUL_STORM:
                    DoScriptText(SAY_SOUL_STORM, me);
                    // DoCast(me, SPELL_SOULSTORM); bug: put the aura without the limit of 10 yards.
                    events.ScheduleEvent(EVENT_SOUL_STORM_AURA, 1000);
                    break;
                case EVENT_SOUL_STORM_AURA:
                    ApplySoulStorm();
                    events.ScheduleEvent(EVENT_SOUL_STORM_AURA, 1000);
                    break;
                case EVENT_FEAR:
                    if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                        DoCast(pTarget,SPELL_FEAR);
                    events.ScheduleEvent(EVENT_FEAR, urand(8000,12000));
                    break;
                case EVENT_SHADOW_BOLT:
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, 2000);
                    break;
                case EVENT_MAGIC_BANE:
                    DoCastVictim(SPELL_MAGIC_S_BANE);
                    events.ScheduleEvent(EVENT_MAGIC_BANE, urand(8000,15000));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_bronjahm(Creature* pCreature)
{
    return new boss_bronjahmAI(pCreature);
}

struct mob_corrupted_soul_fragmentAI : public ScriptedAI
{
    mob_corrupted_soul_fragmentAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = me->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 uiCheckTimer;

    void Reset()
    {
        uiCheckTimer = 0; // first check is immediate
    }

    void UpdateAI(const uint32 diff)
    {
        if (uiCheckTimer <= diff)
        {
            if (pInstance)
            {
                Creature* pBronjham = Unit::GetCreature(*me, pInstance->GetData64(DATA_BRONJAHM));
                if (pBronjham && pBronjham->isAlive())
                {
                    if (me->IsWithinMeleeRange(pBronjham))
                    {
                        pBronjham->CastSpell(pBronjham, SPELL_CONSUME_SOUL, true);
                        me->ForcedDespawn();
                    }
                    else
                    {
                        Position pos;
                        pBronjham->GetPosition(&pos);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MovePoint(0, pos);
                    }
                }
                else
                    me->ForcedDespawn();
            }
            uiCheckTimer = 500;
        }
        else
            uiCheckTimer -= diff;
    }
};

CreatureAI* GetAI_mob_corrupted_soul_fragment(Creature* pCreature)
{
    return new mob_corrupted_soul_fragmentAI(pCreature);
}

void AddSC_boss_bronjahm()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_bronjahm";
    newscript->GetAI = &GetAI_boss_bronjahm;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_corrupted_soul_fragment";
    newscript->GetAI = &GetAI_mob_corrupted_soul_fragment;
    newscript->RegisterSelf();
}
