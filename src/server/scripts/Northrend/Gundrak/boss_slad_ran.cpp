/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "gundrak.h"
#include "Player.h"

enum Spells
{
    SPELL_POISON_NOVA                             = 55081,
    H_SPELL_POISON_NOVA                           = 59842,
    SPELL_POWERFULL_BITE                          = 48287,
    H_SPELL_POWERFULL_BITE                        = 59840,
    SPELL_VENOM_BOLT                              = 54970,
    H_SPELL_VENOM_BOLT                            = 59839
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_SUMMON_SNAKES                             = 3,
    SAY_SUMMON_CONSTRICTORS                       = 4,
    EMOTE_NOVA                                    = 5
};

enum Creatures
{
    CREATURE_SNAKE                                = 29680,
    CREATURE_CONSTRICTORS                         = 29713
};

enum ConstrictorSpells
{
    SPELL_GRIP_OF_SLAD_RAN                        = 55093,
    SPELL_SNAKE_WRAP                              = 55126,
    SPELL_VENOMOUS_BITE                           = 54987,
    H_SPELL_VENOMOUS_BITE                         = 58996
};

static Position SpawnLoc[]=
{
  {1783.81f, 646.637f, 133.948f, 3.71755f},
  {1775.03f, 606.586f, 134.165f, 1.43117f},
  {1717.39f, 630.041f, 129.282f, 5.96903f},
  {1765.66f, 646.542f, 134.02f,  5.11381f},
  {1716.76f, 635.159f, 129.282f, 0.191986f}
};

enum Misc
{
    DATA_SNAKES_WHYD_IT_HAVE_TO_BE_SNAKES       = 1
};

