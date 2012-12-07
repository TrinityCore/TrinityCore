/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "drak_tharon_keep.h"

enum Spells
{
    SPELL_ARCANE_BLAST                            = 49198,
    H_SPELL_ARCANE_BLAST                          = 59909,
    SPELL_ARCANE_FIELD                            = 47346,
    SPELL_BLIZZARD                                = 49034,
    H_SPELL_BLIZZARD                              = 59854,
    SPELL_FROSTBOLT                               = 49037,
    H_SPELL_FROSTBOLT                             = 59855,
    SPELL_WRATH_OF_MISERY                         = 50089,
    H_SPELL_WRATH_OF_MISERY                       = 59856,
    SPELL_SUMMON_MINIONS                          = 59910 //Summons an army of Fetid Troll Corpses to assist the caster.
};

//not in db
enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_KILL                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_NECRO_ADD                                 = 3,
    SAY_REUBBLE                                   = 4
};

enum Creatures
{
    CREATURE_RISEN_SHADOWCASTER                   = 27600,
    CREATURE_FETID_TROLL_CORPSE                   = 27598,
    CREATURE_HULKING_CORPSE                       = 27597,
    CREATURE_CRYSTAL_HANDLER                      = 26627
};

enum CombatPhase
{
    IDLE,
    PHASE_1,
    PHASE_2
};

#define ACTION_MINION_REACHED                     1
#define DATA_OH_NOVOS                             2

static Position AddSpawnPoint = { -379.20f, -816.76f, 59.70f, 0.0f };
static Position CrystalHandlerSpawnPoint = { -326.626343f, -709.956604f, 27.813314f, 0.0f };
static Position AddDestinyPoint = { -379.314545f, -772.577637f, 28.58837f, 0.0f };

class boss_novos : public CreatureScript
{
public:
    boss_novos() : CreatureScript("boss_novos") { }

    struct boss_novosAI : public Scripted_NoMovementAI
    {
        boss_novosAI(Creature* creature) : Scripted_NoMovementAI(creature), lSummons(me)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiTimer;
        uint32 uiCrystalHandlerTimer;
        uint8 crystalHandlerAmount;

        bool ohNovos;

        SummonList lSummons;

        std::list<uint64> luiCrystals;

        CombatPhase Phase;

        InstanceScript* instance;

