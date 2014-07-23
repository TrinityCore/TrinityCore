/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "magisters_terrace.h"

enum Says
{
    SAY_AGGRO                       = 0,
    SAY_ENERGY                      = 1,
    SAY_EMPOWERED                   = 2,
    SAY_KILL                        = 3,
    SAY_DEATH                       = 4,
    EMOTE_CRYSTAL                   = 5
};

enum Spells
{
    // Crystal effect spells
    SPELL_FEL_CRYSTAL_DUMMY         = 44329,
    SPELL_MANA_RAGE                 = 44320,               // This spell triggers 44321, which changes scale and regens mana Requires an entry in spell_script_target

    // Selin's spells
    SPELL_DRAIN_LIFE                = 44294,
    SPELL_FEL_EXPLOSION             = 44314,

    SPELL_DRAIN_MANA                = 46153               // Heroic only
};

enum Phases
{
    PHASE_NORMAL                    = 1,
    PHASE_DRAIN                     = 2
};

enum Events
{
    EVENT_FEL_EXPLOSION             = 1,
    EVENT_DRAIN_CRYSTAL,
    EVENT_DRAIN_MANA,
    EVENT_DRAIN_LIFE,
    EVENT_EMPOWER
};

enum Misc
{
    ACTION_SWITCH_PHASE             = 1
};

class boss_selin_fireheart : public CreatureScript
{
    public:
        boss_selin_fireheart() : CreatureScript("boss_selin_fireheart") { }

        struct boss_selin_fireheartAI : public BossAI
        {
            boss_selin_fireheartAI(Creature* creature) : BossAI(creature, DATA_SELIN)
            {
                CrystalGUID = 0;
                _scheduledEvents = false;
            }

            void Reset() override
            {
                Crystals.clear();
                me->GetCreatureListWithEntryInGrid(Crystals, NPC_FEL_CRYSTAL, 250.0f);

                for (Creature* creature : Crystals)
                {
                    if (!creature->IsAlive())
                        creature->Respawn();

                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }

                _Reset();
                CrystalGUID = 0;
                _scheduledEvents = false;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_SWITCH_PHASE:
                        events.SetPhase(PHASE_NORMAL);
                        events.ScheduleEvent(EVENT_FEL_EXPLOSION, 2000, 0, PHASE_NORMAL);
                        AttackStart(me->GetVictim());
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                        break;
                    default:
                        break;
                }
            }

            void SelectNearestCrystal()
            {
                if (Crystals.empty())
                    return;

                Crystals.sort(Trinity::ObjectDistanceOrderPred(me));
                if (Creature* CrystalChosen = Crystals.front())
                {
                    Talk(SAY_ENERGY);
                    Talk(EMOTE_CRYSTAL);

                    DoCast(CrystalChosen, SPELL_FEL_CRYSTAL_DUMMY);
                    CrystalGUID = CrystalChosen->GetGUID();
                    Crystals.remove(CrystalChosen);

                    float x, y, z;
                    CrystalChosen->GetClosePoint(x, y, z, me->GetObjectSize(), CONTACT_DISTANCE);

                    events.SetPhase(PHASE_DRAIN);
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(1, x, y, z);
                }
            }

            void ShatterRemainingCrystals()
            {
                if (Crystals.empty())
                    return;

                for (Creature* crystal : Crystals)
                {
                    if (crystal && crystal->IsAlive())
                        crystal->Kill(crystal);
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();

                events.SetPhase(PHASE_NORMAL);
                events.ScheduleEvent(EVENT_FEL_EXPLOSION, 2100, 0, PHASE_NORMAL);
             }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == 1)
                {
                    Unit* CrystalChosen = ObjectAccessor::GetUnit(*me, CrystalGUID);
                    if (CrystalChosen && CrystalChosen->IsAlive())
                    {
                        CrystalChosen->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        CrystalChosen->CastSpell(me, SPELL_MANA_RAGE, true);
                        events.ScheduleEvent(EVENT_EMPOWER, 10000, PHASE_DRAIN);
                    }
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();

                ShatterRemainingCrystals();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FEL_EXPLOSION:
                            DoCastAOE(SPELL_FEL_EXPLOSION);
                            events.ScheduleEvent(EVENT_FEL_EXPLOSION, 2000, 0, PHASE_NORMAL);
                            break;
                        case EVENT_DRAIN_CRYSTAL:
                            SelectNearestCrystal();
                            _scheduledEvents = false;
                            break;
                        case EVENT_DRAIN_MANA:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                                DoCast(target, SPELL_DRAIN_MANA);
                            events.ScheduleEvent(EVENT_DRAIN_MANA, 10000, 0, PHASE_NORMAL);
                            break;
                        case EVENT_DRAIN_LIFE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                                DoCast(target, SPELL_DRAIN_LIFE);
                            events.ScheduleEvent(EVENT_DRAIN_LIFE, 10000, 0, PHASE_NORMAL);
                            break;
                        case EVENT_EMPOWER:
                        {
                            Talk(SAY_EMPOWERED);

                            Creature* CrystalChosen = ObjectAccessor::GetCreature(*me, CrystalGUID);
                            if (CrystalChosen && CrystalChosen->IsAlive())
                                CrystalChosen->Kill(CrystalChosen);

                            CrystalGUID = 0;

                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveChase(me->GetVictim());
                            break;
                        }
                        default:
                            break;
                    }
                }

                if (me->GetPower(POWER_MANA) * 100 / me->GetMaxPower(POWER_MANA) < 10)
                {
                    if (events.IsInPhase(PHASE_NORMAL) && !_scheduledEvents)
                    {
                        _scheduledEvents = true;
                        uint32 timer = urand(3000, 7000);
                        events.ScheduleEvent(EVENT_DRAIN_LIFE, timer, 0, PHASE_NORMAL);

                        if (IsHeroic())
                        {
                            events.ScheduleEvent(EVENT_DRAIN_CRYSTAL, urand(10000, 15000), 0, PHASE_NORMAL);
                            events.ScheduleEvent(EVENT_DRAIN_MANA, timer + 5000, 0, PHASE_NORMAL);
                        }
                        else
                            events.ScheduleEvent(EVENT_DRAIN_CRYSTAL, urand(20000, 25000), 0, PHASE_NORMAL);
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            std::list<Creature*> Crystals;
            uint64 CrystalGUID;
            bool _scheduledEvents;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_selin_fireheartAI>(creature);
        };
};

class npc_fel_crystal : public CreatureScript
{
    public:
        npc_fel_crystal() : CreatureScript("npc_fel_crystal") { }

        struct npc_fel_crystalAI : public ScriptedAI
        {
            npc_fel_crystalAI(Creature* creature) : ScriptedAI(creature) { }

            void JustDied(Unit* /*killer*/) override
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                {
                    Creature* Selin = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_SELIN));
                    if (Selin && Selin->IsAlive())
                        Selin->AI()->DoAction(ACTION_SWITCH_PHASE);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<npc_fel_crystalAI>(creature);
        };
};

void AddSC_boss_selin_fireheart()
{
    new boss_selin_fireheart();
    new npc_fel_crystal();
}
