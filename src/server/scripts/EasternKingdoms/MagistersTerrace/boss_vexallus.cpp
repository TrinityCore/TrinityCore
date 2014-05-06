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
SDName: Boss_Vexallus
SD%Complete: 90
SDComment: Heroic and Normal support. Needs further testing.
SDCategory: Magister's Terrace
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "magisters_terrace.h"

enum Yells
{
    SAY_AGGRO                       = 0,
    SAY_ENERGY                      = 1,
    SAY_OVERLOAD                    = 2,
    SAY_KILL                        = 3,
    EMOTE_DISCHARGE_ENERGY          = 4

    //is this text for real?
    //#define SAY_DEATH             "What...happen...ed."
};

enum Spells
{
    // Pure energy spell info
    SPELL_ENERGY_BOLT               = 46156,
    SPELL_ENERGY_FEEDBACK           = 44335,

    // Vexallus spell info
    SPELL_CHAIN_LIGHTNING           = 44318,
    SPELL_H_CHAIN_LIGHTNING         = 46380, // heroic spell
    SPELL_OVERLOAD                  = 44353,
    SPELL_ARCANE_SHOCK              = 44319,
    SPELL_H_ARCANE_SHOCK            = 46381, // heroic spell

    SPELL_SUMMON_PURE_ENERGY        = 44322, // mod scale -10
    H_SPELL_SUMMON_PURE_ENERGY1     = 46154, // mod scale -5
    H_SPELL_SUMMON_PURE_ENERGY2     = 46159  // mod scale -5

};

enum Creatures
{
    NPC_PURE_ENERGY                 = 24745,
};

enum Misc
{
    INTERVAL_MODIFIER               = 15,
    INTERVAL_SWITCH                 = 6
};

class boss_vexallus : public CreatureScript
{
public:
    boss_vexallus() : CreatureScript("boss_vexallus") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_vexallusAI>(creature);
    };

    struct boss_vexallusAI : public BossAI
    {
        boss_vexallusAI(Creature* creature) : BossAI(creature, DATA_VEXALLUS_EVENT)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 ChainLightningTimer;
        uint32 ArcaneShockTimer;
        uint32 OverloadTimer;
        uint32 IntervalHealthAmount;
        bool Enraged;

        void Reset() override
        {
            summons.DespawnAll();
            ChainLightningTimer = 8000;
            ArcaneShockTimer = 5000;
            OverloadTimer = 1200;
            IntervalHealthAmount = 1;
            Enraged = false;

            instance->SetData(DATA_VEXALLUS_EVENT, NOT_STARTED);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            summons.DespawnAll();
            instance->SetData(DATA_VEXALLUS_EVENT, DONE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            instance->SetData(DATA_VEXALLUS_EVENT, IN_PROGRESS);
        }

        void JustSummoned(Creature* summoned) override
        {
            if (Unit* temp = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->GetMotionMaster()->MoveFollow(temp, 0, 0);

            //spells are SUMMON_TYPE_GUARDIAN, so using setOwner should be ok
            summoned->CastSpell(summoned, SPELL_ENERGY_BOLT, false, 0, 0, me->GetGUID());
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!Enraged)
            {
                //used for check, when Vexallus cast adds 85%, 70%, 55%, 40%, 25%
                if (!HealthAbovePct(100 - INTERVAL_MODIFIER * IntervalHealthAmount))
                {
                    //increase amount, unless we're at 10%, then we switch and return
                    if (IntervalHealthAmount == INTERVAL_SWITCH)
                    {
                        Enraged = true;
                        return;
                    }
                    else
                        ++IntervalHealthAmount;

                    Talk(SAY_ENERGY);
                    Talk(EMOTE_DISCHARGE_ENERGY);

                    if (IsHeroic())
                    {
                        DoCast(me, H_SPELL_SUMMON_PURE_ENERGY1, false);
                        DoCast(me, H_SPELL_SUMMON_PURE_ENERGY2, false);
                    }
                    else
                        DoCast(me, SPELL_SUMMON_PURE_ENERGY, false);

                    //below are workaround summons, remove when summoning spells w/implicitTarget 73 implemented in the core
                    me->SummonCreature(NPC_PURE_ENERGY, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);

                    if (IsHeroic())
                        me->SummonCreature(NPC_PURE_ENERGY, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
                }

                if (ChainLightningTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);

                    ChainLightningTimer = 8000;
                } else ChainLightningTimer -= diff;

                if (ArcaneShockTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    if (target)
                        DoCast(target, SPELL_ARCANE_SHOCK);

                    ArcaneShockTimer = 8000;
                } else ArcaneShockTimer -= diff;
            }
            else
            {
                if (OverloadTimer <= diff)
                {
                    DoCastVictim(SPELL_OVERLOAD);

                    OverloadTimer = 2000;
                } else OverloadTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

class npc_pure_energy : public CreatureScript
{
public:
    npc_pure_energy() : CreatureScript("npc_pure_energy") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_pure_energyAI(creature);
    };

    struct npc_pure_energyAI : public ScriptedAI
    {
        npc_pure_energyAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
        }

        void Reset() override { }

        void JustDied(Unit* slayer) override
        {
            if (Unit* temp = me->GetOwner())
            {
                if (temp && temp->IsAlive())
                    slayer->CastSpell(slayer, SPELL_ENERGY_FEEDBACK, true, 0, 0, temp->GetGUID());
            }
        }

        void EnterCombat(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }

        void AttackStart(Unit* /*who*/) override { }
    };
};

void AddSC_boss_vexallus()
{
    new boss_vexallus();
    new npc_pure_energy();
}
