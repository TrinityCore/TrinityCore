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

/*
 * Comment: Timer check pending
 */

#include "ScriptMgr.h"
#include "halls_of_lightning.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Spells
{
    SPELL_BALL_LIGHTNING                          = 52780,
    SPELL_STATIC_OVERLOAD                         = 52658,

    SPELL_DISPERSE                                = 52770,
    SPELL_SUMMON_SPARK                            = 52746,
    SPELL_SPARK_DESPAWN                           = 52776,

    // Spark of Ionar
    SPELL_SPARK_VISUAL_TRIGGER                    = 52667,
    SPELL_RANDOM_LIGHTNING_VISUAL                 = 52663
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
    DATA_POINT_CALLBACK                           = 0
};

static constexpr float DATA_MAX_SPARK_DISTANCE = 90; // Distance to boss - prevent runs through the whole instance

/*######
## Boss Ionar
######*/

struct boss_ionar : public BossAI
{
    boss_ionar(Creature* creature) : BossAI(creature, DATA_IONAR)
    {
        Initialize();
    }

    void Initialize()
    {
        bIsSplitPhase = true;
        bHasDispersed = false;

        uiSplitTimer = 25 * IN_MILLISECONDS;

        uiStaticOverloadTimer = urand(5 * IN_MILLISECONDS, 6 * IN_MILLISECONDS);
        uiBallLightningTimer = urand(10 * IN_MILLISECONDS, 11 * IN_MILLISECONDS);

        uiDisperseHealth = 45 + urand(0, 10);
    }

    void Reset() override
    {
        BossAI::Reset();

        Initialize();

        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
        me->SetControlled(false, UNIT_STATE_ROOT);

        if (!me->IsVisible())
            me->SetVisible(true);

        instance->SetBossState(DATA_IONAR, NOT_STARTED);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DISPERSE)
        {
            for (uint8 i = 0; i < DATA_MAX_SPARKS; ++i)
                me->CastSpell(me, SPELL_SUMMON_SPARK, true);

            me->AttackStop();
            me->SetVisible(false);
            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
            me->SetControlled(true, UNIT_STATE_ROOT);

            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveIdle();
        }
    }

    //make sparks come back
    void CallBackSparks()
    {
        //should never be empty here, but check
        if (summons.empty())
            return;

        Position pos = me->GetPosition();

        for (SummonList::const_iterator itr = summons.begin(); itr != summons.end();)
        {
            Creature* pSpark = ObjectAccessor::GetCreature(*me, *itr);
            ++itr;

            if (pSpark)
            {
                if (pSpark->IsAlive())
                {
                    pSpark->SetReactState(REACT_PASSIVE);
                    pSpark->SetSpeedRate(MOVE_RUN, 2.0f);
                    pSpark->GetMotionMaster()->Clear();
                    pSpark->GetMotionMaster()->MovePoint(DATA_POINT_CALLBACK, pos);
                }
                else
                    pSpark->DespawnOrUnsummon();
            }
        }
    }

    void DamageTaken(Unit* /*pDoneBy*/, uint32 &uiDamage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!me->IsVisible())
            uiDamage = 0;
    }

    void JustSummoned(Creature* summoned) override
    {
        if (summoned->GetEntry() == NPC_SPARK_OF_IONAR)
        {
            summons.Summon(summoned);

            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
            {
                summoned->SetInCombatWith(target);
                summoned->GetMotionMaster()->Clear();
                summoned->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
            }
        }
    }

    void SummonedCreatureDespawn(Creature* summoned) override
    {
        if (summoned->GetEntry() == NPC_SPARK_OF_IONAR)
            summons.Despawn(summoned);
    }

    void UpdateAI(uint32 uiDiff) override
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
                else if (summons.empty())
                {
                    me->SetVisible(true);
                    me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
                    me->SetControlled(false, UNIT_STATE_ROOT);

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
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                DoCast(target, SPELL_STATIC_OVERLOAD);

            uiStaticOverloadTimer = urand(5*IN_MILLISECONDS, 6*IN_MILLISECONDS);
        }
        else
            uiStaticOverloadTimer -= uiDiff;

        if (uiBallLightningTimer <= uiDiff)
        {
            DoCastVictim(SPELL_BALL_LIGHTNING);
            uiBallLightningTimer = urand(10*IN_MILLISECONDS, 11*IN_MILLISECONDS);
        }
        else
            uiBallLightningTimer -= uiDiff;

        // Health check
        if (!bHasDispersed && HealthBelowPct(uiDisperseHealth))
        {
            bHasDispersed = true;

            Talk(SAY_SPLIT);

            if (me->IsNonMeleeSpellCast(false))
                me->InterruptNonMeleeSpells(false);

            DoCast(me, SPELL_DISPERSE, false);
        }

        DoMeleeAttackIfReady();
    }

private:
    bool bIsSplitPhase;
    bool bHasDispersed;

    uint32 uiSplitTimer;

    uint32 uiStaticOverloadTimer;
    uint32 uiBallLightningTimer;

    uint32 uiDisperseHealth;
};

/*######
## npc_spark_of_ionar
######*/

struct npc_spark_of_ionar : public ScriptedAI
{
    npc_spark_of_ionar(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        _instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        uiCheckTimer = 2 * IN_MILLISECONDS;
    }

    void Reset() override
    {
        Initialize();
        DoCastSelf(SPELL_SPARK_VISUAL_TRIGGER);
        DoCastSelf(SPELL_RANDOM_LIGHTNING_VISUAL);
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE || !_instance)
            return;

        if (uiPointId == DATA_POINT_CALLBACK)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 uiDiff) override
    {
        // Despawn if the encounter is not running
        if (_instance->GetBossState(DATA_IONAR) != IN_PROGRESS)
        {
            me->DespawnOrUnsummon();
            return;
        }

        // Prevent them to follow players through the whole instance
        if (uiCheckTimer <= uiDiff)
        {
            Creature* ionar = _instance->GetCreature(DATA_IONAR);
            if (ionar && ionar->IsAlive())
            {
                if (me->GetDistance(ionar) > DATA_MAX_SPARK_DISTANCE)
                {
                    Position pos = ionar->GetPosition();

                    me->SetReactState(REACT_PASSIVE);
                    me->SetSpeedRate(MOVE_RUN, 2.0f);
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePoint(DATA_POINT_CALLBACK, pos);
                }
            }
            else
                me->DespawnOrUnsummon();
            uiCheckTimer = 2*IN_MILLISECONDS;
        }
        else
            uiCheckTimer -= uiDiff;

        // No melee attack at all!
    }

private:
    InstanceScript* _instance;
    uint32 uiCheckTimer;
};

void AddSC_boss_ionar()
{
    RegisterHallsOfLightningCreatureAI(boss_ionar);
    RegisterHallsOfLightningCreatureAI(npc_spark_of_ionar);
}
