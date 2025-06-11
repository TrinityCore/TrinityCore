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
 * Dummy spell 39188 apparently handles actions from EVENT_GROUND_SLAM but maybe something else
 * The way Reverberation & Ground Slam timers are handled may be wrong. Both timers are random but sometimes
  because of that first Reverberation cast may be skipped while so far I never seen it in movies. He can cast
  it twice between Ground Slam sequences or skip one of 2 casts but never skips all. Maybe it's just random
 * The way knock back is handled should be re-checked
 */

#include "ScriptMgr.h"
#include "gruuls_lair.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum GruulTexts
{
    SAY_AGGRO                   = 0,
    SAY_SLAM                    = 1,
    SAY_SHATTER                 = 2,
    SAY_SLAY                    = 3,
    EMOTE_ROAR                  = 4,
    EMOTE_GROW                  = 5
};

enum GruulSpells
{
    SPELL_HURTFUL_STRIKE_PRIMER = 33812,
    SPELL_HURTFUL_STRIKE        = 33813,
    SPELL_CAVE_IN               = 36240,
    SPELL_REVERBERATION         = 36297,
    SPELL_GROWTH                = 36300,

    SPELL_GROUND_SLAM_DUMMY     = 39188,
    SPELL_GROUND_SLAM           = 33525,
    SPELL_LOOK_AROUND           = 33965,
    SPELL_SUMMON_RANDOM_TRACTOR = 39186,
    SPELL_SHATTER               = 33654,
    SPELL_SHATTER_EFFECT        = 33671,
    SPELL_STONED                = 33652
};

enum GruulEvents
{
    EVENT_HURTFUL_STRIKE = 1,
    EVENT_CAVE_IN,
    EVENT_REVERBERATION,
    EVENT_GROWTH,
    EVENT_GROUND_SLAM
};

enum GruulMisc
{
    SOUND_ID_DEATH              = 11363
};

// 19044 - Gruul the Dragonkiller
struct boss_gruul : public BossAI
{
    boss_gruul(Creature* creature) : BossAI(creature, DATA_GRUUL) { }

    void Reset() override
    {
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_HURTFUL_STRIKE, 6s);
        events.ScheduleEvent(EVENT_CAVE_IN, 8s);
        events.ScheduleEvent(EVENT_REVERBERATION, 105s, 115s);
        events.ScheduleEvent(EVENT_GROWTH, 30s);
        events.ScheduleEvent(EVENT_GROUND_SLAM, 40s);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoPlaySoundToSet(me, SOUND_ID_DEATH);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_HURTFUL_STRIKE:
                DoCastSelf(SPELL_HURTFUL_STRIKE_PRIMER);
                events.Repeat(8s);
                break;
            case EVENT_CAVE_IN:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_CAVE_IN);
                events.Repeat(8s);
                break;
            case EVENT_REVERBERATION:
                DoCastSelf(SPELL_REVERBERATION);
                events.Repeat(30s, 45s);
                break;
            case EVENT_GROWTH:
                DoCastSelf(SPELL_GROWTH);
                Talk(EMOTE_GROW);
                events.Repeat(30s);
                break;
            case EVENT_GROUND_SLAM:
                DoCastSelf(SPELL_GROUND_SLAM_DUMMY);
                Talk(SAY_SLAM);
                DoCastSelf(SPELL_GROUND_SLAM);
                events.RescheduleEvent(EVENT_HURTFUL_STRIKE, 21s);
                events.RescheduleEvent(EVENT_CAVE_IN, 15s);
                events.Repeat(70s, 90s);
                break;
            default:
                break;
        }
    }
};

// 33812 - Hurtful Strike Primer
class spell_gruul_hurtful_strike_primer : public SpellScript
{
    PrepareSpellScript(spell_gruul_hurtful_strike_primer);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();

