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

#include "scarlet_monastery.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "Timer.h"

enum MograineAndWhitemaneSays
{
    // Mograine
    SAY_MO_AGGRO       = 0,
    SAY_MO_KILL        = 1,
    SAY_MO_RESURRECTED = 2,

    // Whitemaine
    SAY_WH_INTRO       = 0,
    SAY_WH_KILL        = 1,
    SAY_WH_RESURRECT   = 2,
};

enum MograineAndWhitemaneSpells
{
    // Mograine Spells
    SPELL_CRUSADER_STRIKE      = 14518,
    SPELL_HAMMER_OF_JUSTICE    = 5589,
    SPELL_LAY_ONHANDS          = 9257,
    SPELL_RETRIBUTION_AURA     = 8990,

    // Whitemane Spells
    SPELL_DEEP_SLEEP           = 9256,
    SPELL_SCARLET_RESURRECTION = 9232,
    SPELL_DOMINATE_MIND        = 14515,
    SPELL_HOLY_SMITE           = 9481,
    SPELL_HEAL                 = 12039,
    SPELL_POWER_WORD_SHIELD    = 22187
};

enum MograineAndWhitemaneEvents
{
    // Mograine
    EVENT_CRUSADER_STRIKE = 1,
    EVENT_HAMMER_OF_JUSTICE,

    // Whitemane
    EVENT_HEAL = 1,
    EVENT_POWER_WORD_SHIELD,
    EVENT_HOLY_SMITE,
};

enum MograineAndWhitemanePoints
{
    POINT_WHITEMANE_MOVE_TO_MOGRAINE = 1,
};

Position const WhitemaneIntroMovePos = { 1163.113370f, 1398.856812f, 32.527786f, 0.f };

// Scarlet Commander Mograine - 3976
struct boss_scarlet_commander_mograine : public BossAI
{
public:
    boss_scarlet_commander_mograine(Creature* creature) : BossAI(creature, DATA_MOGRAINE_AND_WHITE_EVENT), _killYellTimer(0s)
    {
        Initialize();
    }

    void Initialize()
    {
        _fakeDeath = false;
        _canDie = true;
    }

    void Reset() override
    {
        Initialize();

        _Reset();
        _killYellTimer.Reset(0s);

        DoCastSelf(SPELL_RETRIBUTION_AURA, true);
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_NON_ATTACKABLE);
        me->SetStandState(UNIT_STAND_STATE_STAND);
        me->SetReactState(REACT_AGGRESSIVE);

