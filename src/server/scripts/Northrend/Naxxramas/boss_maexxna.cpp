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
    SPELL_WEB_WRAP              = 28622,
    SPELL_WEB_SPRAY_10          = 29484,
    SPELL_WEB_SPRAY_25          = 54125,
    SPELL_POISON_SHOCK_10       = 28741,
    SPELL_POISON_SHOCK_25       = 54122,
    SPELL_NECROTIC_POISON_10    = 28776,
    SPELL_NECROTIC_POISON_25    = 54121,
    SPELL_FRENZY_10             = 54123,
    SPELL_FRENZY_25             = 54124,
};

enum Creatures
{
    MOB_WEB_WRAP                = 16486,
    MOB_SPIDERLING              = 17055,
};

#define MAX_POS_WRAP            3
const Position PosWrap[MAX_POS_WRAP] =
{
    {3546.796, -3869.082, 296.450, 0.0},
    {3531.271, -3847.424, 299.450, 0.0},
    {3497.067, -3843.384, 302.384, 0.0},
};

enum Events
{
    EVENT_NONE,
    EVENT_SPRAY,
    EVENT_SHOCK,
    EVENT_POISON,
    EVENT_WRAP,
    EVENT_SUMMON,
    EVENT_FRENZY,
};

struct boss_maexxnaAI : public BossAI
{
    boss_maexxnaAI(Creature *c) : BossAI(c, BOSS_MAEXXNA) {}

    bool enraged;

    void EnterCombat(Unit * /*who*/)
    {
        _EnterCombat();
        enraged = false;
        events.ScheduleEvent(EVENT_WRAP, 20000);
        events.ScheduleEvent(EVENT_SPRAY, 40000);
        events.ScheduleEvent(EVENT_SHOCK, urand(5000,10000));
        events.ScheduleEvent(EVENT_POISON, urand(10000,15000));
        events.ScheduleEvent(EVENT_SUMMON, 30000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() || !CheckInRoom())
            return;

        if (!enraged && HealthBelowPct(30))
        {
            enraged = true;
            events.ScheduleEvent(EVENT_FRENZY, 0); // will be cast immediately
        }

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_WRAP:
                    // TODO : Add missing text
                    for (uint8 i = 0; i < RAID_MODE(1,2); ++i)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 0, true, -SPELL_WEB_WRAP))
                        {
                            pTarget->RemoveAura(RAID_MODE(SPELL_WEB_SPRAY_10,SPELL_WEB_SPRAY_25));
                            uint8 pos = rand()%MAX_POS_WRAP;
                            pTarget->GetMotionMaster()->MoveJump(PosWrap[pos].GetPositionX(), PosWrap[pos].GetPositionY(), PosWrap[pos].GetPositionZ(), 20, 20);
                            if (Creature *wrap = DoSummon(MOB_WEB_WRAP, PosWrap[pos], 0, TEMPSUMMON_CORPSE_DESPAWN))
                                wrap->AI()->SetGUID(pTarget->GetGUID());
                        }
                    }
                    events.ScheduleEvent(EVENT_WRAP, 40000);
                    break;
                case EVENT_SPRAY:
                    DoCastAOE(RAID_MODE(SPELL_WEB_SPRAY_10,SPELL_WEB_SPRAY_25));
                    events.ScheduleEvent(EVENT_SPRAY, 40000);
                    break;
                case EVENT_SHOCK:
                    DoCastAOE(RAID_MODE(SPELL_POISON_SHOCK_10,SPELL_POISON_SHOCK_25));
                    events.ScheduleEvent(EVENT_SHOCK, urand(10000,20000));
                    break;
                case EVENT_POISON:
                    DoCast(me->getVictim(), RAID_MODE(SPELL_NECROTIC_POISON_10,SPELL_NECROTIC_POISON_25));
                    events.ScheduleEvent(EVENT_POISON, urand(10000, 20000));
                    break;
                case EVENT_FRENZY:
                    DoCast(me, RAID_MODE(SPELL_FRENZY_10,SPELL_FRENZY_25), true);
                    events.ScheduleEvent(EVENT_FRENZY, 600000);
                    break;
                case EVENT_SUMMON:
                    // TODO : Add missing text
                    uint8 amount = urand(8,10);
                    for (uint8 i = 0; i < amount; ++i)
                        DoSummon(MOB_SPIDERLING, me, 0, TEMPSUMMON_CORPSE_DESPAWN);
                    events.ScheduleEvent(EVENT_SUMMON, 40000);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct mob_webwrapAI : public NullCreatureAI
{
    mob_webwrapAI(Creature *c) : NullCreatureAI(c), victimGUID(0) {}

    uint64 victimGUID;

    void SetGUID(const uint64 &guid, int32 /*param*/)
    {
        victimGUID = guid;
        if (me->m_spells[0] && victimGUID)
            if (Unit *victim = Unit::GetUnit(*me, victimGUID))
                victim->CastSpell(victim, me->m_spells[0], true, NULL, NULL, me->GetGUID());
    }

    void JustDied(Unit * /*killer*/)
    {
        if (me->m_spells[0] && victimGUID)
            if (Unit *victim = Unit::GetUnit(*me, victimGUID))
                victim->RemoveAurasDueToSpell(me->m_spells[0], me->GetGUID());
    }
};

CreatureAI* GetAI_boss_maexxna(Creature* pCreature)
{
    return new boss_maexxnaAI (pCreature);
}

CreatureAI* GetAI_mob_webwrap(Creature* pCreature)
{
    return new mob_webwrapAI (pCreature);
}

void AddSC_boss_maexxna()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_maexxna";
    newscript->GetAI = &GetAI_boss_maexxna;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_webwrap";
    newscript->GetAI = &GetAI_mob_webwrap;
    newscript->RegisterSelf();

}

