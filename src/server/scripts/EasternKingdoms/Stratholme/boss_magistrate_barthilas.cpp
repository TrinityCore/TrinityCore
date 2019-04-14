/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
SDName: Boss_Magistrate_Barthilas
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_DRAININGBLOW      = 16793,
    SPELL_CROWDPUMMEL       = 10887,
    SPELL_MIGHTYBLOW        = 14099,
    SPELL_FURIOUS_ANGER     = 16791
};

enum Models
{
    MODEL_NORMAL            = 10433,
    MODEL_HUMAN             = 3637
};

class boss_magistrate_barthilas : public CreatureScript
{
public:
    boss_magistrate_barthilas() : CreatureScript("boss_magistrate_barthilas") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStratholmeAI<boss_magistrate_barthilasAI>(creature);
    }

    struct boss_magistrate_barthilasAI : public ScriptedAI
    {
        boss_magistrate_barthilasAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            DrainingBlow_Timer = 20000;
            CrowdPummel_Timer = 15000;
            MightyBlow_Timer = 10000;
            FuriousAnger_Timer = 5000;
            AngerCount = 0;
        }

        uint32 DrainingBlow_Timer;
        uint32 CrowdPummel_Timer;
        uint32 MightyBlow_Timer;
        uint32 FuriousAnger_Timer;
        uint32 AngerCount;

        void Reset() override
        {
            Initialize();

            if (me->IsAlive())
                me->SetDisplayId(MODEL_NORMAL);
            else
                me->SetDisplayId(MODEL_HUMAN);
        }

        void MoveInLineOfSight(Unit* who) override

        {
            //nothing to see here yet

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->SetDisplayId(MODEL_HUMAN);
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (FuriousAnger_Timer <= diff)
            {
                FuriousAnger_Timer = 4000;
                if (AngerCount > 25)
                    return;

                ++AngerCount;
                DoCast(me, SPELL_FURIOUS_ANGER, false);
            } else FuriousAnger_Timer -= diff;

            //DrainingBlow
            if (DrainingBlow_Timer <= diff)
            {
                DoCastVictim(SPELL_DRAININGBLOW);
                DrainingBlow_Timer = 15000;
            } else DrainingBlow_Timer -= diff;

            //CrowdPummel
            if (CrowdPummel_Timer <= diff)
            {
                DoCastVictim(SPELL_CROWDPUMMEL);
                CrowdPummel_Timer = 15000;
            } else CrowdPummel_Timer -= diff;

            //MightyBlow
            if (MightyBlow_Timer <= diff)
            {
                DoCastVictim(SPELL_MIGHTYBLOW);
                MightyBlow_Timer = 20000;
            } else MightyBlow_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_magistrate_barthilas()
{
    new boss_magistrate_barthilas();
}
