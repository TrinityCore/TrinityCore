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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "darkflame_cleft.h"

enum TheCandleKingSpells
{
    SPELL_CURSED_WAX                 = 421648,
    SPELL_CURSED_WAX_DUMMY           = 422079,
    SPELL_CURSED_WAX_STUN            = 421653,
    SPELL_CURSED_WAX_VISUAL          = 422088, // Unk purpose
    SPELL_DARKFLAME_PICKAXE_SELECTOR = 421274,
    SPELL_DARKFLAME_PICKAXE_CAST     = 421277,
    SPELL_DARKFLAME_PICKAXE_MARKER   = 422648,
    SPELL_DARKFLAME_PICKAXE_DAMAGE   = 421282,
    SPELL_DARKFLAME_PICKAXE_VISUAL   = 421283,
    SPELL_DARKLIGHT                  = 426152,
    SPELL_DARKLIGHT_DEBUFF           = 426127,
    SPELL_CANDLELIGHT                = 426125,
    SPELL_EERIE_MOLDS_CLONE_SUMMONER = 420676,
    SPELL_EERIE_MOLDS_SELECTOR       = 420659,
    SPELL_EERIE_MOLDS_SUMMON         = 420665,
    SPELL_MOLTEN_WAX_DAMAGE          = 421067,
    SPELL_PARANOID_MIND              = 426145,
    SPELL_THROW_DARKFLAME_SELECTOR   = 420696,
    SPELL_THROW_DARKFLAME_MARKER     = 421250,
    SPELL_THROW_DARKFLAME_MISSILE    = 421145
};

enum TheCandleKingTexts
{
    SAY_AGGRO           = 0,
    SAY_EERIE_MOLDS     = 1,
    SAY_PICKAXE_WARNING = 2,
    SAY_WIPE            = 3,
    SAY_KILL            = 4,
    SAY_DEATH           = 5
};

enum TheCandleKingEvents
{
    EVENT_EERIE_MOLDS   = 1,
    EVENT_PARANOID_MIND,
    EVENT_DARKFLAME_PICKAXE,
    EVENT_THROW_DARKFLAME
};

enum TheCandleKingMisc
{
    NPC_WAX_STATUE = 209603,
    NPC_WAX_CHUNK  = 209791,
};

// 208745 - The Candle King
struct boss_the_candle_king : public BossAI
{
    boss_the_candle_king(Creature* creature) : BossAI(creature, DATA_THE_CANDLE_KING) { }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_THE_CANDLE_KING, DONE);

        RemoveWaxStatues();
        RemoveWaxChunks();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_THE_CANDLE_KING, FAIL);

        Talk(SAY_WIPE);

        _EnterEvadeMode();
        _DespawnAtEvade();
        RemoveWaxStatues();
        RemoveWaxChunks();
    }

    void RemoveWaxStatues()
    {
        std::list<Creature*> waxStatues;
        Trinity::AllCreaturesOfEntryInRange checker(me, NPC_WAX_STATUE, 200.0f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, waxStatues, checker);
        Cell::VisitAllObjects(me, searcher, 200.0f);

        if (waxStatues.empty())
            return;

        for (Creature* waxStatue : waxStatues)
            waxStatue->DespawnOrUnsummon();
    }

    void RemoveWaxChunks()
    {
        std::list<Creature*> waxChunks;
        Trinity::AllCreaturesOfEntryInRange checker(me, NPC_WAX_CHUNK, 200.0f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, waxChunks, checker);
        Cell::VisitAllObjects(me, searcher, 200.0f);

        if (waxChunks.empty())
            return;

        for (Creature* waxChunk : waxChunks)
            waxChunk->DespawnOrUnsummon();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_KILL);
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_EERIE_MOLDS_SELECTOR)
            Talk(SAY_EERIE_MOLDS);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (!target->IsPlayer())
            return;

        if (spellInfo->Id == SPELL_DARKFLAME_PICKAXE_SELECTOR)
            Talk(SAY_PICKAXE_WARNING, target);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->SetBossState(DATA_THE_CANDLE_KING, IN_PROGRESS);

        Talk(SAY_AGGRO);

        DoCastSelf(SPELL_DARKLIGHT);

        events.ScheduleEvent(EVENT_EERIE_MOLDS, 6s);
        events.ScheduleEvent(EVENT_PARANOID_MIND, 10500ms);
        events.ScheduleEvent(EVENT_DARKFLAME_PICKAXE, 13200ms);
        events.ScheduleEvent(EVENT_THROW_DARKFLAME, 19300ms);
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
                case EVENT_EERIE_MOLDS:
                {
                    DoCastSelf(SPELL_EERIE_MOLDS_SELECTOR);
                    events.Repeat(me->GetMap()->IsMythic() ? 23100ms : 31500ms);
                    break;
                }
                case EVENT_PARANOID_MIND:
                {
                    DoCastSelf(SPELL_PARANOID_MIND);
                    events.Repeat(me->GetMap()->IsMythic() ? 10900ms : 20600ms);
                    break;
                }
                case EVENT_DARKFLAME_PICKAXE:
                {
                    DoCastSelf(SPELL_DARKFLAME_PICKAXE_SELECTOR);
                    events.Repeat(me->GetMap()->IsMythic() ? 23100ms : 17s);
                    break;
                }
                case EVENT_THROW_DARKFLAME:
                {
                    DoCastSelf(SPELL_THROW_DARKFLAME_SELECTOR);
                    events.Repeat(me->GetMap()->IsMythic() ? 24300ms : 17s);
                    break;
                }
                default:
                    break;
            }
        }
    }
};