        void Reset()
        {
            Phase = IDLE;
            luiCrystals.clear();
            ohNovos = true;
            me->CastStop();
            lSummons.DespawnAll();
            crystalHandlerAmount = 0;

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (instance)
            {
                instance->SetData(DATA_NOVOS_EVENT, NOT_STARTED);
                for (uint8 n = 0; n < 4; ++n)
                    luiCrystals.push_back(instance->GetData64(DATA_NOVOS_CRYSTAL_1 + n));
                for (std::list<uint64>::const_iterator itr = luiCrystals.begin(); itr != luiCrystals.end(); ++itr)
                {
                    if (GameObject* temp = instance->instance->GetGameObject(*itr))
                        temp->SetGoState(GO_STATE_READY);
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            Phase = PHASE_1;
            uiCrystalHandlerTimer = 30*IN_MILLISECONDS;
            uiTimer = 1*IN_MILLISECONDS;
            DoCast(SPELL_ARCANE_FIELD);
            if (instance)
            {
                for (std::list<uint64>::const_iterator itr = luiCrystals.begin(); itr != luiCrystals.end(); ++itr)
                {
                    if (GameObject* temp = instance->instance->GetGameObject(*itr))
                        temp->SetGoState(GO_STATE_ACTIVE);
                }
                instance->SetData(DATA_NOVOS_EVENT, IN_PROGRESS);
            }
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void UpdateAI(const uint32 diff)
        {
            switch (Phase)
            {
                case PHASE_1:
                    if (uiTimer <= diff)
                    {
                        Creature* summon = me->SummonCreature(RAND(CREATURE_FETID_TROLL_CORPSE, CREATURE_HULKING_CORPSE, CREATURE_RISEN_SHADOWCASTER), AddSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20*IN_MILLISECONDS);
                        summon->GetMotionMaster()->MovePoint(0, AddDestinyPoint);
                        //If spell is casted stops casting arcane field so no spell casting
                        //DoCast(me, SPELL_SUMMON_MINIONS);
                        uiTimer = 3*IN_MILLISECONDS;
                    } else uiTimer -= diff;
                    if (crystalHandlerAmount < 4)
                    {
                        if (uiCrystalHandlerTimer <= diff)
                        {
                            Talk(SAY_NECRO_ADD);
                            Creature* pCrystalHandler = me->SummonCreature(CREATURE_CRYSTAL_HANDLER, CrystalHandlerSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20*IN_MILLISECONDS);
                            pCrystalHandler->GetMotionMaster()->MovePoint(0, AddDestinyPoint);
                            uiCrystalHandlerTimer = urand(20*IN_MILLISECONDS, 30*IN_MILLISECONDS);
                        } else uiCrystalHandlerTimer -= diff;
                    }
                    break;
                case PHASE_2:
                    if (uiTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, DUNGEON_MODE(RAND(SPELL_ARCANE_BLAST, SPELL_BLIZZARD, SPELL_FROSTBOLT, SPELL_WRATH_OF_MISERY),
                                                         RAND(H_SPELL_ARCANE_BLAST, H_SPELL_BLIZZARD, H_SPELL_FROSTBOLT, H_SPELL_WRATH_OF_MISERY)));
                        uiTimer = urand(1*IN_MILLISECONDS, 3*IN_MILLISECONDS);
                    } else uiTimer -= diff;
                    break;
                default:
                    break;
            }
        }
        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            if (instance)
                instance->SetData(DATA_NOVOS_EVENT, DONE);
            lSummons.DespawnAll();
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;
            Talk(SAY_KILL);
        }

        void JustSummoned(Creature* summon)
        {
            if (summon->GetEntry() == CREATURE_CRYSTAL_HANDLER)
                crystalHandlerAmount++;

            lSummons.Summon(summon);
        }

        void DoAction(int32 const action)
        {
            if (action == ACTION_MINION_REACHED)
                ohNovos = false;
        }

        uint32 GetData(uint32 type) const
        {
            if (type == DATA_OH_NOVOS)
                return ohNovos ? 1 : 0;

            return 0;
        }

        void RemoveCrystal()
        {
            if (!luiCrystals.empty())
            {
                if (instance)
                    if (GameObject* temp = instance->instance->GetGameObject(luiCrystals.back()))
                        temp->SetGoState(GO_STATE_READY);
                luiCrystals.pop_back();
            }
            if (luiCrystals.empty())
            {
                me->CastStop();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                Phase = PHASE_2;
                uiTimer = 1*IN_MILLISECONDS;
            }
        }

        Unit* GetRandomTarget()
        {
            return SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_novosAI(creature);
    }
};

enum CrystalHandlerSpells
{
    SPELL_FLASH_OF_DARKNESS                       = 49668,
    H_SPELL_FLASH_OF_DARKNESS                     = 59004
};

class mob_crystal_handler : public CreatureScript
{
public:
    mob_crystal_handler() : CreatureScript("mob_crystal_handler") { }

    struct mob_crystal_handlerAI : public ScriptedAI
    {
        mob_crystal_handlerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiFlashOfDarknessTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiFlashOfDarknessTimer = 5*IN_MILLISECONDS;
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Creature* pNovos = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_NOVOS) : 0))
                CAST_AI(boss_novos::boss_novosAI, pNovos->AI())->RemoveCrystal();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiFlashOfDarknessTimer <= diff)
            {
                DoCast(me->getVictim(), DUNGEON_MODE(SPELL_FLASH_OF_DARKNESS, H_SPELL_FLASH_OF_DARKNESS));
                uiFlashOfDarknessTimer = 5*IN_MILLISECONDS;
            } else uiFlashOfDarknessTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != 0)
                return;
            if (Creature* pNovos = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_NOVOS) : 0))
                if (Unit* target = CAST_AI(boss_novos::boss_novosAI, pNovos->AI())->GetRandomTarget())
                    AttackStart(target);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_crystal_handlerAI(creature);
    }
};

class mob_novos_minion : public CreatureScript
{
public:
    mob_novos_minion() : CreatureScript("mob_novos_minion") { }

    struct mob_novos_minionAI : public ScriptedAI
    {
        mob_novos_minionAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id !=0)
                return;
            if (Creature* Novos = ObjectAccessor::GetCreature(*me, instance ? instance->GetData64(DATA_NOVOS) : 0))
            {
                Novos->AI()->DoAction(ACTION_MINION_REACHED);
                if (Unit* target = CAST_AI(boss_novos::boss_novosAI, Novos->AI())->GetRandomTarget())
                    AttackStart(target);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_novos_minionAI(creature);
    }
};

class achievement_oh_novos : public AchievementCriteriaScript
{
    public:
        achievement_oh_novos() : AchievementCriteriaScript("achievement_oh_novos")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Novos = target->ToCreature())
                if (Novos->AI()->GetData(DATA_OH_NOVOS))
                    return true;

            return false;
        }
};

void AddSC_boss_novos()
{
    new boss_novos();
    new mob_crystal_handler();
    new mob_novos_minion();
    new achievement_oh_novos();
}
