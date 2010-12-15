/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
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
    SAY_AGGRO                                     = -1600000,
    SAY_KILL                                      = -1600001,
    SAY_DEATH                                     = -1600002,
    SAY_NECRO_ADD                                 = -1600003,
    SAY_REUBBLE_1                                 = -1600004,
    SAY_REUBBLE_2                                 = -1600005
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
enum Achievements
{
    ACHIEV_OH_NOVOS                               = 2057
};

static Position AddSpawnPoint = { -379.20f, -816.76f, 59.70f, 0.0f };
static Position CrystalHandlerSpawnPoint = { -326.626343f, -709.956604f, 27.813314f, 0.0f };
static Position AddDestinyPoint = { -379.314545f, -772.577637f, 28.58837f, 0.0f };

class boss_novos : public CreatureScript
{
public:
    boss_novos() : CreatureScript("boss_novos") { }

    struct boss_novosAI : public Scripted_NoMovementAI
    {
        boss_novosAI(Creature *c) : Scripted_NoMovementAI(c), lSummons(me)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 uiTimer;
        uint32 uiCrystalHandlerTimer;
        uint8 crystalHandlerAmount;

        bool bAchiev;

        SummonList lSummons;

        std::list<uint64> luiCrystals;

        CombatPhase Phase;

        InstanceScript* pInstance;

        void Reset()
        {
            Phase = IDLE;
            luiCrystals.clear();
            bAchiev = true;
            me->CastStop();
            lSummons.DespawnAll();
            crystalHandlerAmount = 0;

            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (pInstance)
            {
                pInstance->SetData(DATA_NOVOS_EVENT, NOT_STARTED);
                luiCrystals.push_back(pInstance->GetData64(DATA_NOVOS_CRYSTAL_1));
                luiCrystals.push_back(pInstance->GetData64(DATA_NOVOS_CRYSTAL_2));
                luiCrystals.push_back(pInstance->GetData64(DATA_NOVOS_CRYSTAL_3));
                luiCrystals.push_back(pInstance->GetData64(DATA_NOVOS_CRYSTAL_4));
                for (std::list<uint64>::const_iterator itr = luiCrystals.begin(); itr != luiCrystals.end(); ++itr)
                {
                    if (GameObject* pTemp = pInstance->instance->GetGameObject(*itr))
                        pTemp->SetGoState(GO_STATE_READY);
                }
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            Phase = PHASE_1;
            uiCrystalHandlerTimer = 30*IN_MILLISECONDS;
            uiTimer = 1*IN_MILLISECONDS;
            DoCast(SPELL_ARCANE_FIELD);
            if (pInstance)
            {
                for (std::list<uint64>::const_iterator itr = luiCrystals.begin(); itr != luiCrystals.end(); ++itr)
                {
                    if (GameObject *pTemp = pInstance->instance->GetGameObject(*itr))
                        pTemp->SetGoState(GO_STATE_ACTIVE);
                }
                pInstance->SetData(DATA_NOVOS_EVENT, IN_PROGRESS);
            }
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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
                        Creature *pSummon = me->SummonCreature(RAND(CREATURE_FETID_TROLL_CORPSE,CREATURE_HULKING_CORPSE,CREATURE_RISEN_SHADOWCASTER), AddSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20*IN_MILLISECONDS);
                        pSummon->GetMotionMaster()->MovePoint(0, AddDestinyPoint);
                        //If spell is casted stops casting arcane field so no spell casting
                        //DoCast(me, SPELL_SUMMON_MINIONS);
                        uiTimer = 3*IN_MILLISECONDS;
                    } else uiTimer -= diff;
                    if (crystalHandlerAmount < 4)
                    {
                        if (uiCrystalHandlerTimer <= diff)
                        {
                            DoScriptText(SAY_NECRO_ADD, me);
                            Creature *pCrystalHandler = me->SummonCreature(CREATURE_CRYSTAL_HANDLER, CrystalHandlerSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN,20*IN_MILLISECONDS);
                            pCrystalHandler->GetMotionMaster()->MovePoint(0, AddDestinyPoint);
                            uiCrystalHandlerTimer = urand(20*IN_MILLISECONDS,30*IN_MILLISECONDS);
                        } else uiCrystalHandlerTimer -= diff;
                    }
                    break;
                case PHASE_2:
                    if (uiTimer <= diff)
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(pTarget, DUNGEON_MODE(RAND(SPELL_ARCANE_BLAST,SPELL_BLIZZARD,SPELL_FROSTBOLT,SPELL_WRATH_OF_MISERY),
                                                         RAND(H_SPELL_ARCANE_BLAST,H_SPELL_BLIZZARD,H_SPELL_FROSTBOLT,H_SPELL_WRATH_OF_MISERY)));
                        uiTimer = urand(1*IN_MILLISECONDS,3*IN_MILLISECONDS);
                    } else uiTimer -= diff;
                    break;
                default:
                    break;
            }
        }
        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            if (pInstance)
            {
                pInstance->SetData(DATA_NOVOS_EVENT, DONE);

                if (IsHeroic() && bAchiev)
                    pInstance->DoCompleteAchievement(ACHIEV_OH_NOVOS);
            }
            lSummons.DespawnAll();
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;
            DoScriptText(SAY_KILL, me);
        }

        void JustSummoned(Creature *summon)
        {
            if (summon->GetEntry() == CREATURE_CRYSTAL_HANDLER)
                crystalHandlerAmount++;

            lSummons.Summon(summon);
        }

        void RemoveCrystal()
        {
            if (!luiCrystals.empty())
            {
                if (pInstance)
                    if (GameObject *pTemp = pInstance->instance->GetGameObject(luiCrystals.back()))
                        pTemp->SetGoState(GO_STATE_READY);
                luiCrystals.pop_back();
            }
            if (luiCrystals.empty())
            {
                me->CastStop();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
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

    CreatureAI *GetAI(Creature *creature) const
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
        mob_crystal_handlerAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 uiFlashOfDarknessTimer;

        InstanceScript *pInstance;

        void Reset()
        {
            uiFlashOfDarknessTimer = 5*IN_MILLISECONDS;
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Creature* pNovos = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_NOVOS) : 0))
                CAST_AI(boss_novos::boss_novosAI,pNovos->AI())->RemoveCrystal();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (uiFlashOfDarknessTimer <= diff)
            {
                DoCast(me->getVictim(), DUNGEON_MODE(SPELL_FLASH_OF_DARKNESS,H_SPELL_FLASH_OF_DARKNESS));
                uiFlashOfDarknessTimer = 5*IN_MILLISECONDS;
            } else uiFlashOfDarknessTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != 0)
                return;
            if (Creature *pNovos = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_NOVOS) : 0))
                if (Unit *pTarget = CAST_AI(boss_novos::boss_novosAI, pNovos->AI())->GetRandomTarget())
                    AttackStart(pTarget);
        }
    };

    CreatureAI *GetAI(Creature *creature) const
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
        mob_novos_minionAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript *pInstance;

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id !=0)
                return;
            if (Creature* pNovos = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_NOVOS) : 0))
            {
                CAST_AI(boss_novos::boss_novosAI, pNovos->AI())->bAchiev = false;
                if (Unit *pTarget = CAST_AI(boss_novos::boss_novosAI, pNovos->AI())->GetRandomTarget())
                    AttackStart(pTarget);
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new mob_novos_minionAI(creature);
    }
};

void AddSC_boss_novos()
{
    new boss_novos;
    new mob_crystal_handler;
    new mob_novos_minion;
}
