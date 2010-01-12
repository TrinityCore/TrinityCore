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
enum StalaggYells
{
    SAY_STAL_AGGRO          = -1533023, //not used
    SAY_STAL_SLAY           = -1533024, //not used
    SAY_STAL_DEATH          = -1533025 //not used
};

enum StalagSpells
{
    SPELL_POWERSURGE        = 54529,
    H_SPELL_POWERSURGE      = 28134
};

//Feugen
enum FeugenYells
{
    SAY_FEUG_AGGRO          = -1533026, //not used
    SAY_FEUG_SLAY           = -1533027, //not used
    SAY_FEUG_DEATH          = -1533028 //not used
};

enum FeugenSpells
{
      SPELL_STATICFIELD     = 28135,
      H_SPELL_STATICFIELD   = 54528
};

//generic
#define C_TESLA_COIL            16218           //the coils (emotes "Tesla Coil overloads!")

//Thaddius
enum ThaddiusYells
{
    SAY_GREET               = -1533029, //not used
    SAY_AGGRO_1             = -1533030,
    SAY_AGGRO_2             = -1533031,
    SAY_AGGRO_3             = -1533032,
    SAY_SLAY                = -1533033,
    SAY_ELECT               = -1533034, //not used
    SAY_DEATH               = -1533035,
    SAY_SCREAM1             = -1533036, //not used
    SAY_SCREAM2             = -1533037, //not used
    SAY_SCREAM3             = -1533038, //not used
    SAY_SCREAM4             = -1533039 //not used
};

enum ThaddiusSpells
{
    SPELL_POLARITY_SHIFT        = 28089,
    SPELL_BALL_LIGHTNING        = 28299,
    SPELL_CHAIN_LIGHTNING       = 28167,
    H_SPELL_CHAIN_LIGHTNING     = 54531,
    SPELL_BERSERK               = 27680
};

enum Events
{
    EVENT_NONE,
    EVENT_SHIFT,
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
        me->SetReactState(REACT_PASSIVE);
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
        DoScriptText(RAND(SAY_AGGRO_1,SAY_AGGRO_2,SAY_AGGRO_3), me);
        events.ScheduleEvent(EVENT_SHIFT, 30000);
        events.ScheduleEvent(EVENT_CHAIN, urand(10000,20000));
        events.ScheduleEvent(EVENT_BERSERK, 360000);
    }

    void UpdateAI(const uint32 diff)
    {
       if (CheckStalaggAlive == false && CheckFeugenAlive == false) {
           me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
           me->SetReactState(REACT_AGGRESSIVE);
       }

       if (!UpdateVictim())
           return;
        
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
                    DoCast(me->getVictim(), RAID_MODE(SPELL_CHAIN_LIGHTNING, H_SPELL_CHAIN_LIGHTNING));
                    events.ScheduleEvent(EVENT_CHAIN, urand(10000,20000));
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

CreatureAI* GetAI_boss_thaddius(Creature* pCreature)
{
    return new boss_thaddiusAI (pCreature);
}

struct TRINITY_DLL_DECL mob_stalaggAI : public ScriptedAI
{
   mob_stalaggAI(Creature *c) : ScriptedAI(c) {}

   uint32 PowerSurgeTimer;

   void reset()
   {
       PowerSurgeTimer = urand(20000,25000);
   }

   void JustDied(Unit *killer)
   {
       CheckStalaggAlive = false;
   }

   void UpdateAI(const uint32 uiDiff)
   {
       if (PowerSurgeTimer <= uiDiff)
       {
           DoCast(m_creature, RAID_MODE(SPELL_POWERSURGE, H_SPELL_POWERSURGE));
           PowerSurgeTimer = urand(15000,20000);
       } else PowerSurgeTimer -= uiDiff;
       DoMeleeAttackIfReady();
   }
};

CreatureAI* GetAI_mob_stalagg(Creature* pCreature)
{
    return new mob_stalaggAI(pCreature);
}

struct TRINITY_DLL_DECL mob_feugenAI : public ScriptedAI
{
   mob_feugenAI(Creature *c) : ScriptedAI(c) {}

   uint32 StaticFieldTimer;
   uint32 Checktimer;

   void reset()
   {
       StaticFieldTimer = 5000;
   }

   void JustDied(Unit *killer)
   {
       CheckFeugenAlive = false;
   }

   void UpdateAI(const uint32 uiDiff)
   {
       if (StaticFieldTimer <= uiDiff)
       {
           DoCast(m_creature, RAID_MODE(SPELL_STATICFIELD, H_SPELL_STATICFIELD));
           StaticFieldTimer = 5000;
       } else StaticFieldTimer -= uiDiff;
       DoMeleeAttackIfReady();
   }
};

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
