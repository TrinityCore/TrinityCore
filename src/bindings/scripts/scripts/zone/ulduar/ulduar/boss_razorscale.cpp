/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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

#include "precompiled.h"
#include "def_ulduar.h"

#define SPELL_FLAME_BUFFET      HEROIC(64016,64023)
#define SPELL_WING_BUFFET       62666
#define SPELL_FUSE_ARMOR        64821
#define SPELL_FLAME_BREATH      HEROIC(63317,64021)
#define SPELL_DEVOURING_FLAME   HEROIC(63014,63816)
#define SPELL_BERSERK           47008

enum Events
{
    EVENT_BUFFET = 1,
    EVENT_WING,
    EVENT_FUSE,
    EVENT_BREATH,
    EVENT_DEVOUR,
    EVENT_BERSERK,
};

struct TRINITY_DLL_DECL boss_razorscaleAI : public BossAI
{
    boss_razorscaleAI(Creature *c) : BossAI(c, BOSS_RAZORSCALE) {}

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_BERSERK, 7*60000);
        events.ScheduleEvent(EVENT_BUFFET, 10000+rand()%5000);
        events.ScheduleEvent(EVENT_WING, 30000+rand()%30000);
        events.ScheduleEvent(EVENT_FUSE, 10000);
        events.ScheduleEvent(EVENT_BREATH, 15000);
        events.ScheduleEvent(EVENT_DEVOUR, 10000);
    }

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        events.Update(diff);

        if(me->hasUnitState(UNIT_STAT_CASTING))
            return;

        if(uint32 eventId = events.GetEvent())
        {
            switch(eventId)
            {
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    return;
                case EVENT_BUFFET:
                    DoCastAOE(SPELL_FLAME_BUFFET);
                    events.RepeatEvent(10000+rand()%5000);
                    return;
                case EVENT_WING:
                    DoCastAOE(SPELL_WING_BUFFET);
                    events.RepeatEvent(30000+rand()%30000);
                    return;
                case EVENT_BREATH:
                    DoCastAOE(SPELL_FLAME_BREATH);
                    events.RepeatEvent(15000);
                    return;
                case EVENT_FUSE:
                    DoCast(me->getVictim(), SPELL_FUSE_ARMOR);
                    events.RepeatEvent(10000);
                    return;
                case EVENT_DEVOUR:
                    if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_DEVOURING_FLAME);
                    events.RepeatEvent(10000);
                    return;
                default:
                    events.PopEvent();
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_razorscale(Creature *_Creature)
{
    return new boss_razorscaleAI (_Creature);
}

void AddSC_boss_razorscale()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_razorscale";
    newscript->GetAI = &GetAI_boss_razorscale;
    newscript->RegisterSelf();
}
