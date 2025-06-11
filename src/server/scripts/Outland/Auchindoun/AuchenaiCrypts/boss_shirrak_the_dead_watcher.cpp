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
#include "Spell.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "auchenai_crypts.h"

enum ShirrakTexts
{
    EMOTE_FOCUSED                  = 0
};

enum ShirrakSpells
{
    SPELL_INHIBIT_MAGIC_PERIODIC   = 33460,
    SPELL_INHIBIT_MAGIC            = 32264,

    SPELL_ATTRACT_MAGIC            = 32265,
    SPELL_CARNIVOROUS_BITE         = 36383,
    SPELL_FOCUS_FIRE_AURA          = 32291,

    SPELL_BIRTH                    = 26262,
    SPELL_FOCUS_TARGET_VISUAL      = 32286,
    SPELL_FIERY_BLAST              = 32302,

    SPELL_FOCUS_FIRE_DUMMY         = 32300,
    SPELL_PING_SHIRRAK             = 32301
};

enum ShirrakEvents
{
    EVENT_ATTRACT_MAGIC            = 1,
    EVENT_CARNIVOROUS_BITE,
    EVENT_FOCUS_FIRE
};

// 18371 - Shirrak the Dead Watcher
struct boss_shirrak_the_dead_watcher : public BossAI
{
    boss_shirrak_the_dead_watcher(Creature* creature) : BossAI(creature, DATA_SHIRRAK_THE_DEAD_WATCHER) { }

    void Reset() override
    {
        DoCastSelf(SPELL_INHIBIT_MAGIC_PERIODIC);
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_ATTRACT_MAGIC, 30s);
        events.ScheduleEvent(EVENT_CARNIVOROUS_BITE, 5s, 10s);
        events.ScheduleEvent(EVENT_FOCUS_FIRE, 20s, 30s);
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
                case EVENT_ATTRACT_MAGIC:
                    DoCastSelf(SPELL_ATTRACT_MAGIC);
                    events.Repeat(30s);
                    break;
                case EVENT_CARNIVOROUS_BITE:
                    DoCastSelf(SPELL_CARNIVOROUS_BITE);
                    events.Repeat(5s, 10s);
                    break;
                case EVENT_FOCUS_FIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 50, true))
                    {
                        DoCast(target, SPELL_FOCUS_FIRE_AURA);
                        Talk(EMOTE_FOCUSED, target);
                    }
                    events.Repeat(15s, 25s);
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

// 18374 - Focus Fire
struct npc_focus_fire : public ScriptedAI
{
    npc_focus_fire(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        // Should be in this sniffed order but makes it ignore other spell casts, so disabled
        // DoCastSelf(SPELL_BIRTH);
        DoCastSelf(SPELL_FOCUS_TARGET_VISUAL);

        _scheduler.Schedule(5s, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_PING_SHIRRAK);
        });
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_FOCUS_FIRE_DUMMY)
            DoCastSelf(SPELL_FIERY_BLAST);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 32301 - Ping Shirrak
class spell_shirrak_ping_shirrak : public SpellScript
{
    PrepareSpellScript(spell_shirrak_ping_shirrak);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FOCUS_FIRE_DUMMY });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_FOCUS_FIRE_DUMMY);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_shirrak_ping_shirrak::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 32264 - Inhibit Magic
class spell_shirrak_inhibit_magic : public SpellScript
{
    PrepareSpellScript(spell_shirrak_inhibit_magic);

    void RemoveOldAura(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->Id);
    }

    void TriggerNext()
    {
        int32 castIndex = GetCastIndex();
        if (castIndex >= 3)
            return;

        float radiusMod = GetSpellValue()->RadiusMod * 0.66f;

        GetCaster()->CastSpell(nullptr, GetSpellInfo()->Id, CastSpellExtraArgs()
            .SetTriggerFlags(TRIGGERED_FULL_MASK)
            .AddSpellMod(SPELLVALUE_BASE_POINT1, castIndex + 1)
            .AddSpellMod(SPELLVALUE_RADIUS_MOD, int32(radiusMod * 10000)));
    }

    int32 GetCastIndex() const
    {
        // we are storing number of casts in a non-effect SPELLVALUE_BASE_POINT1
        return GetSpellValue()->EffectBasePoints[EFFECT_1];
    }

    void Register() override
    {
        if (!GetSpell() || GetCastIndex() == 0)
            OnEffectLaunchTarget += SpellEffectFn(spell_shirrak_inhibit_magic::RemoveOldAura, EFFECT_0, SPELL_EFFECT_APPLY_AURA);

        AfterCast += SpellCastFn(spell_shirrak_inhibit_magic::TriggerNext);
    }
};

void AddSC_boss_shirrak_the_dead_watcher()
{
    RegisterAuchenaiCryptsCreatureAI(boss_shirrak_the_dead_watcher);
    RegisterAuchenaiCryptsCreatureAI(npc_focus_fire);
    RegisterSpellScript(spell_shirrak_ping_shirrak);
    RegisterSpellScript(spell_shirrak_inhibit_magic);
}