class boss_slad_ran : public CreatureScript
{
public:
    boss_slad_ran() : CreatureScript("boss_slad_ran") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_slad_ranAI (creature);
    }

    struct boss_slad_ranAI : public ScriptedAI
    {
        boss_slad_ranAI(Creature* creature) : ScriptedAI(creature), lSummons(me)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiPoisonNovaTimer;
        uint32 uiPowerfullBiteTimer;
        uint32 uiVenomBoltTimer;
        uint32 uiSpawnTimer;

        uint8 uiPhase;

        std::set<uint64> lWrappedPlayers;
        SummonList lSummons;

        InstanceScript* instance;

        void Reset()
        {
            uiPoisonNovaTimer = 10*IN_MILLISECONDS;
            uiPowerfullBiteTimer = 3*IN_MILLISECONDS;
            uiVenomBoltTimer = 15*IN_MILLISECONDS;
            uiSpawnTimer = 5*IN_MILLISECONDS;
            uiPhase = 0;
            lWrappedPlayers.clear();

            lSummons.DespawnAll();

            if (instance)
                instance->SetData(DATA_SLAD_RAN_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(DATA_SLAD_RAN_EVENT, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiPoisonNovaTimer <= diff)
            {
                DoCastVictim(SPELL_POISON_NOVA);
                Talk(EMOTE_NOVA);
                uiPoisonNovaTimer = 15*IN_MILLISECONDS;
            } else uiPoisonNovaTimer -= diff;

            if (uiPowerfullBiteTimer <= diff)
            {
                DoCastVictim(SPELL_POWERFULL_BITE);
                uiPowerfullBiteTimer = 10*IN_MILLISECONDS;
            } else uiPowerfullBiteTimer -= diff;

            if (uiVenomBoltTimer <= diff)
            {
                DoCastVictim(SPELL_VENOM_BOLT);
                uiVenomBoltTimer = 10*IN_MILLISECONDS;
            } else uiVenomBoltTimer -= diff;

            if (uiPhase)
            {
                if (uiSpawnTimer <= diff)
                {
                    if (uiPhase == 1)
                        for (uint8 i = 0; i < DUNGEON_MODE(3, 5); ++i)
                            me->SummonCreature(CREATURE_SNAKE, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20*IN_MILLISECONDS);
                    if (uiPhase == 2)
                        for (uint8 i = 0; i < DUNGEON_MODE(3, 5); ++i)
                            me->SummonCreature(CREATURE_CONSTRICTORS, SpawnLoc[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20*IN_MILLISECONDS);
                    uiSpawnTimer = 5*IN_MILLISECONDS;
                } else uiSpawnTimer -= diff;
            }

            if (uiPhase == 0 && HealthBelowPct(30))
            {
                Talk(SAY_SUMMON_SNAKES);
                uiPhase = 1;
            }

            if (uiPhase == 1 && HealthBelowPct(25))
            {
                Talk(SAY_SUMMON_CONSTRICTORS);
                uiPhase = 2;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            lSummons.DespawnAll();

            if (instance)
                instance->SetData(DATA_SLAD_RAN_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            lSummons.Summon(summoned);
        }

        void SetGUID(uint64 guid, int32 type)
        {
            if (type == DATA_SNAKES_WHYD_IT_HAVE_TO_BE_SNAKES)
                lWrappedPlayers.insert(guid);
        }

        bool WasWrapped(uint64 guid)
        {
            return lWrappedPlayers.count(guid);
        }
    };

};

class npc_slad_ran_constrictor : public CreatureScript
{
public:
    npc_slad_ran_constrictor() : CreatureScript("npc_slad_ran_constrictor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_slad_ran_constrictorAI (creature);
    }

    struct npc_slad_ran_constrictorAI : public ScriptedAI
    {
        npc_slad_ran_constrictorAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 uiGripOfSladRanTimer;

        void Reset()
        {
            uiGripOfSladRanTimer = 1*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiGripOfSladRanTimer <= diff)
            {
                Unit* target = me->GetVictim();

                DoCast(target, SPELL_GRIP_OF_SLAD_RAN);
                uiGripOfSladRanTimer = urand(3, 6)*IN_MILLISECONDS;

                Aura* grip = target->GetAura(SPELL_GRIP_OF_SLAD_RAN, me->GetGUID());
                if (grip && grip->GetStackAmount() == 5)
                {
                    target->RemoveAurasDueToSpell(SPELL_GRIP_OF_SLAD_RAN, me->GetGUID());
                    target->CastSpell(target, SPELL_SNAKE_WRAP, true);

                    if (TempSummon* _me = me->ToTempSummon())
                        if (Creature* sladran = _me->GetSummoner()->ToCreature())
                            sladran->AI()->SetGUID(target->GetGUID(), DATA_SNAKES_WHYD_IT_HAVE_TO_BE_SNAKES);

                    me->DespawnOrUnsummon();
                }
            } else uiGripOfSladRanTimer -= diff;
        }

        InstanceScript* instance;
    };

};

class npc_slad_ran_viper : public CreatureScript
{
public:
    npc_slad_ran_viper() : CreatureScript("npc_slad_ran_viper") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_slad_ran_viperAI (creature);
    }

    struct npc_slad_ran_viperAI : public ScriptedAI
    {
        npc_slad_ran_viperAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 uiVenomousBiteTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiVenomousBiteTimer = 2*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiVenomousBiteTimer <= diff)
            {
                DoCastVictim(SPELL_VENOMOUS_BITE);
                uiVenomousBiteTimer = 10*IN_MILLISECONDS;
            } else uiVenomousBiteTimer -= diff;
        }
    };

};

class achievement_snakes_whyd_it_have_to_be_snakes : public AchievementCriteriaScript
{
    public:
        achievement_snakes_whyd_it_have_to_be_snakes() : AchievementCriteriaScript("achievement_snakes_whyd_it_have_to_be_snakes")
        {
        }

        bool OnCheck(Player* player, Unit* target)
        {
            if (!target)
                return false;

            if (boss_slad_ran::boss_slad_ranAI* sladRanAI = CAST_AI(boss_slad_ran::boss_slad_ranAI, target->GetAI()))
                return !sladRanAI->WasWrapped(player->GetGUID());
            return false;
        }
};

void AddSC_boss_slad_ran()
{
    new boss_slad_ran();
    new npc_slad_ran_constrictor();
    new npc_slad_ran_viper();
    new achievement_snakes_whyd_it_have_to_be_snakes();
}
