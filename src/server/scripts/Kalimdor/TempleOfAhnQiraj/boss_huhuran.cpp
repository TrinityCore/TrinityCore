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
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "temple_of_ahnqiraj.h"

enum HuhuranTexts
{
    EMOTE_ENRAGE                = 0,
    EMOTE_BERSERK               = 1
};

enum HuhuranSpells
{
    SPELL_ACID_SPIT             = 26050,
    SPELL_NOXIOUS_POISON        = 26053,
    SPELL_WYVERN_STING          = 26180,
    SPELL_ENRAGE                = 26051,
    SPELL_BERSERK               = 26068,

    SPELL_WYVERN_STING_DAMAGE   = 26233
};

enum HuhuranEvents
{
    EVENT_ACID_SPIT             = 1,
    EVENT_NOXIOUS_POISON,
    EVENT_WYVERN_STING,
    EVENT_ENRAGE,
    EVENT_BERSERK
};

// 15509 - Princess Huhuran
struct boss_huhuran : public BossAI
{
    boss_huhuran(Creature* creature) : BossAI(creature, DATA_HUHURAN), _berserkTriggered(false) { }

    void Reset() override
    {
        _Reset();
        _berserkTriggered = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_ACID_SPIT, 0s, 15s);
        events.ScheduleEvent(EVENT_NOXIOUS_POISON, 10s, 20s);
        events.ScheduleEvent(EVENT_WYVERN_STING, 35s, 45s);
        events.ScheduleEvent(EVENT_ENRAGE, 10s, 25s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_berserkTriggered && me->HealthBelowPctDamaged(30, damage))
        {
            _berserkTriggered = true;
            events.CancelEvent(EVENT_ENRAGE);
            events.ScheduleEvent(EVENT_BERSERK, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
            case SPELL_ENRAGE:
                Talk(EMOTE_ENRAGE);
                break;
            case SPELL_BERSERK:
                Talk(EMOTE_BERSERK);
                break;
            default:
                break;
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
                case EVENT_ACID_SPIT:
                    DoCastVictim(SPELL_ACID_SPIT);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_NOXIOUS_POISON:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        DoCast(target, SPELL_NOXIOUS_POISON);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_WYVERN_STING:
                    DoCastSelf(SPELL_WYVERN_STING);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_ENRAGE);
                    events.Repeat(10s, 20s);
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

private:
    bool _berserkTriggered;
};

// 26180 - Wyvern Sting
class spell_huhuran_wyvern_sting : public AuraScript
{
    PrepareAuraScript(spell_huhuran_wyvern_sting);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WYVERN_STING_DAMAGE });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();

        if (Unit* caster = GetCaster())
        {
            int32 damage = removeMode == AURA_REMOVE_BY_ENEMY_SPELL ? 3000 : 500;
            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            args.AddSpellBP0(damage);
            caster->CastSpell(GetTarget(), SPELL_WYVERN_STING_DAMAGE, args);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_huhuran_wyvern_sting::AfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_huhuran()
{
    RegisterAQ40CreatureAI(boss_huhuran);
    RegisterSpellScript(spell_huhuran_wyvern_sting);
}
