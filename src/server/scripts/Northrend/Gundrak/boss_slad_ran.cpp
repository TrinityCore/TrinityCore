/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "gundrak.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_POISON_NOVA                             = 55081,
    SPELL_POWERFULL_BITE                          = 48287,
    SPELL_VENOM_BOLT                              = 54970,
    SPELL_SUMMON_SNAKES                           = 55060, // NYI
    SPELL_SUMMON_CONSTRICTORS                     = 54969  // NYI
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_SUMMON_SNAKES                             = 3,
    SAY_SUMMON_CONSTRICTORS                       = 4,
    EMOTE_NOVA                                    = 5,
    EMOTE_ACTIVATE_ALTAR                          = 6
};

enum Creatures
{
    CREATURE_SNAKE                                = 29680,
    CREATURE_CONSTRICTORS                         = 29713
};

enum ConstrictorSpells
{
    SPELL_GRIP_OF_SLAD_RAN                        = 55093,
    SPELL_SNAKE_WRAP                              = 55126, // 55099 -> 55126
    SPELL_VENOMOUS_BITE                           = 54987
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

    struct boss_slad_ranAI : public BossAI
    {
        boss_slad_ranAI(Creature* creature) : BossAI(creature, DATA_SLAD_RAN)
        {
            Initialize();
        }

        void Initialize()
        {
            uiPoisonNovaTimer = 10 * IN_MILLISECONDS;
            uiPowerfullBiteTimer = 3 * IN_MILLISECONDS;
            uiVenomBoltTimer = 15 * IN_MILLISECONDS;
            uiSpawnTimer = 5 * IN_MILLISECONDS;
            uiPhase = 0;
        }

        uint32 uiPoisonNovaTimer;
        uint32 uiPowerfullBiteTimer;
        uint32 uiVenomBoltTimer;
        uint32 uiSpawnTimer;

        uint8 uiPhase;

        GuidSet lWrappedPlayers;

        void Reset() override
        {
            Initialize();
            _Reset();
            lWrappedPlayers.clear();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
        }

        void UpdateAI(uint32 diff) override
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

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
            Talk(EMOTE_ACTIVATE_ALTAR);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summon) override
        {
            summon->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
            summons.Summon(summon);
        }

        void SetGUID(ObjectGuid guid, int32 type) override
        {
            if (type == DATA_SNAKES_WHYD_IT_HAVE_TO_BE_SNAKES)
                lWrappedPlayers.insert(guid);
        }

        bool WasWrapped(ObjectGuid guid)
        {
            return lWrappedPlayers.count(guid) != 0;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetGundrakAI<boss_slad_ranAI>(creature);
    }
};

class npc_slad_ran_constrictor : public CreatureScript
{
public:
    npc_slad_ran_constrictor() : CreatureScript("npc_slad_ran_constrictor") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetGundrakAI<npc_slad_ran_constrictorAI>(creature);
    }

    struct npc_slad_ran_constrictorAI : public ScriptedAI
    {
        npc_slad_ran_constrictorAI(Creature* creature) : ScriptedAI(creature)
        {
            uiGripOfSladRanTimer = 1 * IN_MILLISECONDS;
        }

        uint32 uiGripOfSladRanTimer;

        void Reset() override
        {
            uiGripOfSladRanTimer = 1*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 diff) override
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
                        if (Unit* summoner = _me->GetSummoner())
                            if (Creature* sladran = summoner->ToCreature())
                                sladran->AI()->SetGUID(target->GetGUID(), DATA_SNAKES_WHYD_IT_HAVE_TO_BE_SNAKES);

                    me->DespawnOrUnsummon();
                }
            } else uiGripOfSladRanTimer -= diff;
        }
    };

};

class npc_slad_ran_viper : public CreatureScript
{
public:
    npc_slad_ran_viper() : CreatureScript("npc_slad_ran_viper") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetGundrakAI<npc_slad_ran_viperAI>(creature);
    }

    struct npc_slad_ran_viperAI : public ScriptedAI
    {
        npc_slad_ran_viperAI(Creature* creature) : ScriptedAI(creature)
        {
            uiVenomousBiteTimer = 2 * IN_MILLISECONDS;
        }

        uint32 uiVenomousBiteTimer;

        void Reset() override
        {
            uiVenomousBiteTimer = 2*IN_MILLISECONDS;
        }

        void UpdateAI(uint32 diff) override
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
        achievement_snakes_whyd_it_have_to_be_snakes() : AchievementCriteriaScript("achievement_snakes_whyd_it_have_to_be_snakes") { }

        bool OnCheck(Player* player, Unit* target) override
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
