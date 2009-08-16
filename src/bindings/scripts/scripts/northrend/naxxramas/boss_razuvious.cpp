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
#include "def_naxxramas.h"

//Razuvious - NO TEXT sound only
//8852 aggro01 - Hah hah, I'm just getting warmed up!
//8853 aggro02 Stand and fight!
//8854 aggro03 Show me what you've got!
//8861 slay1 - You should've stayed home!
//8863 slay2-
//8858 cmmnd3 - You disappoint me, students!
//8855 cmmnd1 - Do as I taught you!
//8856 cmmnd2 - Show them no mercy!
//8859 cmmnd4 - The time for practice is over! Show me what you've learned!
//8861 Sweep the leg! Do you have a problem with that?
//8860 death - An honorable... death...
//8947 - Aggro Mixed? - ?

#define SOUND_AGGRO     RAND(8852,8853,8854)
#define SOUND_SLAY      RAND(8861,8863)
#define SOUND_COMMND    RAND(8855,8856,8858,8859,8861)
#define SOUND_DEATH     8860
#define SOUND_AGGROMIX  8847

#define SPELL_UNBALANCING_STRIKE    26613
#define SPELL_DISRUPTING_SHOUT      HEROIC(29107,55543)
#define SPELL_JAGGED_KNIFE          55550
#define SPELL_HOPELESS              29125

enum Events
{
    EVENT_STRIKE,
    EVENT_SHOUT,
    EVENT_KNIFE,
    EVENT_COMMAND,
};

struct TRINITY_DLL_DECL boss_razuviousAI : public BossAI
{
    boss_razuviousAI(Creature *c) : BossAI(c, BOSS_RAZUVIOUS) {}

    void KilledUnit(Unit* victim)
    {
        if (!(rand()%3))
            DoPlaySoundToSet(me, SOUND_SLAY);
    }

    void JustDied(Unit* killer)
    {
        _JustDied();
        DoPlaySoundToSet(me, SOUND_DEATH);
        me->CastSpell(me, SPELL_HOPELESS, true); // TODO: this may affect other creatures
    }

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
        events.ScheduleEvent(EVENT_STRIKE, 30000);
        events.ScheduleEvent(EVENT_SHOUT, 25000);
        events.ScheduleEvent(EVENT_COMMAND, 40000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_STRIKE:
                    DoCast(me->getVictim(), SPELL_UNBALANCING_STRIKE);
                    events.ScheduleEvent(EVENT_STRIKE, 30000);
                    return;
                case EVENT_SHOUT:
                    DoCastAOE(SPELL_DISRUPTING_SHOUT);
                    events.ScheduleEvent(EVENT_SHOUT, 25000);
                    return;
                case EVENT_KNIFE:
                    if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45))
                        DoCast(target, SPELL_JAGGED_KNIFE);
                    events.ScheduleEvent(EVENT_KNIFE, 25000);
                    return;
                case EVENT_COMMAND:
                    DoPlaySoundToSet(me, SOUND_COMMND);
                    events.ScheduleEvent(EVENT_COMMAND, 40000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_razuvious(Creature* pCreature)
{
    return new boss_razuviousAI (pCreature);
}

void AddSC_boss_razuvious()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_razuvious";
    newscript->GetAI = &GetAI_boss_razuvious;
    newscript->RegisterSelf();
}
