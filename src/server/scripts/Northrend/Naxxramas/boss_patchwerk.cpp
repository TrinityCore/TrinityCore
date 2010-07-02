/*
 * Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
 *
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
#include "naxxramas.h"

enum Spells
{
    SPELL_HATEFUL_STRIKE                        = 41926,
    H_SPELL_HATEFUL_STRIKE                      = 59192,
    SPELL_FRENZY                                = 28131,
    SPELL_BERSERK                               = 26662,
    SPELL_SLIME_BOLT                            = 32309,
};

enum Yells
{
    SAY_AGGRO_1                                 = -1533017,
    SAY_AGGRO_2                                 = -1533018,
    SAY_SLAY                                    = -1533019,
    SAY_DEATH                                   = -1533020,
    EMOTE_BERSERK                               = -1533021,
    EMOTE_ENRAGE                                = -1533022,
};

enum Events
{
    EVENT_NONE,
    EVENT_BERSERK,
    EVENT_HATEFUL,
    EVENT_SLIME
};

enum
{
    ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT  = 10286,
};

struct boss_patchwerkAI : public BossAI
{
    boss_patchwerkAI(Creature *c) : BossAI(c, BOSS_PATCHWERK) {}

    bool Enraged;

    void Reset()
    {
        _Reset();

        if (instance)
            instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
    }

    void KilledUnit(Unit* /*Victim*/)
    {
        if (!(rand()%5))
            DoScriptText(SAY_SLAY, me);
    }

    void JustDied(Unit* /*Killer*/)
    {
        _JustDied();
        DoScriptText(SAY_DEATH, me);
    }

    void EnterCombat(Unit * /*who*/)
    {
        _EnterCombat();
        Enraged = false;
        DoScriptText(RAND(SAY_AGGRO_1,SAY_AGGRO_2), me);
        events.ScheduleEvent(EVENT_HATEFUL, 1200);
        events.ScheduleEvent(EVENT_BERSERK, 360000);

        if (instance)
            instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_HATEFUL:
                {
                    //Cast Hateful strike on the player with the highest
                    //amount of HP within melee distance
                    uint32 MostHP = 0;
                    Unit* pMostHPTarget = NULL;
                    std::list<HostileReference*>::const_iterator i = me->getThreatManager().getThreatList().begin();
                    for (; i != me->getThreatManager().getThreatList().end(); ++i)
                    {
                        Unit *pTarget = (*i)->getTarget();
                        if (pTarget->isAlive() && pTarget->GetHealth() > MostHP && me->IsWithinMeleeRange(pTarget))
                        {
                            MostHP = pTarget->GetHealth();
                            pMostHPTarget = pTarget;
                        }
                    }

                    if (pMostHPTarget)
                        DoCast(pMostHPTarget, RAID_MODE(SPELL_HATEFUL_STRIKE,H_SPELL_HATEFUL_STRIKE), true);

                    events.ScheduleEvent(EVENT_HATEFUL, 1200);
                    break;
                }
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK, true);
                    DoScriptText(EMOTE_BERSERK, me);
                    events.ScheduleEvent(EVENT_SLIME, 2000);
                    break;
                case EVENT_SLIME:
                    DoCast(me->getVictim(), SPELL_SLIME_BOLT);
                    events.ScheduleEvent(EVENT_SLIME, 2000);
                    break;
            }
        }

        if (!Enraged && HealthBelowPct(5))
        {
            DoCast(me, SPELL_FRENZY, true);
            DoScriptText(EMOTE_ENRAGE, me);
            Enraged = true;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_patchwerk(Creature* pCreature)
{
    return new boss_patchwerkAI (pCreature);
}

void AddSC_boss_patchwerk()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_patchwerk";
    newscript->GetAI = &GetAI_boss_patchwerk;
    newscript->RegisterSelf();
}
