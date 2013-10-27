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
SDName: Boss_Bloodmage_Thalnos
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Yells
{
    SAY_AGGRO               = 0,
    SAY_HEALTH              = 1,
    SAY_KILL                = 2
};

enum Spells
{
    SPELL_FLAMESHOCK        = 8053,
    SPELL_SHADOWBOLT        = 1106,
    SPELL_FLAMESPIKE        = 8814,
    SPELL_FIRENOVA          = 16079,
};

class boss_bloodmage_thalnos : public CreatureScript
{
public:
    boss_bloodmage_thalnos() : CreatureScript("boss_bloodmage_thalnos") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_bloodmage_thalnosAI(creature);
    }

    struct boss_bloodmage_thalnosAI : public ScriptedAI
    {
        boss_bloodmage_thalnosAI(Creature* creature) : ScriptedAI(creature) { }

        bool HpYell;
        uint32 FlameShock_Timer;
        uint32 ShadowBolt_Timer;
        uint32 FlameSpike_Timer;
        uint32 FireNova_Timer;

        void Reset() OVERRIDE
        {
            HpYell = false;
            FlameShock_Timer = 10000;
            ShadowBolt_Timer = 2000;
            FlameSpike_Timer = 8000;
            FireNova_Timer = 40000;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*Victim*/) OVERRIDE
        {
            Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            //If we are <35% hp
            if (!HpYell && !HealthAbovePct(35))
            {
                Talk(SAY_HEALTH);
                HpYell = true;
            }

            //FlameShock_Timer
            if (FlameShock_Timer <= diff)
            {
                DoCastVictim(SPELL_FLAMESHOCK);
                FlameShock_Timer = urand(10000, 15000);
            }
            else FlameShock_Timer -= diff;

            //FlameSpike_Timer
            if (FlameSpike_Timer <= diff)
            {
                DoCastVictim(SPELL_FLAMESPIKE);
                FlameSpike_Timer = 30000;
            }
            else FlameSpike_Timer -= diff;

            //FireNova_Timer
            if (FireNova_Timer <= diff)
            {
                DoCastVictim(SPELL_FIRENOVA);
                FireNova_Timer = 40000;
            }
            else FireNova_Timer -= diff;

            //ShadowBolt_Timer
            if (ShadowBolt_Timer <= diff)
            {
                DoCastVictim(SPELL_SHADOWBOLT);
                ShadowBolt_Timer = 2000;
            }
            else ShadowBolt_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_bloodmage_thalnos()
{
    new boss_bloodmage_thalnos();
}
