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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "sethekk_halls.h"

enum Says
{
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3,
    EMOTE_ARCANE_EXPLOSION      = 4
};

enum Spells
{
    SPELL_BLINK                 = 38194,
    SPELL_BLINK_TELEPORT        = 38203,
    SPELL_MANA_SHIELD           = 38151,
    SPELL_ARCANE_BUBBLE         = 9438,
    SPELL_SLOW                  = 35032,
    SPELL_POLYMORPH             = 38245,
    SPELL_ARCANE_VOLLEY         = 35059,
    SPELL_ARCANE_EXPLOSION      = 38197,
};

enum Events
{
    EVENT_POLYMORPH = 1,
    EVENT_BLINK,
    EVENT_SLOW,
    EVENT_ARCANE_VOLLEY,
    EVENT_ARCANE_EXPLOSION
};

struct boss_talon_king_ikiss : public BossAI
{
    boss_talon_king_ikiss(Creature* creature) : BossAI(creature, DATA_TALON_KING_IKISS)
    {
        Intro = false;
        ManaShield = false;
    }

    void Reset() override
    {
        _Reset();
        Intro = false;
        ManaShield = false;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!Intro && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 100.0f))
        {
            Intro = true;
            Talk(SAY_INTRO);
        }

        BossAI::MoveInLineOfSight(who);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_ARCANE_VOLLEY, 5s);
        events.ScheduleEvent(EVENT_POLYMORPH, 8s);
        events.ScheduleEvent(EVENT_BLINK, 35s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SLOW, 15s, 30s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_POLYMORPH:
                // Second top aggro in normal, random target in heroic.
                if (IsHeroic())
                    DoCast(SelectTarget(SelectTargetMethod::Random, 0), SPELL_POLYMORPH);
                else
                    DoCast(SelectTarget(SelectTargetMethod::MaxThreat, 1), SPELL_POLYMORPH);
                events.ScheduleEvent(EVENT_POLYMORPH, 15s, 17500ms);
                break;
            case EVENT_ARCANE_VOLLEY:
                DoCast(me, SPELL_ARCANE_VOLLEY);
                events.ScheduleEvent(EVENT_ARCANE_VOLLEY, 7s, 12s);
                break;
            case EVENT_SLOW:
                DoCast(me, SPELL_SLOW);
                events.ScheduleEvent(EVENT_SLOW, 15s, 40s);
                break;
            case EVENT_BLINK:
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);
                Talk(EMOTE_ARCANE_EXPLOSION);
                DoCastAOE(SPELL_BLINK);
                events.ScheduleEvent(EVENT_BLINK, 35s, 40s);
                events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 1s);
                break;
            case EVENT_ARCANE_EXPLOSION:
                DoCast(me, SPELL_ARCANE_EXPLOSION);
                DoCast(me, SPELL_ARCANE_BUBBLE, true);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!ManaShield && me->HealthBelowPctDamaged(20, damage))
        {
            DoCast(me, SPELL_MANA_SHIELD);
            ManaShield = true;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    private:
        bool ManaShield;
        bool Intro;
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
        targets.clear();
        targets.push_back(target);
    }

    void HandleDummyHitTarget(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetCaster(), SPELL_BLINK_TELEPORT, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_talon_king_ikiss_blink::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_talon_king_ikiss_blink::HandleDummyHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_talon_king_ikiss()
{
    RegisterSethekkHallsCreatureAI(boss_talon_king_ikiss);
    RegisterSpellScript(spell_talon_king_ikiss_blink);
}
