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
 * Timers requires to be revisited
 * Looks like SPELL_ARCANE_BUBBLE and SPELL_MANA_SHIELD were removed in Cata
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "sethekk_halls.h"

enum IkissTexts
{
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3,
    EMOTE_ARCANE_EXPLOSION      = 4
};

enum IkissSpells
{
    // Combat
    SPELL_POLYMORPH             = 38245,
    SPELL_ARCANE_VOLLEY         = 35059,
    SPELL_SLOW                  = 35032,
    SPELL_MANA_SHIELD           = 38151,

    // Combat - Sequence
    SPELL_BLINK                 = 38194,
    SPELL_ARCANE_BUBBLE         = 9438,
    SPELL_ARCANE_EXPLOSION      = 38197,

    // Scripts
    SPELL_BLINK_TELEPORT        = 38203
};

enum IkissEvents
{
    EVENT_POLYMORPH             = 1,
    EVENT_ARCANE_VOLLEY,
    EVENT_SLOW,
    EVENT_MANA_SHIELD,

    EVENT_SEQUENCE_1,
    EVENT_SEQUENCE_2,
    EVENT_SEQUENCE_3
};

enum IkissPhases : uint8
{
    PHASE_NONE                  = 0,
    PHASE_HEALTH_80,
    PHASE_HEALTH_50,
    PHASE_HEALTH_25,
    PHASE_HEALTH_15
};

// 18473 - Talon King Ikiss
struct boss_talon_king_ikiss : public BossAI
{
    boss_talon_king_ikiss(Creature* creature) : BossAI(creature, DATA_TALON_KING_IKISS), _introDone(false), _phase(PHASE_NONE) { }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
        me->SetReactState(REACT_AGGRESSIVE);
    }

    /// @todo: Handle this with GameObject 184118 (Auchindoun Arakkoa - Talon King Ikiss Intro Event - Trigger 000)
    void MoveInLineOfSight(Unit* who) override
    {
        if (!_introDone && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 100.0f))
        {
            _introDone = true;
            Talk(SAY_INTRO);
        }

        BossAI::MoveInLineOfSight(who);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_POLYMORPH, 5s, 15s);
        events.ScheduleEvent(EVENT_ARCANE_VOLLEY, 5s, 10s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SLOW, 10s, 20s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_ARCANE_EXPLOSION, me))
            me->SetReactState(REACT_AGGRESSIVE);
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_80 && me->HealthBelowPctDamaged(80, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SEQUENCE_1, 0s);
        }

        if (_phase < PHASE_HEALTH_50 && me->HealthBelowPctDamaged(50, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SEQUENCE_1, 0s);
        }

        if (_phase < PHASE_HEALTH_25 && me->HealthBelowPctDamaged(25, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_SEQUENCE_1, 0s);
        }

        if (_phase < PHASE_HEALTH_15 && me->HealthBelowPctDamaged(15, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_MANA_SHIELD, 0s);
        }
    }

    void KilledUnit(Unit* /*who*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_POLYMORPH:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 30.0f))
                    DoCast(target, SPELL_POLYMORPH);
                events.Repeat(10s, 20s);
                break;
            case EVENT_ARCANE_VOLLEY:
                DoCastSelf(SPELL_ARCANE_VOLLEY);
                events.Repeat(10s);
                break;
            case EVENT_SLOW:
                DoCastSelf(SPELL_SLOW);
                events.Repeat(15s, 20s);
                break;
            case EVENT_MANA_SHIELD:
                DoCastSelf(SPELL_MANA_SHIELD);
                break;

            case EVENT_SEQUENCE_1:
                DoCastSelf(SPELL_BLINK);
                ResetThreatList();
                me->SetReactState(REACT_PASSIVE);
                events.ScheduleEvent(EVENT_SEQUENCE_2, 1200ms);
                break;
            case EVENT_SEQUENCE_2:
                DoCastSelf(SPELL_ARCANE_BUBBLE);
                Talk(EMOTE_ARCANE_EXPLOSION);
                events.ScheduleEvent(EVENT_SEQUENCE_3, 1200ms);
                break;
            case EVENT_SEQUENCE_3:
                DoCastSelf(SPELL_ARCANE_EXPLOSION);
                break;
            default:
                break;
        }
    }

private:
    bool _introDone;
    uint8 _phase;
};

// 38194 - Blink
class spell_talon_king_ikiss_blink : public SpellScript
{
    PrepareSpellScript(spell_talon_king_ikiss_blink);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLINK_TELEPORT });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);

        _selectedTargetGuid = target->GetGUID();
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (GetHitUnit()->GetGUID() == _selectedTargetGuid)
            GetHitUnit()->CastSpell(GetCaster(), SPELL_BLINK_TELEPORT, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_talon_king_ikiss_blink::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_talon_king_ikiss_blink::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    ObjectGuid _selectedTargetGuid;
};

void AddSC_boss_talon_king_ikiss()
{
    RegisterSethekkHallsCreatureAI(boss_talon_king_ikiss);
    RegisterSpellScript(spell_talon_king_ikiss_blink);
}
