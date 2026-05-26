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
 * Lava Bomb requires additional research. Both spells can target mana-users. Doesn't look like they're used randomly. Only one spell is used every 12-15 seconds.
 Looks like the spell boss uses depends on HP PCT but exact PCT is unknown. That should be double-checked
 */

#include "ScriptMgr.h"
#include "molten_core.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum MagmadarTexts
{
    EMOTE_FRENZY                = 0,
    EMOTE_EXHAUSTED             = 1
};

enum MagmadarSpells
{
    SPELL_MAGMA_SPIT            = 19449,

    SPELL_FRENZY                = 19451,
    SPELL_PANIC                 = 19408,
    SPELL_LAVA_BOMB_1           = 19411,
    SPELL_LAVA_BOMB_2           = 20474,

    SPELL_SUMMON_LAVA_BOMB_1    = 20494,
    SPELL_SUMMON_LAVA_BOMB_2    = 20495
};

enum MagmadarEvents
{
    EVENT_FRENZY                = 1,
    EVENT_PANIC,
    EVENT_LAVA_BOMB_1,
    EVENT_LAVA_BOMB_2,

    EVENT_EXHAUSTED
};

// 11982 - Magmadar
struct boss_magmadar : public BossAI
{
    boss_magmadar(Creature* creature) : BossAI(creature, BOSS_MAGMADAR), _lavaBombSwitched(false), _isExhausted(false) { }

    void Reset() override
    {
        _Reset();
        _lavaBombSwitched = false;
        _isExhausted = false;
        DoCastSelf(SPELL_MAGMA_SPIT);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_FRENZY, 5s, 10s);
        events.ScheduleEvent(EVENT_PANIC, 5s, 10s);
        events.ScheduleEvent(EVENT_LAVA_BOMB_1, 10s, 15s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_lavaBombSwitched && me->HealthBelowPctDamaged(60, damage))
        {
            _lavaBombSwitched = true;
            events.CancelEvent(EVENT_LAVA_BOMB_1);
            events.ScheduleEvent(EVENT_LAVA_BOMB_2, 10s, 15s);
        }

        if (!_isExhausted && me->HealthBelowPctDamaged(2, damage))
        {
            _isExhausted = true;
            events.ScheduleEvent(EVENT_EXHAUSTED, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_FRENZY)
            Talk(EMOTE_FRENZY);
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
                case EVENT_FRENZY:
                    DoCastSelf(SPELL_FRENZY);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_PANIC:
                    DoCastSelf(SPELL_PANIC);
                    events.Repeat(30s, 35s);
                    break;
                case EVENT_LAVA_BOMB_1:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_LAVA_BOMB_1);
                    events.Repeat(12s, 15s);
                    break;
                case EVENT_LAVA_BOMB_2:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_LAVA_BOMB_2);
                    events.Repeat(12s, 15s);
                    break;

                case EVENT_EXHAUSTED:
                    Talk(EMOTE_EXHAUSTED);
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
    bool _lavaBombSwitched;
    bool _isExhausted;
};

// 19411, 20474 - Lava Bomb
class spell_magmadar_lava_bomb : public SpellScript
{
    PrepareSpellScript(spell_magmadar_lava_bomb);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_LAVA_BOMB_1, SPELL_SUMMON_LAVA_BOMB_2 });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        switch (GetSpellInfo()->Id)
        {
            case SPELL_LAVA_BOMB_1:
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_LAVA_BOMB_1, true);
                break;
            case SPELL_LAVA_BOMB_2:
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_LAVA_BOMB_2, true);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_magmadar_lava_bomb::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_magmadar()
{
    RegisterMoltenCoreCreatureAI(boss_magmadar);
    RegisterSpellScript(spell_magmadar_lava_bomb);
}
