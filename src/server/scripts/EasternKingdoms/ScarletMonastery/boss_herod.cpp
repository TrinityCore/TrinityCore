/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Boss_Herod
SD%Complete: 95
SDComment: Should in addition spawn Myrmidons in the hallway outside
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_WHIRLWIND               = 1,
    SAY_ENRAGE                  = 2,
    SAY_KILL                    = 3,
    EMOTE_ENRAGE                = 4
};

enum Spells
{
    SPELL_RUSHINGCHARGE         = 8260,
    SPELL_CLEAVE                = 15496,
    SPELL_WHIRLWIND             = 8989,
    SPELL_FRENZY                = 8269
};

enum Entry
{
    ENTRY_SCARLET_TRAINEE       = 6575,
    ENTRY_SCARLET_MYRMIDON      = 4295
};

class boss_herod : public CreatureScript
{
public:
    boss_herod() : CreatureScript("boss_herod") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_herodAI(creature);
    }

    struct boss_herodAI : public ScriptedAI
    {
        boss_herodAI(Creature* creature) : ScriptedAI(creature) {}

        bool Enrage;

        uint32 Cleave_Timer;
        uint32 Whirlwind_Timer;

        void Reset()
        {
            Enrage = false;
            Cleave_Timer = 12000;
            Whirlwind_Timer = 60000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            DoCast(me, SPELL_RUSHINGCHARGE);
        }

         void KilledUnit(Unit* /*victim*/)
         {
             Talk(SAY_KILL);
         }

         void JustDied(Unit* /*killer*/)
         {
             for (uint8 i = 0; i < 20; ++i)
                 me->SummonCreature(ENTRY_SCARLET_TRAINEE, 1939.18f, -431.58f, 17.09f, 6.22f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
         }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //If we are <30% hp goes Enraged
            if (!Enrage && !HealthAbovePct(30) && !me->IsNonMeleeSpellCasted(false))
            {
                Talk(EMOTE_ENRAGE);
                Talk(SAY_ENRAGE);
                DoCast(me, SPELL_FRENZY);
                Enrage = true;
            }

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCastVictim(SPELL_CLEAVE);
                Cleave_Timer = 12000;
            }
            else Cleave_Timer -= diff;

            // Whirlwind_Timer
            if (Whirlwind_Timer <= diff)
            {
                Talk(SAY_WHIRLWIND);
                DoCastVictim(SPELL_WHIRLWIND);
                Whirlwind_Timer = 30000;
            }
            else Whirlwind_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_scarlet_trainee : public CreatureScript
{
public:
    npc_scarlet_trainee() : CreatureScript("npc_scarlet_trainee") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_scarlet_traineeAI(creature);
    }

    struct npc_scarlet_traineeAI : public npc_escortAI
    {
        npc_scarlet_traineeAI(Creature* creature) : npc_escortAI(creature)
        {
            Start_Timer = urand(1000, 6000);
        }

        uint32 Start_Timer;

        void Reset() {}
        void WaypointReached(uint32 /*waypointId*/) {}
        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(uint32 diff)
        {
            if (Start_Timer)
            {
                if (Start_Timer <= diff)
                {
                    Start(true, true);
                    Start_Timer = 0;
                } else Start_Timer -= diff;
            }

            npc_escortAI::UpdateAI(diff);
        }
    };
};

void AddSC_boss_herod()
{
    new boss_herod();
    new npc_scarlet_trainee();
}
