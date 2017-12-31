/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
SDName: Boss_Midnight
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "karazhan.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Texts
{
    SAY_KILL          = 0,
    SAY_RANDOM        = 1,
    SAY_DISARMED      = 2,
    SAY_MIDNIGHT_KILL = 3,
    SAY_APPEAR        = 4,
    SAY_MOUNT         = 5,

    SAY_DEATH         = 3,

    // Midnight
    EMOTE_CALL_ATTUMEN = 0,
    EMOTE_MOUNT_UP     = 1
};

enum Spells
{
    // Attumen
    SPELL_SHADOWCLEAVE           = 29832,
    SPELL_INTANGIBLE_PRESENCE    = 29833,
    SPELL_SPAWN_SMOKE            = 10389,
    SPELL_CHARGE                 = 29847,

    // Midnight
    SPELL_KNOCKDOWN              = 29711,
    SPELL_SUMMON_ATTUMEN         = 29714,
    SPELL_MOUNT                  = 29770,
    SPELL_SUMMON_ATTUMEN_MOUNTED = 29799
};

enum Phases
{
    PHASE_NONE,
    PHASE_ATTUMEN_ENGAGES,
    PHASE_MOUNTED
};

class boss_attumen : public CreatureScript
{
public:
    boss_attumen() : CreatureScript("boss_attumen") { }

    struct boss_attumenAI : public BossAI
    {
        boss_attumenAI(Creature* creature) : BossAI(creature, DATA_ATTUMEN)
        {
            Initialize();
        }

        void Initialize()
        {
            _midnightGUID.Clear();
            _phase = PHASE_NONE;
        }

        void Reset() override
        {
            Initialize();
            BossAI::Reset();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (Creature* midnight = ObjectAccessor::GetCreature(*me, _midnightGUID))
                BossAI::_DespawnAtEvade(Seconds(10), midnight);

            me->DespawnOrUnsummon();
        }

        void ScheduleTasks() override
        {
            scheduler.Schedule(Seconds(15), Seconds(25), [this](TaskContext task)
            {
                DoCastVictim(SPELL_SHADOWCLEAVE);
                task.Repeat(Seconds(15), Seconds(25));
            });

            scheduler.Schedule(Seconds(25), Seconds(45), [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target,SPELL_INTANGIBLE_PRESENCE);

                task.Repeat(Seconds(25), Seconds(45));
            });

            scheduler.Schedule(Seconds(30), Seconds(60), [this](TaskContext task)
            {
                Talk(SAY_RANDOM);
                task.Repeat(Seconds(30), Seconds(60));
            });
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            // Attumen does not die until he mounts Midnight, let health fall to 1 and prevent further damage.
            if (damage >= me->GetHealth() && _phase != PHASE_MOUNTED)
                damage = me->GetHealth() - 1;

