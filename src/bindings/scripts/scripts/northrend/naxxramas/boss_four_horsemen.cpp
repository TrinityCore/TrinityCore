/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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

enum Horsemen
{
    HORSEMEN_THANE,
    HORSEMEN_LADY,
    HORSEMEN_BARON,
    HORSEMEN_SIR,
};

enum Events
{
    EVENT_MARK = 1,
    EVENT_CAST,
    EVENT_BERSERK,
};

const uint32 MOB_HORSEMEN[]     =   {16064, 16065, 30549, 16063};
const uint32 SPELL_MARK[]       =   {28832, 28833, 28834, 28835};
#define SPELL_PRIMARY(i)            HEROIC(SPELL_PRIMARY_N[i],SPELL_PRIMARY_H[i])
const uint32 SPELL_PRIMARY_N[]  =   {28884, 28863, 28882, 28883};
const uint32 SPELL_PRIMARY_H[]  =   {57467, 57463, 57369, 57466};
#define SPELL_SECONDARY(i)          HEROIC(SPELL_SECONDARY_N[i],SPELL_SECONDARY_H[i])
const uint32 SPELL_SECONDARY_N[]=   {0, 57374, 0, 57376};
const uint32 SPELL_SECONDARY_H[]=   {0, 57464, 0, 57465};
const uint32 SPELL_PUNISH[]     =   {0, 57381, 0, 57377};
#define SPELL_BERSERK               26662

// used by 16063,16064,16065,30549, but signed for 16063
const int32 SAY_AGGRO[]     =   {-1533051, -1533044, -1533065, -1533058};
const int32 SAY_TAUNT[3][4] ={  {-1533052, -1533045, -1533071, -1533059},
                                {-1533053, -1533046, -1533072, -1533060},
                                {-1533054, -1533047, -1533073, -1533061},};
const int32 SAY_SPECIAL[]   =   {-1533055, -1533048, -1533070, -1533062};
const int32 SAY_SLAY[]      =   {-1533056, -1533049, -1533068, -1533063};
const int32 SAY_DEATH[]     =   {-1533057, -1533050, -1533074, -1533064};

#define SAY_BARON_AGGRO     RAND(-1533065,-1533066,-1533067)
#define SAY_BARON_SLAY      RAND(-1533068,-1533069)

struct TRINITY_DLL_DECL boss_four_horsemenAI : public BossAI
{
    boss_four_horsemenAI(Creature *c) : BossAI(c, BOSS_HORSEMEN)
    {
        id = Horsemen(0);
        for(uint8 i = 1; i < 4; ++i)
            if (me->GetEntry() == MOB_HORSEMEN[i])
                id = Horsemen(i);
        caster = (id == HORSEMEN_LADY || id == HORSEMEN_SIR);
    }

    Horsemen id;
    bool caster;

    void MoveInLineOfSight(Unit *who)
    {
        BossAI::MoveInLineOfSight(who);
        if (caster)
            SelectNearestTarget(who);
    }

    void AttackStart(Unit *who)
    {
        if (caster)
            AttackStartCaster(who, 20);
        else
            BossAI::AttackStart(who);
    }

    void KilledUnit(Unit* victim)
    {
        if (!(rand()%5))
        {
            if (id == HORSEMEN_BARON)
                DoScriptText(SAY_BARON_SLAY, me);
            else
                DoScriptText(SAY_SLAY[id], me);
        }
    }

    void JustDied(Unit* killer)
    {
        _JustDied();
        DoScriptText(SAY_DEATH[id], me);
    }

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        if (id == HORSEMEN_BARON)
            DoScriptText(SAY_BARON_AGGRO, me);
        else
            DoScriptText(SAY_AGGRO[id], me);
            events.ScheduleEvent(EVENT_MARK, 15000);
            events.ScheduleEvent(EVENT_CAST, 20000+rand()%5000);
            events.ScheduleEvent(EVENT_BERSERK, 15*100*1000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim() || !CheckInRoom())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_MARK:
                    if (!(rand()%5))
                        DoScriptText(SAY_SPECIAL[id], me);
                    DoCastAOE(SPELL_MARK[id]);
                    events.ScheduleEvent(EVENT_MARK, 15000);
                    return;
                case EVENT_CAST:
                    if (!(rand()%5))
                        DoScriptText(SAY_TAUNT[rand()%3][id], me);
                    DoCast(SPELL_PRIMARY(id));
                    events.ScheduleEvent(EVENT_CAST, 15000);
                    return;
                case EVENT_BERSERK:
                    DoScriptText(SAY_SPECIAL[id], me);
                    DoCast(me, EVENT_BERSERK);
                    return;
            }
        }

        if (!caster)
            DoMeleeAttackIfReady();
        else if (!DoSpellAttackIfReady(SPELL_SECONDARY(id)))
            DoCastAOE(SPELL_PUNISH[id]);
    }
};

CreatureAI* GetAI_four_horsemen(Creature* pCreature)
{
    return new boss_four_horsemenAI (pCreature);
}

void AddSC_boss_four_horsemen()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_four_horsemen";
    newscript->GetAI = &GetAI_four_horsemen;
    newscript->RegisterSelf();
}
