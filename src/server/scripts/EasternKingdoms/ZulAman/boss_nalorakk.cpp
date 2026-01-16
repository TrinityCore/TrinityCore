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
 * Creatures in waves should load waypoints, not engage immediately
 * Surge implementation requires additional research
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "zulaman.h"

enum NalorakkTexts
{
    SAY_WAVE_1                      = 0,
    SAY_WAVE_2                      = 1,
    SAY_WAVE_3                      = 2,
    SAY_WAVE_4                      = 3,
    SAY_WAVE_DONE                   = 4,
    SAY_AGGRO                       = 5,
    SAY_SURGE                       = 6,
    SAY_TO_BEAR                     = 7,
    SAY_TO_TROLL                    = 8,
    SAY_BERSERK                     = 9,
    SAY_SLAY                        = 10,
    SAY_DEATH                       = 11,
    SAY_EVENT_1                     = 12,      // NYI
    SAY_EVENT_2                     = 13,      // NYI
    EMOTE_TRANSFORM                 = 14
};

enum NalorakkSpells
{
    // Troll form
    SPELL_BRUTAL_SWIPE              = 42384,
    SPELL_MANGLE                    = 42389,
    SPELL_SURGE                     = 44019,

    // Bear form
    SPELL_LACERATING_SLASH          = 42395,
    SPELL_REND_FLESH                = 42397,
    SPELL_DEAFENING_ROAR            = 42398,

    // Shared
    SPELL_SHAPE_OF_THE_BEAR         = 42377,
    SPELL_BERSERK                   = 45078,

    // Scripts
    SPELL_SURGE_CHARGE              = 42402,
    SPELL_SURGE_HASTE               = 44960
};

enum NalorakkEvents
{
    // Waves
    EVENT_WAVE_DONE_1               = 1,
    EVENT_WAVE_DONE_2,
    EVENT_WAVE_DONE_3,
    EVENT_WAVE_DONE_4,

    // Troll form
    EVENT_BRUTAL_SWIPE,
    EVENT_MANGLE,
    EVENT_SURGE,

    // Bear form
    EVENT_LACERATING_SLASH,
    EVENT_REND_FLESH,
    EVENT_DEAFENING_ROAR,

    // Shared
    EVENT_SHAPESHIFT,
    EVENT_BERSERK
};

enum NalorakkSpawnGroups
{
    SPAWN_GROUP_NALORAKK_WAVE_1     = 329,
    SPAWN_GROUP_NALORAKK_WAVE_2     = 330,
    SPAWN_GROUP_NALORAKK_WAVE_3     = 331,
    SPAWN_GROUP_NALORAKK_WAVE_4     = 332
};

enum NalorakkPaths
{
    PATH_WAVE_DONE_1                = 1,
    PATH_WAVE_DONE_2                = 2,
    PATH_WAVE_DONE_3                = 3
};

static constexpr std::array<uint8, 4> WaveTexts =
{
    SAY_WAVE_1,
    SAY_WAVE_2,
    SAY_WAVE_3,
    SAY_WAVE_4
};

static constexpr std::array<std::string_view, 4> NalorakkWave =
{
    "NalorakkWave1",
    "NalorakkWave2",
    "NalorakkWave3",
    "NalorakkWave4"
};

// 23576 - Nalorakk
struct boss_nalorakk : public BossAI
{
    boss_nalorakk(Creature* creature) : BossAI(creature, BOSS_NALORAKK),
        _waveEventInProgress(true), _isMovingToLocation(false), _isWaiting(false), _isInBearForm(false), _currentWaveCount(0) { }