        instance->HandleGameObject(ObjectGuid::Empty, false, instance->GetGameObject(DATA_HIGH_INQUISITORS_DOOR));
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_MO_AGGRO);

        // Call for help (from old script)
        me->CallForHelp(VISIBLE_RANGE);

        // Just to be sure it's MOTION_SLOT_DEFAULT is static
        me->GetMotionMaster()->MoveIdle();

        // Schedule events
        events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 10s, 15s);
        events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 10s, 15s);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() != TYPEID_PLAYER)
            return;

        if (_killYellTimer.Passed())
        {
            Talk(SAY_MO_KILL);
            _killYellTimer.Reset(5s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_CRUSADER_STRIKE:
                DoCastVictim(SPELL_CRUSADER_STRIKE);
                events.Repeat(10s);
                break;
            case EVENT_HAMMER_OF_JUSTICE:
                DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
                events.Repeat(60s);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && !_fakeDeath)
        {
            _fakeDeath = true;
            _canDie = false;

            // Open the door
            instance->HandleGameObject(ObjectGuid::Empty, true, instance->GetGameObject(DATA_HIGH_INQUISITORS_DOOR));

            // Tell whitemane to move
            if (Creature* whitemane = instance->GetCreature(DATA_WHITEMANE))
            {
                whitemane->GetMotionMaster()->MovePoint(0, WhitemaneIntroMovePos);
                DoZoneInCombat(whitemane);
            }

            me->InterruptNonMeleeSpells(true);
            me->ClearComboPointHolders();
            me->RemoveAllAuras();
            me->ClearAllReactives();
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetStandState(UNIT_STAND_STATE_DEAD);
            me->SetReactState(REACT_PASSIVE); // prevent Mograine from attacking while fake death

            // Stop moving
            me->GetMotionMaster()->Clear();
        }

        if (!_canDie && damage >= me->GetHealth())
            damage = 0;
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        // Casted from Whitemane
        if (spellInfo->Id == SPELL_SCARLET_RESURRECTION)
        {
            scheduler.Schedule(3s, [this](TaskContext /*context*/)
            {
                // Say text
                Talk(SAY_MO_RESURRECTED);

                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetStandState(UNIT_STAND_STATE_STAND);
            });

            scheduler.Schedule(5s, [this](TaskContext /*context*/)
            {
                // Schedule events after ressurrect
                events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 10s, 15s);
                events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 10s, 15s);

                // We can now die
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                _canDie = true;
                DoCastSelf(SPELL_RETRIBUTION_AURA, true);
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        scheduler.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    TimeTracker _killYellTimer;
    bool _fakeDeath;
    bool _canDie;
};

// High Inquisitor Whitemane - 3977
struct boss_high_inquisitor_whitemane : public ScriptedAI
{
public:
    boss_high_inquisitor_whitemane(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _killYellTimer(0s)
    {
        Initialize();
    }

    void Initialize()
    {
        _ressurectionInProgress = false;
        _canDie = true;
    }

    void Reset() override
    {
        Initialize();

        _events.Reset();
        _scheduler.CancelAll();
        _killYellTimer.Reset(0s);

        DoCastSelf(SPELL_RETRIBUTION_AURA);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_WH_INTRO);

        // Just to be sure it's MOTION_SLOT_DEFAULT is static
        me->GetMotionMaster()->MoveIdle();

        // Start events after 5 seconds
        _scheduler.Schedule(5s, [this](TaskContext /*context*/)
        {
            _events.ScheduleEvent(EVENT_HEAL, 10s);
            _events.ScheduleEvent(EVENT_POWER_WORD_SHIELD, 15s);
            _events.ScheduleEvent(EVENT_HOLY_SMITE, 6s);
        });
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() != TYPEID_PLAYER)
            return;

        if (_killYellTimer.Passed())
        {
            Talk(SAY_WH_KILL);
            _killYellTimer.Reset(5s);
        }
    }

    void UpdateAI(const uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);
        _scheduler.Update(diff);

        if (!_killYellTimer.Passed())
            _killYellTimer.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HEAL:
                {
                    Creature* target = nullptr;
                    if (HealthBelowPct(75))
                        target = me;
                    else if (Creature* mograine = _instance->GetCreature(DATA_MOGRAINE))
                    {
                        if (mograine->IsAlive() && mograine->HealthBelowPct(75))
                            target = mograine;
                    }

                    if (target)
                        DoCast(target, SPELL_HEAL);

                    _events.Repeat(13s);
                    break;
                }
                case EVENT_POWER_WORD_SHIELD:
                    DoCastSelf(SPELL_POWER_WORD_SHIELD);
                    _events.Repeat(15s);
                    break;
                case EVENT_HOLY_SMITE:
                    DoCastVictim(SPELL_HOLY_SMITE);
                    _events.Repeat(6s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        if (me->HasReactState(REACT_AGGRESSIVE))
            DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // When Whitemane falls below 50% cast Deep sleep and schedule to ressurrect
        if (me->HealthBelowPctDamaged(50, damage) && !_ressurectionInProgress)
        {
            _ressurectionInProgress = true;
            _canDie = false;

            // Cancel all combat events
            _events.CancelEvent(EVENT_HEAL);
            _events.CancelEvent(EVENT_POWER_WORD_SHIELD);
            _events.CancelEvent(EVENT_HOLY_SMITE);

            me->InterruptNonMeleeSpells(true);

            // Sleep all players
            DoCastAOE(SPELL_DEEP_SLEEP);

            if (Creature* mograine = _instance->GetCreature(DATA_MOGRAINE))
            {
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);

                Position movePosition = mograine->GetPosition();

                // Get a position within 2 yards of mograine, and facing him
                me->MovePosition(movePosition, 2.0f, me->GetRelativeAngle(movePosition));
                me->GetMotionMaster()->MovePoint(POINT_WHITEMANE_MOVE_TO_MOGRAINE, movePosition);
            }
        }

        if (!_canDie && damage >= me->GetHealth())
            damage = 0;
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE || id != POINT_WHITEMANE_MOVE_TO_MOGRAINE)
            return;

        if (Creature* mograine = _instance->GetCreature(DATA_MOGRAINE))
            me->SetFacingToObject(mograine);

        // After 3 seconds cast scarlet ressurection
        _scheduler.Schedule(3s, [this](TaskContext /*context*/)
        {
            if (Creature* mograine = _instance->GetCreature(DATA_MOGRAINE))
                DoCast(mograine, SPELL_SCARLET_RESURRECTION);
            else
                MograineResurrected();
        });
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (target->GetEntry() == NPC_MOGRAINE && spellInfo->Id == SPELL_SCARLET_RESURRECTION)
            MograineResurrected();
    }

private:
    void MograineResurrected()
    {
        Talk(SAY_WH_RESURRECT);

        // Schedule events again
        _events.ScheduleEvent(EVENT_HEAL, 10s);
        _events.ScheduleEvent(EVENT_POWER_WORD_SHIELD, 15s);
        _events.ScheduleEvent(EVENT_HOLY_SMITE, 6s);

        _canDie = true;

        me->SetReactState(REACT_AGGRESSIVE);

        if (me->GetVictim())
            me->GetMotionMaster()->MoveChase(me->GetVictim());
    }

    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
    TimeTracker _killYellTimer;
    bool _ressurectionInProgress;
    bool _canDie;
};

void AddSC_boss_mograine_and_whitemane()
{
    RegisterScarletMonasteryCreatureAI(boss_scarlet_commander_mograine);
    RegisterScarletMonasteryCreatureAI(boss_high_inquisitor_whitemane);
}
