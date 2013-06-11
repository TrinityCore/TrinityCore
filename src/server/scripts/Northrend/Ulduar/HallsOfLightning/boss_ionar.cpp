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

/*
 * Comment: Timer check pending
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "halls_of_lightning.h"
#include "SpellInfo.h"

enum Spells
{
    SPELL_BALL_LIGHTNING                          = 52780,
    H_SPELL_BALL_LIGHTNING                        = 59800,
    SPELL_STATIC_OVERLOAD                         = 52658,
    H_SPELL_STATIC_OVERLOAD                       = 59795,

    SPELL_DISPERSE                                = 52770,
    SPELL_SUMMON_SPARK                            = 52746,
    SPELL_SPARK_DESPAWN                           = 52776,

    //Spark of Ionar
    SPELL_SPARK_VISUAL_TRIGGER                    = 52667,
    H_SPELL_SPARK_VISUAL_TRIGGER                  = 59833
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_SPLIT                                     = 1,
    SAY_SLAY                                      = 2,
    SAY_DEATH                                     = 3
};

enum Creatures
{
    NPC_SPARK_OF_IONAR                            = 28926
};

enum Misc
{
    DATA_MAX_SPARKS                               = 5,
    DATA_MAX_SPARK_DISTANCE                       = 90, // Distance to boss - prevent runs through the whole instance
    DATA_POINT_CALLBACK                           = 0
};

/*######
## Boss Ionar
######*/

class boss_ionar : public CreatureScript
{
public:
    boss_ionar() : CreatureScript("boss_ionar") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ionarAI(creature);
    }

    struct boss_ionarAI : public ScriptedAI
    {
        boss_ionarAI(Creature* creature) : ScriptedAI(creature), lSparkList(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        SummonList lSparkList;

        bool bIsSplitPhase;
        bool bHasDispersed;

        uint32 uiSplitTimer;

        uint32 uiStaticOverloadTimer;
        uint32 uiBallLightningTimer;

        uint32 uiDisperseHealth;

        void Reset()
        {
            lSparkList.DespawnAll();

            bIsSplitPhase = true;
            bHasDispersed = false;

            uiSplitTimer = 25*IN_MILLISECONDS;

            uiStaticOverloadTimer = urand(5*IN_MILLISECONDS, 6*IN_MILLISECONDS);
            uiBallLightningTimer = urand(10*IN_MILLISECONDS, 11*IN_MILLISECONDS);

            uiDisperseHealth = 45 + urand(0, 10);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_DISABLE_MOVE);

            if (!me->IsVisible())
                me->SetVisible(true);

            if (instance)
                instance->SetData(TYPE_IONAR, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(TYPE_IONAR, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            lSparkList.DespawnAll();

            if (instance)
                instance->SetData(TYPE_IONAR, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_DISPERSE)
            {
                for (uint8 i = 0; i < DATA_MAX_SPARKS; ++i)
                    me->CastSpell(me, SPELL_SUMMON_SPARK, true);

                me->AttackStop();
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_DISABLE_MOVE);

                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
            }
        }

        //make sparks come back
        void CallBackSparks()
        {
            //should never be empty here, but check
            if (lSparkList.empty())
                return;

            Position pos;
            me->GetPosition(&pos);

            for (std::list<uint64>::const_iterator itr = lSparkList.begin(); itr != lSparkList.end(); ++itr)
            {
                if (Creature* pSpark = Unit::GetCreature(*me, *itr))
                {
                    if (pSpark->IsAlive())
                    {
                        pSpark->SetSpeed(MOVE_RUN, 2.0f);
                        pSpark->GetMotionMaster()->Clear();
                        pSpark->GetMotionMaster()->MovePoint(DATA_POINT_CALLBACK, pos);
                    }
                    else
                        pSpark->DespawnOrUnsummon();
                }
            }
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
        {
            if (!me->IsVisible())
                uiDamage = 0;
        }

        void JustSummoned(Creature* summoned)
        {
            if (summoned->GetEntry() == NPC_SPARK_OF_IONAR)
            {
                lSparkList.Summon(summoned);

                summoned->CastSpell(summoned, DUNGEON_MODE(SPELL_SPARK_VISUAL_TRIGGER, H_SPELL_SPARK_VISUAL_TRIGGER), true);

                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    summoned->SetInCombatWith(target);
                    summoned->GetMotionMaster()->Clear();
                    summoned->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                }
            }
        }

        void SummonedCreatureDespawn(Creature* summoned)
        {
            if (summoned->GetEntry() == NPC_SPARK_OF_IONAR)
                lSparkList.Despawn(summoned);
        }

        void UpdateAI(uint32 uiDiff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            // Splitted
            if (!me->IsVisible())
            {
                if (uiSplitTimer <= uiDiff)
                {
                    uiSplitTimer = 2500;

                    // Return sparks to where Ionar splitted
                    if (bIsSplitPhase)
                    {
                        CallBackSparks();
                        bIsSplitPhase = false;
                    }
                    // Lightning effect and restore Ionar
                    else if (lSparkList.empty())
                    {
                        me->SetVisible(true);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_DISABLE_MOVE);

                        DoCast(me, SPELL_SPARK_DESPAWN, false);

                        uiSplitTimer = 25*IN_MILLISECONDS;
                        bIsSplitPhase = true;

                        if (me->GetVictim())
                            me->GetMotionMaster()->MoveChase(me->GetVictim());
                    }
                }
                else
                    uiSplitTimer -= uiDiff;

                return;
            }

            if (uiStaticOverloadTimer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_STATIC_OVERLOAD);

                uiStaticOverloadTimer = urand(5*IN_MILLISECONDS, 6*IN_MILLISECONDS);
            }
            else
                uiStaticOverloadTimer -= uiDiff;

            if (uiBallLightningTimer <= uiDiff)
            {
                DoCast(me->GetVictim(), SPELL_BALL_LIGHTNING);
                uiBallLightningTimer = urand(10*IN_MILLISECONDS, 11*IN_MILLISECONDS);
            }
            else
                uiBallLightningTimer -= uiDiff;

            // Health check
            if (!bHasDispersed && HealthBelowPct(uiDisperseHealth))
            {
                bHasDispersed = true;

                Talk(SAY_SPLIT);

                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);

                DoCast(me, SPELL_DISPERSE, false);
            }

            DoMeleeAttackIfReady();
        }
    };

};

