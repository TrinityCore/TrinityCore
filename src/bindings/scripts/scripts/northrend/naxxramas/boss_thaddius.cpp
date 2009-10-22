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
#include "naxxramas.h"

//Stalagg
#define SAY_STAL_AGGRO          -1533023 //not used
#define SAY_STAL_SLAY           -1533024 //not used
#define SAY_STAL_DEATH          -1533025 //not used

#define SPELL_POWERSURGE         54529
#define SPELL_POWERSURGE_H       28134

//Feugen
#define SAY_FEUG_AGGRO          -1533026 //not used
#define SAY_FEUG_SLAY           -1533027 //not used
#define SAY_FEUG_DEATH          -1533028 //not used

#define SPELL_STATICFIELD       28135
#define SPELL_STATICFIELD_H     54528

//generic
#define C_TESLA_COIL            16218           //the coils (emotes "Tesla Coil overloads!")

//Thaddus
#define SAY_GREET               -1533029 //not used
#define SAY_AGGRO               RAND(-1533030,-1533031,-1533032)
#define SAY_SLAY                -1533033
#define SAY_ELECT               -1533034 //not used
#define SAY_DEATH               -1533035
#define SAY_SCREAM1             -1533036 //not used
#define SAY_SCREAM2             -1533037 //not used
#define SAY_SCREAM3             -1533038 //not used
#define SAY_SCREAM4             -1533039 //not used

#define SPELL_POLARITY_SHIFT        28089
#define SPELL_BALL_LIGHTNING        28299
#define SPELL_CHAIN_LIGHTNING       HEROIC(28167,54531)
#define SPELL_BERSERK               27680

enum Events
{
    EVENT_SHIFT = 1,
    EVENT_CHAIN,
    EVENT_BERSERK,
};

bool CheckStalaggAlive = true;
bool CheckFeugenAlive = true;

struct TRINITY_DLL_DECL boss_thaddiusAI : public BossAI
{
    boss_thaddiusAI(Creature *c) : BossAI(c, BOSS_THADDIUS)
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
    }

    void KilledUnit(Unit* victim)
    {
        if (!(rand()%5))
            DoScriptText(SAY_SLAY, me);
    }

    void JustDied(Unit* Killer)
    {
        _JustDied();
        DoScriptText(SAY_DEATH, me);
    }

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        DoScriptText(SAY_AGGRO, me);
        events.ScheduleEvent(EVENT_SHIFT, 30000);
        events.ScheduleEvent(EVENT_CHAIN, 10000+rand()%10000);
        events.ScheduleEvent(EVENT_BERSERK, 6*60000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

       if (CheckStalaggAlive == false && CheckFeugenAlive == false)
           me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
        
       events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_SHIFT:
                    DoCastAOE(SPELL_POLARITY_SHIFT);
                    events.ScheduleEvent(EVENT_SHIFT, 30000);
                    return;
                case EVENT_CHAIN:
                    DoCast(me->getVictim(), SPELL_CHAIN_LIGHTNING);
                    events.ScheduleEvent(EVENT_CHAIN, 10000+rand()%10000);
                    return;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    return;
            }
        }

        if (events.GetTimer() > 15000 && !me->IsWithinMeleeRange(me->getVictim()))
            DoCast(me->getVictim(), SPELL_BALL_LIGHTNING);
        else
            DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_stalaggAI : public CombatAI
{
   mob_stalaggAI(Creature *c) : CombatAI(c)
   {
       m_pInstance = (ScriptedInstance*)c->GetInstanceData();
       m_bIsHeroicMode = c->GetMap()->IsHeroic();
       Reset();
   }

   ScriptedInstance* m_pInstance;
   bool m_bIsHeroicMode;
   uint32 PowerSurge_Timer;

   void reset()
   {
       PowerSurge_Timer = 20000+rand()%5000;
   }

   void JustDied(Unit *killer)
   {
       CheckStalaggAlive = false;
   }

   void UpdateAI(const uint32 uiDiff)
   {
       if (PowerSurge_Timer < uiDiff)
       {
           DoCast(m_creature, m_bIsHeroicMode ? SPELL_POWERSURGE_H : SPELL_POWERSURGE);
           PowerSurge_Timer = 15000+rand()%5000;
       }else PowerSurge_Timer -= uiDiff;
       DoMeleeAttackIfReady();
   }
};

struct TRINITY_DLL_DECL mob_feugenAI : public CombatAI
{
   mob_feugenAI(Creature *c) : CombatAI(c)
   {
       m_pInstance = (ScriptedInstance*)c->GetInstanceData();
       m_bIsHeroicMode = c->GetMap()->IsHeroic();
       Reset();
   }

   ScriptedInstance* m_pInstance;
   bool m_bIsHeroicMode;
   uint32 StaticField_Timer;
   uint32 Checktimer;

   void reset()
   {
       StaticField_Timer = 5000;
   }

   void JustDied(Unit *killer)
   {
       CheckFeugenAlive = false;
   }

   void UpdateAI(const uint32 uiDiff)
   {
       if (StaticField_Timer < uiDiff)
       {
           DoCast(m_creature, m_bIsHeroicMode ? SPELL_STATICFIELD_H : SPELL_STATICFIELD);
           StaticField_Timer = 5000;
       }else StaticField_Timer -= uiDiff;
       DoMeleeAttackIfReady();
   }
};

CreatureAI* GetAI_boss_thaddius(Creature* pCreature)
{
    return new boss_thaddiusAI (pCreature);
}

CreatureAI* GetAI_mob_stalagg(Creature* pCreature)
{
   return new mob_stalaggAI(pCreature);
}

CreatureAI* GetAI_mob_feugen(Creature* pCreature)
{
   return new mob_feugenAI(pCreature);
}

void AddSC_boss_thaddius()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_thaddius";
    newscript->GetAI = &GetAI_boss_thaddius;
    newscript->RegisterSelf();

   newscript = new Script;
   newscript->Name = "mob_stalagg";
   newscript->GetAI = &GetAI_mob_stalagg;
   newscript->RegisterSelf();

   newscript = new Script;
   newscript->Name = "mob_feugen";
   newscript->GetAI = &GetAI_mob_feugen;
   newscript->RegisterSelf();
}
