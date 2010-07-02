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
#include "halls_of_reflection.h"

enum Yells
{
    SAY_AGGRO                                     = -1668050,
    SAY_SLAY_1                                    = -1668051,
    SAY_SLAY_2                                    = -1668052,
    SAY_DEATH                                     = -1668053,
    SAY_IMPENDING_DESPAIR                         = -1668054,
    SAY_DEFILING_HORROR                           = -1668055,
};

enum Spells
{
    SPELL_QUIVERING_STRIKE                        = 72422,
    SPELL_IMPENDING_DESPAIR                       = 72426,
    SPELL_DEFILING_HORROR                         = 72435,
    SPELL_HOPELESSNESS                            = 72395, 
    H_SPELL_HOPELESSNESS                          = 72390, // TODO: not in dbc. Add in DB.
};

enum Events
{
    EVENT_NONE,
    EVENT_QUIVERING_STRIKE,
    EVENT_IMPENDING_DESPAIR,
    EVENT_DEFILING_HORROR,
};

struct boss_falricAI : public boss_horAI
{
    boss_falricAI(Creature *pCreature) : boss_horAI(pCreature) {}

    uint8 uiHopelessnessCount;

    void Reset()
    {
        boss_horAI::Reset();

        uiHopelessnessCount = 0;

        if (pInstance)
            pInstance->SetData(DATA_FALRIC_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, me);
        if (pInstance)
            pInstance->SetData(DATA_FALRIC_EVENT, IN_PROGRESS);

        events.ScheduleEvent(EVENT_QUIVERING_STRIKE, 23000);
        events.ScheduleEvent(EVENT_IMPENDING_DESPAIR, 9000);
        events.ScheduleEvent(EVENT_DEFILING_HORROR, urand(25000,45000)); // TODO adjust timer.
    }

    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, me);

        if (pInstance)
            pInstance->SetData(DATA_FALRIC_EVENT, DONE);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
    }

    void UpdateAI(const uint32 diff)
    {
        // Return since we have no target
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
            case EVENT_QUIVERING_STRIKE:
                DoCast(SPELL_QUIVERING_STRIKE);
                events.ScheduleEvent(EVENT_QUIVERING_STRIKE, 10000);
                break;
            case EVENT_IMPENDING_DESPAIR:
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    DoScriptText(SAY_IMPENDING_DESPAIR, me);
                    DoCast(pTarget, SPELL_IMPENDING_DESPAIR);
                }
                events.ScheduleEvent(EVENT_IMPENDING_DESPAIR, 13000);
                break;
            case EVENT_DEFILING_HORROR:
                DoCast(SPELL_DEFILING_HORROR);
                events.ScheduleEvent(EVENT_DEFILING_HORROR, urand(25000,45000)); // TODO adjust timer.
                break;
        }

        if ((uiHopelessnessCount < 1 && HealthBelowPct(66))
            || (uiHopelessnessCount < 2 && HealthBelowPct(33))
            || (uiHopelessnessCount < 3 && HealthBelowPct(10)))
        {
            uiHopelessnessCount++;
            DoCast(DUNGEON_MODE(SPELL_HOPELESSNESS,H_SPELL_HOPELESSNESS));
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_falric(Creature* pCreature)
{
    return new boss_falricAI(pCreature);
}

void AddSC_boss_falric()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_falric";
    newscript->GetAI = &GetAI_boss_falric;
    newscript->RegisterSelf();
}
