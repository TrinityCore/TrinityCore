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

/* Script Data Start
SDName: Boss sjonnir
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "halls_of_stone.h"

enum Spells
{
    SPELL_LIGHTING_RING                                    = 51849, //Periodic Trigger (interval 2s) spell = 50841
    H_SPELL_LIGHTING_RING                                  = 59861, //Periodic Trigger (interval 2s) spell = 59849
    SPELL_LIGHTING_RING_1                                  = 50840, //Periodic Trigger (interval 2s) spell = 50841
    H_SPELL_LIGHTING_RING_1                                = 59848, //Periodic Trigger (interval 2s) spell = 59849
    SPELL_STATIC_CHARGE                                    = 50834, //Periodic Trigger 2s interval, spell =50835
    H_SPELL_STATIC_CHARGE                                  = 59846, //Periodic Trigger 2s interval, spell =50847
    SPELL_CHAIN_LIGHTING                                   = 50830,
    H_SPELL_CHAIN_LIGHTING                                 = 59844,
    SPELL_LIGHTING_SHIELD                                  = 50831,
    H_SPELL_LIGHTING_SHIELD                                = 59845,
    SPELL_FRENZY                                           = 28747
};

enum Yells
{
    SAY_AGGRO                                              = 0,
    SAY_SLAY                                               = 1,
    SAY_DEATH                                              = 2
};

#define EMOTE_GENERIC_FRENZY                               -1000002

enum SjonnirCreatures
{
    CREATURE_FORGED_IRON_TROGG                             = 27979,
    CREATURE_MALFORMED_OOZE                                = 27981,
    CREATURE_FORGED_IRON_DWARF                             = 27982,
    CREATURE_IRON_SLUDGE                                   = 28165
};

#define DATA_TIME_BEFORE_OOZE                              150000 //2min 30 secs

struct Locations
{
    float x, y, z;
};

static Locations PipeLocations[] =
{
    {1295.44f, 734.07f, 200.3f}, //left
    {1297.7f,  595.6f,  199.9f} //right
};

#define ACTION_OOZE_DEAD                                   1
#define DATA_ABUSE_THE_OOZE                                2

static Locations CenterPoint = {1295.21f, 667.157f, 189.691f};

class boss_sjonnir : public CreatureScript
{
public:
    boss_sjonnir() : CreatureScript("boss_sjonnir") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_sjonnirAI (creature);
    }

    struct boss_sjonnirAI : public ScriptedAI
    {
        boss_sjonnirAI(Creature* creature) : ScriptedAI(creature), lSummons(me)
        {
            instance = creature->GetInstanceScript();
        }

        bool bIsFrenzy;

        uint32 uiChainLightningTimer;
        uint32 uiLightningShieldTimer;
        uint32 uiStaticChargeTimer;
        uint32 uiLightningRingTimer;
        uint32 uiSummonTimer;
        uint32 uiFrenzyTimer;
        uint32 uiEncounterTimer;
        uint8 abuseTheOoze;

        SummonList lSummons;

        InstanceScript* instance;

        void Reset()
        {
            bIsFrenzy = false;

            uiEncounterTimer = 0;
            uiChainLightningTimer = urand(3000, 8000);
            uiLightningShieldTimer = urand(20000, 25000);
            uiStaticChargeTimer = urand(20000, 25000);
            uiLightningRingTimer = urand(30000, 35000);
            uiSummonTimer = 5000;
            uiFrenzyTimer = 300000; //5 minutes
            abuseTheOoze = 0;

            lSummons.DespawnAll();

            if (instance)
                instance->SetData(DATA_SJONNIR_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);

            uiEncounterTimer = 0;

            if (instance)
            {
                if (GameObject* pDoor = instance->instance->GetGameObject(instance->GetData64(DATA_SJONNIR_DOOR)))
                    if (pDoor->GetGoState() == GO_STATE_READY)
                    {
                        EnterEvadeMode();
                        return;
                    }

                instance->SetData(DATA_SJONNIR_EVENT, IN_PROGRESS);
            }
        }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiChainLightningTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_CHAIN_LIGHTING);
                uiChainLightningTimer = urand(10000, 15000);
            } else uiChainLightningTimer -= diff;

            if (uiLightningShieldTimer <= diff)
            {
                DoCast(me, SPELL_LIGHTING_SHIELD);
                uiLightningShieldTimer -= diff;
            }

            if (uiStaticChargeTimer <= diff)
            {
                DoCastVictim(SPELL_STATIC_CHARGE);
                uiStaticChargeTimer = urand(20000, 25000);
            } uiStaticChargeTimer -= diff;

            if (uiLightningRingTimer <= diff)
            {
                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);
                DoCast(me, SPELL_LIGHTING_RING);
                uiLightningRingTimer = urand(30000, 35000);
            } else uiLightningRingTimer -= diff;

            if (uiSummonTimer <= diff)
            {
                uint32 uiSummonPipe = rand()%2;
                me->SummonCreature(uiEncounterTimer > DATA_TIME_BEFORE_OOZE ? CREATURE_MALFORMED_OOZE :
                                           RAND(CREATURE_FORGED_IRON_DWARF, CREATURE_FORGED_IRON_TROGG),
                                           PipeLocations[uiSummonPipe].x, PipeLocations[uiSummonPipe].y, PipeLocations[uiSummonPipe].z, 0.0f,
                                           TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                uiSummonTimer = 20000;
            } else uiSummonTimer -= diff;

            if (!bIsFrenzy)
            {
              if (uiFrenzyTimer <= diff)
              {
                  DoCast(me, SPELL_FRENZY);
                  bIsFrenzy = true;
              }
              else uiFrenzyTimer -= diff;
            }

            uiEncounterTimer +=diff;

            DoMeleeAttackIfReady();
        }

        void JustSummoned(Creature* summon)
        {
            summon->GetMotionMaster()->MovePoint(0, CenterPoint.x, CenterPoint.y, CenterPoint.z);
            /*if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                summon->AI()->AttackStart(target);*/
            lSummons.Summon(summon);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            lSummons.DespawnAll();

            if (instance)
                instance->SetData(DATA_SJONNIR_EVENT, DONE);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_SLAY);
        }

        void DoAction(int32 action)
        {
            if (action == ACTION_OOZE_DEAD)
                ++abuseTheOoze;
        }

        uint32 GetData(uint32 type) const
        {
            if (type == DATA_ABUSE_THE_OOZE)
                return abuseTheOoze;

            return 0;
        }
    };

};

