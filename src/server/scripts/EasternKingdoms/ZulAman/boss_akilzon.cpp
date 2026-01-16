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
#include "zulaman.h"

enum Spells
{
    SPELL_STATIC_DISRUPTION     = 43622,
    SPELL_STATIC_VISUAL         = 45265,
    SPELL_CALL_LIGHTNING        = 43661, // Missing timer
    SPELL_GUST_OF_WIND          = 43621,
    SPELL_ELECTRICAL_STORM      = 43648,
    SPELL_BERSERK               = 45078,
    SPELL_ELECTRICAL_OVERLOAD   = 43658,
    SPELL_EAGLE_SWOOP           = 44732,
    SPELL_ZAP                   = 43137,
    SPELL_SAND_STORM            = 25160,

    SPELL_ELECTRICAL_STORM_AURA = 44007,
    SPELL_TELEPORT_SELF         = 44006,

    SPELL_ELECTRICAL_ARC_1      = 43653,
    SPELL_ELECTRICAL_ARC_2      = 43654,
    SPELL_ELECTRICAL_ARC_3      = 43655,
    SPELL_ELECTRICAL_ARC_4      = 43656,
    SPELL_ELECTRICAL_ARC_5      = 43659
};

enum Says
{
    SAY_AGGRO               = 0,
    SAY_PLAYER_KILL         = 1,
    EMOTE_ELECTRICAL_STORM  = 2,
    SAY_SUMMON_EAGLE        = 3,
    SAY_SUMMON_BIRDS        = 4,
    SAY_BERSERK             = 5,
    SAY_DEATH               = 6
};

class boss_akilzon : public CreatureScript
{
    public:
        boss_akilzon() : CreatureScript("boss_akilzon") { }

        struct boss_akilzonAI : public BossAI
        {
            boss_akilzonAI(Creature* creature) : BossAI(creature, BOSS_AKILZON) { }

            void Reset() override
            {
                _Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_AGGRO);
                BossAI::JustEngagedWith(who);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_PLAYER_KILL);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
                /*
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        default:
                            break;
                    }
                }
                */
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulAmanAI<boss_akilzonAI>(creature);
        }
};

// 43648 - Electrical Storm
class spell_akilzon_electrical_storm : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ELECTRICAL_STORM_AURA, SPELL_TELEPORT_SELF });
    }

    void HandleAfterHit()
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_ELECTRICAL_STORM_AURA, true);
        target->CastSpell(target, SPELL_TELEPORT_SELF, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_akilzon_electrical_storm::HandleAfterHit);
    }
};

// 43658 - Electrical Overload Graphic Pulse
class spell_akilzon_electrical_overload : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ELECTRICAL_ARC_1,
            SPELL_ELECTRICAL_ARC_2,
            SPELL_ELECTRICAL_ARC_3,
            SPELL_ELECTRICAL_ARC_4,
            SPELL_ELECTRICAL_ARC_5
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_ELECTRICAL_ARC_1, true);
        caster->CastSpell(caster, SPELL_ELECTRICAL_ARC_2, true);
        caster->CastSpell(caster, SPELL_ELECTRICAL_ARC_3, true);
        caster->CastSpell(caster, SPELL_ELECTRICAL_ARC_4, true);
        caster->CastSpell(caster, SPELL_ELECTRICAL_ARC_5, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_akilzon_electrical_overload::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_akilzon()
{
    new boss_akilzon();
    RegisterSpellScript(spell_akilzon_electrical_storm);
    RegisterSpellScript(spell_akilzon_electrical_overload);
}
