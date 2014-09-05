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
SDName: Boss_Interrogator_Vishas
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scarlet_monastery.h"

enum Says
{
    SAY_AGGRO               = 0,
    SAY_HEALTH1             = 1,
    SAY_HEALTH2             = 2,
    SAY_KILL                = 3,
    SAY_TRIGGER_VORREL      = 0
};

enum Spells
{
    SPELL_SHADOWWORDPAIN    = 2767
};

class boss_interrogator_vishas : public CreatureScript
{
public:
    boss_interrogator_vishas() : CreatureScript("boss_interrogator_vishas") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_interrogator_vishasAI>(creature);
    }

    struct boss_interrogator_vishasAI : public ScriptedAI
    {
        boss_interrogator_vishasAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = me->GetInstanceScript();
        }

        void Initialize()
        {
            ShadowWordPain_Timer = 5000;
            Yell60 = false;
            Yell30 = false;
        }

        InstanceScript* instance;

        bool Yell30;
        bool Yell60;
        uint32 ShadowWordPain_Timer;

        void Reset() override
        {
            Initialize();
            instance->SetBossState(DATA_INTERROGATOR_VISHAS, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            instance->SetBossState(DATA_INTERROGATOR_VISHAS, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*Victim*/) override
        {
            Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            //Any other Actions to do with vorrel? setStandState?
            if (Creature* vorrel = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_VORREL)))
                vorrel->AI()->Talk(SAY_TRIGGER_VORREL);
            instance->SetBossState(DATA_INTERROGATOR_VISHAS, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            //If we are low on hp Do sayings
            if (!Yell60 && !HealthAbovePct(60))
            {
                Talk(SAY_HEALTH1);
                Yell60 = true;
            }

            if (!Yell30 && !HealthAbovePct(30))
            {
                Talk(SAY_HEALTH2);
                Yell30 = true;
            }

            //ShadowWordPain_Timer
            if (ShadowWordPain_Timer <= diff)
            {
                DoCastVictim(SPELL_SHADOWWORDPAIN);
                ShadowWordPain_Timer = urand(5000, 15000);
            }
            else ShadowWordPain_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_interrogator_vishas()
{
    new boss_interrogator_vishas();
}
