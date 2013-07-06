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
#include "violet_hold.h"

enum Spells
{
    SPELL_SHROUD_OF_DARKNESS                    = 54524,
    H_SPELL_SHROUD_OF_DARKNESS                  = 59745,
    SPELL_SUMMON_VOID_SENTRY                    = 54369,
    SPELL_VOID_SHIFT                            = 54361,
    H_SPELL_VOID_SHIFT                          = 59743,

    SPELL_ZURAMAT_ADD_2                         = 54342,
    H_SPELL_ZURAMAT_ADD_2                       = 59747
};

enum Creatures
{
    NPC_VOID_SENTRY                        = 29364
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_SHIELD                                  = 4,
    SAY_WHISPER                                 = 5
};

enum Misc
{
    DATA_VOID_DANCE                             = 2153
};

class boss_zuramat : public CreatureScript
{
public:
    boss_zuramat() : CreatureScript("boss_zuramat") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_zuramatAI (creature);
    }

    struct boss_zuramatAI : public ScriptedAI
    {
        boss_zuramatAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 SpellVoidShiftTimer;
        uint32 SpellSummonVoidTimer;
        uint32 SpellShroudOfDarknessTimer;
        bool voidDance;

        void Reset() OVERRIDE
        {
            if (instance)
            {
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                    instance->SetData(DATA_1ST_BOSS_EVENT, NOT_STARTED);
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                    instance->SetData(DATA_2ND_BOSS_EVENT, NOT_STARTED);
            }

            SpellShroudOfDarknessTimer = 22000;
            SpellVoidShiftTimer = 15000;
            SpellSummonVoidTimer = 12000;
            voidDance = true;
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            if (instance)
            {
                if (GameObject* pDoor = instance->instance->GetGameObject(instance->GetData64(DATA_ZURAMAT_CELL)))
                    if (pDoor->GetGoState() == GO_STATE_READY)
                    {
                        EnterEvadeMode();
                        return;
                    }
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                    instance->SetData(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                    instance->SetData(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
            }
        }

        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE {}


        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (SpellSummonVoidTimer <= diff)
            {
                DoCastVictim(SPELL_SUMMON_VOID_SENTRY, false);
                SpellSummonVoidTimer = 20000;
            } else SpellSummonVoidTimer -=diff;

            if (SpellVoidShiftTimer <= diff)
            {
                 if (Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(unit, SPELL_VOID_SHIFT);
                SpellVoidShiftTimer = 20000;
            } else SpellVoidShiftTimer -=diff;

            if (SpellShroudOfDarknessTimer <= diff)
            {
                DoCastVictim(SPELL_SHROUD_OF_DARKNESS);
                SpellShroudOfDarknessTimer = 20000;
            } else SpellShroudOfDarknessTimer -=diff;

            DoMeleeAttackIfReady();
        }

        void SummonedCreatureDies(Creature* summoned, Unit* /*who*/) OVERRIDE
        {
            if (summoned->GetEntry() == NPC_VOID_SENTRY)
                voidDance = false;
        }

        uint32 GetData(uint32 type) const OVERRIDE
        {
            if (type == DATA_VOID_DANCE)
                return voidDance ? 1 : 0;

            return 0;
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            if (instance)
            {
                if (instance->GetData(DATA_WAVE_COUNT) == 6)
                {
                    instance->SetData(DATA_1ST_BOSS_EVENT, DONE);
                    instance->SetData(DATA_WAVE_COUNT, 7);
                }
                else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                {
                    instance->SetData(DATA_2ND_BOSS_EVENT, DONE);
                    instance->SetData(DATA_WAVE_COUNT, 13);
                }
            }
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            summon->AI()->AttackStart(me->GetVictim());
            summon->AI()->DoCastAOE(SPELL_ZURAMAT_ADD_2);
            summon->SetPhaseMask(17, true);
        }
    };

};

class achievement_void_dance : public AchievementCriteriaScript
{
    public:
        achievement_void_dance() : AchievementCriteriaScript("achievement_void_dance")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (Creature* Zuramat = target->ToCreature())
                if (Zuramat->AI()->GetData(DATA_VOID_DANCE))
                    return true;

            return false;
        }
};

void AddSC_boss_zuramat()
{
    new boss_zuramat();
    new achievement_void_dance();
}
