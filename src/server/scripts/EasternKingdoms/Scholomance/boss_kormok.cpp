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
SDName: Boss_Kormok
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_SHADOWBOLTVOLLEY      = 20741,
    SPELL_BONESHIELD            = 27688
};

class boss_kormok : public CreatureScript
{
public:
    boss_kormok() : CreatureScript("boss_kormok") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_kormokAI(creature);
    }

    struct boss_kormokAI : public ScriptedAI
    {
        boss_kormokAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 ShadowVolley_Timer;
        uint32 BoneShield_Timer;
        uint32 Minion_Timer;
        uint32 Mage_Timer;
        bool Mages;

        void Reset() OVERRIDE
        {
            ShadowVolley_Timer = 10000;
            BoneShield_Timer = 2000;
            Minion_Timer = 15000;
            Mage_Timer = 0;
            Mages = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
        }

        void SummonMinions(Unit* victim)
        {
            if (Creature* SummonedMinion = DoSpawnCreature(16119, float(irand(-7, 7)), float(irand(-7, 7)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000))
                SummonedMinion->AI()->AttackStart(victim);
        }

        void SummonMages(Unit* victim)
        {
            if (Creature* SummonedMage = DoSpawnCreature(16120, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000))
                SummonedMage->AI()->AttackStart(victim);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            //ShadowVolley_Timer
            if (ShadowVolley_Timer <= diff)
            {
                DoCastVictim(SPELL_SHADOWBOLTVOLLEY);
                ShadowVolley_Timer = 15000;
            } else ShadowVolley_Timer -= diff;

            //BoneShield_Timer
            if (BoneShield_Timer <= diff)
            {
                DoCastVictim(SPELL_BONESHIELD);
                BoneShield_Timer = 45000;
            } else BoneShield_Timer -= diff;

            //Minion_Timer
            if (Minion_Timer <= diff)
            {
                //Cast
                SummonMinions(me->GetVictim());
                SummonMinions(me->GetVictim());
                SummonMinions(me->GetVictim());
                SummonMinions(me->GetVictim());

                Minion_Timer = 12000;
            } else Minion_Timer -= diff;

            //Summon 2 Bone Mages
            if (!Mages && HealthBelowPct(26))
            {
                //Cast
                SummonMages(me->GetVictim());
                SummonMages(me->GetVictim());
                Mages = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_kormok()
{
    new boss_kormok();
}