/*######
## mob_spark_of_ionar
######*/

class mob_spark_of_ionar : public CreatureScript
{
public:
    mob_spark_of_ionar() : CreatureScript("mob_spark_of_ionar") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_spark_of_ionarAI(creature);
    }

    struct mob_spark_of_ionarAI : public ScriptedAI
    {
        mob_spark_of_ionarAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 uiCheckTimer;

        void Reset()
        {
            uiCheckTimer = 2*IN_MILLISECONDS;
            me->SetReactState(REACT_PASSIVE);
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            if (uiType != POINT_MOTION_TYPE || !instance)
                return;

            if (uiPointId == DATA_POINT_CALLBACK)
                me->DespawnOrUnsummon();
        }

        void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage)
        {
            uiDamage = 0;
        }

        void UpdateAI(uint32 uiDiff)
        {
            // Despawn if the encounter is not running
            if (instance && instance->GetData(TYPE_IONAR) != IN_PROGRESS)
            {
                me->DespawnOrUnsummon();
                return;
            }

            // Prevent them to follow players through the whole instance
            if (uiCheckTimer <= uiDiff)
            {
                if (instance)
                {
                    Creature* pIonar = instance->instance->GetCreature(instance->GetData64(DATA_IONAR));
                    if (pIonar && pIonar->IsAlive())
                    {
                        if (me->GetDistance(pIonar) > DATA_MAX_SPARK_DISTANCE)
                        {
                            Position pos;
                            pIonar->GetPosition(&pos);

                            me->SetSpeed(MOVE_RUN, 2.0f);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(DATA_POINT_CALLBACK, pos);
                        }
                    }
                    else
                        me->DespawnOrUnsummon();
                }
                uiCheckTimer = 2*IN_MILLISECONDS;
            }
            else
                uiCheckTimer -= uiDiff;

            // No melee attack at all!
        }
    };

};

void AddSC_boss_ionar()
{
    new boss_ionar();
    new mob_spark_of_ionar();
}