        // First we get rid of all targets that are not within melee range
        targets.remove_if([&](WorldObject* target)
        {
            if (Unit* unit = target->ToUnit())
                return !unit->IsWithinMeleeRange(caster);

            return true;
        });

        if (targets.size() >= 2)
        {
            // Now we sort all targets by threat
            targets.sort([&](WorldObject const* left, WorldObject const* right)
            {
                Unit const* leftTarget = ASSERT_NOTNULL(left->ToUnit());
                Unit const* rightTarget = ASSERT_NOTNULL(right->ToUnit());

                return caster->GetThreatManager().GetThreat(leftTarget) > caster->GetThreatManager().GetThreat(rightTarget);
            });

            // Now we nuke the top threat target so we are only left with the 2nd top victim
            targets.pop_front();

            if (targets.size() >= 2)
                targets.resize(1);
        }
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HURTFUL_STRIKE);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gruul_hurtful_strike_primer::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_gruul_hurtful_strike_primer::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 33525 - Ground Slam
class spell_gruul_ground_slam : public SpellScript
{
    PrepareSpellScript(spell_gruul_ground_slam);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_LOOK_AROUND, SPELL_SUMMON_RANDOM_TRACTOR });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        // Stuns Gruul for 8 seconds
        GetCaster()->CastSpell(GetCaster(), SPELL_LOOK_AROUND);
        /* I guess he forces all enemies including pets to summon creature 19198 by spell 39186(9 summoned units and
           9 units in his threat list). Summoned by that spell creature 19198 casts 33496 on self after being summoned.
           Then after small delay they casts 33497(Pull Towards: (150)) (guess) on their creators and that's how that
           knockback without fall damage is handled. If you look closely, players are knocked to random destinations
           with random angles, means there is no only one spell which handles knockback. However the spell to summon
           that trigger is TARGET_DEST_CASTER_RADIUS, so creature may be spawned just few yards away from player. In
           that case player will be knocked back for a really small distance. It may look weird and wrong.
           Script for 19198 is handled in SAI. 19198 probably is used in Cata dungeons or raids too, also at least in
           one TBC raid or dungeon since there are more spells to summon that creature. */
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_RANDOM_TRACTOR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gruul_ground_slam::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 33965 - Look Around
class spell_gruul_look_around : public AuraScript
{
    PrepareAuraScript(spell_gruul_look_around);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SHATTER });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
        {
            creature->AI()->Talk(EMOTE_ROAR);
            creature->AI()->Talk(SAY_SHATTER);
            creature->CastSpell(creature, SPELL_SHATTER);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_gruul_look_around::AfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 33654 - Shatter
class spell_gruul_shatter : public SpellScript
{
    PrepareSpellScript(spell_gruul_shatter);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_STONED, SPELL_SHATTER_EFFECT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->RemoveAurasDueToSpell(SPELL_STONED);
        target->CastSpell(nullptr, SPELL_SHATTER_EFFECT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gruul_shatter::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 33671 - Shatter
class spell_gruul_shatter_effect : public SpellScript
{
    PrepareSpellScript(spell_gruul_shatter_effect);

    void CalculateDamage()
    {
        if (!GetHitUnit())
            return;

        float radius = GetEffectInfo(EFFECT_0).CalcRadius(GetCaster());
        if (!radius)
            return;

        float distance = GetCaster()->GetDistance2d(GetHitUnit());
        if (distance > 1.0f)
            SetHitDamage(int32(GetHitDamage() * ((radius - distance) / radius)));
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_gruul_shatter_effect::CalculateDamage);
    }
};

void AddSC_boss_gruul()
{
    RegisterGruulsLairCreatureAI(boss_gruul);
    RegisterSpellScript(spell_gruul_hurtful_strike_primer);
    RegisterSpellScript(spell_gruul_ground_slam);
    RegisterSpellScript(spell_gruul_look_around);
    RegisterSpellScript(spell_gruul_shatter);
    RegisterSpellScript(spell_gruul_shatter_effect);
}
