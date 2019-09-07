/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "GameTime.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "scarlet_monastery.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum Says
{
    /// Mograine
    SAY_MO_AGGRO                 = 0,
    SAY_MO_KILL                  = 1,
    SAY_MO_RESURRECTED           = 2,

    /// Whitemaine
    SAY_WH_INTRO                 = 0,
    SAY_WH_KILL                  = 1,
    SAY_WH_RESURRECT             = 2,
};

enum Spells
{
    /// Mograine Spells
    SPELL_CRUSADER_STRIKE        = 14518,
    SPELL_HAMMER_OF_JUSTICE      = 5589,
    SPELL_LAYONHANDS             = 9257,
    SPELL_RETRIBUTIONAURA        = 8990,

    /// Whitemane Spells
    SPELL_DEEPSLEEP              = 9256,
    SPELL_SCARLETRESURRECTION    = 9232,
    SPELL_DOMINATEMIND           = 14515,
    SPELL_HOLYSMITE              = 9481,
    SPELL_HEAL                   = 12039,
    SPELL_POWERWORDSHIELD        = 22187
};

enum Events
{
    /// Mograine
    EVENT_CRUSADER_STRIKE = 1,
    EVENT_HAMMER_OF_JUSTICE,

    /// Whitemane
    EVENT_HEAL = 1,
    EVENT_POWER_WORD_SHIELD,
    EVENT_HOLY_SMITE,
};

enum Points
{
    POINT_WHITEMANE_MOVE_TO_MOGRAINE = 1,
};

const Position WhitemaneIntroMovePos(1163.113370f, 1398.856812f, 32.527786f);

/// Scarlet Commander Mograine - 3976
struct boss_scarlet_commander_mograine : public ScriptedAI
{
    public:
        boss_scarlet_commander_mograine(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            m_LastKillTime = 0;
            m_CanDie       = false;
            m_FakeDeath    = false;
        }

        void Reset() override
        {
            Initialize();

            events.Reset();
            scheduler.CancelAll();

            DoCast(me, SPELL_RETRIBUTIONAURA);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetReactState(REACT_AGGRESSIVE);

            // Close the door
            if (auto instance = me->GetInstanceScript())
                instance->HandleGameObject(instance->GetGuidData(GO_HIGH_INQUISITORS_DOOR), false);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_MO_AGGRO);

            // Call for help (from old script)
            me->CallForHelp(VISIBLE_RANGE);

            // Schedule events
            events.ScheduleEvent(EVENT_CRUSADER_STRIKE, Seconds(10), Seconds(15));
            events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, Seconds(10), Seconds(15));
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            // Cooldown between talking
            time_t currTime = GameTime::GetGameTime();

            if (m_LastKillTime < currTime)
            {
                Talk(SAY_MO_KILL);
                m_LastKillTime = currTime + 5;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            scheduler.Update(diff);
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CRUSADER_STRIKE:
                        DoCastVictim(SPELL_CRUSADER_STRIKE);
                        events.Repeat(Seconds(10));
                        break;
                    case EVENT_HAMMER_OF_JUSTICE:
                        DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
                        events.Repeat(Seconds(60));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            if (damage >= me->GetHealth() && !m_FakeDeath)
            {
                m_FakeDeath = true;

                // Get instance script
                if (auto instance = me->GetInstanceScript())
                {
                    // Stop moving
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveIdle();

                    // Open the door
                    instance->HandleGameObject(instance->GetGuidData(GO_HIGH_INQUISITORS_DOOR), true);

                    // Tell whitemane to move
                    if (auto whitemane = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_WHITEMANE)))
                    {
                        DoZoneInCombat(whitemane);

                        whitemane->GetMotionMaster()->Clear();
                        whitemane->GetMotionMaster()->MovePoint(0, WhitemaneIntroMovePos);
                    }

                    // Interrupt spells and clear auras
                    if (me->IsNonMeleeSpellCast(false))
                        me->InterruptNonMeleeSpells(false);

                    me->ClearComboPointHolders();
                    me->RemoveAllAuras();
                    me->ClearAllReactives();

                    // Set fake death flags
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->SetReactState(REACT_PASSIVE); // prevent mograine from attacking while fake death
                }
            }

            if (!m_CanDie && damage >= me->GetHealth())
                damage = 0;
        }

        void SpellHit(Unit* /*who*/, SpellInfo const* spell) override
        {
            // Casted from Whitemane
            if (spell->Id == SPELL_SCARLETRESURRECTION)
            {
                scheduler.Schedule(Seconds(3), [this](TaskContext /*context*/)
                {
                    // Say text
                    Talk(SAY_MO_RESURRECTED);

                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                });

                scheduler.Schedule(Seconds(5), [this](TaskContext /*context*/)
                {
                    // Schedule events after ressurrect
                    events.ScheduleEvent(EVENT_CRUSADER_STRIKE, Seconds(10), Seconds(15));
                    events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, Seconds(10), Seconds(15));

                    // We can now die
                    me->SetReactState(REACT_AGGRESSIVE);
                    m_CanDie = true;
                });
            }
        }

    private:
        /// Timers
        EventMap      events;
        TaskScheduler scheduler;

        /// Variables
        time_t m_LastKillTime;
        bool   m_FakeDeath;
        bool   m_CanDie;
};

