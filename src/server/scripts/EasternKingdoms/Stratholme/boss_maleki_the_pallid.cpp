/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: boss_maleki_the_pallid
SD%Complete: 100
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_FROSTBOLT     = 17503,
    SPELL_DRAINLIFE     = 20743,
    SPELL_DRAIN_MANA    = 17243,
    SPELL_ICETOMB       = 16869

};

class boss_maleki_the_pallid : public CreatureScript
{
public:
    boss_maleki_the_pallid() : CreatureScript("boss_maleki_the_pallid") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_maleki_the_pallidAI>(creature);
    }

    struct boss_maleki_the_pallidAI : public ScriptedAI
    {
        boss_maleki_the_pallidAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = me->GetInstanceScript();
        }

        void Initialize()
        {
            Frostbolt_Timer = 1000;
            IceTomb_Timer = 16000;
            DrainLife_Timer = 31000;
        }

        InstanceScript* instance;

        uint32 Frostbolt_Timer;
        uint32 IceTomb_Timer;
        uint32 DrainLife_Timer;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(TYPE_PALLID, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Frostbolt
            if (Frostbolt_Timer <= diff)
            {
                if (rand32() % 100 < 90)
                    DoCastVictim(SPELL_FROSTBOLT);
                Frostbolt_Timer = 3500;
            } else Frostbolt_Timer -= diff;

            //IceTomb
            if (IceTomb_Timer <= diff)
            {
                if (rand32() % 100 < 65)
                    DoCastVictim(SPELL_ICETOMB);
                IceTomb_Timer = 28000;
            } else IceTomb_Timer -= diff;

            //DrainLife
            if (DrainLife_Timer <= diff)
            {
                if (rand32() % 100 < 55)
                    DoCastVictim(SPELL_DRAINLIFE);
                DrainLife_Timer = 31000;
            } else DrainLife_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_maleki_the_pallid()
{
    new boss_maleki_the_pallid();
}
