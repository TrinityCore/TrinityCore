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
 * Whirlwind gets interrupted in lots of cases
 * Conversation between creatures requires rechecks and improvements
 */

#include "ScriptMgr.h"
#include "arcatraz.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum DalliahTexts
{
    // Dalliah the Doomsayer
    SAY_AGGRO                       = 1,
    SAY_SLAY                        = 2,
    SAY_WHIRLWIND                   = 3,
    SAY_HEAL                        = 4,
    SAY_DEATH                       = 5,
    SAY_SOCCOTHRATES_DEATH          = 7,

    // Wrath-Scryer Soccothrates
    SAY_AGGRO_DALLIAH_FIRST         = 0,
    SAY_DALLIAH_25_PERCENT          = 5
};

enum DalliahSpells
{
    SPELL_GIFT_OF_THE_DOOMSAYER     = 36173,
    SPELL_WHIRLWIND                 = 36142,
    SPELL_HEAL                      = 36144,
    SPELL_SHADOW_WAVE               = 39016,  // Heroic only

    SPELL_DUMMY                     = 36177
};

enum DalliahEvents
{
    EVENT_GIFT_OF_THE_DOOMSAYER     = 1,
    EVENT_WHIRLWIND,
    EVENT_HEAL,
    EVENT_SHADOW_WAVE,

    EVENT_ME_FIRST,
    EVENT_SOCCOTHRATES_DEATH
};

// 20885 - Dalliah the Doomsayer
struct boss_dalliah_the_doomsayer : public BossAI
{
    boss_dalliah_the_doomsayer(Creature* creature) : BossAI(creature, DATA_DALLIAH),
        _soccothratesTaunt(false), _soccothratesDeath(false) { }

    void Reset() override
    {
        _Reset();
        _soccothratesTaunt = false;
        _soccothratesDeath = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_GIFT_OF_THE_DOOMSAYER, 0s, 10s);
        events.ScheduleEvent(EVENT_WHIRLWIND, 5s, 10s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SHADOW_WAVE, 10s, 15s);
        events.ScheduleEvent(EVENT_ME_FIRST, 6s);
        Talk(SAY_AGGRO);
    }

    void SetData(uint32 /*type*/, uint32 data) override
    {
        switch (data)
        {
            case 1:
                events.ScheduleEvent(EVENT_SOCCOTHRATES_DEATH, 6s);
                _soccothratesDeath = true;
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_soccothratesTaunt && me->HealthBelowPctDamaged(25, damage))
        {
            _soccothratesTaunt = true;

            if (Creature* soccothrates = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SOCCOTHRATES)))
                soccothrates->AI()->Talk(SAY_DALLIAH_25_PERCENT);
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_DUMMY)
            events.ScheduleEvent(EVENT_HEAL, 0s);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_WHIRLWIND)
            if (roll_chance_i(30))
                Talk(SAY_WHIRLWIND);

        if (spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_HEAL, me))
            if (roll_chance_i(50))
                Talk(SAY_HEAL);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        if (Creature* soccothrates = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SOCCOTHRATES)))
            if (soccothrates->IsAlive() && !soccothrates->IsInCombat())
                soccothrates->AI()->SetData(1, 1);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            if (_soccothratesDeath)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SOCCOTHRATES_DEATH:
                            Talk(SAY_SOCCOTHRATES_DEATH);
                            break;
                        default:
                            break;
                    }
                }
            }

            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GIFT_OF_THE_DOOMSAYER:
                    DoCastVictim(SPELL_GIFT_OF_THE_DOOMSAYER);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_WHIRLWIND:
                    DoCastSelf(SPELL_WHIRLWIND);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_HEAL:
                    DoCastSelf(SPELL_HEAL);
                    break;
                case EVENT_SHADOW_WAVE:
                    DoCastVictim(SPELL_SHADOW_WAVE);
                    events.Repeat(10s, 15s);
                    break;

                case EVENT_ME_FIRST:
                    if (Creature* soccothrates = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SOCCOTHRATES)))
                        if (soccothrates->IsAlive() && !soccothrates->IsInCombat())
                            soccothrates->AI()->Talk(SAY_AGGRO_DALLIAH_FIRST);
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
    bool _soccothratesTaunt;
    bool _soccothratesDeath;
};

// 36142 - Whirlwind
class spell_dalliah_the_doomsayer_whirlwind : public AuraScript
{
    PrepareAuraScript(spell_dalliah_the_doomsayer_whirlwind);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DUMMY });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        // When Whirlwind ends, creature casts Dummy spell. When Dummy spell hits,
        // creature casts Heal spell and this is how Heal after Whirlwind is handled
        GetTarget()->CastSpell(GetTarget(), SPELL_DUMMY, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dalliah_the_doomsayer_whirlwind::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_dalliah_the_doomsayer()
{
    RegisterArcatrazCreatureAI(boss_dalliah_the_doomsayer);
    RegisterSpellScript(spell_dalliah_the_doomsayer_whirlwind);
}
