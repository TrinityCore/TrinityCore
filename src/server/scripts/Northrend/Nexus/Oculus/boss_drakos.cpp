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

#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "oculus.h"

enum Texts
{
    SAY_AGGRO                       = 0,
    SAY_KILL                        = 1,
    SAY_DEATH                       = 2,
    SAY_PULL                        = 3,
    SAY_STOMP                       = 4,
    EMOTE_PULL                      = 5
};

enum Spells
{
    SPELL_SUMMON_UNSTABLE_SPHERE    = 50754,
    SPELL_MAGIC_PULL                = 51336,
    SPELL_THUNDERING_STOMP          = 50774,

    SPELL_MAGIC_PULL_EFFECT         = 50770
};

enum Events
{
    EVENT_BOMB_SUMMON               = 1,
    EVENT_MAGIC_PULL,
    EVENT_STOMP
};

enum Misc
{
    ACHIEV_TIMED_START_EVENT        = 18153
};

struct boss_drakos : public BossAI
{
    boss_drakos(Creature* creature) : BossAI(creature, DATA_DRAKOS) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_BOMB_SUMMON, 2s);
        events.ScheduleEvent(EVENT_MAGIC_PULL, 10s, 18s);
        events.ScheduleEvent(EVENT_STOMP, 10s, 18s);
    }

    void OnSpellStart(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_MAGIC_PULL)
        {
            Talk(SAY_PULL);
            Talk(EMOTE_PULL);
        }
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_THUNDERING_STOMP, me))
            if (roll_chance_i(50))
                Talk(SAY_STOMP);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_KILL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        // start achievement timer (kill Eregos within 20 min)
        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
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
                case EVENT_BOMB_SUMMON:
                    DoCastSelf(SPELL_SUMMON_UNSTABLE_SPHERE);
                    events.Repeat(2s);
                    break;
                case EVENT_MAGIC_PULL:
                    DoCastSelf(SPELL_MAGIC_PULL);
                    events.Repeat(6s, 14s);
                    break;
                case EVENT_STOMP:
                    DoCastSelf(SPELL_THUNDERING_STOMP);
                    events.Repeat(10s, 20s);
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

// 51336 - Magic Pull
class spell_drakos_magic_pull : public SpellScript
{
    PrepareSpellScript(spell_drakos_magic_pull);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGIC_PULL_EFFECT, SPELL_SUMMON_UNSTABLE_SPHERE });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MAGIC_PULL_EFFECT, true);
    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        for (uint8 i = 0; i < 5; i++)
            caster->CastSpell(caster, SPELL_SUMMON_UNSTABLE_SPHERE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_drakos_magic_pull::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_drakos_magic_pull::HandleAfterCast);
    }
};

void AddSC_boss_drakos()
{
    RegisterOculusCreatureAI(boss_drakos);
    RegisterSpellScript(spell_drakos_magic_pull);
}
