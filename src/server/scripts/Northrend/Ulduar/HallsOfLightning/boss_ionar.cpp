/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "halls_of_lightning.h"

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
    SAY_AGGRO                                     = -1602011,
    SAY_SLAY_1                                    = -1602012,
    SAY_SLAY_2                                    = -1602013,
    SAY_SLAY_3                                    = -1602014,
    SAY_DEATH                                     = -1602015,
    SAY_SPLIT_1                                   = -1602016,
    SAY_SPLIT_2                                   = -1602017
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ionarAI(pCreature);
    }

    struct boss_ionarAI : public ScriptedAI
    {
        boss_ionarAI(Creature *pCreature) : ScriptedAI(pCreature), lSparkList(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

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

            uiDisperseHealth = 45 + urand(0,10);

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_DISABLE_MOVE);

            if (!me->IsVisible())
                me->SetVisible(true);

            if (pInstance)
                pInstance->SetData(TYPE_IONAR, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
                pInstance->SetData(TYPE_IONAR, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            lSparkList.DespawnAll();

            if (pInstance)
                pInstance->SetData(TYPE_IONAR, DONE);
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2,SAY_SLAY_3), me);
        }

        void SpellHit(Unit* /*caster*/, const SpellEntry* spell)
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
                    if (pSpark->isAlive())
                    {
                        pSpark->SetSpeed(MOVE_RUN, 2.0f);
                        pSpark->GetMotionMaster()->Clear();
                        pSpark->GetMotionMaster()->MovePoint(DATA_POINT_CALLBACK, pos);
                    }
                    else
                        pSpark->ForcedDespawn();
                }
            }
        }

        void DamageTaken(Unit * /*pDoneBy*/, uint32 &uiDamage)
        {
            if (!me->IsVisible())
                uiDamage = 0;
        }

        void JustSummoned(Creature* pSummoned)
        {
            if (pSummoned->GetEntry() == NPC_SPARK_OF_IONAR)
            {
                lSparkList.Summon(pSummoned);

                pSummoned->CastSpell(pSummoned, DUNGEON_MODE(SPELL_SPARK_VISUAL_TRIGGER,H_SPELL_SPARK_VISUAL_TRIGGER), true);

                Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                if (pTarget)
                {
                    pSummoned->SetInCombatWith(pTarget);
                    pSummoned->GetMotionMaster()->Clear();
                    pSummoned->GetMotionMaster()->MoveFollow(pTarget, 0.0f, 0.0f);
                }
            }
        }

        void SummonedCreatureDespawn(Creature *pSummoned)
        {
            if (pSummoned->GetEntry() == NPC_SPARK_OF_IONAR)
                lSparkList.Despawn(pSummoned);
        }

        void UpdateAI(const uint32 uiDiff)
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

                        if (me->getVictim())
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                    }
                }
                else
                    uiSplitTimer -= uiDiff;

                return;
            }

            if (uiStaticOverloadTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_STATIC_OVERLOAD);

                uiStaticOverloadTimer = urand(5*IN_MILLISECONDS, 6*IN_MILLISECONDS);
            }
            else
                uiStaticOverloadTimer -= uiDiff;

            if (uiBallLightningTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_BALL_LIGHTNING);
                uiBallLightningTimer = urand(10*IN_MILLISECONDS, 11*IN_MILLISECONDS);
            }
            else
                uiBallLightningTimer -= uiDiff;

            // Health check
            if (!bHasDispersed && HealthBelowPct(uiDisperseHealth))
            {
                bHasDispersed = true;

                DoScriptText(RAND(SAY_SPLIT_1,SAY_SPLIT_2), me);

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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_spark_of_ionarAI(pCreature);
    }

    struct mob_spark_of_ionarAI : public ScriptedAI
    {
        mob_spark_of_ionarAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 uiCheckTimer;

        void Reset()
        {
            uiCheckTimer = 2*IN_MILLISECONDS;
            me->SetReactState(REACT_PASSIVE);
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            if (uiType != POINT_MOTION_TYPE || !pInstance)
                return;

            if (uiPointId == DATA_POINT_CALLBACK)
                me->ForcedDespawn();
        }

        void DamageTaken(Unit * /*pDoneBy*/, uint32 &uiDamage)
        {
            uiDamage = 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            // Despawn if the encounter is not running
            if (pInstance && pInstance->GetData(TYPE_IONAR) != IN_PROGRESS)
            {
                me->ForcedDespawn();
                return;
            }

            // Prevent them to follow players through the whole instance
            if (uiCheckTimer <= uiDiff)
            {
                if (pInstance)
                {
                    Creature* pIonar = pInstance->instance->GetCreature(pInstance->GetData64(DATA_IONAR));
                    if (pIonar && pIonar->isAlive())
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
                        me->ForcedDespawn();
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