    void Reset() override
    {
        _Reset();
        SetEquipmentSlots(true);
        _isInBearForm = false;

        if (_waveEventInProgress)
        {
            me->SetImmuneToAll(true);
            me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_NALORAKK_WAVE_1, true);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_BRUTAL_SWIPE, 10s, 20s);
        events.ScheduleEvent(EVENT_MANGLE, 5s, 15s);
        events.ScheduleEvent(EVENT_SURGE, 20s, 25s);
        events.ScheduleEvent(EVENT_SHAPESHIFT, 45s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SHAPE_OF_THE_BEAR:
                Talk(SAY_TO_BEAR);
                Talk(EMOTE_TRANSFORM);
                SetEquipmentSlots(false, EQUIP_NO_CHANGE, EQUIP_UNEQUIP, EQUIP_NO_CHANGE);
                break;
            case SPELL_SURGE:
                Talk(SAY_SURGE);
                break;
            case SPELL_BERSERK:
                Talk(SAY_BERSERK);
                break;
            default:
                break;
        }
    }

    void HandleWave(Unit* who)
    {
        Talk(WaveTexts[_currentWaveCount]);

        std::vector<Creature*> waveCreatures;
        GetCreatureListWithOptionsInGrid(waveCreatures, me, 50.0f, { .StringId = NalorakkWave[_currentWaveCount] });
        for (Creature* waveCreature : waveCreatures)
        {
            waveCreature->SetImmuneToAll(false);
            waveCreature->AI()->AttackStart(who);
        }

        ++_currentWaveCount;
        _isWaiting = true;
    }

    /// @todo: Handle this with GameObjects 186274, 186275, 186276, 186277
    void MoveInLineOfSight(Unit* who) override
    {
        if (!_waveEventInProgress)
        {
            BossAI::MoveInLineOfSight(who);
            return;
        }

        if (!me->IsHostileTo(who))
            return;

        if (_isMovingToLocation)
            return;

        if (_isWaiting)
            return;

        switch (_currentWaveCount)
        {
            case 0:
                if (me->IsWithinDistInMap(who, 50))
                    HandleWave(who);
                break;
            case 1:
                if (me->IsWithinDistInMap(who, 40))
                    HandleWave(who);
                break;
            case 2:
                if (me->IsWithinDistInMap(who, 40))
                    HandleWave(who);
                break;
            case 3:
                if (me->IsWithinDistInMap(who, 60))
                    HandleWave(who);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_WAVE_DONE_1:
                Talk(SAY_WAVE_DONE);
                _isMovingToLocation = true;
                _isWaiting = false;
                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_NALORAKK_WAVE_2, true);
                events.ScheduleEvent(EVENT_WAVE_DONE_1, 2s);
                break;
            case ACTION_WAVE_DONE_2:
                Talk(SAY_WAVE_DONE);
                _isMovingToLocation = true;
                _isWaiting = false;
                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_NALORAKK_WAVE_3, true);
                events.ScheduleEvent(EVENT_WAVE_DONE_2, 2s);
                break;
            case ACTION_WAVE_DONE_3:
                Talk(SAY_WAVE_DONE);
                _isMovingToLocation = true;
                _isWaiting = false;
                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_NALORAKK_WAVE_4, true);
                events.ScheduleEvent(EVENT_WAVE_DONE_3, 2s);
                break;
            case ACTION_WAVE_DONE_4:
                events.ScheduleEvent(EVENT_WAVE_DONE_4, 0s);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        _isMovingToLocation = false;
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void UpdateOutOfCombatEvents(uint32 diff)
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WAVE_DONE_1:
                    me->GetMotionMaster()->MovePath(PATH_WAVE_DONE_1, false);
                    break;
                case EVENT_WAVE_DONE_2:
                    me->GetMotionMaster()->MovePath(PATH_WAVE_DONE_2, false);
                    break;
                case EVENT_WAVE_DONE_3:
                    me->GetMotionMaster()->MovePath(PATH_WAVE_DONE_3, false);
                    break;
                case EVENT_WAVE_DONE_4:
                    me->SetImmuneToAll(false);
                    _waveEventInProgress = false;
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            UpdateOutOfCombatEvents(diff);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BRUTAL_SWIPE:
                    DoCastVictim(SPELL_BRUTAL_SWIPE);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_MANGLE:
                    DoCastVictim(SPELL_MANGLE);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_SURGE:
                    DoCastSelf(SPELL_SURGE);
                    events.Repeat(15s, 20s);
                    break;

                case EVENT_LACERATING_SLASH:
                    DoCastVictim(SPELL_LACERATING_SLASH);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_REND_FLESH:
                    DoCastVictim(SPELL_REND_FLESH);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_DEAFENING_ROAR:
                    DoCastSelf(SPELL_DEAFENING_ROAR);
                    events.Repeat(10s, 15s);
                    break;

                case EVENT_SHAPESHIFT:
                {
                    if (_isInBearForm)
                    {
                        Talk(SAY_TO_TROLL);
                        SetEquipmentSlots(true);
                        events.CancelEvent(EVENT_LACERATING_SLASH);
                        events.CancelEvent(EVENT_REND_FLESH);
                        events.CancelEvent(EVENT_DEAFENING_ROAR);
                        events.ScheduleEvent(EVENT_BRUTAL_SWIPE, 10s, 20s);
                        events.ScheduleEvent(EVENT_MANGLE, 5s, 15s);
                        events.ScheduleEvent(EVENT_SURGE, 20s, 25s);
                        events.Repeat(45s);
                        _isInBearForm = false;
                    }
                    else
                    {
                        DoCastSelf(SPELL_SHAPE_OF_THE_BEAR);
                        events.CancelEvent(EVENT_BRUTAL_SWIPE);
                        events.CancelEvent(EVENT_MANGLE);
                        events.CancelEvent(EVENT_SURGE);
                        events.ScheduleEvent(EVENT_LACERATING_SLASH, 5s, 10s);
                        events.ScheduleEvent(EVENT_REND_FLESH, 10s, 20s);
                        events.ScheduleEvent(EVENT_DEAFENING_ROAR, 15s, 20s);
                        events.Repeat(30s);
                        _isInBearForm = true;
                    }
                    break;
                }

                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _waveEventInProgress;
    bool _isMovingToLocation;
    bool _isWaiting;
    bool _isInBearForm;
    uint32 _currentWaveCount;
};

// 44019 - Surge
class spell_nalorakk_surge : public SpellScript
{
    PrepareSpellScript(spell_nalorakk_surge);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SURGE_CHARGE, SPELL_SURGE_HASTE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        caster->CastSpell(target, SPELL_SURGE_CHARGE, true);
        caster->CastSpell(caster, SPELL_SURGE_HASTE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_nalorakk_surge::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_nalorakk_surge::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_nalorakk()
{
    RegisterZulAmanCreatureAI(boss_nalorakk);
    RegisterSpellScript(spell_nalorakk_surge);
}
