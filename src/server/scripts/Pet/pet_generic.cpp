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
 * Spell and creature scripts in this file are not ordered but grouped(all scripts related to same creature in same place).
 * Scriptnames of spells and creatures in this file should be prefixed with "spell_pet_gen_" and "npc_pet_gen_" respectively.
 */

#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum PandarenMonkMisc
{
    SPELL_PANDAREN_MONK = 69800,
    EVENT_FOCUS = 1,
    EVENT_EMOTE = 2,
    EVENT_FOLLOW = 3,
    EVENT_DRINK = 4
};

struct npc_pet_gen_pandaren_monk : public NullCreatureAI
{
    npc_pet_gen_pandaren_monk(Creature* creature) : NullCreatureAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_FOCUS, 1s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_EnterEvadeMode(why))
            return;

        Reset();
    }

    void ReceiveEmote(Player* /*player*/, uint32 emote) override
    {
        me->InterruptSpell(CURRENT_CHANNELED_SPELL);
        me->StopMoving();

        switch (emote)
        {
        case TEXT_EMOTE_BOW:
            _events.ScheduleEvent(EVENT_FOCUS, 1s);
            break;
        case TEXT_EMOTE_DRINK:
            _events.ScheduleEvent(EVENT_DRINK, 1s);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (Unit* owner = me->GetCharmerOrOwner())
            if (!me->IsWithinDist(owner, 30.f))
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FOCUS:
                if (Unit* owner = me->GetCharmerOrOwner())
                    me->SetFacingToObject(owner);
                _events.ScheduleEvent(EVENT_EMOTE, 1s);
                break;
            case EVENT_EMOTE:
                me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                _events.ScheduleEvent(EVENT_FOLLOW, 1s);
                break;
            case EVENT_FOLLOW:
                if (Unit* owner = me->GetCharmerOrOwner())
                    me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                break;
            case EVENT_DRINK:
                me->CastSpell(me, SPELL_PANDAREN_MONK, false);
                break;
            default:
                break;
            }
        }
    }

private:
    EventMap _events;
};

enum SoulTrader
{
    SAY_SOUL_TRADER_INTRO           = 0,

    SPELL_ETHEREAL_ONSUMMON         = 50052,
    SPELL_ETHEREAL_PET_REMOVE_AURA  = 50055
};

struct npc_pet_gen_soul_trader : public ScriptedAI
{
    npc_pet_gen_soul_trader(Creature* creature) : ScriptedAI(creature) { }

    void OnDespawn() override
    {
        if (Unit* owner = me->GetOwner())
            DoCast(owner, SPELL_ETHEREAL_PET_REMOVE_AURA);
    }

    void JustAppeared() override
    {
        Talk(SAY_SOUL_TRADER_INTRO);
        if (Unit* owner = me->GetOwner())
            DoCast(owner, SPELL_ETHEREAL_ONSUMMON);

        CreatureAI::JustAppeared();
    }
};

enum LichPet
{
    SPELL_LICH_PET_AURA         = 69732,
    SPELL_LICH_PET_AURA_ONKILL  = 69731,
    SPELL_LICH_PET_EMOTE        = 70049,

    NPC_LICH_PET                = 36979
};

// 69735 - Lich Pet OnSummon
class spell_pet_gen_lich_pet_onsummon : public SpellScript
{
    PrepareSpellScript(spell_pet_gen_lich_pet_onsummon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LICH_PET_AURA });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_LICH_PET_AURA, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pet_gen_lich_pet_onsummon::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 69736 - Lich Pet Aura Remove
class spell_pet_gen_lich_pet_aura_remove : public SpellScript
{
    PrepareSpellScript(spell_pet_gen_lich_pet_aura_remove);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LICH_PET_AURA });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_LICH_PET_AURA);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pet_gen_lich_pet_aura_remove::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 69732 - Lich Pet Aura
class spell_pet_gen_lich_pet_aura : public AuraScript
{
    PrepareAuraScript(spell_pet_gen_lich_pet_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LICH_PET_AURA_ONKILL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return (eventInfo.GetProcTarget()->GetTypeId() == TYPEID_PLAYER);
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* owner = GetUnitOwner();

        std::list<Creature*> minionList;
        owner->GetAllMinionsByEntry(minionList, NPC_LICH_PET);
        for (Creature* minion : minionList)
            owner->CastSpell(minion, SPELL_LICH_PET_AURA_ONKILL, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_pet_gen_lich_pet_aura::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_pet_gen_lich_pet_aura::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 70050 - [DND] Lich Pet
class spell_pet_gen_lich_pet_periodic_emote : public AuraScript
{
    PrepareAuraScript(spell_pet_gen_lich_pet_periodic_emote);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LICH_PET_EMOTE });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        // The chance to cast this spell is not 100%.
        // Triggered spell roots creature for 3 sec and plays anim and sound (doesn't require any script).
        // Emote and sound never shows up in sniffs because both comes from spell visual directly.
        // Both 69683 and 70050 can trigger spells at once and are not linked together in any way.
        // Effect of 70050 is overlapped by effect of 69683 but not instantly (69683 is a series of spell casts, takes longer to execute).
        // However, for some reason emote is not played if creature is idle and only if creature is moving or is already rooted.
        // For now it's scripted manually in script below to play emote always.
        if (roll_chance_i(50))
            GetTarget()->CastSpell(GetTarget(), SPELL_LICH_PET_EMOTE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_pet_gen_lich_pet_periodic_emote::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 70049 - [DND] Lich Pet
class spell_pet_gen_lich_pet_emote : public AuraScript
{
    PrepareAuraScript(spell_pet_gen_lich_pet_emote);

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->HandleEmoteCommand(EMOTE_ONESHOT_CUSTOM_SPELL_01);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_pet_gen_lich_pet_emote::AfterApply, EFFECT_0, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 69682 - Lil' K.T. Focus
class spell_pet_gen_lich_pet_focus : public SpellScript
{
    PrepareSpellScript(spell_pet_gen_lich_pet_focus);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pet_gen_lich_pet_focus::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_generic_pet_scripts()
{
    RegisterCreatureAI(npc_pet_gen_pandaren_monk);
    RegisterCreatureAI(npc_pet_gen_soul_trader);
    RegisterSpellScript(spell_pet_gen_lich_pet_onsummon);
    RegisterSpellScript(spell_pet_gen_lich_pet_aura_remove);
    RegisterSpellScript(spell_pet_gen_lich_pet_aura);
    RegisterSpellScript(spell_pet_gen_lich_pet_periodic_emote);
    RegisterSpellScript(spell_pet_gen_lich_pet_emote);
    RegisterSpellScript(spell_pet_gen_lich_pet_focus);
}