            if (_phase == PHASE_ATTUMEN_ENGAGES && me->HealthBelowPctDamaged(25, damage))
            {
                _phase = PHASE_NONE;

                if (Creature* midnight = ObjectAccessor::GetCreature(*me, _midnightGUID))
                    midnight->AI()->DoCastAOE(SPELL_MOUNT, true);
            }
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL);
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == NPC_ATTUMEN_MOUNTED)
                if (Creature* midnight = ObjectAccessor::GetCreature(*me, _midnightGUID))
                {
                    if (midnight->GetHealth() > me->GetHealth())
                        summon->SetHealth(midnight->GetHealth());
                    else
                        summon->SetHealth(me->GetHealth());

                    summon->AI()->DoZoneInCombat();
                    summon->AI()->SetGUID(_midnightGUID, NPC_MIDNIGHT);
                }

            BossAI::JustSummoned(summon);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->GetEntry() == NPC_MIDNIGHT)
                _phase = PHASE_ATTUMEN_ENGAGES;

            if (summoner->GetEntry() == NPC_ATTUMEN_UNMOUNTED)
            {
                _phase = PHASE_MOUNTED;
                DoCastSelf(SPELL_SPAWN_SMOKE);

                scheduler.Schedule(Seconds(10), Seconds(25), [this](TaskContext task)
                {
                    Unit* target = nullptr;
                    ThreatContainer::StorageType const &t_list = me->getThreatManager().getThreatList();
                    std::vector<Unit*> target_list;

                    for (ThreatContainer::StorageType::const_iterator itr = t_list.begin(); itr != t_list.end(); ++itr)
                    {
                        target = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid());
                        if (target && !target->IsWithinDist(me, 8.00f, false) && target->IsWithinDist(me, 25.0f, false))
                            target_list.push_back(target);

                        target = nullptr;
                    }

                    if (!target_list.empty())
                        target = Trinity::Containers::SelectRandomContainerElement(target_list);

                    DoCast(target, SPELL_CHARGE);
                    task.Repeat(Seconds(10), Seconds(25));
                });

                scheduler.Schedule(Seconds(25), Seconds(35), [this](TaskContext task)
                {
                    DoCastVictim(SPELL_KNOCKDOWN);
                    task.Repeat(Seconds(25), Seconds(35));
                });
            }
        }

        void JustDied(Unit* killer) override
        {
            Talk(SAY_DEATH);
            if (Unit* midnight = ObjectAccessor::GetUnit(*me, _midnightGUID))
                midnight->KillSelf();

            BossAI::JustDied(killer);
        }

        void SetGUID(ObjectGuid guid, int32 data) override
        {
            if (data == NPC_MIDNIGHT)
                _midnightGUID = guid;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && _phase != PHASE_NONE)
                return;

            scheduler.Update(diff,
                std::bind(&BossAI::DoMeleeAttackIfReady, this));
        }

        void SpellHit(Unit* /*source*/, const SpellInfo* spell) override
        {
            if (spell->Mechanic == MECHANIC_DISARM)
                Talk(SAY_DISARMED);

            if (spell->Id == SPELL_MOUNT)
            {
                if (Creature* midnight = ObjectAccessor::GetCreature(*me, _midnightGUID))
                {
                    _phase = PHASE_NONE;
                    scheduler.CancelAll();

                    midnight->AttackStop();
                    midnight->RemoveAllAttackers();
                    midnight->SetReactState(REACT_PASSIVE);
                    midnight->GetMotionMaster()->MoveChase(me);
                    midnight->AI()->Talk(EMOTE_MOUNT_UP);

                    me->AttackStop();
                    me->RemoveAllAttackers();
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MoveChase(midnight);
                    Talk(SAY_MOUNT);

                    scheduler.Schedule(Seconds(3), [this](TaskContext task)
                    {
                        if (Creature* midnight = ObjectAccessor::GetCreature(*me, _midnightGUID))
                        {
                            if (me->IsWithinMeleeRange(midnight))
                            {
                                DoCastAOE(SPELL_SUMMON_ATTUMEN_MOUNTED);
                                me->SetVisible(false);
                                midnight->SetVisible(false);
                            }
                            else
                            {
                                midnight->GetMotionMaster()->MoveChase(me);
                                me->GetMotionMaster()->MoveChase(midnight);
                                task.Repeat(Seconds(3));
                            }
                        }
                    });
                }
            }
        }

    private:
        ObjectGuid _midnightGUID;
        uint8 _phase;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<boss_attumenAI>(creature);
    }
};

class boss_midnight : public CreatureScript
{
public:
    boss_midnight() : CreatureScript("boss_midnight") { }

    struct boss_midnightAI : public BossAI
    {
        boss_midnightAI(Creature* creature) : BossAI(creature, DATA_ATTUMEN)
        {
            Initialize();
        }

        void Initialize()
        {
            _phase = PHASE_NONE;
        }

        void Reset() override
        {
            Initialize();
            BossAI::Reset();
            me->SetVisible(true);
            me->SetReactState(REACT_DEFENSIVE);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            // Midnight never dies, let health fall to 1 and prevent further damage.
            if (damage >= me->GetHealth())
                damage = me->GetHealth() - 1;

            if (_phase == PHASE_NONE && me->HealthBelowPctDamaged(95, damage))
            {
                _phase = PHASE_ATTUMEN_ENGAGES;
                Talk(EMOTE_CALL_ATTUMEN);
                DoCastAOE(SPELL_SUMMON_ATTUMEN);
            }
            else if (_phase == PHASE_ATTUMEN_ENGAGES && me->HealthBelowPctDamaged(25, damage))
            {
                _phase = PHASE_MOUNTED;
                DoCastAOE(SPELL_MOUNT, true);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == NPC_ATTUMEN_UNMOUNTED)
            {
                _attumenGUID = summon->GetGUID();
                summon->AI()->SetGUID(me->GetGUID(), NPC_MIDNIGHT);
                summon->AI()->AttackStart(me->GetVictim());
                summon->AI()->Talk(SAY_APPEAR);
            }

            BossAI::JustSummoned(summon);
        }

        void EnterCombat(Unit* who) override
        {
            BossAI::EnterCombat(who);

            scheduler.Schedule(Seconds(15), Seconds(25), [this](TaskContext task)
            {
                DoCastVictim(SPELL_KNOCKDOWN);
                task.Repeat(Seconds(15), Seconds(25));
            });
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            BossAI::_DespawnAtEvade(Seconds(10));
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (_phase == PHASE_ATTUMEN_ENGAGES)
            {
                if (Unit* unit = ObjectAccessor::GetUnit(*me, _attumenGUID))
                    Talk(SAY_MIDNIGHT_KILL, unit);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || _phase == PHASE_MOUNTED)
                return;

            scheduler.Update(diff,
                std::bind(&BossAI::DoMeleeAttackIfReady, this));
        }

        private:
            ObjectGuid _attumenGUID;
            uint8 _phase;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetKarazhanAI<boss_midnightAI>(creature);
    }
};

void AddSC_boss_attumen()
{
    new boss_attumen();
    new boss_midnight();
}