// 420677 - Eerie Molds
class spell_the_candle_king_eerie_molds_clone_summoner : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EERIE_MOLDS_CLONE_SUMMONER });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_EERIE_MOLDS_CLONE_SUMMONER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_candle_king_eerie_molds_clone_summoner::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 420659 - Eerie Molds
class spell_the_candle_king_eerie_molds_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_EERIE_MOLDS_SUMMON });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_EERIE_MOLDS_SUMMON, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_candle_king_eerie_molds_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 420696 - Throw Darkflame
class spell_the_candle_king_throw_darkflame_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_THROW_DARKFLAME_MARKER });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_THROW_DARKFLAME_MARKER, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_candle_king_throw_darkflame_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 421250 - Throw Darkflame
class spell_the_candle_king_throw_darkflame_missile : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_THROW_DARKFLAME_MISSILE });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_THROW_DARKFLAME_MISSILE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });
        }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_the_candle_king_throw_darkflame_missile::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 422079 - Cursed Wax
class spell_the_candle_king_cursed_wax : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CURSED_WAX_STUN });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_CURSED_WAX_STUN, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_candle_king_cursed_wax::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 421274 - Darkflame Pickaxe
class spell_the_candle_king_darkflame_pickaxe_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DARKFLAME_PICKAXE_CAST, SPELL_DARKFLAME_PICKAXE_MARKER });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        CastSpellExtraArgs args;
        args.SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        args.SetTriggeringSpell(GetSpell());

        caster->CastSpell(target, SPELL_DARKFLAME_PICKAXE_CAST, args);
        caster->CastSpell(target, SPELL_DARKFLAME_PICKAXE_MARKER, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_candle_king_darkflame_pickaxe_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class DarkflamePickaxeDamageEvent : public BasicEvent
{
public:
    explicit DarkflamePickaxeDamageEvent(Unit* caster, WorldObject* target, Spell* triggeringSpell) : _caster(caster), _target(target), _triggeringSpell(triggeringSpell) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        _caster->CastSpell(_target, SPELL_DARKFLAME_PICKAXE_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = _triggeringSpell
        });
        return true;
    }

private:
    Unit* _caster;
    WorldObject* _target;
    Spell* _triggeringSpell;
};

// 421277 - Darkflame Pickaxe
class spell_the_candle_king_darkflame_pickaxe_cast : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DARKFLAME_PICKAXE_VISUAL, SPELL_DARKFLAME_PICKAXE_DAMAGE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        static constexpr uint8 MAX_TARGETS = 1;

        if (targets.size() <= MAX_TARGETS)
            return;

        targets.remove(GetCaster());

        auto closestTargetItr = std::ranges::min_element(targets, [caster = GetCaster()](WorldObject const* left, WorldObject const* right)
        {
            return caster->GetDistance(left->GetPosition()) < caster->GetDistance(right->GetPosition());
        });

        if (closestTargetItr == targets.end())
            return;

        closestTarget = *closestTargetItr;
        targets.clear();
        targets.push_back(closestTarget);
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();

        CastSpellExtraArgs args;
        args.SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        args.SetTriggeringSpell(GetSpell());

        caster->CastSpell(closestTarget, SPELL_DARKFLAME_PICKAXE_VISUAL, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
        caster->m_Events.AddEventAtOffset(new DarkflamePickaxeDamageEvent(caster, closestTarget, GetSpell()), 300ms);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_the_candle_king_darkflame_pickaxe_cast::FilterTargets, EFFECT_0, TARGET_UNIT_RECT_CASTER);
        OnEffectHitTarget += SpellEffectFn(spell_the_candle_king_darkflame_pickaxe_cast::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    WorldObject* closestTarget = nullptr;
};

// 421648 - Cursed Wax
// Id - 29999
struct at_the_candle_king_cursed_wax : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_CURSED_WAX_DUMMY, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

// 420691 - Molten Wax and 420963 - Molten Wax
// Ids: 29904, 29906
struct at_the_candle_king_molten_wax : public AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        unit->CastSpell(unit, SPELL_MOLTEN_WAX_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_MOLTEN_WAX_DAMAGE);
    }
};

// Id - XXXX (change on merge)
struct at_the_candle_king_candlelight : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_CANDLELIGHT, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        unit->RemoveAurasDueToSpell(SPELL_DARKLIGHT_DEBUFF);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_CANDLELIGHT);
    }
};

void AddSC_boss_the_candle_king()
{
    RegisterDarkflameCleftCreatureAI(boss_the_candle_king);

    RegisterSpellScript(spell_the_candle_king_eerie_molds_clone_summoner);
    RegisterSpellScript(spell_the_candle_king_eerie_molds_selector);
    RegisterSpellScript(spell_the_candle_king_throw_darkflame_selector);
    RegisterSpellScript(spell_the_candle_king_throw_darkflame_missile);
    RegisterSpellScript(spell_the_candle_king_cursed_wax);
    RegisterSpellScript(spell_the_candle_king_darkflame_pickaxe_selector);
    RegisterSpellScript(spell_the_candle_king_darkflame_pickaxe_cast);

    RegisterAreaTriggerAI(at_the_candle_king_cursed_wax);
    RegisterAreaTriggerAI(at_the_candle_king_molten_wax);
    RegisterAreaTriggerAI(at_the_candle_king_candlelight);
}
