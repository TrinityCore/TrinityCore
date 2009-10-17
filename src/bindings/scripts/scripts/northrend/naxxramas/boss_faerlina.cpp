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
#define SAY_GREET       -1533009
#define SAY_AGGRO       RAND(-1533010,-1533011,-1533012,-1533013)
#define SAY_SLAY        RAND(-1533014,-1533015)
#define SAY_DEATH       -1533016
//#define SOUND_RANDOM_AGGRO  8955                            //soundId containing the 4 aggro sounds, we not using this
#define SPELL_POSION_BOLT_VOLLEY    HEROIC(28796,54098)
#define SPELL_RAIN_OF_FIRE          HEROIC(28794,54099)
#define SPELL_FRENZY                HEROIC(28798,54100)
#define SPELL_WIDOWS_EMBRACE        HEROIC(28732,54097)
enum Events
{
    EVENT_POSION = 1,
    EVENT_FIRE,
    EVENT_FRENZY,
};
struct TRINITY_DLL_DECL boss_faerlinaAI : public BossAI
{
    boss_faerlinaAI(Creature *c) : BossAI(c, BOSS_FAERLINA), greet(false) {}
    bool greet;
    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        DoScriptText(SAY_AGGRO, me);
        events.ScheduleEvent(EVENT_POSION, 10000 + rand()%15000);
        events.ScheduleEvent(EVENT_FIRE, 5000 + rand()%15000);
        events.ScheduleEvent(EVENT_FRENZY, 60000 + rand()%20000);
    }
    void MoveInLineOfSight(Unit *who)
    {
        if (!greet)
        {
            DoScriptText(SAY_GREET, me);
            greet = true;
        }
        BossAI::MoveInLineOfSight(who);
    }
    void KilledUnit(Unit* victim)
    {
        if (!(rand()%3))
            DoScriptText(SAY_SLAY, me);
    }
    void JustDied(Unit* Killer)
    {
        _JustDied();
        DoScriptText(SAY_DEATH, me);
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
                case EVENT_POSION:
                    if (!me->HasAura(SPELL_WIDOWS_EMBRACE))
                        DoCastAOE(SPELL_POSION_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_POSION, 10000 + rand()%15000);
                    return;
                case EVENT_FIRE:
                    if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_RAIN_OF_FIRE);
                    events.ScheduleEvent(EVENT_FIRE, 5000 + rand()%15000);
                    return;
                case EVENT_FRENZY:
                    DoCast(me,SPELL_FRENZY);
                    events.ScheduleEvent(EVENT_FRENZY, 60000 + rand()%20000);
                    return;
            }
        }
        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_faerlina(Creature* pCreature)
{
    return new boss_faerlinaAI (pCreature);
}
void AddSC_boss_faerlina()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_faerlina";
    newscript->GetAI = &GetAI_boss_faerlina;
    newscript->RegisterSelf();
}
