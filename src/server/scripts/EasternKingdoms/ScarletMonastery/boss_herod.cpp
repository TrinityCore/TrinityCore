/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "scarlet_monastery.h"

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

enum Npcs
{
    NPC_SCARLET_TRAINEE         = 6575,
    NPC_SCARLET_MYRMIDON        = 4295
};

enum Events
{
    EVENT_CLEAVE                = 1,
    EVENT_WHIRLWIND
};

Position const ScarletTraineePos = { 1939.18f, -431.58f, 17.09f, 6.22f };

class boss_herod : public CreatureScript
{
    public:
        boss_herod() : CreatureScript("boss_herod") { }

        struct boss_herodAI : public BossAI
        {
            boss_herodAI(Creature* creature) : BossAI(creature, DATA_HEROD)
            {
                _enrage = false;
            }

            void Reset() override
            {
                _enrage = false;
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                DoCast(me, SPELL_RUSHINGCHARGE);
                _EnterCombat();

                events.ScheduleEvent(EVENT_CLEAVE, 12000);
                events.ScheduleEvent(EVENT_WHIRLWIND, 60000);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                for (uint8 i = 0; i < 20; ++i)
                    me->SummonCreature(NPC_SCARLET_TRAINEE, ScarletTraineePos, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
            }

            void DamageTaken(Unit* /*done_by*/, uint32& /*damage*/) override
            {
                if (HealthBelowPct(30) && !_enrage)
                {
                    Talk(EMOTE_ENRAGE);
                    Talk(SAY_ENRAGE);
                    DoCast(me, SPELL_FRENZY);
                    _enrage = true;
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 12000);
                        break;
                    case EVENT_WHIRLWIND:
                        Talk(SAY_WHIRLWIND);
                        DoCastVictim(SPELL_WHIRLWIND);
                        events.ScheduleEvent(EVENT_WHIRLWIND, 30000);
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                BossAI::UpdateAI(diff);
            }
            
            private:
                bool _enrage;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_herodAI>(creature);
        }
};

class npc_scarlet_trainee : public CreatureScript
{
public:
    npc_scarlet_trainee() : CreatureScript("npc_scarlet_trainee") { }

    CreatureAI* GetAI(Creature* creature) const override
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

        void Reset() override { }
        void WaypointReached(uint32 /*waypointId*/) override { }
        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
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