/// High Inquisitor Whitemane - 3977
struct boss_high_inquisitor_whitemane : public ScriptedAI
{
    public:
        boss_high_inquisitor_whitemane(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            m_LastKillTime           = 0;
            m_RessurectionInProgress = false;
            m_CanDie                 = false;
        }

        void Reset() override
        {
            events.Reset();
            scheduler.CancelAll();

            DoCast(me, SPELL_RETRIBUTIONAURA);
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_WH_INTRO);

            // Start events after 5 seconds
            scheduler.Schedule(Seconds(5), [this](TaskContext /*context*/)
            {
                events.ScheduleEvent(EVENT_HEAL, Seconds(10));
                events.ScheduleEvent(EVENT_POWER_WORD_SHIELD, Seconds(15));
                events.ScheduleEvent(EVENT_HOLY_SMITE, Seconds(6));
            });
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            // Cooldown between talking
            time_t currTime = GameTime::GetGameTime();

            if (m_LastKillTime < currTime)
            {
                Talk(SAY_MO_KILL);
                m_LastKillTime = currTime + 5;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);
            scheduler.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HEAL:
                    {
                        Creature* target = nullptr;

                        if (HealthBelowPct(75))
                            target = me;
                        else if (auto instance = me->GetInstanceScript())
                        {
                            if (auto mograine = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_MOGRAINE)))
                                if (mograine->IsAlive() && mograine->HealthBelowPct(75))
                                    target = mograine;
                        }

                        if (target)
                            DoCast(target, SPELL_HEAL);

                        events.Repeat(Seconds(13));
                        break;
                    }
                    case EVENT_POWER_WORD_SHIELD:
                        DoCastSelf(SPELL_POWERWORDSHIELD);
                        events.Repeat(Seconds(15));
                        break;
                    case EVENT_HOLY_SMITE:
                        DoCastVictim(SPELL_HOLYSMITE);
                        events.Repeat(Seconds(6));
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*who*/, uint32& damage) override
        {
            // When Whitemane falls below 50% cast Deep sleep and schedule to ressurrect
            if (me->HealthBelowPctDamaged(50, damage) && !m_RessurectionInProgress)
            {
                m_RessurectionInProgress = true;

                // Cancel all combat events
                events.CancelEvent(EVENT_HEAL);
                events.CancelEvent(EVENT_POWER_WORD_SHIELD);
                events.CancelEvent(EVENT_HOLY_SMITE);

                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                // Sleep all players
                DoCastAOE(SPELL_DEEPSLEEP);

                // Move to mograine
                if (auto instance = me->GetInstanceScript())
                {
                    if (auto mograine = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_MOGRAINE)))
                    {
                        // Stop moving
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->Clear();

                        Position pos = *mograine;

                        // Get a position within 2 yards of mograine, and facing him
                        me->MovePosition(pos, 2.0f, me->GetRelativeAngle(*mograine));

                        me->GetMotionMaster()->MovePoint(POINT_WHITEMANE_MOVE_TO_MOGRAINE, pos);
                    }
                }
            }

            if (!m_CanDie && damage >= me->GetHealth())
                damage = 0;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == POINT_WHITEMANE_MOVE_TO_MOGRAINE)
            {
                if (auto instance = me->GetInstanceScript())
                    if (auto mograine = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_MOGRAINE)))
                        me->SetFacingToObject(mograine);

                // After 3 seconds cast scarlet ressurection
                scheduler.Schedule(Seconds(3), [this](TaskContext /*context*/)
                {
                    if (auto instance = me->GetInstanceScript())
                        if (auto mograine = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_MOGRAINE)))
                            DoCast(mograine, SPELL_SCARLETRESURRECTION);
                });

                // After 5 seconds or when finish cast spell, say Arise my champion.. (Maybe this belongs in an OnSuccessfulCastSpell hook? .. if that exists
                scheduler.Schedule(Seconds(5), [this](TaskContext /*context*/)
                {
                    Talk(SAY_WH_RESURRECT);

                    // Schedule events again
                    events.ScheduleEvent(EVENT_HEAL, Seconds(10));
                    events.ScheduleEvent(EVENT_POWER_WORD_SHIELD, Seconds(15));
                    events.ScheduleEvent(EVENT_HOLY_SMITE, Seconds(6));

                    m_CanDie = true;
                    me->SetReactState(REACT_AGGRESSIVE);
                });
            }
        }

    private:
        /// Timers
        EventMap      events;
        TaskScheduler scheduler;

        /// Variables
        time_t m_LastKillTime;
        bool   m_RessurectionInProgress;
        bool   m_CanDie;
};

void AddSC_boss_mograine_and_whitemane()
{
    RegisterScarletMonastaryCreatureAI(boss_scarlet_commander_mograine);
    RegisterScarletMonastaryCreatureAI(boss_high_inquisitor_whitemane);
}
