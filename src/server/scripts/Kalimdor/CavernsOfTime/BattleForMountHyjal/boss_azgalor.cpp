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
 * Combat timers requires to be revisited
 * The way he casts Doom is quite tricky, currently he casts it in solo, it's wrong
   1. In case of player with pet if player is not current victim he will cast spell even if player is not in spell range
   2. In case of solo if player is current victim he doesn't cast spell even if is attacked also by creatures
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "hyjal.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum AzgalorTexts
{
    SAY_INTRO                   = 0,
    SAY_DOOM                    = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3
};

enum AzgalorSpells
{
    // Azgalor
    SPELL_RAIN_OF_FIRE          = 31340,
    SPELL_HOWL_OF_AZGALOR       = 31344,
    SPELL_CLEAVE                = 31345,
    SPELL_DOOM                  = 31347,
    SPELL_BERSERK               = 26662,

    // Lesser Doomguard
    SPELL_THRASH                = 12787,
    SPELL_CRIPPLE               = 31406,
    SPELL_WAR_STOMP             = 31408
};

enum AzgalorEvents
{
    EVENT_RAIN_OF_FIRE          = 1,
    EVENT_HOWL_OF_AZGALOR,
    EVENT_CLEAVE,
    EVENT_DOOM,
    EVENT_BERSERK
};

// 17842 - Azgalor
struct boss_azgalor : public BossAI
{
    boss_azgalor(Creature* creature) : BossAI(creature, DATA_AZGALOR) { }

    void JustAppeared() override
    {
        Talk(SAY_INTRO);
        me->GetMotionMaster()->MovePath(PATH_HORDE_BOSS, false);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 20s, 25s);
        events.ScheduleEvent(EVENT_HOWL_OF_AZGALOR, 30s, 40s);
        events.ScheduleEvent(EVENT_CLEAVE, 5s, 10s);
        events.ScheduleEvent(EVENT_DOOM, 45s, 60s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DOOM)
            Talk(SAY_DOOM);
    }

    // Do not reset SetActive, we want boss to be active all the time
    void JustReachedHome() override { }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                case EVENT_RAIN_OF_FIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                        DoCast(target, SPELL_RAIN_OF_FIRE);
                    events.Repeat(15s, 30s);
                    break;
                case EVENT_HOWL_OF_AZGALOR:
                    DoCastSelf(SPELL_HOWL_OF_AZGALOR);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(8s, 15s);
                    break;
                case EVENT_DOOM:
                    DoCastSelf(SPELL_DOOM);
                    events.Repeat(45s, 60s);
                    break;
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
};

// 17864 - Lesser Doomguard
struct npc_lesser_doomguard : public ScriptedAI
{
    npc_lesser_doomguard(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        DoZoneInCombat();

        if (Creature* azgalor = _instance->GetCreature(DATA_AZGALOR))
            azgalor->AI()->JustSummoned(me);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
        DoCastSelf(SPELL_THRASH);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler
            .Schedule(4s, 10s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_CRIPPLE);
                task.Repeat(10s, 15s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_WAR_STOMP);
                task.Repeat(10s, 15s);
            });
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 31347 - Doom
class spell_azgalor_doom : public SpellScript
{
    PrepareSpellScript(spell_azgalor_doom);

    bool Load() override
    {
        return GetCaster()->IsUnit();
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster()->GetVictim());
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_azgalor_doom::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_azgalor()
{
    RegisterHyjalCreatureAI(boss_azgalor);
    RegisterHyjalCreatureAI(npc_lesser_doomguard);
    RegisterSpellScript(spell_azgalor_doom);
}