class mob_malformed_ooze : public CreatureScript
{
public:
    mob_malformed_ooze() : CreatureScript("mob_malformed_ooze") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_malformed_oozeAI(creature);
    }

    struct mob_malformed_oozeAI : public ScriptedAI
    {
        mob_malformed_oozeAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 uiMergeTimer;

        void Reset()
        {
            uiMergeTimer = 10000;
        }

        void UpdateAI(uint32 diff)
        {
            if (uiMergeTimer <= diff)
            {
                if (Creature* temp = me->FindNearestCreature(CREATURE_MALFORMED_OOZE, 3.0f, true))
                {
                    DoSpawnCreature(CREATURE_IRON_SLUDGE, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000);
                    temp->DisappearAndDie();
                    me->DisappearAndDie();
                }
                uiMergeTimer = 3000;
            } else uiMergeTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

class mob_iron_sludge : public CreatureScript
{
public:
    mob_iron_sludge() : CreatureScript("mob_iron_sludge") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_iron_sludgeAI(creature);
    }

    struct mob_iron_sludgeAI : public ScriptedAI
    {
        mob_iron_sludgeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                if (Creature* Sjonnir = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SJONNIR)))
                    Sjonnir->AI()->DoAction(ACTION_OOZE_DEAD);
        }
    };

};

class achievement_abuse_the_ooze : public AchievementCriteriaScript
{
    public:
        achievement_abuse_the_ooze() : AchievementCriteriaScript("achievement_abuse_the_ooze")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Sjonnir = target->ToCreature())
                if (Sjonnir->AI()->GetData(DATA_ABUSE_THE_OOZE) >= 5)
                    return true;

            return false;
        }
};

void AddSC_boss_sjonnir()
{
    new boss_sjonnir();
    new mob_malformed_ooze();
    new mob_iron_sludge();
    new achievement_abuse_the_ooze();
}
