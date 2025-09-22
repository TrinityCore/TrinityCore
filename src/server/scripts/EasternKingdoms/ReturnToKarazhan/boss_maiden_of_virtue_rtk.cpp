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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "return_to_karazhan.h"

enum MaidenOfVirtueRTKSpells
{
    SPELL_HOLY_BOLT                 = 227809,
    SPELL_HOLY_SHOCK                = 227800,
    SPELL_SACRED_GROUND             = 227789,
    SPELL_SACRED_GROUND_DAMAGE      = 227848,
    SPELL_SACRED_GROUND_PERIODIC    = 227793,
    SPELL_MASS_REPENTANCE           = 227508,
    SPELL_HOLY_BULWARK              = 227817,
    SPELL_HOLY_WRATH                = 227823,
    SPELL_PLAY_SCENE                = 232516
};

enum MaidenOfVirtueRTKEvents
{
    EVENT_HOLY_BOLT = 1,
    EVENT_HOLY_SHOCK,
    EVENT_SACRED_GROUND,
    EVENT_MASS_REPENTANCE,
    EVENT_HOLY_BULWARK,
    EVENT_HOLY_WRATH
};

enum MaidenOfVirtueRTKActions
{
    ACTION_INTERRUPT_HOLY_WRATH = 1
};

enum MaidenOfVirtueRTKTexts
{
    SAY_AGGRO                   = 0,
    SAY_WIPE                    = 1,
    SAY_SLAY                    = 2,
    SAY_HOLY_BOLT               = 3,
    SAY_SACRED_GROUND_WARNING   = 4,
    SAY_SACRED_GROUND           = 5,
    SAY_HOLY_SHOCK              = 6,
    SAY_MASS_REPENTANCE_WARNING = 7,
    SAY_MASS_REPENTANCE         = 8,
    SAY_HOLY_BULWARK            = 9,
    SAY_HOLY_WRATH              = 10,
    SAY_DEAD                    = 11
};

enum MaidenOfVirtueGroup
{
    SPAWNGROUP_MAIDEN_OF_VIRTUE_OUTRO = 1267
};

// 113971 - Maiden of Virtue
struct boss_maiden_of_virtue_rtk : public BossAI
{
    boss_maiden_of_virtue_rtk(Creature* creature) : BossAI(creature, DATA_MAIDEN_OF_VIRTUE_RTK) { }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
        me->RemoveAllAreaTriggers();
        Talk(SAY_DEAD);

        DoCastSelf(SPELL_PLAY_SCENE);

        instance->instance->SpawnGroupSpawn(SPAWNGROUP_MAIDEN_OF_VIRTUE_OUTRO);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_WIPE);
        summons.DespawnAll();
        me->RemoveAllAreaTriggers();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.ScheduleEvent(EVENT_HOLY_BOLT, 8500ms);
        events.ScheduleEvent(EVENT_HOLY_SHOCK, 15800ms);
        events.ScheduleEvent(EVENT_SACRED_GROUND, 10900ms);
        events.ScheduleEvent(EVENT_MASS_REPENTANCE, 48500ms);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_INTERRUPT_HOLY_WRATH)
        {
            me->InterruptNonMeleeSpells(false);
            events.CancelEvent(EVENT_HOLY_WRATH);
            me->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_HOLY_BOLT, 8500ms);
            events.ScheduleEvent(EVENT_HOLY_SHOCK, 15800ms);
            events.ScheduleEvent(EVENT_SACRED_GROUND, 10900ms);
            events.ScheduleEvent(EVENT_MASS_REPENTANCE, 48500ms);
        }
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
                case EVENT_HOLY_BOLT:
                {
                    Talk(SAY_HOLY_BOLT);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        DoCast(target, SPELL_HOLY_BOLT);
                    events.Repeat(9700ms);
                    break;
                }
                case EVENT_HOLY_SHOCK:
                {
                    Talk(SAY_HOLY_SHOCK);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        DoCast(target, SPELL_HOLY_SHOCK);
                    events.Repeat(13300ms);
                    break;
                }
                case EVENT_SACRED_GROUND:
                {
                    Talk(SAY_SACRED_GROUND);
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                    {
                        Talk(SAY_SACRED_GROUND_WARNING, target);
                        DoCast(target, SPELL_SACRED_GROUND);
                    }
                    events.Repeat(19400ms);
                    break;
                }
                case EVENT_MASS_REPENTANCE:
                {
                    Talk(SAY_MASS_REPENTANCE_WARNING);
                    Talk(SAY_MASS_REPENTANCE);
                    events.CancelEvent(EVENT_HOLY_BOLT);
                    events.CancelEvent(EVENT_HOLY_SHOCK);
                    events.CancelEvent(EVENT_SACRED_GROUND);
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_MASS_REPENTANCE);
                    events.ScheduleEvent(EVENT_HOLY_BULWARK, 7300ms);
                    events.Repeat(51s);
                    break;
                }
                case EVENT_HOLY_BULWARK:
                {
                    events.CancelEvent(EVENT_MASS_REPENTANCE);
                    Talk(SAY_HOLY_BULWARK);
                    DoCastSelf(SPELL_HOLY_BULWARK);
                    events.ScheduleEvent(EVENT_HOLY_WRATH, 1200ms);
                    break;
                }
                case EVENT_HOLY_WRATH:
                {
                    Talk(SAY_HOLY_WRATH);
                    DoCastSelf(SPELL_HOLY_WRATH);
                    events.Repeat(2s);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 227793 - Sacred Ground
class spell_maiden_of_virtue_rtk_sacred_ground : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        if (!GetCaster())
            return;

        GetCaster()->CastSpell(GetTarget(), GetEffectInfo(EFFECT_0).CalcValue(), TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_maiden_of_virtue_rtk_sacred_ground::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 227817 - Holy Bulwark
class spell_maiden_of_virtue_rtk_holy_bulwark : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* maiden = instance->GetCreature(DATA_MAIDEN_OF_VIRTUE_RTK))
            maiden->AI()->DoAction(ACTION_INTERRUPT_HOLY_WRATH);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_maiden_of_virtue_rtk_holy_bulwark::AfterRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 227789 - Sacred Ground
struct at_maiden_of_virtue_rtk_sacred_ground : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_SACRED_GROUND_PERIODIC, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAura(SPELL_SACRED_GROUND_PERIODIC);
    }
};

// 232515 - Play Scene 2
// Id - 1538
class scene_maiden_of_virtue_outro : public SceneScript
{
public:
    scene_maiden_of_virtue_outro() : SceneScript("scene_maiden_of_virtue_outro") { }

    static void HandleScene(Player* player)
    {
        player->ClearUnitState(UNIT_STATE_ROOT);
    }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->AddUnitState(UNIT_STATE_ROOT);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        HandleScene(player);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        HandleScene(player);
    }
};

void AddSC_boss_maiden_of_virtue_rtk()
{
    RegisterReturnToKarazhanCreatureAI(boss_maiden_of_virtue_rtk);

    RegisterSpellScript(spell_maiden_of_virtue_rtk_sacred_ground);
    RegisterSpellScript(spell_maiden_of_virtue_rtk_holy_bulwark);

    RegisterAreaTriggerAI(at_maiden_of_virtue_rtk_sacred_ground);

    new scene_maiden_of_virtue_outro();
}
