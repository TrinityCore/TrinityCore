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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "the_underbog.h"

/*
How levitation sequence works: boss casts Levitate and it triggers a chain of spells, target(any target, player or pet, any position in
threat list) eventually gets pulled towards by randomly selected trigger. Then target becomes protected from Pull Towards by Suspension
aura which is triggered every 1 sec up to 4 times. Since it has stun mechanic, diminishing returns cuts off its duration every cast in
half (20 > 10 > 5 > 0). Eventually player becomes immune to Suspension and vulnerable to another pull towards.
Whole levitate sequence is designed to pull player towards up to 3 times. Usually it works like this: player gets pulled towards,
gets protected by Suspension from Pull Towards next 2 times. If player is unlucky, boss can cast Levitate on same player again, in that case
player can be pulled towards 2 times in a row without any protection from fall damage by Suspension(case from sniffs).

However currently diminishing returns affects Suspension after first cast, its duration is 10 instead of 20 seconds and player will be
immune to 4th cast. That allows to pull player towards when levitation sequence ends. Levitation sequence has sensetive design and looks
like lack of delays between packets makes it work differently too.
Of course as was said above player can be pulled towards 2 times in a row but that looks like a rare case.
*/

enum BlackStalkerSpells
{
    SPELL_LEVITATE                      = 31704,
    SPELL_CHAIN_LIGHTNING               = 31717,
    SPELL_STATIC_CHARGE                 = 31715,   // Never seen any cast on retail, probably because of shared cooldown with Chain Lightning
    SPELL_SUMMON_PLAYER                 = 20279,   // NYI, may be 20311 or any other
    SPELL_SUMMON_SPORE_STRIDER_SCRIPT   = 38756,

    SPELL_LEVITATION_PULSE              = 31701,
    SPELL_SOMEONE_GRAB_ME               = 31702,
    SPELL_MAGNETIC_PULL                 = 31703,
    SPELL_SUSPENSION_PRIMER             = 31720,
    SPELL_SUSPENSION                    = 31719,

    SPELL_SUMMON_SPORE_STRIDER          = 38755
};

enum BlackStalkerEvents
{
    EVENT_LEASH_CHECK                   = 1,
    EVENT_LEVITATE,
    EVENT_CHAIN_LIGHTNING,
    EVENT_STATIC_CHARGE,
    EVENT_SUMMON_SPORE_STRIDER
};

enum BlackStalkerPaths
{
    PATH_BLACK_STALKER_IDLE             = 4346960,
};

struct boss_the_black_stalker : public BossAI
{
    boss_the_black_stalker(Creature* creature) : BossAI(creature, DATA_THE_BLACK_STALKER), _summons(creature) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        scheduler.CancelAll();

        _events.ScheduleEvent(EVENT_LEASH_CHECK, 5s);
        _events.ScheduleEvent(EVENT_LEVITATE, 8s, 18s);
        _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 0s, 3s);
        _events.ScheduleEvent(EVENT_STATIC_CHARGE, 10s);
        if (IsHeroic())
            _events.ScheduleEvent(EVENT_SUMMON_SPORE_STRIDER, 20s, 30s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LEASH_CHECK:
                {
                    float x, y, z, o;
                    me->GetHomePosition(x, y, z, o);
                    if (!me->IsWithinDist3d(x, y, z, 60))
                    {
                        EnterEvadeMode();
                        return;
                    }
                    _events.Repeat(1s);
                    break;
                }
                case EVENT_LEVITATE:
                    DoCastSelf(SPELL_LEVITATE);
                    _events.Repeat(18s, 24s);
                    break;
                case EVENT_CHAIN_LIGHTNING:
                    DoCastVictim(SPELL_CHAIN_LIGHTNING);
                    _events.Repeat(6s, 12s);
                    break;
                case EVENT_STATIC_CHARGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30, true))
                        DoCast(target, SPELL_STATIC_CHARGE);
                    _events.Repeat(10s);
                    break;
                case EVENT_SUMMON_SPORE_STRIDER:
                    DoCastSelf(SPELL_SUMMON_SPORE_STRIDER_SCRIPT);
                    _events.Repeat(15s, 25s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId != PATH_BLACK_STALKER_IDLE)
            return;

        if (waypointId == 2 || waypointId == 4 || waypointId == 6)
        {
            scheduler.Schedule(2s, [this](TaskContext /*task*/)
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_EAT);
            });
        }
    }

private:
    EventMap _events;
    SummonList _summons;
};

// 31704 - Levitate
class spell_the_black_stalker_levitate : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LEVITATION_PULSE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_LEVITATION_PULSE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_black_stalker_levitate::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 31701 - Levitation Pulse
class spell_the_black_stalker_levitation_pulse : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOMEONE_GRAB_ME });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_SOMEONE_GRAB_ME, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_the_black_stalker_levitation_pulse::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 31702 - Someone Grab Me
class spell_the_black_stalker_someone_grab_me : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGNETIC_PULL, SPELL_SUSPENSION });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (!GetCaster()->HasAura(SPELL_SUSPENSION))
            GetHitUnit()->CastSpell(GetCaster(), SPELL_MAGNETIC_PULL);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_black_stalker_someone_grab_me::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 31703 - Magnetic Pull
class spell_the_black_stalker_magnetic_pull : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUSPENSION_PRIMER });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUSPENSION_PRIMER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_black_stalker_magnetic_pull::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 38756 - Summon Spore Strider
class spell_the_black_stalker_summon_spore_strider : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SPORE_STRIDER });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        for (uint8 i = 0; i < 3; i++)
            GetCaster()->CastSpell(GetCaster(), SPELL_SUMMON_SPORE_STRIDER, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_the_black_stalker_summon_spore_strider::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_the_black_stalker()
{
    RegisterTheUnderbogCreatureAI(boss_the_black_stalker);
    RegisterSpellScript(spell_the_black_stalker_levitate);
    RegisterSpellScript(spell_the_black_stalker_levitation_pulse);
    RegisterSpellScript(spell_the_black_stalker_someone_grab_me);
    RegisterSpellScript(spell_the_black_stalker_magnetic_pull);
    RegisterSpellScript(spell_the_black_stalker_summon_spore_strider);
}
